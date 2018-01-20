// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/unifying.h"

#include <string.h>

#include "core/led.h"
#include "core/nrf24.h"
#include "core/rf.h"
#include "core/settings.h"
#include "core/timer.h"
#include "core/usb_commands.h"

#include "core/matrix_interpret.h"
#include "core/mouse_report.h"
#include "core/hardware.h"

/* #include "core/.h" */

// NOTE: For uniyfing devices to work, we need to dedicated at least 2 pipes
// for the device. These two pipes have the form:
// X0 = XX:XX:XX:XX:00
// X1 = XX:XX:XX:XX:DD
// where the 4 upper most bytes match. When a unifying device starts, it tries
// to connect to the dongle by pinging the dongles address X0. If it gets a
// response it, will then start sending messages on its own pipe X1. If it
// disconnects, it will go back to pinging X0.

#define UNIFYING_ADDR_WIDTH 5

XRAM unifying_mouse_state_t g_unifying_mouse_state = {0};
XRAM uint8_t g_unifying_mouse_state_changed = false;

// Address for the initial unifying pairing request.
// Note: Addresses are stored in little endian format, because writes to
// the address registers are written LSB bit first
// BB:0A:DC:A5:75
static XRAM uint8_t unifying_pairing_addr[5] = {0x75, 0xA5, 0xDC, 0x0A, 0xBB};
static XRAM uint8_t last_pairing_step = UNIFYING_PAIR_DISABLED;
static XRAM uint8_t pairing_target_addr[UNIFYING_ADDR_WIDTH];
static XRAM uint8_t tmp_buffer[32];
static XRAM uint16_t pairing_timeout;
static XRAM uint16_t packet_timeout;

// TODO: make rf.c share this code
static uint8_t check_checksum(const uint8_t *data, const uint8_t len) {
    uint8_t i;
    uint8_t result = 0;
    for (i=0; i < len; ++i) {
        result += data[i];
    }
    return result;
}

static uint8_t calc_checksum(const uint8_t *data, const uint8_t len) {
    return -check_checksum(data, len);
}

void unifying_read_packet(uint8_t *nrf_packet) {
    const uint8_t nrf_packet_type = nrf_packet[1];
    switch (nrf_packet_type) {
        case 0xC2: {
            uint16_t data[4];
            uint16_t x = ((nrf_packet[5] & 0x0f) << 8) | nrf_packet[4];
            uint16_t y = (uint16_t)((nrf_packet[6]) << 4) | (uint16_t)((nrf_packet[5] & 0xf0) >> 4);
            g_unifying_mouse_state.buttons_1 = nrf_packet[2];
            g_unifying_mouse_state.buttons_2 = nrf_packet[3];
            g_unifying_mouse_state.x = sign_extend_12(x);
            g_unifying_mouse_state.y = sign_extend_12(y);
            g_unifying_mouse_state.wheel_y = nrf_packet[7];
            g_unifying_mouse_state.wheel_x = nrf_packet[8];
            g_unifying_mouse_state_changed = true;
            data[0] = x;
            data[1] = y;
            data[2] = g_unifying_mouse_state.x;
            data[3] = g_unifying_mouse_state.y;
            /* mouse_active = true; */
        } break;

        /* case 0x4f: { */
        /*  /1* g_unifying_mouse_state_changed = true; *1/ */
        /* } break; */

        /* case 0x40: { */
        /*  /1* mouse_active = false; *1/ */
        /*  /1* if (mouse_active) { *1/ */
        /*      g_unifying_mouse_state_changed = true; *1/ */
        /*  /1* } *1/ */
        /*  /1* memset(&g_unifying_mouse_state, 0, sizeof(g_unifying_mouse_state)); *1/ */
        /* } */
    }
}

