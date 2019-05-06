// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <stdint.h>
#include "core/util.h"
#include "core/matrix_interpret.h"
#include "core/unifying.h"
#include "core/nonce.h"

// number of consecutive invalid packets required before a session is terminated
#define PACKET_FAIL_LIMIT 6

#define KEYBOARD_PAYLOAD_LENGTH 16
#define MAX_PAYLOAD_LENGTH 32

#define RF_ADDR_WIDTH 5

#define NUM_KEYBOARD_PIPES 4
#define UNIFYING_RF_PIPE_MOUSE 4
#define UNIFYING_RF_PIPE_DONGLE 5

typedef enum {
    RF_HW_NRF24L01 = 0,
    RF_HW_NRF52_ESB = 1,
} rf_hw_type_t;

extern XRAM uint8_t g_rf_enabled;

void rf_init_send(void);
void rf_init_receive(void);

#if SUPPORT_MULTI_RECEIVER
void rf_auto_ack(bit_t enabled);
bit_t is_auto_ack_enabled(void);
#endif

uint8_t device_id_to_pipe_num(const uint8_t device_id);
uint8_t packet_buffer_free_space(void);
void packet_buffer_add_byte(uint8_t byte);
uint8_t packet_buffer_get(void);
uint8_t packet_buffer_len(void);
void packet_buffer_clear(void);
bit_t packet_buffer_has_data(void);
void packet_buffer_take(XRAM uint8_t *dest, uint8_t width);

bit_t rf_task(void);

void rf_send_matrix_packet(void);
void rf_handle_ack_payloads(void);

void rf_receive_buffer_add(void);

void rf_init_receive_irq(void);
void rf_enable_receive_irq(void);
void rf_disable_receive_irq(void);

void rf_isr(void);
