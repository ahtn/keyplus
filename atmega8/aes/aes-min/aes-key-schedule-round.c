/*****************************************************************************
 * aes-key-schedule-round.c
 *
 * In-place calculation of the next round of the AES-128 key schedule.
 * This is used for encryption with on-the-fly key schedule calculation.
 ****************************************************************************/

/*****************************************************************************
 * Includes
 ****************************************************************************/

#include "aes.h"
#include "aes-sbox.h"

/*****************************************************************************
 * Functions
 ****************************************************************************/

/* This is used for aes128_otfks_encrypt(), on-the-fly key schedule encryption.
 * It is also used by aes128_otfks_decrypt_start_key() to calculate the
 * starting key state for decryption with on-the-fly key schedule calculation.
 * rcon for the round must be provided, out of the sequence:
 *     1, 2, 4, 8, 16, 32, 64, 128, 27, 54
 * Subsequent values can be calculated with aes_mul2().
 */
void aes128_key_schedule_round(uint8_t p_key[AES128_KEY_SIZE], uint8_t rcon)
{
    uint_fast8_t    round;
    uint8_t       * p_key_0 = p_key;
    uint8_t       * p_key_m1 = p_key + AES128_KEY_SIZE - AES_KEY_SCHEDULE_WORD_SIZE;

    /* Rotate previous word and apply S-box. Also XOR Rcon for first byte. */
    p_key_0[0] ^= aes_sbox(p_key_m1[1]) ^ rcon;
    p_key_0[1] ^= aes_sbox(p_key_m1[2]);
    p_key_0[2] ^= aes_sbox(p_key_m1[3]);
    p_key_0[3] ^= aes_sbox(p_key_m1[0]);

    for (round = 1; round < AES128_KEY_SIZE / AES_KEY_SCHEDULE_WORD_SIZE; ++round)
    {
        p_key_m1 = p_key_0;
        p_key_0 += AES_KEY_SCHEDULE_WORD_SIZE;

        /* XOR in previous word */
        p_key_0[0] ^= p_key_m1[0];
        p_key_0[1] ^= p_key_m1[1];
        p_key_0[2] ^= p_key_m1[2];
        p_key_0[3] ^= p_key_m1[3];
    }
}
