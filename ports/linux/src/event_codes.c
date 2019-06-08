// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "event_codes.h"

const uint16_t HID_KB_TO_EV[KB_EVENT_MAP_LEN] = {
    0                      , // 0x00: KC_NONE                   ,
    0                      , // 0x01: KC_ERROR_ROLL_OVER        ,
    0                      , // 0x02: KC_POST_FAIL              ,
    0                      , // 0x03: KC_ERROR_UNDEFINED        ,
    KEY_A                  , // 0x04: KC_A                      ,
    KEY_B                  , // 0x05: KC_B                      ,
    KEY_C                  , // 0x06: KC_C                      ,
    KEY_D                  , // 0x07: KC_D                      ,
    KEY_E                  , // 0x08: KC_E                      ,
    KEY_F                  , // 0x09: KC_F                      ,
    KEY_G                  , // 0x0a: KC_G                      ,
    KEY_H                  , // 0x0b: KC_H                      ,
    KEY_I                  , // 0x0c: KC_I                      ,
    KEY_J                  , // 0x0d: KC_J                      ,
    KEY_K                  , // 0x0e: KC_K                      ,
    KEY_L                  , // 0x0f: KC_L                      ,
    KEY_M                  , // 0x10: KC_M                      ,
    KEY_N                  , // 0x11: KC_N                      ,
    KEY_O                  , // 0x12: KC_O                      ,
    KEY_P                  , // 0x13: KC_P                      ,
    KEY_Q                  , // 0x14: KC_Q                      ,
    KEY_R                  , // 0x15: KC_R                      ,
    KEY_S                  , // 0x16: KC_S                      ,
    KEY_T                  , // 0x17: KC_T                      ,
    KEY_U                  , // 0x18: KC_U                      ,
    KEY_V                  , // 0x19: KC_V                      ,
    KEY_W                  , // 0x1a: KC_W                      ,
    KEY_X                  , // 0x1b: KC_X                      ,
    KEY_Y                  , // 0x1c: KC_Y                      ,
    KEY_Z                  , // 0x1d: KC_Z                      ,
    KEY_1                  , // 0x1e: KC_1                      ,
    KEY_2                  , // 0x1f: KC_2                      ,
    KEY_3                  , // 0x20: KC_3                      ,
    KEY_4                  , // 0x21: KC_4                      ,
    KEY_5                  , // 0x22: KC_5                      ,
    KEY_6                  , // 0x23: KC_6                      ,
    KEY_7                  , // 0x24: KC_7                      ,
    KEY_8                  , // 0x25: KC_8                      ,
    KEY_9                  , // 0x26: KC_9                      ,
    KEY_0                  , // 0x27: KC_0                      ,
    KEY_ENTER              , // 0x28: KC_ENTER                  ,
    KEY_ESC                , // 0x29: KC_ESCAPE                 ,
    KEY_BACKSPACE          , // 0x2a: KC_BACKSPACE              ,
    KEY_TAB                , // 0x2b: KC_TAB                    ,
    KEY_SPACE              , // 0x2c: KC_SPACEBAR               ,
    KEY_MINUS              , // 0x2d: KC_MINUS                  ,
    KEY_EQUAL              , // 0x2e: KC_EQUAL                  ,
    KEY_LEFTBRACE          , // 0x2f: KC_LEFT_BRACKET           ,
    KEY_RIGHTBRACE         , // 0x30: KC_RIGHT_BRACKET          ,
    KEY_BACKSLASH          , // 0x31: KC_BACK_SLASH             ,
    KEY_BACKSLASH          , // 0x32: KC_ISO_HASH               , NOTE: same as above
    KEY_SEMICOLON          , // 0x33: KC_SEMICOLON              ,
    KEY_APOSTROPHE         , // 0x34: KC_APOSTROPHE             ,
    KEY_GRAVE              , // 0x35: KC_GRAVE                  ,
    KEY_COMMA              , // 0x36: KC_COMMA                  ,
    KEY_DOT                , // 0x37: KC_PERIOD                 ,
    KEY_SLASH              , // 0x38: KC_FORWARD_SLASH          ,
    KEY_CAPSLOCK           , // 0x39: KC_CAPS_LOCK              ,
    KEY_F1                 , // 0x3a: KC_F1                     ,
    KEY_F2                 , // 0x3b: KC_F2                     ,
    KEY_F3                 , // 0x3c: KC_F3                     ,
    KEY_F4                 , // 0x3d: KC_F4                     ,
    KEY_F5                 , // 0x3e: KC_F5                     ,
    KEY_F6                 , // 0x3f: KC_F6                     ,
    KEY_F7                 , // 0x40: KC_F7                     ,
    KEY_F8                 , // 0x41: KC_F8                     ,
    KEY_F9                 , // 0x42: KC_F9                     ,
    KEY_F10                , // 0x43: KC_F10                    ,
    KEY_F11                , // 0x44: KC_F11                    ,
    KEY_F12                , // 0x45: KC_F12                    ,
    KEY_SYSRQ              , // 0x46: KC_PRINT_SCREEN           ,
    KEY_SCROLLLOCK         , // 0x47: KC_SCROLL_LOCK            ,
    KEY_PAUSE              , // 0x48: KC_PAUSE                  ,
    KEY_INSERT             , // 0x49: KC_INSERT                 ,
    KEY_HOME               , // 0x4a: KC_HOME                   ,
    KEY_PAGEUP             , // 0x4b: KC_PAGE_UP                ,
    KEY_DELETE             , // 0x4c: KC_DELETE                 ,
    KEY_END                , // 0x4d: KC_END                    ,
    KEY_PAGEDOWN           , // 0x4e: KC_PAGE_DOWN              ,
    KEY_RIGHT              , // 0x4f: KC_RIGHT_ARROW            ,
    KEY_LEFT               , // 0x50: KC_LEFT_ARROW             ,
    KEY_DOWN               , // 0x51: KC_DOWN_ARROW             ,
    KEY_UP                 , // 0x52: KC_UP_ARROW               ,
    KEY_NUMLOCK            , // 0x53: KC_NUM_LOCK               ,
    KEY_KPSLASH            , // 0x54: KC_KP_FORWARD_SLASH       ,
    KEY_KPASTERISK         , // 0x55: KC_KP_ASTERISK            ,
    KEY_KPMINUS            , // 0x56: KC_KP_MINUS               ,
    KEY_KPPLUS             , // 0x57: KC_KP_PLUS                ,
    KEY_KPENTER            , // 0x58: KC_KP_ENTER               ,
    KEY_KP1                , // 0x59: KC_KP_1                   ,
    KEY_KP2                , // 0x5a: KC_KP_2                   ,
    KEY_KP3                , // 0x5b: KC_KP_3                   ,
    KEY_KP4                , // 0x5c: KC_KP_4                   ,
    KEY_KP5                , // 0x5d: KC_KP_5                   ,
    KEY_KP6                , // 0x5e: KC_KP_6                   ,
    KEY_KP7                , // 0x5f: KC_KP_7                   ,
    KEY_KP8                , // 0x60: KC_KP_8                   ,
    KEY_KP9                , // 0x61: KC_KP_9                   ,
    KEY_KP0                , // 0x62: KC_KP_0                   ,
    KEY_KPDOT              , // 0x63: KC_KP_PERIOD              ,
    KEY_102ND              , // 0x64: KC_ISO_BACK_SLASH         ,
    KEY_COMPOSE            , // 0x65: KC_APPLICATION            ,
    KEY_POWER              , // 0x66: KC_POWER                  ,
    KEY_KPEQUAL            , // 0x67: KC_KP_EQUAL               ,
    KEY_F13                , // 0x68: KC_F13                    ,
    KEY_F14                , // 0x69: KC_F14                    ,
    KEY_F15                , // 0x6A: KC_F15                    ,
    KEY_F16                , // 0x6B: KC_F16                    ,
    KEY_F17                , // 0x6C: KC_F17                    ,
    KEY_F18                , // 0x6D: KC_F18                    ,
    KEY_F19                , // 0x6E: KC_F19                    ,
    KEY_F20                , // 0x6F: KC_F20                    ,
    KEY_F21                , // 0x70: KC_F21                    ,
    KEY_F22                , // 0x71: KC_F22                    ,
    KEY_F23                , // 0x72: KC_F23                    ,
    KEY_F24                , // 0x73: KC_F24                    ,
    KEY_OPEN               , // 0x74: KC_EXECUTE                ,
    KEY_HELP               , // 0x75: KC_HELP                   ,
    KEY_MENU               , // 0x76: KC_MENU                   ,
    KEY_FRONT              , // 0x77: KC_SELECT                 ,
    KEY_STOP               , // 0x78: KC_STOP                   ,
    KEY_AGAIN              , // 0x79: KC_AGAIN                  ,
    KEY_UNDO               , // 0x7a: KC_UNDO                   ,
    KEY_CUT                , // 0x7b: KC_CUT                    ,
    KEY_COPY               , // 0x7c: KC_COPY                   ,
    KEY_PASTE              , // 0x7d: KC_PASTE                  ,
    KEY_FIND               , // 0x7e: KC_FIND                   ,
    KEY_MUTE               , // 0x7f: KC_MUTE                   ,
    KEY_VOLUMEUP           , // 0x80: KC_VOLUME_UP              ,
    KEY_VOLUMEDOWN         , // 0x81: KC_VOLUME_DOWN            ,
    KEY_UNKNOWN            , // 0x82: KC_LOCKING_CAPS_LOCK      ,
    KEY_UNKNOWN            , // 0x83: KC_LOCKING_NUM_LOCK       ,
    KEY_UNKNOWN            , // 0x84: KC_LOCKING_SCROLL_LOCK    ,
    KEY_KPCOMMA            , // 0x85: KC_KP_COMMA               ,
    KEY_UNKNOWN            , // 0x86: KC_KP_EQUAL_AS400         ,
    KEY_RO                 , // 0x87: KC_INTERNATIONAL_1        ,
    KEY_KATAKANAHIRAGANA   , // 0x88: KC_INTERNATIONAL_2        ,
    KEY_YEN                , // 0x89: KC_INTERNATIONAL_3        ,
    KEY_HENKAN             , // 0x8a: KC_INTERNATIONAL_4        ,
    KEY_MUHENKAN           , // 0x8b: KC_INTERNATIONAL_5        ,
    KEY_KPJPCOMMA          , // 0x8c: KC_INTERNATIONAL_6        ,
    KEY_UNKNOWN            , // 0x8d: KC_INTERNATIONAL_7        ,
    KEY_UNKNOWN            , // 0x8e: KC_INTERNATIONAL_8        ,
    KEY_UNKNOWN            , // 0x8f: KC_INTERNATIONAL_9        ,
    KEY_HANGUEL            , // 0x90: KC_LANG_1                 ,
    KEY_HANJA              , // 0x91: KC_LANG_2                 ,
    KEY_KATAKANA           , // 0x92: KC_LANG_3                 ,
    KEY_HIRAGANA           , // 0x93: KC_LANG_4                 ,
    KEY_ZENKAKUHANKAKU     , // 0x94: KC_LANG_5                 ,
    KEY_UNKNOWN            , // 0x95: KC_LANG_6                 ,
    KEY_UNKNOWN            , // 0x96: KC_LANG_7                 ,
    KEY_UNKNOWN            , // 0x97: KC_LANG_8                 ,
    KEY_UNKNOWN            , // 0x98: KC_LANG_9                 ,
    KEY_UNKNOWN            , // 0x99: KC_ALTERNATE_ERASE        ,
    KEY_UNKNOWN            , // 0x9a: KC_SYS_REQ                ,
    KEY_UNKNOWN            , // 0x9b: KC_CANCEL                 ,
    KEY_DELETE             , // 0x9c: KC_CLEAR                  ,
    KEY_UNKNOWN            , // 0x9d: KC_PRIOR                  ,
    KEY_UNKNOWN            , // 0x9e: KC_RETURN                 ,
    KEY_UNKNOWN            , // 0x9f: KC_SEPARATOR              ,
    KEY_UNKNOWN            , // 0xa0: KC_OUT                    ,
    KEY_UNKNOWN            , // 0xa1: KC_OPER                   ,
    KEY_UNKNOWN            , // 0xa2: KC_CLEAR_AGAIN            ,
    KEY_UNKNOWN            , // 0xa3: KC_CRSEL                  ,
    KEY_UNKNOWN            , // 0xa4: KC_EXSEL                  ,
    KEY_UNKNOWN            , /* 0xa5: KC_RESERVED               , */
    KEY_UNKNOWN            , /* 0xa6: KC_RESERVED               , */
    KEY_UNKNOWN            , /* 0xa7: KC_RESERVED               , */
    KEY_UNKNOWN            , /* 0xa8: KC_RESERVED               , */
    KEY_UNKNOWN            , /* 0xa9: KC_RESERVED               , */
    KEY_UNKNOWN            , /* 0xaa: KC_RESERVED               , */
    KEY_UNKNOWN            , /* 0xab: KC_RESERVED               , */
    KEY_UNKNOWN            , /* 0xac: KC_RESERVED               , */
    KEY_UNKNOWN            , /* 0xad: KC_RESERVED               , */
    KEY_UNKNOWN            , /* 0xae: KC_RESERVED               , */
    KEY_UNKNOWN            , /* 0xaf: KC_RESERVED               , */
    KEY_UNKNOWN            , // 0xb0: KC_KP_00                  ,
    KEY_UNKNOWN            , // 0xb1: KC_KP_000                 ,
    KEY_UNKNOWN            , // 0xb2: KC_THOUSANDS_SEPARATOR    ,
    KEY_UNKNOWN            , // 0xb3: KC_DECIMAL_SEPARATOR      ,
    KEY_UNKNOWN            , // 0xb4: KC_CURRENCY_UNIT          ,
    KEY_UNKNOWN            , // 0xb5: KC_CURRENCY_SUB_UNIT      ,
    KEY_KPLEFTPAREN        , // 0xb6: KC_KP_LEFT_PARENTHESIS    ,
    KEY_KPRIGHTPAREN       , // 0xb7: KC_KP_RIGHT_PARENTHESIS   ,
    KEY_UNKNOWN            , // 0xb8: KC_KP_LEFT_BRACE          ,
    KEY_UNKNOWN            , // 0xb9: KC_KP_RIGHT_BRACE         ,
    KEY_UNKNOWN            , // 0xba: KC_KP_TAB                 ,
    KEY_UNKNOWN            , // 0xbb: KC_KP_BACK_SPACE          ,
    KEY_UNKNOWN            , // 0xbc: KC_KP_A                   ,
    KEY_UNKNOWN            , // 0xbd: KC_KP_B                   ,
    KEY_UNKNOWN            , // 0xbe: KC_KP_C                   ,
    KEY_UNKNOWN            , // 0xbf: KC_KP_D                   ,
    KEY_UNKNOWN            , // 0xc0: KC_KP_E                   ,
    KEY_UNKNOWN            , // 0xc1: KC_KP_F                   ,
    KEY_UNKNOWN            , // 0xc2: KC_KP_XOR                 ,
    KEY_UNKNOWN            , // 0xc3: KC_KP_CARET               ,
    KEY_UNKNOWN            , // 0xc4: KC_KP_PERCENT             ,
    KEY_UNKNOWN            , // 0xc5: KC_KP_LESS_THAN           ,
    KEY_UNKNOWN            , // 0xc6: KC_KP_GREATER_THAN        ,
    KEY_UNKNOWN            , // 0xc7: KC_KP_BITWISE_AND         ,
    KEY_UNKNOWN            , // 0xc8: KC_KP_LOGICAL_AND         ,
    KEY_UNKNOWN            , // 0xc9: KC_KP_BITWISE_OR          ,
    KEY_UNKNOWN            , // 0xca: KC_KP_LOGICAL_OR          ,
    KEY_UNKNOWN            , // 0xcb: KC_KP_COLON               ,
    KEY_UNKNOWN            , // 0xcc: KC_KP_HASH                ,
    KEY_UNKNOWN            , // 0xcd: KC_KP_SPACE               ,
    KEY_UNKNOWN            , // 0xce: KC_KP_AT_SIGN             ,
    KEY_UNKNOWN            , // 0xcf: KC_KP_EXCLAMATION         ,
    KEY_UNKNOWN            , // 0xd0: KC_KP_MEMORY_STORE        ,
    KEY_UNKNOWN            , // 0xd1: KC_KP_MEMORY_RECALL       ,
    KEY_UNKNOWN            , // 0xd2: KC_KP_MEMORY_CLEAR        ,
    KEY_UNKNOWN            , // 0xd3: KC_KP_MEMORY_ADD          ,
    KEY_UNKNOWN            , // 0xd4: KC_KP_MEMORY_SUBTRACT     ,
    KEY_UNKNOWN            , // 0xd5: KC_KP_MEMORY_MULTIPLY     ,
    KEY_UNKNOWN            , // 0xd6: KC_KP_MEMORY_DIVIDE       ,
    KEY_UNKNOWN            , // 0xd7: KC_KP_PLUS_MINUS          ,
    KEY_DELETE             , // 0xd8: KC_KP_CLEAR               ,
    KEY_UNKNOWN            , // 0xd9: KC_KP_CLEAR_ENTRY         ,
    KEY_UNKNOWN            , // 0xda: KC_KP_BINARY              ,
    KEY_UNKNOWN            , // 0xdb: KC_KP_OCTAL               ,
    KEY_UNKNOWN            , // 0xdc: KC_KP_DECIMAL             ,
    KEY_UNKNOWN            , // 0xdd: KC_KP_HEXADECIMAL         ,
    KEY_UNKNOWN            , /* 0xde: KC_RESERVED               , */
    KEY_UNKNOWN            , /* 0xdf: KC_RESERVED               , */
    KEY_LEFTCTRL           , // 0xe0: KC_LEFT_CONTROL           ,
    KEY_LEFTSHIFT          , // 0xe1: KC_LEFT_SHIFT             ,
    KEY_LEFTALT            , // 0xe2: KC_LEFT_ALT               ,
    KEY_LEFTMETA           , // 0xe3: KC_LEFT_GUI               ,
    KEY_RIGHTCTRL          , // 0xe4: KC_RIGHT_CONTROL          ,
    KEY_RIGHTSHIFT         , // 0xe5: KC_RIGHT_SHIFT            ,
    KEY_RIGHTALT           , // 0xe6: KC_RIGHT_ALT              ,
    KEY_RIGHTMETA          , // 0xe7: KC_RIGHT_GUI              ,
    /* reserved e8-ffff */
};

