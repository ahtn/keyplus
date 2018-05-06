// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include "xmega/usb_xmega.h"

#define INTERFACE_VENDOR 0
#define EP_NUM_VENDOR 1
#define EP_SIZE_VENDOR 64
#define VENDOR_REPORT_LEN 64
#define REPORT_INTERVAL_VENDOR 0x01

#define EP_IN_BUF_VENDOR ep1_buf_in
#define BC_IN_VENDOR usb_xmega_endpoints[EP_NUM_VENDOR].in.CNT
#define EP_OUT_BUF_VENDOR ep1_buf_out
#define BC_OUT_VENDOR usb_xmega_endpoints[EP_NUM_VENDOR].out.CNT

typedef struct vendor_report_t {
    /* vendor_report_data_t data; */
    uint8_t data[VENDOR_REPORT_LEN];
    uint8_t len;
} vendor_report_t;

extern uint8_t ep1_buf_in[EP_SIZE_VENDOR];
extern uint8_t ep1_buf_out[EP_SIZE_VENDOR];

extern vendor_report_t g_vendor_report_in;
extern vendor_report_t g_vendor_report_out;

bool is_ready_vendor_in_report(void);
bool send_vendor_report(void);
bool is_ready_vendor_out_report(void);
uint8_t read_vendor_report(uint8_t *dest);
