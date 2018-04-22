// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <stdint.h>

#include "core/flash.h"

typedef uint16_t keycode_t;

typedef enum keycode_type_t {
    KC_TYPE_L_MODKEY = 0b00,
    KC_TYPE_R_MODKEY = 0b01,
    // TODO: should probably remove force and just make it the default
    // behaviour for modkeys since it seems like the more logical behaviour
    KC_TYPE_L_MODKEY_FORCE = 0b10,
    KC_TYPE_R_MODKEY_FORCE = 0b11,
    KC_TYPE_SPECIAL = 0b100,

    KC_TYPE_EXTERNAL = 0b1000,
} keycode_type_t;

/*********************************************************************
 *                         external keycodes                         *
 *********************************************************************/
// external keycodes are advanced functions that have some sort of data
// component. They don't fit inside a 16-bit keycode, so instead they
// indirect their data stage to outside the layout keycode map. They
// have the form:
//  1AAA_AAAA_AAAA_AAAA
// Where the 'A' bits are a 15-bit address into the layout data table.
// This is the address to the actual keycode value. The address after
// the keycode is the data for the keycode function, which is interpreted
// by the key_handler of the keycode.
#define KC_EXTERNAL_FLAG (1<<15)
#define KC_EXTERNAL_ADDR_MASK (~(1<<15))

#define KC_SPECIAL_START (KC_TYPE_SPECIAL<<12)

#define KC_EXTERNAL(addr) ((KC_EXTERNAL_FLAG | (addr & KC_EXTERNAL_ADDR_MASK)))

/*********************************************************************
 *                         usb hid keycodes                          *
 *********************************************************************/

// NOTE: For the HID keycodes, see this header file
#include "usb/util/hut_keyboard.h"

/*********************************************************************
 *                            short names                            *
 *********************************************************************/
// short renames of common keycodes
#define KC_SLASH KC_FORWARD_SLASH
#define KC_UP    KC_UP_ARROW
#define KC_DOWN KC_DOWN_ARROW
#define KC_LEFT KC_LEFT_ARROW
#define KC_RIGHT KC_RIGHT_ARROW
#define KC_PGUP KC_PAGE_UP
#define KC_PGDN KC_PAGE_DOWN

// short names for common keycodes to match tmk names
#define KC_LCTL KC_LCTRL
#define KC_RCTL KC_RCTRL
#define KC_LSFT KC_LSHIFT
#define KC_RSFT KC_RSHIFT
#define KC_ESC  KC_ESCAPE
#define KC_BSPC KC_BACKSPACE
#define KC_ENT  KC_ENTER
#define KC_DEL  KC_DELETE
#define KC_INS  KC_INSERT
#define KC_CAPS KC_CAPSLOCK
#define KC_CLCK KC_CAPSLOCK
#define KC_RGHT KC_RIGHT
#define KC_PSCR KC_PRINT_SCREEN
#define KC_SLCK KC_SCROLL_LOCK
#define KC_PAUS KC_PAUSE
#define KC_BRK  KC_PAUSE
#define KC_NLCK KC_NUM_LOCK
#define KC_SPC  KC_SPACEBAR
#define KC_MINS KC_MINUS
#define KC_EQL  KC_EQUAL
#define KC_GRV  KC_GRAVE
#define KC_RBRC KC_RIGHT_BRACKET
#define KC_LBRC KC_LEFT_BRACKET
#define KC_COMM KC_COMMA
#define KC_DOT  KC_PERIOD
#define KC_BSLS KC_BACK_SLASH
#define KC_SLSH KC_SLASH
#define KC_SCLN KC_SEMICOLON
#define KC_QUOT KC_APOSTROPHE
#define KC_APP  KC_APPLICATION
#define KC_NUHS KC_NONUS_HASH
#define KC_NUBS KC_NONUS_BSLASH
#define KC_LCAP KC_LOCKING_CAPS
#define KC_LNUM KC_LOCKING_NUM
#define KC_LSCR KC_LOCKING_SCROLL
#define KC_ERAS KC_ALT_ERASE
#define KC_CLR  KC_CLEAR

