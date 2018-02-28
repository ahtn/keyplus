// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include "usb/util/hut_desktop.h"
#include "usb/util/hut_keyboard.h"
#include "usb/util/hut_consumer.h"
#include "usb/util/hut_led.h"

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

ROM const uint8_t hid_desc_nkro_keyboard[] = {
    HID_USAGE_PAGE(1)        , HID_USAGE_PAGE_GENERIC_DESKTOP,
    HID_USAGE(1)             , HID_USAGE_KEYBOARD,
    HID_COLLECTION(1)        , HID_COLLECTION_APPLICATION,
        HID_USAGE_PAGE(1)      , HID_USAGE_PAGE_KEYBOARD,
        HID_USAGE_MINIMUM(1)   , KC_LEFT_CONTROL,
        HID_USAGE_MAXIMUM(1)   , KC_RIGHT_GUI,
        HID_LOGICAL_MINIMUM(1) , 0x00,
        HID_LOGICAL_MAXIMUM(1) , 0x01,
        HID_REPORT_COUNT(1)    , 0x08,
        HID_REPORT_SIZE(1)     , 0x01,
        HID_INPUT(1)           , IOF_DATA | IOF_VARIABLE | IOF_ABSOLUTE,
        // keycodes
        // HID_LOGICAL_MINIMUM(1) , 0x00, // Reuse global item
        // HID_LOGICAL_MAXIMUM(1) , 0x01, // Reuse global item
        HID_USAGE_MINIMUM(1)   , 0x00,
        HID_USAGE_MAXIMUM(1)   , 0xdf,
        HID_REPORT_COUNT(1)    , 0xe0,
        // HID_REPORT_SIZE(1)     , 0x01, // Reuse global item
        HID_INPUT(1)           , IOF_DATA | IOF_VARIABLE | IOF_ABSOLUTE,
#if 0
        // TODO/Note: This part of the descriptor is unnecessary unless the
        // device is compiled without the 6KRO/boot keyboard report since the
        // boot keyboard report already stores the LED state from the host.
        // LEDs
        HID_USAGE_PAGE(1)      , HID_USAGE_PAGE_LEDS,
        HID_LOGICAL_MINIMUM(1) , 0x00,
        HID_LOGICAL_MAXIMUM(1) , 0x01,
        HID_USAGE_MINIMUM(1)   , HID_LED_Num_Lock,
        HID_USAGE_MAXIMUM(1)   , HID_LED_Kana,
        HID_REPORT_COUNT(1)    , 0x05,
        // HID_REPORT_SIZE(1)     , 0x01, // Reuse global item
        HID_OUTPUT(1)          , IOF_DATA | IOF_VARIABLE | IOF_ABSOLUTE,
        // leftover
        HID_REPORT_COUNT(1)    , 0x01,
        HID_REPORT_SIZE(1)     , 0x03,
        HID_OUTPUT(1)          , IOF_CONSTANT | IOF_VARIABLE | IOF_ABSOLUTE,
#endif
    HID_END_COLLECTION(0),
};
ROM const uint8_t sizeof_hid_desc_nkro_keyboard = sizeof(hid_desc_nkro_keyboard);


