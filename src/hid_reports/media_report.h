// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <stdint.h>
#include "core/util.h"

#if defined(USE_USB) && USE_USB
    #include "usb/descriptors.h"
#else
    #define REPORT_ID_SYSTEM 1
    #define REPORT_ID_CONSUMER 2
#endif

#include "usb/util/hut_consumer.h"
#include "usb/util/hut_desktop.h"
typedef struct hid_report_media_t {
    uint8_t report_id;
    uint16_t code;
} hid_report_media_t;

extern XRAM hid_report_media_t g_media_report;
extern bit_t g_report_pending_media;

void reset_media_report(void);
void touch_media_report(void);

bit_t send_media_report(void);
