// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include <avr/interrupt.h>

#include <stdlib.h>

#include "core/hardware.h"
#include "core/debug.h"
#include "core/usb_commands.h"
#include "usb_reports/vendor_report.h"
#include "power.h"

#if defined(DEBUG_LEVEL) && DEBUG_LEVEL >= 4
__ATTR_NORETURN__ void hang(void) {
    wdt_disable();

    cli();

    while (1) {
    }
}

ISR(BADISR_vect) {
    // Catch all for unknown interrupts
    //
    debug_set(0, 0);
    debug_set(1, 1);
    debug_set(2, 1);
    debug_set(3, 0);

    while (1) {
        USB_PRINT_TEXT("unhandled irq");

        send_vendor_report();
        handle_vendor_out_reports();

        enter_sleep_mode(SLEEP_MODE_IDLE);
        wdt_kick();

        usb_poll();
    }
}

// void assert_fn (const char *func, const char *file, int line, const char *failedexpr) {
	// if (func == NULL) {
	// 	(void)fprintf(stderr,
	// 	     "Assertion failed: (%s), file %s, line %d.\n", failedexpr,
	// 	     file, line);
    // } else {
	// 	(void)fprintf(stderr,
	// 	     "Assertion failed: (%s), function %s, file %s, line %d.\n",
	// 	     failedexpr, func, file, line);
    // }

__ATTR_NORETURN__ void assert_fail(uint16_t line_num) {

    static_delay_ms(1);

    debug_set(0, 1);
    debug_set(1, 1);
    debug_set(2, 1);
    debug_set(3, 0);

    cli();

#define digit(x) ((x) + '0')
    while (1) {
        uint8_t message[] = "assert failed line: 00000";
        message[14] = digit(line_num / 10000 % 10);
        message[15] = digit(line_num / 1000 % 10);
        message[16] = digit(line_num / 100 % 10);
        message[17] = digit(line_num / 10 % 10);
        message[18] = digit(line_num / 1 % 10);
        usb_print(message, sizeof(message));

        send_vendor_report();
        handle_vendor_out_reports();

        enter_sleep_mode(SLEEP_MODE_IDLE);
        wdt_kick();
        usb_poll();
    }
}


#endif


// #ifndef DISABLE_DEBUG
#if defined(DEBUG_LEVEL) && DEBUG_LEVEL >= 2

void init_debug(void) {
    // test pins
    // A6, A7, B0, D4, D5, E2
    PORTA.DIRSET = PIN6_bm | PIN7_bm;
    PORTB.DIRSET = PIN0_bm;
    PORTD.DIRSET = PIN4_bm | PIN5_bm;
    PORTE.DIRSET = PIN2_bm;

    PORTA.OUTCLR = PIN6_bm | PIN7_bm;
    PORTB.OUTCLR = PIN0_bm;
    PORTD.OUTCLR = PIN4_bm | PIN5_bm;
    PORTE.OUTCLR = PIN2_bm;
}

#define TOG_PIN(a, n) (PORT ## a .OUTTGL = PIN ## n ## _bm)

#define SET_PIN(a, b, val) do { \
    if (val) { \
        PORT ## a . OUTSET = PIN ## b ## _bm; \
    } else { \
        PORT ## a . OUTCLR = PIN ## b ## _bm; \
    } \
} while(0)

void debug_toggle(uint8_t x) {
    if (x == 0)      { TOG_PIN(A, 6); }
    else if (x == 1) { TOG_PIN(A, 7); }
    else if (x == 2) { TOG_PIN(B, 0); }
    else if (x == 3) { TOG_PIN(D, 4); }
    else if (x == 4) { TOG_PIN(D, 5); }
    else if (x == 5) { TOG_PIN(E, 2); }
}

void debug_set(uint8_t x, uint8_t val) {
    if (x == 0)      { SET_PIN(A, 6, val); }
    else if (x == 1) { SET_PIN(A, 7, val); }
    else if (x == 2) { SET_PIN(B, 0, val); }
    else if (x == 3) { SET_PIN(D, 4, val); }
    else if (x == 4) { SET_PIN(D, 5, val); }
    else if (x == 5) { SET_PIN(E, 2, val); }
}

#endif
