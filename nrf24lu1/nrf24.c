// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include <stdint.h>

#include "nrf24lu1.h"
#include "core/nrf24.h"
#include "core/rf.h"

void nrf24_init(void) {
    RFCTL = 0x11;       // enable SPI, 1/2 clock
    RFCON = 0x04;       // enable RF clock, CSN low, CE low
}

inline uint8_t nrf24_spi_send_byte(uint8_t byte) {
    RFDAT = byte;
    RFSPIF = 0;
    while (!RFSPIF);
    byte = RFDAT;
    return byte;
}

inline void nrf24_csn(uint8_t val) {
    RFCSN = val;
}

inline void nrf24_ce(uint8_t val) {
    RFCE = val;
}

uint8_t nrf24_irq(void) {
    return RFIRQ;
}

void rf_enable_receive_irq(void) {
    RF_IRQEN = 1;
}

void rf_init_receive_irq(void) {
    rf_enable_receive_irq();
}

void rf_disable_receive_irq(void) {
    RF_IRQEN = 0;
}

void nrf24lu1_rf_isr(void) __interrupt (ISR_RFIRQ) {
    rf_isr();
}
