// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "hid_reports/mouse_report.h"

#include "core/settings.h"

#if defined(USE_USB) && USE_USB
#include "usb/descriptors.h"
#endif

#include "hid_reports/usb_reports.h"
#include "hid_reports/ble_reports.h"
#include "hid_reports/virtual_reports.h"

#include <string.h>

/// The HID mouse report
XRAM hid_report_mouse_t g_mouse_report;

/// Set to true if a mouse report is pending.
bit_t g_report_pending_mouse = false;

/// @brief Convert a 16 bit signed value into a 16 bit signed value.
///
/// @return A 16 bit signed value
int16_t sign_extend_12(uint16_t x) {
    return ((x & 0x0800) ? (x | 0xf000) : x);
}

/// @brief Convert a 8 bit signed value into a 16 bit signed value.
///
/// @return A 16 bit signed value
int16_t sign_extend_8(uint8_t x) {
    return ((x & 0x80) ? (x | 0xff00) : x);
}

/// @brief Reset the mouse to its start-up state
void reset_mouse_report(void) {
    memset(&g_mouse_report, 0, sizeof(hid_report_mouse_t));
    // g_report_pending_mouse = true; // Set to true so that
#if SHARED_HID_DESCRIPTOR
    g_mouse_report.report_id = REPORT_ID_MOUSE;
#endif
}

/// @brief Mark the mouse report as modified and needs an update.
void touch_mouse_report(void) {
    g_report_pending_mouse = true;
}

#if USE_USB
/// @brief Check if the HID endpoint for MOUSE reports is ready
bit_t is_ready_mouse_report(void) {
    return is_in_endpoint_ready(EP_NUM_MOUSE);
}
#endif

static void zero_mouse(void) {
    { // Zero the mouse movement component now that the packet is sent
        g_mouse_report.x = 0;
        g_mouse_report.y = 0;
        g_mouse_report.wheel_x = 0;
        g_mouse_report.wheel_y = 0;
    }

    g_report_pending_mouse = false;
}

/// @brief Send any pending mouse report.
///
/// @retval true A mouse report is ready but could not be sent and was left pending.
/// @retval false No mouse report was left pending.
bit_t send_mouse_report(void) {
    if (!g_report_pending_mouse) {
        return false;
    }

#if USE_VIRTUAL_MODE
    kp_virtual_hid_mouse_report_send();
    zero_mouse();
    return false;
#endif

#if USE_BLUETOOTH
    if (g_runtime_settings.mode == TRANS_MODE_BLE) {
        kp_ble_hids_input_report_send(
            BLE_INPUT_REPORT_INDEX_MOUSE,
            sizeof(hid_report_mouse_t),
            (uint8_t*)&g_mouse_report
        );
        zero_mouse();
        return false;
    }
#endif

#if USE_USB
    if (is_ready_mouse_report()) {
        uint8_t report_size = sizeof(hid_report_mouse_t);

        usb_write_in_endpoint(
            EP_NUM_MOUSE,
            (uint8_t*)&g_mouse_report,
            report_size
        );
        zero_mouse();
        return false;
    } else {
        return true;
    }
#endif
}
