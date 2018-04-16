// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

// TODO: caps_lock / scroll_lock / num_lock / kana_lock handling
// TODO: Abstract hardware specific functions

#include <string.h>

#include "config.h"

#include "nrf24lu1.h"

#include "core/usb_commands.h"
#include "core/unifying.h"

#include "core/aes.h"
#include "core/error.h"
#include "core/hardware.h"
#include "core/led.h"
#include "core/matrix_interpret.h"
#include "core/rf.h"
#include "core/settings.h"
#include "core/timer.h"
#include "core/util.h"

#include "core/macro.h"
#include "key_handlers/key_hold.h"
#include "key_handlers/key_mouse.h"

#include "usb_reports/keyboard_report.h"
#include "usb_reports/media_report.h"
#include "usb_reports/mouse_report.h"
#include "usb_reports/vendor_report.h"

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

// NOTE: we use these functions to disable the RF and USB interrupt service
// routines. The main reason for doing this is that the 8051 has a very limited
// stack space. If these interrupt routines are triggered while the CPU is in a
// deeply nested function call, then a stack over flow is likely to occur. So
// before calling any function that needs to use a lot of stack space, these
// functions should be used.
//
// NOTE: We only use 3 interrupts on the nRF24LU1+:
// * USB_IRQ
// * RF_IRQ
// * T2_IRQ
// We leave the T2 interrupt alone, since it does not need as much stack space.
static void irq_off(void) {
    USB_IRQEN = 0;
    rf_disable_receive_irq();
}

static void irq_on(void) {
    USB_IRQEN = 1;
    rf_enable_receive_irq();
}

void main(void) {
    dongle_init();

    // enable all interrupts
    EA = 1;

    while (true) {
        if (!g_input_disabled && !has_critical_error()) {
            {
                irq_off();
                interpret_all_keyboard_matrices();
                irq_on();
            }

            irq_off();
            if (unifying_is_pairing_active()) {
                unifying_pairing_poll();
            } else {
                rf_task();
            }
            irq_on();


            // Disable usb interrupt while processing USB events
            irq_off();
            {
                mouse_key_task();
                macro_task();

                // send reports
                unifying_mouse_handle();
                send_keyboard_report();
                send_media_report();
                send_mouse_report();

                // handle special key tasks
                sticky_key_task();
                hold_key_task();
            }
            irq_on();
        }

        // Disable usb interrupt while processing USB events
        irq_off();
        {
            send_vendor_report();
            handle_vendor_out_reports();
        }
        irq_on();

        wdt_kick();
    }
}
