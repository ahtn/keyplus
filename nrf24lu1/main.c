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

    hardware_init();
    settings_load_from_flash();
    aes_key_init(g_settings.rf.ekey, g_settings.rf.dkey);
    timer_init();
    led_init();
    usb_init();
    rf_init_receive();
    keyboards_init();
    reset_usb_reports();
}

// TODO: remove later
// #include "usb/hid/hut_consumer.h"

void main(void) {
    dongle_init();

    // TODO: make this controlable by USB commands
    // unifying pairing options
    /* set_pairing_address(g_settings.pipe_addr_1, g_settings.pipe_addr_4); */

    // enable all interrupts
    EA = 1;

    rf_enable_receive_irq();

    while (true) {
        wdt_kick();

        // need to add unifying task back in
        /* // next handle data received over RF */
        /* if (g_rf_unifying_mouse_poll) { */
        /*  unifying_pairing_poll(); */
        /*  continue; */
        /* } else { */
        /*  has_rf_message = rf_task(); */
        /* } */

        rf_task();

        interpret_all_keyboard_matrices();

        macro_task();

        unifying_mouse_handle();
        send_keyboard_report();
        send_media_report();
        send_mouse_report();
        send_vendor_report();

        handle_vendor_out_reports();

        sticky_key_task();
        hold_key_task();

    }
}
