; Copyright 2017 jem@seethis.link
; Licensed under the MIT license (http://opensource.org/licenses/MIT)
;
; Need to clear SRAM because it might hold sensitive data, otherwise newly loaded
; programs could potentially read that data.

#include <avr/io.h>

#define HI8(X) (((X) >> 8) & 0xff)
#define LO8(X) ((X) & 0xff)

#define BOOTLOADER_MAGIC_ADDR 0x2400

#define SRAM_FILL_VALUE 0xCC

.section .init3

save_magic:
	; lds	r16, (BOOTLOADER_MAGIC_ADDR+0)
	; lds	r17, (BOOTLOADER_MAGIC_ADDR+1)
	; lds	r18, (BOOTLOADER_MAGIC_ADDR+2)
	; lds	r19, (BOOTLOADER_MAGIC_ADDR+3)
	ldi	r31, HI8(BOOTLOADER_MAGIC_ADDR)	; Z is bootloader flag address
	ldi	r30, LO8(BOOTLOADER_MAGIC_ADDR)
	ld	r16, Z+				; save magic flag into r19:r18:r17:r16
	ld	r17, Z+
	ld	r18, Z+
	ld	r19, Z+

clear_sram:
	ldi	r23, SRAM_FILL_VALUE		; fill ram with a recognizable value
	ldi	r29, HI8(INTERNAL_SRAM_SIZE)	; Y is counter for sram size
	ldi	r28, LO8(INTERNAL_SRAM_SIZE)
	ldi	r27, HI8(INTERNAL_SRAM_START)	; X is write position for sram
	ldi	r26, LO8(INTERNAL_SRAM_START)

erase_loop:
	st	X+, r23		; 1 xmega cycle
	st	X+, r23		; 1 xmega cycle
	st	X+, r23		; 1 xmega cycle
	st	X+, r23		; 1 xmega cycle
	sbiw	Y, 4		; 2 cycles
	brne	erase_loop	; 2 cycles if true

restore_magic:
	; sts	(BOOTLOADER_MAGIC_ADDR+0), r16
	; sts	(BOOTLOADER_MAGIC_ADDR+1), r17
	; sts	(BOOTLOADER_MAGIC_ADDR+2), r18
	; sts	(BOOTLOADER_MAGIC_ADDR+3), r19
	st	-Z, r19		; restore magic flag into BOOTLOADER_MAGIC_ADDR
	st	-Z, r18
	st	-Z, r17
	st	-Z, r16

