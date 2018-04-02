/* USB Keyboard Example for Teensy USB Development Board
 * http://www.pjrc.com/teensy/usb_keyboard.html
 * Copyright (c) 2009 PJRC.COM, LLC
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

// Version 1.0: Initial Release
// Version 1.1: Add support for Teensy 2.0

#define USB_SERIAL_PRIVATE_INCLUDE
#include "usb_keyboard.h"

#include <string.h>
#include <stdbool.h>

#include <util/atomic.h>
#include <util/delay.h>

#include "usb/descriptors.h"
#include "usb_reports/keyboard_report.h"

#include "usb_32u4.h"


/**************************************************************************
 *
 *  Configurable Options
 *
 **************************************************************************/

// You can change these to give your code its own name.
#define STR_MANUFACTURER    L"keyplus"
#define STR_PRODUCT     L"Keyboard"

// Mac OS-X and Linux automatically load the correct drivers.  On
// Windows, even though the driver is supplied by Microsoft, an
// INF file is needed to load the driver.  These numbers need to
// match the INF file.
#define VENDOR_ID       0x16C0
#define PRODUCT_ID      0x047C

// USB devices are supposed to implment a halt feature, which is
// rarely (if ever) used.  If you comment this line out, the halt
// code will be removed, saving 102 bytes of space (gcc 4.3.0).
// This is not strictly USB compliant, but works with all major
// operating systems.
#define SUPPORT_ENDPOINT_HALT



/**************************************************************************
 *
 *  Endpoint Buffer Configuration
 *
 **************************************************************************/

#define ENDPOINT0_SIZE      64

#define KEYBOARD_INTERFACE  0
#define KEYBOARD_ENDPOINT   1
#define KEYBOARD_SIZE       8
#define KEYBOARD_BUFFER     EP_DOUBLE_BUFFER

#define DEFAULT_BUFFERING EP_SINGLE_BUFFER
// #define DEFAULT_BUFFERING EP_DOUBLE_BUFFER

static const uint8_t PROGMEM endpoint_config_table[] = {
    1, EP_NUM_BOOT_KEYBOARD, EP_TYPE_INTERRUPT_IN,  EP_SIZE(EP_IN_SIZE_BOOT_KEYBOARD) | DEFAULT_BUFFERING,
    1, EP_NUM_MOUSE, EP_TYPE_INTERRUPT_IN,  EP_SIZE(EP_IN_SIZE_MOUSE) | DEFAULT_BUFFERING,
    1, EP_NUM_MEDIA, EP_TYPE_INTERRUPT_IN,  EP_SIZE(EP_IN_SIZE_MEDIA) | DEFAULT_BUFFERING,
    1, EP_NUM_VENDOR_IN, EP_TYPE_INTERRUPT_IN,  EP_SIZE(EP_SIZE_VENDOR) | DEFAULT_BUFFERING,
    1, EP_NUM_VENDOR_OUT, EP_TYPE_INTERRUPT_OUT, EP_SIZE(EP_SIZE_VENDOR) | DEFAULT_BUFFERING,
    1, EP_NUM_NKRO_KEYBOARD, EP_TYPE_INTERRUPT_IN,  EP_SIZE(EP_IN_SIZE_NKRO_KEYBOARD) | DEFAULT_BUFFERING,
    0
};


/**************************************************************************
 *
 *  Variables - these are the only non-stack RAM usage
 *
 **************************************************************************/

// zero when we are not configured, non-zero when enumerated
static volatile uint8_t usb_configuration;

// which modifier keys are currently pressed
// 1=left ctrl,    2=left shift,   4=left alt,    8=left gui
// 16=right ctrl, 32=right shift, 64=right alt, 128=right gui

hid_report_boot_keyboard_t kb_report = {0};

// protocol setting from the host.  We use exactly the same report
// either way, so this variable only stores the setting since we
// are required to be able to report which setting is in use.
static uint8_t keyboard_protocol=1;

// the idle configuration, how often we send the report to the
// host (ms * 4) even when it hasn't changed
static uint8_t keyboard_idle_config=125;

