// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#if defined(USE_USB) && USE_USB
#include "usb/descriptors.h"
#endif

#include "core/util.h"

#include "core/ring_buf.h"

#include "config.h"

#ifdef EP_SIZE_VENDOR
    #define VENDOR_REPORT_LEN EP_SIZE_VENDOR
#else
    #define VENDOR_REPORT_LEN 64
#endif

typedef struct vendor_report_t {
    /* vendor_report_data_t data; */
    uint8_t data[VENDOR_REPORT_LEN];
    uint8_t len;
} ATTR_PACKED vendor_report_t;

extern XRAM vendor_report_t g_vendor_report_in;
extern XRAM vendor_report_t g_vendor_report_out;

bit_t is_ready_vendor_in_report(void);
bit_t is_ready_vendor_out_report(void);
bit_t send_vendor_report(void);
uint8_t read_vendor_report(void);
void reset_vendor_report(void);


#if USB_BUFFERED
void vendor_out_write_byte(uint8_t byte);
uint8_t vendor_out_get_byte(void);
void vendor_out_load_packet(void);
uint8_t vendor_out_buf_has_packet(void);

uint8_t vendor_in_get_byte(void);
void vendor_in_load_packet(void);
uint8_t vendor_in_buf_has_packet(void);
#endif

void vendor_in_write_byte(uint8_t byte);
uint8_t vendor_in_free_space(void);
void vendor_in_write_buf(const XRAM uint8_t* data, uint8_t length);
