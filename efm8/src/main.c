// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)
/// @file main.c
///
/// Blink demo for EFM8UB2
///
/// Blinks LEDs on pins P2.2 and P2.3

#include "efm8_sfr.h"

#include "efm8_util/delay.h"
#include "peripheral_driver/inc/wdt_0.h"

#include "usb_test.h"
#include "usb/util/hut_keyboard.h"


#if DEVICE_PKG_QFP32 || DEVICE_PKG_QFN32
#  define LED0 P2_B2
#  define LED1 P2_B3
#  define BUTTON_PIN P1_B7
// #elif DEVICE_PKG_QFN20
#elif 1
#  define LED0 P0_B0
#  define LED1 P0_B1
#  define BUTTON_PIN P1_B2
#else
#  error "Unsupported package size"
#endif

/// Time between blinks
#define BLINK_DELAY 250

void usb_isr(void) __interrupt (USB0_IRQn);

extern XRAM uint8_t keyboardReport[8];

// A sequence of keystroke input reports.
extern SI_SEGMENT_VARIABLE(reportTable[], const KeyReport_TypeDef, SI_SEG_CODE);

/// Setup io pins
static void io_init() {
    // P0    -  Skipped,     Open-Drain, Digital
    // P1    -  Skipped,     Open-Drain, Digital
    // P2.2  -  Unassigned,  Push-Pull,  Digital
    // P2.3  -  Unassigned,  Push-Pull,  Digital

#if defined(EFM8UB2_DEVICE)
    P1MDIN    = PIN7_bm | PIN6_bm;
    P2MDOUT   = PIN2_bm | PIN3_bm;
    P0SKIP    = 0xFF;
    P1SKIP    = 0xFF;
    P2SKIP    = 0xFF;
    XBR1      = XBR1_XBARE__ENABLED;
// #elif DEVICE_PKG_QFN20
#elif defined(EFM8UB1_DEVICE)
    P0MDOUT   = PIN0_bm | PIN1_bm;
    P1MDIN    = PIN2_bm;
    P0SKIP    = 0xFF;
    P1SKIP    = 0xFF;
    XBR2      = XBR2_XBARE__ENABLED;
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
#elif defined(EFM8UB1_DEVICE)
    // Enable the flash prefetch engine, required for clock >25MHz
    PFE0CN = (
        PFE0CN_FLRT__BMASK
        | PFE0CN_FLRT__SYSCLK_BELOW_50_MHZ
    );
    // Clock settings
    CLKSEL = CLKSEL_CLKSL__HFOSC1;
#endif
}

/// Setup code
void setup(void) {
    WDT0_stop();

    oscillator_init();
    io_init();

    usb_init();

    // Disable interrupts
    IE_EA = 1;
}

void main(void) {
    uint8_t currentKeycode = KC_A;
    uint8_t keyState = 0;

    setup();

    LED0 = 1;
    LED1 = 0;

    while (1) {
        LED0 = !LED0;

        if (!BUTTON_PIN) {
            if (keyState == 0) {
                // Send the USB HID keycodes from KC_A to KC_FORWARD_SLASH
                // advancing to the next one each time the button is pressed.
                keyboardReport[2] = currentKeycode++;

                // Return to the start when it reaches the end of the range.
                if (currentKeycode > KC_FORWARD_SLASH) {
                    currentKeycode = KC_A;
                }

                IE_EA = 0;
                USBD_Write(EP1IN, keyboardReport, sizeof(KeyReport_TypeDef), false);
                IE_EA = 1;
                LED1 = !LED1;
            }
            keyState = 1;
        } else {
            if (keyState == 1) {
                // Send an empty (key released) report
                keyboardReport[2] = 0;
                IE_EA = 0;
                USBD_Write(EP1IN, keyboardReport, sizeof(KeyReport_TypeDef), false);
                IE_EA = 1;
            }
            keyState = 0;
        }
        efm8_delay_ms(5);
    }
}
