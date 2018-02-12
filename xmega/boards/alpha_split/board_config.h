// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

// This file lists pins that have function locked at compile time.

// Alpha split:
// Locked pins are:
//
// C1: VBUS pin
// E3: OE_RIGHT_PORT
// R0: OE_LEFT_PORT
// R1: USB_OE

#define IO_USABLE_PINS { \
    PORT_A_USABLE_PINS, \
    PORT_B_USABLE_PINS, \
    PORT_C_USABLE_PINS & (~PIN1_bm), \
    PORT_D_USABLE_PINS, \
    PORT_E_USABLE_PINS & (~PIN3_bm), \
    PORT_R_USABLE_PINS & (~PIN0_bm) & (~PIN1_bm), \
}
