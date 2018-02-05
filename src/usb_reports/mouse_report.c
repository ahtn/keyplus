// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "usb_reports/mouse_report.h"

#include "usb_reports/usb_reports.h"
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

bit_t is_ready_mouse_report(void) {
    return is_in_endpoint_ready(EP_NUM_MOUSE);
}

bit_t send_mouse_report(void) {
    if (is_ready_mouse_report() && g_report_pending_mouse) {
        uint8_t report_size = sizeof(hid_report_mouse_t);

        usb_write_in_endpoint(
            EP_NUM_MOUSE,
            (uint8_t*)&g_mouse_report,
            report_size
        );

        g_report_pending_mouse = false;

        return false;
    } else {
        return true;
    }
}
