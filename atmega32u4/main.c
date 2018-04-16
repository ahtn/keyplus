// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "usb_keyboard.h"
#include "usb_reports/keyboard_report.h"
#include "usb_reports/media_report.h"
#include "usb_reports/mouse_report.h"
#include "usb_reports/vendor_report.h"

#include "core/error.h"
#include "core/flash.h"
#include "core/hardware.h"
#include "core/macro.h"
#include "core/matrix_interpret.h"
#include "core/matrix_scanner.h"
#include "core/usb_commands.h"
#include "core/settings.h"
#include "core/timer.h"

#include "key_handlers/key_hold.h"
#include "key_handlers/key_mouse.h"

#include "bootloaders/kp_boot_32u4/interface/kp_boot_32u4.h"

#include "io_map/avr_port_util.h"


void pin_init(void) {
}

void setup_everything(void) {
    hardware_init();
    timer_init();
    io_map_init();
    pin_init();
    settings_load_from_flash();
#if USE_NRF24
    aes_key_init(g_rf_settings.ekey, g_rf_settings.dkey);
#endif
    matrix_scanner_init();
    reset_usb_reports();
    keyboards_init();
}

/// When we encounter a critical error, stop all other features and only
/// enable those necessary to load a new valid layout.
void recovery_mode_main_loop(void) {
    while (1) {
        // usb out reports
        send_vendor_report();
        handle_vendor_out_reports();
        wdt_kick();
    }
}

int main(void) {
    setup_everything();

    usb_init();
    sei();

    while (1) {
        _delay_ms(2);

        bool scan_changed = matrix_scan();

        // TODO: need to clean this up
        if (scan_changed) {
            uint8_t matrix_data[32];
            const uint8_t use_deltas = true;
            const uint8_t data_size = get_matrix_data(matrix_data, use_deltas);

            keyboard_update_device_matrix(GET_SETTING(device_id), matrix_data);
        }

        // passthrough_keycodes_task();
        interpret_all_keyboard_matrices();

        mouse_key_task();
        macro_task();

        send_keyboard_report();
        send_media_report();
        send_mouse_report();
        send_vendor_report();

        // usb out reports
        handle_vendor_out_reports();

        sticky_key_task();
        hold_key_task();

        if (has_critical_error()) {
            recovery_mode_main_loop();
        }

        wdt_kick();

    }
}
