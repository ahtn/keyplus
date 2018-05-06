/*****************************************************************************
 * aes-inv.c
 *
 * aes_inv() calculates multiplicative inverse in Galois field GF(2^8) with
 * reduction polynomial 0x11B.
 ****************************************************************************/

/*****************************************************************************
 * Includes
 ****************************************************************************/

#include "aes-inv.h"
#include "aes-mul.h"

/*****************************************************************************
 * Defines
 ****************************************************************************/

#define CHAIN_LEN           11u

/*****************************************************************************
 * Functions
 ****************************************************************************/

/* Calculation of inverse in GF(2^8), by exponentiation to power 254.
 * Use minimal addition chain to raise to the power of 254, which requires
 * 11 multiplies.
 * There are many addition chains of length 11 for 254. This one was picked
 * because it has the most multiplies by the previous value, and least
 * references to earlier history, which in theory could minimise the size of
 * prev_values[]. However, in the end we do the simplest possible
 * implementation of the algorithm to minimise code size (because aes_inv() is
 * used to achieve smallest possible S-box implementation), so it doesn't
 * really matter which addition chain we pick.
 */
uint8_t aes_inv(uint8_t a)
{
    static const uint8_t addition_chain_idx[CHAIN_LEN] = { 0, 1, 1, 3, 4, 3, 6, 7, 3, 9, 1 };
    uint_fast8_t    i;
    uint8_t         prev_values[CHAIN_LEN];

    for (i = 0; i < CHAIN_LEN; i++)
    {
        prev_values[i] = a;
        a = aes_mul(a, prev_values[addition_chain_idx[i]]);
    }
    return a;
}
