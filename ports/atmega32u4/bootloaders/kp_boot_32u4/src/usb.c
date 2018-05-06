/* USB Keyboard Example for Teensy USB Development Board
 * http://www.pjrc.com/teensy/usb_keyboard.html
 * Copyright (c) 2009 PJRC.COM, LLC
 * Copyright 2018 jem@seethis.link
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

#include <string.h>
#include <stdbool.h>

#include <util/delay.h>
#include <avr/eeprom.h>
#include <avr/wdt.h>

#include "usb.h"

#include "usb/descriptors.h"
#include "usb/util/usb_hid.h"

/**************************************************************************
 *
 *  Endpoint Buffer Configuration
 *
 **************************************************************************/

// initialize USB
void usb_init(void) {
    HW_CONFIG();
    USB_FREEZE();   // enable USB
    PLL_CONFIG();   // config PLL
    while (!(PLLCSR & (1<<PLOCK))) ;    // wait for PLL lock

    USB_CONFIG();   // start USB clock

    UDCON = 1;      // disconnect attach resistor
    _delay_ms(10);
    UDCON = 0;      // enable attach resistor
}


// NOTE: All writes to the HID endpoint must match the size used in the HID
// endpoint descriptor.
static inline
void usb_write_endpoint(uint8_t ep_number, const uint8_t *src) {
    uint8_t i;
    UENUM = ep_number;
    for (i = 0; i < EP_SIZE_VENDOR; ++i) {
        UEDATX = src[i];
    }
    UEINTX = (1<<STALLEDI) | (1<<RXSTPI) | (1<<NAKOUTI) | (1<<RWAL);
}

static inline
void usb_read_endpoint(uint8_t ep_number, uint8_t *dest) {
    uint8_t i;
    UENUM = ep_number;
    uint8_t length = UEBCLX;
    for (i = 0; i < length; ++i) {
        dest[i] = UEDATX;
    }
    UEINTX = 0x6B;
}

/// Checks if the given USB endpoint is ready
static inline
bool usb_is_endpoint_ready(uint8_t ep_num) {
    uint8_t result;
    UENUM = ep_num;
    result = UEINTX & (1<<RWAL);
    return result;
}

// Misc functions to wait for ready and send/receive packets
static inline
void usb_wait_in_ready(void) {
    while (!(UEINTX & (1<<TXINI))) ;
}

static inline
void usb_send_in(void) {
    UEINTX = ~(1<<TXINI);
}

#if 0
static inline
void usb_wait_receive_out(void) {
    while (!(UEINTX & (1<<RXOUTI))) ;
}

static inline
void usb_ack_out(void) {
    UEINTX = ~(1<<RXOUTI);
}
#endif

#define is_setup_packet(x) (x & (1<<RXSTPI))

#define USB_EP0_STALL() (UECONX = (1<<STALLRQ)|(1<<EPEN))

// TODO: descriptor stuff move to another file later
#include "usb/descriptors.h"

#include "usb/util/usb_hid.h"

#if 0
#define MAX_STRING_LEN 32
uint16_t string_desc_buf[MAX_STRING_LEN+32+1];
char string_copy_buf[MAX_STRING_LEN+32];
static uint8_t s_serial_string_write_pos;

static void make_string_desc(char *str) {
    char c;
    uint8_t i = 0;
    uint8_t len = 0;
    while ( ((c = str[i]) != '\0') && len != MAX_STRING_LEN) {
        string_desc_buf[i+1] = c; // char -> uint16_t
        len++;
        i++;
    }
    string_desc_buf[0] = USB_STRING_DESC_SIZE((len+1)*sizeof(uint16_t));
}

static char hexdigit_to_char(uint8_t d) {
    d = d & 0x0f;
    if (d < 0x0a) {
        return '0' + d;
    } else {
        return 'a' + (d - 0x0a);
    }
}

static void write_serial_helper(uint8_t byte) {
    string_copy_buf[s_serial_string_write_pos++] = byte;
}

static void write_serial_hex_byte(uint8_t hex_char) {
    write_serial_helper(hexdigit_to_char(hex_char >> 4));
    write_serial_helper(hexdigit_to_char(hex_char >> 0));
}

