// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <stdint.h>

#define REGISTER_MASK 0x1F

typedef enum {
    R_REGISTER          = 0x00,
    W_REGISTER          = 0x20,
    R_RX_PAYLOAD        = 0x61,
    W_TX_PAYLOAD        = 0xA0,
    FLUSH_TX            = 0xE1,
    FLUSH_RX            = 0xE2,
    REUSE_TX_PL         = 0xE3,
    R_RX_PL_WID         = 0x60,
    W_ACK_PAYLOAD       = 0xA8,
    W_TX_PAYLOAD_NO_ACK = 0xB0,
    NRF_NOP             = 0xFF,
} nrf24_spi_command_t;

typedef enum {
    CONFIG       = 0x00,
    EN_AA        = 0x01,
    EN_RXADDR    = 0x02,
    SETUP_AW     = 0x03,
    SETUP_RETR   = 0x04,
    RF_CH        = 0x05,
    RF_SETUP     = 0x06,
    NRF_STATUS   = 0x07,
    OBSERVE_TX   = 0x08,
    RPD          = 0x09,
    RX_ADDR_P0   = 0x0A,
    RX_ADDR_P1   = 0x0B,
    RX_ADDR_P2   = 0x0C,
    RX_ADDR_P3   = 0x0D,
    RX_ADDR_P4   = 0x0E,
    RX_ADDR_P5   = 0x0F,
    TX_ADDR      = 0x10,
    RX_PW_P0     = 0x11,
    RX_PW_P1     = 0x12,
    RX_PW_P2     = 0x13,
    RX_PW_P3     = 0x14,
    RX_PW_P4     = 0x15,
    RX_PW_P5     = 0x16,
    FIFO_STATUS  = 0x17,
    DYNPD        = 0x1C,
    FEATURE      = 0x1D,
} nrf24_register_t;


// CONFIG
#define MASK_RX_DR  6
#define MASK_TX_DS  5
#define MASK_MAX_RT 4
#define EN_CRC      3
#define CRCO        2
#define PWR_UP      1
#define PRIM_RX     0

#define MASK_RX_DR_bm   (1 << MASK_RX_DR)
#define MASK_TX_DS_bm   (1 << MASK_TX_DS)
#define MASK_MAX_RT_bm  (1 << MASK_MAX_RT)
#define EN_CRC_bm       (1 << EN_CRC)
#define CRCO_bm         (1 << CRCO)
#define PWR_UP_bm       (1 << PWR_UP)
#define PRIM_RX_bm      (1 << PRIM_RX)

#define MASK_ALL_IRQ_bm (MASK_RX_DR_bm | MASK_TX_DS_bm | MASK_MAX_RT_bm)

// SETUP_RETR
#define ARD         4
#define ARC         0

// RF_SETUP
#define CONT_WAVE   7
#define RF_DR_LOW   5
#define PLL_LOCK    4
#define RF_DR_HIGH  3
#define RF_PWR_HIGH 2
#define RF_PWR_LOW  1
#define LNA_HCURR   0

#define CONT_WAVE_bm   (1<<CONT_WAVE)
#define RF_DR_LOW_bm   (1<<RF_DR_LOW)
#define PLL_LOCK_bm    (1<<PLL_LOCK)
#define RF_DR_HIGH_bm  (1<<RF_DR_HIGH)
#define RF_PWR_HIGH_bm (1<<RF_PWR_HIGH)
#define RF_PWR_LOW_bm  (1<<RF_PWR_LOW)
#define LNA_HCURR_bm   (1<<LNA_HCURR)

// STATUS
#define STATUS_RX_DR        6
#define STATUS_TX_DS        5
#define STATUS_MAX_RT       4
#define STATUS_RX_P_NO      1
#define STATUS_TX_FULL      0

#define STATUS_RX_DR_bm     (1 << STATUS_RX_DR)
#define STATUS_TX_DS_bm     (1 << STATUS_TX_DS)
#define STATUS_MAX_RT_bm    (1 << STATUS_MAX_RT)
#define STATUS_TX_FULL_bm   (1 << STATUS_TX_FULL)

#define NRF24_STATUS_RX_PIPE(x) (((x) >> STATUS_RX_P_NO) & 0b0111)
#define STATUS_RX_FIFO_EMPTY (0b0111)

#define STATUS_ALL_IRQ_FLAGS_bm (STATUS_MAX_RT_bm | STATUS_RX_DR_bm | STATUS_TX_DS_bm)

// OBSERVE_TX
#define PLOS_CNT    4
#define ARC_CNT     0

// RPD - CD in nRF24L01
#define RPD_BIT     0

// FIFO_STATUS
#define FIFO_TX_REUSE       6
#define FIFO_TX_FULL        5
#define FIFO_TX_EMPTY       4
#define FIFO_RX_FULL        1
#define FIFO_RX_EMPTY       0

#define FIFO_TX_REUSE_bm    (1 << FIFO_TX_REUSE)
#define FIFO_TX_FULL_bm     (1 << FIFO_TX_FULL)
#define FIFO_TX_EMPTY_bm    (1 << FIFO_TX_EMPTY)
#define FIFO_RX_FULL_bm     (1 << FIFO_RX_FULL)
#define FIFO_RX_EMPTY_bm    (1 << FIFO_RX_EMPTY)

// FEATURE
#define EN_DPL          2
#define EN_ACK_PAY      1
#define EN_DYN_ACK      0

#define EN_DPL_bm       (1 << EN_DPL)
#define EN_ACK_PAY_bm   (1 << EN_ACK_PAY)
#define EN_DYN_ACK_bm   (1 << EN_DYN_ACK)

// power
#define PWR_NEG_18DB    0x00
#define PWR_NEG_12DB    0x01
#define PWR_NEG_6DB     0x02
#define PWR_0DB         0x03

// data rate
#define RF_DR_250KBPS   (1 << RF_DR_LOW)
#define RF_DR_1MBPS     0
#define RF_DR_2MBPS     (1 << RF_DR_HIGH)
