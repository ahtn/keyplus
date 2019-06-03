// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "key_handlers/key_mouse.h"

#include <string.h>

#include "core/matrix_interpret.h"
#include "core/timer.h"

#if USE_UNIFYING
#  include "core/unifying.h"
#endif

#include "hid_reports/mouse_report.h"

// /* TODO: mouse keycode */
bit_t is_mouse_keycode(keycode_t keycode) {
#if USE_UNIFYING && USE_MOUSE_GESTURE
    return ( IS_MOUSEKEY(keycode) || keycode == KC_MOUSE_GESTURE);
#else
    return IS_MOUSEKEY(keycode);
#endif
}

// TODO: make these configurable
#define MOUSE_SPEED 10
#define MOUSE_WHEEL_SPEED 1
#define MOUSE_REPORT_RATE 10

#define MOUSE_KEY_LEFT  0x01
#define MOUSE_KEY_RIGHT 0x02
#define MOUSE_KEY_UP    0x04
#define MOUSE_KEY_DOWN  0x08

#define MOUSE_KEY_WHEEL_LEFT  0x10
#define MOUSE_KEY_WHEEL_RIGHT 0x20
#define MOUSE_KEY_WHEEL_UP    0x40
#define MOUSE_KEY_WHEEL_DOWN  0x80

/// The number of mouse keys currently in the pressed state
static XRAM uint8_t s_num_mouse_keys_down;
/// Keeps track of the number mouse keys that need
static XRAM uint8_t s_report_time;

static XRAM uint8_t s_mouse_keys;

/// The mouse buttons to be released on the next mouse key report
static XRAM uint8_t s_relased_buttons;
/// The number of mouse buttons to be released on the next mouse key report
static XRAM uint8_t s_num_mouse_keys_to_release;

/* TODO: proper mouse handling */
void handle_mouse_keycode(keycode_t ekc, key_event_t event) REENT {
    keycode_t kc = get_ekc_type(ekc);

    if (event == EVENT_RESET) {
        s_mouse_keys = 0;
        s_relased_buttons = 0;
        s_num_mouse_keys_down = 0;
        s_num_mouse_keys_to_release = 0;
#if USE_UNIFYING && USE_MOUSE_GESTURE
        gesture_init();
#endif
        return;
    }

    if (s_num_mouse_keys_down == 0) {
        s_report_time = timer_read8_ms();
    }

    if (IS_MOUSEKEY_BUTTON(kc)) {
        if (event == EVENT_PRESSED) {
            g_mouse_report.buttons_1 |= (1 << MOUSEKEY_BUTTON_NUM(kc));
            s_num_mouse_keys_down += 1;
            g_report_pending_mouse = true;
        } else {
            // Release any buttons if necessary
            g_mouse_report.buttons_1 &= ~(1 << MOUSEKEY_BUTTON_NUM(kc));
            // NOTE: Don't remove the number s_num_mouse_keys_down until after the
            // mouse report has been sent.
            s_num_mouse_keys_to_release += 1;
            g_report_pending_mouse = true;
        }
    } else if (kc >= KC_MOUSE_UP && kc <= KC_MOUSE_WH_RIGHT) {
        if (event == EVENT_PRESSED) {
            switch (kc) {
                case KC_MOUSE_UP:    { s_mouse_keys |= MOUSE_KEY_UP; } break;
                case KC_MOUSE_DOWN:  { s_mouse_keys |= MOUSE_KEY_DOWN; } break;
                case KC_MOUSE_LEFT:  { s_mouse_keys |= MOUSE_KEY_LEFT; } break;
                case KC_MOUSE_RIGHT: { s_mouse_keys |= MOUSE_KEY_RIGHT; } break;

                case KC_MOUSE_WH_UP:    { s_mouse_keys |= MOUSE_KEY_WHEEL_UP; } break;
                case KC_MOUSE_WH_DOWN:  { s_mouse_keys |= MOUSE_KEY_WHEEL_DOWN; } break;
                case KC_MOUSE_WH_LEFT:  { s_mouse_keys |= MOUSE_KEY_WHEEL_LEFT; } break;
                case KC_MOUSE_WH_RIGHT: { s_mouse_keys |= MOUSE_KEY_WHEEL_RIGHT; } break;
            }
            s_num_mouse_keys_down += 1;
        } else {
            switch (kc) {
                case KC_MOUSE_UP:    { s_mouse_keys &= ~MOUSE_KEY_UP; } break;
                case KC_MOUSE_DOWN:  { s_mouse_keys &= ~MOUSE_KEY_DOWN; } break;
                case KC_MOUSE_LEFT:  { s_mouse_keys &= ~MOUSE_KEY_LEFT; } break;
                case KC_MOUSE_RIGHT: { s_mouse_keys &= ~MOUSE_KEY_RIGHT; } break;

                case KC_MOUSE_WH_UP:    { s_mouse_keys &= ~MOUSE_KEY_WHEEL_UP; } break;
                case KC_MOUSE_WH_DOWN:  { s_mouse_keys &= ~MOUSE_KEY_WHEEL_DOWN; } break;
                case KC_MOUSE_WH_LEFT:  { s_mouse_keys &= ~MOUSE_KEY_WHEEL_LEFT; } break;
                case KC_MOUSE_WH_RIGHT: { s_mouse_keys &= ~MOUSE_KEY_WHEEL_RIGHT; } break;
            }
            s_num_mouse_keys_to_release += 1;
        }
#if USE_UNIFYING && USE_MOUSE_GESTURE
    } else if (kc == KC_MOUSE_GESTURE) {
        // Mouse gesture
        uint8_t kb_id = get_active_keyboard_id();
        if (event == EVENT_PRESSED) {
            gesture_press(EKC_DATA_ADDR(ekc), kb_id);
        } else {
            gesture_release(EKC_DATA_ADDR(ekc), kb_id);
        }
#endif
    }
}

