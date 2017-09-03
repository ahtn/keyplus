// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/layout.h"

#include "core/keycode.h"
#include "core/macro.h"
#include "core/settings.h"

XRAM flash_size_t g_layout_storage_pos[MAX_NUM_KEYBOARDS];

#define KC_CTRL_ALT MODKEY(MODKEY_TAG_LCTL | MODKEY_TAG_LALT, 0)

#define _8(x) ((uint8_t)(x) & 0xff)
#define _16(x) _8(((uint16_t)x)), _8(((uint16_t)x) >> 8)
#define _32(x) _16(((uint32_t)x)), _16(((uint32_t)x >> 16))

#define KEYMAP( \
        K00, K01, K02, K03, K04, K05, \
        K10, K11, K12, K13, K14, K15, \
        K20, K21, K22, K23, K24, K25, \
        K30, K31, K32, K33, K34, \
        \
        K40, K41, K42, K43, K44, K45, \
        K50, K51, K52, K53, K54, K55, \
        K60, K61, K62, K63, K64, K65, \
        K70, K71, K72, K73, K74 \
        ) \
      _16(KC_##K00), _16(KC_##K01), _16(KC_##K02), _16(KC_##K03), _16(KC_##K04), _16(KC_##K05), _16(KC_##K10), _16(KC_##K11  ), \
      _16(KC_##K12), _16(KC_##K13), _16(KC_##K14), _16(KC_##K15), _16(KC_##K20), _16(KC_##K21), _16(KC_##K22), _16(KC_##K23  ), \
      _16(KC_##K24), _16(KC_##K25), _16(KC_##K30), _16(KC_##K31), _16(KC_##K32), _16(KC_##K33), _16(KC_##K34), _16(KC_NONE   ), \
    \
      _16(KC_##K40), _16(KC_##K41), _16(KC_##K42), _16(KC_##K43), _16(KC_##K44), _16(KC_##K45), _16(KC_##K50), _16(KC_##K51  ), \
      _16(KC_##K52), _16(KC_##K53), _16(KC_##K54), _16(KC_##K55), _16(KC_##K60), _16(KC_##K61), _16(KC_##K62), _16(KC_##K63  ), \
      _16(KC_##K64), _16(KC_##K65), _16(KC_##K70), _16(KC_##K71), _16(KC_##K72), _16(KC_##K73), _16(KC_##K74), _16(KC_NONE)

#define KEYMAP_1( \
        K00, K01, K02, K03, K04, K05, \
        K10, K11, K12, K13, K14, K15, \
        K20, K21, K22, K23, K24, K25, \
        K30, K31, K32, K33, K34, K35  \
        ) \
    _16(KC_##K00), _16(KC_##K01), _16(KC_##K02), _16(KC_##K03), _16(KC_##K04), _16(KC_##K05), _16(KC_##K10), _16(KC_##K11), \
    _16(KC_##K12), _16(KC_##K13), _16(KC_##K14), _16(KC_##K15), _16(KC_##K20), _16(KC_##K21), _16(KC_##K22), _16(KC_##K23), \
    _16(KC_##K24), _16(KC_##K25), _16(KC_##K30), _16(KC_##K31), _16(KC_##K32), _16(KC_##K33), _16(KC_##K34), _16(KC_##K35)

#define KC_MACRO_0 KC_EXTERNAL(0)
#define KC_MACRO_1 KC_EXTERNAL(24)
#define KC_MACRO_2 KC_EXTERNAL(34)
#define KC_HOLD_1  KC_EXTERNAL(48)
#define KC_ENT_SFT KC_EXTERNAL(58)

#define EXTENDED_KEYCODES() \
    _32(68ULL), \
    _16(KC_MACRO), \
    _16(KC_H), _16(KC_E), _16(KC_L), _16(KC_L), _16(KC_0), \
    _16(KC_H), _16(KC_E), _16(KC_L), _16(KC_L), _16(KC_0), \
    _16(MACRO_CMD_FINISH), \
    _16(KC_MACRO), \
    _16(KC_B), _16(KC_Y), _16(KC_E), \
    _16(MACRO_CMD_FINISH), \
    _16(KC_MACRO_UP_AND_DOWN), \
    _16(42), \
    _16(KC_B), \
    _16(MACRO_CMD_FINISH), \
    _16(KC_Y), _16(KC_E), \
    _16(MACRO_CMD_FINISH), \
    _16(KC_HOLD_KEY), \
    _16(125), \
    _16(0), \
    _16(KC_A), \
    _16(KC_MACRO_1), \
    _16(KC_HOLD_KEY), \
    _16(200), \
    _16(0), \
    _16(KC_STICKY_LSHIFT), \
    _16(KC_ENT),

#define EXTENDED_KEYCODES1() \
    _32(230ULL), \
    _16(MACRO_CMD_SET_RATE), _16(500), \
    _16(MODKEY(MODKEY_TAG_LALT, KC_TAB)), \
    _16(MACRO_CMD_SET_RATE), _16(100), \
    _16(KC_E), _16(KC_C), _16(KC_H), _16(KC_O), _16(KC_SPC), _16(KC_s(QUOT)), \
    _16(MODKEY(MODKEY_TAG_LALT, KC_TAB)), \
    _16(MACRO_CMD_SET_RATE), _16(10), \
    _16(MACRO_CMD_MOUSE_SET_BUTTONS), _16(0x0001), \
    _16(MACRO_CMD_REPEAT_BLOCK), _16(40), \
    _16(MACRO_CMD_MOUSE_SET_POS), (uint8_t)+5,  (uint8_t)+5, \
    _16(MACRO_CMD_REPEAT_JMP), _16((uint16_t)-8), \
    _16(MACRO_CMD_MOUSE_CLEAR), \
    \
    _16(MACRO_CMD_SET_RATE), _16(250), \
    _16(KC_a(TAB)), \
    _16(KC_H), _16(KC_E), _16(KC_L), _16(KC_L), _16(KC_O), \
    _16(KC_a(TAB)), \
    \
    _16(MACRO_CMD_SET_RATE), _16(10), \
    _16(MACRO_CMD_MOUSE_SET_BUTTONS), _16(0x0001), \
    _16(MACRO_CMD_REPEAT_BLOCK), _16(40), \
    _16(MACRO_CMD_MOUSE_SET_POS), (uint8_t)-0,  (uint8_t)-5, \
    _16(MACRO_CMD_REPEAT_JMP), _16((uint16_t)-8), \
    _16(MACRO_CMD_MOUSE_CLEAR), \
    \
    _16(MACRO_CMD_SET_RATE), _16(500), \
    _16(KC_a(TAB)), \
    _16(MACRO_CMD_SET_RATE), _16(5), \
    _16(KC_SPC), _16(KC_W), _16(KC_O), _16(KC_R), _16(KC_L), _16(KC_D), \
    _16(MACRO_CMD_SET_RATE), _16(500), \
    _16(KC_a(TAB)), \
    \
    _16(MACRO_CMD_SET_RATE), _16(10), \
    _16(MACRO_CMD_MOUSE_SET_BUTTONS), _16(0x0001), \
    _16(MACRO_CMD_REPEAT_BLOCK), _16(40), \
    _16(MACRO_CMD_MOUSE_SET_POS), (uint8_t)-5,  (uint8_t)-0, \
    _16(MACRO_CMD_REPEAT_JMP), _16((uint16_t)-8), \
    _16(MACRO_CMD_MOUSE_CLEAR), \
    _16(MACRO_CMD_MOUSE_SET_BUTTONS), _16(0x0000), \
    _16(MACRO_CMD_SET_RATE), _16(500), \
    _16(KC_a(TAB)), \
    _16(KC_BSLS), _16(KC_s(1)), _16(KC_s(QUOT)), _16(KC_ENT), \
    _16(KC_a(TAB)), \
    _16(MACRO_CMD_MOUSE_SET_POS), (uint8_t)+127,  (uint8_t)-0, \
    _16(MACRO_CMD_REPEAT_BLOCK), _16(8), \
    _16(MACRO_CMD_SET_RATE), _16(5), \
    _16(MACRO_CMD_MOUSE_SET_BUTTONS), _16(0x0001), \
    _16(MACRO_CMD_REPEAT_BLOCK), _16(10), \
    _16(MACRO_CMD_MOUSE_SET_POS), (uint8_t)+0,  (uint8_t)+10, \
    _16(MACRO_CMD_REPEAT_JMP), _16((uint16_t)-8), \
    _16(MACRO_CMD_REPEAT_BLOCK), _16(10), \
    _16(MACRO_CMD_MOUSE_SET_POS), (uint8_t)+6,  (uint8_t)-6, \
    _16(MACRO_CMD_REPEAT_JMP), _16((uint16_t)-8), \
    _16(MACRO_CMD_REPEAT_BLOCK), _16(10), \
    _16(MACRO_CMD_MOUSE_SET_POS), (uint8_t)-6,  (uint8_t)-6, \
    _16(MACRO_CMD_REPEAT_JMP), _16((uint16_t)-8), \
    _16(MACRO_CMD_SET_RATE), _16(5), \
    _16(MACRO_CMD_MOUSE_SET_BUTTONS), _16(0x0000), \
    _16(MACRO_CMD_WAIT), \
    _16(MACRO_CMD_MOUSE_SET_POS), (uint8_t)-30,  (uint8_t)-0, \
    _16(MACRO_CMD_WAIT), \
    _16(MACRO_CMD_REPEAT_JMP), _16((uint16_t)-64), \
    _16(MACRO_CMD_FINISH),

#if 0
#endif


#if DEVICE_ID == 0
#if KEYPLUS_MINI_TESTING

#define KEY_NUMBER_MAP() \
     0,  1,  2,  3,  4,  5, \
     6,  7,  8,  9, 10, 11, \
    12, 13, 14, 15, 16, 17, \
    23, 22, 21, 18, 19, 20,
#else
// r3c3: 0  | r3c2: 1  | r2c3: 2  | r2c2: 3  | r1c3: 4  | r1c2: 5
// r3c5: 6  | r3c0: 7  | r2c5: 8  | r2c0: 9  | r1c0: 10 | r1c5: 11
// r3c4: 12 | r3c1: 13 | r2c4: 14 | r2c1: 15 | r1c4: 16 | r1c1: 17
// r0c4: 18 | r0c0: 19 | r0c5: 20 | r0c1: 21
#define KEY_NUMBER_MAP() \
   20, 22, 99, 99, 19, 21, \
   10, 17,  5,  4, 16, 11, \
    9, 15,  3,  2, 14,  8, \
    7, 13,  1,  0, 12,  6,

#endif

#elif DEVICE_ID == 1
#if KEYPLUS_MINI_TESTING
#define KEY_NUMBER_MAP() \
     0,  1,  2,  3,  4,  5, \
     6,  7,  8,  9, 10, 11, \
    12, 13, 14, 15, 16, 17, \
    20, 21, 22, 19, 18, 23,
#else
// 0: r3c0 1: r3c4 2: r1c0 3: r1c4 4: r0c0 5: r0c4 6: r3c2 7: r3c5 8: r1c2 9: r1c5 10:r0c2 11:r0c5 12:r3c1 13:r3c3 14:r1c1 15:r1c3 16:r0c1 17:r0c3 18:r2c1 19:r2c3 20:r2c2 21:r2c5
#define KEY_NUMBER_MAP() \
     4, 16, 10, 17,  5, 11, \
     2, 14,  8, 15,  3,  9, \
    99, 18, 20, 19, 99, 21, \
     0, 12,  6, 13,  1,  7,
#endif
#elif DEVICE_ID == 2 || DEVICE_ID == 8 || DEVICE_ID == 9
#define KEY_NUMBER_MAP() \
     0,  1,  2,  3,  4,  5, \
     6,  7,  8,  9, 10, 11, \
    12, 13, 14, 15, 16, 17, \
    18, 19, 20, 21, 22, 23,
#elif DEVICE_ID == 4
#define KEY_NUMBER_MAP() \
     0,  1,  2,  3,  4,  5, \
     6,  7,  8,  9, 10, 11, \
    12, 13, 14, 15, 16, 17, \
    23, 22, 21, 18, 19, 20,
#elif DEVICE_ID == 5
#define KEY_NUMBER_MAP() \
     0,  1,  2,  3,  4,  5, \
     6,  7,  8,  9, 10, 11, \
    12, 13, 14, 15, 16, 17, \
    20, 21, 22, 19, 18, 23,
#elif DEVICE_ID == 0x30
#define KEY_NUMBER_MAP()
#endif


#define KC_UNDO2 MODKEY(MODKEY_TAG_LCTL | MODKEY_TAG_LSFT, KC_Z)


// layout storage structure is like this:
//
// The first section is for storing the (row, col) -> (key number map). It's
// size is `g_settings.row_count * g_settings.col_count`.
//  `flash_ptr_t storage_pos = (g_settings.row_count * g_settings.col_count + 1) / 2;`
//
// The second section is for the extended keycode data. It's size is given in the
// first 4 bytes of the section.
//
// The third section is for the layout data. The structure of the layout section
// is determined by the g_settings.layout[].
//

AT__LAYOUT_ADDR
// ROM const keycode_t layout_storage[LAYOUT_SIZE/sizeof(keycode_t)] = {
ROM const uint8_t g_layout_storage[] = {
// key number map section
    KEY_NUMBER_MAP()
// extended keycode section
    EXTENDED_KEYCODES()
// layout section
#ifndef NO_USB
    /* colemak L0 */
    KEYMAP(
            /* left hand */
            TAB     , Q   , W    , F   , P   , G ,
            ENT_SFT , A   , R    , S   , T   , D ,
            LALT    , Z   , X    , C   , V   , B ,
            ESC     , L6 , LCTL , SPC , L5 ,
            /* right hand */
            J    , L    , U    , Y    , SCLN , MINS ,
            H    , N    , E    , I    , O    , QUOT ,
            K    , M    , COMM , DOT  , SLSH , GRV  ,
            // BSPC , LSFT , STICKY_L4  , LGUI , ESC
            BSPC , STICKY_LSHIFT , STICKY_L4  , LGUI , ESC
            ),
    /* dvorak L1 */
    KEYMAP(
            /* left hand */
            TRNS , QUOT , COMM , DOT  , P    , Y ,
            TRNS , A    , O    , E    , U    , I ,
            TRNS , SCLN , Q    , J    , K    , X ,
            TRNS , TRNS , TRNS , TRNS , TRNS ,
            /* right hand */
            F    , G    , C    , R    , L    , SLSH ,
            D    , H    , T    , N    , S    , MINS ,
            B    , M    , W    , V    , Z    , GRV  ,
            TRNS , TRNS , TRNS , TRNS , TRNS
            ),
    /* qwerty L2 */
    KEYMAP(
            /* left hand */
            TRNS , Q    , W    , E    , R    , T ,
            TRNS , A    , S    , D    , F    , G ,
            TRNS , Z    , X    , C    , V    , B ,
            TRNS , TRNS , TRNS , TRNS , TRNS ,
            /* right hand */
            Y    , U    , I    , O    , P    , MINS ,
            H    , J    , K    , L    , SCLN , QUOT ,
            M    , N    , COMM , DOT  , SLSH , GRV ,
            TRNS , TRNS , TRNS , TRNS , TRNS
            ),
    /* qwerty-arrows L3 */
    KEYMAP(
            /* left hand */
            TRNS , Q    , W    , E    , R    , T ,
            TRNS , A    , S    , D    , F    , G ,
            TRNS , Z    , X    , C    , V    , B ,
            TRNS , TRNS , TRNS , TRNS , TRNS ,
            /* right hand */
            Y    , U    , UP   , O     , P    , MINS ,
            H    , LEFT , DOWN , RIGHT , SCLN , QUOT ,
            N    , M    , COMM , DOT   , SLSH , GRV  ,
            TRNS , TRNS , TRNS , TRNS  , TRNS
            ),
    /* symbol L4 */
    KEYMAP(
            /* left hand */
            TRNS , fs(BSLS) , f_(2) , f_(3)  , f_(4) , f_(5)       ,
            TRNS , f_(1)     , f_(BSLS) , fs(9) , f_(LBRC) , fs(LBRC) ,
            TRNS , fs(1)    , fs(2) , fs(3) , fs(4) , fs(5)    ,
            TRNS , TRNS    , TRNS , TRNS , L6 ,
            /* right hand */
            f_(6)     , f_(7) , f_(8)  , f_(9)    , fs(EQL) , f_(MINS)   ,
            fs(RBRC) , f_(RBRC) , fs(0) , f_(EQL)  , f_(0)      , fs(8)   ,
            fs(6)    , fs(7) , f_(COMM) , f_(DOT)  , f_(SLSH)   , fs(GRV) ,
            TRNS    , TRNS , TRNS , TRNS , TRNS
            ),
    /* fn L5 */
    KEYMAP(
            /* left hand */
            INS  , DEL  , HOME , UP   , END  , PGUP ,
            TRNS , ESC  , LEFT , DOWN , RGHT , PGDN ,
            TRNS , F1   , F2   , F3   , F4   , F5   ,
            TRNS , TRNS , TRNS , TRNS , TRNS ,
            /* right hand */
            c(PGUP) , c(HOME) , c(UP)   , c(END)   , c(DEL)  , F12 ,
            c(PGDN) , c(LEFT) , c(DOWN) , c(RIGHT) , c(BSPC) , F11 ,
            /* F6      , F7      , F8      , F9       , F10     , F13 , */
            F6      , F7      , F8      , F9       , F10     , CTRL_ALT ,
            TRNS    , TRNS    , L6    , TRNS     , TRNS
            ),
    /* media L6 */
    KEYMAP(
            /* left hand */
            SLCK , PSCR , MPLY , VOLU , MSTP   , F11    ,
            BSPC , MUTE , MPRV , VOLD , MNXT   , APP    ,
            LGUI , c(Y) , UNDO2, E    , c(E)   , s(E)   ,
            TRNS , TRNS , TRNS , TRNS , TRNS   ,
            /* right hand */
            WH_U , BTN1 , MS_U , BTN2 , r_s(C) , HOLD_1 ,
            WH_D , MS_L , MS_D , MS_R , BTN3   , MACRO_0 ,
            SET_L3  , SET_L0  , SET_L1  , SET_L2  , NONE   , LAYER_RESET   ,
            TRNS , TRNS , TRNS , TRNS , TRNS
            ),
/*********************************************************************
 *                      test half-split-layout                       *
 *********************************************************************/
    KEYMAP_1(
            /* left hand */
            A , 6 , 7 , 8 , 9 , 0 ,
            B , A , R , S , T , D ,
            C , Z , X , C , V , B ,
            D , 1 , 2 , 3 , 4 , SPC
            ),

    /* colemak L0 */
    KEYMAP(
            /* left hand */
            TAB  , Q   , W    , F   , P   , G ,
            ENT  , A   , R    , S   , T   , D ,
            LALT , Z   , X    , C   , V   , B ,
            ESC  , L6 , LCTL , SPC , L5 ,
            /* right hand */
            J    , L    , U    , Y    , SCLN , MINS ,
            H    , N    , E    , I    , O    , QUOT ,
            K    , M    , COMM , DOT  , SLSH , GRV  ,
            // BSPC , LSFT , STICKY_L4  , LGUI , ESC
            BSPC , STICKY_LSHIFT , STICKY_L4  , LGUI , ESC
            ),

    /* dvorak L1 */
    KEYMAP(
            /* left hand */
            TRNS , QUOT , COMM , DOT  , P    , Y ,
            TRNS , A    , O    , E    , U    , I ,
            TRNS , SCLN , Q    , J    , K    , X ,
            TRNS , TRNS , TRNS , TRNS , TRNS ,
            /* right hand */
            F    , G    , C    , R    , L    , SLSH ,
            D    , H    , T    , N    , S    , MINS ,
            B    , M    , W    , V    , Z    , GRV  ,
            TRNS , TRNS , TRNS , TRNS , TRNS
            ),

    KEYMAP_1(
            /* left hand */
            TAB , Q , W , F , P , G ,
            ENT , A , R , S , T , D ,
            MINS , Z , X , C , V , B ,
            LALT , 1 , 2 , 3 , LCTRL , SPC
            ),

#endif
};

// TODO: change these to flash ptrs?
void keyboard_layouts_init(void) {
    uint8_t i;

    flash_ptr_t storage_pos = (flash_ptr_t)&g_layout_storage[0];

    // TODO: clean up this handling and make it more robust
    /* g_keyboard_slots[0].layout = (const ROM uint16_t*) LAYOUT_ADDR; */

    // key num map section
    {
        // skip the key num map section, since it is in a known location at compile
        // time.
        flash_size_t key_num_map_size = g_settings.row_count * g_settings.col_count;
        storage_pos += key_num_map_size;
    }

    // extended keycode section
    {
        flash_read((uint8_t*)&g_ekc_storage_size, storage_pos, sizeof(uint32_t));
        storage_pos += sizeof(uint32_t);

        if (!is_valid_storage_pos(storage_pos + g_ekc_storage_size)) {
            // TODO: a warnning here would be nice, but it will just screw up the
            // layout instead.
            g_ekc_storage_size = 0;
        }
        g_ekc_storage_ptr = storage_pos;

        storage_pos += g_ekc_storage_size;
    }


    // layout section
    g_layout_storage_pos[0] = storage_pos;

    // calculate the start of the keyload positions and save them for later
    for (i = 1; i < g_settings.layout.number_layouts; ++i) {
        const uint8_t matrix_size = g_settings.layout.layouts[i-1].matrix_size;
        const uint8_t layer_count = g_settings.layout.layouts[i-1].layer_count;
        const flash_size_t this_layout_size = g_settings.layout.layouts[i].matrix_size;

        storage_pos += 8*sizeof(keycode_t) * matrix_size * layer_count;

        if (is_valid_storage_pos(storage_pos + this_layout_size - 1)) {
            g_layout_storage_pos[i] = storage_pos;
        } else {
            // TODO: a warning here would be nice. Instead for now, we just map
            // excessive layout positions to the first one.
            g_layout_storage_pos[i] = (flash_ptr_t)g_layout_storage_pos[0];
        }
        g_layout_storage_pos[i] = storage_pos;
    }
}
