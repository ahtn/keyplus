/* Copyright (c) 2012 Michał Trybus <komar007 at gmail.com>
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

#pragma once

#include <avr/io.h>
#include <stdint.h>

#define LAST_BOOT_ENTRY (FLASHEND - 3)

/* Addresses to bootloader ABI functions (in bytes) */
#define PAGE_ERASE_AND_WRITE_ADDR	(LAST_BOOT_ENTRY - 24)
#define READ_SIG_ADDR			(LAST_BOOT_ENTRY - 20)
#define READ_FUSE_ADDR			(LAST_BOOT_ENTRY - 16)
#define FILL_TEMP_BUFFER_ADDR		(LAST_BOOT_ENTRY - 12)
#define PRG_PAGE_ADDR			(LAST_BOOT_ENTRY - 8)
#define PAGE_ERASE_ADDR			(LAST_BOOT_ENTRY - 4)
#define LOCK_WR_BITS_ADDR		(LAST_BOOT_ENTRY - 0)

#define PUSH_REGS \
	"push r0"     "\n\t" \
	"push r1"     "\n\t" \
	"push r16"    "\n\t" \
	"push r17"    "\n\t" \

#define POP_REGS \
	"pop r17"     "\n\t" \
	"pop r16"     "\n\t" \
	"pop r1"      "\n\t" \
	"pop r0"      "\n\t" \

/* wrapper which passes one 24-bit argument in r18:r17:r16 to Atmel DFU
 * bootloader function */
#define ATMEL_DFU_CALL_1ARG(addr, arg) \
(__extension__({                                              \
	__asm__ __volatile__(                                 \
		PUSH_REGS                                     \
		"mov r18, %0" "\n\t"                          \
		"mov r17, %1" "\n\t"                          \
		"mov r16, %2" "\n\t"                          \
		"call %3"     "\n\t"                          \
		POP_REGS                                      \
		:                                             \
		: "r" (((arg) >> 16) & 0xff),                 \
		  "r" (((arg) >>  8) & 0xff),                 \
		  "r" (((arg) >>  0) & 0xff),                 \
		  "i" ((addr))                                \
		: "r0", "r1", "r16", "r17", "r18",            \
		  "r20", "r30", "r31");                       \
}))                                                           \

/* wrapper which passes one 24-bit argument in r18:r17:r16 to Atmel DFU
 * bootloader function and returns value returned in r16 */
#define ATMEL_DFU_CALL_1ARG_RET(addr, arg) \
(__extension__({                                              \
	uint8_t ret;                                          \
	__asm__ __volatile__(                                 \
		PUSH_REGS                                     \
		"mov r18, %1" "\n\t"                          \
		"mov r17, %2" "\n\t"                          \
		"mov r16, %3" "\n\t"                          \
		"call %4"     "\n\t"                          \
		"mov %0, r16" "\n\t"                          \
		POP_REGS                                      \
		: "=r" (ret)                                  \
		: "r" (((arg) >> 16) & 0xff),                 \
		  "r" (((arg) >>  8) & 0xff),                 \
		  "r" (((arg) >>  0) & 0xff),                 \
		  "i" ((addr))                                \
		: "r0", "r1", "r16", "r17", "r18",            \
		  "r20", "r30", "r31");                       \
	ret;                                                  \
}))

/* wrapper which passes two 16-bit arguments in r17:r16 and r18:r19,
 * respectively */
#define ATMEL_DFU_CALL_2ARG(addr, arg1, arg2) \
(__extension__({                                              \
	__asm__ __volatile__(                                 \
		PUSH_REGS                                     \
		"mov r19, %0" "\n\t"                          \
		"mov r18, %1" "\n\t"                          \
		"mov r17, %2" "\n\t"                          \
		"mov r16, %3" "\n\t"                          \
		"call %4"     "\n\t"                          \
		POP_REGS                                      \
		:                                             \
		: "r" (((arg2) >> 8) & 0xff),                 \
		  "r" (((arg2) >> 0) & 0xff),                 \
		  "r" (((arg1) >> 0) & 0xff),                 \
		  "r" (((arg1) >> 8) & 0xff),                 \
		  "i" ((addr))                                \
		: "r0", "r1", "r16", "r17", "r18", "r19",     \
		  "r20", "r30", "r31");                       \
}))

/* Atmel DFU bootloader ABI calls */
static inline void flash_page_erase_and_write(uint32_t addr)
{
	ATMEL_DFU_CALL_1ARG(PAGE_ERASE_AND_WRITE_ADDR, addr);
}
static inline uint8_t flash_read_sig(uint32_t addr)
{
	return ATMEL_DFU_CALL_1ARG_RET(READ_SIG_ADDR, addr);
}
static inline uint8_t flash_read_fuse(uint32_t addr)
{
	return ATMEL_DFU_CALL_1ARG_RET(READ_FUSE_ADDR, addr);
}
static inline void flash_fill_temp_buffer(uint16_t data, uint16_t addr)
{
	ATMEL_DFU_CALL_2ARG(FILL_TEMP_BUFFER_ADDR, data, addr);
}
static inline void flash_prg_page(uint32_t addr)
{
	ATMEL_DFU_CALL_1ARG(PRG_PAGE_ADDR, addr);
}
static inline void flash_page_erase(uint32_t addr)
{
	ATMEL_DFU_CALL_1ARG(PAGE_ERASE_ADDR, addr);
}
static inline void flash_lock_wr_bits(uint8_t bits)
{
	ATMEL_DFU_CALL_1ARG(LOCK_WR_BITS_ADDR, (uint32_t)bits);
}

/* fuse bits addresses */
#define FUSE_LOW	0
#define FUSE_HIGH	3
#define FUSE_EXTENDED	2

#define BOOTSZ0 1
#define BOOTSZ1 2

/* Determines the size of bootloader section in run-time based on BOOTSZ[1..0]
 * fusebits */
static inline uint32_t bootloader_size(void)
{
	uint8_t hfuse = flash_read_fuse(FUSE_HIGH);
	uint8_t bootsz = (hfuse >> BOOTSZ0) & 0x03;
	return 512 << (3-bootsz);
}

/* Jumps to the beginning of bootloader. Address is computed in runtime */
static inline void run_bootloader(void)
{
	TIMSK0 = 0;
	/* compute the address of the beginning of the bootloader section and
	 * convert to word address */
	uint32_t bladdr = (FLASHEND - bootloader_size()) / 2 + 1;
	__asm__ __volatile__(
		"mov r30, %0" "\n\t"
		"mov r31, %1" "\n\t"
		"ijmp"
		:
		: "r" ((bladdr >> 0) & 0xff),
		  "r" ((bladdr >> 8) & 0xff)
		: "r30", "r31");
}

void flash_write_page(uint32_t addr, const uint8_t *data);
