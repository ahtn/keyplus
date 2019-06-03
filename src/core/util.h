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
    #define WEAK
    #define AT(address) __at (address)
    // sdcc doesn't have no return attribute.
    #define NO_RETURN_ATTR
    // sdcc has no attribute for packed structs, however since the target is 8
    // bit, padding won't be used anyway so it's not needed
    #define ATTR_PACKED
#elif defined(__arm__) && defined(__GNUC__)
    #define REENT
    #define XRAM
    #define IRAM
    #define PRAM
    #define ROM
    #define WEAK __attribute__((weak))
    #define ATTR_PACKED __attribute__((packed))
    #define AT(address)
    #define NO_RETURN_ATTR __attribute__((noreturn))
#elif (defined(__x86_64__) || defined(__i386__)) && defined(__GNUC__)
    #define REENT
    #define XRAM
    #define IRAM
    #define PRAM
    #define ROM
    #define WEAK __attribute__((weak))
    #define ATTR_PACKED __attribute__((packed))
    #define AT(address)
    #define NO_RETURN_ATTR __attribute__((noreturn))
#elif defined(AVR) && defined(__GNUC__)
    #include "avr/pgmspace.h"

    #define REENT
    #define XRAM
    #define IRAM
    #define PRAM
    #define ROM __flash
    #define WEAK __attribute__((weak))
    #define ATTR_PACKED __attribute__((packed))
    #define AT(address)
    #define NO_RETURN_ATTR __attribute__((noreturn))
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
    /// The 8051 has two main classes of RAM: internal ram (IRAM) and external RAM (XRAM).
    /// IRAM is used as the default storage classes for variables as it is faster
    /// and generates smaller code.  However, IRAM is very limited on the 8051
    /// (only 256 bytes) and is mainly used for the stack space for function calls.
    /// For this reason global variables and large variables should be placed in
    /// XRAM with the `XRAM` specifier, otherwise the compiler will run out of SRAM
    /// space.
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

    /// Compiler attribute to specify no padding in C structs
    #define ATTR_PACKED

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

/// Compile time assert.
///
/// If available use C11 _Static_assert, if compile doesn't support it then,
/// use workaround
#define KP_STATIC_ASSERT(x, y) _Static_assert(x, y)

#if defined __SDCC
    #define UNREFERENCED_ARGUMENT(arg) ((void)arg)
#else
    #define UNREFERENCED_ARGUMENT(arg) ((void)arg)
#endif

#define KP_SIGN(x) ((x) == 0 ? 0 : ((x) < 0 ? -1 : +1))
#define KP_MAX(x, y) ((x) > (y) ? (x) : (y))
#define KP_MIN(x, y) ((x) < (y) ? (x) : (y))

#define LSB_U16(x) ((x) & 0xff)
#define MSB_U16(x) (((x) >> 8) & 0xff)


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

#ifdef __SDCC_mcs51
    // Have to make all the compiler optimizations ourself
    #define read_u16le(ptr) (*((uint16_t*)(ptr)))
    #define read_u24le(ptr) (\
          ((uint32_t)(ptr)[0] <<  0) \
        | ((uint32_t)(ptr)[1] <<  8) \
        | ((uint32_t)(ptr)[2] << 16) \
    )
    #define read_u32le(ptr) (*((uint32_t*)(ptr)))
#else
    /// Read data from pointer as little endian uint16
    #define read_u16le(ptr) (\
          ((uint16_t)(ptr)[0] << 0) \
        | ((uint16_t)(ptr)[1] << 8) \
    )
    /// Read data from pointer as little endian uint24
    #define read_u24le(ptr) (\
          ((uint32_t)(ptr)[0] <<  0) \
        | ((uint32_t)(ptr)[1] <<  8) \
        | ((uint32_t)(ptr)[2] << 16) \
    )
    /// Read data from pointer as little endian uint32
    #define read_u32le(ptr) (\
          ((uint32_t)(ptr)[0] <<  0) \
        | ((uint32_t)(ptr)[1] <<  8) \
        | ((uint32_t)(ptr)[2] << 16) \
        | ((uint32_t)(ptr)[3] << 24) \
    )
#endif

/// Read data from pointer as big endian uint16
#define read_u16be(ptr) (\
      ((uint16_t)(ptr)[1] << 0) \
    | ((uint16_t)(ptr)[0] << 8) \
)
/// Read data from pointer as big endian uint24
#define read_u24be(ptr) (\
      ((uint32_t)(ptr)[2] <<  0) \
    | ((uint32_t)(ptr)[1] <<  8) \
    | ((uint32_t)(ptr)[0] << 16) \
)
/// Read data from pointer as big endian uint32
#define read_u32be(ptr) (\
      ((uint32_t)(ptr)[3] <<  0) \
    | ((uint32_t)(ptr)[2] <<  8) \
    | ((uint32_t)(ptr)[1] << 16) \
    | ((uint32_t)(ptr)[0] << 24) \
)

/// Write data pointer as little endian uint16
#define write_u16le(ptr, data) do {\
    (ptr)[0] = ((data) >> 0) & 0xff; \
    (ptr)[1] = ((data) >> 8) & 0xff; \
} while(0)
/// Write data pointer as little endian uint24
#define write_u24le(ptr) do {\
    (ptr)[0] = ((data) >>  0) & 0xff; \
    (ptr)[1] = ((data) >>  8) & 0xff; \
    (ptr)[2] = ((data) >> 16) & 0xff; \
} while(0)
/// Write data pointer as little endian uint32
#define write_u32le(ptr) do {\
    (ptr)[0] = ((data) >>  0) & 0xff; \
    (ptr)[1] = ((data) >>  8) & 0xff; \
    (ptr)[2] = ((data) >> 16) & 0xff; \
    (ptr)[3] = ((data) >> 24) & 0xff; \
} while(0)

/// Write data pointer as big endian uint16
#define write_u16be(ptr, data) do {\
    (ptr)[0] = ((data) >> 8) & 0xff; \
    (ptr)[1] = ((data) >> 0) & 0xff; \
} while(0)
/// Write data pointer as big endian uint24
#define write_u24be(ptr) do {\
    (ptr)[0] = ((data) >> 16) & 0xff; \
    (ptr)[1] = ((data) >>  8) & 0xff; \
    (ptr)[2] = ((data) >>  0) & 0xff; \
} while(0)
/// Write data pointer as big endian uint32
#define write_u32be(ptr) do {\
    (ptr)[0] = ((data) >> 24) & 0xff; \
    (ptr)[1] = ((data) >> 16) & 0xff; \
    (ptr)[2] = ((data) >>  8) & 0xff; \
    (ptr)[3] = ((data) >>  0) & 0xff; \
} while(0)

/// Convert an u16 to network byte order
#ifndef htons
#define htons(x) ( (x&0xff00)>>8 | (x&0x00ff)<<8 )
#endif

/// Convert an u16 to host byte order
#ifndef ntohs
#define ntohs(x) ( (x&0xff00)>>8 | (x&0x00ff)<<8 )
#endif
