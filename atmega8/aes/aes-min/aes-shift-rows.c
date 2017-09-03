/*****************************************************************************
 * aes-shift-rows.c
 *
 * Implementation of AES encryption shift-rows step.
 ****************************************************************************/

/*****************************************************************************
 * Includes
 ****************************************************************************/

#include "aes.h"
#include "aes-shift-rows.h"

/*****************************************************************************
 * Functions
 ****************************************************************************/

void aes_shift_rows(uint8_t p_block[AES_BLOCK_SIZE])
{
    uint8_t temp_byte;

    /* First row doesn't shift */

    /* Shift the second row */
    temp_byte = p_block[0 * AES_COLUMN_SIZE + 1u];
    p_block[0  * AES_COLUMN_SIZE + 1u] = p_block[1u * AES_COLUMN_SIZE + 1u];
    p_block[1u * AES_COLUMN_SIZE + 1u] = p_block[2u * AES_COLUMN_SIZE + 1u];
    p_block[2u * AES_COLUMN_SIZE + 1u] = p_block[3u * AES_COLUMN_SIZE + 1u];
    p_block[3u * AES_COLUMN_SIZE + 1u] = temp_byte;

    /* Shift the third row */
    temp_byte = p_block[0 * AES_COLUMN_SIZE + 2u];
    p_block[0  * AES_COLUMN_SIZE + 2u] = p_block[2u * AES_COLUMN_SIZE + 2u];
    p_block[2u * AES_COLUMN_SIZE + 2u] = temp_byte;
    temp_byte = p_block[1u * AES_COLUMN_SIZE + 2u];
    p_block[1u * AES_COLUMN_SIZE + 2u] = p_block[3u * AES_COLUMN_SIZE + 2u];
    p_block[3u * AES_COLUMN_SIZE + 2u] = temp_byte;

    /* Shift the fourth row */
    temp_byte = p_block[3u * AES_COLUMN_SIZE + 3u];
    p_block[3u * AES_COLUMN_SIZE + 3u] = p_block[2u * AES_COLUMN_SIZE + 3u];
    p_block[2u * AES_COLUMN_SIZE + 3u] = p_block[1u * AES_COLUMN_SIZE + 3u];
    p_block[1u * AES_COLUMN_SIZE + 3u] = p_block[0  * AES_COLUMN_SIZE + 3u];
    p_block[0  * AES_COLUMN_SIZE + 3u] = temp_byte;
}
