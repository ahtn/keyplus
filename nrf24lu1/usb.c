// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include <stdint.h>

#include "nrf24lu1.h"
#include "nrf24lu1_usb.h"

#define DECLARE_USB_REGS
#include "nrf24lu1_usb_regs.h"

#include "usb/descriptors.h"
#include "usb/util/requests.h"

#include "core/led.h"
#include "core/hardware.h"
#include "core/util.h"
#include "core/usb_commands.h"

#include "usb_reports/keyboard_report.h"
#include "usb_reports/mouse_report.h"
#include "usb_reports/vendor_report.h"

XRAM uint8_t g_has_received_usb_data;

static XRAM uint8_t usb_current_configuration;
static XRAM usb_state_t usb_state;

// TODO: probably move these
static XRAM uint8_t led_report = 0;
#define ENABLE_USB_ISR

// TODO: according to the USB HID specification handling Get_Idle and Set_Idle
// requests is required for both boot and non-boot keyboards. From what I've
// seen most modern OS's don't care.
//
// Idle rate: The frequency at which a device reports data when no new events
// have occurred.  Most devices only report new events and therefore default to
// an idle rate of infinity. Keyboards may use the idle rate for auto repeating
// keys.

void usb_init(void) {
    USB_IRQEN = 0;

    // reconnect to the host by disabling and reenabling the USB D+ pull-up
    usbcs = USBCS_DISCON_bm;
    static_delay_ms(50);
    usbcs = 0;

    // set up usb interrupts
    usbien = (
        USBIRQ_SOF_bm |
        USBIRQ_SUDAV_bm
    );

    // enable endpoints
    in_ien = (
        USBIRQ_EP0 |
        USBIRQ_EP1 |
        USBIRQ_EP2 |
        USBIRQ_EP3 |
        USBIRQ_EP4 |
        USBIRQ_EP5
    );
    out_ien = (
        USBIRQ_EP0 |
        USBIRQ_EP4
    );

    inbulkval = (
        (1 << 0) |
        (1 << 1) |
        (1 << 2) |
        (1 << 3) |
        (1 << 4) |
        (1 << 5)
    );
    outbulkval = (
        (1 << 0) |
        (1 << 4)
    );

    // iso endpoints not used
    inisoval = 0x00;
    outisoval = 0x00;
    usbpair = 0;

    // clear in and out interrupt flags
    in_irq = 0x1f;
    out_irq = 0x1f;

    // setup the USB RAM
    {
        // NOTE: Refer to the USB memory mapping options in section 7.7 of the
        // datasheet.
        bout1addr = 0;
        bout2addr = 0;
        bout3addr = 0;
        bout4addr = (EP0_OUT_SIZE)/2;
        bout5addr = 0;
        binstaddr = (EP0_OUT_SIZE + EP4_OUT_SIZE)/4;

        bin1addr = (EP0_IN_SIZE)/2;
        bin2addr = (EP0_IN_SIZE + EP1_IN_SIZE)/2;
        bin3addr = (EP0_IN_SIZE + EP1_IN_SIZE + EP2_IN_SIZE)/2;
        bin4addr = (EP0_IN_SIZE + EP1_IN_SIZE + EP2_IN_SIZE + EP3_IN_SIZE)/2;
        bin5addr = (EP0_IN_SIZE + EP1_IN_SIZE + EP2_IN_SIZE + EP3_IN_SIZE + EP4_IN_SIZE)/2;
    }

    out0bc = 0xff;
    out1bc = 0xff;
    out2bc = 0xff;
    out3bc = 0xff;
    out4bc = 0xff;
    out5bc = 0xff;

    g_has_received_usb_data = 0;
#ifdef ENABLE_USB_ISR
    USB_IRQEN = 1;
#endif
}

void usb_disable(void) {
    USB_IRQEN = 0;
}

