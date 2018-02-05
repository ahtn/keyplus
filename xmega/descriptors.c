// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include <avr/pgmspace.h>
#include <string.h>

#include "xmega/usb_xmega.h"

#include "core/flash.h"
#include "core/settings.h"

#include "usb_reports/keyboard_report.h"
#include "usb_reports/mouse_report.h"
#include "usb_reports/vendor_report.h"

#include "usb/descriptors.h"
#include "usb/util/usb_hid.h"

#define MANUFACTURER_STRING "keyplus"

// waste some ram
char manufacturer_string[] = MANUFACTURER_STRING;

#define MAX_STRING_LEN 32
uint16_t string_desc_buf[MAX_STRING_LEN+1];
char string_copy_buf[MAX_STRING_LEN];

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

uint8_t read_production_signature_byte(uint16_t address) {
    uint8_t result;
    NVM_CMD = NVM_CMD_READ_CALIB_ROW_gc;
    result = pgm_read_byte(address);
    NVM_CMD = NVM_CMD_NO_OPERATION_gc;
    return result;
}

// USB string used for serial number of the device
// string format (17 byte ascii): "LLLLL-WW-XXXXYYYY"
// LLLLL: 5byte ascii lot number
// WW: wafer number in hexadecimal
// XXXX: 2 byte X wafer coordinate in hexadecimal
// YYYY: 2 byte Y wafer coordinate in hexadecimal
#define SERIAL_STRING_LENGTH 18
static uint8_t s_serial_string_write_pos = 0;

static void write_serial_helper(uint8_t byte) {
    string_copy_buf[s_serial_string_write_pos++] = byte;
}

static char hexdigit_to_char(uint8_t d) {
    d = d & 0x0f;
    if (d < 0x0a) {
        return '0' + d;
    } else {
        return 'a' + (d - 0x0a);
    }
}

static void write_serial_hex_byte(uint8_t hex_char) {
    write_serial_helper(hexdigit_to_char(hex_char >> 4));
    write_serial_helper(hexdigit_to_char(hex_char >> 0));
}

static void make_serial_string(void) {
    // Load the unique serial number into the serial number string of the
    // USB device descriptor. Convert the non-ascii components to ascii.
    uint8_t i;
    s_serial_string_write_pos = 0;

    { // lot number (5 byte)
        uint16_t addr = offsetof(NVM_PROD_SIGNATURES_t, LOTNUM0);
        for (i = 0; i < 5; ++i) {
            write_serial_helper(read_production_signature_byte(addr++));
        }
    }
    write_serial_helper('-'); // (1 byte)
    { // wafer number (2 byte)
        const uint16_t addr = offsetof(NVM_PROD_SIGNATURES_t, WAFNUM);
        const uint8_t wafer_num = read_production_signature_byte(addr);
        write_serial_hex_byte(wafer_num);
    }
    write_serial_helper('-'); // (1 byte)
    { // xy pos (8 byte)
        uint16_t addr = offsetof(NVM_PROD_SIGNATURES_t, COORDX0);
        for (i = 0; i < 2; ++i) {
            const uint8_t coord0 = read_production_signature_byte(addr++);
            const uint8_t coord1 = read_production_signature_byte(addr++);
            write_serial_hex_byte(coord1);
            write_serial_hex_byte(coord0);
        }
    }
    write_serial_helper('\0'); // (1 byte)
    // 18 byte total
}

