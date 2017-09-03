// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/timer.h"

#include "nrf24lu1.h"

static volatile IRAM uint32_t timer_counter;

// NOTE: Can probably use the RTC clock and/or USB SOF to keep track of time
// instead if we need timer2 for something else.
void timer_init(void) {
    // Reload mode 0: overflow causes reload
    // Prescaler: clk / 12
    T2CON |= 0x10;

    // Setup the reload value for timer 2.
    // Want the timer to overflow every millisecond.
    // So reload_value = 0x10000 - (num_ticks_per_ms)
    // Timer ticks every (ticks_per_s = F_CPU/12) cycles.
    // num_ticks_per_ms = (0.001 s) * (ticks_per_s)
    // = 0.001 * (F_CPU/12)
    // = 0.001 * (16*10^6 / 12)
    // = 1333.33333333 ticks
    T2 = CRC = 0xffff - 1334;  // auto reload value for timer

    timer_counter = 0;
    T2I0 = 1; // Start Timer2
    ET2 = 1; // enable timer2 isr
}

uint8_t timer_read8_ms(void) {
    return (uint8_t)timer_counter;
}

uint16_t timer_read16_ms(void) {
    return (uint16_t)timer_read_ms();
}

uint32_t timer_read_ms(void) {
    uint32_t result;
    bit_t ea = EA; // disable interrupts while reading
    EA = 0;
    result = timer_counter;
    EA = ea;
    return result;
}

void t2_isr(void) __interrupt (ISR_T2) {
    // TODO: check, do I need to do this manually?
    TF2 = 0; // clear the interrupt flag
    timer_counter++;
}
