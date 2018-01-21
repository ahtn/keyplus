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

// binary object store descriptor
typedef struct usb_bos_desc_t {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint16_t wTotalLength;
    uint8_t bNumDeviceCaps;
} usb_bos_desc_t;


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
#define USB_DESC_DEVICE                0x01
#define USB_DESC_CONFIGURATION         0x02
#define USB_DESC_STRING                0x03
#define USB_DESC_INTERFACE             0x04
#define USB_DESC_ENDPOINT              0x05
#define USB_DESC_DEVICE_QUAL           0x06
#define USB_DESC_OTHER_SPEED_CONF      0x07
#define USB_DESC_INTERFACE_POWER       0x08
#define USB_DESC_OTG                   0x09
#define USB_DESC_DEBUG                 0x0A
#define USB_DESC_INTERFACE_ASSOCIATION 0x0B

#define USB_DESC_BOS                   0x0F
#define USB_DESC_DEVICE_CAPABILITY     0x10

#define USB_DESC_HID                   0x21
#define USB_DESC_HID_REPORT            0x22
#define USB_DESC_HID_PHYS              0x23

#define USB_DESC_HUB                   0x29
#define USB_DESC_SUPERSPEED_HUB        0x2A
#define USB_DESC_SS_ENDPOINT_COMPANION 0x30



// Configuration descriptor attributes
#define USB_CONFIG_BUS_POWERED   0x80
#define USB_CONFIG_SELF_POWERED  0x40
#define USB_CONFIG_REMOTE_WAKEUP 0x20

// endpoint types
#define USB_EP_TYPE_CTRL  0x00
#define USB_EP_TYPE_ISO   0x01
#define USB_EP_TYPE_BULK  0x02
#define USB_EP_TYPE_INT   0x03


#define USB_CLASS_AUDIO                 1
#define USB_CLASS_COMM                  2
#define USB_CLASS_HID                   3
#define USB_CLASS_PHYSICAL              5
#define USB_CLASS_PRINTER               7
#define USB_CLASS_PTP                   6
#define USB_CLASS_IMAGE                 6

#define USB_CLASS_MASS_STORAGE          8
#define USB_CLASS_HUB                   9
#define USB_CLASS_DATA                  10
#define USB_CLASS_SMART_CARD            0x0b

#define USB_CLASS_CONTENT_SECURITY      0x0d
#define USB_CLASS_VIDEO                 0x0e
#define USB_CLASS_PERSONAL_HEALTHCARE   0x0f
#define USB_CLASS_DIAGNOSTIC_DEVICE     0xdc

#define USB_CLASS_WIRELESS              0xe0
#define USB_CLASS_APPLICATION           0xfe
#define USB_CLASS_VENDOR                0xff

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

// USB 2.0.1
 #define USB_REVISION_2_0_1 0x0201

// HID 1.11
#define USB_HID_REVISION_1_11 0x0111


#define USB_DEV_CAPABILITY_WIRELESS_USB                 0x01
#define USB_DEV_CAPABILITY_USB_2_0_EXTENSION            0x02
#define USB_DEV_CAPABILITY_SUPERSPEED_USB               0x03
#define USB_DEV_CAPABILITY_CONTAINER_ID                 0x04
#define USB_DEV_CAPABILITY_PLATFORM                     0x05
#define USB_DEV_CAPABILITY_POWER_DELIVERY_CAPABILITY    0x06
#define USB_DEV_CAPABILITY_BATTERY_INFO_CAPABILITY      0x07
#define USB_DEV_CAPABILITY_PD_CONSUMER_PORT_CAPABILITY  0x08
#define USB_DEV_CAPABILITY_PD_PROVIDER_PORT_CAPABILITY  0x09
#define USB_DEV_CAPABILITY_SUPERSPEED_PLUS              0x0A
#define USB_DEV_CAPABILITY_PRECISION_TIME_MEASUREMENT   0x0B
#define USB_DEV_CAPABILITY_WIRELESS_USB_EXT             0x0C
