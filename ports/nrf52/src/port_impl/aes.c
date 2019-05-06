// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/aes.h"

#include "app_error.h"
#include "nrf_crypto.h"

// NOTE: only nRF52840 has arm cryptocell 310 hardware. However, other devices
// in the nRF52 family have AES encryption peripheral but offers no decryption.
// It might be better to switch to using that peripheral and provide a software
// implementation of AES decryption.

static uint8_t s_ekey_ptr[AES_KEY_SIZE];

void aes_key_init(const uint8_t *ekey, const uint8_t *dkey) {
    memcpy(s_ekey_ptr, ekey, AES_KEY_SIZE);
}

/// Encrypt a block (in-place)
void aes_encrypt(uint8_t *aes_block) {
    size_t      len_out;
    ret_code_t  ret_val;
    uint8_t     encrypted_text[AES_BLOCK_SIZE*2]; // nrf_crypto functions need 1 block padding
    len_out = AES_BLOCK_SIZE*2;

    nrf_crypto_aes_context_t      ecb_encr_ctx;

    ret_val = nrf_crypto_aes_crypt(
        &ecb_encr_ctx,
        &g_nrf_crypto_aes_ecb_128_info,
        NRF_CRYPTO_ENCRYPT,
        s_ekey_ptr,
        NULL,
        aes_block,
        AES_BLOCK_SIZE,
        encrypted_text,
        &len_out
    );
    APP_ERROR_CHECK(ret_val);
    memcpy(aes_block, encrypted_text, AES_BLOCK_SIZE);
}

/// Decrypt a block (in-place)
void aes_decrypt(uint8_t *aes_block) {
    size_t      len_out;
    ret_code_t  ret_val;
    uint8_t     decrypted_text[AES_BLOCK_SIZE*2]; // nrf_crypto functions need 1 block padding

    nrf_crypto_aes_context_t      ecb_decr_ctx;

    // Decryption start
    ret_val = nrf_crypto_aes_init(
        &ecb_decr_ctx,
        &g_nrf_crypto_aes_ecb_128_info,
        NRF_CRYPTO_DECRYPT
    );
    APP_ERROR_CHECK(ret_val);

    /* Set encryption and decryption key */
    ret_val = nrf_crypto_aes_key_set(&ecb_decr_ctx, s_ekey_ptr);
    APP_ERROR_CHECK(ret_val);

    /* Decrypt blocks */
    len_out = sizeof(decrypted_text);
    ret_val = nrf_crypto_aes_finalize(
        &ecb_decr_ctx,
        aes_block,
        AES_BLOCK_SIZE,
        decrypted_text,
        &len_out
    );
    APP_ERROR_CHECK(ret_val);

    memcpy(aes_block, decrypted_text, AES_BLOCK_SIZE);
}
