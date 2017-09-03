/*****************************************************************************
 * aes-shift-rows.h
 *
 * Prototypes for AES encryption shift-rows and decryption inverse steps.
 ****************************************************************************/

#ifndef AES_SHIFT_ROWS_H
#define AES_SHIFT_ROWS_H

/*****************************************************************************
 * Includes
 ****************************************************************************/

#include <stdint.h>

/*****************************************************************************
 * Function prototypes
 ****************************************************************************/

void aes_shift_rows(uint8_t p_block[AES_BLOCK_SIZE]);
void aes_shift_rows_inv(uint8_t p_block[AES_BLOCK_SIZE]);

#endif /* !defined(AES_SHIFT_ROWS_H) */