ROM const uint8_t hid_desc_mouse[] = {
    HID_USAGE_PAGE(1), HID_USAGE_PAGE_GENERIC_DESKTOP,
    HID_USAGE(1), HID_USAGE_MOUSE,
    HID_COLLECTION(1), HID_COLLECTION_APPLICATION,
        // mouse
        HID_USAGE(1), HID_USAGE_POINTER,
        HID_COLLECTION(1), HID_COLLECTION_PHYSICAL,
            // mouse buttons
            HID_USAGE_PAGE(1)      , HID_USAGE_PAGE_BUTTON,
            HID_LOGICAL_MINIMUM(1) , 0,
            HID_LOGICAL_MAXIMUM(1) , 1,
            HID_USAGE_MINIMUM(1)   , 1,
            HID_USAGE_MAXIMUM(1)   , 16,
            HID_REPORT_COUNT(1)    , 16,
            HID_REPORT_SIZE(1)     , 1,
            HID_INPUT(1)           , IOF_DATA | IOF_VARIABLE | IOF_ABSOLUTE,
            // mouse X, Y
            HID_USAGE_PAGE(1)      , HID_USAGE_PAGE_GENERIC_DESKTOP,
            HID_USAGE(1)           , HID_USAGE_X,
            HID_USAGE(1)           , HID_USAGE_Y,
            HID_LOGICAL_MINIMUM(2) , DB16(INT16_MIN),
            HID_LOGICAL_MAXIMUM(2) , DB16(INT16_MAX),
            HID_REPORT_COUNT(1)    , 2,
            HID_REPORT_SIZE(1)     , 16,
            HID_INPUT(1)           , IOF_DATA | IOF_VARIABLE | IOF_RELATIVE,
            // mouse wheel
            HID_USAGE(1)           , HID_USAGE_WHEEL,
            HID_LOGICAL_MINIMUM(1) , DB8(INT8_MIN),
            HID_LOGICAL_MAXIMUM(1) , DB8(INT8_MAX),
            HID_REPORT_COUNT(1)    , 1,
            HID_REPORT_SIZE(1)     , 8,
            HID_INPUT(1)           , IOF_DATA | IOF_VARIABLE | IOF_RELATIVE,
            // mouse pan wheel
            HID_USAGE_PAGE(1)      , HID_USAGE_PAGE_CONSUMER,
            HID_USAGE(2)           , DB16(HID_CONSUMER_AC_PAN),
            // HID_LOGICAL_MINIMUM(1) , DB8(INT8_MIN), // Reuse global item
            // HID_LOGICAL_MAXIMUM(1) , DB8(INT8_MAX), // Reuse global item
            // HID_REPORT_COUNT(1)    , 1, // Reuse global item
            // HID_REPORT_SIZE(1)     , 8, // Reuse global item
            HID_INPUT(1), IOF_DATA | IOF_VARIABLE | IOF_RELATIVE,
        HID_END_COLLECTION(0),
    HID_END_COLLECTION(0),
};
ROM const uint8_t sizeof_hid_desc_mouse = sizeof(hid_desc_mouse);

ROM const uint8_t hid_desc_media[] = {
    HID_USAGE_PAGE(1), HID_USAGE_PAGE_GENERIC_DESKTOP, /* Generic Desktop */
    HID_USAGE(1), HID_USAGE_SYSTEM_CONTROL, /* System Control */
    HID_COLLECTION(1), HID_COLLECTION_APPLICATION,
        HID_REPORT_ID(1), REPORT_ID_SYSTEM,
        HID_LOGICAL_MINIMUM(1) , HID_DESKTOP_System_Control,
        HID_LOGICAL_MAXIMUM(1) , HID_DESKTOP_System_Display_LCD_Autoscale,
        HID_USAGE_MINIMUM(1)   , HID_DESKTOP_System_Control,
        HID_USAGE_MAXIMUM(1)   , HID_DESKTOP_System_Display_LCD_Autoscale,
        HID_REPORT_SIZE(1)     , 8,
        HID_REPORT_COUNT(1)    , 1,
        HID_INPUT(1)           , IOF_DATA | IOF_ARRAY | IOF_ABSOLUTE,
    HID_END_COLLECTION(0),

    HID_USAGE_PAGE(1), HID_USAGE_PAGE_CONSUMER,
    HID_USAGE(1), HID_CONSUMER_CONSUMER_CONTROL,
    HID_COLLECTION(1), HID_COLLECTION_APPLICATION,
        HID_REPORT_ID(1)       , REPORT_ID_CONSUMER,
        HID_LOGICAL_MINIMUM(2) , DB16(HID_CONSUMER_PLUS_10),
        HID_LOGICAL_MAXIMUM(2) , DB16(HID_CONSUMER_AC_DISTRIBUTE_VERTICALLY),
        HID_USAGE_MINIMUM(2)   , DB16(HID_CONSUMER_PLUS_10),
        HID_USAGE_MAXIMUM(2)   , DB16(HID_CONSUMER_AC_DISTRIBUTE_VERTICALLY),
        HID_REPORT_SIZE(1)     , 16,
        // HID_REPORT_COUNT(1)    , 1, // Resuse global item
        HID_INPUT(1)           , IOF_DATA | IOF_ARRAY | IOF_ABSOLUTE,
    HID_END_COLLECTION(0),
};
ROM const uint8_t sizeof_hid_desc_media = sizeof(hid_desc_media);

#define HID_USAGE_PAGE_VENDOR HID_USAGE_PAGE_VENDOR_START
#define HID_COLLECTION_VENDOR HID_COLLECTION_VENDOR_START
#define HID_USAGE_VENDOR_0 0x80+0
#define HID_USAGE_VENDOR_1 0x80+1
#define HID_USAGE_VENDOR_2 0x80+2

// Note: For HID_LOGICAL_MAXIMUM=255, we use the value 0x00ff instead of 0xff.
// This is because the integers used in logical min/max values are assumed
// to be in 2's complement notation. So, 0xff == -1, while 0x00ff == 255.
ROM const uint8_t hid_desc_vendor[] = {
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

ROM const uint8_t sizeof_hid_desc_vendor = sizeof(hid_desc_vendor);
