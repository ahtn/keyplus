// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/vendor_report.h"

#include "core/error.h"
#include "core/debug.h"

// TODO: would be much nicer to have a buffered/pipe interfaces for accessing
// the vendor report.
// TODO: put this into an init function
XRAM vendor_report_t g_vendor_report_in;
XRAM vendor_report_t g_vendor_report_out;

#if USB_BUFFERED
XRAM ring_buf128_type s_vendor_buffer_in;
XRAM ring_buf128_type s_vendor_buffer_out;
#endif

#include "core/ring_buf.h"

void reset_vendor_report(void) {
    g_vendor_report_in.len = 0;
    g_vendor_report_out.len = 0;
#if USB_BUFFERED
    ring_buf128_clear(&s_vendor_buffer_in);
    ring_buf128_clear(&s_vendor_buffer_out);
#endif
}

/*********************************************************************
 *                           buffered usb                            *
 *********************************************************************/

#if USB_BUFFERED
void vendor_out_write_byte(uint8_t byte) {
    ring_buf128_put(&s_vendor_buffer_out, byte);
}

void vendor_out_write_buf(const XRAM uint8_t* data, uint8_t length) {
    uint8_t i;
    for (i = 0; i < length; ++i) {
        vendor_out_write_byte(data[i]);
    }
}


uint8_t vendor_out_get_byte(void) {
    return ring_buf128_get(&s_vendor_buffer_out);
}

void vendor_out_load_packet(void) {
    const uint8_t packet_len = vendor_out_get_byte();
    if (ring_buf128_len(&s_vendor_buffer_out) < packet_len) {
        ring_buf128_clear(&s_vendor_buffer_out);
        return;
    }
    ring_buf128_take(&s_vendor_buffer_out, g_vendor_report_out.data, packet_len);
    g_vendor_report_out.len = packet_len;
}

uint8_t vendor_out_buf_has_packet(void) {
    return ring_buf128_has_data(&s_vendor_buffer_out);
}


void vendor_in_write_byte(uint8_t byte) {
    ring_buf128_put(&s_vendor_buffer_in, byte);
}

void vendor_in_write_buf(const XRAM uint8_t* data, uint8_t length) {
    uint8_t i;
    for (i = 0; i < length; ++i) {
        vendor_in_write_byte(data[i]);
    }
}

uint8_t vendor_in_get_byte(void) {
    return ring_buf128_get(&s_vendor_buffer_in);
}

void vendor_in_load_packet(void) {
    uint8_t packet_len;

    if (g_vendor_report_in.len != 0) {
        // packet already queued
        return;
    }

    packet_len = vendor_in_get_byte();

    if (ring_buf128_len(&s_vendor_buffer_in) < packet_len) {
        ring_buf128_clear(&s_vendor_buffer_in);
        register_error(11);
        return;
    };

    if (packet_len > EP_SIZE_VENDOR) {
        ring_buf128_clear(&s_vendor_buffer_in);
        register_error(12);
        return;
    }

    ring_buf128_take(&s_vendor_buffer_in, g_vendor_report_in.data, packet_len);
    g_vendor_report_in.len = packet_len;
}

uint8_t vendor_in_buf_has_packet(void) {
    return ring_buf128_has_data(&s_vendor_buffer_in);
}

uint8_t vendor_in_free_space(void) {
    return ring_buf128_free_space(&s_vendor_buffer_in);
}

#endif

/*********************************************************************
 *                          unbuffered usb                           *
 *********************************************************************/

#if !USB_BUFFERED

#include <string.h>
uint8_t vendor_in_free_space(void) {
    return VENDOR_REPORT_LEN;
}

void vendor_in_write_byte(uint8_t byte) {
    assert(g_vendor_report_in.len < VENDOR_REPORT_LEN);
    g_vendor_report_in.data[g_vendor_report_in.len++] = byte;
}

void vendor_in_write_buf(const XRAM uint8_t* data, uint8_t length) {
    assert(length < VENDOR_REPORT_LEN);
    memcpy(g_vendor_report_in.data, data, length);
    g_vendor_report_in.len = length;
}

void vendor_out_write_byte(uint8_t byte) {
    assert(g_vendor_report_out.len < VENDOR_REPORT_LEN);
    g_vendor_report_out.data[g_vendor_report_out.len++] = byte;
}
#endif