// count until idle timeout
static uint8_t keyboard_idle_count=0;

// 1=num lock, 2=caps lock, 4=scroll lock, 8=compose, 16=kana
volatile uint8_t keyboard_leds=0;


/**************************************************************************
 *
 *  Public Functions - these are the API intended for the user
 *
 **************************************************************************/


// initialize USB
void usb_init(void)
{
    HW_CONFIG();
    USB_FREEZE();   // enable USB
    PLL_CONFIG();   // config PLL
    while (!(PLLCSR & (1<<PLOCK))) ;    // wait for PLL lock

    USB_CONFIG();   // start USB clock

    UDCON = 1;      // disconnect attach resistor
    _delay_ms(10);
    UDCON = 0;      // enable attach resistor

    usb_configuration = 0;

    // enable usb interrupts
    UDIEN = (1<<EORSTE)|(1<<SOFE);
}

// return 0 if the USB is not configured, or the configuration
// number selected by the HOST
uint8_t usb_configured(void)
{
    return usb_configuration;
}

static inline int8_t usb_wait_endpoint(uint8_t ep_num);

int8_t usb_keyboard_send_blocking(void) {
    if (usb_wait_endpoint(KEYBOARD_ENDPOINT)) {
        return -1;
    } else {
        return usb_keyboard_send();
    }
}

// perform a single keystroke
int8_t usb_keyboard_press(uint8_t key, uint8_t modifier)
{
    int8_t r;

    kb_report.modifiers = modifier;
    kb_report.keys[0] = key;
    r = usb_keyboard_send_blocking();
    if (r) return r;
    kb_report.modifiers = modifier;
    kb_report.keys[0] = 0;
    return usb_keyboard_send_blocking();
}

void usb_write_endpoint(uint8_t ep_number, const uint8_t *src, uint8_t length) {
    uint8_t i;
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        UENUM = ep_number;
        for (i = 0; i < length; ++i) {
            UEDATX = src[i];
        }
        UEINTX = (1<<STALLEDI) | (1<<RXSTPI) | (1<<NAKOUTI) | (1<<RWAL);
    }
}

void usb_read_endpoint(uint8_t ep_number, uint8_t *dest, uint8_t *length) {
    uint8_t i;
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        UENUM = ep_number;
        *length = UEBCX;
        for (i = 0; i < *length; ++i) {
            dest[i] = UEDATX;
        }
        UEINTX = 0x6B;
    }
}

static inline int8_t usb_wait_endpoint(uint8_t ep_num) {
    uint8_t timeout = UDFNUML + 50;
    while (1) {
        bool ready = false;
        ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
            ready = usb_is_endpoint_ready(ep_num);
        }
        if (ready) {
            return 0;
        } else if (!usb_configuration || UDFNUML == timeout) {
            return -1; // has the USB gone offline or timed out
        }
    }
}

// send the contents of keyboard_keys and keyboard_modifier_keys
int8_t usb_keyboard_send(void)
{
    uint8_t ret_val = -1;

    if (!usb_configuration) {
        return ret_val;
    }

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        if (usb_is_endpoint_ready(KEYBOARD_ENDPOINT)) {
            usb_write_endpoint(KEYBOARD_ENDPOINT, (uint8_t*)&kb_report, 8);
            ret_val = 0;
        }
    }

    return ret_val;
}

/**************************************************************************
 *
 *  Private Functions - not intended for general user consumption....
 *
 **************************************************************************/



