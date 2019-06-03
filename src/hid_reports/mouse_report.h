// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include "core/util.h"

/* TODO: move this to a flash settings */
#ifndef MOUSE_SMOOTH_SCROOL
#define MOUSE_SMOOTH_SCROLL 0
#endif

#if USE_USB
#include "usb/descriptors.h"
#endif

// TODO: Should probably make this compatiable with a HID boot mouse

// this is what the data that we send to the host is comprised of
typedef struct hid_report_mouse_t {
#ifdef SHARED_HID_DESCRIPTOR
    uint8_t report_id;
#endif
    uint8_t buttons_1;
    uint8_t buttons_2;
    int16_t x;
    int16_t y;
    int8_t wheel_y;
    int8_t wheel_x;
} ATTR_PACKED hid_report_mouse_t;

extern XRAM hid_report_mouse_t g_mouse_report;
extern bit_t g_report_pending_mouse;

void reset_mouse_report(void);
void touch_mouse_report(void);

int16_t sign_extend_12(uint16_t x);
int16_t sign_extend_8(uint8_t x);

bit_t is_ready_mouse_report(void);
bit_t send_mouse_report(void);
