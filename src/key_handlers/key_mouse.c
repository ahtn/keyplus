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

#define MOUSE_SPEED 10
#define MOUSE_WHEEL_SPEED 1

/* TODO: proper mouse handling */
void handle_mouse_keycode(keycode_t kc, key_event_t event) REENT {
    hid_report_mouse_t mouse = {0};
    if (IS_MOUSEKEY_BUTTON(kc)) {
        if (event == EVENT_PRESSED) {
            mouse.buttons_1 |= (1 << MOUSEKEY_BUTTON_NUM(kc));
        } else {
            mouse.buttons_1 &= ~(1 << (MOUSEKEY_BUTTON_NUM(kc)));
        }
    } else if (kc >= KC_MOUSE_UP && kc <= KC_MOUSE_WH_RIGHT) {
        if (event == EVENT_PRESSED) {
            switch (kc) {
                case KC_MOUSE_UP:    { mouse.y += -MOUSE_SPEED; } break;
                case KC_MOUSE_DOWN:  { mouse.y += +MOUSE_SPEED; } break;
                case KC_MOUSE_LEFT:  { mouse.x += -MOUSE_SPEED; } break;
                case KC_MOUSE_RIGHT: { mouse.x += +MOUSE_SPEED; } break;

                case KC_MOUSE_WH_UP:    { mouse.wheel_y += +MOUSE_WHEEL_SPEED; } break;
                case KC_MOUSE_WH_DOWN:  { mouse.wheel_y += -MOUSE_WHEEL_SPEED; } break;
                case KC_MOUSE_WH_LEFT:  { mouse.wheel_x += +MOUSE_WHEEL_SPEED; } break;
                case KC_MOUSE_WH_RIGHT: { mouse.wheel_x += -MOUSE_WHEEL_SPEED; } break;
            }
        }
    }
    // TODO: don't overide external mouse state
    memcpy(&g_mouse_report, &mouse, sizeof(hid_report_mouse_t));
    g_report_pending_mouse = true;
}

XRAM keycode_callbacks_t mouse_keycodes = {
    .checker = is_mouse_keycode,
    .handler = handle_mouse_keycode,
};

