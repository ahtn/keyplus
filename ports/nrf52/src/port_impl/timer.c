// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/timer.h"

#include "nrf_drv_rtc.h"
#include "nrf_drv_clock.h"

const nrf_drv_rtc_t rtc = NRF_DRV_RTC_INSTANCE(0); /**< Declaring an instance of nrf_drv_rtc for RTC0. */

static volatile uint32_t s_timer_counter;

// handler for rtc interrupts (tick and compare)
static void rtc_handler(nrf_drv_rtc_int_type_t int_type) {
    s_timer_counter++;
}

// function starting the internal LFCLK XTAL oscillator.
static void lfclk_config(void) {
    ret_code_t err_code = nrf_drv_clock_init();
    APP_ERROR_CHECK(err_code);

    nrf_drv_clock_lfclk_request(NULL);
}

static void rtc_config(void) {
    uint32_t err_code;

    // RTC clock is 32.768kHz
    // Frequency is then (32.768k) / (PRESCALER + 1)
    // PRESCALER = 32 ==> f = (32.768k) / (33) == 992.969696969697 Hz
    //
    //Initialize RTC instance
    nrf_drv_rtc_config_t config = NRF_DRV_RTC_DEFAULT_CONFIG;
    config.prescaler = 32; // 1ms
    err_code = nrf_drv_rtc_init(&rtc, &config, rtc_handler);

    APP_ERROR_CHECK(err_code);

    //Enable tick event & interrupt
    nrf_drv_rtc_tick_enable(&rtc,true);

    ////Set compare channel to trigger interrupt after COMPARE_COUNTERTIME seconds
    //err_code = nrf_drv_rtc_cc_set(&rtc,0,COMPARE_COUNTERTIME * 1000,true);
    //APP_ERROR_CHECK(err_code);

    //Power on RTC instance
    nrf_drv_rtc_enable(&rtc);
}

void timer_init(void) {
    lfclk_config();
    rtc_config();
}

// void timer_disable(void);
// void timer_adjust(int32_t adj);

uint8_t timer_read8_ms(void) {
    return s_timer_counter;
}

uint16_t timer_read16_ms(void) {
    return s_timer_counter;
}

uint32_t timer_read_ms(void) {
    return s_timer_counter;
}
