// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "dual_usb.h"

#include "core/hardware.h"

#include <avr/io.h>

#define USB_PINS_PORT (PORTD)
#define USB_PINS_MASK (PIN7_bm | PIN6_bm)
#define USB_DM_PIN (PIN7_bm)
#define USB_DP_PIN (PIN6_bm)
#define USB_PULSE_MASK (USB_DP_PIN)

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

static void setup_usb_ports_for_sampling(void) {
    USB_PINS_PORT.DIRCLR = USB_PINS_MASK;
    PORTCFG.MPCMASK = USB_PINS_MASK;
    USB_PINS_PORT.PIN0CTRL = PORT_OPC_TOTEM_gc;
}

// Time it takes to make a HI<->LO transition in μs
#define DATA_LINE_TRANSITION_TIME 5

// Pulse the USB data lines, putting a HI voltage on one pin and a LO voltage
// on the other for 2μs. Once the pulse is finished, leave the pins as floating
// inputs.
static void usb_ports_pulse(void) {
    USB_PINS_PORT.DIRSET = USB_PINS_MASK;
    USB_PINS_PORT.OUTSET = USB_DP_PIN;
    USB_PINS_PORT.OUTCLR = USB_DM_PIN;
    static_delay_us(DATA_LINE_TRANSITION_TIME);
    USB_PINS_PORT.DIRCLR = USB_PINS_MASK;
    USB_PINS_PORT.OUTCLR = USB_PINS_MASK;
    static_delay_us(DATA_LINE_TRANSITION_TIME);
}

static uint8_t sample_usb_data_lines(void) {
    return USB_PINS_PORT.IN & USB_PINS_MASK;
}

static uint8_t usb_port_data_line_state(void) {
    // Pulse the data lines and observe the response
    usb_ports_pulse();
    const uint8_t sample = sample_usb_data_lines();

    if (sample == 0) {
        // Data lines are pulled down => USB host connected
        return 1;
    } else if (sample == USB_PINS_MASK) {
        // Data lines are pulled up => I2C connected
        return 0;
    } else {
        // Data lines are floating
        return 2;
    }
}