void unifying_mouse_handle(void) {
    // TODO: clean this up
    // make it so that unifying mouse overides keyboard mouse
    if (!g_unifying_mouse_state_changed) {
        return;
    }
    g_mouse_report.buttons_1 = g_unifying_mouse_state.buttons_1;
    g_mouse_report.buttons_2 = g_unifying_mouse_state.buttons_2;
    if (g_mouse_report.buttons_1 || g_mouse_report.buttons_2) {
        clear_sticky_mods();
    }

    g_mouse_report.x = g_unifying_mouse_state.x;
    g_mouse_report.y = g_unifying_mouse_state.y;

    g_report_pending_mouse = true;
    g_unifying_mouse_state_changed = false;;

    /* TODO: test code only, remove later */
    /* if (keyboard_get_layer_mask(0) & (1 << 6)) { */
    /*  if (g_unifying_mouse_state.wheel_y > 0) { */
    /*      g_media_report.id = REPORT_ID_CONSUMER; */
    /*      g_media_report.code = HID_CONSUMER_VOLUME_INCREMENT; */
    /*      g_report_pending_media = true; */
    /*  } else if (g_unifying_mouse_state.wheel_y < 0) { */
    /*      g_media_report.id = REPORT_ID_CONSUMER; */
    /*      g_media_report.code = HID_CONSUMER_VOLUME_DECREMENT; */
    /*      g_report_pending_media = true; */
    /*  } else if (g_unifying_mouse_state.wheel_y == 0) { */
    /*      g_media_report.id = REPORT_ID_CONSUMER; */
    /*      g_media_report.code = 0; */
    /*      g_report_pending_media = true; */
    /*      g_mouse_report.wheel_x = g_unifying_mouse_state.wheel_x; */
    /*      g_mouse_report.wheel_y = g_unifying_mouse_state.wheel_y; */
    /*  } */
    /*  return; */
    /* } */

#if 1
    g_mouse_report.wheel_x = SIGN(g_unifying_mouse_state.wheel_x);
    g_mouse_report.wheel_y = SIGN(g_unifying_mouse_state.wheel_y);
#else
    g_mouse_report.wheel_x = g_unifying_mouse_state.wheel_x;
    g_mouse_report.wheel_y = g_unifying_mouse_state.wheel_y;
#endif
}

void unifying_begin_pairing(void) {
    uint8_t config;

    disable_interrupts();

    rf_init_receive(); // set rf settings for receive mode

    unifying_set_pairing_address(g_rf_settings.pipe_addr_1, g_rf_settings.pipe_addr_4);

    // TODO: probably add interrupt based mode later, but for now just mask the
    // IRQ for the NRF
    config = nrf24_read_reg(CONFIG);
    config = config | MASK_ALL_IRQ_bm;
    nrf24_write_reg(CONFIG, config);

    enable_interrupts();
    last_pairing_step = 0;
    pairing_timeout = timer_read16_ms() + UNIFYING_PAIRING_TIMEOUT;
}

void unifying_end_pairing(void) {
    last_pairing_step = UNIFYING_PAIR_DISABLED;
    rf_init_receive();
}

bit_t unifying_is_pairing_active(void) {
    return last_pairing_step != UNIFYING_PAIR_DISABLED;
}

// Note: Assumes all other relevant settings are in place
void unifying_set_pairing_address(const uint8_t *target_addr, uint8_t addr_lsb) {
    // Use first three pipes
    // P0 = BB:0A:DC:A5:75
    // P1 = TARGET_ADDRESS
    // P2 = TARGET_ADDRESS with LSB set to 0
    // P3..P5 = disabled
    nrf24_write_addr(TX_ADDR, unifying_pairing_addr, UNIFYING_ADDR_WIDTH);
    nrf24_write_addr(RX_ADDR_P0, unifying_pairing_addr, UNIFYING_ADDR_WIDTH);

    memcpy(pairing_target_addr, target_addr, UNIFYING_ADDR_WIDTH);
    pairing_target_addr[0] = addr_lsb;

    // set MSB of addr, assumes addresses are stored in little endian
    nrf24_write_addr(RX_ADDR_P1, pairing_target_addr, UNIFYING_ADDR_WIDTH);
    nrf24_write_reg(RX_ADDR_P2, 0);

    nrf24_write_reg(EN_RXADDR, 0b0111);
}

