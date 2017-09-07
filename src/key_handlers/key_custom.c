// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "key_custom.h"

#include "config.h"

#include "core/usb_commands.h"

#include "core/keyboard_report.h"
#include "core/keycode.h"
#include "core/matrix_interpret.h"
#include "core/mouse_report.h"
#include "core/rf.h"
#include "core/settings.h"

#if 1

static const ROM char msg[] = "hello world\n";
#ifndef AVR
// TODO: integrate this into the handling as rf receiver
static bit_t enabled = false;
#endif

static bit_t is_test_key(keycode_t keycode) {
    return ( keycode >= KC_TEST_0 && keycode <= KC_TEST_7 );
}

static bit_t is_dongle_key(keycode_t keycode) {
    return ( keycode >= KC_DONGLE_0 && keycode <= KC_DONGLE_7 );
}

static bit_t keycode_checker(keycode_t keycode) {
    return is_test_key(keycode) || is_dongle_key(keycode);
}


/* TODO:  */
static void handler(keycode_t keycode, key_event_t event) REENT {
    if (is_test_key(keycode)) {
        switch (keycode) {
            case KC_TEST_3: {
                if (event == EVENT_PRESSED) {
                    usb_print((uint8_t *)msg, sizeof(msg));
                }
            } break;

            case KC_TEST_4: {
                if (event == EVENT_PRESSED) {
                    // run_macro(0);
                }
            } break;

            default:
                break;
        }
        return;
    }

#if USE_NRF24
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

#endif
