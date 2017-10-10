// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include <stdint.h>

#include "c8051f38x.h"

void oscillator_init(void) {
    FLSCL     = FOSE_bm | FLRT_bm;
    CLKSEL    = SYSCLK_INTERNAL_HF_OSC_gc;
}

void interrupts_init(void) {
    EIE1      = EPCA0_bm | EUSB0_bm;
}

void port_init (void) {
   XBR0     = 0x00;                    // No digital peripherals selected
   XBR1     = 0x40;                    // Enable crossbar and weak pull-ups
   P2MDOUT |= 0x04;                    // Enable LED as a push-pull output
}

// don't really care if this isn't accurate
void dynamic_delay_us(uint16_t us) {
    while (us--) {
        __asm
            nop
            nop
            nop
            nop
            nop
        __endasm;
    }
}

void dynamic_delay_ms(uint16_t ms) {
    while (ms--) {
        dynamic_delay_us(1000);
    }
}

void main (void)
{
    PCA0MD &= ~0x40;                         // WDTE = 0 (clear watchdog timer)

    oscillator_init ();                      // Initialize system clock
    port_init ();                            // Initialize crossbar and GPIO

    while (1) {
        dynamic_delay_ms(10);
        P2_2 = !P2_2;
    }
}
