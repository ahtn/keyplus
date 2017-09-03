/*****************************************************************************
 * aes-mul.c
 *
 * aes_mul() multiplies two numbers in Galois field GF(2^8) with reduction
 * polynomial 0x11B.
 ****************************************************************************/

/*****************************************************************************
 * Includes
 ****************************************************************************/

#include "aes-mul.h"
#include "aes-mul2.h"

/*****************************************************************************
 * Functions
 ****************************************************************************/

/* Multiply two numbers in Galois field GF(2^8) with reduction polynomial
 * 0x11B.
 * TODO: To prevent timing attacks, analyse the compiler-generated code
 * to see if it has constant execution time regardless of input values.
 */
uint8_t aes_mul(uint8_t a, uint8_t b)
{
    uint8_t         result = 0;
    uint_fast8_t    i;
    for (i = 0; i < 8u; i++)
    {
#if 0
        /* This code variant is less likely to have constant execution time,
         * and thus more likely to be vulnerable to timing attacks. */
        if (b & 1)
        {
            result ^= a;
        }
#else
        result ^= (-(b & 1u)) & a;
#endif
        a = aes_mul2(a);
        b >>= 1;
    }
    return result;
}

