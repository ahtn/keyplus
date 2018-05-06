// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#define HID_USAGE_PAGE_VENDOR HID_USAGE_PAGE_VENDOR_START
#define HID_COLLECTION_VENDOR HID_COLLECTION_VENDOR_START
#define HID_USAGE_VENDOR_0 0x80+0
#define HID_USAGE_VENDOR_1 0x80+1
#define HID_USAGE_VENDOR_2 0x80+2

// Note: For HID_LOGICAL_MAXIMUM=255, we use the value 0x00ff instead of 0xff.
// This is because the integers used in logical min/max values are assumed
// to be in 2's complement notation. So, 0xff == -1, while 0x00ff == 255.
const uint8_t hid_desc_vendor[] = {
    HID_USAGE_PAGE(2), DB16(HID_USAGE_PAGE_VENDOR_START),
    HID_USAGE(1), HID_USAGE_VENDOR_0,
    HID_COLLECTION(1), HID_COLLECTION_VENDOR,
        // Vendor input usage:
        HID_LOGICAL_MINIMUM(1) , DB8(0),
        HID_LOGICAL_MAXIMUM(2) , DB16(0x00ff),
        HID_REPORT_SIZE(1)     , 8,
        HID_REPORT_COUNT(1)    , 64,
        HID_USAGE(1)           , HID_USAGE_VENDOR_1,
        HID_INPUT(1)           , IOF_DATA | IOF_VARIABLE | IOF_ABSOLUTE,
        // Vendor output usage:
        // HID_LOGICAL_MINIMUM(1) , DB8(0), // Reuse global item
        // HID_LOGICAL_MAXIMUM(2) , DB16(0x00FF), // Reuse global item
        // HID_REPORT_SIZE(1)     , 8, // Reuse global item
        // HID_REPORT_COUNT(1)    , 64, // Reuse global item
        HID_USAGE(1)           , HID_USAGE_VENDOR_2,
        HID_OUTPUT(1)          , IOF_DATA | IOF_VARIABLE | IOF_ABSOLUTE,
    HID_END_COLLECTION(0),
};

const uint8_t sizeof_hid_desc_vendor = sizeof(hid_desc_vendor);
