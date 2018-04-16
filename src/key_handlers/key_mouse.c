// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "key_handlers/key_mouse.h"

#include <string.h>

#include "core/timer.h"

#include "usb_reports/mouse_report.h"

// /* TODO: mouse keycode */
bit_t is_mouse_keycode(keycode_t keycode) {
    return IS_MOUSEKEY(keycode);
}

#define MOUSE_SPEED 8
#define MOUSE_WHEEL_SPEED 1
#define MOUSE_REPORT_RATE 8

static XRAM hid_report_mouse_t s_mouse_state;
static XRAM uint8_t s_mouse_keys_down;
static XRAM uint8_t s_force_update;
static XRAM uint8_t s_report_time;

/* TODO: proper mouse handling */
void handle_mouse_keycode(keycode_t kc, key_event_t event) REENT {
    if (event == EVENT_RESET) {
        s_mouse_keys_down = 0;
        s_force_update = 0;
        return;
    }

    if (s_mouse_keys_down == 0) {
        memset((uint8_t*)&s_mouse_state, 0, sizeof(s_mouse_state));
        s_report_time = timer_read8_ms();
    }

    if (IS_MOUSEKEY_BUTTON(kc)) {
        if (event == EVENT_PRESSED) {
            s_mouse_state.buttons_1 |= (1 << MOUSEKEY_BUTTON_NUM(kc));
            s_mouse_keys_down += 1;
        } else {
            s_mouse_state.buttons_1 &= ~(1 << (MOUSEKEY_BUTTON_NUM(kc)));
            if (s_mouse_keys_down != 0) {
                s_mouse_keys_down -= 1;
            }
            s_force_update = 1;
        }
    } else if (kc >= KC_MOUSE_UP && kc <= KC_MOUSE_WH_RIGHT) {
        if (event == EVENT_PRESSED) {
            switch (kc) {
                case KC_MOUSE_UP:    { s_mouse_state.y = -MOUSE_SPEED; } break;
                case KC_MOUSE_DOWN:  { s_mouse_state.y = +MOUSE_SPEED; } break;
                case KC_MOUSE_LEFT:  { s_mouse_state.x = -MOUSE_SPEED; } break;
                case KC_MOUSE_RIGHT: { s_mouse_state.x = +MOUSE_SPEED; } break;

                case KC_MOUSE_WH_UP:    { s_mouse_state.wheel_y = +MOUSE_WHEEL_SPEED; } break;
                case KC_MOUSE_WH_DOWN:  { s_mouse_state.wheel_y = -MOUSE_WHEEL_SPEED; } break;
                case KC_MOUSE_WH_LEFT:  { s_mouse_state.wheel_x = +MOUSE_WHEEL_SPEED; } break;
                case KC_MOUSE_WH_RIGHT: { s_mouse_state.wheel_x = -MOUSE_WHEEL_SPEED; } break;
            }
            s_mouse_keys_down += 1;
        } else {
            switch (kc) {
                case KC_MOUSE_UP:    { s_mouse_state.y = 0; } break;
                case KC_MOUSE_DOWN:  { s_mouse_state.y = 0; } break;
                case KC_MOUSE_LEFT:  { s_mouse_state.x = 0; } break;
                case KC_MOUSE_RIGHT: { s_mouse_state.x = 0; } break;

                case KC_MOUSE_WH_UP:    { s_mouse_state.wheel_y = 0; } break;
                case KC_MOUSE_WH_DOWN:  { s_mouse_state.wheel_y = 0; } break;
                case KC_MOUSE_WH_LEFT:  { s_mouse_state.wheel_x = 0; } break;
                case KC_MOUSE_WH_RIGHT: { s_mouse_state.wheel_x = 0; } break;
            }
            if (s_mouse_keys_down != 0) {
                s_mouse_keys_down -= 1;
            }
        }
    }
    s_mouse_keys_down += s_force_update;
}

void mouse_key_task(void) {
    if (
        s_mouse_keys_down &&
        ((uint8_t)(timer_read8_ms() - s_report_time) > MOUSE_REPORT_RATE)
    ) {
        memcpy(&g_mouse_report, &s_mouse_state, sizeof(hid_report_mouse_t));
        g_report_pending_mouse = true;
        s_report_time = timer_read8_ms();
        s_mouse_keys_down -= s_force_update;
        s_force_update = 0;
    }
}

XRAM keycode_callbacks_t mouse_keycodes = {
    .checker = is_mouse_keycode,
    .handler = handle_mouse_keycode,
};