void usb_handle_device_request(void) {
    switch (usb_request.val.bRequest) {
        case USB_REQ_GET_STATUS: {
            // We must be in ADDRESSED or CONFIGURED state, and wIndex must be 0
            if ( (usb_state == USB_ADDRESSED || usb_state == USB_CONFIGURED) &&
                    (usb_request.val.wIndexLSB == 0x00) )
            {
                // We aren't self-powered and we don't support remote wakeup
                in0buf[0] = 0x00;
                in0buf[1] = 0x00;
                in0bc = 0x02;
            } else {
                // Stall for invalid requests
                USB_EP0_STALL();
            }
        } break;

        case USB_REQ_SET_ADDRESS: {
            // nrf controller automatically sets the address
            usb_state = USB_ADDRESSED;
        } break;

        case USB_REQ_GET_DESCRIPTOR: {
            usb_get_descriptor((usb_request_t*)&usb_request);
        } break;

        case USB_REQ_GET_CONFIGURATION: {
            if (usb_state == USB_ADDRESSED) {
                in0buf[0] = 0x00;
                in0bc = 0x01;
            } else if (usb_state == USB_CONFIGURED) {
                in0buf[0] = usb_current_configuration;
                in0bc = 0x01;
            } else {
                // Behavior not specified in other states, so STALL
                USB_EP0_STALL();
            }
        } break;

        case USB_REQ_SET_CONFIGURATION: {
            if (usb_request.val.wValueLSB == 0x00) {
                usb_state = USB_ADDRESSED;
                usb_current_configuration = 0x00;
                USB_EP0_HSNAK();
            } else if (usb_request.val.wValueLSB == 0x01) {
                usb_state = USB_CONFIGURED;
                usb_current_configuration = 0x01;
                USB_EP0_HSNAK();
            } else {
                USB_EP0_STALL(); // Stall for invalid config values
            }
        } break;

        default: {
            USB_EP0_STALL();
        } break;
    }
}

void usb_handle_endpoint_request(void) {
    switch (usb_request.val.bRequest) {
        case USB_REQ_GET_STATUS: {
            uint8_t endpoint = usb_request.val.wIndexLSB;

            if (usb_state != USB_CONFIGURED) {
                USB_EP0_STALL();
                return;
            }

            switch (endpoint) {
                case USB_DIR_IN | 0x01: {in0buf[0] = in1cs & 0x01;} break;
                case USB_DIR_IN | 0x02: {in0buf[0] = in2cs & 0x01;} break;
                case USB_DIR_IN | 0x03: {in0buf[0] = in3cs & 0x01;} break;
                case USB_DIR_IN | 0x04: {in0buf[0] = in4cs & 0x01;} break;
                case USB_DIR_IN | 0x05: {in0buf[0] = in5cs & 0x01;} break;
            }

            in0bc = 0x02;

        } break;

        default: {
            USB_EP0_STALL();
        }
    }
}

void usb_handle_interface_request(void) {
    switch (usb_request.val.bRequest) {
        case USB_REQ_GET_STATUS: {
            if (usb_state != USB_CONFIGURED) {
                USB_EP0_STALL();
                return;
            }

            // all values are reserved for interfaces
            in0buf[0] = 0x00;
            in0buf[1] = 0x00;
            in0bc = 0x02;
        } break;

        case USB_REQ_GET_DESCRIPTOR: {
            usb_get_descriptor((usb_request_t*)&usb_request);
        } break;

        default: {
            USB_EP0_STALL();
        }
    }
}

// NOTE: This function is used to avoid calling memcpy which is not reentrant
// and so should not be used in an ISR. It also saves a couple of bytes.
static void usb_isr_memcpy_in0buf(void XRAM* src, uint8_t size) {
    uint8_t i;
    for (i = 0; i < size; ++i) {
        in0buf[i] = ((uint8_t*)src)[i];
    }
    in0bc = size;
}

void usb_hid_request(void) {
    uint8_t bRequest = usb_request.val.bRequest;
    uint8_t interface = usb_request.val.wIndexLSB;

    switch (usb_request.val.bRequest) {
        case USB_REQ_HID_SET_REPORT: {
            // we have to wait for the 1 byte LED report
            // which will come with the next EP0OUT interrupt
            // TODO:
            USB_EP0_STALL();
        } break;

        case USB_REQ_HID_GET_REPORT: {
            uint8_t report_id = usb_request.val.wValueLSB;
            // These HID requests don't need to be sent over there specific
            // endpoints but also may be sent over endpoint 0.
            if (interface == INTERFACE_BOOT_KEYBOARD) {
                usb_isr_memcpy_in0buf(
                    &g_boot_keyboard_report,
                    sizeof(hid_report_boot_keyboard_t)
                );
            } else if (interface == INTERFACE_MEDIA) {
                if (report_id == REPORT_ID_SYSTEM) {
                    in0buf[0] = REPORT_ID_SYSTEM;
                    in0buf[1] = 0;
                    in0bc = REPORT_SIZE_SYSTEM;
                } else if (report_id == REPORT_ID_CONSUMER) {
                    in0buf[0] = REPORT_ID_CONSUMER;
                    in0buf[1] = 0;
                    in0buf[2] = 0;
                    in0bc = REPORT_SIZE_CONSUMER;
                } else {
                    in0bc = 0;
                }
            } else if (interface == INTERFACE_MOUSE) {
                usb_isr_memcpy_in0buf(
                    &g_mouse_report,
                    sizeof(hid_report_mouse_t)
                );
            } else if (interface == INTERFACE_VENDOR) {
                usb_isr_memcpy_in0buf(
                    g_vendor_report_in.data,
                    EP_IN_SIZE_VENDOR
                );
            } else if (interface == INTERFACE_NKRO_KEYBOARD) {
                usb_isr_memcpy_in0buf(
                    &g_nkro_keyboard_report,
                    sizeof(hid_report_nkro_keyboard_t)
                );
            } else {
                in0bc = 0;
            }
        } break;

        case USB_REQ_HID_SET_PROTOCOL: {
            if (usb_request.val.wIndexLSB == INTERFACE_BOOT_KEYBOARD) {
                clear_keyboard_report();
                if (usb_request.val.wValueLSB == 0) {
                    set_keyboard_protocol(PROTOCOL_BOOT);
                } else if (usb_request.val.wValueLSB == 1) {
                    set_keyboard_protocol(PROTOCOL_REPORT);
                } else {
                    USB_EP0_STALL();
                }
                in0bc = 0x00;
                USB_EP0_HSNAK();
            }
        } break;

        case USB_REQ_HID_GET_PROTOCOL: {
            if (usb_request.val.wIndexLSB == INTERFACE_BOOT_KEYBOARD) {
                in0buf[0] = get_keyboard_protocol();
                in0bc = 0x01;
            }
        } break;

        default: {
            USB_EP0_STALL();
        }
    }
}

