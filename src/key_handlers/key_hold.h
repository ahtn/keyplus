// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include "key_handlers/key_handlers.h"

#define MAX_NUM_HOLD_KEYS 4

// hold key settings in external keycode table
enum {
    HOLD_KEY_SETTING_ACTIVATE_ON_KEY_PRESS = 0x01,
};

// NOTE: since we use `uint16_t` for `end_time`, we are limit to a hold duration
// of (UINT16_MAX/2) ms ≈ 32s
typedef struct {
    uint16_t ekc_addr;
    uint16_t end_time;
    uint8_t kb_id;
    uint8_t activate_on_key_press: 1;
    uint8_t has_been_held: 1;
    uint8_t has_been_tapped: 1;
    uint8_t has_generated_event: 1;
    uint8_t reserved: 5;
} hold_event_t;

extern XRAM keycode_callbacks_t hold_keycodes;

void hold_key_task(void);
