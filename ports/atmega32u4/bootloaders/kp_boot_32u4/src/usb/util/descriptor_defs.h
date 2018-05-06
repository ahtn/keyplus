// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <stdint.h>

// usb device descriptor
typedef struct usb_device_desc_t {
    uint8_t   bLength;
    uint8_t   bDescriptorType;
    uint16_t  bcdUSB;
    uint8_t   bDeviceClass;
    uint8_t   bDeviceSubClass;
    uint8_t   bDeviceProtocol;
    uint8_t   bMaxPacketSize;
    uint16_t  idVendor;
    uint16_t  idProduct;
    uint16_t  bcdDevice;
    uint8_t   iManufacturer;
    uint8_t   iProduct;
    uint8_t   iSerialNumber;
    uint8_t   bNumConfigurations;
} usb_device_desc_t;

// configuration descriptor
typedef struct usb_config_desc_t {
    uint8_t   bLength;
    uint8_t   bDescriptorType;
    uint16_t  wTotalLength;
    uint8_t   bNumInterfaces;
    uint8_t   bConfigurationValue;
    uint8_t   iConfiguration;
    uint8_t   bmAttributes;
    uint8_t   bMaxPower;
} usb_config_desc_t;

// string descriptor
typedef struct usb_string_desc_t {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint8_t* bString;
} usb_string_desc_t;

// interface descriptor
typedef struct usb_if_desc_t {
    uint8_t   bLength;
    uint8_t   bDescriptorType;
    uint8_t   bInterfaceNumber;
    uint8_t   bAlternateSetting;
    uint8_t   bNumEndpoints;
    uint8_t   bInterfaceClass;
    uint8_t   bInterfaceSubClass;
    uint8_t   bInterfaceProtocol;
    uint8_t   iInterface;
} usb_interface_desc_t;

// endpoint descriptor
typedef struct usb_ep_desc_t {
    uint8_t   bLength;
    uint8_t   bDescriptorType;
    uint8_t   bEndpointAddress;
    uint8_t   bmAttributes;
    uint16_t  wMaxPacketSize;
    uint8_t   bInterval;
} usb_endpoint_desc_t;

// hid descriptor
typedef struct usb_hid_desc_t {
    uint8_t   bLength;
    uint8_t   bDescriptorType;
    uint16_t  bcdHID;
    uint8_t   bCountryCode;
    uint8_t   bNumDescriptors;
    uint8_t   bDescriptorType_HID;
    uint16_t  wDescriptorLength;
} usb_hid_desc_t;

typedef enum {
    USB_ATTACHED,
    USB_POWERED,
    USB_DEFAULT,
    USB_ADDRESSED,
    USB_CONFIGURED,
    USB_SUSPENDED
} usb_state_t;

#define USB_DIR_IN  0x80
#define USB_DIR_OUT 0x00

// descriptor types
#define USB_DESC_DEVICE            0x01
#define USB_DESC_CONFIGURATION     0x02
#define USB_DESC_STRING            0x03
#define USB_DESC_INTERFACE         0x04
#define USB_DESC_ENDPOINT          0x05
#define USB_DESC_DEVICE_QUAL       0x06
#define USB_DESC_OTHER_SPEED_CONF  0x07
#define USB_DESC_INTERFACE_POWER   0x08

#define USB_DESC_HID         0x21
#define USB_DESC_HID_REPORT  0x22
#define USB_DESC_HID_PHYS    0x23

// Configuration descriptor attributes
#define USB_CONFIG_BUS_POWERED   0x80
#define USB_CONFIG_SELF_POWERED  0x40
#define USB_CONFIG_REMOTE_WAKEUP 0x20

// endpoint types
#define USB_EP_TYPE_CTRL  0x00
#define USB_EP_TYPE_ISO   0x01
#define USB_EP_TYPE_BULK  0x02
#define USB_EP_TYPE_INT   0x03

#define USB_CLASS_HID 3
#define USB_CLASS_VENDOR 0xff

#define HID_SUBCLASS_NONE 0
#define HID_SUBCLASS_BOOT 1

#define HID_PROTOCOL_NONE 0
#define HID_PROTOCOL_KEYBOARD 1
#define HID_PROTOCOL_MOUSE 2

// endpoint address mask
#define USB_EP_ADDR_MASK  0x0f
#define USB_EP_ADDR_IN    0x80
#define USB_EP_ADDR_OUT   0x00

#define USB_BM_STATE_CONFIGURED           0x01
#define USB_BM_STATE_ALLOW_REMOTE_WAKEUP  0x02

#define USB_STRING_DESC_SIZE(size) ((USB_DESC_STRING<<8) | (size))

// USB 1.1
#define USB_REVISION_1_1 0x0110

// USB 2.0
 #define USB_REVISION_2_0 0x0200

// HID 1.11
#define USB_HID_REVISION_1_11 0x0111

// Macro for setting the .bMaxPower field in the device descriptor
#define USB_MAX_POWER(current_in_ma) ((current_in_ma+1)/2)
