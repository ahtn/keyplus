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


/*
 * param a: r24
 * param b: r22
 * param reducer: r0
 */
A = 28
B = 29
P = 0
xREDUCER = 25

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
T0= 2
T1= 3
T2= 4
T3= 5
SBOX_SAVE0 = 6
SBOX_SAVE1 = 7
ST00 =  8
ST01 =  9
ST02 = 10
ST03 = 11
ST10 = 12
ST11 = 13
ST12 = 14
ST13 = 15
ST20 = 16
ST21 = 17
ST22 = 18
ST23 = 19
ST30 = 20
ST31 = 21
ST32 = 22
ST33 = 23
CTR = 24
/*
 * param state:  r24:r25
 * param ks:     r22:r23
 * param rounds: r20   
 */
.global aes_encrypt_core
aes_encrypt_core:
	push_range 2, 17
	push r28
	push r29
	push r24
	push r25
	movw r26, r22
	movw r30, r24
	mov  CTR, r20
	clt
	
	.irp row, 0, 1, 2, 3
		.irp col, 0, 1, 2, 3
			ld ST\row\col, Z+
		.endr
	.endr
	
	ldi xREDUCER, 0x1b /* load reducer */
	ldi r31, hi8(aes_sbox)
	
	/* key whitening */
1:

	.irp row, 0, 1, 2, 3
		.irp col, 0, 1, 2, 3
			ld r0, X+
			eor ST\row\col, r0
		.endr
	.endr
	
	brtc 2f
exit:
	pop r31
	pop r30
	.irp row, 0, 1, 2, 3
			.irp col, 0, 1, 2, 3
			st Z+, ST\row\col
		.endr
	.endr
	pop r29
	pop r28
	pop_range 2, 17
	ret

2:	dec CTR
	brne 3f
	set
3:

	/* encryption loop */ 

	/* SBOX substitution and shifting */
	mov r30, ST00
	lpm ST00, Z
	mov r30, ST10
	lpm ST10, Z
	mov r30, ST20
	lpm ST20, Z
	mov r30, ST30
	lpm ST30, Z

	mov r30, ST01
	lpm T0, Z
	mov r30, ST11
	lpm ST01, Z
	mov r30, ST21
	lpm ST11, Z
	mov r30, ST31
	lpm ST21, Z
	mov ST31, T0

	mov r30, ST02
	lpm T0, Z
	mov r30, ST12
	lpm T1, Z
	mov r30, ST22
	lpm ST02, Z
	mov r30, ST32
	lpm ST12, Z
	mov ST22, T0
	mov ST32, T1

	mov r30, ST03
	lpm T0, Z
	mov r30, ST33
	lpm ST03, Z
	mov r30, ST23
	lpm ST33, Z
	mov r30, ST13
	lpm ST23, Z
	mov ST13, T0
		
	/* mixcols (or rows in our case) */
	brtc 2f
	rjmp 1b
2:	
 /* mixrows */
 .irp row, 0, 1, 2, 3
	mov r0, ST\row\()2
	eor r0, ST\row\()3
	mov T2, r0

	mov T0, ST\row\()0
	eor ST\row\()0, ST\row\()1
	eor r0, ST\row\()0
	lsl ST\row\()0
	brcc 3f
	eor ST\row\()0, xREDUCER
3:	eor ST\row\()0, r0
	eor ST\row\()0, T0

	mov T1, ST\row\()1
	eor T1, ST\row\()2
	lsl T1
	brcc 3f
	eor T1, xREDUCER
3:	eor T1, r0
	eor ST\row\()1, T1

	lsl T2
	brcc 3f
	eor T2, xREDUCER
3:  eor T2, r0
	eor ST\row\()2, T2

	eor T0, ST\row\()3
	lsl T0
	brcc 3f
	eor T0, xREDUCER
3:	eor T0, r0
	eor ST\row\()3, T0

.endr
	/* mix colums (rows) done */

	/* add key*/
	rjmp 1b
	








