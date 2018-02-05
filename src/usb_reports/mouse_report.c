// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "usb_reports/mouse_report.h"

#include "usb/descriptors.h"

#include <string.h>

bit_t g_report_pending_mouse = false;
XRAM hid_report_mouse_t g_mouse_report;

int16_t sign_extend_12(uint16_t x) {
    return ((x & 0x0800) ? (x | 0xf000) : x);
}

int16_t sign_extend_8(uint8_t x) {
    return ((x & 0x80) ? (x | 0xff00) : x);
}

void reset_mouse_report(void) {
    memset(&g_mouse_report, 0, sizeof(hid_report_mouse_t));
}
