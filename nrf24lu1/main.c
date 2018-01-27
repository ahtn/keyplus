// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

// TODO: caps_lock / scroll_lock / num_lock / kana_lock handling
// TODO: Abstract hardware specific functions

#include <string.h>

#include "config.h"

#include "nrf24lu1.h"

#include "core/usb_commands.h"
#include "core/unifying.h"

#include "core/keyboard_report.h"
#include "core/media_report.h"
#include "core/mouse_report.h"
#include "core/vendor_report.h"

#include "core/aes.h"
#include "core/error.h"
#include "core/hardware.h"
#include "core/led.h"
#include "core/matrix_interpret.h"
#include "core/rf.h"
#include "core/settings.h"
#include "core/timer.h"
#include "core/util.h"

#include "usb/common.h"

// Include these isr function prototypes here so that the compiler adds
// them to the interrupt vector table.
void t2_isr(void) __interrupt (ISR_T2);
void usb_isr(void) __interrupt (ISR_USB_INT);
void nrf24lu1_rf_isr(void) __interrupt (ISR_RFIRQ);

// TODO: cleanup init code
void dongle_init(void) {
    wdt_init();
    init_error_system();

    hardware_init();
    timer_init();
    led_init();

    settings_load_from_flash();
    if (!has_critical_error()) {
        aes_key_init(g_rf_settings.ekey, g_rf_settings.dkey);
        rf_init_receive();
        keyboards_init();
    }

    usb_init();
    reset_usb_reports();
}

// TODO: remove later
// #include "usb/hid/hut_consumer.h"

void main(void) {
    dongle_init();

    // enable all interrupts
    EA = 1;

    while (true) {
        wdt_kick();

    if (!g_input_disabled && !has_critical_error()) {
            if (unifying_is_pairing_active()) {
                unifying_pairing_poll();
            } else {
                rf_task();
            }

            interpret_all_keyboard_matrices();

            macro_task();

            unifying_mouse_handle();
            send_keyboard_report();
            send_media_report();
            send_mouse_report();

            sticky_key_task();
            hold_key_task();
        }

        if (g_error_code_table[0] == 0xff) {
            led_testing_set(1);
        } else {
            led_testing_set(0);
        }
        send_vendor_report();
        handle_vendor_out_reports();
    }
}
