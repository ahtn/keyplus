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

#include "core/usb_commands.h"
#include "usb_reports/vendor_report.h"

/// USB interrupt handler
void usb_isr(void) __interrupt (USB0_IRQn);

/// Setup io pins
static void io_init() {
    // P0    -  Skipped,     Open-Drain, Digital
    // P1    -  Skipped,     Open-Drain, Digital
    // P2.2  -  Unassigned,  Push-Pull,  Digital
    // P2.3  -  Unassigned,  Push-Pull,  Digital

#if defined(EFM8UB2_DEVICE)
    // P0MDIN    = 0;
    // P1MDIN    = 0;
    // P2MDIN    = 0;
    // P1MDOUT   = 0;
    // P2MDOUT   = 0;
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

void main(void) {
    setup();

    while (1) {
        handle_vendor_out_reports();
        send_vendor_report();
    }
}