void usb_cb_get_descriptor(uint8_t type, uint8_t index, uint8_t interface, fat_ptr_t* ptr) {
    uint16_t size    = 0;
    raw_ptr_t address = (raw_ptr_t)NULL;

    // most of our descriptors are stored in flash, so default to flash
    ptr->type = PTR_FLASH;

    switch (type) {
        case USB_DTYPE_Device: {
            address = (raw_ptr_t)&usb_device_desc;
            size    = sizeof(usb_device_desc);
        } break;

        case USB_DTYPE_Configuration: {
            address = (raw_ptr_t)&usb_config_desc;
            size    = sizeof(usb_config_desc);
        } break;

        case USB_DTYPE_HID_REPORT: {
            switch (interface) {
                case INTERFACE_BOOT_KEYBOARD: {
                    address = (raw_ptr_t)hid_desc_boot_keyboard;
                    size = sizeof_hid_desc_boot_keyboard;
                } break;
                case INTERFACE_MOUSE: {
                    address = (raw_ptr_t)hid_desc_mouse;
                    size = sizeof_hid_desc_mouse;
                } break;
                case INTERFACE_MEDIA: {
                    address = (raw_ptr_t)hid_desc_media;
                    size = sizeof_hid_desc_media;
                } break;
                case INTERFACE_VENDOR: {
                    address = (raw_ptr_t)hid_desc_vendor;
                    size = sizeof_hid_desc_vendor;
                } break;
                case INTERFACE_NKRO_KEYBOARD: {
                    address = (raw_ptr_t)hid_desc_nkro_keyboard;
                    size = sizeof_hid_desc_nkro_keyboard;
                } break;
            }
        } break;

        case USB_DTYPE_String: {
            switch (index) {
                case STRING_DESC_NONE: {
                    address = (raw_ptr_t)usb_string_desc_0;
                } break;

                case STRING_DESC_MANUFACTURER: {
                    ptr->type = PTR_DATA;
                    make_string_desc(manufacturer_string);
                    address = (raw_ptr_t)string_desc_buf;
                } break;

                case STRING_DESC_PRODUCT: {
                    ptr->type = PTR_DATA;
                    flash_read(
                        (uint8_t*) string_copy_buf,
                        (flash_ptr_t)&(GET_SETTING(device_name)),
                        MAX_STRING_LEN
                    );
                    make_string_desc(string_copy_buf);
                    address = (raw_ptr_t)string_desc_buf;
                } break;

                // case STRING_DESC_SERIAL_NUMBER: {
                //     address = (raw_ptr_t)usb_string_desc_3;
                // } break;

                case STRING_DESC_SERIAL_NUMBER: {
                    make_serial_string();
                    make_string_desc(string_copy_buf);
                    ptr->type = PTR_DATA;
                    address = (raw_ptr_t)string_desc_buf;
                } break;
            }

            if (address != 0) {
                if (ptr->type == PTR_FLASH) {
                    size = flash_read_byte((flash_ptr_t)&(((USB_StringDescriptor*)address)->bLength));
                } else if (ptr->type == PTR_DATA) {
                    size = (((USB_StringDescriptor*)address)->bLength);
                }
            }
        } break;
    }

    ptr->size = size;
    ptr->ptr.raw = address;
}

uint8_t ep1_buf_in[EP1_IN_SIZE] = {0};
uint8_t ep2_buf_in[EP2_IN_SIZE] = {0};
uint8_t ep3_buf_in[EP3_IN_SIZE] = {0};
uint8_t ep4_buf_in[EP4_IN_SIZE] = {0};
uint8_t ep5_buf_in[EP5_IN_SIZE] = {0};

uint8_t ep4_buf_out[EP4_OUT_SIZE] = {0};

void usb_cb_reset(void) {
    /* usb_ep_disable(0x01); */
    /* usb_ep_enable(0x81, USB_EP_TYPE_INTERRUPT, 64); */
    /* usb_ep_reset(0x81); */
    /* usb_ep_disable(0x81); */

    // in endpoints
    usb_xmega_endpoints[1].in.STATUS = USB_EP_BUSNACK0_bm;
    usb_xmega_endpoints[1].in.CTRL = USB_EP_TYPE_BULK_gc | USB_EP_size_to_gc(EP1_IN_SIZE);
    usb_xmega_endpoints[1].in.DATAPTR = (uint16_t)ep1_buf_in;

    usb_xmega_endpoints[2].in.STATUS = USB_EP_BUSNACK0_bm;
    usb_xmega_endpoints[2].in.CTRL = USB_EP_TYPE_BULK_gc | USB_EP_size_to_gc(EP2_IN_SIZE);
    usb_xmega_endpoints[2].in.DATAPTR = (uint16_t)ep2_buf_in;

    usb_xmega_endpoints[3].in.STATUS = USB_EP_BUSNACK0_bm;
    usb_xmega_endpoints[3].in.CTRL = USB_EP_TYPE_BULK_gc | USB_EP_size_to_gc(EP3_IN_SIZE);
    usb_xmega_endpoints[3].in.DATAPTR = (uint16_t)ep3_buf_in;

    usb_xmega_endpoints[4].in.STATUS = USB_EP_BUSNACK0_bm;
    usb_xmega_endpoints[4].in.CTRL = USB_EP_TYPE_BULK_gc | USB_EP_size_to_gc(EP4_IN_SIZE);
    usb_xmega_endpoints[4].in.DATAPTR = (uint16_t)ep4_buf_in;

    usb_xmega_endpoints[5].in.STATUS = USB_EP_BUSNACK0_bm;
    usb_xmega_endpoints[5].in.CTRL = USB_EP_TYPE_BULK_gc | USB_EP_size_to_gc(EP5_IN_SIZE);
    usb_xmega_endpoints[5].in.DATAPTR = (uint16_t)ep5_buf_in;

    // out endpoints
    usb_xmega_endpoints[4].out.STATUS = 0;
    usb_xmega_endpoints[4].out.CTRL = USB_EP_TYPE_BULK_gc | USB_EP_size_to_gc(EP4_OUT_SIZE);
    usb_xmega_endpoints[4].out.DATAPTR = (uint16_t)ep4_buf_out;
}

