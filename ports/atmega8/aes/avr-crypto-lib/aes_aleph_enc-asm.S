/* aes_enc-asm.S */
/*
    This file is part of the AVR-Crypto-Lib.
    Copyright (C) 2006-2015 Daniel Otte (bg@nerilex.org)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
/**
 * \file     aes_enc-asm.S
 * \email    bg@nerilex.org
 * \author   Daniel Otte 
 * \date     2009-01-10
 * \license  GPLv3 or later
 * 
 */

#include "avr-asm-macros.S"


xtime:
	lsl r24
	brcc 1f
	eor r24, r27
1:
	ret

shift_offset_table:
	.byte 12,  8,  4,  0
	.byte  9,  5,  1, 13
	.byte  6,  2, 14, 10
	.byte  3, 15, 11,  7

.global aes256_enc
aes256_enc:
	ldi r20, 14
	rjmp aes_encrypt_core

.global aes192_enc
aes192_enc:
	ldi r20, 12
	rjmp aes_encrypt_core

.global aes128_enc
aes128_enc:
	ldi r20, 10

/*
  void aes_encrypt_core(aes_cipher_state_t *state, const aes_genctx_t *ks, uint8_t rounds)
*/
/*
 * param state:  r24:r25
 * param ks:     r22:r23
 * param rounds: r20   
 */

.global aes_encrypt_core
aes_encrypt_core:
	push r3
	push r16
	push r17
	push r28
	push r29
	mov r3, r20
	clt
	movw r28, r24
x:
	movw r24, r28
key_add:

	clr r21
	ldi r20, 16
	call memxor
	movw r22, r26 /* switch to next roundkey; r26 points after the end of src after memxor ;-) */

	brtc sub_shift_bytes
4:
	pop r29
	pop r28
	pop r17
	pop r16
	pop r3
	ret

sub_shift_bytes:
	ldi r30, lo8(shift_offset_table)
	ldi r31, hi8(shift_offset_table)
	ldi r20, 4   /* load counter for columns (rows in spec) */
	movw r24, r28
1:
	ldi r21, 4
2:
	ld r16, Y
	adiw r28, 4
	push r16
	dec r21
	brne 2b

	ldi r21, 4
2:
	pop r16
	movw r26, r24
	lpm r0, Z+
	add r26, r0
	adc r27, r1
	st X, r16
	dec r21
	brne 2b

	sbiw r28, 15

	dec r20
	brne 1b

	sbiw r28, 4 /* set Y back to the start of state */

	dec r3
	brne mix_rows
	set

mix_rows:
	ldi r31, hi8(aes_sbox)
	ldi r27, 0x1B
	ldi r20, 4
1:
	ldd r30, Y+0
	lpm r16, Z
	ldd r30, Y+1
	lpm r17, Z
	ldd r30, Y+2
	lpm r18, Z
	ldd r30, Y+3
	lpm r19, Z

	brts 2f
	mov r26, r16

	mov r24, r16
	eor r24, r17

	mov r21, r24
	eor r21, r18
	eor r21, r19

	rcall xtime
	eor r16, r24
	eor r16, r21

	mov r24, r17
	eor r24, r18
	rcall xtime
	eor r17, r24
	eor r17, r21

	mov r24, r18
	eor r24, r19
	rcall xtime
	eor r18, r24
	eor r18, r21

	mov r24, r19
	eor r24, r26
	rcall xtime
	eor r19, r24
	eor r19, r21
2:
	st Y+, r16
	st Y+, r17
	st Y+, r18
	st Y+, r19
	dec r20
	brne 1b
	sbiw r28, 16
	rjmp x