// mouse key short forms
#define KC_MS_U KC_MOUSE_UP
#define KC_MS_D KC_MOUSE_DOWN
#define KC_MS_L KC_MOUSE_LEFT
#define KC_MS_R KC_MOUSE_RIGHT
#define KC_BTN1 KC_MOUSE_BTN1
#define KC_BTN2 KC_MOUSE_BTN2
#define KC_BTN3 KC_MOUSE_BTN3
#define KC_BTN4 KC_MOUSE_BTN4
#define KC_BTN5 KC_MOUSE_BTN5
#define KC_BTN6 KC_MOUSE_BTN6
#define KC_BTN7 KC_MOUSE_BTN7
#define KC_BTN8 KC_MOUSE_BTN8
#define KC_WH_U KC_MOUSE_WH_UP
#define KC_WH_D KC_MOUSE_WH_DOWN
#define KC_WH_L KC_MOUSE_WH_LEFT
#define KC_WH_R KC_MOUSE_WH_RIGHT
#define KC_MUTE KC_AUDIO_MUTE
#define KC_VOLU KC_AUDIO_VOL_UP
#define KC_VOLD KC_AUDIO_VOL_DOWN
#define KC_MNXT KC_MEDIA_NEXT_TRACK
#define KC_MPRV KC_MEDIA_PREV_TRACK
#define KC_MFFD KC_MEDIA_FAST_FORWARD
#define KC_MRWD KC_MEDIA_REWIND
#define KC_MSTP KC_MEDIA_STOP
#define KC_MPLY KC_MEDIA_PLAY_PAUSE

#define KC_BTLD KC_BOOTLOADER
#define KC_TRNS KC_TRANSPARENT

/*********************************************************************
 *                         special keycodes                          *
 *********************************************************************/
// NOTE: has space for 16384 (0x4000) keycodes