// USB Device Interrupt - handle all device-level events
// the transmit buffer flushing is triggered by the start of frame
//
ISR(USB_GEN_vect) {
    uint8_t irq_flags;
    static uint8_t div4=0;

    irq_flags = UDINT;
    UDINT = 0;

    // USB SOF interrupt
    if ((irq_flags & (1<<SOFI)) && usb_configuration) {

        // if (keyboard_idle_config && (++div4 & 3) == 0) {
        //     UENUM = KEYBOARD_ENDPOINT;
        //     if (UEINTX & (1<<RWAL)) {
        //         keyboard_idle_count++;
        //         if (keyboard_idle_count == keyboard_idle_config) {
        //             keyboard_idle_count = 0;
        //             usb_read_endpoint(
        //                 KEYBOARD_ENDPOINT,
        //                 (uint8_t*)&kb_report,
        //                 sizeof(kb_report)
        //             );
        //             UEINTX = (1<<STALLEDI) | (1<<RXSTPI) | (1<<NAKOUTI) | (1<<RWAL);
        //         }
        //     }
        // }

    }

    // USB end of reset interrupt
    if (irq_flags & (1<<EORSTI)) {
        UENUM = 0;
        UECONX = 1;
        UECFG0X = EP_TYPE_CONTROL;
        UECFG1X = EP_SIZE(ENDPOINT0_SIZE) | EP_SINGLE_BUFFER;
        UEIENX = (1<<RXSTPE);
        usb_configuration = 0;
    }

    // USB suspend interrupt
    // if (irq_flags & (1<<SUSPI)) {
    // }

    // USB end of resume interrupt
    // if (irq_flags & (1<<UPRSMI)) {
    // }

    // USB upstream resume interrupt
    // if (irq_flags & (1<<EORSMI)) {
    // }

    // USB wake up interrupt
    // if (irq_flags & (1<<WAKEUPI)) {
    // }
}



// Misc functions to wait for ready and send/receive packets
static inline void usb_wait_in_ready(void)
{
    while (!(UEINTX & (1<<TXINI))) ;
}
static inline void usb_send_in(void)
{
    UEINTX = ~(1<<TXINI);
}
static inline void usb_wait_receive_out(void)
{
    while (!(UEINTX & (1<<RXOUTI))) ;
}
static inline void usb_ack_out(void)
{
    UEINTX = ~(1<<RXOUTI);
}

#define is_setup_packet(x) (x & (1<<RXSTPI))

#define USB_EP0_STALL() (UECONX = (1<<STALLRQ)|(1<<EPEN))

// TODO: descriptor stuff move to another file later
#include "usb/descriptors.h"

#include "usb/util/usb_hid.h"


void get_descriptor(
    usb_request_t* req,
    fat_ptr_t *ptr
) {
    uint16_t length   = 0;
    raw_ptr_t address = (raw_ptr_t)NULL;

    // by default load the descriptor from flash memory
    ptr->type = PTR_FLASH;

    switch (req->get_desc.type) {
        // USB Host requested a device descriptor
        case USB_DESC_DEVICE: {
            address = (raw_ptr_t)&usb_device_desc;
            length  = sizeof(usb_device_desc);
        } break;

        // USB Host requested a configuration descriptor
        case USB_DESC_CONFIGURATION: {
            address = (raw_ptr_t)&usb_config_desc;
            length  = sizeof(usb_config_desc);
        } break;

        // USB Host requested a string descriptor
        case USB_DESC_STRING: {
            switch (req->get_desc.index) {

                default:
                case STRING_DESC_NONE: {
                    address = (raw_ptr_t)((uint8_t*)usb_string_desc_0);
                    length = sizeof(usb_string_desc_0);
                } break;

                // case STRING_DESC_MANUFACTURER: {
                //     // make_string_desc(manufacturer_string);
                //     // address = (raw_ptr_t)string_desc_buf;
                // } break;

                // case STRING_DESC_MANUFACTURER: {
                //     ptr->type = PTR_DATA;
                //     // make_string_desc(manufacturer_string);
                //     // address = (raw_ptr_t)string_desc_buf;
                // } break;

                // case STRING_DESC_PRODUCT: {
                // } break;

                // case STRING_DESC_PRODUCT: {
                //     ptr->type = PTR_DATA;
                //     flash_read(
                //         (uint8_t*) string_copy_buf,
                //         (flash_ptr_t)&(GET_SETTING(device_name)),
                //         MAX_STRING_LEN
                //     );
                //     make_string_desc(string_copy_buf);
                //     address = (raw_ptr_t)string_desc_buf;
                // } break;

                // case STRING_DESC_SERIAL_NUMBER: {
                //     make_serial_string();
                //     make_string_desc(string_copy_buf);
                //     ptr->type = PTR_DATA;
                //     address = (raw_ptr_t)string_desc_buf;
                // } break;
            }

            // if (address != 0) {
            //     if (ptr->type == PTR_FLASH) {
            //         length = flash_read_byte(
            //             (flash_ptr_t)&(((usb_string_desc_t*)address)->bLength)
            //         );
            //     } else if (ptr->type == PTR_DATA) {
            //         length = ((usb_string_desc_t*)address)->bLength;
            //     }
            // }
        } break;

        // USB Host requested a HID descriptor
        case USB_DESC_HID_REPORT: {
            switch (req->get_hid_desc.interface) {
                case INTERFACE_BOOT_KEYBOARD: {
                    address = (raw_ptr_t)hid_desc_boot_keyboard;
                    length  = sizeof_hid_desc_boot_keyboard;
                } break;
                case INTERFACE_MOUSE: {
                    address = (raw_ptr_t)hid_desc_mouse;
                    length  = sizeof_hid_desc_mouse;
                } break;
                case INTERFACE_MEDIA: {
                    address = (raw_ptr_t)hid_desc_media;
                    length  = sizeof_hid_desc_media;
                } break;
                case INTERFACE_VENDOR: {
                    address = (raw_ptr_t)hid_desc_vendor;
                    length  = sizeof_hid_desc_vendor;
                } break;
                case INTERFACE_NKRO_KEYBOARD: {
                    address = (raw_ptr_t)hid_desc_nkro_keyboard;
                    length  = sizeof_hid_desc_nkro_keyboard;
                } break;
            }
        } break;

    }

    ptr->len = length;
    ptr->ptr.raw = address;
}