bool mouse_key_task(void) {
    if (
        s_num_mouse_keys_down &&
        ((uint8_t)(timer_read8_ms() - s_report_time) > MOUSE_REPORT_RATE)
    ) {
        // Calulate mouse speed based of current mouse key button state
        if (s_mouse_keys & MOUSE_KEY_LEFT)  { g_mouse_report.x += -MOUSE_SPEED; }
        if (s_mouse_keys & MOUSE_KEY_RIGHT) { g_mouse_report.x += +MOUSE_SPEED; }
        if (s_mouse_keys & MOUSE_KEY_UP)    { g_mouse_report.y += -MOUSE_SPEED; }
        if (s_mouse_keys & MOUSE_KEY_DOWN)  { g_mouse_report.y += +MOUSE_SPEED; }

        if (s_mouse_keys & MOUSE_KEY_WHEEL_LEFT)  { g_mouse_report.wheel_x += -MOUSE_WHEEL_SPEED; }
        if (s_mouse_keys & MOUSE_KEY_WHEEL_RIGHT) { g_mouse_report.wheel_x += +MOUSE_WHEEL_SPEED; }
        if (s_mouse_keys & MOUSE_KEY_WHEEL_UP)    { g_mouse_report.wheel_y += +MOUSE_WHEEL_SPEED; }
        if (s_mouse_keys & MOUSE_KEY_WHEEL_DOWN)  { g_mouse_report.wheel_y += -MOUSE_WHEEL_SPEED; }

        // Now that we have updated, we can remove the button release keys.
        if (s_num_mouse_keys_to_release >= s_num_mouse_keys_down) {
            s_num_mouse_keys_down = 0;
        } else {
            s_num_mouse_keys_down -= s_num_mouse_keys_to_release;
        }
        s_num_mouse_keys_to_release = 0;

        g_report_pending_mouse = true;
        s_report_time = timer_read8_ms();
    }

    return s_mouse_keys;
}

XRAM keycode_callbacks_t mouse_keycodes = {
    .checker = is_mouse_keycode,
    .handler = handle_mouse_keycode,
};

