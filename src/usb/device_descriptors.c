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

// #define USB_REVISION USB_REVISION_1_1
// #define USB_REVISION USB_REVISION_2_0
#define USB_REVISION USB_REVISION_2_0_1
// #define USB_REVISION USB_REVISION_2_1

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
        .bMaxPower           = 250, //
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

#if !USE_WEBUSB || USE_EXTRA_INTERFACE
    // vendor interface descriptor
    .intf3 = {
        .bLength            = sizeof(usb_interface_desc_t),
        .bDescriptorType    = USB_DESC_INTERFACE,
        .bInterfaceNumber   = INTERFACE_VENDOR,
        .bAlternateSetting  = 0,
        .bNumEndpoints      = 2,
        .bInterfaceClass    = USB_CLASS_HID,
        .bInterfaceSubClass = USB_CLASS_VENDOR,
        .bInterfaceProtocol = USB_CLASS_VENDOR,
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
#else
    // vendor interface descriptor
    .intf3 = {
        .bLength            = sizeof(usb_interface_desc_t),
        .bDescriptorType    = USB_DESC_INTERFACE,
        .bInterfaceNumber   = INTERFACE_VENDOR,
        .bAlternateSetting  = 0,
        .bNumEndpoints      = 2,
        .bInterfaceClass    = USB_CLASS_VENDOR,
        .bInterfaceSubClass = USB_CLASS_VENDOR,
        .bInterfaceProtocol = USB_CLASS_VENDOR,
        .iInterface         = STRING_DESC_NONE,
    },
#endif

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

#if USE_WEBUSB && USE_EXTRA_INTERFACE
    .intf5 = {
        .bLength            = sizeof(usb_interface_desc_t),
        .bDescriptorType    = USB_DESC_INTERFACE,
        .bInterfaceNumber   = INTERFACE_WEBUSB,
        .bAlternateSetting  = 0,
        .bNumEndpoints      = 2,
        .bInterfaceClass    = USB_CLASS_VENDOR,
        .bInterfaceSubClass = USB_CLASS_VENDOR,
        .bInterfaceProtocol = USB_CLASS_VENDOR,
        .iInterface         = STRING_DESC_NONE,
    },
    // endpoint descriptor in
    .ep4in_duplicate = {
        .bLength          = sizeof(usb_endpoint_desc_t),
        .bDescriptorType  = USB_DESC_ENDPOINT,
        .bEndpointAddress = USB_DIR_IN | EP_NUM_VENDOR,
        .bmAttributes     = USB_EP_TYPE_INT,
        .wMaxPacketSize   = EP_IN_SIZE_WEBUSB,
        .bInterval        = REPORT_INTERVAL_WEBUSB_IN,
    },
    // endpoint descriptor out
    .ep4out_duplicate = {
        .bLength          = sizeof(usb_endpoint_desc_t),
        .bDescriptorType  = USB_DESC_ENDPOINT,
        .bEndpointAddress = USB_DIR_OUT | EP_NUM_VENDOR,
        .bmAttributes     = USB_EP_TYPE_INT,
        .wMaxPacketSize   = EP_OUT_SIZE_WEBUSB,
        .bInterval        = REPORT_INTERVAL_WEBUSB_OUT,
    },
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
ROM const bos_desc_table_t bos_desc_table = {
    .bos_desc = {
        .bLength = sizeof(usb_bos_desc_t),
        .bDescriptorType = USB_DESC_BOS,
        .wTotalLength = sizeof(bos_desc_table_t),
        .bNumDeviceCaps = 1,
    },

// webusb descriptor
    .webusb_bos_desc = {
        .bLength = sizeof(usb_webusb_desc_t),
        .bDescriptorType = USB_DESC_DEVICE_CAPABILITY,
        .bDevCapabilityType = USB_DEV_CAPABILITY_PLATFORM,
        .bReserved = 0,
        .PlatformCapabilityUUID = WEBUSB_UUID,
        .bcdVersion = WEBUSB_BCDVERSION,
        .bVendorCode = WEBUSB_VENDOR_CODE,
        .iLandingPage = WEBUSB_LANDING_PAGE,
    },
};

// // Note: Chrome will only report the landing page for urls using HTTPS
// ROM const uint8_t webusb_url_desc_1[13] = {
//     sizeof(webusb_url_desc_1),
//     WEBUSB_URL,
//     WEBUSB_SCHEME_HTTPS,
//     'k', 'e', 'y', 'p', 'l', 'u', 's', '.', 'i', 'o'
// };

ROM const uint8_t webusb_url_desc_1[17] = {
    sizeof(webusb_url_desc_1),
    WEBUSB_URL,
    WEBUSB_SCHEME_HTTP,
    'l', 'o', 'c', 'a', 'l', 'h', 'o', 's', 't', ':', '8', '0', '0', '0'
};

// ROM const uint8_t usb_url_desc_2[15] = {
//     sizeof(usb_url_desc_1),
//     WEBUSB_URL,
//     WEBUSB_SCHEME_HTTP,
//     '0', '.', '0', '.', '0', '.', '0', ':', '8', '0', '0', '0'
// };
#endif
