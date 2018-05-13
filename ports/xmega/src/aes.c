// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/aes.h"

#include "xmega_hardware/aes.h"

#include <string.h>

static XRAM aes_key_t aes_ekey;
static XRAM aes_key_t aes_dkey;

void aes_key_init(const uint8_t *ekey, const uint8_t *dkey) {
    memcpy(aes_ekey, ekey, AES_KEY_SIZE);
    memcpy(aes_dkey, dkey, AES_KEY_SIZE);
}

void aes_encrypt(uint8_t *block) {
    xmega_aes_crypt(block, block, aes_ekey, XMEGA_AES_ENCRYPT);
}

void aes_decrypt(uint8_t *block) {
    xmega_aes_crypt(block, block, aes_dkey, XMEGA_AES_DECRYPT);
}