typedef enum special_keycode_t {
    KC_TRANSPARENT             = KC_SPECIAL_START | 0x00 ,

    // mouse movement keycodes
    KC_MOUSE_UP                = KC_SPECIAL_START | 0x10 ,
    KC_MOUSE_DOWN              = KC_SPECIAL_START | 0x11 ,
    KC_MOUSE_LEFT              = KC_SPECIAL_START | 0x12 ,
    KC_MOUSE_RIGHT             = KC_SPECIAL_START | 0x13 ,

    KC_MOUSE_WH_UP             = KC_SPECIAL_START | 0x14 ,
    KC_MOUSE_WH_DOWN           = KC_SPECIAL_START | 0x15 ,
    KC_MOUSE_WH_LEFT           = KC_SPECIAL_START | 0x16 ,
    KC_MOUSE_WH_RIGHT          = KC_SPECIAL_START | 0x17 ,
    // 17-1F reserved

    // mouse button keycodes
    KC_MOUSE_BTN1              = KC_SPECIAL_START | 0x20 ,
    KC_MOUSE_BTN2              = KC_SPECIAL_START | 0x21 ,
    KC_MOUSE_BTN3              = KC_SPECIAL_START | 0x22 ,
    KC_MOUSE_BTN4              = KC_SPECIAL_START | 0x23 ,
    KC_MOUSE_BTN5              = KC_SPECIAL_START | 0x24 ,
    KC_MOUSE_BTN6              = KC_SPECIAL_START | 0x25 ,
    KC_MOUSE_BTN7              = KC_SPECIAL_START | 0x26 ,
    KC_MOUSE_BTN8              = KC_SPECIAL_START | 0x27 ,

    KC_MOUSE_RAPID_BTN1        = KC_SPECIAL_START | 0x28 ,
    // 27-2F reserved for mouse keys

    // system control
    KC_SYSTEM_POWER            = KC_SPECIAL_START | 0xA5 ,
    KC_SYSTEM_SLEEP            = KC_SPECIAL_START | 0xA6 ,
    KC_SYSTEM_WAKE             = KC_SPECIAL_START | 0xA7 ,

    // media control
    KC_AUDIO_MUTE              = KC_SPECIAL_START | 0xA8 ,
    KC_AUDIO_VOL_UP            = KC_SPECIAL_START | 0xA9 ,
    KC_AUDIO_VOL_DOWN          = KC_SPECIAL_START | 0xAA ,
    KC_MEDIA_NEXT_TRACK        = KC_SPECIAL_START | 0xAB ,
    KC_MEDIA_PREV_TRACK        = KC_SPECIAL_START | 0xAC ,
    KC_MEDIA_FAST_FORWARD      = KC_SPECIAL_START | 0xAD ,
    KC_MEDIA_REWIND            = KC_SPECIAL_START | 0xAE ,
    KC_MEDIA_STOP              = KC_SPECIAL_START | 0xAF ,
    KC_MEDIA_PLAY_PAUSE        = KC_SPECIAL_START | 0xB0 ,
    KC_MEDIA_EJECT             = KC_SPECIAL_START | 0xB1 ,
    KC_MEDIA_SELECT            = KC_SPECIAL_START | 0xB2 ,
    KC_MAIL                    = KC_SPECIAL_START | 0xB3 ,
    KC_CALCULATOR              = KC_SPECIAL_START | 0xB4 ,
    KC_MY_COMPUTER             = KC_SPECIAL_START | 0xB5 ,
    KC_WWW_SEARCH              = KC_SPECIAL_START | 0xB6 ,
    KC_WWW_HOME                = KC_SPECIAL_START | 0xB7 ,
    KC_WWW_BACK                = KC_SPECIAL_START | 0xB8 ,
    KC_WWW_FORWARD             = KC_SPECIAL_START | 0xB9 ,
    KC_WWW_STOP                = KC_SPECIAL_START | 0xBA ,
    KC_WWW_REFRESH             = KC_SPECIAL_START | 0xBB ,
    KC_WWW_FAVORITES           = KC_SPECIAL_START | 0xBC ,

    // hardware control
    KC_DONGLE_0                = KC_SPECIAL_START | 0xE0,
    KC_DONGLE_1                = KC_SPECIAL_START | 0xE1,
    KC_DONGLE_2                = KC_SPECIAL_START | 0xE2,
    KC_DONGLE_3                = KC_SPECIAL_START | 0xE3,
    KC_DONGLE_4                = KC_SPECIAL_START | 0xE4,
    KC_DONGLE_5                = KC_SPECIAL_START | 0xE5,
    KC_DONGLE_6                = KC_SPECIAL_START | 0xE6,
    KC_DONGLE_7                = KC_SPECIAL_START | 0xE7,

    KC_BOOTLOADER              = KC_SPECIAL_START | 0xE8,
    KC_BOOTLOADER_2            = KC_SPECIAL_START | 0xE9,
    KC_RESET                   = KC_SPECIAL_START | 0xEA,
    KC_KRO_6                   = KC_SPECIAL_START | 0xEB,
    KC_KRO_N                   = KC_SPECIAL_START | 0xEC,
    KC_KRO_AUTO                = KC_SPECIAL_START | 0xED,
    KC_LAYER_RESET             = KC_SPECIAL_START | 0xEE,
    KC_UNIFYING_PAIR           = KC_SPECIAL_START | 0xEF,

    KC_TEST_0                  = KC_SPECIAL_START | 0xF8,
    KC_TEST_1                  = KC_SPECIAL_START | 0xF9,
    KC_TEST_2                  = KC_SPECIAL_START | 0xFA,
    KC_TEST_3                  = KC_SPECIAL_START | 0xFB,
    KC_TEST_4                  = KC_SPECIAL_START | 0xFC,
    KC_TEST_5                  = KC_SPECIAL_START | 0xFD,
    KC_TEST_6                  = KC_SPECIAL_START | 0xFE,
    KC_TEST_7                  = KC_SPECIAL_START | 0xFF,

    // basic layer keycodes, layer is active while key is down
    KC_L0                      = KC_SPECIAL_START | 0x100,
    KC_L1                      = KC_SPECIAL_START | 0x101,
    KC_L2                      = KC_SPECIAL_START | 0x102,
    KC_L3                      = KC_SPECIAL_START | 0x103,
    KC_L4                      = KC_SPECIAL_START | 0x104,
    KC_L5                      = KC_SPECIAL_START | 0x105,
    KC_L6                      = KC_SPECIAL_START | 0x106,
    KC_L7                      = KC_SPECIAL_START | 0x107,
    KC_L8                      = KC_SPECIAL_START | 0x108,
    KC_L9                      = KC_SPECIAL_START | 0x109,
    KC_L10                     = KC_SPECIAL_START | 0x10A,
    KC_L11                     = KC_SPECIAL_START | 0x10B,
    KC_L12                     = KC_SPECIAL_START | 0x10C,
    KC_L13                     = KC_SPECIAL_START | 0x10D,
    KC_L14                     = KC_SPECIAL_START | 0x10E,
    KC_L15                     = KC_SPECIAL_START | 0x10F,

    // sets the base layer
    KC_SET_L0                  = KC_SPECIAL_START | 0x110,
    KC_SET_L1                  = KC_SPECIAL_START | 0x111,
    KC_SET_L2                  = KC_SPECIAL_START | 0x112,
    KC_SET_L3                  = KC_SPECIAL_START | 0x113,
    KC_SET_L4                  = KC_SPECIAL_START | 0x114,
    KC_SET_L5                  = KC_SPECIAL_START | 0x115,
    KC_SET_L6                  = KC_SPECIAL_START | 0x116,
    KC_SET_L7                  = KC_SPECIAL_START | 0x117,
    KC_SET_L8                  = KC_SPECIAL_START | 0x118,
    KC_SET_L9                  = KC_SPECIAL_START | 0x119,
    KC_SET_L10                 = KC_SPECIAL_START | 0x11A,
    KC_SET_L11                 = KC_SPECIAL_START | 0x11B,
    KC_SET_L12                 = KC_SPECIAL_START | 0x11C,
    KC_SET_L13                 = KC_SPECIAL_START | 0x11D,
    KC_SET_L14                 = KC_SPECIAL_START | 0x11E,
    KC_SET_L15                 = KC_SPECIAL_START | 0x11F,

    // actives a layer until it is pressed again (toggles it on off on press)
    KC_TOGGLE_L0               = KC_SPECIAL_START | 0x120,
    KC_TOGGLE_L1               = KC_SPECIAL_START | 0x121,
    KC_TOGGLE_L2               = KC_SPECIAL_START | 0x122,
    KC_TOGGLE_L3               = KC_SPECIAL_START | 0x123,
    KC_TOGGLE_L4               = KC_SPECIAL_START | 0x124,
    KC_TOGGLE_L5               = KC_SPECIAL_START | 0x125,
    KC_TOGGLE_L6               = KC_SPECIAL_START | 0x126,
    KC_TOGGLE_L7               = KC_SPECIAL_START | 0x127,
    KC_TOGGLE_L8               = KC_SPECIAL_START | 0x128,
    KC_TOGGLE_L9               = KC_SPECIAL_START | 0x129,
    KC_TOGGLE_L10              = KC_SPECIAL_START | 0x12A,
    KC_TOGGLE_L11              = KC_SPECIAL_START | 0x12B,
    KC_TOGGLE_L12              = KC_SPECIAL_START | 0x12C,
    KC_TOGGLE_L13              = KC_SPECIAL_START | 0x12D,
    KC_TOGGLE_L14              = KC_SPECIAL_START | 0x12E,
    KC_TOGGLE_L15              = KC_SPECIAL_START | 0x12F,

    // actives a layer until the next non-layer key is pressed
    KC_STICKY_L0               = KC_SPECIAL_START | 0x130,
    KC_STICKY_L1               = KC_SPECIAL_START | 0x131,
    KC_STICKY_L2               = KC_SPECIAL_START | 0x132,
    KC_STICKY_L3               = KC_SPECIAL_START | 0x133,
    KC_STICKY_L4               = KC_SPECIAL_START | 0x134,
    KC_STICKY_L5               = KC_SPECIAL_START | 0x135,
    KC_STICKY_L6               = KC_SPECIAL_START | 0x136,
    KC_STICKY_L7               = KC_SPECIAL_START | 0x137,
    KC_STICKY_L8               = KC_SPECIAL_START | 0x138,
    KC_STICKY_L9               = KC_SPECIAL_START | 0x139,
    KC_STICKY_L10              = KC_SPECIAL_START | 0x13A,
    KC_STICKY_L11              = KC_SPECIAL_START | 0x13B,
    KC_STICKY_L12              = KC_SPECIAL_START | 0x13C,
    KC_STICKY_L13              = KC_SPECIAL_START | 0x13D,
    KC_STICKY_L14              = KC_SPECIAL_START | 0x13E,
    KC_STICKY_L15              = KC_SPECIAL_START | 0x13F,

    KC_STICKY_LCTRL            = KC_SPECIAL_START | 0x140,
    KC_STICKY_LSHIFT           = KC_SPECIAL_START | 0x141,
    KC_STICKY_LALT             = KC_SPECIAL_START | 0x142,
    KC_STICKY_LGUI             = KC_SPECIAL_START | 0x143,
    KC_STICKY_RCTRL            = KC_SPECIAL_START | 0x144,
    KC_STICKY_RSHIFT           = KC_SPECIAL_START | 0x145,
    KC_STICKY_RALT             = KC_SPECIAL_START | 0x146,
    KC_STICKY_RGUI             = KC_SPECIAL_START | 0x147,

    // tap key
    KC_TAP_KEY                 = KC_SPECIAL_START | 0x1000,

    // hold key
    KC_HOLD_KEY                = KC_SPECIAL_START | 0x1001,

    // tap and hold
    KC_MACRO                   = KC_SPECIAL_START | 0x1002,
    KC_MACRO_UP_AND_DOWN       = KC_SPECIAL_START | 0x1003,
} special_keycode_t;

