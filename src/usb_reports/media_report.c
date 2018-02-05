// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "usb_reports/media_report.h"

#include <string.h>

#include "usb_reports/usb_reports.h"
#include "usb/descriptors.h"

XRAM hid_report_media_t g_media_report;

bit_t g_report_pending_media = false;

void reset_media_report(void) {
    g_media_report.id = 0;
    g_media_report.code = 0;
    g_report_pending_media = false;
}

static bit_t is_ready_media_report(void) {
    return is_in_endpoint_ready(EP_NUM_MEDIA);
}

bit_t send_media_report(void) {
    if (is_ready_media_report() && g_report_pending_media) {
        const uint8_t report_size = sizeof(hid_report_media_t);

        usb_write_in_endpoint(
            EP_NUM_MEDIA,
            (uint8_t*)&g_media_report,
            report_size
        );

        g_report_pending_media = false;
        return false;
    } else {
        return true;
    }
}
