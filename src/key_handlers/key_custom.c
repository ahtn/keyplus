// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "key_handlers/key_custom.h"

#include "config.h"

#include "core/hardware.h"
#include "core/keycode.h"
#include "core/rf.h"
#include "core/settings.h"
#include "core/unifying.h"
#include "core/usb_commands.h"

#include "hid_reports/mouse_report.h"
#include "hid_reports/keyboard_report.h"
#include "hid_reports/media_report.h"

#include "usb/util/hut_consumer.h"
#include "usb/util/hut_desktop.h"

static bit_t keycode_checker(keycode_t keycode) {
    return ( KC_DONGLE_0 <= keycode && keycode <= KC_TEST_7);
}

static uint8_t s_hid_code;
static uint16_t s_consumer;
static uint8_t s_system;

/* TODO:  */
static void handler(keycode_t keycode, key_event_t event) REENT {
    if (event == EVENT_RESET) {
        s_hid_code = 0;
        s_consumer = HID_CONSUMER_CONSUMER_CONTROL;
        // s_consumer = HID_CONSUMER_GENERIC_GUI_APPLICATION_CONTROLS;
        s_system = HID_DESKTOP_Pointer;
    }

    switch (keycode) {

        // test keyboard hid codes
        case KC_TEST_0: {
            if (event == EVENT_PRESSED) {
                // skip problematic keys
                if (s_hid_code == KC_POWER) {
                    s_hid_code++;
                }
                add_keycode(s_hid_code);
            } else if (EVENT_RELEASED) {
                del_keycode(s_hid_code);
                s_hid_code++;
            }
        } break;

        // test keyboard consumer codes
        case KC_TEST_1: {
            if (event == EVENT_PRESSED) {
                g_media_report.report_id = REPORT_ID_CONSUMER;
                g_media_report.code = s_consumer;
                touch_media_report();
            } else if (EVENT_RELEASED) {
                g_media_report.report_id = REPORT_ID_CONSUMER;
                g_media_report.code = 0;
                touch_media_report();
                s_consumer++;
            }
        } break;

        // test keyboard consumer codes
        case KC_TEST_2: {
            if (event == EVENT_PRESSED) {
                g_media_report.report_id = REPORT_ID_SYSTEM;
                g_media_report.code = s_system;
                touch_media_report();
            } else if (EVENT_RELEASED) {
                g_media_report.report_id = REPORT_ID_SYSTEM;
                g_media_report.code = 0;
                touch_media_report();
                s_system++;
            }
        } break;

        case KC_BOOTLOADER: {
            bootloader_jmp();
        } break;

        case KC_RESET: {
            reset_mcu();
        } break;

#if USE_UNIFYING
        case KC_UNIFYING_PAIR: {
            if (event == EVENT_PRESSED) {
                unifying_begin_pairing();
            }
            return;
        } break;
#endif

    }

// #if USE_NRF24
#if 0
    // TODO: move this to extended keycode type
    if (is_dongle_key(keycode) && event == EVENT_PRESSED) {
        const uint8_t id = keycode - KC_DONGLE_0;
        if (id == GET_SETTING(device_id)) {
            rf_auto_ack(true);
        } else {
            rf_auto_ack(false);
            keyboard_reset_matrix(0 /*TODO*/);
            reset_mouse_report();
        }
    }
#endif

}

XRAM keycode_callbacks_t custom_keycodes = {
    .checker = keycode_checker,
    .handler = handler,
    .active_when_disabled = true,
};
