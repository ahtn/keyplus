// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include <avr/io.h>
#include <util/delay.h>

#include "core/aes.h"
#include "core/hardware.h"
#include "core/nrf24.h"

#if defined(__AVR_ATmega32U4__)
#ifndef CE
#define CE 5   // b5
#endif
#ifndef CSN
#define CSN 6  // b6
#endif
#define MOSI 2   // b2
#define MISO 3   // b3
#define SCK  1   // b1
#elif defined(__AVR_ATmega328P__)
#ifndef CE
#define CE 1   // b1
#endif
#ifndef CSN
#define CSN 2  // b2
#endif
#define MOSI 3   // b3
#define MISO 4   // b4
#define SCK  5   // b5
#endif

#define CREATE_BIT_SETTER(func, port, port_bit) \
void func(uint8_t val) { \
  if (val) { \
    PORT##port |= (1 << port_bit);\
  } else { \
    PORT##port &= ~(1 << port_bit);\
  } \
} \
inline void ddr_##func(uint8_t val) { \
  if (val) { \
    DDR##port |= (1 << port_bit);\
  } else { \
    DDR##port &= ~(1 << port_bit);\
  } \
} \

#if defined(__AVR_ATmega32U4__)
CREATE_BIT_SETTER(nrf24_ce, B, CE);
CREATE_BIT_SETTER(nrf24_csn, B, CSN);
#elif defined(__AVR_ATmega328P__)
CREATE_BIT_SETTER(nrf24_ce, B, CE);
CREATE_BIT_SETTER(nrf24_csn, B, CSN);
#endif

void nrf24_init(void) {
    /* TODO: change this define to an appropriate one for the promicro */
    ddr_nrf24_csn(1);
    ddr_nrf24_ce(1);
    DDRB |= (0<<MISO)|(1<<MOSI)|(1<<SCK);
    nrf24_csn(1);
    nrf24_ce(0);

    // nrf supports 10Mbs on spi
    // setup spi with: msb, mode0, clk/2
    SPCR = (1<<SPI2X) | (1<<SPE) | (1<<MSTR);
}

uint8_t nrf24_spi_send_byte(uint8_t byte) {
    SPDR = byte;
    while(!(SPSR & (1<<SPIF)));
    return SPDR;
}

void led_testing_toggle(void) {
}

#if defined(AES_TINY128)

#include <string.h>
#include "aes/tiny_aes128/aes.h"

static uint8_t aes_ekey[AES_KEY_SIZE];

void aes_key_init(const uint8_t *ekey, const uint8_t *dkey) {
    memcpy(aes_ekey, ekey, AES_KEY_SIZE);
}

void aes_encrypt(uint8_t *block) {
    AES128_ECB_encrypt(block, aes_ekey, block);
}

void aes_decrypt(uint8_t *block) {
    AES128_ECB_decrypt(block, aes_ekey, block);
}

#elif defined(AES_MIN)

#include <string.h>
#include "aes/aes-min/aes.h"

static uint8_t aes_ekey[AES_KEY_SIZE];
static uint8_t aes_key_schedule[AES128_KEY_SCHEDULE_SIZE];

void aes_key_init(const uint8_t *ekey, const uint8_t *dkey) {
    memcpy(aes_ekey, ekey, AES_KEY_SIZE);
    aes128_key_schedule(aes_key_schedule, aes_ekey);
}

void aes_encrypt(uint8_t *block) {
    aes128_encrypt(block, aes_key_schedule);
}

void aes_decrypt(uint8_t *block) {
    aes128_encrypt(block, aes_key_schedule);
}
#elif defined(AES_CRYPTO_LIB)

#include <string.h>
#include "aes/avr-crypto-lib/aes.h"

static aes128_ctx_t aes_ctx;

void aes_key_init(const uint8_t *ekey, const uint8_t *dkey) {
    aes128_init(ekey, &aes_ctx);
}

void aes_encrypt(uint8_t *block) {
    aes128_enc(block, &aes_ctx);
}

void aes_decrypt(uint8_t *block) {
    aes128_dec(block, &aes_ctx);
}
#endif


void flash_read(uint8_t* dest, uint16_t addr, uint16_t len) {
    memcpy_P(dest, (uint8_t*)(addr), len);
}

void dynamic_delay_ms(uint16_t ms) {
    uint16_t i;
    if (g_slow_clock_mode) {
        for (i = 0; i < ms; ++i) {
            static_delay_ms(1);
        }
    } else {
        for (i = 0; i < ms; ++i) {
            static_delay_slow_ms(1);
        }
    }
}
