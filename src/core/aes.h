// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)
/// @file core/aes.h
///
/// Simple interface to AES functions.
///
/// This module is only needed if the mcu port uses nRF24 wireless.

#pragma once

#include <stdint.h>
#include "core/util.h"

#define AES_BUF_SIZE                16
#define AES_KEY_SIZE                16
#define AES_BLOCK_SIZE              16

typedef enum aes_crypt_mode_t {
    AES_ENCRYPT = 0,
    AES_DECRYPT = 1,
} aes_crypt_mode_t;

/// Initialize the AES module.
///
/// NOTE: AES is a symmetric algorithm so it only needs one key to encrypt and
/// decrypt. However, this function requires both the AES key and the
/// "decryption key" which is the final round key of the encryption operation
/// ().  The algorithm to compute the
/// final round key is performed on the host software which saves code space
/// (the algorithm needs a 256 byte lookup table, and some other code).
///
/// See: `host-software/keyplus/utility/round_keys.py` for the code used to
/// generate the round key.
void aes_key_init(const uint8_t *ekey, const uint8_t *dkey);

/// Encrypt a block (in-place)
void aes_encrypt(uint8_t *block);

/// Decrypt a block (in-place)
void aes_decrypt(uint8_t *block);
