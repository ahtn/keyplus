// MIT License
//
// Copyright (c) 2017 seethis.link
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "xmega_aes.h"

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
