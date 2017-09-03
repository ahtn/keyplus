// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/media_report.h"

#include <string.h>

#include "usb/descriptors.h"

XRAM hid_report_media_t g_media_report;

/* TODO: media keycode handling, move to separate file */
bit_t g_report_pending_media = false;

void reset_media_report(void) {
    g_media_report.id = 0;
    g_media_report.code = 0;
}
