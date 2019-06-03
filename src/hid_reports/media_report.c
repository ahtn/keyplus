// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)
/// @file

// TODO: It would be benefical to treat the CONSUMER and SYSTEM reports as
// separate reports. However, it is low priority as it will only be an issue
// if CONSUMER and SYSTEM reports are being sent at the same time which is
// unlikely.

#include "hid_reports/media_report.h"

#include <string.h>

#include "hid_reports/usb_reports.h"
#include "hid_reports/ble_reports.h"
#include "hid_reports/virtual_reports.h"

#include "core/settings.h"

#if defined(USE_USB) && USE_USB
#include "usb/descriptors.h"
#endif

XRAM hid_report_media_t g_media_report;

bit_t g_report_pending_media = false;

/// @brief Mark the mouse report as modified and needs an update.
void touch_media_report(void) {
    g_report_pending_media = true;
}

/// @brief Reset the media report to its start-up state.
void reset_media_report(void) {
    g_media_report.report_id = 0;
    g_media_report.code = 0;
    g_report_pending_media = false;
}

#if USE_USB
bit_t is_ready_media_report(void) {
    return is_in_endpoint_ready(EP_NUM_MEDIA);
}
#endif

bit_t send_media_report(void) {
    if (!g_report_pending_media) {
        return false;
    }

#if USE_VIRTUAL_MODE
    kp_virtual_hid_media_report_send();
    g_report_pending_media = false;
    return false;
#endif

#if USE_BLUETOOTH
    if (g_runtime_settings.mode == TRANS_MODE_BLE) {
        // The media report is slightly different for Bluetooth and USB.
        // By default the code uses the USB Report IDs, so here we translate them
        // to their Bluetooth version.
        //
        // Also, the Bluetooth HID API doesn't include the HID report ID in the
        // packet, so we leave it out.
        uint8_t report_index = 0;
        switch (g_media_report.report_id) {
            case REPORT_ID_CONSUMER: { report_index = BLE_INPUT_REPORT_INDEX_CONSUMER; } break;
            case REPORT_ID_SYSTEM:   { report_index = BLE_INPUT_REPORT_INDEX_SYSTEM; } break;
            default: { return true; } break;
        }
        kp_ble_hids_input_report_send(
            report_index,
            sizeof(uint16_t),
            (uint8_t*)&g_media_report.code
        );
        reset_media_report();
        return false;
    }
#endif

#if USE_USB
    if (is_ready_media_report()) {
        const uint8_t report_size = sizeof(hid_report_media_t);

        usb_write_in_endpoint(
            EP_NUM_MEDIA,
            (uint8_t*)&g_media_report,
            report_size
        );

        reset_media_report();
        return false;
    } else {
        return true;
    }
#endif
}
