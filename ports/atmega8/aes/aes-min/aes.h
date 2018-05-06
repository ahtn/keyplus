/*****************************************************************************
 * aes.h
 *
 * Minimal byte-oriented AES-128 encryption/decryption implementation suitable
 * for small microprocessors.
 ****************************************************************************/

#ifndef AES_H
#define AES_H

/*****************************************************************************
 * Includes
 ****************************************************************************/

#include <stdint.h>

/*****************************************************************************
 * Defines
 ****************************************************************************/

#define AES_BLOCK_SIZE              16u
#define AES_COLUMN_SIZE             4u
#define AES_NUM_COLUMNS             4u

#define AES_KEY_SCHEDULE_WORD_SIZE  4u

#define AES128_NUM_ROUNDS           10u
#define AES128_KEY_SIZE             16u
#define AES128_KEY_SCHEDULE_SIZE    (AES_BLOCK_SIZE * (AES128_NUM_ROUNDS + 1u))

/*****************************************************************************
 * Function prototypes
 ****************************************************************************/

void aes128_encrypt(uint8_t p_block[AES_BLOCK_SIZE], const uint8_t p_key_schedule[AES128_KEY_SCHEDULE_SIZE]);
void aes128_decrypt(uint8_t p_block[AES_BLOCK_SIZE], const uint8_t p_key_schedule[AES128_KEY_SCHEDULE_SIZE]);

void aes128_key_schedule(uint8_t p_key_schedule[AES128_KEY_SCHEDULE_SIZE], const uint8_t p_key[AES128_KEY_SIZE]);

void aes128_otfks_encrypt(uint8_t p_block[AES_BLOCK_SIZE], uint8_t p_key[AES128_KEY_SIZE]);
void aes128_otfks_decrypt(uint8_t p_block[AES_BLOCK_SIZE], uint8_t p_decrypt_start_key[AES128_KEY_SIZE]);

void aes128_otfks_decrypt_start_key(uint8_t p_key[AES128_KEY_SIZE]);


#endif /* !defined(AES_H) */

