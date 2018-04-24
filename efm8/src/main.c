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
#include "usb/util/hut_consumer.h"

#include "usb_desc/descriptors.h"

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

#define NKRO_REPORT_BYTES (0xe0/8)
typedef struct {
    uint8_t id;

    union {
        struct {
            uint16_t value;
        } system;

        struct {
            uint16_t value;
        } consumer;

        struct {
            uint8_t modifiers;
            uint8_t bitmask[NKRO_REPORT_BYTES];
        } nkro;

        struct {
            uint8_t buttons_1;
            uint8_t buttons_2;
            int16_t x;
            int16_t y;
            int8_t wheel_y;
            int8_t wheel_x;
        } mouse;
    } report;
} shared_hid_report_t;

XRAM shared_hid_report_t g_shared_hid;

// XRAM uint8_t g_vendor_in_report[VENDOR_REPORT_SIZE];
// XRAM uint8_t g_vendor_out_report[VENDOR_REPORT_SIZE];

XRAM uint8_t g_vendor_in_report[8];
XRAM uint8_t g_vendor_out_report[8];

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
                if (currentKeycode % 2 == 1) {
                    USBD_Write(EP1IN, keyboardReport, sizeof(KeyReport_TypeDef), false);
                }

                // NOTE: On the Shared HID interface, we can only send one
                // kind of report at a time.
                if (currentKeycode % 3 == 0) {
                    g_shared_hid.id = REPORT_ID_CONSUMER;
                    g_shared_hid.report.consumer.value = HID_CONSUMER_PLAY_PAUSE;
                    USBD_Write(EP2IN, &g_shared_hid, 3, false);
                } else if (currentKeycode % 4 == 0) {
                    g_shared_hid.id = REPORT_ID_MOUSE;
                    g_shared_hid.report.mouse.x = 100;
                    USBD_Write(EP2IN, &g_shared_hid, 8, false);
                } else if (currentKeycode % 2 == 0) {
                    g_shared_hid.id = REPORT_ID_NKRO;
                    g_shared_hid.report.nkro.modifiers  = (1 << (KC_LEFT_SHIFT-0xE0));
                    g_shared_hid.report.nkro.bitmask[0] = (1 << KC_A);
                    USBD_Write(EP2IN, &g_shared_hid, NKRO_REPORT_BYTES+1, false);
                } else if (currentKeycode % 5 == 0) {
                    USBD_Write(EP3IN, &g_shared_hid, VENDOR_REPORT_SIZE, false);
                }
                IE_EA = 1;
                LED1 = !LED1;
            }
            keyState = 1;
        } else {
            if (keyState == 1) {
                // Send an empty (key released) report
                keyboardReport[2] = 0;
                IE_EA = 0;
                if (currentKeycode % 2 == 1) {
                    USBD_Write(EP1IN, keyboardReport, sizeof(KeyReport_TypeDef), false);
                }

                if (currentKeycode % 3 == 0) {
                    g_shared_hid.id = REPORT_ID_CONSUMER;
                    g_shared_hid.report.consumer.value = 0;
                    USBD_Write(EP2IN, &g_shared_hid, 3, false);
                } else if (currentKeycode % 4 == 0) {
                    g_shared_hid.id = REPORT_ID_MOUSE;
                    g_shared_hid.report.mouse.x = 0;
                    USBD_Write(EP2IN, &g_shared_hid, 8, false);
                } else if (currentKeycode % 2 == 0) {
                    g_shared_hid.id = REPORT_ID_NKRO;
                    g_shared_hid.report.nkro.modifiers  = 0;
                    g_shared_hid.report.nkro.bitmask[0] = 0;
                    USBD_Write(EP2IN, &g_shared_hid, NKRO_REPORT_BYTES+1, false);
                }
                IE_EA = 1;
            }
            keyState = 0;
        }

        if (!USBD_EpIsBusy(EP3OUT)) {
            USBD_Read(EP3OUT, g_vendor_out_report, sizeof(g_vendor_out_report), true);

            if (g_vendor_out_report[0] == 1 && !USBD_EpIsBusy(EP3IN)) {
                g_vendor_in_report[0] = 0xAA;
                g_vendor_in_report[1] = 0x55;
                g_vendor_in_report[2] = 0xAA;
                g_vendor_in_report[3] = 0x55;
                USBD_Write(EP3IN, g_vendor_in_report, VENDOR_REPORT_SIZE, false);
            }
        }
        efm8_delay_ms(5);
    }
}
