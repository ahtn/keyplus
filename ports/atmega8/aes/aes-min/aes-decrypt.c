/*****************************************************************************
 * aes-decrypt.c
 *
 * AES-128 decryption with pre-calculated key schedule.
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

/* AES-128 decryption.
 *
 * p_block points to a 16-byte buffer of encrypted data to decrypt. Decryption
 * is done in-place in that buffer.
 * p_key_schedule points to a pre-calculated key schedule, which can be
 * calculated by aes128_key_schedule().
 */
void aes128_decrypt(uint8_t p_block[AES_BLOCK_SIZE], const uint8_t p_key_schedule[AES128_KEY_SCHEDULE_SIZE])
{
    uint_fast8_t    round;

    aes_add_round_key(p_block, &p_key_schedule[AES128_NUM_ROUNDS * AES_BLOCK_SIZE]);
    aes_shift_rows_inv(p_block);
    aes_sbox_inv_apply_block(p_block);
    for (round = AES128_NUM_ROUNDS - 1u; round >= 1; --round)
    {
        aes_add_round_key(p_block, &p_key_schedule[round * AES_BLOCK_SIZE]);
        aes_mix_columns_inv(p_block);
        aes_shift_rows_inv(p_block);
        aes_sbox_inv_apply_block(p_block);
    }
    aes_add_round_key(p_block, p_key_schedule);
}
