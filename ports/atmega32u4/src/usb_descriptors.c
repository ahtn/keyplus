
#include "usb/descriptors.h"

void usb_cb_get_descriptor(
    uint8_t type,
    uint8_t index,
    uint8_t interface,
    fat_ptr_t* ptr
) {
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
                    uint8_t len;
                    flash_read(
                        &len,
                        (flash_ptr_t)(GET_SETTING(device_name)),
                        1
                    );
                    if (len <= SETTINGS_NAME_STORAGE_SIZE) {
                        address = (flash_ptr_t)GET_SETTING(device_name);
                    }
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
