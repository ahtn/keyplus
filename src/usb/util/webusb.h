// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <stdint.h>

// webusb descriptor
typedef struct usb_webusb_desc_t {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint8_t bDevCapabilityType;
    uint8_t bReserved;
    uint8_t PlatformCapabilityUUID[16];
    uint16_t bcdVersion;
    uint8_t bVendorCode;
    uint8_t iLandingPage;
} usb_webusb_desc_t;

#define WEBUSB_UUID { \
    0x34,0x08,0xb6,0x38,0x09,0xa9,0x47,0xa0,0x8b,0xfd,0xa0,0x76,0x88,0x15,0xb6,0x65 }
#define WEBUSB_BCDVERSION 0x0100

#define WEBUSB_URL 3

#define WEBUSB_SCHEME_HTTP 0
#define WEBUSB_SCHEME_HTTPS 1
#define WEBUSB_SCHEME_RAW 255
