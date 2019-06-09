// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <stdint.h>

// HID usage table for key codes to be used in implementing a USB keyboard.
// See: http://www.usb.org/developers/hidpage/Hut1_12v2.pdf
#include <linux/input-event-codes.h>

// for older versions
#ifndef KEY_ASSISTANT
    #define KEY_ASSISTANT		0x247	/* AL Context-aware desktop assistant */
#endif

#ifndef REL_WHEEL_HI_RES
    #define REL_WHEEL_HI_RES	0x0b
#endif
#ifndef REL_HWHEEL_HI_RES
    #define REL_HWHEEL_HI_RES	0x0c
#endif

#include "debug.h"

#define KB_EVENT_MAP_LEN        256
#define MOUSE_EVENT_MAP_LEN     8
#define SYSTEM_EVENT_MAP_LEN    128
#define CONSUMER_EVENT_MAP_LEN  0x029D

#define HID_SYSTEM_MAP_OFFSET 0x80

extern const uint16_t HID_KB_TO_EV[KB_EVENT_MAP_LEN];
extern const uint16_t HID_MOUSE_TO_EV[MOUSE_EVENT_MAP_LEN];
extern const uint16_t HID_SYSTEM_TO_EV_TABLE[SYSTEM_EVENT_MAP_LEN];
extern const uint16_t HID_CONSUMER_TO_EV_TABLE[CONSUMER_EVENT_MAP_LEN];

static inline int hid_keyboard_to_ev(uint8_t kc) {
    KP_ASSERT(kc < KB_EVENT_MAP_LEN);
    return HID_KB_TO_EV[kc];
}

static inline int hid_mouse_to_ev(uint8_t btn) {
    KP_ASSERT(btn < MOUSE_EVENT_MAP_LEN);
    return HID_MOUSE_TO_EV[btn];
}

static inline uint16_t hid_system_to_ev(uint8_t code) {
    if (code < HID_SYSTEM_MAP_OFFSET) {
        return 0;
    }
    return HID_SYSTEM_TO_EV_TABLE[code-HID_SYSTEM_MAP_OFFSET];
}

static inline uint16_t hid_consumer_to_ev(uint16_t code) {
    if (code >= CONSUMER_EVENT_MAP_LEN) {
        return 0;
    }
    return HID_CONSUMER_TO_EV_TABLE[code];
}
