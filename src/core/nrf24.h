// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "core/nrf24_registers.h"
#include "core/util.h"

#define NRF24_NUMBER_PIPES 6

typedef uint8_t nrf24_status_t;

// platform specific implementations required for this module
void nrf24_init(void);
void nrf24_disable(void);
uint8_t nrf24_spi_send_byte(uint8_t byte);
void nrf24_csn(uint8_t val);
void nrf24_ce(uint8_t val);
nrf24_status_t nrf24_read_status(void);

// read and write single byte registers
uint8_t nrf24_read_reg(nrf24_register_t reg);
void nrf24_write_reg(nrf24_register_t reg, uint8_t val);

// read and write address registers
nrf24_status_t nrf24_read_addr(nrf24_register_t reg, uint8_t XRAM* IRAM dest, uint8_t len);
nrf24_status_t nrf24_write_addr(nrf24_register_t reg, const uint8_t * IRAM src, uint8_t len);

// fn for reading rx payloads
uint8_t nrf24_read_rx_payload_width(void);
uint8_t nrf24_get_rx_pipe_num(void);
nrf24_status_t nrf24_read_rx_payload(uint8_t XRAM* dest, uint8_t len);

// fn for flushing fifos
nrf24_status_t nrf24_flush_rx(void);
nrf24_status_t nrf24_flush_tx(void);

// pwr up and down the nrf24
void nrf24_power_set(bool on);

// fn for writing and sending tx packets
nrf24_status_t nrf24_write_tx_payload(uint8_t *buf, uint8_t len);
nrf24_status_t nrf24_write_ack_payload(uint8_t *buf, uint8_t len, uint8_t pipe_num);
void nrf24_send_one(void);
void nrf24_send_all(void);
