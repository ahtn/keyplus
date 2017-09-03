// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include "usb/descriptors.h"
#include "core/util.h"

#define VENDOR_REPORT_LEN EP_SIZE_VENDOR

typedef struct vendor_report_t {
    /* vendor_report_data_t data; */
    uint8_t data[VENDOR_REPORT_LEN];
    uint8_t len;
} vendor_report_t;

extern XRAM vendor_report_t g_vendor_report_in;
extern XRAM vendor_report_t g_vendor_report_out;

bit_t is_ready_vendor_in_report(void);
bit_t is_ready_vendor_out_report(void);
bit_t send_vendor_report(void);
uint8_t read_vendor_report(uint8_t *dest);
void reset_vendor_report(void);
