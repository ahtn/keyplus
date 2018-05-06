// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include "core/util.h"

#include "usb/util/descriptor_defs.h"
#include "usb/util/requests.h"

#define USB_VERSION_ACCESS_TYPE         USB_VERSION_HID_INTERFACE_2

typedef struct usb_config_desc_keyboard_t {
    usb_config_desc_t conf;

    usb_interface_desc_t intf0;
    usb_hid_desc_t hid0;
    usb_endpoint_desc_t ep1in;

    usb_interface_desc_t intf1;
    usb_hid_desc_t hid1;
    usb_endpoint_desc_t ep2in;

    usb_interface_desc_t intf2;
    usb_hid_desc_t hid2;
    usb_endpoint_desc_t ep3in;
    usb_endpoint_desc_t ep3out;
} usb_config_desc_keyboard_t;

// endpoint and interface numbers
#define INTERFACE_BOOT_KEYBOARD     0
#define INTERFACE_SHARED_HID        1
#define INTERFACE_VENDOR            2

#define NUM_INTERFACES (INTERFACE_VENDOR+1)

#define EP_NUM_BOOT_KEYBOARD    1
#define EP_NUM_SHARED_HID       2

#define EP_NUM_VENDOR_IN        3
#define EP_NUM_VENDOR_OUT       3

#define EP_NUM_NKRO_KEYBOARD    2
#define EP_NUM_MEDIA            2
#define EP_NUM_MOUSE            2

// endpoint sizes
#define VENDOR_REPORT_SIZE  0x40
#define EP_SIZE_VENDOR      0x40
#define EP0_SIZE            0x40

// EP 1 -> boot keyboard
#define EP_IN_SIZE_BOOT_KEYBOARD    0x08
#define EP_OUT_SIZE_BOOT_KEYBOARD   0

// EP 2 -> shared hid (media, nkro, mouse)
// #define EP_IN_SIZE_SHARED_HID       0x20
#define EP_IN_SIZE_SHARED_HID       0x08
#define EP_OUT_SIZE_SHARED_HID      0

// EP 3 -> vendor in/out
#define EP_IN_SIZE_VENDOR           EP_SIZE_VENDOR
#define EP_OUT_SIZE_VENDOR          EP_SIZE_VENDOR

#define EP0_IN_SIZE     EP0_SIZE
#define EP1_IN_SIZE     EP_IN_SIZE_BOOT_KEYBOARD
#define EP2_IN_SIZE     EP_IN_SIZE_SHARED_HID
#define EP3_IN_SIZE     EP_IN_SIZE_VENDOR

#define EP0_OUT_SIZE    EP0_SIZE
#define EP1_OUT_SIZE    EP_OUT_SIZE_BOOT_KEYBOARD
#define EP2_OUT_SIZE    EP_OUT_SIZE_SHARED_HID
#define EP3_OUT_SIZE    EP_OUT_SIZE_VENDOR

// report intervals for enpdoints (in ms)
#define REPORT_INTERVAL_BOOT_KEYBOARD   1
#define REPORT_INTERVAL_SHARED_HID      1
#define REPORT_INTERVAL_VENDOR_IN       1
#define REPORT_INTERVAL_VENDOR_OUT      1

// string descriptors
#define USB_STRING_DESC_COUNT 0

#if USB_STRING_DESC_COUNT == 0
#  define STRING_DESC_NONE              0
#  define STRING_DESC_MANUFACTURER      0
#  define STRING_DESC_PRODUCT           0
#  define STRING_DESC_SERIAL_NUMBER     0
#else
#  define STRING_DESC_NONE              0
#  define STRING_DESC_MANUFACTURER      1
#  define STRING_DESC_PRODUCT           2
#  define STRING_DESC_SERIAL_NUMBER     3
#endif

#define REPORT_ID_SYSTEM    1
#define REPORT_ID_CONSUMER  2
#define REPORT_ID_NKRO      3
#define REPORT_ID_MOUSE     4


extern ROM const usb_config_desc_keyboard_t usb_config_desc;
extern ROM const usb_device_desc_t usb_device_desc;
extern ROM const uint16_t usb_string_desc_0[2];
extern ROM const uint16_t usb_string_desc_1[8];
extern ROM const uint16_t usb_string_desc_2[];
extern ROM const uint16_t usb_string_desc_3[];

extern ROM const uint8_t sizeof_hid_desc_boot_keyboard;
extern ROM const uint8_t hid_desc_boot_keyboard[];

extern ROM const uint8_t sizeof_hid_desc_shared_hid;
extern ROM const uint8_t hid_desc_shared_hid[];

extern ROM const uint8_t sizeof_hid_desc_vendor;
extern ROM const uint8_t hid_desc_vendor[];

void usb_ep0_packetizer_data_set(const ROM uint8_t *data, uint16_t size);
void usb_ep0_packetizer_data_send(void);
void usb_get_descriptor(const XRAM usb_request_t *request);
