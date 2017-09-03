/*****************************************************************************
 * aes-mix-columns.h
 *
 * Prototypes for AES encryption mix-columns and decryption inverse steps.
 ****************************************************************************/

#ifndef AES_MIX_COLUMNS_H
#define AES_MIX_COLUMNS_H

/*****************************************************************************
 * Includes
 ****************************************************************************/

#include <stdint.h>

/*****************************************************************************
 * Function prototypes
 ****************************************************************************/

void aes_mix_columns(uint8_t p_block[AES_BLOCK_SIZE]);
void aes_mix_columns_inv(uint8_t p_block[AES_BLOCK_SIZE]);

#endif /* !defined(AES_MIX_COLUMNS_H) */
