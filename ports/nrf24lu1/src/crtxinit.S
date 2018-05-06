; Copyright 2017 jem@seethis.link
; Licensed under the MIT license (http://opensource.org/licenses/MIT)

.area GSINIT3   (CODE)

XRAM_SIZE = 0x800
XRAM_START = 0x8000

USE_XINIT = 1

; Initializes variables for the SDCC C compiler
; need to copy XINIT to XISEG
__mcs51_genXINIT::
.if USE_XINIT
; init xram
	orl	_DPS, #0x01
	mov	dptr, #s_XINIT ; dptr1 == s_XINIT (src)
	dec	_DPS
	mov	dptr, #s_XISEG ; dptr0 == s_XISEG (dest)

	mov	r1, #l_XINIT ; LSB
	mov	r2, #((l_XINIT+255) >> 8)
00001$:
	; read byte
	inc	_DPS
	movx	a, @dptr
	inc	dptr
	; copy byte
	mov	_DPS, #0x00
	movx	@dptr, a
	inc	dptr

	djnz	r1, 00001$
	djnz	r2, 00001$
.endif
