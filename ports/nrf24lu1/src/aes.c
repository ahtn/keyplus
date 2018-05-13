// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/aes.h"

#include <string.h>

#include "nrf24lu1.h"

#define AESCS_GO   0
#define AESCS_DECR 1
#define AESCS_MODE 2

#define AESCS_ECB_ENC ((ECB << AESCS_MODE) | (0<<AESCS_DECR))
#define AESCS_ECB_DEC ((ECB << AESCS_MODE) | (1<<AESCS_DECR))

typedef enum {
    CBC = 0b000,
    CFB = 0b001,
    OFB = 0b010,
    CTR = 0b011,
    ECB = 0b100,
} aes_modes_t;

static void aes_keyin_write_buf(const uint8_t *buf) {
    int8_t index;
    AESIA1 = 0;
    for(index=AES_KEY_SIZE-1; index>=0; index--) {
        AESKIN = buf[index];
    }
}

static void aes_block_go(uint8_t *block) {
    int8_t index;
    { /* aes_data_write_buf(block); */
        AESIA2 = 0;
        for(index=AES_KEY_SIZE-1; index>=0; index--) {
            AESD = block[index];
        }
    }

    // peform the crypt/decrypt operation
    GO=1; while(GO);

    { /* aes_data_read_buf(block); */
        AESIA1 = 0;
        for(index=AES_KEY_SIZE-1; index>=0; index--) {
            block[index] = AESD;
        }
    }
}

static XRAM uint8_t aes_dkey[AES_KEY_SIZE];
static XRAM uint8_t aes_ekey[AES_KEY_SIZE];
static XRAM aes_crypt_mode_t aes_mode;

/*********************************************************************
 *                         public functions                          *
 *********************************************************************/

void aes_key_init(const uint8_t *ekey, const uint8_t *dkey) {
    memcpy(aes_ekey, ekey, AES_KEY_SIZE);
    memcpy(aes_dkey, dkey, AES_KEY_SIZE);

    aes_mode = AES_ENCRYPT;
    AESCS = AESCS_ECB_ENC;
    aes_keyin_write_buf(aes_ekey);
}

void aes_encrypt(uint8_t *block) {
    if (aes_mode != AES_ENCRYPT) {
        aes_mode = AES_ENCRYPT;
        AESCS = AESCS_ECB_ENC;
        aes_keyin_write_buf(aes_ekey);
    }
    aes_block_go(block);
}

void aes_decrypt(uint8_t *block) {
    if (aes_mode != AES_DECRYPT) {
        aes_mode = AES_DECRYPT;
        AESCS = AESCS_ECB_DEC;
        aes_keyin_write_buf(aes_dkey);
    }
    aes_block_go(block);
}