const uint16_t HID_MOUSE_TO_EV[MOUSE_EVENT_MAP_LEN] = {
    BTN_LEFT,
    BTN_RIGHT,
    BTN_MIDDLE,
    BTN_SIDE,
    BTN_EXTRA,
    BTN_FORWARD,
    BTN_BACK,
    BTN_TASK,
};

const uint16_t HID_SYSTEM_TO_EV_TABLE[SYSTEM_EVENT_MAP_LEN] = {
    ABS_MISC            , // 0x80: HID_DESKTOP_SYSTEM_CONTROL
    KEY_POWER           , // 0x81: HID_DESKTOP_SYSTEM_POWER_DOWN
    KEY_SLEEP           , // 0x82: HID_DESKTOP_SYSTEM_SLEEP
    KEY_WAKEUP          , // 0x83: HID_DESKTOP_SYSTEM_WAKE_UP
    KEY_CONTEXT_MENU    , // 0x84: HID_DESKTOP_SYSTEM_CONTEXT_MENU
    KEY_MENU            , // 0x85: HID_DESKTOP_SYSTEM_MAIN_MENU
    KEY_PROG1           , // 0x86: HID_DESKTOP_SYSTEM_APP_MENU
    KEY_HELP            , // 0x87: HID_DESKTOP_SYSTEM_MENU_HELP
    KEY_EXIT            , // 0x88: HID_DESKTOP_SYSTEM_MENU_EXIT
    KEY_SELECT          , // 0x89: HID_DESKTOP_SYSTEM_MENU_SELECT
    KEY_RIGHT           , // 0x8a: HID_DESKTOP_SYSTEM_MENU_RIGHT
    KEY_LEFT            , // 0x8b: HID_DESKTOP_SYSTEM_MENU_LEFT
    KEY_UP              , // 0x8c: HID_DESKTOP_SYSTEM_MENU_UP
    KEY_DOWN            , // 0x8d: HID_DESKTOP_SYSTEM_MENU_DOWN
    KEY_POWER2          , // 0x8e: HID_DESKTOP_SYSTEM_COLD_RESTART
    KEY_RESTART         , // 0x8f: HID_DESKTOP_SYSTEM_WARM_RESTART
    0                   , // 0x90: HID_DESKTOP_D_PAD_UP
    0                   , // 0x91: HID_DESKTOP_D_PAD_DOWN
    0                   , // 0x92: HID_DESKTOP_D_PAD_RIGHT
    0                   , // 0x93: HID_DESKTOP_D_PAD_LEFT
    0                   , // 0x94
    0                   , // 0x95
    0                   , // 0x96
    0                   , // 0x97
    0                   , // 0x98
    0                   , // 0x99
    0                   , // 0x9a
    0                   , // 0x9b
    0                   , // 0x9c
    0                   , // 0x9d
    0                   , // 0x9e
    0                   , // 0x9f
    0                   , // 0xa0: HID_DESKTOP_SYSTEM_DOCK
    0                   , // 0xa1: HID_DESKTOP_SYSTEM_UNDOCK
    0                   , // 0xa2: HID_DESKTOP_SYSTEM_SETUP
    0                   , // 0xa3: HID_DESKTOP_SYSTEM_BREAK
    0                   , // 0xa4: HID_DESKTOP_SYSTEM_DEBUGGER_BREAK
    0                   , // 0xa5: HID_DESKTOP_APPLICATION_BREAK
    0                   , // 0xa6: HID_DESKTOP_APPLICATION_DEBUGGER_BREAK
    0                   , // 0xa7: HID_DESKTOP_SYSTEM_SPEAKER_MUTE
    0                   , // 0xa8: HID_DESKTOP_SYSTEM_HIBERNATE
    0                   , // 0xa9
    0                   , // 0xaa
    0                   , // 0xab
    0                   , // 0xac
    0                   , // 0xad
    0                   , // 0xae
    0                   , // 0xaf
    0                   , // 0xb0: HID_DESKTOP_SYSTEM_DISPLAY_INVERT
    0                   , // 0xb1: HID_DESKTOP_SYSTEM_DISPLAY_INTERNAL
    0                   , // 0xb2: HID_DESKTOP_SYSTEM_DISPLAY_EXTERNAL
    0                   , // 0xb3: HID_DESKTOP_SYSTEM_DISPLAY_BOTH
    0                   , // 0xb4: HID_DESKTOP_SYSTEM_DISPLAY_DUAL
    KEY_SWITCHVIDEOMODE , // 0xb5: HID_DESKTOP_SYSTEM_DISPLAY_TOGGLE_INT_EXT
    0                   , // 0xb6: HID_DESKTOP_SYSTEM_DISPLAY_SWAP_PRIMARY_SECONDARY
    0                   , // 0xb7: HID_DESKTOP_SYSTEM_DISPLAY_LCD_AUTOSCALE
    0                   , // 0xb8
    0                   , // 0xb9
    0                   , // 0xba
    0                   , // 0xbb
    0                   , // 0xbc
    0                   , // 0xbd
    0                   , // 0xbe
    0                   , // 0xbf
    0                   , // 0xc0
    0                   , // 0xc1
    0                   , // 0xc2
    0                   , // 0xc3
    0                   , // 0xc4
    0                   , // 0xc5
    0                   , // 0xc6
    0                   , // 0xc7
    0                   , // 0xc8
    0                   , // 0xc9
    0                   , // 0xca
    0                   , // 0xcb
    0                   , // 0xcc
    0                   , // 0xcd
    0                   , // 0xce
    0                   , // 0xcf
    0                   , // 0xd0
    0                   , // 0xd1
    0                   , // 0xd2
    0                   , // 0xd3
    0                   , // 0xd4
    0                   , // 0xd5
    0                   , // 0xd6
    0                   , // 0xd7
    0                   , // 0xd8
    0                   , // 0xd9
    0                   , // 0xda
    0                   , // 0xdb
    0                   , // 0xdc
    0                   , // 0xdd
    0                   , // 0xde
    0                   , // 0xdf
    0                   , // 0xe0
    0                   , // 0xe1
    0                   , // 0xe2
    0                   , // 0xe3
    0                   , // 0xe4
    0                   , // 0xe5
    0                   , // 0xe6
    0                   , // 0xe7
    0                   , // 0xe8
    0                   , // 0xe9
    0                   , // 0xea
    0                   , // 0xeb
    0                   , // 0xec
    0                   , // 0xed
    0                   , // 0xee
    0                   , // 0xef
    0                   , // 0xf0
    0                   , // 0xf1
    0                   , // 0xf2
    0                   , // 0xf3
    0                   , // 0xf4
    0                   , // 0xf5
    0                   , // 0xf6
    0                   , // 0xf7
    0                   , // 0xf8
    0                   , // 0xf9
    0                   , // 0xfa
    0                   , // 0xfb
    0                   , // 0xfc
    0                   , // 0xfd
    0                   , // 0xfe
    0                   , // 0xff
};