// this function selects the appropriate request handle when we recevie a setup
// data packet
void usb_receive_request(void) {
    const uint8_t req_type = usb_request.val.bmRequestType & USB_REQTYPE_TYPE_MASK;

    switch (req_type) {
        case USB_REQTYPE_TYPE_STANDARD: {
            const uint8_t recipient = usb_request.val.bmRequestType & USB_REQTYPE_RECIPIENT_MASK;
            switch (recipient) {
                case USB_REQTYPE_RECIPIENT_DEVICE: {
                    usb_handle_device_request();
                } break;

                case USB_REQTYPE_RECIPIENT_INTERFACE: {
                    usb_handle_interface_request();
                } break;

                case USB_REQTYPE_RECIPIENT_ENDPOINT: {
                    usb_handle_endpoint_request();
                } break;

                default: {
                    USB_EP0_STALL();
                } break;
            }
        } break;

        case USB_REQTYPE_TYPE_CLASS: {
            usb_hid_request();
        } break;

        default: {
            // stall on unsupported requests
            USB_EP0_STALL();
        } break;
    }
}

void usb_handle_received_data(void) {
    if (usb_request.val.bRequest == USB_REQ_HID_SET_REPORT) {
        led_report = out0buf[0];
    }

    // send an empty packet and ACK the request
    in0bc = 0x00;
    USB_EP0_HSNAK();
}

// The handle USBIRQ events. Either using an ISR or polling function
#ifdef ENABLE_USB_ISR
void usb_isr(void) __interrupt (ISR_USB_INT) {
#else
void usb_poll(void) {
    if (!USBIRQ) {
        return;
    }
#endif

    switch (ivec) {
        case IVEC_SUDAV: {    // SETUP data packet
            usbirq = USBIRQ_SUDAV_bm;  // clear interrupt flag

            usb_receive_request();  // process setup data

            // rearm ep0 out so we are ready to receive more data
            out0bc = 0x40;

        } break;
        case IVEC_SOF: { // SOF packet
            usbirq = USBIRQ_SOF_bm;
        } break;

        case IVEC_SUTOK: { // setup token
            usbirq = USBIRQ_SUTOK_bm;
        } break;

        case IVEC_SUSPEND: { // suspend signal
            usbirq = USBIRQ_SUSP_bm;
        } break;

        case IVEC_USBRESET: { // USB bus reset
            usbirq = USBIRQ_URES_bm;
            usb_state = USB_DEFAULT;    // reset internal states
            usb_current_configuration = 0;
        } break;

        case IVEC_EP0IN: {
            in_irq = USBIRQ_EP0;
            usb_ep0_packetizer_data_send();
        } break;

        case IVEC_EP0OUT: {
            out_irq = USBIRQ_EP0;
            usb_handle_received_data();
            out0bc = 0x40;
        } break;

        // clear flags
        case IVEC_EP1IN: { in_irq = USBIRQ_EP1; } break;
        case IVEC_EP2IN: { in_irq = USBIRQ_EP2; } break;
        case IVEC_EP3IN: { in_irq = USBIRQ_EP3; } break;
        case IVEC_EP4IN: { in_irq = USBIRQ_EP4; } break;
        case IVEC_EP5IN: { in_irq = USBIRQ_EP5; } break;

        case IVEC_EP4OUT: {
            out_irq = USBIRQ_EP4;
            g_has_received_usb_data |= USBIRQ_EP4;
        } break;


        default: {
            USB_EP0_STALL();
        } break;
    }
}
