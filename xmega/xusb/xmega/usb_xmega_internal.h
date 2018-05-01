// Copyright (c) 2011-2014 Nonolith Labs
// Copyright (c) 2014 Technical Machine
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.

#pragma once

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <avr/eeprom.h>
#include <util/delay.h>

#define CPU_TO_LE16(x) x

#define ATTR_ALWAYS_INLINE __attribute__ ((always_inline))

/// From Atmel: Macros for XMEGA instructions not yet supported by the toolchain
// Load and Clear
#ifdef __GNUC__
#define LACR16(addr,msk) \
    __asm__ __volatile__ ( \
    "ldi r16, %1" "\n\t" \
    ".dc.w 0x9306" "\n\t"\
    ::"z" (addr), "M" (msk):"r16")
#else
    #define LACR16(addr,msk) __lac((unsigned char)msk,(unsigned char*)addr)
#endif

// Load and Set
#ifdef __GNUC__
#define LASR16(addr,msk) \
    __asm__ __volatile__ ( \
    "ldi r16, %1" "\n\t" \
    ".dc.w 0x9305" "\n\t"\
    ::"z" (addr), "M" (msk):"r16")
#else
#define LASR16(addr,msk) __las((unsigned char)msk,(unsigned char*)addr)
#endif

// Exchange
#ifdef __GNUC__
#define XCHR16(addr,msk) \
    __asm__ __volatile__ ( \
    "ldi r16, %1" "\n\t" \
    ".dc.w 0x9304" "\n\t"\
    ::"z" (addr), "M" (msk):"r16")
#else
#define XCHR16(addr,msk) __xch(msk,addr)
#endif

// Load and toggle
#ifdef __GNUC__
#define LATR16(addr,msk) \
    __asm__ __volatile__ ( \
    "ldi r16, %1" "\n\t" \
    ".dc.w 0x9307" "\n\t"\
    ::"z" (addr), "M" (msk):"r16")
#else
#define LATR16(addr,msk) __lat(msk,addr)
#endif

#define USB_EP_size_to_gc(x)  ((x <= 8   )?USB_EP_BUFSIZE_8_gc:\
                               (x <= 16  )?USB_EP_BUFSIZE_16_gc:\
                               (x <= 32  )?USB_EP_BUFSIZE_32_gc:\
                               (x <= 64  )?USB_EP_BUFSIZE_64_gc:\
                               (x <= 128 )?USB_EP_BUFSIZE_128_gc:\
                               (x <= 256 )?USB_EP_BUFSIZE_256_gc:\
                               (x <= 512 )?USB_EP_BUFSIZE_512_gc:\
                                           USB_EP_BUFSIZE_1023_gc)