bool usb_cb_set_configuration(uint8_t config) {
    if (config <= 1) {
        return true;
    } else {
        return false;
    }
}

void usb_cb_completion(void) {
}

uint8_t usbHidIdle = 0;      // forever
uint8_t usbFrameCnt = 0;  // reset idle counter

// HID request codes
#define USB_REQ_HID_GET_REPORT    0x01
#define USB_REQ_HID_GET_IDLE      0x02
#define USB_REQ_HID_GET_PROTOCOL  0x03
#define USB_REQ_HID_SET_REPORT    0x09
#define USB_REQ_HID_SET_IDLE      0x0a
#define USB_REQ_HID_SET_PROTOCOL  0x0b
void usb_cb_control_setup(void) {

    if ((usb_setup.bmRequestType & USB_REQTYPE_TYPE_MASK) == 0x20) {
        uint8_t bRequest = usb_setup.bRequest;
        uint8_t interface = usb_setup.wIndex;
        uint8_t length = usb_setup.wLength;
        uint8_t report_id = LSB(usb_setup.wValue);
        /* uint8_t interface = 1; */

        if (bRequest == USB_REQ_HID_SET_REPORT) {
            /* TODO: */
            usb_ep0_stall();
        } else if (bRequest == USB_REQ_HID_GET_REPORT) {
            /* uint8_t report_id = usbRequest.wValueLSB; */
            // this requests the HID report we defined with the HID report descriptor.
            // this is usually sent over EP1 IN, but can be sent over EP0 too.
            //

            /* TODO: clean this up */
            switch (interface) {
                case INTERFACE_BOOT_KEYBOARD:
                    memcpy(ep0_buf_in, (uint8_t*)&g_boot_keyboard_report, sizeof(hid_report_boot_keyboard_t));
                    usb_ep0_in(sizeof(hid_report_boot_keyboard_t));
                    usb_ep0_out();
                    break;
                case INTERFACE_MOUSE:
                    memcpy(ep0_buf_in, (uint8_t*)&g_mouse_report, sizeof(hid_report_mouse_t));
                    usb_ep0_in(sizeof(hid_report_mouse_t));
                    usb_ep0_out();
                    break;
                case INTERFACE_MEDIA:
                    if (report_id == REPORT_ID_SYSTEM) {
                        ep0_buf_in[0] = REPORT_ID_SYSTEM;
                        ep0_buf_in[1] = 0;
                        usb_ep0_in(REPORT_SIZE_SYSTEM);
                        usb_ep0_out();
                    } else if (report_id == REPORT_ID_CONSUMER) {
                        ep0_buf_in[0] = REPORT_ID_CONSUMER;
                        ep0_buf_in[1] = 0;
                        ep0_buf_in[2] = 0;
                        usb_ep0_in(length);
                        usb_ep0_out();
                    } else {
                        usb_ep0_in(0);
                        usb_ep0_out();
                    }
                    break;
                case INTERFACE_VENDOR:
                    memset(ep0_buf_in, 0, 64);
                    usb_ep0_in(64);
                    usb_ep0_out();
                    break;
                case INTERFACE_NKRO_KEYBOARD:
                    memcpy(ep0_buf_in, (uint8_t*)&g_nkro_keyboard_report, sizeof(hid_report_nkro_keyboard_t));
                    usb_ep0_in(sizeof(hid_report_nkro_keyboard_t));
                    usb_ep0_out();
                    break;
            }
        } else if (bRequest == USB_REQ_HID_GET_IDLE) {
            ep0_buf_in[0] = usbHidIdle;
            usb_ep0_in(1);
            usb_ep0_out();
        } else if (bRequest == USB_REQ_HID_SET_IDLE) {
            /* usbHidIdle = usbRequest.wValueMSB; */

            /* usbFrameCnt = 0;  // reset idle counter */

            // send an empty packet and ACK the request
            usb_ep0_in(0);
            usb_ep0_out();

        } else {
            usb_ep0_stall();
        }
    } else {
        usb_ep0_stall();
    }
}


void usb_cb_control_in_completion(void) {
}

void usb_cb_control_out_completion(void) {
}

bool usb_cb_set_interface(uint16_t interface, uint16_t altsetting) {
    return false;
}
