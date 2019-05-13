// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "hid_reports/hid_reports.h"

void reset_hid_reports(void) {
    reset_media_report();
    reset_vendor_report();
    reset_mouse_report();
    reset_keyboard_reports();
}

void send_hid_reports(void) {
    send_keyboard_report();
    send_mouse_report();
    send_media_report();
    send_vendor_report();
}
