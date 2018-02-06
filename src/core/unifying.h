// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include "core/util.h"

#define UNIFYING_PAIR_FAILED 0
#define UNIFYING_PAIR_IN_PROGRESS 1
#define UNIFYING_PAIR_FINISHED 2
#define UNIFYING_PAIR_DISABLED 255

// If pairing is not complete in this time, fail
#define UNIFYING_PAIRING_TIMEOUT 20000
#define UNIFYING_PAIRING_PACKET_TIMEOUT 2000

typedef enum {
    FRAME_PAIRING = 0x5f,
} frame_type_t;

typedef struct {
    uint8_t id;
    uint8_t type;
    uint8_t step;
} unifying_packet_header_t;

typedef struct {
    uint8_t id;
    uint8_t frame_type;
    uint8_t step;
    uint8_t addr[5];
    uint8_t unknown_1;
    uint16_t pid;
    uint8_t unknown_2[2];
    uint16_t type;
    uint8_t unknown_3[5];
    uint8_t unknown_4;
    uint8_t csum;
} unifying_req_1_t;

typedef struct {
    uint8_t id;
    uint8_t frame_type;
    uint8_t step;
    uint8_t crypto[4];
    uint8_t serial[4];
    uint16_t ability;
    uint8_t unknown_1[8];
    uint8_t csum;
} unifying_req_2_t;

typedef struct {
    uint8_t id;
    uint8_t frame_type;
    uint8_t step;
    uint8_t unknown_1[2];
    uint8_t len;
    uint8_t dev_str[16];
    uint8_t csum;
} unifying_req_3_t;

typedef struct {
    uint8_t id;
    uint8_t frame_type;
    uint8_t step;
    uint8_t crypto[6];
    uint8_t csum;
} unifying_resp_3_t;

typedef struct {
    uint8_t id;
    uint8_t frame_type;
    uint8_t step;
    uint8_t cryto[6];
    uint8_t csum;
} unifying_req_4_t;

typedef union unifying_packet_t {
    unifying_packet_header_t header;
    unifying_req_1_t req_1;
    unifying_req_2_t req_2;
    unifying_req_3_t req_3;
    unifying_resp_3_t resp_3;
    unifying_req_4_t req_4;
} unifying_packet_t;

typedef struct unifying_mouse_state_t {
    uint8_t buttons_1;
    uint8_t buttons_2;
    int16_t x;
    int16_t y;
    int8_t wheel_x;
    int8_t wheel_y;
} unifying_mouse_state_t;

extern XRAM unifying_mouse_state_t g_unifying_mouse_state;
extern XRAM uint8_t g_unifying_mouse_state_changed;

uint8_t unifying_calc_checksum(const XRAM uint8_t *data, const uint8_t len);
void unifying_mouse_handle(void);
void unifying_pairing_poll(void);
void unifying_set_pairing_address(const XRAM uint8_t *target_addr, uint8_t addr_lsb);
void unifying_read_packet(uint8_t XRAM *nrf_packet);
void unifying_begin_pairing(void);
bit_t unifying_is_pairing_active(void);
