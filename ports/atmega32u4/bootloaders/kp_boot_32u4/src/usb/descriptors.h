// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include "usb/util/descriptor_defs.h"
#include "usb/util/requests.h"

typedef struct usb_config_desc_keyboard_t {
    usb_config_desc_t conf;

    usb_interface_desc_t intf3;
    usb_hid_desc_t hid3;
    usb_endpoint_desc_t ep4in;
    usb_endpoint_desc_t ep4out;
} usb_config_desc_keyboard_t;

// endpoint and interface numbers
#define INTERFACE_VENDOR 0
#define NUM_INTERFACES (INTERFACE_VENDOR+1)

// On some ports (atmega32u4), the USB hardware must assign IN and OUT endpoints
// to separate ENDPOINT numbers.
#  define EP_NUM_VENDOR_IN        1
#  define EP_NUM_VENDOR_OUT       2

// endpoint sizes
#define EP_SIZE_VENDOR 0x40
#define EP0_SIZE 0x40

#define EP_IN_SIZE_BOOT_KEYBOARD    0x08
#define EP_IN_SIZE_VENDOR           EP_SIZE_VENDOR

#define EP_OUT_SIZE_BOOT_KEYBOARD   0
#define EP_OUT_SIZE_VENDOR          EP_SIZE_VENDOR

#define EP0_IN_SIZE EP0_SIZE
#define EP1_IN_SIZE EP_IN_SIZE_BOOT_KEYBOARD
#define EP4_IN_SIZE EP_IN_SIZE_VENDOR

#define EP0_OUT_SIZE EP0_SIZE
#define EP1_OUT_SIZE 0
#define EP4_OUT_SIZE EP_OUT_SIZE_VENDOR

// report intervals for enpdoints (in ms)
#define REPORT_INTERVAL_BOOT_KEYBOARD 1
#define REPORT_INTERVAL_VENDOR_IN 1
#define REPORT_INTERVAL_VENDOR_OUT 1

#define STRING_DESC_NONE 0
// string descriptors
#if 0
#define USB_STRING_DESC_COUNT 4
#define STRING_DESC_MANUFACTURER 1
#define STRING_DESC_PRODUCT 2
#define STRING_DESC_SERIAL_NUMBER 3
#else
#define USB_STRING_DESC_COUNT 0
#endif

#define USB_DEVICE_VERSION 0x0000

extern const usb_config_desc_keyboard_t usb_config_desc;
extern const usb_device_desc_t usb_device_desc;
extern const uint8_t sizeof_hid_desc_boot_keyboard;
extern const uint8_t hid_desc_boot_keyboard[];
extern const uint8_t sizeof_hid_desc_vendor;
extern const uint8_t hid_desc_vendor[];