// enum values for mods
typedef enum mod_masks_t {
    MOD_LCTL = 0x01,
    MOD_LSFT = 0x02,
    MOD_LALT = 0x04,
    MOD_LGUI = 0x08,

    MOD_RCTL = 0x10,
    MOD_RSFT = 0x20,
    MOD_RALT = 0x40,
    MOD_RGUI = 0x80,
} mod_masks_t;

#define MODKEY_TAG_OFFSET (8)
#define MODKEY_TAG_RIGHT (0x10)
#define MODKEY_TAG_FORCE (0x20)

// enum values for mods in a modkey keycode
enum {
    MODKEY_TAG_LCTL = 0x01,
    MODKEY_TAG_LSFT = 0x02,
    MODKEY_TAG_LALT = 0x04,
    MODKEY_TAG_LGUI = 0x08,
    MODKEY_TAG_RCTL = 0x11,
    MODKEY_TAG_RSFT = 0x12,
    MODKEY_TAG_RALT = 0x14,
    MODKEY_TAG_RGUI = 0x18,
};

#define KEYCODE(kind, value)    ((kind)<<12 | (value))

// converts a modkey tag ts corresponding modifier
#define MODKEY_TAG_TO_MASK(x) ((x&MODKEY_TAG_RIGHT) ? (x&0x0f)<<4 : (x&0x0f))
#define MODKEY_TAG_IS_FORCED(x) (x&MODKEY_TAG_FORCE)

