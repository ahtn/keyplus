// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/rf.h"

#include <string.h>

#include "core/aes.h"
#include "core/flash.h"
#include "core/led.h"
#include "core/nrf24.h"
#include "core/packet.h"
#include "core/settings.h"
#include "core/util.h"

#define NUM_KEYBOARD_PIPES 4

#define RF_CRC_MODE (EN_CRC_bm | CRCO_bm)

#define DEV_STATE_DISCONNECTED  0x00
#define DEV_STATE_SYNCING_0     0x40
#define DEV_STATE_SYNCED_0      0x80

XRAM bool g_rf_enabled;

// #define NRF24_IRQ_MASKS (MASK_TX_DS_bm | MASK_MAX_RT_bm)
// #define NRF24_IRQ_MASKS (0x70)
#define NRF24_IRQ_MASKS (0x00)

void nrf_registers_common(void) {
    // When ack payloads > 15bytes are used @2Mbps, need ARD >=500µs.
    // maybe increase the auto matic retransmit delay?
    // The ARD is given by `(ard + 1) * 250µs` with a maximum delay of 4ms.
    const uint8_t rf_ard = device_id_to_pipe_num(GET_SETTING(device_id)) + 1;

    nrf24_write_reg(CONFIG, NRF24_IRQ_MASKS); // need to power down before settings these registers
    nrf24_write_reg(RF_SETUP, RF_DR_2MBPS | PWR_0DB);
    nrf24_write_reg(SETUP_AW, ((RF_ADDR_WIDTH - 2) & 0x3));
    nrf24_write_reg(RF_CH, g_rf_settings.channel);
    nrf24_write_reg(FEATURE, EN_DPL_bm | EN_ACK_PAY_bm);
    nrf24_write_reg(SETUP_RETR, ((rf_ard & 0xf) << ARD) | ((g_rf_settings.arc & 0xf) << ARC));
}

#include "core/usb_commands.h"

#ifndef NO_RF_TRANSMIT

#include "core/matrix_scanner.h"
#include "core/matrix_scanner.h"

/* TODO: move settings */
static void nrf_registers_init_sender(void) {
    const uint8_t pipe_num = GET_SETTING(device_id) % NUM_KEYBOARD_PIPES;
    // radio settings
    nrf_registers_common();

    // address settings
    if (pipe_num == 0) {
        nrf24_write_addr(RX_ADDR_P0, g_rf_settings.pipe_addr_0, RF_ADDR_WIDTH);
        nrf24_write_addr(TX_ADDR,    g_rf_settings.pipe_addr_0, RF_ADDR_WIDTH);
    } else if (pipe_num >= 1) {
        nrf24_write_addr(RX_ADDR_P0, g_rf_settings.pipe_addr_1, RF_ADDR_WIDTH);
        nrf24_write_addr(TX_ADDR,    g_rf_settings.pipe_addr_1, RF_ADDR_WIDTH);

        // the pipes P2-P5 are the same as P1 except for their least significat
        // byte. So set that byte here.
        if (pipe_num >= 2) {
            uint8_t *pipe_addr = &g_rf_settings.pipe_addr_2 + (pipe_num-2);
            nrf24_write_addr(RX_ADDR_P0, pipe_addr, 1);
            nrf24_write_addr(TX_ADDR,    pipe_addr, 1);
        }
    }

    // pipe settings
    nrf24_write_reg(EN_AA, 0x01); // enable auto ack, on P0
    nrf24_write_reg(EN_RXADDR, 0x01); // enable rx pipes: P0 for auto ack response
    nrf24_write_reg(DYNPD, 0x01);
    nrf24_write_reg(RX_PW_P0, 32);
}

void rf_init_send(void) {
    nrf24_init();

    nrf_registers_init_sender();

    nrf24_flush_rx();
    nrf24_flush_tx();

    nrf24_write_reg(CONFIG, RF_CRC_MODE | PWR_UP_bm | (0<<PRIM_RX) | NRF24_IRQ_MASKS);
    nrf24_ce(0);
}

void rf_send_matrix_packet(void) {
    XRAM packet_matrix_t packet;

    const uint8_t matrix_size = get_matrix_data(packet.matrix_data, false);

    if (matrix_size < PACKET_PAYLOAD_LENGTH) {
        memset(packet.matrix_data+matrix_size, 0, PACKET_PAYLOAD_LENGTH-matrix_size);
    }

    // TODO: make a function that does this for us
    packet.device_id = GET_SETTING(device_id);
    packet.packet_id = uid_generate();

    aes_encrypt((uint8_t*)&packet);
    nrf24_write_tx_payload((uint8_t*)&packet, AES_BUF_SIZE);
}