uint8_t usb_handle_ep0(usb_request_std_t *req) {
    switch(req->bRequest) {
        case USB_REQ_GET_DESCRIPTOR: {
            uint8_t len, i, n;
            fat_ptr_t desc_ptr;

            get_descriptor((usb_request_t*)req, &desc_ptr);

            // desc_ptr.type = PTR_FLASH;
            // desc_ptr.len = sizeof(usb_device_desc);
            // desc_ptr.ptr.raw = (raw_ptr_t)&usb_device_desc;

            if (desc_ptr.ptr.raw == 0) {
                USB_EP0_STALL();
                return 1;
            }

            len = (req->wLength < 256) ? req->wLength : 255;

            if (len > desc_ptr.len) {
                len = desc_ptr.len;
            }

            do {
                // wait for host ready for IN packet
                do {
                    i = UEINTX;
                } while (!(i & ((1<<TXINI)|(1<<RXOUTI))));

                if (i & (1<<RXOUTI)) {
                    return 1;    // abort
                }

                // send IN packet
                n = len < ENDPOINT0_SIZE ? len : ENDPOINT0_SIZE;
                for (i = n; i; i--) {
                    switch (desc_ptr.type) {
                        case PTR_FLASH: {
                            UEDATX = pgm_read_byte(desc_ptr.ptr.flash++);
                        } break;

                        case PTR_DATA: {
                            UEDATX = desc_ptr.ptr.data[0];
                            desc_ptr.ptr.data++;
                        } break;
                    }
                }
                len -= n;
                usb_send_in();
            } while (len || n == ENDPOINT0_SIZE);

            return 1;
        } break;

        case SET_ADDRESS: {
            usb_send_in();
            usb_wait_in_ready();
            UDADDR = req->wValue | (1<<ADDEN);
            return 1;
        } break;

        case SET_CONFIGURATION: {
            const uint8_t *cfg;
            uint8_t i;

            if (req->bmRequestType == 0) {
                usb_configuration = req->wValue;
                usb_send_in();
                cfg = endpoint_config_table;
                for (i=0; i<6; i++) {
                    uint8_t en, ep_num;

                    en = pgm_read_byte(cfg++);
                    ep_num = pgm_read_byte(cfg++);
                    UENUM = ep_num;

                    UECONX = en;
                    if (en) {
                        UECFG0X = pgm_read_byte(cfg++);
                        UECFG1X = pgm_read_byte(cfg++);
                    }
                }
            }
            UERST = 0x1E;
            UERST = 0;
            return 1;
        } break;

        case GET_CONFIGURATION: {
            if (req->bmRequestType == 0x80) {
                usb_wait_in_ready();
                UEDATX = usb_configuration;
                usb_send_in();
                return 1;
            }
        } break;

        case GET_STATUS: {
            uint8_t i;

            usb_wait_in_ready();
            i = 0;
#ifdef SUPPORT_ENDPOINT_HALT
            if (req->bmRequestType == 0x82) {
                UENUM = req->wIndex;
                if (UECONX & (1<<STALLRQ)) i = 1;
                UENUM = 0;
            }
#endif
            UEDATX = i;
            UEDATX = 0;
            usb_send_in();
            return 1;
        } break;

#ifdef SUPPORT_ENDPOINT_HALT
        case CLEAR_FEATURE:
        case SET_FEATURE: {
            if (req->bmRequestType == 0x02 && req->wValue == 0) {
                uint8_t i;

                i = req->wIndex & 0x7F;
                if (i >= 1 && i <= MAX_ENDPOINT) {
                    usb_send_in();
                    UENUM = i;
                    if (req->bRequest == SET_FEATURE) {
                        USB_EP0_STALL();
                    } else {
                        UECONX = (1<<STALLRQC)|(1<<RSTDT)|(1<<EPEN);
                        UERST = (1 << i);
                        UERST = 0;
                    }
                    return 1;
                }
            }
        } break;
#endif
    }
    return 0;
}

