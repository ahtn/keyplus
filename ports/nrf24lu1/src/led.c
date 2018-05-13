// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/led.h"

#include "nrf24lu1.h"

void led_init(void) {
    P0 = 0x30; // P05..4==1, P03..0==0

    P0ALT = 0x00;   // all GPIO default behavior
    P0EXP = 0x00;

    /* P0DIR = 0x00;   // all out; LED is on P03 */
    P0DIR = 0x20;   // P05 input, P04..0==0

    P03 = 0;
}

void led_testing_set(uint8_t led_number, uint8_t state) {
    if (led_number == 0) {
        P03 = state;
    }
}

void led_testing_toggle(void) {
    P03 = !P03;
}
