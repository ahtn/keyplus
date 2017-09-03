/*****************************************************************************
 * aes-key-schedule.c
 *
 * Calculate the AES-128 expanded key schedule.
 ****************************************************************************/

/*****************************************************************************
 * Includes
 ****************************************************************************/

#include "aes.h"
#include "aes-sbox.h"
#include "aes-mul2.h"

#include <string.h>

/*****************************************************************************
 * Defines
 ****************************************************************************/

#define AES_KEY_SCHEDULE_FIRST_RCON     1u

/*****************************************************************************
 * Functions
 ****************************************************************************/

void aes128_key_schedule(uint8_t p_key_schedule[AES128_KEY_SCHEDULE_SIZE], const uint8_t p_key[AES128_KEY_SIZE])
{
    uint_fast8_t    round;
    uint8_t       * p_key_0 = p_key_schedule + AES128_KEY_SIZE;
    uint8_t         temp_byte;
    uint8_t         rcon = AES_KEY_SCHEDULE_FIRST_RCON;

    /* Initial part of key schedule is simply the AES-128 key copied verbatim. */
    memcpy(p_key_schedule, p_key, AES128_KEY_SIZE);

    for (round = 0; round < (AES128_KEY_SCHEDULE_SIZE - AES128_KEY_SIZE) / AES_KEY_SCHEDULE_WORD_SIZE; ++round)
    {
        memcpy(p_key_0, p_key_0 - AES_KEY_SCHEDULE_WORD_SIZE, AES_KEY_SCHEDULE_WORD_SIZE);

        if ((round % (AES128_KEY_SIZE / AES_KEY_SCHEDULE_WORD_SIZE)) == 0)
        {
            /* Rotate previous word and apply S-box. Also XOR Rcon for first byte. */
            temp_byte = p_key_0[0];
            p_key_0[0] = aes_sbox(p_key_0[1]) ^ rcon;
            p_key_0[1] = aes_sbox(p_key_0[2]);
            p_key_0[2] = aes_sbox(p_key_0[3]);
            p_key_0[3] = aes_sbox(temp_byte);

            /* Next rcon */
            rcon = aes_mul2(rcon);
        }

        /* XOR in bytes from AES128_KEY_SIZE bytes ago */
        p_key_0[0] ^= p_key_0[0 - (signed)AES128_KEY_SIZE];
        p_key_0[1] ^= p_key_0[1 - (signed)AES128_KEY_SIZE];
        p_key_0[2] ^= p_key_0[2 - (signed)AES128_KEY_SIZE];
        p_key_0[3] ^= p_key_0[3 - (signed)AES128_KEY_SIZE];

        p_key_0 += AES_KEY_SCHEDULE_WORD_SIZE;
    }
}
