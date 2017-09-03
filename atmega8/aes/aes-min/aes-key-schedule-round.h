/*****************************************************************************
 * aes-key-schedule-round.h
 *
 * In-place calculation of the next round of the AES-128 key schedule.
 * This is used for encryption with on-the-fly key schedule calculation.
 ****************************************************************************/

#ifndef AES_KEY_SCHEDULE_ROUND_H
#define AES_KEY_SCHEDULE_ROUND_H

/*****************************************************************************
 * Includes
 ****************************************************************************/

#include "aes.h"

/*****************************************************************************
 * Function prototypes
 ****************************************************************************/

void aes128_key_schedule_round(uint8_t p_key[AES128_KEY_SIZE], uint8_t rcon);

#endif /* !defined(AES_KEY_SCHEDULE_ROUND_H) */
