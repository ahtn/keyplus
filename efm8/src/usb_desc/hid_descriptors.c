// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include "usb_util/hut_desktop.h"
#include "usb_util/hut_keyboard.h"
#include "usb_util/hut_consumer.h"
#include "usb_util/hut_led.h"

// the default keyboard descriptor - compatible with keyboard boot protocol
// tatken from the HID Descriptor Tool
ROM const uint8_t hid_desc_boot_keyboard[] = {
    HID_USAGE_PAGE(1)        , HID_USAGE_PAGE_GENERIC_DESKTOP,
    HID_USAGE(1)             , HID_USAGE_KEYBOARD,
    HID_COLLECTION(1)        , HID_COLLECTION_APPLICATION,
        // modifiers
        HID_USAGE_PAGE(1)      , HID_USAGE_PAGE_KEYBOARD,
        HID_USAGE_MINIMUM(1)   , KC_LEFT_CONTROL,
        HID_USAGE_MAXIMUM(1)   , KC_RIGHT_GUI,
        HID_LOGICAL_MINIMUM(1) , 0x00,
        HID_LOGICAL_MAXIMUM(1) , 0x01,
        HID_REPORT_COUNT(1)    , 0x08,
        HID_REPORT_SIZE(1)     , 0x01,
        HID_INPUT(1)           , IOF_DATA | IOF_VARIABLE | IOF_ABSOLUTE,
        // reserved/OEM
        HID_REPORT_COUNT(1)    , 0x01,
        HID_REPORT_SIZE(1)     , 0x08,
        HID_INPUT(1)           , IOF_CONSTANT | IOF_VARIABLE | IOF_ABSOLUTE,
        // keycodes
        HID_LOGICAL_MINIMUM(1) , KC_NONE,
        HID_LOGICAL_MAXIMUM(1) , KC_RIGHT_GUI,
        HID_USAGE_MINIMUM(1)   , KC_NONE,
        HID_USAGE_MAXIMUM(1)   , KC_RIGHT_GUI,
        HID_REPORT_COUNT(1)    , 0x06,
        // HID_REPORT_SIZE(1)     , 0x08, // Reuse global item
        HID_INPUT(1)           , IOF_DATA | IOF_ARRAY | IOF_ABSOLUTE,
        // LEDs
        HID_USAGE_PAGE(1)      , HID_USAGE_PAGE_LEDS,
        HID_LOGICAL_MINIMUM(1) , 0x00,
        HID_LOGICAL_MAXIMUM(1) , 0x01,
        HID_USAGE_MINIMUM(1)   , HID_LED_Num_Lock,
        HID_USAGE_MAXIMUM(1)   , HID_LED_Kana,
        HID_REPORT_COUNT(1)    , 0x05,
        HID_REPORT_SIZE(1)     , 0x01,
        HID_OUTPUT(1)          , IOF_DATA | IOF_VARIABLE | IOF_ABSOLUTE,
        // leftover
        HID_REPORT_COUNT(1)    , 0x01,
        HID_REPORT_SIZE(1)     , 0x03,
        HID_OUTPUT(1)          , IOF_CONSTANT | IOF_VARIABLE | IOF_ABSOLUTE,
    HID_END_COLLECTION(0),
};
ROM const uint8_t sizeof_hid_desc_boot_keyboard = sizeof(hid_desc_boot_keyboard);
