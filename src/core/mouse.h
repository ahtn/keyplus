// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include "core/util.h"
#include "core/keycode.h"
#include "hid_reports/mouse_report.h"

typedef enum {
    UNIFYING_MOUSE_INACTIVE = 0x00,
    UNIFYING_MOUSE_ACTIVE = 0x01,
    UNIFYING_MOUSE_EXTRA_BUTTON = 0x02,
} unifying_mouse_activity_t;

enum {
    GESTURE_STATE_INACTIVE = 0,
    GESTURE_STATE_SCANNING = 1,
    GESTURE_STATE_ACTIVATED = 2,
};

enum {
    GESTURE_LEFT = 0,
    GESTURE_RIGHT = 1,
    GESTURE_UP = 2,
    GESTURE_DOWN = 3,
    GESTURE_UP_LEFT = 4,
    GESTURE_UP_RIGHT = 5,
    GESTURE_DOWN_LEFT = 6,
    GESTURE_DOWN_RIGHT = 7,
    GESTURE_TAP = 8,
};

#define EKC_GESTURE_LEFT_ADDR 0x06
typedef struct gesture_state_t {
    uint8_t state;
    int16_t x;
    int16_t y;
    uint8_t kb_id;
    uint16_t ekc_addr;
    keycode_t triggered_kc;
    int16_t threshold;
    int16_t threshold_diag;
    int16_t threshold_tap;
} gesture_state_t;

extern XRAM hid_report_mouse_t g_mouse_state;
extern XRAM uint8_t g_mouse_state_changed;
extern XRAM uint8_t g_mouse_activity;

#if USE_VIRTUAL_MODE
void mouse_click(uint8_t buttons);
void mouse_unclick(uint8_t buttons);
void mouse_move(int16_t x, int16_t y, int8_t wheel_y, int8_t wheel_x);
#endif

void gesture_init(void);
void gesture_press(uint16_t ekc_addr, uint8_t kd_id);
void gesture_release(uint16_t ekc_addr, uint8_t kd_id);

void handle_mouse_events(void) REENT;
