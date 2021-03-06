#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

import keyplus.chip_id

from keyplus.exceptions import *

from keyplus.io_map.common import PinMap, IoMapperNumbered

virtual_key_map = {
    'NONE' : 0x00,
    'ERROR_ROLL_OVER' : 0x01,
    'POST_FAIL' : 0x02,
    'ERROR_UNDEFINED' : 0x03,
    'A' : 0x04,
    'B' : 0x05,
    'C' : 0x06,
    'D' : 0x07,
    'E' : 0x08,
    'F' : 0x09,
    'G' : 0x0a,
    'H' : 0x0b,
    'I' : 0x0c,
    'J' : 0x0d,
    'K' : 0x0e,
    'L' : 0x0f,
    'M' : 0x10,
    'N' : 0x11,
    'O' : 0x12,
    'P' : 0x13,
    'Q' : 0x14,
    'R' : 0x15,
    'S' : 0x16,
    'T' : 0x17,
    'U' : 0x18,
    'V' : 0x19,
    'W' : 0x1a,
    'X' : 0x1b,
    'Y' : 0x1c,
    'Z' : 0x1d,
    '1' : 0x1e,
    '2' : 0x1f,
    '3' : 0x20,
    '4' : 0x21,
    '5' : 0x22,
    '6' : 0x23,
    '7' : 0x24,
    '8' : 0x25,
    '9' : 0x26,
    '0' : 0x27,
    'ENTER' : 0x28, 'ENT' : 0x28,
    'ESCAPE' : 0x29,
    'BACKSPACE' : 0x2a,
    'TAB' : 0x2b,
    'SPACEBAR' : 0x2c,
    'MINUS' : 0x2d,
    'EQUAL' : 0x2e,
    'LEFT_BRACKET' : 0x2f, '[' : 0x2f,
    'RIGHT_BRACKET' : 0x30, ']' : 0x30,
    'BACK_SLASH' : 0x31, '\\' : 0x31,
    'ISO_HASH' : 0x32,
    'SEMICOLON' : 0x33, ';' : 0x33,
    'APOSTROPHE' : 0x34, '\'' : 0x34,
    'GRAVE' : 0x35,
    'COMMA' : 0x36, ',' : 0x36,
    'PERIOD' : 0x37, '.' : 0x37,
    'FORWARD_SLASH' : 0x38, '/' : 0x38,
    'CAPS_LOCK' : 0x39, 'CAPS' : 0x39,
    'F1' : 0x3a,
    'F2' : 0x3b,
    'F3' : 0x3c,
    'F4' : 0x3d,
    'F5' : 0x3e,
    'F6' : 0x3f,
    'F7' : 0x40,
    'F8' : 0x41,
    'F9' : 0x42,
    'F10' : 0x43,
    'F11' : 0x44,
    'F12' : 0x45,
    'PRINT_SCREEN' : 0x46,
    'SCROLL_LOCK' : 0x47,
    'PAUSE' : 0x48,
    'INSERT' : 0x49, 'INS' : 0x49,
    'HOME' : 0x4a,
    'PAGE_UP' : 0x4b, 'PGUP' : 0x4b,
    'DELETE' : 0x4c, 'DEL' : 0x4c,
    'END' : 0x4d, 'END' : 0x4d,
    'PAGE_DOWN' : 0x4e, 'PGDN' : 0x4e,
    'RIGHT_ARROW' : 0x4f, 'RIGHT' : 0x4f, 'RGHT' : 0x4f,
    'LEFT_ARROW' : 0x50, 'LEFT' : 0x50,
    'DOWN_ARROW' : 0x51, 'DOWN' : 0x51,
    'UP_ARROW' : 0x52, 'UP' : 0x52,
    'NUM_LOCK' : 0x53,
    'KP_FORWARD_SLASH' : 0x54,
    'KP_ASTERISK' : 0x55,
    'KP_MINUS' : 0x56,
    'KP_PLUS' : 0x57,
    'KP_ENTER' : 0x58,
    'KP_1' : 0x59,
    'KP_2' : 0x5a,
    'KP_3' : 0x5b,
    'KP_4' : 0x5c,
    'KP_5' : 0x5d,
    'KP_6' : 0x5e,
    'KP_7' : 0x5f,
    'KP_8' : 0x60,
    'KP_9' : 0x61,
    'KP_0' : 0x62,
    'KP_PERIOD' : 0x63,
    'ISO_BACK_SLASH' : 0x64,
    'APPLICATION' : 0x65,
    'POWER' : 0x66,
    'KP_EQUAL' : 0x67,
    'F13' : 0x68,
    'F14' : 0x69,
    'F15' : 0x6A,
    'F16' : 0x6B,
    'F17' : 0x6C,
    'F18' : 0x6D,
    'F19' : 0x6E,
    'F20' : 0x6F,
    'F21' : 0x70,
    'F22' : 0x71,
    'F23' : 0x72,
    'F24' : 0x73,
    'EXECUTE' : 0x74,
    'HELP' : 0x75,
    'MENU' : 0x76,
    'SELECT' : 0x77,
    'STOP' : 0x78,
    'AGAIN' : 0x79,
    'UNDO' : 0x7a,
    'CUT' : 0x7b,
    'COPY' : 0x7c,
    'PASTE' : 0x7d,
    'FIND' : 0x7e,
    'MUTE' : 0x7f,
    'VOLUME_UP' : 0x80,
    'VOLUME_DOWN' : 0x81,
    'LOCKING_CAPS_LOCK' : 0x82,
    'LOCKING_NUM_LOCK' : 0x83,
    'LOCKING_SCROLL_LOCK' : 0x84,
    'KP_COMMA' : 0x85,
    'KP_EQUAL_AS400' : 0x86,
    'INTERNATIONAL_1' : 0x87,
    'INTERNATIONAL_2' : 0x88,
    'INTERNATIONAL_3' : 0x89,
    'INTERNATIONAL_4' : 0x8a,
    'INTERNATIONAL_5' : 0x8b,
    'INTERNATIONAL_6' : 0x8c,
    'INTERNATIONAL_7' : 0x8d,
    'INTERNATIONAL_8' : 0x8e,
    'INTERNATIONAL_9' : 0x8f,
    'LANG_1' : 0x90,
    'LANG_2' : 0x91,
    'LANG_3' : 0x92,
    'LANG_4' : 0x93,
    'LANG_5' : 0x94,
    'LANG_6' : 0x95,
    'LANG_7' : 0x96,
    'LANG_8' : 0x97,
    'LANG_9' : 0x98,
    'ALTERNATE_ERASE' : 0x99,
    'SYS_REQ' : 0x9a,
    'CANCEL' : 0x9b,
    'CLEAR' : 0x9c,
    'PRIOR' : 0x9d,
    'RETURN' : 0x9e,
    'SEPARATOR' : 0x9f,
    'OUT' : 0xa0,
    'OPER' : 0xa1,
    'CLEAR_AGAIN' : 0xa2,
    'CRSEL' : 0xa3,
    'EXSEL' : 0xa4,
    # /* reserved a5-af */
    # /* KC_RESERVED               = 0xa5, */
    # /* KC_RESERVED               = 0xa6, */
    # /* KC_RESERVED               = 0xa7, */
    # /* KC_RESERVED               = 0xa8, */
    # /* KC_RESERVED               = 0xa9, */
    # /* KC_RESERVED               = 0xaa, */
    # /* KC_RESERVED               = 0xab, */
    # /* KC_RESERVED               = 0xac, */
    # /* KC_RESERVED               = 0xad, */
    # /* KC_RESERVED               = 0xae, */
    # /* KC_RESERVED               = 0xaf, */
    'KP_00' : 0xb0,
    'KP_000' : 0xb1,
    'THOUSANDS_SEPARATOR' : 0xb2,
    'DECIMAL_SEPARATOR' : 0xb3,
    'CURRENCY_UNIT' : 0xb4,
    'CURRENCY_SUB_UNIT' : 0xb5,
    'KP_LEFT_PARENTHESIS' : 0xb6,
    'KP_RIGHT_PARENTHESIS' : 0xb7,
    'KP_LEFT_BRACE' : 0xb8,
    'KP_RIGHT_BRACE' : 0xb9,
    'KP_TAB' : 0xba,
    'KP_BACK_SPACE' : 0xbb,
    'KP_A' : 0xbc,
    'KP_B' : 0xbd,
    'KP_C' : 0xbe,
    'KP_D' : 0xbf,
    'KP_E' : 0xc0,
    'KP_F' : 0xc1,
    'KP_XOR' : 0xc2,
    'KP_CARET' : 0xc3,
    'KP_PERCENT' : 0xc4,
    'KP_LESS_THAN' : 0xc5,
    'KP_GREATER_THAN' : 0xc6,
    'KP_BITWISE_AND' : 0xc7,
    'KP_LOGICAL_AND' : 0xc8,
    'KP_BITWISE_OR' : 0xc9,
    'KP_LOGICAL_OR' : 0xca,
    'KP_COLON' : 0xcb,
    'KP_HASH' : 0xcc,
    'KP_SPACE' : 0xcd,
    'KP_AT_SIGN' : 0xce,
    'KP_EXCLAMATION' : 0xcf,
    'KP_MEMORY_STORE' : 0xd0,
    'KP_MEMORY_RECALL' : 0xd1,
    'KP_MEMORY_CLEAR' : 0xd2,
    'KP_MEMORY_ADD' : 0xd3,
    'KP_MEMORY_SUBTRACT' : 0xd4,
    'KP_MEMORY_MULTIPLY' : 0xd5,
    'KP_MEMORY_DIVIDE' : 0xd6,
    'KP_PLUS_MINUS' : 0xd7,
    'KP_CLEAR' : 0xd8,
    'KP_CLEAR_ENTRY' : 0xd9,
    'KP_BINARY' : 0xda,
    'KP_OCTAL' : 0xdb,
    'KP_DECIMAL' : 0xdc,
    'KP_HEXADECIMAL' : 0xdd,
    # /* reserved de-df */
    # /* KC_RESERVED               = 0xde, */
    # /* KC_RESERVED               = 0xdf, */
    'LEFT_CONTROL' : 0xe0, 'LCTRL' : 0xe0, 'LCTL' : 0xe0,
    'LEFT_SHIFT' : 0xe1, 'LSFT' : 0xe1,
    'LEFT_ALT' : 0xe2, 'LALT' : 0xe2,
    'LEFT_GUI' : 0xe3, 'LGUI' : 0xe3, 'LMETA' : 0xe3, 'LWIN' : 0xe3,
    'RIGHT_CONTROL' : 0xe4, 'RCTRL' : 0xe4, 'RCTL' : 0xe4,
    'RIGHT_SHIFT' : 0xe5, 'RSFT' : 0xe5,
    'RIGHT_ALT' : 0xe6, 'RALT' : 0xe6,
    'RIGHT_GUI' : 0xe7, 'RGUI' : 0xe7, 'RMETA' : 0xe7, 'RWIN' : 0xe7,
    # /* reserved e8-ffff */

    'SYS_POWER'         : 0x101,  # 0x81: HID_DESKTOP_SYSTEM_POWER_DOWN
    'SYS_SLEEP'         : 0x102,  # 0x82: HID_DESKTOP_SYSTEM_SLEEP
    'SYS_WAKEUP'        : 0x103,  # 0x83: HID_DESKTOP_SYSTEM_WAKE_UP
    'SYS_CONTEXT_MENU'  : 0x104,  # 0x84: HID_DESKTOP_SYSTEM_CONTEXT_MENU
    'SYS_MENU'          : 0x105,  # 0x85: HID_DESKTOP_SYSTEM_MAIN_MENU
    'SYS_APP_MENU'      : 0x106,  # 0x86: HID_DESKTOP_SYSTEM_APP_MENU
    'SYS_HELP'          : 0x107,  # 0x87: HID_DESKTOP_SYSTEM_MENU_HELP
    'SYS_EXIT'          : 0x108,  # 0x88: HID_DESKTOP_SYSTEM_MENU_EXIT
    'SYS_SELECT'        : 0x109,  # 0x89: HID_DESKTOP_SYSTEM_MENU_SELECT
    'SYS_RIGHT'         : 0x10a,  # 0x8a: HID_DESKTOP_SYSTEM_MENU_RIGHT
    'SYS_LEFT'          : 0x10b,  # 0x8b: HID_DESKTOP_SYSTEM_MENU_LEFT
    'SYS_UP'            : 0x10c,  # 0x8c: HID_DESKTOP_SYSTEM_MENU_UP
    'SYS_DOWN'          : 0x10d,  # 0x8d: HID_DESKTOP_SYSTEM_MENU_DOWN
    'SYS_COLD_RESTART'  : 0x10e,  # 0x8e: HID_DESKTOP_SYSTEM_COLD_RESTART
    'SYS_WARM_RESTART'  : 0x10f,  # 0x8f: HID_DESKTOP_SYSTEM_WARM_RESTART

    'BTN1' : 0x110,  # Left Mouse Button
    'BTN2' : 0x111,  # Right Mouse Button
    'BTN3' : 0x112,  # Middle Mouse Button
    'BTN4' : 0x113,  # Mouse Button 4
    'BTN5' : 0x114,  # Mouse Button 5
    'BTN6' : 0x115,  # Mouse Button 6
    'BTN7' : 0x116,  # Mouse Button 7
    'BTN8' : 0x117,  # Mouse Button 8

}


class IoMapperVirtual():

    def __init__(self, chip_id):
        self.chip_info = keyplus.chip_id.lookup_chip_id(chip_id)

    def get_pin_number(self, name):
        name = str(name).upper()
        if name in virtual_key_map:
            return virtual_key_map[name]
        else:
            raise KeyplusSettingsError("Unknown key in map: {}".format(name))

    def get_pin_numbers(self, pin_names):
        return [self.get_pin_number(pin) for pin in pin_names]

    def get_gpio_count(self):
        return 512
