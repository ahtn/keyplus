; Copyright 2017 jem@seethis.link
; Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include <avr/io.h>

#define NVM_CMD_NO_OPERATION_gc (0x00<<0)   // Noop/Ordinary LPM

; avr-asm notes
; caller saved registers
; r18-r27, Z(r30-r31)
.section .text

.global erase_application_page_fn
; ---
; This routine erases the page at address R25:R24:R23:R22 in the application
; section. The address can point anywhere inside the page.
; Input:
;     R25:R24:R23:R22 - Byte address into Flash page.
;
; Returns:
;     Nothing.
; ---
erase_application_page_fn:
	rcall	SP_EraseApplicationPage
	rcall	SP_WaitForSPM
	ldi	r18, NVM_CMD_NO_OPERATION_gc
	sts	NVM_CMD, r18
	ret

.global write_application_page_fn
; ---
; 1. This routine flushes the Flash page buffer.
;
; 2. This routine writes an entire page from the SRAM buffer at
; address R25:R24 into the Flash page buffer.
;
; 3. This routine writes the page buffer to the Flash page at address R23:R22:R21:R20
; in the application section. The address can point anywhere inside the page.
;
; Input:
;     R25:R24 - 16-bit pointer to SRAM buffer.
;     R23:R22:R21:R20 - Byte address into Flash page.
;
; Returns:
;     Nothing.
; ---
write_application_page_fn:
	; save flash address (r23-r20) to stack
	push	r23
	push	r22
	push	r21
	push	r20
	rcall	SP_EraseFlashBuffer	; flush flash page buffer
	rcall	SP_WaitForSPM

	rcall	SP_LoadFlashPage	; load the flash page buffer (R25:R24)
	rcall	SP_WaitForSPM

	pop	r22			; restore flash address to R25:R24:R23:R22
	pop	r23
	pop	r24
	pop	r25
	rcall	SP_WriteApplicationPage	; write the flash page buffer
	rcall	SP_WaitForSPM

	ldi	r18, NVM_CMD_NO_OPERATION_gc
	sts	NVM_CMD, r18

	ret


.section .spm_interface_table,"ax",@progbits


#if BOOT_SECTION_SIZE <= 0x1000
.MACRO		spm_jmp addr
		rjmp \addr
.ENDM
#else
.MACRO		spm_jmp addr
		jmp \addr
.ENDM
#endif

; table pos 0
.global erase_application_page
erase_application_page:
	spm_jmp		erase_application_page_fn

; table pos 1
.global write_application_page
write_application_page:
	spm_jmp	write_application_page_fn

; table pos 2
.global SP_ReadCalibrationByte_fn
SP_ReadCalibrationByte_fn:
	spm_jmp	SP_ReadCalibrationByte

; table pos 3
.global SP_ReadFuseByte_fn
SP_ReadFuseByte_fn:
	spm_jmp	SP_ReadFuseByte

; table pos 4
.global SP_WriteLockBits_fn
SP_WriteLockBits_fn:
	spm_jmp	SP_WriteLockBits

; table pos 5
.global SP_ReadLockBits_fn
SP_ReadLockBits_fn:
	spm_jmp	SP_ReadLockBits

; table pos 6
.global SP_ReadUserSignatureByte_fn
SP_ReadUserSignatureByte_fn:
	spm_jmp	SP_ReadUserSignatureByte

; table pos 7
.global SP_EraseUserSignatureRow_fn
SP_EraseUserSignatureRow_fn:
	spm_jmp	SP_EraseUserSignatureRow

; table pos 8
.global SP_WriteUserSignatureRow_fn
SP_WriteUserSignatureRow_fn:
	spm_jmp	SP_WriteUserSignatureRow

; table pos 9
.global SP_EraseApplicationPage_fn
SP_EraseApplicationPage_fn:
	spm_jmp	SP_EraseApplicationPage

; table pos 10
.global SP_EraseWriteApplicationPage_fn
SP_EraseWriteApplicationPage_fn:
	spm_jmp	SP_EraseWriteApplicationPage

; table pos 11
.global SP_WriteApplicationPage_fn
SP_WriteApplicationPage_fn:
	spm_jmp	SP_WriteApplicationPage

; table pos 12
.global SP_LoadFlashWord_fn
SP_LoadFlashWord_fn:
	spm_jmp	SP_LoadFlashWord

; table pos 13
.global SP_LoadFlashPage_fn
SP_LoadFlashPage_fn:
	spm_jmp	SP_LoadFlashPage

; table pos 14
.global SP_ReadFlashPage_fn
SP_ReadFlashPage_fn:
	spm_jmp	SP_ReadFlashPage

; table pos 15
.global SP_EraseFlashBuffer_fn
SP_EraseFlashBuffer_fn:
	spm_jmp	SP_EraseFlashBuffer

; table pos 16
.global SP_ApplicationCRC_fn
SP_ApplicationCRC_fn:
	spm_jmp	SP_ApplicationCRC

; table pos 17
.global SP_BootCRC_fn
SP_BootCRC_fn:
	spm_jmp	SP_BootCRC

; table pos 18
.global SP_LockSPM_fn
SP_LockSPM_fn:
	spm_jmp	SP_LockSPM

; table pos 19
.global SP_WaitForSPM_fn
SP_WaitForSPM_fn:
	spm_jmp	SP_WaitForSPM

