/*****************************************************************************
 * aes-add-round-key.h
 ****************************************************************************/

#ifndef AES_ADD_ROUND_KEY_H
#define AES_ADD_ROUND_KEY_H

/*****************************************************************************
 * Includes
 ****************************************************************************/

#include "aes.h"

/*****************************************************************************
 * Inline functions
 ****************************************************************************/

/* XOR the specified round key into the AES block.
 * Fixed block size.
 */
static inline void aes_add_round_key(uint8_t p_block[AES_BLOCK_SIZE], const uint8_t p_round_key[AES_BLOCK_SIZE])
{
    uint_fast8_t    i;

    for (i = 0; i < AES_BLOCK_SIZE; ++i)
    {
        p_block[i] ^= p_round_key[i];
    }
}

#endif /* !defined(AES_ADD_ROUND_KEY_H) */
