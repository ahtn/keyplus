/*****************************************************************************
 * aes-sbox-small.c
 *
 * AES S-box implemented as a code calculation using Galois inverse.
 *
 * However it is doubtful whether this saves much over table look-up, due to
 * the size of the implementation of aes_inv() and aes_mul() which it uses,
 * as well as the size of aes_rotate_left_uint8() if it's not optimised.
 * Check the size of the generated code on the target platform.
 ****************************************************************************/

/*****************************************************************************
 * Includes
 ****************************************************************************/

#include "aes-sbox.h"
#include "aes-rotate.h"
#include "aes-inv.h"

/*****************************************************************************
 * Functions
 ****************************************************************************/

uint8_t aes_sbox(uint8_t a)
{
    uint8_t x;
    
    a = aes_inv(a);
    
    x = aes_rotate_left_uint8(a, 1u);
    x ^= aes_rotate_left_uint8(x, 1u);
    x ^= aes_rotate_left_uint8(x, 2u);
    
    return a ^ x ^ 0x63u;
}

void aes_sbox_apply_block(uint8_t p_block[AES_BLOCK_SIZE])
{
    uint_fast8_t    i;

    for (i = 0; i < AES_BLOCK_SIZE; ++i)
    {
        p_block[i] = aes_sbox(p_block[i]);
    }
}
