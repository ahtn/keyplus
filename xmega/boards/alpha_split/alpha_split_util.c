// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "alpha_split_util.h"

#include <avr/io.h>

#include "core/timer.h"

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

