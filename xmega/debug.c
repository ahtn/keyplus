// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include <avr/interrupt.h>

#include <stdlib.h>

#include "core/hardware.h"
#include "core/debug.h"

#if !(NDEBUG > 4)
__ATTR_NORETURN__ void hang(void) {
    cli();
    wdt_disable();


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

    hang();
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

__ATTR_NORETURN__ void assert_fail(void) {

    static_delay_ms(1);

    debug_set(0, 1);
    debug_set(1, 1);
    debug_set(2, 1);
    debug_set(3, 0);

    hang();
}


#endif


// #ifndef DISABLE_DEBUG
#if !(NDEBUG > 3)

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
