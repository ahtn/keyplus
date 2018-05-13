/*****************************************************************************
 * aes-encrypt.c
 *
 * AES-128 encryption with pre-calculated key schedule.
 ****************************************************************************/

/*****************************************************************************
 * Includes
 ****************************************************************************/

#include "aes.h"
#include "aes-add-round-key.h"
#include "aes-sbox.h"
#include "aes-shift-rows.h"
#include "aes-mix-columns.h"

/*****************************************************************************
 * Functions
 ****************************************************************************/

/* AES-128 encryption.
 *
 * p_block points to a 16-byte buffer of plain data to encrypt. Encryption
 * is done in-place in that buffer.
 * p_key_schedule points to a pre-calculated key schedule, which can be
 * calculated by aes128_key_schedule().
 */
void aes128_encrypt(uint8_t p_block[AES_BLOCK_SIZE], const uint8_t p_key_schedule[AES128_KEY_SCHEDULE_SIZE])
{
    uint_fast8_t    round;

    aes_add_round_key(p_block, p_key_schedule);
    for (round = 1; round < AES128_NUM_ROUNDS; ++round)
    {
        aes_sbox_apply_block(p_block);
        aes_shift_rows(p_block);
        aes_mix_columns(p_block);
        aes_add_round_key(p_block, &p_key_schedule[round * AES_BLOCK_SIZE]);
    }
    aes_sbox_apply_block(p_block);
    aes_shift_rows(p_block);
    aes_add_round_key(p_block, &p_key_schedule[AES128_NUM_ROUNDS * AES_BLOCK_SIZE]);
}
