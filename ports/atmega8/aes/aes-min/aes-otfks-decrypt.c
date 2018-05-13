/*****************************************************************************
 * aes-otfks-decrypt.c
 *
 * AES-128 decryption with on-the-fly calculation of key schedule.
 ****************************************************************************/

/*****************************************************************************
 * Includes
 ****************************************************************************/

#include "aes.h"
#include "aes-add-round-key.h"
#include "aes-key-schedule-round.h"
#include "aes-sbox.h"
#include "aes-shift-rows.h"
#include "aes-mix-columns.h"
#include "aes-mul2.h"       /* For aes_mul2() and aes_div2() */

/*****************************************************************************
 * Defines
 ****************************************************************************/

#define AES_KEY_SCHEDULE_FIRST_RCON     1u
#define AES128_KEY_SCHEDULE_LAST_RCON   54u

/*****************************************************************************
 * Functions
 ****************************************************************************/

/* This is used for aes128_otfks_decrypt(), on-the-fly key schedule decryption.
 * rcon for the round must be provided, out of the sequence:
 *     54, 27, 128, 64, 32, 16, 8, 4, 2, 1
 * Subsequent values can be calculated with aes_div2().
 */
static void aes128_key_schedule_inv_round(uint8_t p_key[AES128_KEY_SIZE], uint8_t rcon)
{
    uint_fast8_t    round;
    uint8_t       * p_key_0 = p_key + AES128_KEY_SIZE - AES_KEY_SCHEDULE_WORD_SIZE;
    uint8_t       * p_key_m1 = p_key_0 - AES_KEY_SCHEDULE_WORD_SIZE;

    for (round = 1; round < AES128_KEY_SIZE / AES_KEY_SCHEDULE_WORD_SIZE; ++round)
    {
        /* XOR in previous word */
        p_key_0[0] ^= p_key_m1[0];
        p_key_0[1] ^= p_key_m1[1];
        p_key_0[2] ^= p_key_m1[2];
        p_key_0[3] ^= p_key_m1[3];

        p_key_0 = p_key_m1;
        p_key_m1 -= AES_KEY_SCHEDULE_WORD_SIZE;
    }

    /* Rotate previous word and apply S-box. Also XOR Rcon for first byte. */
    p_key_m1 = p_key + AES128_KEY_SIZE - AES_KEY_SCHEDULE_WORD_SIZE;
    p_key_0[0] ^= aes_sbox(p_key_m1[1]) ^ rcon;
    p_key_0[1] ^= aes_sbox(p_key_m1[2]);
    p_key_0[2] ^= aes_sbox(p_key_m1[3]);
    p_key_0[3] ^= aes_sbox(p_key_m1[0]);
}

/* Calculate the starting key state needed for decryption with on-the-fly key
 * schedule calculation. The starting decryption key state is the last 16 bytes
 * of the AES-128 key schedule.
 * The decryption start key calculation is done in-place in the buffer p_key[].
 * So p_key points to a 16-byte buffer containing the AES-128 key. On exit, it
 * contains the decryption start key state suitable for aes128_otfks_decrypt().
 */
void aes128_otfks_decrypt_start_key(uint8_t p_key[AES128_KEY_SIZE])
{
    uint_fast8_t    round;
    uint8_t         rcon = AES_KEY_SCHEDULE_FIRST_RCON;

    for (round = 0; round < AES128_NUM_ROUNDS; ++round)
    {
        aes128_key_schedule_round(p_key, rcon);

        /* Next rcon */
        rcon = aes_mul2(rcon);
    }
}

/* AES-128 decryption with on-the-fly key schedule calculation.
 *
 * p_block points to a 16-byte buffer of encrypted data to decrypt. Decryption
 * is done in-place in that buffer.
 * p_key must initially point to a starting key state for decryption, which is
 * the last 16 bytes of the AES-128 key schedule. It can be calculated from the
 * AES-128 16-byte key by aes128_otfks_decrypt_start_key(). Key schedule is
 * calculated on-the-fly in that buffer, so the buffer must re-initialised for
 * subsequent decryption operations.
 */
void aes128_otfks_decrypt(uint8_t p_block[AES_BLOCK_SIZE], uint8_t p_key[AES128_KEY_SIZE])
{
    uint_fast8_t    round;
    uint8_t         rcon = AES128_KEY_SCHEDULE_LAST_RCON;

    aes_add_round_key(p_block, p_key);
    aes_shift_rows_inv(p_block);
    aes_sbox_inv_apply_block(p_block);
    for (round = AES128_NUM_ROUNDS - 1u; round >= 1; --round)
    {
        aes128_key_schedule_inv_round(p_key, rcon);
        aes_add_round_key(p_block, p_key);
        aes_mix_columns_inv(p_block);
        aes_shift_rows_inv(p_block);
        aes_sbox_inv_apply_block(p_block);

        /* Previous rcon */
        rcon = aes_div2(rcon);
    }
    aes128_key_schedule_inv_round(p_key, rcon);
    aes_add_round_key(p_block, p_key);
}
