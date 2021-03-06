/*****************************************************************************
 * aes-mix-columns-inv.c
 *
 * Implementation of AES decryption inverse mix-columns step.
 ****************************************************************************/

/*****************************************************************************
 * Include
 ****************************************************************************/

#include "aes.h"
#include "aes-mix-columns.h"
#include "aes-mul2.h"

#include <string.h>

/*****************************************************************************
 * Functions
 ****************************************************************************/

/* 14 = 1110b
 *  9 = 1001b
 * 13 = 1101b
 * 11 = 1011b
 */
void aes_mix_columns_inv(uint8_t p_block[AES_BLOCK_SIZE])
{
    uint8_t         temp_column[AES_COLUMN_SIZE];
    uint_fast8_t    i;
    uint_fast8_t    j;
    uint8_t         byte_value;
    uint8_t         byte_value_2;
    uint8_t         byte_value_4;
    uint8_t         byte_value_8;

    for (i = 0; i < AES_NUM_COLUMNS; i++)
    {
        memset(temp_column, 0, AES_COLUMN_SIZE);
        for (j = 0; j < AES_COLUMN_SIZE; j++)
        {
            byte_value = p_block[i * AES_COLUMN_SIZE + j];
            byte_value_2 = aes_mul2(byte_value);
            byte_value_4 = aes_mul2(byte_value_2);
            byte_value_8 = aes_mul2(byte_value_4);
            temp_column[(j + 0 ) % AES_COLUMN_SIZE] ^= byte_value_8 ^ byte_value_4 ^ byte_value_2;  // 14 = 1110b
            temp_column[(j + 1u) % AES_COLUMN_SIZE] ^= byte_value_8 ^ byte_value;                   //  9 = 1001b
            temp_column[(j + 2u) % AES_COLUMN_SIZE] ^= byte_value_8 ^ byte_value_4 ^ byte_value;    // 13 = 1101b
            temp_column[(j + 3u) % AES_COLUMN_SIZE] ^= byte_value_8 ^ byte_value_2 ^ byte_value;    // 11 = 1011b
        }
        memcpy(&p_block[i * AES_COLUMN_SIZE], temp_column, AES_COLUMN_SIZE);
    }
}
