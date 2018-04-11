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
#include "core/flash.h"
#include "core/hardware.h"
#include "core/matrix_interpret.h"
#include "core/matrix_scanner.h"
#include "core/usb_commands.h"
#include "core/settings.h"

#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))

#include "bootloaders/kp_boot_32u4/interface/kp_boot_32u4.h"

int main(void) {
    // set for 16 MHz clock
    CPU_PRESCALE(0);

    wdt_reset();
    wdt_disable();

    DDRF |= _BV(7) | _BV(6);
    PORTF |= _BV(7) | _BV(6);

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

        send_vendor_report();
        handle_vendor_out_reports();
        wdt_kick();
    }
}
