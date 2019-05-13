// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "hid_reports/vendor_report.h"

#include "config.h"

#include "core/settings.h"
#include "core/error.h"
#include "core/debug.h"

#include "hid_reports/usb_reports.h"
#include "hid_reports/ble_reports.h"

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

bit_t is_ready_vendor_in_report(void) {
    return is_in_endpoint_ready(EP_NUM_VENDOR_IN);
}

bit_t send_vendor_report(void) {
#if USB_BUFFERED
    if (g_vendor_report_in.len == 0 && vendor_in_buf_has_packet()) {
        vendor_in_load_packet();
    }
#endif

    if (g_vendor_report_in.len == 0) {
        return false;
    }

#if USE_BLUETOOTH
    if (g_runtime_settings.mode == TRANS_MODE_BLE) {
        kp_ble_hids_input_report_send(
            BLE_INPUT_REPORT_INDEX_VENDOR,
            VENDOR_REPORT_LEN,
            g_vendor_report_in.data
        );
        g_vendor_report_in.len = 0;
        return false;
    }
#endif

    if (is_ready_vendor_in_report()) {
        // Send the vendor report
        usb_write_in_endpoint(
            EP_NUM_VENDOR_IN,
            g_vendor_report_in.data,
            VENDOR_REPORT_LEN
        );
        g_vendor_report_in.len = 0;
        return false;
    } else {
        return true;
    }
}

bit_t is_ready_vendor_out_report(void) {
    return is_out_endpoint_ready(EP_NUM_VENDOR_OUT);
}

uint8_t read_vendor_report(void) {
#if USE_BLUETOOTH
    if (g_runtime_settings.mode == TRANS_MODE_BLE) {
        if (!kp_ble_hids_output_has_data(BLE_OUTPUT_REPORT_INDEX_VENDOR)) {
            return 1;
        }

        kp_ble_hids_output_report_read(
            BLE_OUTPUT_REPORT_INDEX_VENDOR,
            VENDOR_REPORT_LEN,
            g_vendor_report_out.data
        );
        return 0;
    }
#endif

    if (!is_ready_vendor_out_report()) {
        return 1;
    }

    usb_read_out_endpoint(
        EP_NUM_VENDOR_OUT,
        g_vendor_report_out.data,
        &g_vendor_report_out.len
    );

    return 0;
}
