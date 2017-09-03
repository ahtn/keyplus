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

extern XRAM bool g_rf_enabled;

void rf_init_send(void);
void rf_init_receive(void);

void rf_auto_ack(bit_t enabled);
bit_t is_auto_ack_enabled(void);

bit_t rf_task(void);

void rf_send_matrix_packet(void);
void rf_handle_ack_payloads(void);

void rf_receive_buffer_add(void);

void rf_enable_isr(void);
void rf_disable_receive_irq(void);

void rf_isr(void);
