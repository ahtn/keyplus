// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include "core/flash.h"

#include "core/keycode.h"

#define MACRO_TAG_BIT_POS (13)
#define MACRO_TAG_MASK (0b11 << MACRO_TAG_BIT_POS)
#define GET_MACRO_TAG(x) (((x) >> MACRO_TAG_BIT_POS) & 0b11)

enum {
    MACRO_TAG_KEY_SEND = 0b00,
    MACRO_TAG_KEY_PRESS = 0b01,
    MACRO_TAG_KEY_RELEASE = 0b10,
};

// TODO: add flag to macro keycode to indicate no delay

#define MACRO_KC_PRESS(x) ((x) | ((MACRO_TAG_KEY_PRESS) << MACRO_TAG_BIT_POS))
#define MACRO_KC_RELEASE(x) ((x) | ((MACRO_TAG_KEY_RELEASE) << MACRO_TAG_BIT_POS))

// we don't allow extended keycodes in macros, so we use the region that they
// occupy for macro controls
// TODO: probably should allow extended keycodes in macros
#define KC_MACRO_CMD_START_ADDR (KC_TYPE_MACRO_COMMAND_MASK)

enum {
    MACRO_CMD_REPEAT_BLOCK      = KC_MACRO_CMD_START_ADDR | 0x00,
    MACRO_CMD_REPEAT_JMP        = KC_MACRO_CMD_START_ADDR | 0x01,
    MACRO_CMD_SET_RATE          = KC_MACRO_CMD_START_ADDR | 0x02,
    MACRO_CMD_FINISH            = KC_MACRO_CMD_START_ADDR | 0x03,
    MACRO_CMD_WAIT              = KC_MACRO_CMD_START_ADDR | 0x04,

    // macro mouse control commands
    MACRO_CMD_MOUSE_SET_POS     = KC_MACRO_CMD_START_ADDR | 0x10,
    MACRO_CMD_MOUSE_SET_WHEEL   = KC_MACRO_CMD_START_ADDR | 0x11,
    MACRO_CMD_MOUSE_SET_BUTTONS = KC_MACRO_CMD_START_ADDR | 0x12,
    MACRO_CMD_MOUSE_CLEAR       = KC_MACRO_CMD_START_ADDR | 0x13,
};

void macro_task(void);
void call_macro(uint16_t ekc_addr, uint8_t kb_id);
void macro_abort(void);