#include "usb_reports/mouse_report.h"


void usb_hid_request(usb_request_std_t *req) {
    switch (req->wIndex) {
        case INTERFACE_BOOT_KEYBOARD: {
            if (req->bmRequestType == 0xA1) {
                if (req->bRequest == HID_GET_REPORT) {
                    usb_wait_in_ready();
                    usb_write_endpoint(0, (uint8_t*)&kb_report, sizeof(kb_report));
                    usb_send_in();
                    return;
                }
                if (req->bRequest == HID_GET_IDLE) {
                    usb_wait_in_ready();
                    UEDATX = keyboard_idle_config;
                    usb_send_in();
                    return;
                }
                if (req->bRequest == HID_GET_PROTOCOL) {
                    usb_wait_in_ready();
                    UEDATX = keyboard_protocol;
                    usb_send_in();
                    return;
                }
            }
            if (req->bmRequestType == 0x21) {
                if (req->bRequest == HID_SET_REPORT) {
                    usb_wait_receive_out();
                    keyboard_leds = UEDATX;
                    usb_ack_out();
                    usb_send_in();
                    return;
                }
                if (req->bRequest == HID_SET_IDLE) {
                    keyboard_idle_config = (req->wValue >> 8);
                    keyboard_idle_count = 0;
                    usb_send_in();
                    return;
                }
                if (req->bRequest == HID_SET_PROTOCOL) {
                    keyboard_protocol = req->wValue;
                    usb_send_in();
                    return;
                }
            }
        } break;

        case INTERFACE_MOUSE: {
            if (req->bmRequestType == 0xA1) {
                if (req->bRequest == HID_GET_REPORT) {
                    usb_wait_in_ready();
                    usb_write_endpoint(
                        0,
                        (uint8_t*)&g_mouse_report,
                        sizeof(hid_report_mouse_t)
                    );
                    usb_send_in();
                    return;
                }
                if (req->bRequest == HID_GET_IDLE) {
                    usb_wait_in_ready();
                    UEDATX = keyboard_idle_config;
                    usb_send_in();
                    return;
                }
                if (req->bRequest == HID_GET_PROTOCOL) {
                    usb_wait_in_ready();
                    UEDATX = keyboard_protocol;
                    usb_send_in();
                    return;
                }
            }
            if (req->bmRequestType == 0x21) {
                if (req->bRequest == HID_SET_REPORT) {
                    usb_wait_receive_out();
                    keyboard_leds = UEDATX;
                    usb_ack_out();
                    usb_send_in();
                    return;
                }
                if (req->bRequest == HID_SET_IDLE) {
                    keyboard_idle_config = (req->wValue >> 8);
                    keyboard_idle_count = 0;
                    usb_send_in();
                    return;
                }
                if (req->bRequest == HID_SET_PROTOCOL) {
                    keyboard_protocol = req->wValue;
                    usb_send_in();
                    return;
                }
            }
        }
    }

    USB_EP0_STALL();
}

