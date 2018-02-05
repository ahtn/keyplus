// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <stdint.h>
#include "core/util.h"

typedef struct {
    uint8_t id;
    uint16_t code;
} hid_report_media_t;

extern XRAM hid_report_media_t g_media_report;
extern bit_t g_report_pending_media;

void reset_media_report(void);

void usb_write_endpoint_in_data(
    uint8_t endpoint_num,
    uint8_t *data,
    uint8_t size
);

bit_t is_ready_media_report(void);
bit_t send_media_report(void);
