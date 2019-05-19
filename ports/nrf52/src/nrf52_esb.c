/**
 * Copyright (c) 2014 - 2019, Nordic Semiconductor ASA
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form, except as embedded into a Nordic
 *    Semiconductor ASA integrated circuit in a product or a software update for
 *    such product, must reproduce the above copyright notice, this list of
 *    conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 *
 * 3. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * 4. This software, with or without modification, must only be used with a
 *    Nordic Semiconductor ASA integrated circuit.
 *
 * 5. Any software provided in binary form under this license must not be reverse
 *    engineered, decompiled, modified and/or disassembled.
 *
 * THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "sdk_common.h"
#include "nrf.h"
#include "nrf_esb.h"
#include "nrf_error.h"
#include "nrf_esb_error_codes.h"
#include "nrf_delay.h"
#include "nrf_gpio.h"
#include "boards.h"
#include "nrf_delay.h"
#include "app_util.h"

#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"

#include "app_error.h"

#include "core/rf.h"
#include "core/led.h"

#include "esb_timeslot.h"

static nrf_esb_payload_t        tx_payload = NRF_ESB_CREATE_PAYLOAD(
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
);
static nrf_esb_payload_t        rx_payload;

#define NUM_ESB_PIPES 6
// #define DEBUG_CHANNEL 11

static uint32_t rx_packet_count;
static uint32_t tx_packet_count;
static uint32_t tx_failed_count;
static bool esb_data_flag;

#if 1
    #include "core/ring_buf.h"
    #include "core/packet.h"
    #include "core/settings.h"
    #include "core/aes.h"
    #define PACKET_BUFFER_MAX_LEN 22
    #define MAX_ESB_PIPE 5

    typedef struct packet_id_t {
        uint8_t sync_state;
        uint32_t check_id;
    } packet_id_t;

    extern XRAM packet_id_t device_uid_list[MAX_NUM_DEVICES];
#endif

void nrf52_esb_packet_buffer_add(nrf_esb_payload_t *packet) {
    if (packet->pipe > MAX_ESB_PIPE) {
        // no data in rx fifo
        return;
    }

    if (packet_buffer_free_space() < packet->length+2) {
        // no space left in buffer
        // nrf_esb_flush_rx();
        // drop packet
        return;
    }

    if (packet->length > PACKET_BUFFER_MAX_LEN) {
        // drop packets that are too large
        return;
    }

    packet_buffer_add_byte(packet->pipe);
    packet_buffer_add_byte(packet->length);

    for (int i = 0; i < packet->length; ++i) {
        packet_buffer_add_byte(packet->data[i]);
    }
}

void rf_esb_write_ack_payload(nrf_esb_payload_t *tx_payload) {
    uint32_t err_code;

#if USE_BLUETOOTH
    if (g_rf_settings.hw_type == RF_HW_BLE_AND_ESB) {
        esb_timeslot_ack_payload(tx_payload);
    } else {
#else
    {
#endif
        if ( (err_code = nrf_esb_write_payload(tx_payload)) == NRF_SUCCESS) {
            // nothing
        } else if (err_code == NRF_ERROR_NO_MEM) {
            NRF_LOG_INFO("tx buffer full, flushing");
            nrf_esb_flush_tx();
        } else {
            NRF_LOG_INFO("tx_payload failed: %d", err_code);
        }
    }
}

void rf_nrf52_load_sync_ack_payload(uint8_t device_id) {
    packet_t *packet = (packet_t*)tx_payload.data;

    // construct the packet
    set_packet_type(packet, PACKET_TYPE_SESSION_UPDATE);
    packet->sync.nonce = device_uid_list[device_id].check_id;
    memset(packet->sync.salt, 0, PACKET_SYNC_SALT_LENGTH);
    // encrypt and load into ack payload fifo

    tx_payload.pipe = device_id_to_pipe_num(device_id);
    tx_payload.length = 16;

    aes_encrypt(tx_payload.data); // PACKET_SIZE is one block

    rf_esb_write_ack_payload(&tx_payload);
}

void nrf_esb_event_handler(nrf_esb_evt_t const * p_event) {
    esb_data_flag = true;
    led_testing_toggle(2);
    switch (p_event->evt_id)
    {
        case NRF_ESB_EVENT_TX_SUCCESS:
            NRF_LOG_DEBUG("TX SUCCESS EVENT");
            tx_packet_count++;
            break;
        case NRF_ESB_EVENT_TX_FAILED:
            NRF_LOG_DEBUG("TX FAILED EVENT");
            tx_failed_count++;
            nrf_esb_flush_tx();
            nrf_esb_start_tx();
            // nrf_esb_pop_tx();
            break;
        case NRF_ESB_EVENT_RX_RECEIVED:
            NRF_LOG_DEBUG("RX RECEIVED EVENT");
            if (rx_payload.length > 15) {
                NRF_LOG_INFO(
                    "tx: %5d rx: %5d drop: %5d ",
                    tx_packet_count,
                    rx_packet_count,
                    tx_failed_count
                );
            }
            while (nrf_esb_read_rx_payload(&rx_payload) == NRF_SUCCESS) {
                if (rx_payload.length > 0) {
                    NRF_LOG_DEBUG("RX RECEIVED PAYLOAD");
                    rx_packet_count++;
                    nrf52_esb_packet_buffer_add(&rx_payload);
                }
            }
            break;
    }
}


void clocks_start( void ) {
    NRF_CLOCK->EVENTS_HFCLKSTARTED = 0;
    NRF_CLOCK->TASKS_HFCLKSTART = 1;

    while (NRF_CLOCK->EVENTS_HFCLKSTARTED == 0);
}


void gpio_init( void ) {
    nrf_gpio_range_cfg_output(8, 15);
    bsp_board_init(BSP_INIT_LEDS);
}

static uint32_t nrf52_esb_init_common(
    nrf_esb_mode_t mode,
    uint8_t tx_pipe_num
) {
    uint32_t err_code;

    uint8_t base_addr_0[4];
    uint8_t base_addr_1[4];

    uint8_t addr_prefix[NUM_ESB_PIPES];
    uint8_t i;

    rx_packet_count = 0;
    tx_packet_count = 0;
    tx_failed_count = 0;
    esb_data_flag = false;

    g_rf_settings.hw_type = RF_HW_NRF52_ESB;

    // memcpy(base_addr_0, g_rf_settings.pipe_addr_0+1, 4);
    for (i = 0; i < 4; ++i) {
        base_addr_0[i] = g_rf_settings.pipe_addr_0[i+1];
    }
    for (i = 0; i < 4; ++i) {
        base_addr_1[i] = g_rf_settings.pipe_addr_1[i+1];
    }

    addr_prefix[0] = g_rf_settings.pipe_addr_0[0];
    addr_prefix[1] = g_rf_settings.pipe_addr_1[0];
    addr_prefix[2] = g_rf_settings.pipe_addr_2;
    addr_prefix[3] = g_rf_settings.pipe_addr_3;
    addr_prefix[4] = g_rf_settings.pipe_addr_4;
    addr_prefix[5] = g_rf_settings.pipe_addr_5;

    #if DEBUG_CHANNEL
        uint8_t rf_channel = DEBUG_CHANNEL;
    #else
        uint8_t rf_channel = g_rf_settings.channel;
    #endif

    // The ARD is given by `(ard + 1) * 250µs` with a maximum delay of 4ms.
    const uint8_t dev_ard = device_id_to_pipe_num(GET_SETTING(device_id)) + 1;
    const uint32_t ard_in_ms = (dev_ard + 1) * 250;
    const uint8_t arc = g_rf_settings.arc & 0x0F;

    nrf_esb_config_t nrf_esb_config         = NRF_ESB_DEFAULT_CONFIG;
    nrf_esb_config.protocol                 = NRF_ESB_PROTOCOL_ESB_DPL;
    nrf_esb_config.retransmit_delay         = ard_in_ms;
    nrf_esb_config.bitrate                  = NRF_ESB_BITRATE_2MBPS;
    nrf_esb_config.crc                      = NRF_ESB_CRC_16BIT;
    nrf_esb_config.event_handler            = nrf_esb_event_handler;
    nrf_esb_config.selective_auto_ack       = false;
    nrf_esb_config.payload_length           = 32;
    nrf_esb_config.retransmit_count         = arc;

    nrf_esb_config.mode                     = mode;

    err_code = nrf_esb_init(&nrf_esb_config);

    APP_ERROR_CHECK(err_code);

    err_code = nrf_esb_set_base_address_0(base_addr_0);
    APP_ERROR_CHECK(err_code);

    if (mode == NRF_ESB_MODE_PRX) {
        err_code = nrf_esb_set_base_address_1(base_addr_1);
        APP_ERROR_CHECK(err_code);

        err_code = nrf_esb_set_prefixes(addr_prefix, NUM_ESB_PIPES);
        APP_ERROR_CHECK(err_code);
    } else if (mode == NRF_ESB_MODE_PTX) {
        err_code = nrf_esb_set_prefixes(addr_prefix, 1);
        APP_ERROR_CHECK(err_code);
    }

    err_code = nrf_esb_set_rf_channel(rf_channel);
    APP_ERROR_CHECK(err_code);

    return err_code;
}

uint32_t nrf52_esb_init_tx( void ) {
    ret_code_t err_code;

    const uint8_t pipe_num = device_id_to_pipe_num(GET_SETTING(device_id));
    nrf52_esb_init_common(NRF_ESB_MODE_PTX, pipe_num);

    err_code = nrf_esb_start_tx();
    APP_ERROR_CHECK(err_code);

    return err_code;
}

uint32_t nrf52_esb_init_rx( void ) {
    ret_code_t err_code;

    nrf52_esb_init_common(NRF_ESB_MODE_PRX, 0);

    err_code = nrf_esb_start_rx();
    APP_ERROR_CHECK(err_code);

    return err_code;
}

uint32_t nrf52_esb_init_unifying_pair(
    const XRAM uint8_t *unifying_pairing_addr,
    const XRAM uint8_t *target_addr,
    uint8_t addr_lsb
) {
    // Use first three pipes
    // P0 = BB:0A:DC:A5:75
    // P1 = TARGET_ADDRESS
    // P2 = TARGET_ADDRESS with LSB set to 0
    // P3..P5 = disabled

    ret_code_t err_code;

    nrf52_esb_init_common(NRF_ESB_MODE_PRX, 0);

    // Set unifying pairing addresses
    {
        uint8_t prefixes[3] = {
            unifying_pairing_addr[0],
            addr_lsb,
            0x00,
        };
        nrf_esb_enable_pipes(0);
        nrf_esb_set_base_address_0(unifying_pairing_addr + 1);
        nrf_esb_set_base_address_1(target_addr + 1);
        nrf_esb_set_prefixes(prefixes, 3);
    }

    err_code = nrf_esb_start_rx();
    APP_ERROR_CHECK(err_code);

    return err_code;
}

void nrf52_esb_hw_init(void) {
    clocks_start();
}