const uint16_t HID_CONSUMER_TO_EV_TABLE[CONSUMER_EVENT_MAP_LEN] = {
    0                   , /* 0x0000: HID_CONSUMER_UNASSIGNED */
    KEY_UNKNOWN         , /* 0x0001: HID_CONSUMER_CONSUMER_CONTROL     */
    KEY_UNKNOWN         , /* 0x0002: HID_CONSUMER_NUMERIC_KEY_PAD      */
    KEY_UNKNOWN         , /* 0x0003: HID_CONSUMER_PROGRAMMABLE_BUTTONS */
    KEY_UNKNOWN         , /* 0x0004: HID_CONSUMER_MICROPHONE           */
    KEY_UNKNOWN         , /* 0x0005: HID_CONSUMER_HEADPHONE            */
    KEY_UNKNOWN         , /* 0x0006: HID_CONSUMER_GRAPHIC_EQUALIZER    */
    KEY_UNKNOWN         , /* 0x0007 */
    KEY_UNKNOWN         , /* 0x0008 */
    KEY_UNKNOWN         , /* 0x0009 */
    KEY_UNKNOWN         , /* 0x000a */
    KEY_UNKNOWN         , /* 0x000b */
    KEY_UNKNOWN         , /* 0x000c */
    KEY_UNKNOWN         , /* 0x000d */
    KEY_UNKNOWN         , /* 0x000e */
    KEY_UNKNOWN         , /* 0x000f */
    KEY_UNKNOWN         , /* 0x0010 */
    KEY_UNKNOWN         , /* 0x0011 */
    KEY_UNKNOWN         , /* 0x0012 */
    KEY_UNKNOWN         , /* 0x0013 */
    KEY_UNKNOWN         , /* 0x0014 */
    KEY_UNKNOWN         , /* 0x0015 */
    KEY_UNKNOWN         , /* 0x0016 */
    KEY_UNKNOWN         , /* 0x0017 */
    KEY_UNKNOWN         , /* 0x0018 */
    KEY_UNKNOWN         , /* 0x0019 */
    KEY_UNKNOWN         , /* 0x001a */
    KEY_UNKNOWN         , /* 0x001b */
    KEY_UNKNOWN         , /* 0x001c */
    KEY_UNKNOWN         , /* 0x001d */
    KEY_UNKNOWN         , /* 0x001e */
    KEY_UNKNOWN         , /* 0x001f */
    KEY_UNKNOWN         , /* 0x0020: HID_CONSUMER_PLUS_10  */
    KEY_UNKNOWN         , /* 0x0021: HID_CONSUMER_PLUS_100 */
    KEY_UNKNOWN         , /* 0x0022: HID_CONSUMER_AM_PM    */
    KEY_UNKNOWN         , /* 0x0023 */
    KEY_UNKNOWN         , /* 0x0024 */
    KEY_UNKNOWN         , /* 0x0025 */
    KEY_UNKNOWN         , /* 0x0026 */
    KEY_UNKNOWN         , /* 0x0027 */
    KEY_UNKNOWN         , /* 0x0028 */
    KEY_UNKNOWN         , /* 0x0029 */
    KEY_UNKNOWN         , /* 0x002a */
    KEY_UNKNOWN         , /* 0x002b */
    KEY_UNKNOWN         , /* 0x002c */
    KEY_UNKNOWN         , /* 0x002d */
    KEY_UNKNOWN         , /* 0x002e */
    KEY_UNKNOWN         , /* 0x002f */
    KEY_POWER           , /* 0x0030: HID_CONSUMER_Power            */
    KEY_RESTART         , /* 0x0031: HID_CONSUMER_RESET            */
    KEY_SLEEP           , /* 0x0032: HID_CONSUMER_SLEEP            */
    KEY_UNKNOWN         , /* 0x0033: HID_CONSUMER_SLEEP_AFTER      */
    KEY_SLEEP           , /* 0x0034: HID_CONSUMER_SLEEP_MODE       */
    KEY_KBDILLUMTOGGLE  , /* 0x0035: HID_CONSUMER_ILLUMINATION     */
    BTN_0               , /* 0x0036: HID_CONSUMER_FUNCTION_BUTTONS */
    KEY_UNKNOWN         , /* 0x0037 */
    KEY_UNKNOWN         , /* 0x0038 */
    KEY_UNKNOWN         , /* 0x0039 */
    KEY_UNKNOWN         , /* 0x003a */
    KEY_UNKNOWN         , /* 0x003b */
    KEY_UNKNOWN         , /* 0x003c */
    KEY_UNKNOWN         , /* 0x003d */
    KEY_UNKNOWN         , /* 0x003e */
    KEY_UNKNOWN         , /* 0x003f */
    KEY_MENU            , /* 0x0040: HID_CONSUMER_MENU                */
    KEY_SELECT          , /* 0x0040: HID_CONSUMER_MENU_PICK           */
    KEY_UP              , /* 0x0040: HID_CONSUMER_MENU_UP             */
    KEY_DOWN            , /* 0x0040: HID_CONSUMER_MENU_DOWN           */
    KEY_LEFT            , /* 0x0040: HID_CONSUMER_MENU_LEFT           */
    KEY_RIGHT           , /* 0x0040: HID_CONSUMER_MENU_RIGHT          */
    KEY_ESC             , /* 0x0040: HID_CONSUMER_MENU_ESCAPE         */
    KEY_KPPLUS          , /* 0x0040: HID_CONSUMER_MENU_VALUE_INCREASE */
    KEY_KPMINUS         , /* 0x0040: HID_CONSUMER_MENU_VALUE_DECREASE */
    KEY_UNKNOWN         , /* 0x0049 */
    KEY_UNKNOWN         , /* 0x004a */
    KEY_UNKNOWN         , /* 0x004b */
    KEY_UNKNOWN         , /* 0x004c */
    KEY_UNKNOWN         , /* 0x004d */
    KEY_UNKNOWN         , /* 0x004e */
    KEY_UNKNOWN         , /* 0x004f */
    KEY_UNKNOWN         , /* 0x0050 */
    KEY_UNKNOWN         , /* 0x0051 */
    KEY_UNKNOWN         , /* 0x0052 */
    KEY_UNKNOWN         , /* 0x0053 */
    KEY_UNKNOWN         , /* 0x0054 */
    KEY_UNKNOWN         , /* 0x0055 */
    KEY_UNKNOWN         , /* 0x0056 */
    KEY_UNKNOWN         , /* 0x0057 */
    KEY_UNKNOWN         , /* 0x0058 */
    KEY_UNKNOWN         , /* 0x0059 */
    KEY_UNKNOWN         , /* 0x005a */
    KEY_UNKNOWN         , /* 0x005b */
    KEY_UNKNOWN         , /* 0x005c */
    KEY_UNKNOWN         , /* 0x005d */
    KEY_UNKNOWN         , /* 0x005e */
    KEY_UNKNOWN         , /* 0x005f */
    KEY_INFO            , /* 0x0060: HID_CONSUMER_DATA_ON_SCREEN        */
    KEY_SUBTITLE        , /* 0x0061: HID_CONSUMER_CLOSED_CAPTION        */
    KEY_UNKNOWN         , /* 0x0062: HID_CONSUMER_CLOSED_CAPTION_SELECT */
    KEY_VCR             , /* 0x0063: HID_CONSUMER_VCR_TV                */
    KEY_UNKNOWN         , /* 0x0064: HID_CONSUMER_BROADCAST_MODE        */
    KEY_CAMERA          , /* 0x0065: HID_CONSUMER_SNAPSHOT              */
    KEY_UNKNOWN         , /* 0x0066: HID_CONSUMER_STILL                 */
    KEY_UNKNOWN         , /* 0x0067 */
    KEY_UNKNOWN         , /* 0x0068 */
    KEY_RED             , /* 0x0069 */
    KEY_GREEN           , /* 0x006a */
    KEY_BLUE            , /* 0x006b */
    KEY_YELLOW          , /* 0x006c */
    KEY_SCREEN          , /* 0x006d */
    KEY_UNKNOWN         , /* 0x006e */
    KEY_BRIGHTNESSUP    , /* 0x006f */
    KEY_BRIGHTNESSDOWN  , /* 0x0070 */
    KEY_UNKNOWN         , /* 0x0071 */
    KEY_DISPLAYTOGGLE   , /* 0x0072 */
    KEY_BRIGHTNESS_MIN  , /* 0x0073 */
    KEY_BRIGHTNESS_MAX  , /* 0x0074 */
    KEY_BRIGHTNESS_ZERO , /* 0x0075 */
    KEY_UNKNOWN         , /* 0x0076 */
    KEY_UNKNOWN         , /* 0x0077 */
    KEY_UNKNOWN         , /* 0x0078 */
    KEY_KBDILLUMUP      , /* 0x0079 */
    KEY_KBDILLUMDOWN    , /* 0x007a */
    KEY_UNKNOWN         , /* 0x007b */
    KEY_KBDILLUMTOGGLE  , /* 0x007c */
    KEY_UNKNOWN         , /* 0x007d */
    KEY_UNKNOWN         , /* 0x007e */
    KEY_UNKNOWN         , /* 0x007f */
    KEY_UNKNOWN         , /* 0x0080: HID_CONSUMER_SELECTION */
    KEY_UNKNOWN         , /* 0x0081: HID_CONSUMER_ASSIGN_SELECTION */
    KEY_VIDEO_NEXT      , /* 0x0082: HID_CONSUMER_MODE_STEP */
    KEY_LAST            , /* 0x0083: HID_CONSUMER_RECALL_LAST */
    KEY_ENTER           , /* 0x0084: HID_CONSUMER_ENTER_CHANNEL */
    KEY_UNKNOWN         , /* 0x0085: HID_CONSUMER_ORDER_MOVIE */
    KEY_UNKNOWN         , /* 0x0086: HID_CONSUMER_CHANNEL */
    KEY_UNKNOWN         , /* 0x0087: HID_CONSUMER_MEDIA_SELECTION */
    KEY_PC              , /* 0x0088: HID_CONSUMER_MEDIA_SELECT_COMPUTER */
    KEY_TV              , /* 0x0089: HID_CONSUMER_MEDIA_SELECT_TV */
    KEY_WWW             , /* 0x008a: HID_CONSUMER_MEDIA_SELECT_WWW */
    KEY_DVD             , /* 0x008b: HID_CONSUMER_MEDIA_SELECT_DVD */
    KEY_PHONE           , /* 0x008c: HID_CONSUMER_MEDIA_SELECT_TELEPHONE */
    KEY_PROGRAM         , /* 0x008d: HID_CONSUMER_MEDIA_SELECT_PROGRAM_GUIDE */
    KEY_VIDEOPHONE      , /* 0x008e: HID_CONSUMER_MEDIA_SELECT_VIDEO_PHONE */
    KEY_GAMES           , /* 0x008f: HID_CONSUMER_MEDIA_SELECT_GAMES */
    KEY_MEMO            , /* 0x0090: HID_CONSUMER_MEDIA_SELECT_MESSAGES */
    KEY_CD              , /* 0x0091: HID_CONSUMER_MEDIA_SELECT_CD */
    KEY_VCR             , /* 0x0092: HID_CONSUMER_MEDIA_SELECT_VCR */
    KEY_TUNER           , /* 0x0093: HID_CONSUMER_MEDIA_SELECT_TUNER */
    KEY_EXIT            , /* 0x0094: HID_CONSUMER_QUIT */
    KEY_HELP            , /* 0x0095: HID_CONSUMER_HELP */
    KEY_TAPE            , /* 0x0096: HID_CONSUMER_MEDIA_SELECT_TAPE */
    KEY_TV2             , /* 0x0097: HID_CONSUMER_MEDIA_SELECT_CABLE */
    KEY_SAT             , /* 0x0098: HID_CONSUMER_MEDIA_SELECT_SATELLITE */
    KEY_UNKNOWN         , /* 0x0099: HID_CONSUMER_MEDIA_SELECT_SECURITY */
    KEY_PVR             , /* 0x009a: HID_CONSUMER_MEDIA_SELECT_HOME */
    KEY_UNKNOWN         , /* 0x009b: HID_CONSUMER_MEDIA_SELECT_CALL */
    KEY_CHANNELUP       , /* 0x009c: HID_CONSUMER_CHANNEL_INCREMENT */
    KEY_CHANNELDOWN     , /* 0x009d: HID_CONSUMER_CHANNEL_DECREMENT */
    KEY_UNKNOWN         , /* 0x009e: HID_CONSUMER_MEDIA_SELECT_SAP */
    KEY_UNKNOWN         , /* 0x009f */
    KEY_VCR2            , /* 0x00a0: HID_CONSUMER_VCR_PLUS */
    KEY_UNKNOWN         , /* 0x00a1: HID_CONSUMER_ONCE */
    KEY_UNKNOWN         , /* 0x00a2: HID_CONSUMER_DAILY */
    KEY_UNKNOWN         , /* 0x00a3: HID_CONSUMER_WEEKLY */
    KEY_UNKNOWN         , /* 0x00a4: HID_CONSUMER_MONTHLY */
    KEY_UNKNOWN         , /* 0x00a5 */
    KEY_UNKNOWN         , /* 0x00a6 */
    KEY_UNKNOWN         , /* 0x00a7 */
    KEY_UNKNOWN         , /* 0x00a8 */
    KEY_UNKNOWN         , /* 0x00a9 */
    KEY_UNKNOWN         , /* 0x00aa */
    KEY_UNKNOWN         , /* 0x00ab */
    KEY_UNKNOWN         , /* 0x00ac */
    KEY_UNKNOWN         , /* 0x00ad */
    KEY_UNKNOWN         , /* 0x00ae */
    KEY_UNKNOWN         , /* 0x00af */
    KEY_PLAY            , /* 0x00b0: HID_CONSUMER_PLAY */
    KEY_PAUSE           , /* 0x00b1: HID_CONSUMER_PAUSE */
    KEY_RECORD          , /* 0x00b2: HID_CONSUMER_RECORD */
    KEY_FASTFORWARD     , /* 0x00b3: HID_CONSUMER_FAST_FORWARD */
    KEY_REWIND          , /* 0x00b4: HID_CONSUMER_REWIND */
    KEY_NEXTSONG        , /* 0x00b5: HID_CONSUMER_SCAN_NEXT_TRACK */
    KEY_PREVIOUSSONG    , /* 0x00b6: HID_CONSUMER_SCAN_PREVIOUS_TRACK */
    KEY_STOPCD          , /* 0x00b7: HID_CONSUMER_STOP */
    KEY_EJECTCD         , /* 0x00b8: HID_CONSUMER_EJECT */
    KEY_SHUFFLE         , /* 0x00b9: HID_CONSUMER_RANDOM_PLAY */
    KEY_UNKNOWN         , /* 0x00ba: HID_CONSUMER_SELECT_DISC */
    KEY_UNKNOWN         , /* 0x00bb: HID_CONSUMER_ENTER_DISC */
    KEY_MEDIA_REPEAT    , /* 0x00bc: HID_CONSUMER_REPEAT */
    KEY_UNKNOWN         , /* 0x00bd: HID_CONSUMER_TRACKING */
    KEY_UNKNOWN         , /* 0x00be: HID_CONSUMER_TRACK_NORMAL */
    KEY_SLOW            , /* 0x00bf: HID_CONSUMER_SLOW_TRACKING */
    KEY_UNKNOWN         , /* 0x00c0: HID_CONSUMER_FRAME_FORWARD */
    KEY_UNKNOWN         , /* 0x00c1: HID_CONSUMER_FRAME_BACK */
    KEY_UNKNOWN         , /* 0x00c2: HID_CONSUMER_MARK */
    KEY_UNKNOWN         , /* 0x00c3: HID_CONSUMER_CLEAR_MARK */
    KEY_UNKNOWN         , /* 0x00c4: HID_CONSUMER_REPEAT_FROM_MARK */
    KEY_UNKNOWN         , /* 0x00c5: HID_CONSUMER_RETURN_TO_MARK */
    KEY_UNKNOWN         , /* 0x00c6: HID_CONSUMER_SEARCH_MARK_FORWARD */
    KEY_UNKNOWN         , /* 0x00c7: HID_CONSUMER_SEARCH_MARK_BACKWARDS */
    KEY_UNKNOWN         , /* 0x00c8: HID_CONSUMER_COUNTER_RESET */
    KEY_UNKNOWN         , /* 0x00c9: HID_CONSUMER_SHOW_COUNTER */
    KEY_UNKNOWN         , /* 0x00ca: HID_CONSUMER_TRACKING_INCREMENT */
    KEY_UNKNOWN         , /* 0x00cb: HID_CONSUMER_TRACKING_DECREMENT */
    KEY_UNKNOWN         , /* 0x00cc: HID_CONSUMER_STOP_EJECT */
    KEY_PLAYPAUSE       , /* 0x00cd: HID_CONSUMER_PLAY_PAUSE */
    KEY_UNKNOWN         , /* 0x00ce: HID_CONSUMER_PLAY_SKIP */
    KEY_VOICECOMMAND    , /* 0x00cf */
    KEY_UNKNOWN         , /* 0x00d0 */
    KEY_UNKNOWN         , /* 0x00d1 */
    KEY_UNKNOWN         , /* 0x00d2 */
    KEY_UNKNOWN         , /* 0x00d3 */
    KEY_UNKNOWN         , /* 0x00d4 */
    KEY_UNKNOWN         , /* 0x00d5 */
    KEY_UNKNOWN         , /* 0x00d6 */
    KEY_UNKNOWN         , /* 0x00d7 */
    KEY_UNKNOWN         , /* 0x00d8 */
    KEY_UNKNOWN         , /* 0x00d9 */
    KEY_UNKNOWN         , /* 0x00da */
    KEY_UNKNOWN         , /* 0x00db */
    KEY_UNKNOWN         , /* 0x00dc */
    KEY_UNKNOWN         , /* 0x00dd */
    KEY_UNKNOWN         , /* 0x00de */
    KEY_UNKNOWN         , /* 0x00df */
    ABS_VOLUME          , /* 0x00e0: HID_CONSUMER_VOLUME */
    KEY_UNKNOWN         , /* 0x00e1: HID_CONSUMER_BALANCE */
    KEY_MUTE            , /* 0x00e2: HID_CONSUMER_MUTE */
    KEY_UNKNOWN         , /* 0x00e3: HID_CONSUMER_BASS */
    KEY_UNKNOWN         , /* 0x00e4: HID_CONSUMER_TREBLE */
    KEY_BASSBOOST       , /* 0x00e5: HID_CONSUMER_BASS_BOOST */
    KEY_UNKNOWN         , /* 0x00e6: HID_CONSUMER_SURROUND_MODE */
    KEY_UNKNOWN         , /* 0x00e7: HID_CONSUMER_LOUDNESS */
    KEY_UNKNOWN         , /* 0x00e8: HID_CONSUMER_MPX */
    KEY_VOLUMEUP        , /* 0x00e9: HID_CONSUMER_VOLUME_INCREMENT */
    KEY_VOLUMEDOWN      , /* 0x00ea: HID_CONSUMER_VOLUME_DECREMENT */
    KEY_UNKNOWN         , /* 0x00eb */
    KEY_UNKNOWN         , /* 0x00ec */
    KEY_UNKNOWN         , /* 0x00ed */
    KEY_UNKNOWN         , /* 0x00ee */
    KEY_UNKNOWN         , /* 0x00ef */
    KEY_UNKNOWN         , /* 0x00f0: HID_CONSUMER_SPEED_SELECT */
    KEY_UNKNOWN         , /* 0x00f1: HID_CONSUMER_PLAYBACK_SPEED */
    KEY_UNKNOWN         , /* 0x00f2: HID_CONSUMER_STANDARD_PLAY */
    KEY_UNKNOWN         , /* 0x00f3: HID_CONSUMER_LONG_PLAY */
    KEY_UNKNOWN         , /* 0x00f4: HID_CONSUMER_EXTENDED_PLAY */
    KEY_SLOW            , /* 0x00f5: HID_CONSUMER_SLOW */
    KEY_UNKNOWN         , /* 0x00f6 */
    KEY_UNKNOWN         , /* 0x00f7 */
    KEY_UNKNOWN         , /* 0x00f8 */
    KEY_UNKNOWN         , /* 0x00f9 */
    KEY_UNKNOWN         , /* 0x00fa */
    KEY_UNKNOWN         , /* 0x00fb */
    KEY_UNKNOWN         , /* 0x00fc */
    KEY_UNKNOWN         , /* 0x00fd */
    KEY_UNKNOWN         , /* 0x00fe */
    KEY_UNKNOWN         , /* 0x00ff */
    KEY_UNKNOWN         , /* 0x0100: HID_CONSUMER_FAN_ENABLE */
    KEY_UNKNOWN         , /* 0x0101: HID_CONSUMER_FAN_SPEED */
    KEY_UNKNOWN         , /* 0x0102: HID_CONSUMER_LIGHT_ENABLE */
    KEY_UNKNOWN         , /* 0x0103: HID_CONSUMER_LIGHT_ILLUMINATION_LEVEL */
    KEY_UNKNOWN         , /* 0x0104: HID_CONSUMER_CLIMATE_CONTROL_ENABLE */
    KEY_UNKNOWN         , /* 0x0105: HID_CONSUMER_ROOM_TEMPERATURE */
    KEY_UNKNOWN         , /* 0x0106: HID_CONSUMER_SECURITY_ENABLE */
    KEY_UNKNOWN         , /* 0x0107: HID_CONSUMER_FIRE_ALARM */
    KEY_UNKNOWN         , /* 0x0108: HID_CONSUMER_POLICE_ALARM */
    KEY_UNKNOWN         , /* 0x0109: HID_CONSUMER_PROXIMITY */
    KEY_UNKNOWN         , /* 0x010a: HID_CONSUMER_MOTION */
    KEY_UNKNOWN         , /* 0x010b: HID_CONSUMER_DURESS_ALARM */
    KEY_UNKNOWN         , /* 0x010c: HID_CONSUMER_HOLDUP_ALARM */
    KEY_UNKNOWN         , /* 0x010d: HID_CONSUMER_MEDICAL_ALARM */
    KEY_UNKNOWN         , /* 0x010e */
    KEY_UNKNOWN         , /* 0x010f */
    KEY_UNKNOWN         , /* 0x0110 */
    KEY_UNKNOWN         , /* 0x0111 */
    KEY_UNKNOWN         , /* 0x0112 */
    KEY_UNKNOWN         , /* 0x0113 */
    KEY_UNKNOWN         , /* 0x0114 */
    KEY_UNKNOWN         , /* 0x0115 */
    KEY_UNKNOWN         , /* 0x0116 */
    KEY_UNKNOWN         , /* 0x0117 */
    KEY_UNKNOWN         , /* 0x0118 */
    KEY_UNKNOWN         , /* 0x0119 */
    KEY_UNKNOWN         , /* 0x011a */
    KEY_UNKNOWN         , /* 0x011b */
    KEY_UNKNOWN         , /* 0x011c */
    KEY_UNKNOWN         , /* 0x011d */
    KEY_UNKNOWN         , /* 0x011e */
    KEY_UNKNOWN         , /* 0x011f */
    KEY_UNKNOWN         , /* 0x0120 */
    KEY_UNKNOWN         , /* 0x0121 */
    KEY_UNKNOWN         , /* 0x0122 */
    KEY_UNKNOWN         , /* 0x0123 */
    KEY_UNKNOWN         , /* 0x0124 */
    KEY_UNKNOWN         , /* 0x0125 */
    KEY_UNKNOWN         , /* 0x0126 */
    KEY_UNKNOWN         , /* 0x0127 */
    KEY_UNKNOWN         , /* 0x0128 */
    KEY_UNKNOWN         , /* 0x0129 */
    KEY_UNKNOWN         , /* 0x012a */
    KEY_UNKNOWN         , /* 0x012b */
    KEY_UNKNOWN         , /* 0x012c */
    KEY_UNKNOWN         , /* 0x012d */
    KEY_UNKNOWN         , /* 0x012e */
    KEY_UNKNOWN         , /* 0x012f */
    KEY_UNKNOWN         , /* 0x0130 */
    KEY_UNKNOWN         , /* 0x0131 */
    KEY_UNKNOWN         , /* 0x0132 */
    KEY_UNKNOWN         , /* 0x0133 */
    KEY_UNKNOWN         , /* 0x0134 */
    KEY_UNKNOWN         , /* 0x0135 */
    KEY_UNKNOWN         , /* 0x0136 */
    KEY_UNKNOWN         , /* 0x0137 */
    KEY_UNKNOWN         , /* 0x0138 */
    KEY_UNKNOWN         , /* 0x0139 */
    KEY_UNKNOWN         , /* 0x013a */
    KEY_UNKNOWN         , /* 0x013b */
    KEY_UNKNOWN         , /* 0x013c */
    KEY_UNKNOWN         , /* 0x013d */
    KEY_UNKNOWN         , /* 0x013e */
    KEY_UNKNOWN         , /* 0x013f */
    KEY_UNKNOWN         , /* 0x0140 */
    KEY_UNKNOWN         , /* 0x0141 */
    KEY_UNKNOWN         , /* 0x0142 */
    KEY_UNKNOWN         , /* 0x0143 */
    KEY_UNKNOWN         , /* 0x0144 */
    KEY_UNKNOWN         , /* 0x0145 */
    KEY_UNKNOWN         , /* 0x0146 */
    KEY_UNKNOWN         , /* 0x0147 */
    KEY_UNKNOWN         , /* 0x0148 */
    KEY_UNKNOWN         , /* 0x0149 */
    KEY_UNKNOWN         , /* 0x014a */
    KEY_UNKNOWN         , /* 0x014b */
    KEY_UNKNOWN         , /* 0x014c */
    KEY_UNKNOWN         , /* 0x014d */
    KEY_UNKNOWN         , /* 0x014e */
    KEY_UNKNOWN         , /* 0x014f */
    KEY_UNKNOWN         , /* 0x0150: HID_CONSUMER_BALANCE_RIGHT */
    KEY_UNKNOWN         , /* 0x0151: HID_CONSUMER_BALANCE_LEFT */
    KEY_UNKNOWN         , /* 0x0152: HID_CONSUMER_BASS_INCREMENT */
    KEY_UNKNOWN         , /* 0x0153: HID_CONSUMER_BASS_DECREMENT */
    KEY_UNKNOWN         , /* 0x0154: HID_CONSUMER_TREBLE_INCREMENT */
    KEY_UNKNOWN         , /* 0x0155: HID_CONSUMER_TREBLE_DECREMENT */
    KEY_UNKNOWN         , /* 0x0156 */
    KEY_UNKNOWN         , /* 0x0157 */
    KEY_UNKNOWN         , /* 0x0158 */
    KEY_UNKNOWN         , /* 0x0159 */
    KEY_UNKNOWN         , /* 0x015a */
    KEY_UNKNOWN         , /* 0x015b */
    KEY_UNKNOWN         , /* 0x015c */
    KEY_UNKNOWN         , /* 0x015d */
    KEY_UNKNOWN         , /* 0x015e */
    KEY_UNKNOWN         , /* 0x015f */
    KEY_UNKNOWN         , /* 0x0160: HID_CONSUMER_SPEAKER_SYSTEM */
    KEY_UNKNOWN         , /* 0x0161: HID_CONSUMER_CHANNEL_LEFT */
    KEY_UNKNOWN         , /* 0x0162: HID_CONSUMER_CHANNEL_RIGHT */
    KEY_UNKNOWN         , /* 0x0163: HID_CONSUMER_CHANNEL_CENTER */
    KEY_UNKNOWN         , /* 0x0164: HID_CONSUMER_CHANNEL_FRONT */
    KEY_UNKNOWN         , /* 0x0165: HID_CONSUMER_CHANNEL_CENTER_FRONT */
    KEY_UNKNOWN         , /* 0x0166: HID_CONSUMER_CHANNEL_SIDE */
    KEY_UNKNOWN         , /* 0x0167: HID_CONSUMER_CHANNEL_SURROUND */
    KEY_UNKNOWN         , /* 0x0168: HID_CONSUMER_CHANNEL_LOW_FREQUENCY_ENHANCEMENT */
    KEY_UNKNOWN         , /* 0x0169: HID_CONSUMER_CHANNEL_TOP */
    KEY_UNKNOWN         , /* 0x016a: HID_CONSUMER_CHANNEL_UNKNOWN */
    KEY_UNKNOWN         , /* 0x016b */
    KEY_UNKNOWN         , /* 0x016c */
    KEY_UNKNOWN         , /* 0x016d */
    KEY_UNKNOWN         , /* 0x016e */
    KEY_UNKNOWN         , /* 0x016f */
    KEY_UNKNOWN         , /* 0x0170: HID_CONSUMER_SUB_CHANNEL */
    KEY_UNKNOWN         , /* 0x0171: HID_CONSUMER_SUB_CHANNEL_INCREMENT */
    KEY_UNKNOWN         , /* 0x0172: HID_CONSUMER_SUB_CHANNEL_DECREMENT */
    KEY_UNKNOWN         , /* 0x0173: HID_CONSUMER_ALTERNATE_AUDIO_INCREMENT */
    KEY_UNKNOWN         , /* 0x0174: HID_CONSUMER_ALTERNATE_AUDIO_DECREMENT */
    KEY_UNKNOWN         , /* 0x0175 */
    KEY_UNKNOWN         , /* 0x0176 */
    KEY_UNKNOWN         , /* 0x0177 */
    KEY_UNKNOWN         , /* 0x0178 */
    KEY_UNKNOWN         , /* 0x0179 */
    KEY_UNKNOWN         , /* 0x017a */
    KEY_UNKNOWN         , /* 0x017b */
    KEY_UNKNOWN         , /* 0x017c */
    KEY_UNKNOWN         , /* 0x017d */
    KEY_UNKNOWN         , /* 0x017e */
    KEY_UNKNOWN         , /* 0x017f */
    KEY_UNKNOWN         , /* 0x0180: HID_CONSUMER_APPLICATION_LAUNCH_BUTTONS */
    KEY_BUTTONCONFIG    , /* 0x0181: HID_CONSUMER_AL_LAUNCH_BUTTON_CONFIGURATION_TOOL */
    KEY_BOOKMARKS       , /* 0x0182: HID_CONSUMER_AL_PROGRAMMABLE_BUTTON_CONFIGURATION */
    KEY_CONFIG          , /* 0x0183: HID_CONSUMER_AL_CONSUMER_CONTROL_CONFIGURATION */
    KEY_WORDPROCESSOR   , /* 0x0184: HID_CONSUMER_AL_WORD_PROCESSOR */
    KEY_EDITOR          , /* 0x0185: HID_CONSUMER_AL_TEXT_EDITOR */
    KEY_SPREADSHEET     , /* 0x0186: HID_CONSUMER_AL_SPREADSHEET */
    KEY_GRAPHICSEDITOR  , /* 0x0187: HID_CONSUMER_AL_GRAPHICS_EDITOR */
    KEY_PRESENTATION    , /* 0x0188: HID_CONSUMER_AL_PRESENTATION_APP */
    KEY_DATABASE        , /* 0x0189: HID_CONSUMER_AL_DATABASE_APP */
    KEY_MAIL            , /* 0x018a: HID_CONSUMER_AL_EMAIL_READER */
    KEY_NEWS            , /* 0x018b: HID_CONSUMER_AL_NEWSREADER */
    KEY_VOICEMAIL       , /* 0x018c: HID_CONSUMER_AL_VOICEMAIL */
    KEY_ADDRESSBOOK     , /* 0x018d: HID_CONSUMER_AL_CONTACTS_ADDRESS_BOOK */
    KEY_CALENDAR        , /* 0x018e: HID_CONSUMER_AL_CALENDAR_SCHEDULE */
    KEY_TASKMANAGER     , /* 0x018f: HID_CONSUMER_AL_TASK_PROJECT_MANAGER */
    KEY_JOURNAL         , /* 0x0190: HID_CONSUMER_AL_LOG_JOURNAL_TIMECARD */
    KEY_FINANCE         , /* 0x0191: HID_CONSUMER_AL_CHECKBOOK_FINANCE */
    KEY_CALC            , /* 0x0192: HID_CONSUMER_AL_CALCULATOR */
    KEY_PLAYER          , /* 0x0193: HID_CONSUMER_AL_A_V_CAPTURE_PLAYBACK */
    KEY_FILE            , /* 0x0194: HID_CONSUMER_AL_LOCAL_MACHINE_BROWSER */
    KEY_UNKNOWN         , /* 0x0195: HID_CONSUMER_AL_LAN_WAN_BROWSER */
    KEY_WWW             , /* 0x0196: HID_CONSUMER_AL_INTERNET_BROWSER */
    KEY_UNKNOWN         , /* 0x0197: HID_CONSUMER_AL_REMOTE_NETWORKING_ISP_CONNECT */
    KEY_UNKNOWN         , /* 0x0198: HID_CONSUMER_AL_NETWORK_CONFERENCE */
    KEY_CHAT            , /* 0x0199: HID_CONSUMER_AL_NETWORK_CHAT */
    KEY_UNKNOWN         , /* 0x019a: HID_CONSUMER_AL_TELEPHONY_DIALER */
    KEY_UNKNOWN         , /* 0x019b: HID_CONSUMER_AL_LOGON */
    KEY_LOGOFF          , /* 0x019c: HID_CONSUMER_AL_LOGOFF */
    KEY_UNKNOWN         , /* 0x019d: HID_CONSUMER_AL_LOGON_LOGOFF */
    KEY_SCREENLOCK      , /* 0x019e: HID_CONSUMER_AL_TERMINAL_LOCK_SCREENSAVER */
    KEY_CONTROLPANEL    , /* 0x019f: HID_CONSUMER_AL_CONTROL_PANEL */
    KEY_UNKNOWN         , /* 0x01a0: HID_CONSUMER_AL_COMMAND_LINE_PROCESSOR_RUN */
    KEY_UNKNOWN         , /* 0x01a1: HID_CONSUMER_AL_PROCESS_TASK_MANAGER */
    KEY_APPSELECT       , /* 0x01a2: HID_CONSUMER_AL_SELECT_TASK_APPLICATION */
    KEY_NEXT            , /* 0x01a3: HID_CONSUMER_AL_NEXT_TASK_APPLICATION */
    KEY_PREVIOUS        , /* 0x01a4: HID_CONSUMER_AL_PREVIOUS_TASK_APPLICATION */
    KEY_UNKNOWN         , /* 0x01a5: HID_CONSUMER_AL_PREEMPTIVE_HALT_TASK_APPLICATION */
    KEY_HELP            , /* 0x01a6: HID_CONSUMER_AL_INTEGRATED_HELP_CENTER */
    KEY_DOCUMENTS       , /* 0x01a7: HID_CONSUMER_AL_DOCUMENTS */
    KEY_UNKNOWN         , /* 0x01a8: HID_CONSUMER_AL_THESAURUS */
    KEY_UNKNOWN         , /* 0x01a9: HID_CONSUMER_AL_DICTIONARY */
    KEY_UNKNOWN         , /* 0x01aa: HID_CONSUMER_AL_DESKTOP */
    KEY_SPELLCHECK      , /* 0x01ab: HID_CONSUMER_AL_SPELL_CHECK */
    KEY_UNKNOWN         , /* 0x01ac: HID_CONSUMER_AL_GRAMMAR_CHECK */
    KEY_UNKNOWN         , /* 0x01ad: HID_CONSUMER_AL_WIRELESS_STATUS */
    KEY_KEYBOARD        , /* 0x01ae: HID_CONSUMER_AL_KEYBOARD_LAYOUT */
    KEY_UNKNOWN         , /* 0x01af: HID_CONSUMER_AL_VIRUS_PROTECTION */
    KEY_UNKNOWN         , /* 0x01b0: HID_CONSUMER_AL_ENCRYPTION */
    KEY_SCREENSAVER     , /* 0x01b1: HID_CONSUMER_AL_SCREEN_SAVER */
    KEY_UNKNOWN         , /* 0x01b2: HID_CONSUMER_AL_ALARMS */
    KEY_UNKNOWN         , /* 0x01b3: HID_CONSUMER_AL_CLOCK */
    KEY_FILE            , /* 0x01b4: HID_CONSUMER_AL_FILE_BROWSER */
    KEY_UNKNOWN         , /* 0x01b5: HID_CONSUMER_AL_POWER_STATUS */
    KEY_IMAGES          , /* 0x01b6: HID_CONSUMER_AL_IMAGE_BROWSER */
    KEY_AUDIO           , /* 0x01b7: HID_CONSUMER_AL_AUDIO_BROWSER */
    KEY_VIDEO           , /* 0x01b8: HID_CONSUMER_AL_MOVIE_BROWSER */
    KEY_UNKNOWN         , /* 0x01b9: HID_CONSUMER_AL_DIGITAL_RIGHTS_MANAGER */
    KEY_UNKNOWN         , /* 0x01ba: HID_CONSUMER_AL_DIGITAL_WALLET */
    KEY_UNKNOWN         , /* 0x01bb */
    KEY_MESSENGER       , /* 0x01bc: HID_CONSUMER_AL_INSTANT_MESSAGING */
    KEY_INFO            , /* 0x01bd: HID_CONSUMER_AL_OEM_FEATURES_BROWSER */
    KEY_UNKNOWN         , /* 0x01be: HID_CONSUMER_AL_OEM_HELP */
    KEY_UNKNOWN         , /* 0x01bf: HID_CONSUMER_AL_ONLINE_COMMUNITY */
    KEY_UNKNOWN         , /* 0x01c0: HID_CONSUMER_AL_ENTERTAINMENT_CONTENT_BROWSER */
    KEY_UNKNOWN         , /* 0x01c1: HID_CONSUMER_AL_ONLINE_SHOPPING_BROWSER */
    KEY_UNKNOWN         , /* 0x01c2: HID_CONSUMER_AL_SMARTCARD_INFORMATION_HELP */
    KEY_UNKNOWN         , /* 0x01c3: HID_CONSUMER_AL_MARKET_MONITOR_FINANCE_BROWSER */
    KEY_UNKNOWN         , /* 0x01c4: HID_CONSUMER_AL_CUSTOMIZED_CORPORATE_NEWS_BROWSER */
    KEY_UNKNOWN         , /* 0x01c5: HID_CONSUMER_AL_ONLINE_ACTIVITY_BROWSER */
    KEY_UNKNOWN         , /* 0x01c6: HID_CONSUMER_AL_RESEARCH_SEARCH_BROWSER */
    KEY_UNKNOWN         , /* 0x01c7: HID_CONSUMER_AL_AUDIO_PLAYER */
    KEY_UNKNOWN         , /* 0x01c8 */
    KEY_UNKNOWN         , /* 0x01c9 */
    KEY_UNKNOWN         , /* 0x01ca */
    KEY_ASSISTANT       , /* 0x01cb code 583 ? */
    KEY_UNKNOWN         , /* 0x01cc */
    KEY_UNKNOWN         , /* 0x01cd */
    KEY_UNKNOWN         , /* 0x01ce */
    KEY_UNKNOWN         , /* 0x01cf */
    KEY_UNKNOWN         , /* 0x01d0 */
    KEY_UNKNOWN         , /* 0x01d1 */
    KEY_UNKNOWN         , /* 0x01d2 */
    KEY_UNKNOWN         , /* 0x01d3 */
    KEY_UNKNOWN         , /* 0x01d4 */
    KEY_UNKNOWN         , /* 0x01d5 */
    KEY_UNKNOWN         , /* 0x01d6 */
    KEY_UNKNOWN         , /* 0x01d7 */
    KEY_UNKNOWN         , /* 0x01d8 */
    KEY_UNKNOWN         , /* 0x01d9 */
    KEY_UNKNOWN         , /* 0x01da */
    KEY_UNKNOWN         , /* 0x01db */
    KEY_UNKNOWN         , /* 0x01dc */
    KEY_UNKNOWN         , /* 0x01dd */
    KEY_UNKNOWN         , /* 0x01de */
    KEY_UNKNOWN         , /* 0x01df */
    KEY_UNKNOWN         , /* 0x01e0 */
    KEY_UNKNOWN         , /* 0x01e1 */
    KEY_UNKNOWN         , /* 0x01e2 */
    KEY_UNKNOWN         , /* 0x01e3 */
    KEY_UNKNOWN         , /* 0x01e4 */
    KEY_UNKNOWN         , /* 0x01e5 */
    KEY_UNKNOWN         , /* 0x01e6 */
    KEY_UNKNOWN         , /* 0x01e7 */
    KEY_UNKNOWN         , /* 0x01e8 */
    KEY_UNKNOWN         , /* 0x01e9 */
    KEY_UNKNOWN         , /* 0x01ea */
    KEY_UNKNOWN         , /* 0x01eb */
    KEY_UNKNOWN         , /* 0x01ec */
    KEY_UNKNOWN         , /* 0x01ed */
    KEY_UNKNOWN         , /* 0x01ee */
    KEY_UNKNOWN         , /* 0x01ef */
    KEY_UNKNOWN         , /* 0x01f0 */
    KEY_UNKNOWN         , /* 0x01f1 */
    KEY_UNKNOWN         , /* 0x01f2 */
    KEY_UNKNOWN         , /* 0x01f3 */
    KEY_UNKNOWN         , /* 0x01f4 */
    KEY_UNKNOWN         , /* 0x01f5 */
    KEY_UNKNOWN         , /* 0x01f6 */
    KEY_UNKNOWN         , /* 0x01f7 */
    KEY_UNKNOWN         , /* 0x01f8 */
    KEY_UNKNOWN         , /* 0x01f9 */
    KEY_UNKNOWN         , /* 0x01fa */
    KEY_UNKNOWN         , /* 0x01fb */
    KEY_UNKNOWN         , /* 0x01fc */
    KEY_UNKNOWN         , /* 0x01fd */
    KEY_UNKNOWN         , /* 0x01fe */
    KEY_UNKNOWN         , /* 0x01ff */
    KEY_UNKNOWN         , /* 0x0200: HID_CONSUMER_GENERIC_GUI_APPLICATION_CONTROLS */
    KEY_NEW             , /* 0x0201: HID_CONSUMER_AC_NEW */
    KEY_OPEN            , /* 0x0202: HID_CONSUMER_AC_OPEN */
    KEY_CLOSE           , /* 0x0203: HID_CONSUMER_AC_CLOSE */
    KEY_EXIT            , /* 0x0204: HID_CONSUMER_AC_EXIT */
    KEY_UNKNOWN         , /* 0x0205: HID_CONSUMER_AC_MAXIMIZE */
    KEY_UNKNOWN         , /* 0x0206: HID_CONSUMER_AC_MINIMIZE */
    KEY_SAVE            , /* 0x0207: HID_CONSUMER_AC_SAVE */
    KEY_PRINT           , /* 0x0208: HID_CONSUMER_AC_PRINT */
    KEY_PROPS           , /* 0x0209: HID_CONSUMER_AC_PROPERTIES */
    KEY_UNKNOWN         , /* 0x020a: HID_CONSUMER_AC_UNDO */
    KEY_UNKNOWN         , /* 0x020b: HID_CONSUMER_AC_COPY */
    KEY_UNKNOWN         , /* 0x020c: HID_CONSUMER_AC_CUT */
    KEY_UNKNOWN         , /* 0x020d: HID_CONSUMER_AC_PASTE */
    KEY_UNKNOWN         , /* 0x020e: HID_CONSUMER_AC_SELECT_ALL */
    KEY_UNKNOWN         , /* 0x020f: HID_CONSUMER_AC_FIND */
    KEY_UNKNOWN         , /* 0x0210: HID_CONSUMER_AC_FIND_AND_REPLACE */
    KEY_UNKNOWN         , /* 0x0211: HID_CONSUMER_AC_SEARCH */
    KEY_UNKNOWN         , /* 0x0212: HID_CONSUMER_AC_GO_TO */
    KEY_UNKNOWN         , /* 0x0213: HID_CONSUMER_AC_HOME */
    KEY_UNKNOWN         , /* 0x0214: HID_CONSUMER_AC_BACK */
    KEY_UNKNOWN         , /* 0x0215: HID_CONSUMER_AC_FORWARD */
    KEY_UNKNOWN         , /* 0x0216: HID_CONSUMER_AC_STOP */
    KEY_UNKNOWN         , /* 0x0217: HID_CONSUMER_AC_REFRESH */
    KEY_UNKNOWN         , /* 0x0218: HID_CONSUMER_AC_PREVIOUS_LINK */
    KEY_UNKNOWN         , /* 0x0219: HID_CONSUMER_AC_NEXT_LINK */
    KEY_UNDO            , /* 0x021a: HID_CONSUMER_AC_BOOKMARKS */
    KEY_COPY            , /* 0x021b: HID_CONSUMER_AC_HISTORY */
    KEY_CUT             , /* 0x021c: HID_CONSUMER_AC_SUBSCRIPTIONS */
    KEY_PASTE           , /* 0x021d: HID_CONSUMER_AC_ZOOM_IN */
    KEY_UNKNOWN         , /* 0x021e: HID_CONSUMER_AC_ZOOM_OUT */
    KEY_FIND            , /* 0x021f: HID_CONSUMER_AC_ZOOM */
    KEY_UNKNOWN         , /* 0x0220: HID_CONSUMER_AC_FULL_SCREEN_VIEW */
    KEY_SEARCH          , /* 0x0221: HID_CONSUMER_AC_NORMAL_VIEW */
    KEY_GOTO            , /* 0x0222: HID_CONSUMER_AC_VIEW_TOGGLE */
    KEY_HOMEPAGE        , /* 0x0223: HID_CONSUMER_AC_SCROLL_UP */
    KEY_BACK            , /* 0x0224: HID_CONSUMER_AC_SCROLL_DOWN */
    KEY_FORWARD         , /* 0x0225: HID_CONSUMER_AC_SCROLL */
    KEY_STOP            , /* 0x0226: HID_CONSUMER_AC_PAN_LEFT */
    KEY_REFRESH         , /* 0x0227: HID_CONSUMER_AC_PAN_RIGHT */
    KEY_UNKNOWN         , /* 0x0228: HID_CONSUMER_AC_PAN */
    KEY_UNKNOWN         , /* 0x0229: HID_CONSUMER_AC_NEW_WINDOW */
    KEY_BOOKMARKS       , /* 0x022a: HID_CONSUMER_AC_TILE_HORIZONTALLY */
    KEY_UNKNOWN         , /* 0x022b: HID_CONSUMER_AC_TILE_VERTICALLY */
    KEY_UNKNOWN         , /* 0x022c: HID_CONSUMER_AC_FORMAT */
    KEY_ZOOMIN          , /* 0x022d: HID_CONSUMER_AC_EDIT */
    KEY_ZOOMOUT         , /* 0x022e: HID_CONSUMER_AC_BOLD */
    KEY_ZOOMRESET       , /* 0x022f: HID_CONSUMER_AC_ITALICS */
    KEY_UNKNOWN         , /* 0x0230: HID_CONSUMER_AC_UNDERLINE */
    KEY_UNKNOWN         , /* 0x0231: HID_CONSUMER_AC_STRIKETHROUGH */
    KEY_ZOOM            , /* 0x0232: HID_CONSUMER_AC_SUBSCRIPT */
    KEY_SCROLLUP        , /* 0x0233: HID_CONSUMER_AC_SUPERSCRIPT */
    KEY_SCROLLDOWN      , /* 0x0234: HID_CONSUMER_AC_ALL_CAPS */
    KEY_UNKNOWN         , /* 0x0235: HID_CONSUMER_AC_ROTATE */
    KEY_UNKNOWN         , /* 0x0236: HID_CONSUMER_AC_RESIZE */
    KEY_UNKNOWN         , /* 0x0237: HID_CONSUMER_AC_FLIP_HORIZONTAL */
    REL_HWHEEL          , /* 0x0238: HID_CONSUMER_AC_FLIP_VERTICAL */
    KEY_UNKNOWN         , /* 0x0239: HID_CONSUMER_AC_MIRROR_HORIZONTAL */
    KEY_UNKNOWN         , /* 0x023a: HID_CONSUMER_AC_MIRROR_VERTICAL */
    KEY_UNKNOWN         , /* 0x023b: HID_CONSUMER_AC_FONT_SELECT */
    KEY_UNKNOWN         , /* 0x023c: HID_CONSUMER_AC_FONT_COLOR */
    KEY_EDIT            , /* 0x023d: HID_CONSUMER_AC_FONT_SIZE */
    KEY_UNKNOWN         , /* 0x023e: HID_CONSUMER_AC_JUSTIFY_LEFT */
    KEY_UNKNOWN         , /* 0x023f: HID_CONSUMER_AC_JUSTIFY_CENTER_H */
    KEY_UNKNOWN         , /* 0x0240: HID_CONSUMER_AC_JUSTIFY_RIGHT */
    KEY_UNKNOWN         , /* 0x0241: HID_CONSUMER_AC_JUSTIFY_BLOCK_H */
    KEY_UNKNOWN         , /* 0x0242: HID_CONSUMER_AC_JUSTIFY_TOP */
    KEY_UNKNOWN         , /* 0x0243: HID_CONSUMER_AC_JUSTIFY_CENTER_V */
    KEY_UNKNOWN         , /* 0x0244: HID_CONSUMER_AC_JUSTIFY_BOTTOM */
    KEY_UNKNOWN         , /* 0x0245: HID_CONSUMER_AC_JUSTIFY_BLOCK_V */
    KEY_UNKNOWN         , /* 0x0246: HID_CONSUMER_AC_INDENT_DECREASE */
    KEY_UNKNOWN         , /* 0x0247: HID_CONSUMER_AC_INDENT_INCREASE */
    KEY_UNKNOWN         , /* 0x0248: HID_CONSUMER_AC_NUMBERED_LIST */
    KEY_UNKNOWN         , /* 0x0249: HID_CONSUMER_AC_RESTART_NUMBERING */
    KEY_UNKNOWN         , /* 0x024a: HID_CONSUMER_AC_BULLETED_LIST */
    KEY_UNKNOWN         , /* 0x024b: HID_CONSUMER_AC_PROMOTE */
    KEY_UNKNOWN         , /* 0x024c: HID_CONSUMER_AC_DEMOTE */
    KEY_UNKNOWN         , /* 0x024d: HID_CONSUMER_AC_YES */
    KEY_UNKNOWN         , /* 0x024e: HID_CONSUMER_AC_NO */
    KEY_UNKNOWN         , /* 0x024f: HID_CONSUMER_AC_CANCEL */
    KEY_UNKNOWN         , /* 0x0250: HID_CONSUMER_AC_CATALOG */
    KEY_UNKNOWN         , /* 0x0251: HID_CONSUMER_AC_BUY_CHECKOUT */
    KEY_UNKNOWN         , /* 0x0252: HID_CONSUMER_AC_ADD_TO_CART */
    KEY_UNKNOWN         , /* 0x0253: HID_CONSUMER_AC_EXPAND */
    KEY_UNKNOWN         , /* 0x0254: HID_CONSUMER_AC_EXPAND_ALL */
    KEY_UNKNOWN         , /* 0x0255: HID_CONSUMER_AC_COLLAPSE */
    KEY_UNKNOWN         , /* 0x0256: HID_CONSUMER_AC_COLLAPSE_ALL */
    KEY_UNKNOWN         , /* 0x0257: HID_CONSUMER_AC_PRINT_PREVIEW */
    KEY_UNKNOWN         , /* 0x0258: HID_CONSUMER_AC_PASTE_SPECIAL */
    KEY_UNKNOWN         , /* 0x0259: HID_CONSUMER_AC_INSERT_MODE */
    KEY_UNKNOWN         , /* 0x025a: HID_CONSUMER_AC_DELETE */
    KEY_UNKNOWN         , /* 0x025b: HID_CONSUMER_AC_LOCK */
    KEY_UNKNOWN         , /* 0x025c: HID_CONSUMER_AC_UNLOCK */
    KEY_UNKNOWN         , /* 0x025d: HID_CONSUMER_AC_PROTECT */
    KEY_UNKNOWN         , /* 0x025e: HID_CONSUMER_AC_UNPROTECT */
    KEY_CANCEL          , /* 0x025f: HID_CONSUMER_AC_ATTACH_COMMENT */
    KEY_UNKNOWN         , /* 0x0260: HID_CONSUMER_AC_DELETE_COMMENT */
    KEY_UNKNOWN         , /* 0x0261: HID_CONSUMER_AC_VIEW_COMMENT */
    KEY_UNKNOWN         , /* 0x0262: HID_CONSUMER_AC_SELECT_WORD */
    KEY_UNKNOWN         , /* 0x0263: HID_CONSUMER_AC_SELECT_SENTENCE */
    KEY_UNKNOWN         , /* 0x0264: HID_CONSUMER_AC_SELECT_PARAGRAPH */
    KEY_UNKNOWN         , /* 0x0265: HID_CONSUMER_AC_SELECT_COLUMN */
    KEY_UNKNOWN         , /* 0x0266: HID_CONSUMER_AC_SELECT_ROW */
    KEY_UNKNOWN         , /* 0x0267: HID_CONSUMER_AC_SELECT_TABLE */
    KEY_UNKNOWN         , /* 0x0268: HID_CONSUMER_AC_SELECT_OBJECT */
    KEY_INSERT          , /* 0x0269: HID_CONSUMER_AC_REDO_REPEAT */
    KEY_DELETE          , /* 0x026a: HID_CONSUMER_AC_SORT */
    KEY_UNKNOWN         , /* 0x026b: HID_CONSUMER_AC_SORT_ASCENDING */
    KEY_UNKNOWN         , /* 0x026c: HID_CONSUMER_AC_SORT_DESCENDING */
    KEY_UNKNOWN         , /* 0x026d: HID_CONSUMER_AC_FILTER */
    KEY_UNKNOWN         , /* 0x026e: HID_CONSUMER_AC_SET_CLOCK */
    KEY_UNKNOWN         , /* 0x026f: HID_CONSUMER_AC_VIEW_CLOCK */
    KEY_UNKNOWN         , /* 0x0270: HID_CONSUMER_AC_SELECT_TIME_ZONE */
    KEY_UNKNOWN         , /* 0x0271: HID_CONSUMER_AC_EDIT_TIME_ZONES */
    KEY_UNKNOWN         , /* 0x0272: HID_CONSUMER_AC_SET_ALARM */
    KEY_UNKNOWN         , /* 0x0273: HID_CONSUMER_AC_CLEAR_ALARM */
    KEY_UNKNOWN         , /* 0x0274: HID_CONSUMER_AC_SNOOZE_ALARM */
    KEY_UNKNOWN         , /* 0x0275: HID_CONSUMER_AC_RESET_ALARM */
    KEY_UNKNOWN         , /* 0x0276: HID_CONSUMER_AC_SYNCHRONIZE */
    KEY_UNKNOWN         , /* 0x0277: HID_CONSUMER_AC_SEND_RECEIVE */
    KEY_UNKNOWN         , /* 0x0278: HID_CONSUMER_AC_SEND_TO */
    KEY_REDO            , /* 0x0279: HID_CONSUMER_AC_REPLY */
    KEY_UNKNOWN         , /* 0x027a: HID_CONSUMER_AC_REPLY_ALL */
    KEY_UNKNOWN         , /* 0x027b: HID_CONSUMER_AC_FORWARD_MSG */
    KEY_UNKNOWN         , /* 0x027c: HID_CONSUMER_AC_SEND */
    KEY_UNKNOWN         , /* 0x027d: HID_CONSUMER_AC_ATTACH_FILE */
    KEY_UNKNOWN         , /* 0x027e: HID_CONSUMER_AC_UPLOAD */
    KEY_UNKNOWN         , /* 0x027f: HID_CONSUMER_AC_DOWNLOAD_SAVE_TARGET_AS */
    KEY_UNKNOWN         , /* 0x0280: HID_CONSUMER_AC_SET_BORDERS */
    KEY_UNKNOWN         , /* 0x0281: HID_CONSUMER_AC_INSERT_ROW */
    KEY_UNKNOWN         , /* 0x0282: HID_CONSUMER_AC_INSERT_COLUMN */
    KEY_UNKNOWN         , /* 0x0283: HID_CONSUMER_AC_INSERT_FILE */
    KEY_UNKNOWN         , /* 0x0284: HID_CONSUMER_AC_INSERT_PICTURE */
    KEY_UNKNOWN         , /* 0x0285: HID_CONSUMER_AC_INSERT_OBJECT */
    KEY_UNKNOWN         , /* 0x0286: HID_CONSUMER_AC_INSERT_SYMBOL */
    KEY_UNKNOWN         , /* 0x0287: HID_CONSUMER_AC_SAVE_AND_CLOSE */
    KEY_UNKNOWN         , /* 0x0288: HID_CONSUMER_AC_RENAME */
    KEY_REPLY           , /* 0x0289: HID_CONSUMER_AC_MERGE */
    KEY_UNKNOWN         , /* 0x028a: HID_CONSUMER_AC_SPLIT */
    KEY_FORWARDMAIL     , /* 0x028b: HID_CONSUMER_AC_DISRIBUTE_HORIZONTALLY */
    KEY_SEND            , /* 0x028c: HID_CONSUMER_AC_DISTRIBUTE_VERTICALLY */
    KEY_UNKNOWN         , /* 0x028d */
    KEY_UNKNOWN         , /* 0x028e */
    KEY_UNKNOWN         , /* 0x028f */
    KEY_UNKNOWN         , /* 0x0290 */
    KEY_UNKNOWN         , /* 0x0291 */
    KEY_UNKNOWN         , /* 0x0292 */
    KEY_UNKNOWN         , /* 0x0293 */
    KEY_UNKNOWN         , /* 0x0294 */
    KEY_UNKNOWN         , /* 0x0295 */
    KEY_UNKNOWN         , /* 0x0296 */
    KEY_UNKNOWN         , /* 0x0297 */
    KEY_UNKNOWN         , /* 0x0298 */
    KEY_UNKNOWN         , /* 0x0299 */
    KEY_UNKNOWN         , /* 0x029a */
    KEY_UNKNOWN         , /* 0x029b */
    KEY_UNKNOWN         , /* 0x029c */
};
