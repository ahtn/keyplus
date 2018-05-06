// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "usb/util/requests.h"
#include "usb/util/usb_hid.h"
#include "usb/descriptors.h"

// we include this *.c file here instead of compiling separately so the c
// compiler can calculate the hid descriptor sizes at compile time
#include "usb/hid_descriptors.c"

// NOTE: since we're not using high speed, USB 1.1 works fine here

#define USB_REVISION USB_REVISION_1_1
#define USB_HID_REVISION USB_HID_REVISION_1_11

const usb_device_desc_t usb_device_desc = {
    .bLength            = sizeof(usb_device_desc_t),
    .bDescriptorType    = USB_DESC_DEVICE,
    .bcdUSB             = USB_REVISION,
    .bDeviceClass       = 0,
    .bDeviceSubClass    = 0,
    .bDeviceProtocol    = 0,
    .bMaxPacketSize     = EP0_SIZE,
    .idVendor           = USB_VID,
    .idProduct          = USB_PID,
    .bcdDevice          = USB_DEVICE_VERSION,
#if 1
    .iManufacturer      = 0,
    .iProduct           = 0,
    .iSerialNumber      = 0,
#else
    .iManufacturer      = STRING_DESC_MANUFACTURER,
    .iProduct           = STRING_DESC_PRODUCT,
    .iSerialNumber      = STRING_DESC_SERIAL_NUMBER,
#endif
    .bNumConfigurations = 1,
};

const usb_config_desc_keyboard_t usb_config_desc = {
    // configuration descriptor
    {
        .bLength             = sizeof(usb_config_desc_t),
        .bDescriptorType     = USB_DESC_CONFIGURATION,
        .wTotalLength        = sizeof(usb_config_desc_keyboard_t),
        .bNumInterfaces      = NUM_INTERFACES,
        .bConfigurationValue = 1,
        .iConfiguration      = STRING_DESC_NONE,
        .bmAttributes        = USB_CONFIG_BUS_POWERED,
        .bMaxPower           = USB_MAX_POWER(500),
    },

    // vendor interface descriptor
    {
        .bLength            = sizeof(usb_interface_desc_t),
        .bDescriptorType    = USB_DESC_INTERFACE,
        .bInterfaceNumber   = INTERFACE_VENDOR,
        .bAlternateSetting  = 0,
        .bNumEndpoints      = 2,
        .bInterfaceClass    = USB_CLASS_HID,
        .bInterfaceSubClass = 0,
        .bInterfaceProtocol = 0, // TODO
        .iInterface         = STRING_DESC_NONE,
    },
    // vendor HID descriptor
    {
        .bLength             = sizeof(usb_hid_desc_t),
        .bDescriptorType     = USB_DESC_HID,
        .bcdHID              = USB_HID_REVISION,
        .bCountryCode        = HID_COUNTRY_NONE,
        .bNumDescriptors     = 1,
        .bDescriptorType_HID = USB_DESC_HID_REPORT,
        .wDescriptorLength   = sizeof(hid_desc_vendor),
    },
    // endpoint descriptor in
    {
        .bLength          = sizeof(usb_endpoint_desc_t),
        .bDescriptorType  = USB_DESC_ENDPOINT,
        .bEndpointAddress = USB_DIR_IN | EP_NUM_VENDOR_IN,
        .bmAttributes     = USB_EP_TYPE_INT,
        .wMaxPacketSize   = EP_SIZE_VENDOR,
        .bInterval        = REPORT_INTERVAL_VENDOR_IN,
    },
    // endpoint descriptor out
    {
        .bLength          = sizeof(usb_endpoint_desc_t),
        .bDescriptorType  = USB_DESC_ENDPOINT,
        .bEndpointAddress = USB_DIR_OUT | EP_NUM_VENDOR_OUT,
        .bmAttributes     = USB_EP_TYPE_INT,
        .wMaxPacketSize   = EP_SIZE_VENDOR,
        .bInterval        = REPORT_INTERVAL_VENDOR_OUT,
    },
};

#if 0
// language id in string 0 descriptor
const uint16_t usb_string_desc_0[2] = {
    USB_STRING_DESC_SIZE(sizeof(usb_string_desc_0)),
    HID_LANG_ID(HID_LANG_ENGLISH, HID_SUBLANG_ENGLISH_US),
};

// language id in string 0 descriptor
const uint16_t usb_string_desc_1[8] = {
    USB_STRING_DESC_SIZE(sizeof(usb_string_desc_1)),
    'k', 'e', 'y', 'p', 'l', 'u', 's'
};
#endif
