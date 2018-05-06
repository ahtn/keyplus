// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "xmega_hardware/aes.h"

#include <avr/io.h>

void xmega_aes_crypt(aes_block_t out_block, aes_block_t in_block, const aes_key_t key, xmega_aes_mode_t mode) {
    AES.CTRL = AES_RESET_bm;

    if (mode) {
        AES.CTRL |= AES_DECRYPT_bm;
    } else {
        AES.CTRL &= ~AES_DECRYPT_bm;
    }

    for (int i = 0; i < AES_BUF_LEN; ++i) {
        AES.KEY = key[i];
    }
    for (int i = 0; i < AES_BUF_LEN; ++i) {
        AES.STATE = in_block[i];
    }
    AES.CTRL |= AES_START_bm;
    while (!(AES.STATUS & AES_SRIF_bm));
    for (int i = 0; i < AES_BUF_LEN; ++i) {
        out_block[i] = AES.STATE;
    }
}
