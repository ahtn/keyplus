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


// The byte ordering for the WEBUSB UUID comes from Microsofts UUID structure:
// https://msdn.microsoft.com/en-us/library/windows/desktop/aa379358(v=vs.85).aspx
//
// struct UUID {
//   uint32_t data1;
//   uint16_t data2;
//   uint16_t data3;
//   uint8_t data4[8];
// };
//
// The webusb UUID: {3408b638-09a9-47a0-8bfd-a0768815b665}
// needs to be encoded in little endian based on the UUID structure above.

#define WEBUSB_UUID { \
    0x38,0xb6,0x08,0x34, \
    0xa9,0x09, \
    0xa0,0x47, \
    0x8b,0xfd,0xa0,0x76,0x88,0x15,0xb6,0x65 \
}
#define WEBUSB_BCDVERSION 0x0100

#define WEBUSB_URL 3

#define WEBUSB_SCHEME_HTTP 0
#define WEBUSB_SCHEME_HTTPS 1
#define WEBUSB_SCHEME_RAW 255

#define WEBUSB_REQ_GET_URL 2