#define SERIAL_SIG_START_ADDR 0x0E
#define SERIAL_SIG_END_ADDR 0x18
#define SERIAL_LENGTH 10
static void make_serial_string(void) {
    s_serial_string_write_pos = 0;
    uint8_t i;
    for (i = 0; i < SERIAL_LENGTH; ++i) {
        write_serial_hex_byte(
            boot_signature_byte_get(SERIAL_SIG_START_ADDR + i)
        );
    }
    write_serial_helper('\0'); // (1 byte)
}
#endif

static void usb_handle_ep0(usb_request_t *req) {
    switch(req->std.bRequest) {
        case USB_REQ_GET_DESCRIPTOR: {
            uint16_t length   = 0;
            uint8_t* address = NULL;

            switch (req->get_desc.type) {
                // USB Host requested a device descriptor
                case USB_DESC_DEVICE: {
                    address = (uint8_t*)&usb_device_desc;
                    length  = sizeof(usb_device_desc);
                } break;

                // USB Host requested a configuration descriptor
                case USB_DESC_CONFIGURATION: {
                    address = (uint8_t*)&usb_config_desc;
                    length  = sizeof(usb_config_desc);
                } break;

#if 0//#if
                // USB Host requested a string descriptor
                case USB_DESC_STRING: {
                    switch (req->get_desc.index) {
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

                        case STRING_DESC_SERIAL_NUMBER: {
                            make_serial_string();
                            make_string_desc(string_copy_buf);
                            address = (raw_ptr_t)string_desc_buf;
                        } break;

                        case STRING_DESC_MANUFACTURER: {
                            address = (raw_ptr_t)((uint8_t*)usb_string_desc_1);
                        } break;

                        default:
                        case STRING_DESC_NONE: {
                            address = (raw_ptr_t)((uint8_t*)usb_string_desc_0);
                        } break;

                    }

                    if (address != 0) {
                        length = ((usb_string_desc_t*)address)->bLength;
                    }
                } break;
#endif//#endif

                // USB Host requested a HID descriptor
                case USB_DESC_HID_REPORT: {
                    switch (req->get_hid_desc.interface) {
                        case INTERFACE_VENDOR: {
                            address = (uint8_t*)hid_desc_vendor;
                            length  = sizeof_hid_desc_vendor;
                        } break;
                    }
                } break;

            }

            if (address == NULL) {
                USB_EP0_STALL();
            }

            // All our USB descriptors fit in one packet, so don't need to
            // worry about packetizing them.
            {
                uint8_t len = (req->std.wLength < 256) ? req->std.wLength : 255;

                if (len > length) {
                    len = length;
                }

                for (uint8_t i = len; i; i--) {
                    UEDATX = *address++;
                }
                usb_send_in();
            }

        } break;

        case USB_REQ_SET_ADDRESS: {
            usb_send_in();
            usb_wait_in_ready();
            UDADDR = req->std.wValue | (1<<ADDEN);
        } break;

        case USB_REQ_SET_CONFIGURATION: {
            // const uint8_t *cfg;
            // uint8_t i;

#ifdef USE_USB_CONFIGURATION
            usb_configuration = req->std.wValue;
#endif
            usb_send_in();
            // cfg = endpoint_config_table;

        } break;

        // case USB_REQ_GET_CONFIGURATION: {
        //     if (req->std.bmRequestType == 0x80) {
        //         // usb_wait_in_ready();
        //         UEDATX = usb_configuration;
        //         usb_send_in();
        //     }
        // } break;

        // case USB_REQ_GET_STATUS: {
        //     // usb_wait_in_ready();
        //     UEDATX = 0;
        //     UEDATX = 0;
        //     usb_send_in();
        // } break;

    }
}

