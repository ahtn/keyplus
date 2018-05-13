// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "usb/descriptors.h"
#include "usb/util/requests.h"

#include "nrf24lu1.h"
#include "core/settings.h"

static XRAM uint16_t packetizer_data_size = 0;
static const uint8_t *XRAM packetizer_data_ptr;

// TODO: Should probably write this to the USB EP0 buffer memory directly
#define SERIAL_STR_DESC_LEN (10+1)
static XRAM uint16_t s_serial_str_desc_buf[SERIAL_STR_DESC_LEN];

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
        // Copy as many bytes as we can into endpoint 0
        // NOTE: Instead of using a function like memcpy(), we use a for loop.
        // This is because the functions for copying memory are not re-entrant
        // in SDCC when targeting 8051. So if this interrupt was triggered
        // while the code was using them, it would cause undefined behavior.
        {
            uint8_t i;
            for (i = 0; i < packet_size; ++i) {
                USB_EP0_IN_BUF[i] = packetizer_data_ptr[i];
            }
        }
        USB_EP0_IN_WRITE(packet_size);

        packetizer_data_size -= packet_size;
        packetizer_data_ptr += packet_size;
    }
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

static void load_serial_number_str_desc(void) {
    uint8_t i;
    uint16_t *str = s_serial_str_desc_buf;

    // First load length
    *str++ = USB_STRING_DESC_SIZE(sizeof(s_serial_str_desc_buf));

    // Then load the 5 byte chip ID as a 10 character hex string
    // Note: UTF-16LE
    for (i = 0; i < 5; ++i) {
        char c = read_info_page_byte(CHIPID + i);
        *str++ = hexdigit_to_char(c >> 4);
        *str++ = hexdigit_to_char(c >> 0);
    }
}

// When the USB host requests a descriptor (device, configuration, string, , this function is called and loads
// the appropriate data into the packetizer.
void usb_get_descriptor(const XRAM usb_request_t *request) {
    const uint8_t desc_type = request->get_desc.type;
    if (packetizer_data_size != 0) {
        return;
    }
    packetizer_data_ptr = NULL;

    switch (desc_type) {
        case USB_DESC_DEVICE: {
            packetizer_data_ptr = (uint8_t*)&usb_device_desc;
            packetizer_data_size = sizeof(usb_device_desc);
        } break;

        // for USB 2.0
        case USB_DESC_DEVICE_QUAL:
        case USB_DESC_OTHER_SPEED_CONF: {
            // Do nothing, this will generate an error and signifies that this is not
            // a USB 2.0 high-speed device.
        } break;

        case USB_DESC_CONFIGURATION: {
            packetizer_data_ptr = (uint8_t*)&usb_config_desc;
            packetizer_data_size = sizeof(usb_config_desc);
        } break;

        case USB_DESC_STRING: {
            const uint8_t string_id = request->get_desc.index;
            if (string_id < USB_STRING_DESC_COUNT) {
                switch (string_id) {
                    case STRING_DESC_NONE: {
                        packetizer_data_ptr = usb_string_desc_0;
                    }
                    case STRING_DESC_MANUFACTURER: {
                        packetizer_data_ptr = usb_string_desc_1;
                    } break;
                    case STRING_DESC_PRODUCT: {
                        packetizer_data_ptr = GET_SETTING(device_name);
                        if (packetizer_data_ptr[0] > SETTINGS_NAME_STORAGE_SIZE) {
                            packetizer_data_ptr = NULL;
                        }
                    } break;
                    case STRING_DESC_SERIAL_NUMBER: {
                        load_serial_number_str_desc();
                        packetizer_data_ptr = s_serial_str_desc_buf;
                    } break;
                }

                packetizer_data_size = packetizer_data_ptr[0];
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
