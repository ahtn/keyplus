// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <stdint.h>
#include "core/util.h"

#define AES_BUF_SIZE                16
#define AES_KEY_SIZE                16

typedef enum aes_crypt_mode_t {
    AES_ENCRYPT = 0,
    AES_DECRYPT = 1,
} aes_crypt_mode_t;

void aes_key_init(const uint8_t *ekey, const uint8_t *dkey);
void aes_encrypt(uint8_t *block);
void aes_decrypt(uint8_t *block);
