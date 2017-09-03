/*****************************************************************************
 * aes-otfks-encrypt.c
 *
 * AES-128 encryption with on-the-fly calculation of key schedule.
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
#include "aes-mul2.h"

/*****************************************************************************
 * Defines
 ****************************************************************************/

#define AES_KEY_SCHEDULE_FIRST_RCON     1u

/*****************************************************************************
 * Functions
 ****************************************************************************/

/* AES-128 encryption with on-the-fly key schedule calculation.
 *
 * p_block points to a 16-byte buffer of plain data to encrypt. Encryption
 * is done in-place in that buffer.
 * p_key must initially point to a starting key state for encryption, which is
 * simply the 16 bytes of the AES-128 key. Key schedule is calculated on-the-
 * fly in that buffer, so the buffer must re-initialised for subsequent
 * encryption operations.
 */
void aes128_otfks_encrypt(uint8_t p_block[AES_BLOCK_SIZE], uint8_t p_key[AES128_KEY_SIZE])
{
    uint_fast8_t    round;
    uint8_t         rcon = AES_KEY_SCHEDULE_FIRST_RCON;

    aes_add_round_key(p_block, p_key);
    for (round = 1; round < AES128_NUM_ROUNDS; ++round)
    {
        aes128_key_schedule_round(p_key, rcon);
        aes_sbox_apply_block(p_block);
        aes_shift_rows(p_block);
        aes_mix_columns(p_block);
        aes_add_round_key(p_block, p_key);

        /* Next rcon */
        rcon = aes_mul2(rcon);
    }
    aes128_key_schedule_round(p_key, rcon);
    aes_sbox_apply_block(p_block);
    aes_shift_rows(p_block);
    aes_add_round_key(p_block, p_key);
}
