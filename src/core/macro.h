// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include "core/flash.h"

#include "core/keycode.h"

// we don't allow extended keycodes in macros, so we use the region that they
// occupy for macro controls
// TODO: probably should allow extended keycodes in macros
#define KC_MACRO_CMD_START_ADDR (KC_TYPE_MACRO_COMMAND_MASK)

enum {
    MACRO_CMD_PRESS             = KC_MACRO_CMD_START_ADDR | 0x00,
    MACRO_CMD_RELEASE           = KC_MACRO_CMD_START_ADDR | 0x01,
    MACRO_CMD_SET_RATE          = KC_MACRO_CMD_START_ADDR | 0x02,
    MACRO_CMD_FINISH            = KC_MACRO_CMD_START_ADDR | 0x03,
    MACRO_CMD_REPEAT_BLOCK      = KC_MACRO_CMD_START_ADDR | 0x04,
    MACRO_CMD_REPEAT_JMP        = KC_MACRO_CMD_START_ADDR | 0x05,

    MACRO_CMD_CLEAR_KEYBOARD    = KC_MACRO_CMD_START_ADDR | 0x06,
    MACRO_CMD_CLEAR_MOUSE       = KC_MACRO_CMD_START_ADDR | 0x07,

    MACRO_CMD_SET_CLEAR_RATE    = KC_MACRO_CMD_START_ADDR | 0x08,

    // macro mouse control commands
    MACRO_CMD_MOUSE_MOVE        = KC_MACRO_CMD_START_ADDR | 0x10,
    MACRO_CMD_MOUSE_WHEEL       = KC_MACRO_CMD_START_ADDR | 0x11,
};

typedef struct macro_cmd_mouse_move_t {
    int16_t x;
    int16_t y;
} macro_cmd_mouse_move_t ;

typedef struct macro_cmd_mouse_wheel_t {
    int8_t x;
    int8_t y;
} macro_cmd_mouse_wheel_t ;

void macro_task(void);
void call_macro(uint16_t ekc_addr, uint8_t kb_id);
void macro_abort(void);