// void usb_handle_endpoint_request(usb_request_t *req) {
//     switch (req->val.bRequest) {
//         case USB_REQ_GET_STATUS: {
//             uint8_t endpoint = req->val.wIndexLSB;

//             if (usb_configuration != USB_CONFIGURED) {
//                 USB_EP0_STALL();
//                 return;
//             }

//             // switch (endpoint) {
//             //     case USB_DIR_IN | 0x01: {in0buf[0] = in1cs & 0x01;} break;
//             //     case USB_DIR_IN | 0x02: {in0buf[0] = in2cs & 0x01;} break;
//             //     case USB_DIR_IN | 0x03: {in0buf[0] = in3cs & 0x01;} break;
//             //     case USB_DIR_IN | 0x04: {in0buf[0] = in4cs & 0x01;} break;
//             //     case USB_DIR_IN | 0x05: {in0buf[0] = in5cs & 0x01;} break;
//             // }

//             // all values are reserved for interfaces
//             {
//                 uint8_t response[2] = {0, 0};
//                 UENUM = endpoint & 0x7F;
//                 response[0] = !!(UEINTX & _BV(STALLEDI));
//                 usb_write_endpoint(0, response, sizeof(response));
//             }
//         } break;

//         default: {
//             USB_EP0_STALL();
//         }
//     }
// }

// USB Endpoint Interrupt - endpoint 0 is handled here.  The
// other endpoints are manipulated by the user-callable
// functions, and the start-of-frame interrupt.
//
ISR(USB_COM_vect) {
    usb_request_t req;


    // if (!is_setup_packet(UEINTX)) {
    //     USB_EP0_STALL();
    // }

    UENUM = 0;
    {
        uint8_t length;
        usb_read_endpoint(0, (uint8_t*)&req, &length);
    }
    UEINTX = ~((1<<RXSTPI) | (1<<RXOUTI) | (1<<TXINI));

    const uint8_t req_type = req.val.bmRequestType & USB_REQTYPE_TYPE_MASK;

    switch (req_type) {
        case USB_REQTYPE_TYPE_STANDARD: {
            const uint8_t recipient = req.val.bmRequestType & USB_REQTYPE_RECIPIENT_MASK;
            switch (recipient) {
                case USB_REQTYPE_RECIPIENT_DEVICE: {
                    // usb_handle_device_request();
                    usb_handle_ep0((usb_request_std_t*)&req);
                } break;

                case USB_REQTYPE_RECIPIENT_INTERFACE: {
                    switch (req.val.bRequest) {
                        case USB_REQ_GET_STATUS: {
                            if (usb_configuration != USB_CONFIGURED) {
                                USB_EP0_STALL();
                                return;
                            }

                            // all values are reserved for interfaces
                            {
                                uint8_t response[2] = {0, 0};
                                usb_write_endpoint(0, response, sizeof(response));
                            }
                        } break;

                        case USB_REQ_GET_DESCRIPTOR: {
                            usb_handle_ep0((usb_request_std_t*)&req);
                        } break;

                        default: {
                            USB_EP0_STALL();
                        }
                    }
                } break;

                // case USB_REQTYPE_RECIPIENT_ENDPOINT: {
                //     usb_handle_endpoint_request(&req);
                // } break;

                default: {
                    USB_EP0_STALL();
                } break;
            }
        } break;

        case USB_REQTYPE_TYPE_CLASS: {
            usb_hid_request((usb_request_std_t*)&req);
        } break;

        default: {
            // stall on unsupported requests
            USB_EP0_STALL();
        } break;
    }
}
