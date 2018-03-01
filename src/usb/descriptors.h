// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include "core/util.h"

#include "usb/util/descriptor_defs.h"
#include "usb/util/requests.h"

#include "usb_user_impl.h"

#if USE_WEBUSB
#include "usb/util/webusb.h"
#endif

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

    usb_interface_desc_t intf3;
    usb_hid_desc_t hid3;
    usb_endpoint_desc_t ep4in;
    usb_endpoint_desc_t ep4out;

    usb_interface_desc_t intf4;
    usb_hid_desc_t hid4;
    usb_endpoint_desc_t ep5in;

#ifdef USE_WEBUSB
    usb_webusb_desc_t webusb;
#endif
} usb_config_desc_keyboard_t;

// endpoint and interface numbers
#define INTERFACE_BOOT_KEYBOARD 0
#define INTERFACE_MOUSE 1
#define INTERFACE_MEDIA 2
#define INTERFACE_VENDOR 3
#define INTERFACE_NKRO_KEYBOARD 4
#define NUM_INTERFACES (INTERFACE_NKRO_KEYBOARD+1)

#define EP_NUM_BOOT_KEYBOARD    1
#define EP_NUM_MOUSE            2
#define EP_NUM_MEDIA            3
#define EP_NUM_VENDOR           4
#define EP_NUM_NKRO_KEYBOARD    5

// endpoint sizes
#define EP_SIZE_VENDOR 0x40
#define EP0_SIZE 0x40

#define EP_IN_SIZE_BOOT_KEYBOARD    0x08
#define EP_IN_SIZE_MOUSE            0x08
#define EP_IN_SIZE_MEDIA            0x08
#define EP_IN_SIZE_VENDOR           EP_SIZE_VENDOR
#define EP_IN_SIZE_NKRO_KEYBOARD    0x20

#define EP_OUT_SIZE_BOOT_KEYBOARD   0
#define EP_OUT_SIZE_MOUSE           0
#define EP_OUT_SIZE_MEDIA           0
#define EP_OUT_SIZE_VENDOR          EP_SIZE_VENDOR
#define EP_OUT_SIZE_NKRO_KEYBOARD   0

#define EP0_IN_SIZE EP0_SIZE
#define EP1_IN_SIZE EP_IN_SIZE_BOOT_KEYBOARD
#define EP2_IN_SIZE EP_IN_SIZE_MOUSE
#define EP3_IN_SIZE EP_IN_SIZE_MEDIA
#define EP4_IN_SIZE EP_IN_SIZE_VENDOR
#define EP5_IN_SIZE EP_IN_SIZE_NKRO_KEYBOARD

#define EP0_OUT_SIZE EP0_SIZE
#define EP1_OUT_SIZE 0
#define EP2_OUT_SIZE 0
#define EP3_OUT_SIZE 0
#define EP4_OUT_SIZE EP_OUT_SIZE_VENDOR
#define EP5_OUT_SIZE 0

// report intervals for enpdoints (in ms)
#define REPORT_INTERVAL_BOOT_KEYBOARD 1
#define REPORT_INTERVAL_MEDIA 10
#define REPORT_INTERVAL_MOUSE 1
#define REPORT_INTERVAL_VENDOR_IN 1
#define REPORT_INTERVAL_VENDOR_OUT 1
#define REPORT_INTERVAL_NKRO_KEYBOARD 1

// report id for media report
#define REPORT_ID_SYSTEM 0x01
#define REPORT_ID_CONSUMER 0x02

// report sizes (including report ID)
#define REPORT_SIZE_SYSTEM 0x02
#define REPORT_SIZE_CONSUMER 0x03

// string descriptors
#define USB_STRING_DESC_COUNT 5

#define STRING_DESC_NONE 0
#define STRING_DESC_MANUFACTURER 1
#define STRING_DESC_PRODUCT 2
#define STRING_DESC_SERIAL_NUMBER 3

extern ROM const usb_config_desc_keyboard_t usb_config_desc;
extern ROM const usb_device_desc_t usb_device_desc;
extern ROM const uint16_t usb_string_desc_0[];
extern ROM const uint16_t usb_string_desc_1[];
extern ROM const uint16_t usb_string_desc_2[];
extern ROM const uint16_t usb_string_desc_3[];
extern ROM const uint8_t sizeof_hid_desc_boot_keyboard;
extern ROM const uint8_t hid_desc_boot_keyboard[];
extern ROM const uint8_t sizeof_hid_desc_media;
extern ROM const uint8_t hid_desc_media[];
extern ROM const uint8_t sizeof_hid_desc_mouse;
extern ROM const uint8_t hid_desc_mouse[];
extern ROM const uint8_t sizeof_hid_desc_vendor;
extern ROM const uint8_t hid_desc_vendor[];
extern ROM const uint8_t sizeof_hid_desc_nkro_keyboard;
extern ROM const uint8_t hid_desc_nkro_keyboard[];

void usb_ep0_packetizer_data_set(const ROM uint8_t *data, uint16_t size);
void usb_ep0_packetizer_data_send(void);
void usb_get_descriptor(const XRAM usb_request_t *request);