// Need to find if the lines are floating, i2c or USB.
// To do this, we will pulse the pins to either Hi/Lo and observe the responses
//
// For I2C:
// We assume that an I2C lines have 10kΩ pull-up resistors on the data lines.
// We also assume that they have parasitic capacitance on the order of 50pF.
// So if we pulse the input line Lo, then due to the parasitic capacitance, it
// will take about 2RC = 2*(10kΩ)(50pF) = 1μs for the input lines to recover.
//
// For USB:
// We assume that the USB host has 15kΩ pull-down resistors on the D+/D- lines.
// We'll again assume that we need 1μs to overcome the parasitic input capacitance.
//
uint8_t usb_find_port(void) {
    uint8_t has_usb_port = false;

    setup_usb_ports_for_sampling();

    while (true) {
        // NOTE: I2C_OE_LEFT is also connected to USB_SEL, so we
        // try right port first (because I2C_OE_LEFT shared with USB SEL)
        // TODO: we set some of these values redundantly here just to make
        // the code clearer
        SET_BUS_SWITCH(USB_OE, 1);
        SET_BUS_SWITCH(I2C_OE_LEFT, 0); // 0 -> USB Left, 1 -> USB Right

        // Since in the USB plug, the power pins mate first before the data lines
        // we should wait before trying to sample them again
        dynamic_delay_ms(100);

        // First check right port for USB/I2C
        const uint8_t left_data_line_state = usb_port_data_line_state();

        if (left_data_line_state == 1) {
            // both lines were stable and LO, so this port has a USB connection
            // So USB port is on the left, connect the right side to I2C
            has_usb_port = 1;
            SET_BUS_SWITCH(USB_OE, 1);
            SET_BUS_SWITCH(I2C_OE_LEFT, 0); // USB on left port
            SET_BUS_SWITCH(I2C_OE_RIGHT, 1); // I2C on right port
            return has_usb_port;
        }

        // Switch the USB port to the right
        SET_BUS_SWITCH(I2C_OE_LEFT, 1); // enable I2C on left => USB on right

        dynamic_delay_ms(10);

        // USB data lines now on the right port, so sample the state of the
        // data lines again, to discover the nature of the right port
        const uint8_t right_data_line_state = usb_port_data_line_state();

        if (left_data_line_state == 0) {
            // both lines were stable and HI, so this port has an I2C connection
            // So enable I2C on the left port, which will also swap the USB
            // data lines to the right port.


            if (right_data_line_state == 1) {
                // The right port has a USB connection
                has_usb_port = 1;
                SET_BUS_SWITCH(USB_OE, 1);
                SET_BUS_SWITCH(I2C_OE_LEFT, 1);
                SET_BUS_SWITCH(I2C_OE_RIGHT, 0);
                return has_usb_port;
            }

            if (right_data_line_state == 0) {
                // The right port is also an I2C port, so we'll enable
                // I2C on the right port as well, and disconnect the USB data
                // lines because they are unneeded because both ports are being
                // used for I2C.
                SET_BUS_SWITCH(USB_OE, 0);
                SET_BUS_SWITCH(I2C_OE_LEFT, 1); // I2C on left port
                SET_BUS_SWITCH(I2C_OE_RIGHT, 1); // I2C on right port
                return has_usb_port;
            }

            if (right_data_line_state == 2) {
                // The right port is floating. For now we assume that the right
                // port is not a USB port.
                // TODO: technically, this still could be a USB port, because
                // if the user inserts the USB cable very slowly, the USB
                // data connections might not be made yet, but the power
                // connections have been made for both boards, and so the I2C
                // pull-ups will be active on the left port, while the right
                // port has not yet been connected to the pull-down resistors
                // of the USB host. But for now go with this implementation
                SET_BUS_SWITCH(USB_OE, 0);
                SET_BUS_SWITCH(I2C_OE_LEFT, 1); // I2C on left port
                SET_BUS_SWITCH(I2C_OE_RIGHT, 1); // I2C on right port
                return has_usb_port;
            }
        }

        if (left_data_line_state == 2) {
            // the lines didn't arrive at one of the valid states based on the
            // pull up/down resistors expected of a I2C/USB port. So it must
            // be disconnected right now. Before we connect it to I2C, we need
            // to know the state of the other port.

            if (right_data_line_state == 1) {
                // Got a USB connection on the right port
                has_usb_port = 1;
                SET_BUS_SWITCH(I2C_OE_LEFT, 1); // I2C on left port
                SET_BUS_SWITCH(I2C_OE_RIGHT, 0); // turn off I2C on right port
                SET_BUS_SWITCH(USB_OE, 1);
                return has_usb_port;
            }

            if (right_data_line_state == 0) {
                // Got an I2C connection on the right port
                if (0) {
                    // TODO: probably a more robust implementation
                    SET_BUS_SWITCH(I2C_OE_LEFT, 0); // USB data lines on left
                    SET_BUS_SWITCH(I2C_OE_RIGHT, 1); // I2C on right port
                    SET_BUS_SWITCH(USB_OE, 1);

                    // Again because of the delay between making contact with
                    // the power, pins we can't be sure about the state of
                    // the left port just yet.

                    // TODO: setup handler to detect if the data lines on the
                    // left are actually being used for I2C
                    // NOTE: should probably do this by pinging the right port
                    // requesting to see if any device in the chain has a USB
                    // port.
                    return has_usb_port;
                }

                if (1) {
                    // NOTE: could potential be incorrect if the USB port is
                    // inserted slowly.
                    // Got an I2C connection on the right port, connect the
                    SET_BUS_SWITCH(I2C_OE_LEFT, 1); // floating state left port
                    SET_BUS_SWITCH(I2C_OE_RIGHT, 1); // I2C on right port
                    SET_BUS_SWITCH(USB_OE, 0);
                    return has_usb_port;
                }
            }

            if (right_data_line_state == 2) {
                // We couldn't detect an I2C or USB connection on either port.
                // So run this routine again until we find something.
                continue;
            }
        }

        // Note: if this loop gets stuck and runs for too long, then the
        // watchdog timer will reset the microcontroller for us.
    }
}
