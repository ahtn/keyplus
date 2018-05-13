// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/timer.h"
#include <util/delay.h>
#include <util/atomic.h>
#include "core/led.h"

static volatile uint32_t timer_counter;
static uint8_t timer_increment_amount;

// WARN: If the RTC.PER register is <2, then interrupts won't be triggered
// for all overflow events. Instead:
// RTC.PER == 0 -> every third overflow
// RTC.PER == 1 -> every second overflow
// RTC.PER >= 2 -> every overflow
//
// NOTE: the ULP (ultra low power) rtc has accurracy ±30%.
// NOTE: It takes 1 µA of current vs 29 µA for the 32.768kHz oscillator.
void rtc_ulp_init(void) {
    // 1.024 kHz from internal 32kHz ULP
    CLK.RTCCTRL = CLK_RTCSRC_ULP_gc | CLK_RTCEN_bm;;

    while (RTC.STATUS & RTC_SYNCBUSY_bm);

    timer_increment_amount = 3; // must be >= 3

    RTC.PER = timer_increment_amount - 1; // overflow every 3 ticks (see note above why this can't go lower)
    RTC.CNT = 0x00; // set the clock counter to 0
    RTC.COMP = 0x00;


    RTC.INTCTRL = RTC_OVFINTLVL_HI_gc | RTC_COMPINTLVL_OFF_gc; // set low interrupt level
    RTC.CTRL = RTC_PRESCALER_DIV1_gc; // set prescaler to 1
}

void rtc_32k_init(void) {
    // Turn on internal 32kHz.
    CCP = CCP_IOREG_gc;
    OSC.CTRL |= OSC_RC32KEN_bm;
    while ((OSC.STATUS & OSC_RC32KRDY_bm) == 0);

    // 32.768 kHz from internal 32.768 kHz RC oscillator
    CLK.RTCCTRL = CLK_RTCSRC_RCOSC32_gc | CLK_RTCEN_bm;
    while (RTC.STATUS & RTC_SYNCBUSY_bm);

    RTC.PER = 32; // overflow every ms

    RTC.CNT = 0x00; // set the clock counter to 0
    RTC.COMP = 0x00;

    timer_increment_amount = 1;

    RTC.INTCTRL = RTC_OVFINTLVL_HI_gc | RTC_COMPINTLVL_OFF_gc; // set low interrupt level
    RTC.CTRL = RTC_PRESCALER_DIV1_gc; // set prescaler to 1
}

ISR(RTC_OVF_vect) {
    timer_counter += timer_increment_amount;
}

void timer_init(void) {
    rtc_32k_init();
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

void timer_disable(void) {
    RTC.INTCTRL = RTC_OVFINTLVL_OFF_gc; // set low interrupt level
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