// TODO: should move this to functions to save flash size
#define MODKEY_KEYCODE(x) (x & 0xFF)
#define MODKEY_MODS(x) (MODKEY_TAG_TO_MASK((x>>8) & 0xFF))


// modkeys are a combination of a HID keycode and a set of modifiers. The
// modifiers part of the modkey can't mix left and right modifiers; they can
// only have one or the other.
#define MODKEY(mods, key) (KEYCODE(0, ((mods)&0x1f)<<8 | (key)))

#define MODKEY_FORCE_MODS(mods, key) ( KEYCODE(0, ((mods)&0x1f)<<8 | (key)) |\
        (MODKEY_TAG_FORCE << MODKEY_TAG_OFFSET) )

// Use these values instead of the HID keycodes for keymaps.
#define KC_LCTRL    MODKEY(MODKEY_TAG_LCTL, 0)
#define KC_LSHIFT   MODKEY(MODKEY_TAG_LSFT, 0)
#define KC_LALT     MODKEY(MODKEY_TAG_LALT, 0)
#define KC_LGUI     MODKEY(MODKEY_TAG_LGUI, 0)

#define KC_RCTRL    MODKEY(MODKEY_TAG_RCTL, 0)
#define KC_RSHIFT   MODKEY(MODKEY_TAG_RSFT, 0)
#define KC_RALT     MODKEY(MODKEY_TAG_RALT, 0)
#define KC_RGUI     MODKEY(MODKEY_TAG_RGUI, 0)

