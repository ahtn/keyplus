// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/timer.h"

#include <util/atomic.h>

static volatile uint32_t timer_counter;

#ifndef TIMER_PRESCALER
#   if F_CPU > 16000000
#       define TIMER_PRESCALER      256
#   elif F_CPU > 2000000
#       define TIMER_PRESCALER      64
#   elif F_CPU > 250000
#       define TIMER_PRESCALER      8
#   else
#       define TIMER_PRESCALER      1
#   endif
#endif

#define TIMER_RAW_FREQ      (F_CPU/TIMER_PRESCALER)
#define TIMER_RAW           TCNT0
#define TIMER_RAW_TOP       (TIMER_RAW_FREQ/1000)

#if (TIMER_RAW_TOP > 255)
#   error "Timer0 can't count 1ms at this clock freq. Use larger prescaler."
#endif

void timer_init(void) {
    // Timer0 CTC mode
    TCCR0A = 0x02;

#if TIMER_PRESCALER == 1
    TCCR0B = 0x01;
#elif TIMER_PRESCALER == 8
    TCCR0B = 0x02;
#elif TIMER_PRESCALER == 64
    TCCR0B = 0x03;
#elif TIMER_PRESCALER == 256
    TCCR0B = 0x04;
#elif TIMER_PRESCALER == 1024
    TCCR0B = 0x05;
#else
#   error "Timer prescaler value is NOT vaild."
#endif

    OCR0A = TIMER_RAW_TOP;
#ifdef TIMSK0
    TIMSK0 = (1<<OCIE0A);
#else
    TIMSK = (1<<OCIE0A);
#endif
}

void timer_disable(void) {
}

ISR(TIMER0_COMPA_vect) {
    timer_counter++;
}


void reset_timer_value(void) {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        timer_counter = 0;
    }
}

void timer_adjust(int32_t adj) {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        timer_counter += adj;
    }
}

uint8_t timer_read8_ms(void) {
    return timer_counter;
}

uint16_t timer_read16_ms(void) {
    uint16_t result;
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        result = timer_counter;
    }
    return result;
}

uint32_t timer_read_ms(void) {
    uint32_t result;
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        result = timer_counter;
    }
    return result;
}
