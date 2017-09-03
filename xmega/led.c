// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/led.h"

#include <avr/io.h>

#define STATUS_LED_PIN PIN0_bm
#define STATUS_LED_PORT PORTC

void led_init(void) {
    /* STATUS_LED_PORT.DIRSET = STATUS_LED_PIN; */
    /* STATUS_LED_PORT.OUTCLR = STATUS_LED_PIN; */
}

void led_testing_set(uint8_t state) {
    /* if (state) { */
    /*  STATUS_LED_PORT.OUTSET = STATUS_LED_PIN; */
    /* } else { */
    /*  STATUS_LED_PORT.OUTCLR = STATUS_LED_PIN; */
    /* } */
}
void led_testing_toggle(void) {
    /* STATUS_LED_PORT.OUTTGL = STATUS_LED_PIN; */
}
