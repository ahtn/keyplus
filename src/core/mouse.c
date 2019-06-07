// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/mouse.h"

#include <stdlib.h>

#include "core/layout.h"
#include "core/matrix_interpret.h"
#include "key_handlers/key_hold.h"

#include <stdio.h>

// TODO: should move this to an init function
XRAM hid_report_mouse_t g_mouse_state = {0};
XRAM uint8_t g_mouse_activity = 0;

#if USE_MOUSE_GESTURE
XRAM gesture_state_t s_gesture = {0};

void gesture_init(void) {
}

void gesture_press(uint16_t ekc_addr, uint8_t kb_id) {
    if (s_gesture.state == GESTURE_STATE_INACTIVE) {
        s_gesture.x = 0;
        s_gesture.y = 0;
        s_gesture.state = GESTURE_STATE_SCANNING;
        s_gesture.ekc_addr = ekc_addr;
        s_gesture.kb_id = kb_id;
        get_ekc_data(&s_gesture.threshold, s_gesture.ekc_addr, sizeof(uint16_t)*3);
    }
}

void gesture_release(uint16_t ekc_addr, uint8_t kb_id) {
    switch (s_gesture.state) {
        case GESTURE_STATE_SCANNING: {
            if (
                (abs(s_gesture.x) < s_gesture.threshold_tap) &&
                (abs(s_gesture.y) < s_gesture.threshold_tap)
            ) {
                // TAP
            }
            s_gesture.state = GESTURE_STATE_INACTIVE;
        } break;
        case GESTURE_STATE_ACTIVATED: {
            queue_keycode_event(s_gesture.triggered_kc, EVENT_RELEASED, s_gesture.kb_id);
            s_gesture.state = GESTURE_STATE_INACTIVE;
        } break;
    }
}

void trigger_gesture(uint8_t gesture_type) {
    // Gesture EKC data layout:
    //
    // typedef struct ekc_gesture_t {
    // 00:  uint16_t threshold;
    // 02:  uint16_t threshold_diag;
    // 04:  uint16_t threshold_tap;
    // 06:  keycode_t left;
    // 08:  keycode_t right;
    // 0A:  keycode_t up;
    // 0C:  keycode_t down;
    // 1E:  keycode_t up_left;
    // 10:  keycode_t up_right;
    // 12:  keycode_t down_left;
    // 14:  keycode_t down_right;
    // 16:  keycode_t tap;
    // } ekc_gesture_t;
    keycode_t gesture_kc;
    get_ekc_data(
        &gesture_kc,
        s_gesture.ekc_addr + EKC_GESTURE_LEFT_ADDR + gesture_type*2,
        sizeof(keycode_t)
    );

    queue_keycode_event(gesture_kc, EVENT_PRESSED, s_gesture.kb_id);

    s_gesture.state = GESTURE_STATE_ACTIVATED;
    s_gesture.triggered_kc = gesture_kc;
}
#endif

#if USE_VIRTUAL_MODE
void mouse_click(uint8_t buttons) {
    g_mouse_state.buttons_1 |= buttons;

    g_mouse_activity = UNIFYING_MOUSE_ACTIVE;
}

void mouse_unclick(uint8_t buttons) {
    g_mouse_state.buttons_1 &= ~buttons;

    g_mouse_activity = UNIFYING_MOUSE_ACTIVE;
}

void mouse_move(int16_t x, int16_t y, int8_t wheel_y, int8_t wheel_x) {
    g_mouse_state.x += x;
    g_mouse_state.y += y;
    g_mouse_state.wheel_y += wheel_y;
    g_mouse_state.wheel_x += wheel_x;

    g_mouse_activity = UNIFYING_MOUSE_ACTIVE;
}
#endif

static void zero_mouse_movement(void) {
    g_mouse_state.x = 0;
    g_mouse_state.y = 0;
    g_mouse_state.wheel_x = 0;
    g_mouse_state.wheel_y = 0;
}

void handle_mouse_events(void) REENT {
    if (!g_mouse_activity) {
        return;
    }

    if (has_active_slot() && has_mouse_layers(get_active_keyboard_id())) {
        update_mouse_matrix(g_mouse_state.buttons_1);
    } else {
        // If no keyboard layout is active, use default button mapping
        g_mouse_report.buttons_1 = g_mouse_state.buttons_1;
        g_mouse_report.buttons_2 = g_mouse_state.buttons_2;
        g_report_pending_mouse = true;

        if (g_mouse_report.buttons_1) {
            hold_key_task(true);
        }
    }

    if (g_mouse_report.buttons_1 || g_mouse_report.buttons_2) {
        // Allow mouse button presses to clear sticky mods
        clear_sticky_mods();
    }

    if (g_mouse_activity == UNIFYING_MOUSE_ACTIVE) {
        g_mouse_report.x = g_mouse_state.x;
        g_mouse_report.y = g_mouse_state.y;
        g_mouse_report.wheel_x = KP_SIGN(g_mouse_state.wheel_x);
        g_mouse_report.wheel_y = KP_SIGN(g_mouse_state.wheel_y);
        g_report_pending_mouse = true;
    } else if (g_mouse_activity == UNIFYING_MOUSE_EXTRA_BUTTON) {
        // If a special button was pressed don't want to update the cursor position.
        //
        // NOTE: x and y cleared automatically whenever a mouse report is sent
        // so no need to do it here
    }

#if USE_MOUSE_GESTURE
    // Gesture handling
    // if (g_mouse_state.buttons_1 & 0x80) {
    switch (s_gesture.state) {
        case GESTURE_STATE_SCANNING: {
            uint8_t has_pos_x, has_neg_x, has_pos_y, has_neg_y;

            s_gesture.x += g_mouse_state.x;
            s_gesture.y += g_mouse_state.y;

            // trigger threshold for diagonal motions
            has_pos_x = s_gesture.x >  s_gesture.threshold_diag;
            has_neg_x = s_gesture.x < -s_gesture.threshold_diag;
            has_pos_y = s_gesture.y >  s_gesture.threshold_diag;
            has_neg_y = s_gesture.y < -s_gesture.threshold_diag;

            if (has_neg_x && has_neg_y) {
                trigger_gesture(GESTURE_UP_LEFT);
            } else if (has_pos_x && has_neg_y) {
                trigger_gesture(GESTURE_UP_RIGHT);
            } else if (has_neg_x && has_pos_y) {
                trigger_gesture(GESTURE_DOWN_LEFT);
            } else if (has_pos_x && has_pos_y) {
                trigger_gesture(GESTURE_DOWN_RIGHT);
            } else if (s_gesture.x < -s_gesture.threshold) {
                trigger_gesture(GESTURE_LEFT);
            } else if (s_gesture.x > s_gesture.threshold) {
                trigger_gesture(GESTURE_RIGHT);
            } else if (s_gesture.y < -s_gesture.threshold) {
                trigger_gesture(GESTURE_UP);
            } else if (s_gesture.y >  s_gesture.threshold) {
                trigger_gesture(GESTURE_DOWN);
            }
        } break;
    }
#endif

    zero_mouse_movement();
    g_mouse_activity = 0;
}
