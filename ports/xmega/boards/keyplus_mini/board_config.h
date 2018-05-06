// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

// This file lists pins that have function locked at compile time.

// The locked pins are:
// E2: vbus check

#define IO_USABLE_PINS { \
    PORT_A_USABLE_PINS, \
    PORT_B_USABLE_PINS, \
    PORT_C_USABLE_PINS, \
    PORT_D_USABLE_PINS, \
    PORT_E_USABLE_PINS & (~PIN2_bm), \
    PORT_R_USABLE_PINS, \
}
