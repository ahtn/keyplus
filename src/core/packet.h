// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <stdint.h>
#include <stdbool.h>

//
// need packets for:

// split keyboard matrix packet
// generic keyboard matrix packet
// empty keyboard matrix packet, with other data
//
// hid keycode packet
// extended hid keycode packet
// empty hid keycode packet, with other data
//
// ran out of PID/SID pair
/* enum packet_type_t { */
/* }; */
#define PACKET_TYPE_DEBUG          0x00 // debug info
#define PACKET_TYPE_KEYCODE        0x01 // hid keycodes
#define PACKET_TYPE_SESSION_UPDATE 0x02 // update for session id
#define PACKET_TYPE_EMPTY_MATRIX   0x03 // no keys, pressed
#define PACKET_TYPE_MATRIX         0x80 // keymatrix

#define PACKET_SIZE 16
#define PACKET_PAYLOAD_LENGTH 11
#define PACKET_SYNC_SALT_LENGTH (PACKET_PAYLOAD_LENGTH-5)
#define PACKET_ID_MAX_INCREMENT_BITS 16
#define PACKET_ID_MAX_INCREMENT ((uint32_t)1 << PACKET_ID_MAX_INCREMENT_BITS)
#define PACKET_ID_MAX_INCREMENT_MASK ((uint32_t)(~((uint32_t)0)<<PACKET_ID_MAX_INCREMENT_BITS))

#define PACKET_MATRIX_SIZE_MASK 0x1f
#define PACKET_MATRIX_TYPE_MASK 0xe0
#define PACKET_MATRIX_TYPE_BIT_POS 5

// non-zero indicates pressed
// zero indicates released
#define MATRIX_DELTA_TYPE_MASK 0x80
#define MATRIX_DELTA_TYPE_PRESSED 0x80
#define MATRIX_DELTA_TYPE_RELEASED 0x00

#define MATRIX_DELTA_KEY_MASK 0x7f

typedef enum {
    PACKET_MATRIX_RAW = 0x00,
    PACKET_MATRIX_KEY_LIST = 0x01,
    PACKET_MATRIX_DELTA_LIST = 0x02,
    PACKET_MATRIX_RESERVED = 0x03,
} wired_packet_type_t;

// 16 bytes
typedef struct packet_base_t {
    uint8_t payload[PACKET_PAYLOAD_LENGTH];
    uint8_t device_id;
    uint32_t packet_id;
} packet_base_t;

typedef struct packet_generic_t {
    uint8_t type;
    uint8_t payload[PACKET_PAYLOAD_LENGTH-1];
    uint8_t device_id;
    uint32_t packet_id;
} packet_generic_t;

typedef struct packet_matrix_t {
    uint8_t matrix_data[PACKET_PAYLOAD_LENGTH];
    uint8_t device_id;
    uint32_t packet_id;
} packet_matrix_t;

typedef struct packet_sync_t {
    uint8_t type;
    uint32_t nonce;
    uint8_t salt[PACKET_SYNC_SALT_LENGTH];
    uint8_t device_id;
    uint32_t packet_id;
} packet_sync_t;

typedef union packet_t {
    packet_base_t base;
    packet_generic_t gen;
    packet_sync_t sync;
    packet_matrix_t matrix;
    uint8_t raw[PACKET_SIZE];
} packet_t;

uint8_t get_packet_type(const packet_t *packet);
void set_packet_type(packet_t *packet, uint8_t type);
bool is_matrix_packet(packet_t *packet);
