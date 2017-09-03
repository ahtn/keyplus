// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include <avr/eeprom.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/power.h>
#include <avr/sleep.h>
#include <util/delay.h>
#include <avr/wdt.h>

#include <string.h>
#include "core/aes.h"
#include "core/rf.h"
#include "core/nrf24.h"
#include "core/settings.h"
#include "core/packet.h"
#include "core/matrix_scanner.h"

#include "config.h"
#include "scan.h"
#include "clock.h"

// How long the keyboard can be inactive before it goes to sleep. The keyboard
// is considered active if any key is down.
#ifndef INACTIVITY_TIMEOUT
#define INACTIVITY_TIMEOUT 1 // 0-255 seconds
#endif

// If no keys are either presses or released in this time, the keyboard
// will go to sleep. If something gets left on the keyboard, this value will
// let it know when it is safe to assume nobody is using it, but it also
// limits how long you can hold down a key for.
#ifndef UNCHANGED_TIMEOUT
#define UNCHANGED_TIMEOUT 30 // 0-255 seconds
#endif

#ifndef ERROR_LIMIT
#define ERROR_LIMIT 7
#endif

// how many iterations the main loop can do in a second
// WARN: this is value was measured for the current clock speeds and does
// not control the given scan rate. It is used as a rough estimate of how
// long a second is in terms of matrix scans.
#define SCAN_RATE 300

void disable_unused_hardware(void) {
    wdt_disable();

    ADCSRA = 0; // disable ADC
    power_adc_disable();

    power_usart0_disable();
    power_timer0_disable();
    power_timer1_disable();
    power_timer2_disable();
    power_twi_disable();
}

void disable_hardware(void) {
    nrf24_power_set(0);
    power_spi_disable();
}

void enable_hardware(void) {
    power_spi_enable();
}

void reset_hardware(void) {
    // default state, output low
    DDRB = 0xff;
    DDRC = 0xff;
    DDRD = 0xff;
    PORTB = 0x00;
    PORTC = 0x00;
    PORTD = 0x00;

    nrf24_init();
    nrf24_power_set(1);
    matrix_init();
}

void slave_sleep(void) {
    // want to be fast on wakeup
    clock_fast();

    disable_hardware();

    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    cli();
    sleep_enable();

    // set the matrix to fire interrupt on pin change
    matrix_interrupt_mode();

    // Turn off brown out detection during sleep. Saves about 35μA in sleep mode.
    // Brown-out detection will be automatically reenabled on wake up.
    // WARN: This is a timed sequence. Have 4 clock cycles, from this point
    // to go to sleep, or otherwise BODS will be reenabled.
    MCUCR = (1<<BODS) | (1<<BODSE); // special write sequence, see datasheet
    MCUCR = (1<<BODS);
    sei();
    sleep_cpu();
    cli();

    enable_hardware();
    reset_hardware();
    sei();
}

void slave_disable(void) {
    enable_hardware();
}

void setup(void) {

    clock_fast();

    disable_unused_hardware();
    /* load_eeprom_settings(&settings); */
    _delay_ms(100); // nrf takes about this long to start from no power
    reset_hardware();

    settings_load_from_flash();
    aes_key_init(g_rf_settings.ekey, g_rf_settings.dkey);

    /* setup_test_settings(); */

    rf_init_send();

    sei();
}

// get vcc voltage
uint16_t vcc_ref(void) {
    // From the data sheet:
    //   ADC = V_in * 1024 / V_ref
    //
    // Here we mearsue the 1.1 internal V_ref, with AVCC. So:
    //    V_in  = V_bg
    //    V_ref = AVCC
    //
    // So:
    //   AVCC = V_ref = (1.1 * 1024) / ADC
    // Or with 8 bit resolution:
    //   AVCC = V_ref = (1.1 * 256) /  ADC
    uint8_t adc;
    power_adc_enable();
    //ADCSRA = (1 << ADEN) | 0x7;
    ADCSRA = (1 << ADEN) | 0x7;
    ADMUX = (0b01 << REFS0) | (1 << ADLAR) | (0b1110 << MUX0);
    _delay_us(200); // 200us
    ADCSRA |= (1 << ADSC);
    while (ADCSRA & (1 << ADSC)); // ~ (25 * CLK / 128) @ 8MHZ => 800us
    adc = ADCH;
    ADCSRA = 0;
    power_adc_disable();
    return (uint16_t)(1.1 * 256 * 100) / adc;
}

int main(void) {
    uint8_t nrf_status = 0;
    uint8_t inactive_time = 0;
    uint8_t unchanged_time = 0;
#if SCAN_RATE <= 255
    uint8_t scan_rate_counter = 0;
#else
    uint16_t scan_rate_counter = 0;
#endif
    bool should_ping = false;
    /* uint8_t error_rate = 0; */

    setup();

    while(1) {
        // WARN: the debounce of this scan is effectively the rate at which this
        // loop runs.
        clock_slow();

        bool scan_changed = matrix_scan_slow();

        clock_fast();
        {
            nrf_status = nrf24_read_reg(NRF_STATUS);
            if (nrf_status & ((1<<STATUS_MAX_RT) | (1<<STATUS_TX_FULL))) {
                nrf24_flush_tx();
                nrf24_write_reg(NRF_STATUS, 0x70);
            }

            // only send the scan result if something changed
            if (scan_changed || should_ping) {
                rf_send_matrix_packet();

                if (scan_changed) {
                    unchanged_time = 0;
                }

                if (get_matrix_num_keys_down() != 0) {
                    inactive_time = 0;
                }

                should_ping = false;
            }

            rf_handle_ack_payloads();

            scan_rate_counter++;
            if (scan_rate_counter == SCAN_RATE) {
                scan_rate_counter = 0;
                should_ping = true;

                // don't sleep if messages are pending
                if ( ((inactive_time >= INACTIVITY_TIMEOUT) || (unchanged_time >= UNCHANGED_TIMEOUT))
                        && (nrf24_read_reg(FIFO_STATUS) & (1 << FIFO_TX_EMPTY)) ) {
                    inactive_time = 0;
                    unchanged_time = 0;
                    slave_sleep();
                }

                inactive_time++;
                unchanged_time++;
            }
        }
    }

}
