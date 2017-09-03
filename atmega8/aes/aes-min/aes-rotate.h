/*****************************************************************************
 * aes-rotate.h
 ****************************************************************************/

#ifndef AES_ROTATE_H
#define AES_ROTATE_H

/*****************************************************************************
 * Includes
 ****************************************************************************/

#include <stdint.h>

/*****************************************************************************
 * Inline functions
 ****************************************************************************/

/* Hopefully the compiler reduces this to a single rotate instruction.
 * However in testing with gcc on x86-64, it didn't happen. But it is target-
 * and compiler-specific.
 *
 * Alternatively for a particular platform:
 *     - Use an intrinsic 8-bit rotate function provided by the compiler.
 *     - Use inline assembler.
 *
 * TODO: Examine code produced on the target platform.
 */
static inline uint8_t aes_rotate_left_uint8(uint8_t a, uint_fast8_t num_bits)
{
    return ((a << num_bits) | (a >> (8u - num_bits)));
}

#endif /* !defined(AES_MUL2_H) */

