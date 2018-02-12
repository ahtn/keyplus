// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

/// @file core/util.h
/// Provides compiler utility macros for different compilers and some small
/// utility functions.

#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

// compiler
#if defined(__SDCC_mcs51)
// sdcc
#define REENT __reentrant
#define XRAM __xdata
#define IRAM __idata
#define PRAM __pdata
#define ROM __code
#define WEAK __attribute__((weak))
#define AT(address) __at (address)
// sdcc doesn't have no return attribute.
#define NO_RETURN_ATTR

#elif defined(AVR) && defined(__GNUC__)

#include "avr/pgmspace.h"

#define REENT
#define XRAM
#define IRAM
#define PRAM
#define ROM __flash
#define WEAK __attribute__((weak))
#define AT(address)
#define NO_RETURN_ATTR __ATTR_NORETURN__

#else
// fallback versions

/// Indicates that a function should be reentrant for the 8051 compiler.
///
/// Since the 8051 has limited stack space, the compiler does not use a stack
/// like most other traditional c compilers. Instead function arguments are
/// stored in fixed register/SRAM locations which are calculated at compile time.
/// The
///
/// Refrences: [sdcc compiler manual](http://sdcc.sourceforge.net/doc/sdccman.pdf)
#define REENT

/// Indicates that a variable should be placed in external RAM on 8051 ports.
///
/// The 8051 has two classes or RAM: SRAM and XRAM (external RAM). SRAM is used
/// as the default storage classes for variables as it is faster and generates
/// smaller code.  However, SRAM is very limited on the 8051 (only 256 bytes)
/// and is mainly used for the stack space for function calls. For this reason
/// global variables and large variables should be placed in XRAM with the
/// `XRAM` specifier, otherwise the compiler will run out of SRAM space.
///
/// Also, this specifier can be used with pointers to point to a variable or
/// address in XRAM.
///
/// Refrences: [sdcc compiler manual](http://sdcc.sourceforge.net/doc/sdccman.pdf)
#define XRAM

/// Indicates that a variable should be placed in flash / read-only memory.
///
/// On `avr-gcc` this is equivalent to `__flash`.
/// On `sdcc` this is equivalent to `__code`.
#define ROM

/// Functions defined with the `WEAK` attribute can be overridden by other implementations
///
/// Supported by: GCC
#define WEAK

/// On the 8051 compilers, this attribute can be used to place a variable at fixed address.
///
/// Supported by sdcc. To achieve the same affect on other compilers, it is
/// necessary to use linker scripts.
///
/// Supported by: sdcc
#define AT(address)

/// Attribute used with functions that don't return.
///
/// Marking a function as `NO_RETURN_ATTR` will allow the compiler to make
/// significant space optimizations. One use of this attribute is with custom
/// `assert()` implementations in debug builds that hang the CPU when an
/// assertion fails.
#define NO_RETURN_ATTR

// TODO: probably won't use these
// #define IRAM
// #define PRAM
// #define ISR(x)
#endif

#if defined(__SDCC_mcs51) || defined(DOXYGEN)
/// Single bit or boolean variable type.
///
/// The 8051 compiler has access to single bit registers. Using these registers
/// results in smaller code size.
///
/// On other architectures this maps to `bool`.
#define bit_t __bit
#else
#define bit_t bool
#endif

// TODO: The names of these functions are very common and probably will cause
// naming conflicts in the future. Should probably rename them.
#define SIGN(x) ((x) == 0 ? 0 : ((x) < 0 ? -1 : +1))
#define LSB(x) ((x) & 0xff)
#define MSB(x) (((x) >> 8) & 0xff)
#define MAX(x, y) ((x) > (y) ? (x) : (y))

/// Perform integer division and round up instead of down
///
/// Let x,y be integers, then INT_DIV_ROUND_UP(x,y) = ceil(x/y)
#define INT_DIV_ROUND_UP(dividend, divisor) (\
    ( (dividend) + ((divisor)-1) ) / (divisor) \
)

#if defined(__SDCC_mcs51) || defined(DOXYGEN)
// #if 1

/// Returns the `n`th bit of `byte`
///
/// Note: the `sdcc` compiler has pretty bad optimizations for bit shifts. Using
/// this function can save significant code space.
bit_t is_bitn_set(uint8_t byte, uint8_t n);

/// Gets a bit mask for the `n`th bit;
///
/// Note: the `sdcc` compiler has pretty bad optimizations for bit shifts. Using
/// this function can save significant code space.
uint8_t bitn_mask(uint8_t n);

/// Get bit `n` in a bitmap array.
bit_t bitmap_get_bit(uint8_t *array, uint8_t n);

/// Set bit `n` in a bitmap array.
void bitmap_set_bit(uint8_t *array, uint8_t n);

/// Clear bit `n` in a bitmap array.
void bitmap_clear_bit(uint8_t *array, uint8_t n);

#else

#define is_bitn_set(byte, n) ((byte) & (1 << (n)))
#define bitn_mask(n) (1 << (n))

#define bitmap_get_bit(array, n) is_bitn_set(array[n / 8], n%8)
#define bitmap_set_bit(array, n) (array[n / 8] |= (bitn_mask(n % 8)))
#define bitmap_clear_bit(array, n) (array[n / 8] &= ~(bitn_mask(n % 8)))

#endif

