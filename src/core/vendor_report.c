// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/vendor_report.h"

// TODO: would be much nicer to have a buffered/pipe interfaces for accessing
// the vendor report.
// TODO: put this into an init function
XRAM vendor_report_t g_vendor_report_in;
XRAM vendor_report_t g_vendor_report_out;

void reset_vendor_report(void) {
    g_vendor_report_in.len = 0;
    g_vendor_report_out.len = 0;
}
