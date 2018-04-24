// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include "core/util.h"

#include "usb/util/descriptor_defs.h"
#include "usb/util/requests.h"

// #include "usb_user_impl.h"

typedef struct usb_config_desc_keyboard_t {
    usb_config_desc_t conf;

    usb_interface_desc_t intf0;
    usb_hid_desc_t hid0;
    usb_endpoint_desc_t ep1in;

} usb_config_desc_keyboard_t;

// endpoint and interface numbers
#define INTERFACE_BOOT_KEYBOARD 0
#define NUM_INTERFACES (INTERFACE_BOOT_KEYBOARD+1)

#define EP_NUM_BOOT_KEYBOARD    1

// endpoint sizes
#define EP_SIZE_VENDOR 0x40
#define EP0_SIZE 0x40

#define EP_IN_SIZE_BOOT_KEYBOARD    0x08
#define EP_OUT_SIZE_BOOT_KEYBOARD   0

#define EP0_IN_SIZE EP0_SIZE
#define EP1_IN_SIZE EP_IN_SIZE_BOOT_KEYBOARD

#define EP0_OUT_SIZE EP0_SIZE
#define EP1_OUT_SIZE 0

// report intervals for enpdoints (in ms)
#define REPORT_INTERVAL_BOOT_KEYBOARD 1

// string descriptors
#define USB_STRING_DESC_COUNT 0

#define REPORT_ID_CONSUMER 0
#define REPORT_ID_SYSTEM 1

#if USB_STRING_DESC_COUNT == 0
#  define STRING_DESC_NONE 0
#  define STRING_DESC_MANUFACTURER 0
#  define STRING_DESC_PRODUCT 0
#  define STRING_DESC_SERIAL_NUMBER 0
#else
#  define STRING_DESC_NONE 0
#  define STRING_DESC_MANUFACTURER 1
#  define STRING_DESC_PRODUCT 2
#  define STRING_DESC_SERIAL_NUMBER 3
#endif

extern ROM const usb_config_desc_keyboard_t usb_config_desc;
extern ROM const usb_device_desc_t usb_device_desc;
extern ROM const uint16_t usb_string_desc_0[2];
extern ROM const uint16_t usb_string_desc_1[8];
extern ROM const uint16_t usb_string_desc_2[];
extern ROM const uint16_t usb_string_desc_3[];
extern ROM const uint8_t sizeof_hid_desc_boot_keyboard;
extern ROM const uint8_t hid_desc_boot_keyboard[];

void usb_ep0_packetizer_data_set(const ROM uint8_t *data, uint16_t size);
void usb_ep0_packetizer_data_send(void);
void usb_get_descriptor(const XRAM usb_request_t *request);
