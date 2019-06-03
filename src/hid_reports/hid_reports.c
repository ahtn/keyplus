// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "hid_reports/hid_reports.h"

#if USE_VIRTUAL_MODE
#include "hid_reports/virtual_reports.h"
#endif

void reset_hid_reports(void) {
    reset_keyboard_reports();
    reset_mouse_report();
    reset_media_report();
#if USE_VIRTUAL_MODE
    // don't support vendor report
#else
    reset_vendor_report();
#endif

#if USE_VIRTUAL_MODE
    kp_virtual_hid_reports_reset();
#endif
}

void send_hid_reports(void) {
    send_keyboard_report();
    send_mouse_report();
    send_media_report();
#if USE_VIRTUAL_MODE
    // don't support vendor report
#else
    send_vendor_report();
#endif
}
