/*****************************************************************************
 * aes-sbox.h
 *
 * Prototypes for AES S-box and inverse S-box.
 ****************************************************************************/

#ifndef AES_SBOX_H
#define AES_SBOX_H

/*****************************************************************************
 * Includes
 ****************************************************************************/

#include "aes.h"

#include <stdint.h>

/*****************************************************************************
 * Function prototypes
 ****************************************************************************/

uint8_t aes_sbox(uint8_t a);
uint8_t aes_sbox_inv(uint8_t a);
void aes_sbox_apply_block(uint8_t p_block[AES_BLOCK_SIZE]);
void aes_sbox_inv_apply_block(uint8_t p_block[AES_BLOCK_SIZE]);


#endif /* !defined(AES_SBOX_H) */
