// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <avr/io.h>

// Add pass reset status onto the USB interface some how
// RST.STATUS = RST.STATUS;

#if 1

static inline void init_debug(void) {
    // test pins
    // A7, B0, D4, E2
    PORTA.DIRSET = PIN7_bm;
    PORTB.DIRSET = PIN0_bm;
    PORTD.DIRSET = PIN4_bm;
    PORTE.DIRSET = PIN2_bm;

    PORTA.OUTCLR = PIN7_bm;
    PORTB.OUTCLR = PIN0_bm;
    PORTD.OUTCLR = PIN4_bm;
    PORTE.OUTCLR = PIN2_bm;
}

#define SET_PIN(a, b, val) do { \
    if (val) { \
        PORT ## a . OUTSET = PIN ## b ## _bm; \
    } else { \
        PORT ## a . OUTCLR = PIN ## b ## _bm; \
    } \
} while(0)

#define debug_toggle(x) do { \
    if (x == 0) PORTA.OUTTGL = PIN7_bm; \
    else if (x == 1) PORTB.OUTTGL = PIN0_bm; \
    else if (x == 2) PORTD.OUTTGL = PIN4_bm; \
    else if (x == 3) PORTE.OUTTGL = PIN2_bm; \
} while(0)

#define debug_set(x, val) do { \
    if (x == 0)      { SET_PIN(A, 7, val); } \
    else if (x == 1) { SET_PIN(B, 0, val); } \
    else if (x == 2) { SET_PIN(D, 4, val); } \
    else if (x == 3) { SET_PIN(E, 2, val); } \
} while(0)

#else

#define init_debug()
#define debug_toggle(x)
#define debug_set(x, y)

#endif