void rf_handle_ack_payloads(void) {
    XRAM uint8_t data_buffer[MAX_PAYLOAD_LENGTH];
    uint8_t pipe_no;
    while ( (pipe_no = nrf24_get_rx_pipe_num() ) != STATUS_RX_FIFO_EMPTY) {
        uint8_t payload_width = nrf24_read_rx_payload_width();
        if (payload_width != PACKET_SIZE) {
            continue;
        }
        nrf24_read_rx_payload(data_buffer, payload_width);
        aes_decrypt(data_buffer);
        {
            packet_t *packet = (packet_t*)data_buffer;
            if (get_packet_type(packet) == PACKET_TYPE_SESSION_UPDATE &&
                    is_buffer_zeroed(packet->sync.salt, PACKET_SYNC_SALT_LENGTH)) {
                set_packet_type(packet, PACKET_TYPE_SESSION_UPDATE);
                packet->sync.nonce = packet->sync.nonce;
                packet->sync.device_id = GET_SETTING(device_id);
                packet->sync.packet_id = uid_generate();
                memset(packet->sync.salt, 0, PACKET_SYNC_SALT_LENGTH);

                memcpy(data_buffer, (uint8_t*)packet, 16);
                aes_encrypt(data_buffer);
                nrf24_write_tx_payload(data_buffer, 16);
                nrf24_send_all();

                rf_send_matrix_packet();
            }
        }
    }
}
#endif

#ifndef NO_RF_RECEIVE

#define RECEIVE_BUFFER_MAX_LENGTH 8

typedef struct {
    uint8_t pipe_num;
    uint8_t width;
    uint8_t payload[22];
} nrf_packet_t;

volatile XRAM uint8_t s_receive_buffer_len;
XRAM nrf_packet_t s_receive_buffer[RECEIVE_BUFFER_MAX_LENGTH];

static bit_t auto_ack = true;

typedef struct packet_id_t {
    uint8_t sync_state;
    uint32_t check_id;
} packet_id_t;

// TODO: put this in an `init` function
static XRAM packet_id_t device_uid_list[MAX_NUM_DEVICES];
static XRAM uint16_t last_crc[NRF24_NUMBER_PIPES];

static void nrf_registers_init_receiver(void) {
    uint8_t i;

    nrf_registers_common();

    { // pipe addresses
        nrf24_write_addr(RX_ADDR_P0, g_rf_settings.pipe_addr_0, RF_ADDR_WIDTH);
        nrf24_write_addr(RX_ADDR_P1, g_rf_settings.pipe_addr_1, RF_ADDR_WIDTH);

        // initialize addresses for pipes P2 to P5
        for (i = 0; i < 4; ++i) {
            nrf24_write_reg(RX_ADDR_P2+i, ((uint8_t*)&g_rf_settings.pipe_addr_2)[i]);
        }
    }

    { // pipe settings
        // set max payload for pipes
        for (i = 0; i < 6; ++i) {
            nrf24_write_reg(RX_PW_P0+i, 32);
        }

        // enable rx with auto ack and dynamic payload on all channels
        nrf24_write_reg(EN_AA, 0x3f); // receiver channel
        nrf24_write_reg(EN_RXADDR, 0x3f); // enable address
        nrf24_write_reg(DYNPD, 0x3f);
    }
}

static void init_uid_buffer_list(void) {
    memset(device_uid_list, 0, sizeof(device_uid_list));
}

void rf_init_receive(void) {
    nrf24_init();

    nrf_registers_init_receiver();
    init_uid_buffer_list();

    // init the receiver
    nrf24_flush_rx();
    nrf24_flush_tx();

    nrf24_write_reg(CONFIG, RF_CRC_MODE | PWR_UP_bm | (1<<PRIM_RX) | NRF24_IRQ_MASKS);

    nrf24_write_reg(NRF_STATUS, 0x70);

    s_receive_buffer_len = 0;
#if !RF_POLLING
    rf_enable_receive_irq();
#endif

    // enable the receiver
    nrf24_ce(1);
}

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

