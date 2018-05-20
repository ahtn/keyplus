// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)
/// @file main.c
///
/// Keyplus EFM8 main loop
#include <string.h>

#include "efm8_util/io.h"
#include "efm8_util/delay.h"

#include "peripheral_driver/inc/wdt_0.h"

#include "usb_test.h"
#include "efm8_port_util.h"

#include "core/error.h"
#include "core/hardware.h"
#include "core/io_map.h"
#include "core/keycode.h"
#include "core/macro.h"
#include "core/matrix_interpret.h"
#include "core/settings.h"
#include "core/timer.h"
#include "core/usb_commands.h"

#include "key_handlers/key_mouse.h"
#include "key_handlers/key_hold.h"

#include "usb_reports/keyboard_report.h"
#include "usb_reports/mouse_report.h"
#include "usb_reports/media_report.h"
#include "usb_reports/vendor_report.h"

/// USB interrupt handler
void usb_isr(void) __interrupt (USB0_IRQn);

/// Timer 0 interrupt handler
void t0_isr(void) __interrupt (TIMER0_IRQn);

/// Setup io pins
static void io_init() {
    efm8_reset_ports();
    P0SKIP    = 0xFF;
    P1SKIP    = 0xFF;
#if defined(EFM8UB2_DEVICE)
    P2SKIP    = 0xFF;
#endif

#if defined(EFM8UB2_DEVICE)
    XBR1      = XBR1_XBARE__ENABLED;
#elif defined(EFM8UB1_DEVICE) || defined(EFM8UB3_DEVICE)
    XBR2    = XBR2_XBARE__ENABLED;
#else
    #error "device family not defined"
#endif

}

/// Setup oscillator and flash read timings
static void oscillator_init() {
#if defined(EFM8UB2_DEVICE)
    // Flash settings
    FLSCL  = (
        FLSCL_FOSE__ENABLED
        | FLSCL_FLRT__SYSCLK_BELOW_48_MHZ
    );
    // Clock settings
    CLKSEL = CLKSEL_CLKSL__HFOSC;
#elif defined(EFM8UB1_DEVICE) | defined(EFM8UB3_DEVICE)
    SFRPAGE = PG2_PAGE;
    // Enable the flash prefetch engine, required for clock >25MHz
    PFE0CN = (
        PFE0CN_FLRT__BMASK
        | PFE0CN_FLRT__SYSCLK_BELOW_50_MHZ
    );
    // Clock settings
    CLKSEL = CLKSEL_CLKSL__HFOSC1;
    SFRPAGE = 0;
#endif

    // NOTE: Assumes SFRPAGE = 0x00
    // TODO: probably just make this always enabled at setup after power on
#if defined(DEVICE_EFM8UB1) || defined(DEVICE_EFM8UB2) || defined(DEVICE_EFM8UB3)
    // Enable VDD monitor and set it as a reset source
    // So if a VDD is not stable will result in reset protecting against flash
    // corruption.
    VDM0CN |= VDM0CN_VDMEN__ENABLED;
    RSTSRC = RSTSRC_PORSF__SET;
#endif

}

void _sdcc_external_startup (void) {
    WDT0_stop(); // disable the watch dog
}

/// Setup code
void setup(void) {
    oscillator_init();
    io_init();

    hardware_init();
    timer_init();
    usb_init();

    software_reset();

    // Disable interrupts
    IE_EA = 1;
}

/// When we encounter a critical error, stop all other features and only
/// enable those necessary to load a new valid layout.
void recovery_mode_main_loop(void) {
    while (1) {
        // usb out reports
        send_vendor_report();
        handle_vendor_out_reports();
        wdt_kick();
        efm8_delay_ms(2);
    }
}

void main(void) {
    uint8_t state = 0;
    setup();

    while (1) {
        uint8_t scan_changed;

        if (has_critical_error()) {
            recovery_mode_main_loop();
        }

        scan_changed = matrix_scan();

        // TODO: need to clean this up
        if (scan_changed) {
            XRAM uint8_t matrix_data[32];
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
        hold_key_task(false);

        wdt_kick();
        // efm8_delay_ms(2);
    }
}
