// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include "core/util.h"

#define WIRED_PACKET_ADDRESS_BYTE       0
#define WIRED_PACKET_CONTROL_BYTE       1

#define WIRED_ADDRESS_DEVICE_ID_OFFSET  32

#define I2C_GENERAL_CALL_ADDRESS        0x00
#define I2C_BUFFER_COUNT 8
#define I2C_BROADCAST_MAX_SIZE 16

#define CPU_SPEED       F_CPU
#define BAUDRATE        400000
/* #define BAUDRATE        800000 */
/* #define BAUDRATE        1600000 */
/* #define BAUDRATE        1000000 */
#define TWI_BAUDSETTING TWI_BAUD(CPU_SPEED, BAUDRATE)

#define i2c_address_to_device_id(i2c_addr) (i2c_addr - WIRED_ADDRESS_DEVICE_ID_OFFSET)
#define device_id_to_i2c_address(dev_id) (dev_id + WIRED_ADDRESS_DEVICE_ID_OFFSET)

void wired_init(void);
void wired_send_matrix_packet(uint8_t type, uint8_t *data);

void i2c_buffer_advance(void);
uint8_t *i2c_get_buffer(void);
void i2c_init(void);
uint8_t i2c_broadcast(const uint8_t* data, uint8_t size);
uint8_t i2c_get_active_address(void);
uint8_t i2c_calculate_checksum(uint8_t *buffer, uint8_t length);
