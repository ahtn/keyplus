// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "key_handlers/key_macro.h"

#include "core/keycode.h"
#include "core/macro.h"
#include "core/matrix_interpret.h"

#define MACRO_UP_AND_DOWN_RELEASE_POINTER_ADDR 0
#define MACRO_UP_AND_DOWN_PRESS_MARCO_ADDR 2

bit_t is_macro_keycode(keycode_t keycode) {
    return keycode == KC_MACRO || keycode == KC_MACRO_UP_AND_DOWN;
}

void handle_macro_keycodes(keycode_t keycode, key_event_t event) REENT {
    uint16_t kc = get_ekc_type(keycode);
    uint16_t ekc_addr = EKC_DATA_ADDR(keycode);
    const uint8_t kb_id = get_active_keyboard_id();

    if (kc == KC_MACRO) {
        if (event == EVENT_PRESSED) {
            call_macro(ekc_addr, kb_id);
        }
    } else if (kc == KC_MACRO_UP_AND_DOWN) {
        // External data for `KC_MACRO_UP_AND_DOWN` looks like this:
        // uint16_t up_macro_address;
        // uint8_t press_macro_data[]
        if (event == EVENT_PRESSED) {
            call_macro(ekc_addr + MACRO_UP_AND_DOWN_PRESS_MARCO_ADDR, kb_id);
        } else if (event == EVENT_RELEASED) {
            uint16_t release_macro_addr;
            uint8_t err;
            err = get_ekc_data(
                (uint8_t*)&release_macro_addr,
                ekc_addr + MACRO_UP_AND_DOWN_RELEASE_POINTER_ADDR,
                sizeof(uint16_t)
            );
            if (!err) {
                call_macro(release_macro_addr, kb_id);
            }
        }
    }
}

XRAM keycode_callbacks_t macro_keycodes = {
    .checker = is_macro_keycode,
    .handler = handle_macro_keycodes,
};