bit_t handle_pairing(uint8_t pipe_num) {
    unifying_packet_t *packet = (unifying_packet_t*)tmp_buffer;
    uint8_t width = nrf24_read_rx_payload_width();

    nrf24_read_rx_payload(tmp_buffer, width);

    if (pipe_num > 1) {
        return false;
    }

    if ( check_checksum(tmp_buffer, width) ) {
        return false;
    }

    if ( !(packet->header.type == FRAME_PAIRING || packet->header.type == 0x0f ||
            last_pairing_step >= 3)) {
        return false;
    }

    last_pairing_step++;

    tmp_buffer[width] = last_pairing_step;
    usb_print(tmp_buffer, width+1);

    packet_timeout = timer_read16_ms() + UNIFYING_PAIRING_PACKET_TIMEOUT;

    if (packet->header.step == 1 && last_pairing_step == 1) {


        packet->req_1.frame_type = 0x1f;
        //req_1->step = 1;

        packet->req_1.addr[0] = pairing_target_addr[4];
        packet->req_1.addr[1] = pairing_target_addr[3];
        packet->req_1.addr[2] = pairing_target_addr[2];
        packet->req_1.addr[3] = pairing_target_addr[1];
        packet->req_1.addr[4] = pairing_target_addr[0];

        packet->req_1.csum = calc_checksum(tmp_buffer, sizeof(unifying_req_1_t)-1);

        nrf24_write_ack_payload(tmp_buffer, sizeof(unifying_req_1_t), pipe_num);
        //nrf24_write_ack_payload(2, tmp_buffer, sizeof(req_1_t));
        //uint8_t fifo = read_reg(FIFO_STATUS);

        /* p("\na%d w%d: ", pipe_num, sizeof(req_1_t)); */
        /* print_buf(tmp_buffer, sizeof(req_1_t)); */
        /* p("\n"); */
    } else if (packet->header.step == 2 && last_pairing_step == 2) {
        packet->req_2.frame_type = 0x1f;
        //req_2->step = 2;

        // TODO: something with data received here

        packet->req_2.csum = calc_checksum(tmp_buffer, sizeof(unifying_req_2_t)-1);

        /* nrf24_write_ack_payload(pipe_num, (uint8_t*)packet->req_2, sizeof(unifying_req_2_t)); */
        nrf24_write_ack_payload(tmp_buffer, sizeof(unifying_req_2_t), pipe_num);

        /* p("\na%d w%d: ", pipe_num, sizeof(packet->req_1_t)); */
        /* print_buf(tmp_buffer, sizeof(packet->req_1_t)); */
        /* p("\n"); */
    } else if (packet->header.step == 3 && last_pairing_step == 3) {
        packet->resp_3.frame_type = 0x0f;
        //resp_3->step = 6;

        // TODO: do something with data received here
        //memset(resp_3->crypto, 0, 6);

        packet->resp_3.csum = calc_checksum(tmp_buffer, sizeof(unifying_resp_3_t)-1);

        nrf24_write_ack_payload(tmp_buffer, sizeof(unifying_resp_3_t), pipe_num);

        /* p("\na%d w%d: ", pipe_num, sizeof(packet->resp_3_t)); */
        /* print_buf(tmp_buffer, sizeof(packet->resp_3_t)); */
    } else if (last_pairing_step >= 10) {
        // Successfully paired with the device, and received a packet from it
        // after it has paired
        return true;
    }
    return false;
}

// TODO: add interrupt based mode?
void unifying_pairing_poll(void) {
    uint8_t pipe_num = nrf24_get_rx_pipe_num();
    uint8_t pairing_complete = false;

    while (pipe_num != 0b111) {
        pairing_complete |= handle_pairing(pipe_num);

        led_testing_toggle();
        pipe_num = nrf24_get_rx_pipe_num();
    }

    if (has_passed_time16(timer_read16_ms(), packet_timeout)) {
        last_pairing_step = 0;
    }

    if (
        pairing_complete ||
        has_passed_time16(timer_read16_ms(), pairing_timeout)
    ) {
        reset_mcu();
    }
}
