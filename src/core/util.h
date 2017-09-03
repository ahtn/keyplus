// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

// compiler
#ifdef SDCC
// sdcc
#define REENT __reentrant
#define XRAM __xdata
#define IRAM __idata
#define PRAM __pdata
#define ROM __code
#define WEAK __attribute__((weak))
#define AT(addr) __at (addr)

#elif AVR

#include "avr/pgmspace.h"

#define REENT
#define XRAM
#define IRAM
#define PRAM
#define ROM __flash
#define WEAK __attribute__((weak))
#define AT(addr)

#else
// generic
#define REENT
#define XRAM
#define IRAM
#define PRAM
#define ROM
#define WEAK
#define ISR(x)
#define AT(addr)
#endif

#if defined(__SDCC_mcs51)
// using __bit instead of bool reduces code size, but it can't be accessed by a pointer
#define bit_t __bit
#else
#define bit_t bool
#endif

#define SIGN(x) (x == 0 ? 0 : (x < 0 ? -1 : +1))

#define LSB(x) (x & 0xff)
#define MSB(x) ((x >> 8) & 0xff)

#define MAX(x, y) ((x > y) ? x : y)

bool bitn(uint8_t byte, uint8_t n);

uint8_t is_buffer_zeroed(uint8_t *buffer, uint8_t len);
