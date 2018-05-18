// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)
/// @file main.c
///
/// Keyplus EFM8 main loop
#include "efm8_sfr.h"

#include <string.h>

#include "efm8_util/delay.h"
#include "peripheral_driver/inc/wdt_0.h"

#include "usb_test.h"

#include "core/hardware.h"

#include "core/usb_commands.h"

#include "core/keycode.h"

#include "usb_reports/keyboard_report.h"
#include "usb_reports/mouse_report.h"
#include "usb_reports/vendor_report.h"

/// USB interrupt handler
void usb_isr(void) __interrupt (USB0_IRQn);

/// Setup io pins
static void io_init() {
#if defined(EFM8UB2_DEVICE)
    // P0MDIN    = 0;
    // P1MDIN    = 0;
    // P2MDIN    = 0;
    // P0MDOUT   = 0;
    // P1MDOUT   = 0;
    // P2MDOUT   = 0;

    // P0MDIN    = 0;
    // P1MDIN    |= PIN7_bm | PIN6_bm;
    // P2MDIN    |= PIN1_bm | PIN0_bm;
    // P0MDOUT   = 0;
    // P1MDOUT   = 0;
    P2MDOUT   |= PIN3_bm | PIN2_bm;
    P0SKIP    = 0xFF;
    P1SKIP    = 0xFF;
    P2SKIP    = 0xFF;
    XBR1      = XBR1_XBARE__ENABLED;
// #elif DEVICE_PKG_QFN20
#elif defined(EFM8UB1_DEVICE) || defined(EFM8UB3_DEVICE)
    // All PxMDIN, PxMDOUT, PxSKIP, XBRx are all on PG3 on these micros
    SFRPAGE = PG3_PAGE;
    // P0MDOUT = 0;
    // P1MDIN  = PIN2_bm;
    P0SKIP  = 0xFF;
    P1SKIP  = 0xFF;
    XBR2    = XBR2_XBARE__ENABLED;
    SFRPAGE = 0;
#else
#  error "device family not defined"
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
}

void _sdcc_external_startup (void) {
    WDT0_stop(); // disable the watch dog
}

/// Setup code
void setup(void) {
    oscillator_init();
    io_init();

    reset_usb_reports();

    usb_init();

    // Disable interrupts
    IE_EA = 1;
}

#define BUTTON0 P1_B6
#define BUTTON1 P1_B7
#define BUTTON2 P2_B0
#define BUTTON3 P2_B1

#if defined(EFM8UB2_DEVICE)
  #define LED0 P2_B2
  #define LED1 P2_B3
#elif defined(EFM8UB1_DEVICE) || defined(EFM8UB3_DEVICE)
  #define LED0 P0_0
  #define LED1 P0_1
#endif

void main(void) {
    uint8_t state = 0;
    setup();

    LED0 = 0;
    LED1 = 1;

    set_keyboard_report_mode(KEYBOARD_REPORT_MODE_NKRO);

    while (1) {
        if (BUTTON2 & state == 0) {
            state = 1;
            LED0 = 1;
            del_keycode(KC_A);

            g_mouse_report.x = 0;
            touch_mouse_report();

            static_delay_ms(10);
        } else if (!BUTTON2 & state == 1) {
            state = 0;
            LED0 = 0;
            add_keycode(KC_A);

            g_mouse_report.x = 100;
            touch_mouse_report();

            static_delay_ms(10);
        }

        send_keyboard_report();
        send_mouse_report();

        handle_vendor_out_reports();
        send_vendor_report();
    }
}