#define KC_l_c(kc) MODKEY(MODKEY_TAG_LCTL, KC_##kc)
#define KC_l_s(kc) MODKEY(MODKEY_TAG_LSFT, KC_##kc)
#define KC_l_a(kc) MODKEY(MODKEY_TAG_LALT, KC_##kc)
#define KC_l_g(kc) MODKEY(MODKEY_TAG_LGUI, KC_##kc)

#define KC_r_c(kc) MODKEY(MODKEY_TAG_RCTL, KC_##kc)
#define KC_r_s(kc) MODKEY(MODKEY_TAG_RSFT, KC_##kc)
#define KC_r_a(kc) MODKEY(MODKEY_TAG_RALT, KC_##kc)
#define KC_r_g(kc) MODKEY(MODKEY_TAG_RGUI, KC_##kc)

#define KC_c(kc) KC_l_c(kc)
#define KC_s(kc) KC_l_s(kc)
#define KC_a(kc) KC_l_a(kc)
#define KC_g(kc) KC_l_g(kc)

#define KC_f_(kc) (MODKEY_FORCE_MODS(0, KC_##kc))
#define KC_fc(kc) (KC_l_c(kc) | (MODKEY_TAG_FORCE << MODKEY_TAG_OFFSET))
#define KC_fs(kc) (KC_l_s(kc) | (MODKEY_TAG_FORCE << MODKEY_TAG_OFFSET))
#define KC_fa(kc) (KC_l_a(kc) | (MODKEY_TAG_FORCE << MODKEY_TAG_OFFSET))
#define KC_fg(kc) (KC_l_g(kc) | (MODKEY_TAG_FORCE << MODKEY_TAG_OFFSET))

#define IS_EXTERNAL(kc) (kc & KC_EXTERNAL_FLAG)
#define IS_MODKEY(kc) ((kc & 0xc000) == 0)
#define IS_MEDIA(kc) (kc >= KC_SYSTEM_POWER && kc <= KC_WWW_FAVORITES)
#define IS_MOUSEKEY(kc) (kc >= KC_MOUSE_UP && kc <= KC_MOUSE_BTN8)
#define IS_MOUSEKEY_BUTTON(kc) (kc >= KC_MOUSE_BTN1 && kc <= KC_MOUSE_BTN8)
#define MOUSEKEY_BUTTON_NUM(kc) ((kc - KC_MOUSE_BTN1) & 0x07)

#define EKC_ADDR(kc) ((kc) & KC_EXTERNAL_ADDR_MASK)
#define EKC_DATA_ADDR(kc) (((kc) & KC_EXTERNAL_ADDR_MASK) + 2)

extern XRAM flash_ptr_t g_ekc_storage_ptr;
extern XRAM uint32_t g_ekc_storage_size;

uint8_t get_ekc_data(void *dest, uint16_t offset, uint16_t size) REENT;
keycode_t get_ekc_class(keycode_t kc);
