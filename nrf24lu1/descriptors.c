// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "usb/descriptors.h"
#include "usb/util/requests.h"

#include "nrf24lu1.h"
#include "core/settings.h"
#include "core/flash.h"

static XRAM uint16_t packetizer_data_size = 0;
const XRAM uint8_t *XRAM packetizer_data_ptr;

#define MAX_STRING_LEN 32
XRAM uint16_t string_desc_buffer[MAX_STRING_LEN];

const ROM char manufacturer_string[] = "keyplus";

// This function is used for sending descriptor data to the host that might
// not fit inside a single packet. It is called multiple times until all the
// data is sent over the ep0_in endpoint
void usb_ep0_packetizer_data_send(void) {
    uint16_t packet_size = packetizer_data_size;

    if (packet_size > EP0_SIZE) {
        packet_size = EP0_SIZE;
    }

    if (packet_size == 0) {
        USB_EP0_HSNAK();
    } else {
        flash_read(USB_EP0_IN_BUF, (uint16_t)packetizer_data_ptr, packet_size);
        USB_EP0_IN_WRITE(packet_size);

        packetizer_data_size -= packet_size;
        packetizer_data_ptr += packet_size;
    }
}

static void make_string_desc(char *str) {
    char c;
    uint8_t i = 0;
    uint8_t len = 0;
    while ( ((c = str[i]) != '\0') && len != MAX_STRING_LEN) {
        string_desc_buffer[i+1] = c; // char -> uint16_t
        len++;
        i++;
    }
    string_desc_buffer[0] = USB_STRING_DESC_SIZE((len+1)*sizeof(uint16_t));
}

static uint8_t read_info_page_byte(uint16_t addr) {
    // __asm
    //     ; addr -> (DPL, DPH)
    //     set     _INFEN          ; make movx read from info page
    //     movx    a, @dptr        ; read value at addr (dptr)
    //     clr     _INFEN          ; disable reading from info page
    //     mov     _DPL, a         ; return value is stored in DPL
    // __endasm;
    uint8_t result;
    INFEN = 1;
    result = *((XRAM uint8_t*)addr);
    INFEN = 0;
    return result;
}

static char hexdigit_to_char(uint8_t d) {
    d = d & 0x0f;
    if (d < 0x0a) {
        return '0' + d;
    } else {
        return 'a' + (d - 0x0a);
    }
}


static void make_serial_string(void) {
    uint8_t i;
    uint8_t *str = (uint8_t*)string_desc_buffer+16;
    for (i = 0; i < 5; ++i) {
        char c = read_info_page_byte(CHIPID + i);
        *str++ = hexdigit_to_char(c >> 4);
        *str++ = hexdigit_to_char(c >> 0);
    }
    *str++ = '\0';
    make_string_desc((uint8_t*)string_desc_buffer + 16); // NOTE: intentionally overlap memory
}

/* /1* // sets the data to be packetized *1/ */
/* void usb_ep0_packetizer_data_set(const ROM uint8_t *data, uint16_t size) { */
/*  packetizer_data_ptr = data; */
/*  packetizer_data_size = size; */
/* } */

// When the USB host requests a descriptor (device, configuration, string, , this function is called and loads
// the appropriate data into the packetizer.
void usb_get_descriptor(const usb_request_t *request) {
    /* const ROM uint8_t *packetizer_data_ptr = NULL; */
    /* uint16_t packetizer_data_size = 0; */
    const uint8_t desc_type = request->get_desc.type;
    if (packetizer_data_size != 0) {
        return;
    }
    packetizer_data_ptr = NULL;

    switch (desc_type) {
        case USB_DESC_DEVICE: {
            packetizer_data_ptr = (const XRAM uint8_t*) &usb_device_desc;
            packetizer_data_size = sizeof(usb_device_desc);
        } break;

        // for USB 2.0
        case USB_DESC_DEVICE_QUAL:
        case USB_DESC_OTHER_SPEED_CONF: {
            // Do nothing, this will generate an error and signifies that this is not
            // a USB 2.0 high-speed device.
        } break;

        case USB_DESC_CONFIGURATION: {
            packetizer_data_ptr = (const XRAM uint8_t*) &usb_config_desc;
            packetizer_data_size = sizeof(usb_config_desc);
        } break;

        case USB_DESC_STRING: {
            const uint8_t string_id = request->get_desc.index;
            if (string_id < USB_STRING_DESC_COUNT) {
                switch (string_id) {
                    case STRING_DESC_NONE: {
                        packetizer_data_ptr = (const XRAM uint8_t*)usb_string_desc_0;
                    }
                    case STRING_DESC_MANUFACTURER: {
                        make_string_desc(manufacturer_string);
                        packetizer_data_ptr = string_desc_buffer;
                    } break;
                    case STRING_DESC_PRODUCT: {
                        make_string_desc(g_settings.device_name);
                        packetizer_data_ptr = string_desc_buffer;
                    } break;
                    case STRING_DESC_SERIAL_NUMBER: {
                        make_serial_string();
                        packetizer_data_ptr = string_desc_buffer;
                    } break;
                }
                packetizer_data_size = flash_read_byte((uint16_t)packetizer_data_ptr);
            } else {
                USB_EP0_STALL();
            }
        } break;

        case USB_DESC_HID_REPORT: {
            const uint8_t desc_interface = request->get_hid_desc.interface;
            switch (desc_interface) {
                case INTERFACE_BOOT_KEYBOARD: {
                    packetizer_data_ptr = (const XRAM uint8_t*)hid_desc_boot_keyboard;
                    packetizer_data_size = sizeof_hid_desc_boot_keyboard;
                } break;
                case INTERFACE_MOUSE : {
                    packetizer_data_ptr = (const XRAM uint8_t*)hid_desc_mouse;
                    packetizer_data_size = sizeof_hid_desc_mouse;
                } break;
                case INTERFACE_MEDIA: {
                    packetizer_data_ptr = (const XRAM uint8_t*)hid_desc_media;
                    packetizer_data_size = sizeof_hid_desc_media;
                } break;
                case INTERFACE_VENDOR: {
                    packetizer_data_ptr = (const XRAM uint8_t*)hid_desc_vendor;
                    packetizer_data_size = sizeof_hid_desc_vendor;
                } break;
                case INTERFACE_NKRO_KEYBOARD: {
                    packetizer_data_ptr = (const XRAM uint8_t*)hid_desc_nkro_keyboard;
                    packetizer_data_size = sizeof_hid_desc_nkro_keyboard;
                } break;
            }
        } break;
    }


    {
        // check how much the host is requesting of the descriptor
        const uint16_t req_size = request->get_desc.length;
        if (packetizer_data_size > req_size) {
            packetizer_data_size = req_size;
        }
    }

    // if (packetizer_data_size && packetizer_data_ptr) {
    if (packetizer_data_size) {
        usb_ep0_packetizer_data_send();
    } else {
        USB_EP0_STALL();
    }
}
