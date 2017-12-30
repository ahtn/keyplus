// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "alpha_split_util.h"

#include <avr/io.h>

#ifdef ALPHA_SPLIT_V2
#define I2C_OE_LEFT

void init_bus_switches(void) {
    // Configure all thes bus switch control lines to output. Default to
    // disconnect all bus switches
    I2C_OE_LEFT_PORT.DIRSET = I2C_OE_LEFT_PIN;
    SET_BUS_SWITCH(I2C_OE_LEFT, 0);

    I2C_OE_RIGHT_PORT.DIRSET = I2C_OE_RIGHT_PIN;
    SET_BUS_SWITCH(I2C_OE_RIGHT, 0);

    USB_OE_PORT.DIRSET = USB_OE_PIN;
    SET_BUS_SWITCH(USB_OE, 0);
}
#endif

void bootloader_extra_setup(void) {
    init_bus_switches();
}

// 10_000 -> approx .300ms
#define USB_SWITCHING_TIME 10000

// Timer used to check when trying to connect to a USB port
void init_bus_switch_toggler(void) {
    // F_CPU == 32MHz --> tick == 1024 / 32MHz == 32µs
    TCC0.CTRLA = TC_CLKSEL_DIV1024_gc;
    TCC0.PER = 0xFFFF;
    TCC0.CNT = 0x0000;
}

void bus_switch_toggle_task(void) {
    static uint8_t port = 0;
    if (TCC0.CNT > USB_SWITCHING_TIME) {
        port = !port;
        SET_BUS_SWITCH(I2C_OE_LEFT, port);
        TCC0.CNT = 0;
    }
}
