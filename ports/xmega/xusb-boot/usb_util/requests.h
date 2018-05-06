// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <stdint.h>

// bmRequestType
#define USB_REQTYPE_DIRECTION_MASK 0x80
#define USB_REQTYPE_TYPE_MASK      0x60
#define USB_REQTYPE_RECIPIENT_MASK 0x1F

// request type: direction
#define USB_REQTYPE_DIRECTION_HOST_TO_DEVICE 0
#define USB_REQTYPE_DIRECTION_DEVICE_TO_HOST 1

// request type: type
#define USB_REQTYPE_TYPE_STANDARD 0
#define USB_REQTYPE_TYPE_CLASS    1
#define USB_REQTYPE_TYPE_VENDOR   2
// #define USB_REQTYPE_TYPE_RESERVED 3

// request type: type
#define USB_REQTYPE_RECIPIENT_DEVICE        0
#define USB_REQTYPE_RECIPIENT_INTERFACE     1
#define USB_REQTYPE_RECIPIENT_ENDPOINT      2
#define USB_REQTYPE_RECIPIENT_OTHER         3

// standard request (bRequest)
#define USB_REQ_GET_STATUS         0x00
#define USB_REQ_CLEAR_FEATURE      0x01
#define USB_REQ_SET_FEATURE        0x03
#define USB_REQ_SET_ADDRESS        0x05
#define USB_REQ_GET_DESCRIPTOR     0x06
#define USB_REQ_SET_DESCRIPTOR     0x07
#define USB_REQ_GET_CONFIGURATION  0x08
#define USB_REQ_SET_CONFIGURATION  0x09
#define USB_REQ_GET_INTERFACE      0x0a
#define USB_REQ_SET_INTERFACE      0x0b
#define USB_REQ_SYNCH_FRAME        0x0c

// HID request codes (bRequest)
#define USB_REQ_HID_GET_REPORT    0x01
#define USB_REQ_HID_GET_IDLE      0x02
#define USB_REQ_HID_GET_PROTOCOL  0x03
#define USB_REQ_HID_SET_REPORT    0x09
#define USB_REQ_HID_SET_IDLE      0x0a
#define USB_REQ_HID_SET_PROTOCOL  0x0b

typedef union usb_request_t {
    struct {
        uint8_t   bmRequestType;
        uint8_t   bRequest;
        uint16_t  wValue;
        uint16_t  wIndex;
        uint16_t  wLength;
    } std;

    struct {
        uint8_t   bmRequestType;
        uint8_t   bRequest;
        uint8_t   wValueLSB;
        uint8_t   wValueMSB;
        uint8_t   wIndexLSB;
        uint8_t   wIndexMSB;
        uint8_t   wLengthLSB;
        uint8_t   wLengthMSB;
    } val;

    struct {
        uint8_t   bmRequestType;
        uint8_t   bRequest;
        uint8_t   descriptor_index;
        uint8_t   descriptor_type;
        uint16_t  language_id;
        uint16_t  descriptor_length;
    } get_desc;

    struct {
        uint8_t   bmRequestType;
        uint8_t   bRequest;
        uint8_t   descriptor_index;
        uint8_t   descriptor_type;
        // TODO: change to uint16_t
        uint8_t   descriptor_interface;
        uint8_t   filler;
        uint16_t  descriptor_length;
    } get_hid_desc;
} usb_request_t;