// expected format
// addr -> transmitter address [5 bytes]
// raw_packet -> PID[9 bit] + payload[x byte] + crc16[2 byte]
// raw_packet.len -> 4+x bytes
// the packet has (x+3)*8+1 bits of actual data
//
// Returns non zero on CRC error
bit_t check_packet_crc(const uint8_t *addr, uint8_t *raw_packet, uint8_t payload_len) {
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



// To disable sending auto ack packets as a receiver, we need to disable
// enhanced shockburst mode and read the enhanced shockburst packets the
// and validate the crc ourself

// regular shockburst packet
// | preamble 1byte | Addr 3-5byte | payload 1-32byte | CRC 1-2 |

// enhanced shockburst packet
// | preamble 1byte | Addr 3-5byte | packet ctrl field 9bit | payload 0-32byte | CRC 1-2 |

// To read an enhanced shockburst packet in regular mode, need to set the payload
// length to +2

void rf_auto_ack(bit_t enabled) {
    auto_ack = enabled;
    dongle_active = enabled;
    if (enabled) {
        // enable enhanced shock burst
        nrf24_ce(0);
        rf_init_receive();
        nrf24_ce(1);
    } else {
        // disable enhanced shock burst, but still read the packets
        nrf24_ce(0);
        nrf24_write_reg(EN_AA, 0x00);
        nrf24_write_reg(EN_RXADDR, 0x0f);       // enable address
        nrf24_write_reg(DYNPD, 0x00);
        nrf24_write_reg(FEATURE, 0x00);
        // 9bit ctrl field + 2 byte crc16, so need 4 bytes extra
        nrf24_write_reg(RX_PW_P0, KEYBOARD_PAYLOAD_LENGTH+4);
        nrf24_write_reg(RX_PW_P1, KEYBOARD_PAYLOAD_LENGTH+4);
        nrf24_write_reg(RX_PW_P2, KEYBOARD_PAYLOAD_LENGTH+4);
        nrf24_write_reg(RX_PW_P3, KEYBOARD_PAYLOAD_LENGTH+4);
        nrf24_write_reg(CONFIG, PWR_UP_bm | (1<<PRIM_RX) | NRF24_IRQ_MASKS); // don't validate crc
        nrf24_ce(1);
    }
    nrf24_flush_rx();
}

bit_t is_auto_ack_enabled(void) {
    return auto_ack;
}

// This function is used when a new device wants to connect to this receiver.
// To prevent replay attacks, we construct a challenge packet to be sent to
// the device. If the device can't correctly respond to the challenge, then it
// is not allowed to connect.
//
// The challenge packet relies on the preshared key between the two devices.
// We encrypt an UID and send it to the slave. Then to pass the challenge the
// slave must be able to decrypt the packet and send back an encrypted packet
// with UID+1. This protects us from replay attacks because even if the attacker
// knows what UID is, they will not be able to construct response packet because
// they do not hold our preshared encryption key. If they try send a response
// to the receiver, it will decrypt to junk data and be rejected.
void rf_load_sync_ack_payload(uint8_t device_id) {
    XRAM uint8_t tmp_buffer[MAX_PAYLOAD_LENGTH];
    packet_t *packet = (packet_t*)tmp_buffer;
    // consturct the packet
    set_packet_type(packet, PACKET_TYPE_SESSION_UPDATE);
    packet->sync.nonce = device_uid_list[device_id].check_id;
    memset(packet->sync.salt, 0, PACKET_SYNC_SALT_LENGTH);
    // encrypt and load into ack payload fifo
    aes_encrypt(tmp_buffer);
    nrf24_write_ack_payload(tmp_buffer, PACKET_SIZE, device_id_to_pipe_num(device_id));
}

// For a packet to be valid:
// * its pipe must be correctly associated with the device_id in the packet
// * the packet ID can't be older then the most recently received packet for
//      the device
// * the packet ID must be within a relatively small interval from the last
//      received packet.
//
// If we receive too many invalid packets, the device will be disconnected
// from the receive and will have to pass the challenge-response authentication
// again.
bit_t is_valid_packet(const packet_t *packet, uint8_t pipe_num) {
    const uint8_t device_id = packet->gen.device_id;
    const uint32_t pid = packet->gen.packet_id;
    const uint32_t last_pid = device_uid_list[device_id].check_id;
    // packet needs to be received on the correct pipe for its device id
    if (device_id % NUM_KEYBOARD_PIPES != pipe_num) {
        return false;
    }
    // only except small jumps in pid
    if (pid < last_pid || pid > (last_pid+PACKET_ID_MAX_INCREMENT)) {
        return false;
    }

    if (device_id > GET_SETTING(layout.number_devices)) {
        return false;
    }

    return true;
}

// not being local helps SDCC
// static XRAM uint8_t s_nrf_data[33];

// Returns false if not a valid packet
bit_t read_packet(uint8_t buffer_pos) REENT {
    uint8_t pipe_num = s_receive_buffer[buffer_pos].pipe_num;
    uint8_t width = s_receive_buffer[buffer_pos].width;
    XRAM uint8_t *packet_payload = s_receive_buffer[buffer_pos].payload;

    // NOTE: currently mouse pipes are disabled in passive listening mode
    if (pipe_num == 5 || pipe_num == 4) {
        uint8_t i;
        uint8_t csum = 0;

        // the unifying protocal packets use a siple arithmetic checksum
        for (i=0; i < width; i++) {
            csum += packet_payload[i];
        }

        if (csum != 0) {
            return false;
        }

        // usb_print(packet_payload, 16); // debugging

        // checksum passed, so assume we got a valid unifying packet
        unifying_read_packet(packet_payload);
        return true;
    }

    // need to change how this is handled
#if 0
    if (!auto_ack) { //
        // Passive listening. We implement this mode because we want to be able
        // to receive packets, but not send acknowledge packets. The nrf24 can't
        // be configured to do this while in 'Enhanced ShockBurst' mode.
        // We can fake it by disabling enhanced shock burst and hence auto acks,
        // but we then have to parse the packet manually because the structure
        // is different from what the nrf24 expects when auto acks are disabled.
        //
        // To do this we have to set the packet size larger so we can read in
        // the packet ctrl field and crc (done above).  Then we have to check
        // the packet crc, and then shuffle the bits around because of the
        // control field.
        uint16_t got_crc;
        int8_t i;
        XRAM uint8_t addr[5];

        nrf24_read_rx_payload(s_nrf_data, KEYBOARD_PAYLOAD_LENGTH+4);

        if (pipe_num == 0) {
            /* addr = g_rf_settings.pipe_addr_0; */
            // flash_load_rom(addr, g_rf_settings.pipe_addr_0, RF_ADDR_WIDTH);
            memcpy(addr, g_rf_settings.pipe_addr_0, RF_ADDR_WIDTH);
        } else if (pipe_num == 1) {
            /* addr = g_rf_settings.pipe_addr_1; */
            // flash_load_rom(addr, g_rf_settings.pipe_addr_1, RF_ADDR_WIDTH);
            memcpy(addr, g_rf_settings.pipe_addr_1, RF_ADDR_WIDTH);
        } else {
            // flash_load_rom(addr, g_rf_settings.pipe_addr_1, RF_ADDR_WIDTH);
            memcpy(addr, g_rf_settings.pipe_addr_1, RF_ADDR_WIDTH);
            if (pipe_num <= 5) {
                addr[0] = ((uint8_t*)&g_rf_settings.pipe_addr_2)[pipe_num-2];
            } else {
                return false;
            }
        }

        // check crc
        if (check_packet_crc(addr, s_nrf_data, KEYBOARD_PAYLOAD_LENGTH)) {
            return false;
        }

        // extract payload from the s_nrf_data
        for (i=0; i < KEYBOARD_PAYLOAD_LENGTH+2; i++) {
            data_buffer[i] = (uint8_t)(s_nrf_data[i+1] << 1) | (uint8_t)(s_nrf_data[i+2] >> 7);
        }

        got_crc = *((uint16_t *)(data_buffer+KEYBOARD_PAYLOAD_LENGTH));

        if (last_crc[pipe_num] == got_crc) {
            return false;
        } else {
            last_crc[pipe_num] = got_crc;
        }
    }
#else
    if (!auto_ack) {
        return false;
    }
#endif

    // All packets except unifying mouse packets are encrypted.
    aes_decrypt(packet_payload);

    // usb_print(packet_payload, 16); // debugging

    // Valitate that the packet before handling it
    {
        packet_t *packet = (packet_t*)packet_payload;
        const uint8_t device_id = packet->gen.device_id;
        const uint8_t packet_type = get_packet_type(packet);
        uint8_t state = device_uid_list[device_id].sync_state;

        // We received a packet from a disconnected device.  We generate a uid
        // which we will send to the slave in a packet.
        //
        // The slave will have to resend this unique ID in another encrypted
        // packet before we will receive further packets from the device. When
        // it passes this challenge, we then update the check_id in the
        // device_uid_list with the packet_id received from the slave.
        //
        // The check_id is then used and updated in is_valid_packet() to
        // validate further packets received from the slave.
        if (state == DEV_STATE_DISCONNECTED) {
            device_uid_list[device_id].sync_state = DEV_STATE_SYNCING_0;
            // set the check_id for the challenge-response authentication
            device_uid_list[device_id].check_id = uid_generate();
            // construct and send a challenge packet for the device
            rf_load_sync_ack_payload(device_id);

            // reject all data until we have synced
            return false;
        } else if (state >= DEV_STATE_SYNCING_0 && state < DEV_STATE_SYNCED_0 ) {
            // expecting a respone to the challenge from this device.
            if (packet_type == PACKET_TYPE_SESSION_UPDATE &&
                    device_uid_list[device_id].check_id == packet->sync.nonce &&
                    is_buffer_zeroed(packet->sync.salt, PACKET_SYNC_SALT_LENGTH) ) {
                // valid response to the challenge
                device_uid_list[device_id].sync_state = DEV_STATE_SYNCED_0;
                device_uid_list[device_id].check_id = packet->sync.packet_id;

                // Got a valid sync packet! Can now accept future packets
                // but don't have any data to process in the current sync packet
                // so return now.
                return false;
            } else {
                // incorrect response to the challenge
                device_uid_list[device_id].sync_state++; // keep track of failed attempts
                // TODO: should probably reduce retry attempts to 1?
                if (state >= DEV_STATE_SYNCING_0 + 4) {
                    // too many failed attempts, return to disconnected state
                    device_uid_list[device_id].sync_state = DEV_STATE_DISCONNECTED;
                }

                // reject all data until we have synced
                return false;
            }
        }

        // expecting a normal data packet from the slave.
        if (!is_valid_packet(packet, pipe_num)) {
            // keep track of the number of failed packets received
            device_uid_list[device_id].sync_state++;

            // If we exceed the PACKET_FAIL_LIMIT, the device returns to
            // the disconnected state where it will have a chance to sync
            // again and update it's check_id.
            if (device_uid_list[device_id].sync_state > DEV_STATE_SYNCED_0 + PACKET_FAIL_LIMIT) {
                device_uid_list[device_id].sync_state = DEV_STATE_DISCONNECTED;
            }
            return false;
        }

        // the packet we got is valid, so reset the sync state count
        device_uid_list[device_id].sync_state = DEV_STATE_SYNCED_0;
        device_uid_list[device_id].check_id = packet->gen.packet_id;

        // finally have a valid data packet ready to be processed
        if (is_matrix_packet(packet)) {
            keyboard_update_device_matrix(device_id, packet_payload);
            return true;
        } else {
            /* TODO: handle other packet types here */
            return false;
        }
    }
}

void rf_receive_buffer_add(void) {
    uint8_t pipe_num;
    uint8_t width;

    pipe_num = nrf24_get_rx_pipe_num();
    if (pipe_num == STATUS_RX_FIFO_EMPTY) {
        return;
    }

    width = nrf24_read_rx_payload_width();

    if (s_receive_buffer_len == RECEIVE_BUFFER_MAX_LENGTH) {
        nrf24_flush_rx(); // TODO: could probably handle this better
        return;
    }

    if (width > 22) {
        // drop packets that are too large
        nrf24_read_rx_payload(NULL, 0);
        return;
    }

    s_receive_buffer[s_receive_buffer_len].pipe_num = pipe_num;
    s_receive_buffer[s_receive_buffer_len].width = width;
    nrf24_read_rx_payload(s_receive_buffer[s_receive_buffer_len].payload, width);

    s_receive_buffer_len++;
}

void rf_isr(void) {
    uint8_t status = nrf24_read_status();

    if (status & STATUS_RX_DR_bm) {
        do {
            rf_receive_buffer_add();
        } while ( (nrf24_get_rx_pipe_num()) != STATUS_RX_FIFO_EMPTY );
    }


    nrf24_write_reg(NRF_STATUS, STATUS_ALL_IRQ_FLAGS_bm);
}

// check for radio messages and handle them
bit_t rf_task(void) {
    // TODO: should probably add an option to make this interrupt based when we
    // have access to the nrf24 IRQ.
    bit_t has_data = false;

#if RF_POLLING
    rf_isr();
#endif

#if !RF_POLLING
    // disable the rf_isr while we are reading packets, it modifies the
    // s_receive_buffer_len list which we are reading here.
    rf_disable_receive_irq();
#endif

    {
        uint8_t i;
        for (i = 0; i < s_receive_buffer_len; ++i) {
            has_data |= read_packet(i);
        }
    }

    s_receive_buffer_len = 0;

#if !RF_POLLING
    rf_enable_receive_irq();
#endif

    return has_data;
}

#endif
