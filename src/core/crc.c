// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/flash.h"
#include "core/crc.h"

// WARNING: this crc doesn't output 0 when appended with itself
#define CRC16_POLY 0x1021
uint16_t crc16_step(uint16_t crc, uint8_t data, uint8_t num_bits) {
    while (num_bits != 0) {
        bit_t bitn = data & 0x80;
        bit_t crc_carry = crc & 0x8000;
        crc = crc << 1;
        if (crc_carry ^ bitn) {
            crc ^= CRC16_POLY;
        }
        num_bits--;
        data = data << 1;
    }
    return crc;
}

uint16_t crc16_buffer(const uint8_t *buf_ptr, uint8_t length) {
    uint16_t crc = 0xffff;
    while (length-- > 0) {
        crc = crc16_step(crc, *buf_ptr++, 8);
        length--;
    }
    return crc;
}

uint16_t crc16_flash_buffer(flash_ptr_t flash_ptr, uint8_t length) {
    uint16_t crc = 0xffff;
    while (length-- > 0) {
        const uint8_t flash_byte = flash_read_byte(flash_ptr++);
        crc = crc16_step(crc, flash_byte , 8);
    }
    return crc;
}

#if USE_NRF24

#include "core/rf.h"

// expected format
// addr -> transmitter address [5 bytes]
// raw_packet -> PID[9 bit] + payload[x byte] + crc16[2 byte]
// raw_packet.len -> 4+x bytes
// the packet has (x+3)*8+1 bits of actual data
//
// Returns non zero on CRC error
bit_t crc_check_nrf24_raw_packet(XRAM const uint8_t *addr, XRAM uint8_t *raw_packet, uint8_t payload_len) {
    uint16_t crc = 0xffff;
    int8_t i;

    // the crc is computed over the address as well as the data
    for (i = RF_ADDR_WIDTH-1; i >= 0; --i) {
        crc = crc16_step(crc, addr[i], 8);
    }

    // combine (x+3) bytes to the checksum
    for (i = 0; i < payload_len+3; ++i) {
        crc = crc16_step(crc, raw_packet[i], 8);
    }

    // get the one left over bit and apply it to the checksum
    crc = crc16_step(crc, raw_packet[i], 1);

    return crc != 0;
}

#endif
