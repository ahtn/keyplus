// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/timer.h"

#include "efm8_util/io.h"

static volatile IRAM uint32_t timer_counter;

// System clock is 48_000_000MHZ.
// So tick period is 0.25µs.
// Want to make a 1ms interrupt.
// So that's 1_000µs / 0.25µs == 4_000 ticks
#define TIMER0_RELOAD_VALUE (0xffff - 4000 + 1)

#define TIMER0_RELOAD(x) do { \
    TL0 = (TIMER0_RELOAD_VALUE >> 0) & 0xff; \
    TH0 = (TIMER0_RELOAD_VALUE >> 8) & 0xff; \
} while(0)

// NOTE: Should probably just use USB start of frame instead.
void timer_init(void) {

    timer_counter = 0;

    // Set timer 0 as a 16 bit timer
    TMOD = (TMOD & 0xF0) | TMOD_T0M__MODE1;

    TIMER0_RELOAD();

    TCON_TR0 = 1; // Enable the timer 0
    IE_ET0 = 1; // Enable the timer 0 interrupt
}

uint8_t timer_read8_ms(void) {
    return (uint8_t)timer_counter;
}

uint16_t timer_read16_ms(void) {
    return (uint16_t)timer_read_ms();
}

uint32_t timer_read_ms(void) {
    uint32_t result;
    bit_t ea = IE_EA; // disable interrupts while reading
    IE_EA = 0;
    result = timer_counter;
    IE_EA = ea;
    return result;
}

void t0_isr(void) __interrupt (TIMER0_IRQn) {
    // TF0 = 0; // done by hardware when entering ISR_T0
    timer_counter++;
    TIMER0_RELOAD();
}
