// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "config.h"

#include "usb/util/requests.h"
#include "usb/util/usb_hid.h"
#include "usb/descriptors.h"

// we include this *.c file here instead of compiling separately so the c
// compiler can calculate the hid descriptor sizes at compile time
#include "usb/hid_descriptors.c"

// NOTE: since we're not using high speed, USB 1.1 works fine here

#define USB_REVISION USB_REVISION_1_1
#define USB_HID_REVISION USB_HID_REVISION_1_11

ROM const usb_device_desc_t usb_device_desc = {
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
    .iManufacturer      = STRING_DESC_MANUFACTURER,
    .iProduct           = STRING_DESC_PRODUCT,
    .iSerialNumber      = STRING_DESC_SERIAL_NUMBER,
    .bNumConfigurations = 1,
};

ROM const usb_config_desc_keyboard_t usb_config_desc = {
    // configuration descriptor
    {
        .bLength             = sizeof(usb_config_desc_t),
        .bDescriptorType     = USB_DESC_CONFIGURATION,
        .wTotalLength        = sizeof(usb_config_desc_keyboard_t),
        .bNumInterfaces      = NUM_INTERFACES,
        .bConfigurationValue = 1,
        .iConfiguration      = STRING_DESC_NONE,
        .bmAttributes        = USB_CONFIG_BUS_POWERED,
#ifdef CUSTOM_USB_CURRENT_LIMIT
        .bMaxPower           = USB_MAX_POWER(CUSTOM_USB_CURRENT_LIMIT),
#else
        .bMaxPower           = USB_MAX_POWER(500),
#endif
    },

    // boot keyboard interface descriptor
    {
        .bLength            = sizeof(usb_interface_desc_t),
        .bDescriptorType    = USB_DESC_INTERFACE,
        .bInterfaceNumber   = INTERFACE_BOOT_KEYBOARD,
        .bAlternateSetting  = 0,
        .bNumEndpoints      = 1,
        .bInterfaceClass    = USB_CLASS_HID,
        .bInterfaceSubClass = HID_SUBCLASS_BOOT,
        .bInterfaceProtocol = HID_PROTOCOL_KEYBOARD,
        .iInterface         = STRING_DESC_NONE,
    },
    // boot keyboard HID descriptor
    {
        .bLength             = sizeof(usb_hid_desc_t),
        .bDescriptorType     = USB_DESC_HID,
        .bcdHID              = USB_HID_REVISION,
        .bCountryCode        = HID_COUNTRY_NONE,
        .bNumDescriptors     = 1,
        .bDescriptorType_HID = USB_DESC_HID_REPORT,
        .wDescriptorLength   = sizeof(hid_desc_boot_keyboard),
    },
    // boot keyboard in endpoint descriptor
    {
        .bLength          = sizeof(usb_endpoint_desc_t),
        .bDescriptorType  = USB_DESC_ENDPOINT,
        .bEndpointAddress = (uint8_t)(USB_DIR_IN | EP_NUM_BOOT_KEYBOARD),
        .bmAttributes     = USB_EP_TYPE_INT,
        .wMaxPacketSize   = EP_IN_SIZE_BOOT_KEYBOARD,
        .bInterval        = REPORT_INTERVAL_BOOT_KEYBOARD,
    },

    // mouse interface descriptor
    {
        .bLength            = sizeof(usb_interface_desc_t),
        .bDescriptorType    = USB_DESC_INTERFACE,
        .bInterfaceNumber   = INTERFACE_MOUSE,
        .bAlternateSetting  = 0,
        .bNumEndpoints      = 1,
        .bInterfaceClass    = USB_CLASS_HID,
        .bInterfaceSubClass = HID_SUBCLASS_BOOT,
        .bInterfaceProtocol = HID_PROTOCOL_MOUSE, // mouse
        .iInterface         = STRING_DESC_NONE,
    },
    { // mouse HID descriptor
        .bLength             = sizeof(usb_hid_desc_t),
        .bDescriptorType     = USB_DESC_HID,
        .bcdHID              = USB_HID_REVISION,
        .bCountryCode        = HID_COUNTRY_NONE,
        .bNumDescriptors     = 1,
        .bDescriptorType_HID = USB_DESC_HID_REPORT,
        .wDescriptorLength   = sizeof(hid_desc_mouse),
    },
    { // mouse in endpoint descriptor
        .bLength          = sizeof(usb_endpoint_desc_t),
        .bDescriptorType  = USB_DESC_ENDPOINT,
        .bEndpointAddress = USB_DIR_IN | EP_NUM_MOUSE,
        .bmAttributes     = USB_EP_TYPE_INT,
        .wMaxPacketSize   = EP_IN_SIZE_MOUSE,
        .bInterval        = REPORT_INTERVAL_MOUSE,
    },

    // media interface descriptor
    {
        .bLength            = sizeof(usb_interface_desc_t),
        .bDescriptorType    = USB_DESC_INTERFACE,
        .bInterfaceNumber   = INTERFACE_MEDIA,
        .bAlternateSetting  = 0,
        .bNumEndpoints      = 1,
        .bInterfaceClass    = USB_CLASS_HID,
        .bInterfaceSubClass = 0,
        .bInterfaceProtocol = 0, // TODO
        .iInterface         = STRING_DESC_NONE,
    },
    // media HID descriptor
    {
        .bLength             = sizeof(usb_hid_desc_t),
        .bDescriptorType     = USB_DESC_HID,
        .bcdHID              = USB_HID_REVISION,
        .bCountryCode        = HID_COUNTRY_NONE,
        .bNumDescriptors     = 1,
        .bDescriptorType_HID = USB_DESC_HID_REPORT,
        .wDescriptorLength   = sizeof(hid_desc_media),
    },
    // media endpoint descriptor
    {
        .bLength          = sizeof(usb_endpoint_desc_t),
        .bDescriptorType  = USB_DESC_ENDPOINT,
        .bEndpointAddress = USB_DIR_IN | EP_NUM_MEDIA,
        .bmAttributes     = USB_EP_TYPE_INT,
        .wMaxPacketSize   = EP_IN_SIZE_MEDIA,
        .bInterval        = REPORT_INTERVAL_MEDIA,
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
        .bEndpointAddress = USB_DIR_IN | EP_NUM_VENDOR,
        .bmAttributes     = USB_EP_TYPE_INT,
        .wMaxPacketSize   = EP_SIZE_VENDOR,
        .bInterval        = REPORT_INTERVAL_VENDOR_IN,
    },
    // endpoint descriptor out
    {
        .bLength          = sizeof(usb_endpoint_desc_t),
        .bDescriptorType  = USB_DESC_ENDPOINT,
        .bEndpointAddress = USB_DIR_OUT | EP_NUM_VENDOR,
        .bmAttributes     = USB_EP_TYPE_INT,
        .wMaxPacketSize   = EP_SIZE_VENDOR,
        .bInterval        = REPORT_INTERVAL_VENDOR_OUT,
    },

    // nkro keyboard interface descriptor
    {
        .bLength            = sizeof(usb_interface_desc_t),
        .bDescriptorType    = USB_DESC_INTERFACE,
        .bInterfaceNumber   = INTERFACE_NKRO_KEYBOARD,
        .bAlternateSetting  = 0,
        .bNumEndpoints      = 1,
        .bInterfaceClass    = USB_CLASS_HID,
        .bInterfaceSubClass = 0,
        .bInterfaceProtocol = 0,
        .iInterface         = STRING_DESC_NONE,
    },

    // nkro keyboard HID descriptor
    {
        .bLength             = sizeof(usb_hid_desc_t),
        .bDescriptorType     = USB_DESC_HID,
        .bcdHID              = USB_HID_REVISION,
        .bCountryCode        = HID_COUNTRY_NONE,
        .bNumDescriptors     = 1,
        .bDescriptorType_HID = USB_DESC_HID_REPORT,
        .wDescriptorLength   = sizeof(hid_desc_nkro_keyboard),
    },
    // keyboard in endpoint descriptor
    {
        .bLength          = sizeof(usb_endpoint_desc_t),
        .bDescriptorType  = USB_DESC_ENDPOINT,
        .bEndpointAddress = USB_DIR_IN | EP_NUM_NKRO_KEYBOARD,
        .bmAttributes     = USB_EP_TYPE_INT,
        .wMaxPacketSize   = EP_IN_SIZE_NKRO_KEYBOARD,
        .bInterval        = REPORT_INTERVAL_NKRO_KEYBOARD,
    },

#ifdef USE_WEBUSB
    // webusb descriptor
    {
        .bLength = sizeof(usb_webusb_desc_t),
        // .bDescriptorType = WEBUSB;
        // .bDevCapabilityType;
        // .bReserved;
        .PlatformCapabilityUUID = WEBUSB_UUID,
        .bcdVersion = WEBUSB_BCDVERSION,
        // .bVendorCode;
        // .iLandingPage;
    }
#endif
};

// language id in string 0 descriptor
ROM const uint16_t usb_string_desc_0[2] = {
    USB_STRING_DESC_SIZE(sizeof(usb_string_desc_0)),
    HID_LANG_ID(HID_LANG_ENGLISH, HID_SUBLANG_ENGLISH_US),
};

ROM const uint16_t usb_string_desc_1[7] = {
    USB_STRING_DESC_SIZE(sizeof(usb_string_desc_1)),
    'V','e','n','d','o','r'
};

ROM const uint16_t usb_string_desc_2[7] = {
    USB_STRING_DESC_SIZE(sizeof(usb_string_desc_2)),
    'n','r','f','k','e','y',
};

ROM const uint16_t usb_string_desc_3[7] = {
    USB_STRING_DESC_SIZE(sizeof(usb_string_desc_3)),
    '0','.','1','2','3','4'
};

#ifdef USE_WEBUSB
ROM const uint8_t usb_url_desc_1[17] = {
    sizeof(usb_url_desc_1),
    WEBUSB_URL,
    WEBUSB_SCHEME_HTTP,
    '1', '2', '7', '.', '0', '.', '0', '.', '1', ':', '8', '0', '0', '0'
};
#endif
