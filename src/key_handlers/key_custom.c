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

#include "usb_reports/mouse_report.h"

static const ROM char msg[] = "hello world\n";

#if USE_NRF24
static bit_t is_dongle_key(keycode_t keycode) {
    return ( KC_DONGLE_0 <= keycode && keycode <= KC_DONGLE_7 );
}
#endif

static bit_t keycode_checker(keycode_t keycode) {
    return ( KC_DONGLE_0 <= keycode && keycode <= KC_TEST_7);
}

/* TODO:  */
static void handler(keycode_t keycode, key_event_t event) REENT {
    switch (keycode) {

        case KC_BOOTLOADER: {
            bootloader_jmp();
        } break;

        case KC_RESET: {
            reset_mcu();
        } break;

#if USE_NRF24
        case KC_UNIFYING_PAIR: {
            if (event == EVENT_PRESSED) {
                unifying_begin_pairing();
            }
            return;
        } break;
#endif

        case KC_TEST_3: {
            if (event == EVENT_PRESSED) {
                usb_print((uint8_t *)msg, sizeof(msg));
            }
            return;
        } break;

        case KC_TEST_4: {
            if (event == EVENT_PRESSED) {
                // run_macro(0);
            }
            return;
        } break;
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
