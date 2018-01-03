// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include "core/util.h"

uint16_t crc16_step(uint16_t crc, uint8_t data, uint8_t num_bits);
bit_t crc_check_nrf24_raw_packet(XRAM const uint8_t *addr, XRAM uint8_t *raw_packet, uint8_t payload_len);
uint16_t crc16_buffer(const uint8_t *buf_ptr, uint8_t length);
