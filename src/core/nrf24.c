// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/nrf24.h"
#include "core/hardware.h"

static uint8_t nrf24_reg(nrf24_register_t reg, uint8_t val) {
    uint8_t result;
    nrf24_csn(0);
    nrf24_spi_send_byte(reg);
    result = nrf24_spi_send_byte(val);
    nrf24_csn(1);
    return result;
}

static nrf24_status_t nrf24_read_buf(nrf24_spi_command_t cmd, uint8_t *dest, uint8_t len) {
    uint8_t result;
    uint8_t i;
    nrf24_csn(0);
    result = nrf24_spi_send_byte(cmd);
    for (i = 0; i < len; ++i) {
        dest[i] = nrf24_spi_send_byte(NRF_NOP);
    }
    nrf24_csn(1);
    return result;
}

static nrf24_status_t nrf24_write_buf(nrf24_spi_command_t cmd, const uint8_t *src, uint8_t len) {
    uint8_t result;
    uint8_t i;
    nrf24_csn(0);
    result = nrf24_spi_send_byte(cmd);
    for (i = 0; i < len; ++i) {
        nrf24_spi_send_byte(src[i]);
    }
    nrf24_csn(1);
    return result;
}

nrf24_status_t nrf24_read_status(void) {
    uint8_t result;
    nrf24_csn(0);
    result = nrf24_spi_send_byte(NRF_NOP);
    nrf24_csn(1);
    return result;
}

uint8_t nrf24_read_reg(nrf24_register_t reg) {
    return nrf24_reg(R_REGISTER | reg, 0xff);
}

void nrf24_write_reg(nrf24_register_t reg, uint8_t val) {
    nrf24_reg(W_REGISTER | reg, val);
}


nrf24_status_t nrf24_read_addr(nrf24_register_t reg, uint8_t XRAM* IRAM dest, uint8_t len) {
    return nrf24_read_buf(R_REGISTER | reg, dest, len);
}

nrf24_status_t nrf24_write_addr(nrf24_register_t reg, const uint8_t * IRAM src, uint8_t len) {
    return nrf24_write_buf(W_REGISTER | reg, src, len);
}

nrf24_status_t nrf24_flush_rx(void) {
    return nrf24_write_buf(FLUSH_RX, NULL, 0);
}

nrf24_status_t nrf24_flush_tx(void) {
    return nrf24_write_buf(FLUSH_TX, NULL, 0);
}

nrf24_status_t nrf24_read_rx_payload(uint8_t XRAM* dest, uint8_t len) {
    return nrf24_read_buf(R_RX_PAYLOAD, dest, len);
}

uint8_t nrf24_read_rx_payload_width(void) {
    uint8_t result;
    nrf24_read_buf(R_RX_PL_WID, &result, 1);
    return result;
}

uint8_t nrf24_get_rx_pipe_num(void) {
    return NRF24_STATUS_RX_PIPE(nrf24_read_status());
}

nrf24_status_t nrf24_write_tx_payload(uint8_t *buf, uint8_t len) {
    return nrf24_write_buf(W_TX_PAYLOAD, buf, len);
}

// write an ack payload packet
nrf24_status_t nrf24_write_ack_payload(uint8_t *buf, uint8_t len, uint8_t pipe_num) {
    return nrf24_write_buf(W_ACK_PAYLOAD | (pipe_num & 0b0111), buf, len);
}

// sends packets from the tx fifo until it is empty or a packet fails to send
void nrf24_send_all(void) {
  nrf24_ce(1);
  while( !(nrf24_read_reg(FIFO_STATUS) & FIFO_TX_EMPTY_bm) &&
         !(nrf24_read_status() & STATUS_MAX_RT_bm) );
  nrf24_ce(0);
}

// sends one packet from the tx fifo
void nrf24_send_one(void) {
    nrf24_ce(1);

    // need to hold CE for at least 10μs to transmit a packet
    if (g_slow_clock_mode) {
        static_delay_slow_us(10);
    } else {
        static_delay_us(10);
    }
    nrf24_ce(0);
}

// power set
void nrf24_power_set(bool on) {
    const uint8_t config = nrf24_read_reg(CONFIG);
    uint8_t new_config = config;
    if (on) {
        new_config |= (1<<PWR_UP);
    } else {
        new_config &= ~(1<<PWR_UP);
    }
    if (new_config != config) {
        nrf24_write_reg(CONFIG, new_config);
    }
}