#if 0
static void usb_hid_request(usb_request_std_t *req) {
    switch (req->wIndex) {
        case INTERFACE_BOOT_KEYBOARD: {
            if (req->bmRequestType == 0xA1) {
                if (req->bRequest == HID_GET_REPORT) {
                    // usb_wait_in_ready();
                    usb_write_endpoint(0, (uint8_t*)&kb_report, sizeof(kb_report));
                    usb_send_in();
                    return;
                }
                if (req->bRequest == HID_GET_IDLE) {
                    // usb_wait_in_ready();
                    UEDATX = keyboard_idle_config;
                    usb_send_in();
                    return;
                }
                if (req->bRequest == HID_GET_PROTOCOL) {
                    // usb_wait_in_ready();
                    UEDATX = keyboard_protocol;
                    usb_send_in();
                    return;
                }
            }
            if (req->bmRequestType == 0x21) {
                if (req->bRequest == HID_SET_REPORT) {
                    // usb_wait_receive_out();
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

    }

    USB_EP0_STALL();
}
#endif

#define MAX_EP_NUM 2

// USB Device Interrupt - handle all device-level events
// the transmit buffer flushing is triggered by the start of frame
static void usb_gen_isr(void) {
    uint8_t irq_flags;
    // static uint8_t has_seen_setup_packet = 0;

    irq_flags = UDINT;
    UDINT = 0;

    // if (has_seen_setup_packet) {
    //     wdt_reset();
    // }

    // USB end of reset interrupt
    if (irq_flags & (1<<EORSTI)) {
        // has_seen_setup_packet = 1;
#if 0
        uint8_t i;
        for (i = 0; i <= MAX_EP_NUM; ++i) {
            UENUM = i;
            UECONX = (1<<EPEN);
            if (i) {
                UECFG0X = EP_TYPE_CONTROL;
            } else {
                UECFG0X = 0;
            }
            UECFG1X = EP_SIZE(ENDPOINT0_SIZE) | EP_SINGLE_BUFFER;
            UEIENX = (1<<RXSTPE);
        }
#else
        UENUM = 0;
        UECONX = (1<<EPEN);
        UECFG0X = EP_TYPE_CONTROL;
        UECFG1X = EP_SIZE(ENDPOINT0_SIZE) | EP_SINGLE_BUFFER;
        UEIENX = (1<<RXSTPE);

        UENUM = EP_NUM_VENDOR_IN;
        UECONX = (1<<EPEN);

        UECFG0X = EP_TYPE_INTERRUPT_IN;
        UECFG1X = EP_SIZE(ENDPOINT0_SIZE) | EP_SINGLE_BUFFER;

        UENUM = EP_NUM_VENDOR_OUT;
        UECONX = (1<<EPEN);

        UECFG0X = EP_TYPE_INTERRUPT_OUT;
        UECFG1X = EP_SIZE(ENDPOINT0_SIZE) | EP_SINGLE_BUFFER;
#endif

        UERST = 0;
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

// USB Endpoint Interrupt - endpoint 0 is handled here.  The
// other endpoints are manipulated by the user-callable
// functions, and the start-of-frame interrupt.
//
// ISR(USB_COM_vect) {
static void usb_com_isr(void) {
    usb_request_t req;
    UENUM = 0;

    if ( !(is_setup_packet(UEINTX) ) ) {
        return;
    }

    usb_read_endpoint(0, (uint8_t*)&req);
    UEINTX = ~((1<<RXSTPI) | (1<<RXOUTI) | (1<<TXINI));

    const uint8_t req_type = req.val.bmRequestType & USB_REQTYPE_TYPE_MASK;

    switch (req_type) {
        case USB_REQTYPE_TYPE_STANDARD: {
            const uint8_t recipient = req.val.bmRequestType & USB_REQTYPE_RECIPIENT_MASK;
            switch (recipient) {
                case USB_REQTYPE_RECIPIENT_DEVICE: {
                    // usb_handle_device_request();
                    usb_handle_ep0(&req);
                } break;

                case USB_REQTYPE_RECIPIENT_INTERFACE: {
                    switch (req.val.bRequest) {
#if 0
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
#endif

                        case USB_REQ_GET_DESCRIPTOR: {
                            usb_handle_ep0(&req);
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

        // case USB_REQTYPE_TYPE_CLASS: {
        //     usb_hid_request((usb_request_std_t*)&req);
        // } break;

        default: {
            // stall on unsupported requests
            USB_EP0_STALL();
        } break;
    }
}

enum {
    USB_CMD_VERSION = 0,
    USB_CMD_INFO = 1,
    USB_CMD_ERASE = 2,
    USB_CMD_SPM = 3,
    USB_CMD_WRITE_EEPROM = 4,
    USB_CMD_RESET = 5,
};

static void spm_leap_cmd(uint16_t addr, uint8_t spmCmd, uint8_t spmCmd2, uint16_t optValue);

void usb_poll(void) {
    usb_com_isr();
    usb_gen_isr();

    if (usb_is_endpoint_ready(EP_NUM_VENDOR_OUT)) {
        uint8_t data[EP_OUT_SIZE_VENDOR];
        usb_read_endpoint(
            EP_NUM_VENDOR_OUT,
            data
        );

        uint8_t cmd = data[0];
        // uint16_t address = *((uint16_t*)(data+1));
        uint16_t address = (data[2]<<8) | data[1];
        uint8_t size = data[5];

        switch(cmd) {
            // Format:
            //
            // data[0]: USB_CMD_SPM
            // data[1:2]: spm Z address
            // data[3]: spm action
            // data[4]: spm action 2
            // data[5]: repeat count
            // data[6:7]: r0:r1 spm data
            case USB_CMD_SPM: {
                const uint8_t spm_action = data[3];
                const uint8_t spm_action2 = data[4];
                for (uint8_t i = 6; i < size; i+=2) {
                    // const uint16_t spm_data = *((uint16_t*)&data[i]);
                    const uint16_t spm_data = (data[i+1]<<8) | data[i];
                    spm_leap_cmd(
                        address+i - 6,
                        spm_action,
                        spm_action2,
                        spm_data
                    );
                }
            } break;

            // data[0]: USB_CMD_WRITE_EEPROM
            // data[1:2]: eeprom write start address
            // data[3]: number of bytes to write
            // data[4:...]: the data to be written
            case USB_CMD_WRITE_EEPROM: {
                for (uint8_t i = 6; i < size; ++i) {
                    eeprom_write_byte((uint8_t*)address, data[i]);
                    address++;
                }
            } break;

            case USB_CMD_RESET: {
                UDCON = 1;      // disconnect attach resistor
                while(1); // wait for wdt to timeout to cause a reset
            } break;

            default: {
            } break;
        }

        // load response value
        data[0] = USB_CMD_INFO;
        data[1] = BOOTLOADER_VERSION;
        data[2] = CHIP_ID | BOOT_SIZE;

        usb_write_endpoint(
            EP_NUM_VENDOR_IN,
            data
        );

    }
}

static void spm_leap_cmd(uint16_t addr, uint8_t spmCmd, uint8_t spmCmd2, uint16_t optValue) {
    asm volatile(
        "push r10\n"
        "push r11\n"
        "push r0\n"
        "push r1\n"
        "push r30\n"
        "push r31\n"

        // NOTE: bootloader always waits after executing the SPM instruction,
        // so don't need to check it here.

        // For the `call_spm_fn` function, the following registers are used
        // * Z[r30:r31]: word address which the command will operate on
        // * [r0:r1]: optional value used by the command
        // * r20: command value loaded into the SPMCSR register
        "movw r0, %[optValue] \n" // set the value to be written
        "mov r10, %[spmCmd]\n"    // SPMCSR value
        "mov r11, %[spmCmd2]\n"    // SPMCSR value
        "mov r30, %A[addr]\n"
        "mov r31, %B[addr]\n"

        "call call_spm\n"

        // Return from the bootloader, pop values from stack and return
        "pop r31\n"
        "pop r30\n"
        "pop r1\n"
        "pop r0\n"
        "pop r11\n"
        "pop r10\n"
            // output registers
            : "=r" (addr)                                   // %0
            // input registers
            : [spmCmd] "r" (spmCmd),                        // %1
              [spmCmd2] "r" (spmCmd2),                      // %2
              [optValue] "r" (optValue),                    // %3
              [addr] "0" (addr),                            // %4
              [SPM_CSR] "I" (_SFR_IO_ADDR(SPMCSR))          // %5
    );
}
