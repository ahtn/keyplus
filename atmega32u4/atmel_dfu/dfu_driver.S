;*A**************************************************************************
; $RCSfile: flash_boot_drv.s90,v $
;----------------------------------------------------------------------------
; Copyright (c) Atmel.
;----------------------------------------------------------------------------
; RELEASE:      $Name:  $
; REVISION:     $Revision: 1.7 $
; FILE_CVSID:   $Id: flash_boot_drv.s90,v 1.7 2005/10/03 15:50:12 $
;----------------------------------------------------------------------------
; PURPOSE:
; This file contains the low level driver for the flash access
;****************************************************************************
NAMEflash_drv(16)
;_____ I N C L U D E S ______________________________________________________
#define ASM_INCLUDE
#include "config.h"
;************************************************************************** **
; This is the absolute table entry points for low level flash drivers
; This table defines the entry points that can be called
; from the application section to perform on-chip flash operations:
;
;  entry_flash_page_erase_and_write:
;        R18:17:R16: The byte address of the page
;
;  entry_flash_fill_temp_buffer:
;        data16 :  R16/R17: word to load in the temporary buffer.
;        address:  R18/R19: address of the word in the temp. buffer.
;
;  entry_flash_prg_page:
;        R18:17:R16: The byte address of the page
;
;  entry_flash_page_erase:
;        R18:17:R16: The byte address of the page
;
;************************************************************************** **
ASEG FLASH_END-0x0001B
entry_flash_page_erase_and_write:
   JMP flash_page_erase_and_write
entry_flash_read_sig:
   JMP  flash_read_sig
entry_flash_read_fuse:
   JMP  flash_read_fuse
entry_flash_fill_temp_buffer:
   JMP  flash_fill_temp_buffer
entry_flash_prg_page:
   JMP  flash_prg_page
entry_flash_page_erase:
   JMP  flash_page_erase_public
entry_lock_wr_bits:
   JMP  lock_wr_bits
RSEGBOOT
;*F**************************************************************************
; NAME: flash_page_erase_and_write
;----------------------------------------------------------------------------
; PARAMS:  R18:17:R16: The byte address of the page
;----------------------------------------------------------------------------
; PURPOSE: This function can be called for the user appplication
; This function performs an erase operation of the selected target page and
; the launch the prog sequence of the same target page.
; This function allows to save the 256 bytes software temporary buffer in
; the application section
;****************************************************************************
flash_page_erase_and_write:
   PUSH  R18
   RCALL flash_page_erase
   POP   R18
   RCALL flash_prg_page
   RET
;*F**************************************************************************
; NAME: flash_prg_page
;----------------------------------------------------------------------------
; PARAMS: R18:17:R16: The byte address of the page
;----------------------------------------------------------------------------
; PURPOSE:  Launch the prog sequence of the target pag
;****************************************************************************
flash_prg_page:
  RCALL   WAIT_SPMEN  ;Wait for SPMEN flag cleared
  MOV     R31,R17
  MOV     R30,R16     ;move adress to z pointer (R31=ZH R30=ZL)
  OUT     RAMPZ, R18
  LDI     R20,$05     ;(1<<PGWRT) + (1<<SPMEN))
  OUT SPMCSR,R20; argument 2 decides function (r18)
  SPM                ;Store program memory
  RCALL    WAIT_SPMEN  ;Wait for SPMEN flag cleared
  RCALL   flash_rww_enable
  RET
;*F**************************************************************************
; NAME: flash_page_erase
;----------------------------------------------------------------------------
; PARAMS:   R18:17:R16: The byte address of the page
;----------------------------------------------------------------------------
; PURPOSE:  Launch the erase sequence of the target page
;----------------------------------------------------------------------------
; NOTE:  This function does nt set the RWWSE bit after erase. Thus it does
not
; erase the hardware temporary temp buffer.
; This function is for bootloader usage
;----------------------------------------------------------------------------
; REQUIREMENTS:
;****************************************************************************
 flash_page_erase:
  RCALL   WAIT_SPMEN  ;Wait for SPMEN flag cleared
  MOV     R31,R17
  MOV     R30,R16     ;move adress to z pointer (R31=ZH R30=ZL)
  OUT     RAMPZ, R18
  LDI     R20,$03     ;(1<<PGERS) + (1<<SPMEN)))
  OUT SPMCSR, R20; argument 2 decides function (r18)
  SPM                ;Store program memory
  RCALL    WAIT_SPMEN  ;Wait for SPMEN flag cleared
  ;RCALL   flash_rww_enable CAUTION DO NOT ACTIVATE HERE or
  ;        you will loose the entire page buffer content !!!
  RET
;*F**************************************************************************
; NAME: flash_page_erase_public
;----------------------------------------------------------------------------
; PARAMS:  R18:17:R16: The byte address of the page
;----------------------------------------------------------------------------
; PURPOSE:  Launch the erase sequence of the target page
;----------------------------------------------------------------------------
; NOTE:  !!!!This function set the RWWSE bit after erase. Thus it
; erase the hardware temporary temp buffer after page erase
;****************************************************************************
flash_page_erase_public:
  RCALL   WAIT_SPMEN  ;Wait for SPMEN flag cleared
  MOV     R31,R17
  MOV     R30,R16     ;move adress to z pointer (R31=ZH R30=ZL)
  OUT     RAMPZ, R18
  LDI     R20,$03     ;(1<<PGERS) + (1<<SPMEN)))
  OUTSPMCSR, R20; argument 2 decides function (r18)
  SPM                ;Store program memory
  RCALL    WAIT_SPMEN  ;Wait for SPMEN flag cleared
  RCALL   flash_rww_enable
  RET
;*F**************************************************************************
; NAME: flash_rww_enable
;----------------------------------------------------------------------------
; PARAMS:  none
;----------------------------------------------------------------------------
; PURPOSE:  Set RWSE bit. It allows to execute code in the application
section
; after a flash prog (erase or write page)
;****************************************************************************
  flash_rww_enable:
  RCALL   WAIT_SPMEN  ;Wait for SPMEN flag cleared
  LDI     R20,$11     ;(1<<WWSRE) + (1<<SPMEN)))
  OUT SPMCSR, R20 ; argument 2 decides function (r18)
  SPM                 ;Store program memory
  RJMP    WAIT_SPMEN  ;Wait for SPMEN flag cleare
;*F**************************************************************************
; NAME: flash_read_sig
;----------------------------------------------------------------------------
; PARAMS:
; Return: R16: signature value
;----------------------------------------------------------------------------
; PURPOSE:  Read harware signature byte. THe byte is selected trought the
addr
; passed as argument (see product data sheet)
;****************************************************************************
flash_read_sig:
  RCALL   WAIT_SPMEN  ;Wait for SPMEN flag cleared
  MOV     R31,R17
  MOV     R30,R16     ;move adress to z pointer (R31=ZH R30=ZL)
  OUT     RAMPZ, R18
  LDI     R20,$21     ;(1<<SPMEN) | (1<<SIGRD))
  OUT SPMCSR, R20; argument 2 decides function (r18)
  LPM                ;Store program memory
  MOV     R16, R0      ;Store return value (1byte->R16 register)
  RJMP    WAIT_SPMEN  ;Wait for SPMEN flag cleared
;*F**************************************************************************
; NAME: flash_read_fuse
;----------------------------------------------------------------------------
; Return: R16: fuse value
;----------------------------------------------------------------------------
; PURPOSE: Read fuse byte. The fuse byte is elected through the address
passed
; as argument (See product datasheet for addr value)
;****************************************************************************
flash_read_fuse:
  RCALL   WAIT_SPMEN  ;Wait for SPMEN flag cleared
  MOV     R31,R17
  MOV     R30,R16     ;move adress to z pointer (R31=ZH R30=ZL)
  OUT     RAMPZ, R18
  LDI     R20,$09     ;(1<<SPMEN) | (1<<BLBSET))
  OUT SPMCSR, R20; argument 2 decides function (r18)
  LPM                ;Store program memory
  MOV     R16, R0        ;Store return value (1byte->R16 register)
  RJMP    WAIT_SPMEN  ;Wait for SPMEN flag cleared
/*F**************************************************************************
* NAME: flash_fill_temp_buffer
*----------------------------------------------------------------------------
* PARAMS:
* data16 :  R16/R17: word to load in the temporary buffer.
* address:  R18/R19: address of the word.
* return:  none
*----------------------------------------------------------------------------
* PURPOSE:
* This function allows to load a word in the temporary flash buffer.
*----------------------------------------------------------------------------
* EXAMPLE:
* fill_temp_buffer(data16, address);
*----------------------------------------------------------------------------
* NOTE:
* the first paramater used the registers R16, R17
* The second parameter used the registers R18, R19
*****************************************************************************/
flash_fill_temp_buffer:
  MOV     R31,R19     ;move adress to z pointer (R31=ZH R30=ZL)
  MOV     R30,R18
  MOV     R0,R17      ;move data16 to reg 0 and 1
  MOV     R1,R16
  LDI     R20,(1<<SPMEN)
  OUT SPMCSR, R20; r18 decides function
  SPM                ; Store program memory
  RJMP   WAIT_SPMEN   ; Wait for SPMEN flag cleared
;*F**************************************************************************
; NAME: lock_wr_bits
;----------------------------------------------------------------------------
; PARAMS:   R16: value to write
;----------------------------------------------------------------------------
; PURPOSE:
;****************************************************************************
lock_wr_bits:
  RCALL   WAIT_SPMEN  ; Wait for SPMEN flag cleared
  MOV     R0,R16
  LDI     R18,((1<<BLBSET)|(1<<SPMEN))
  OUT SPMCSR, R18 ; r18 decides function
  SPM                 ; write lockbits
  RJMP   WAIT_SPMEN   ; Wait for SPMEN flag cleared
;*F**************************************************************************
; NAME: wait_spmen
;----------------------------------------------------------------------------
; PARAMS:    none
;----------------------------------------------------------------------------
; PURPOSE:   Performs an active wait on SPME flag
;****************************************************************************
WAIT_SPMEN:
  MOVR0, R18
  INR18, SPMCSR   ; get SPMCR into r18
  SBRC   R18,SPMEN
  RJMP   WAIT_SPMEN    ; Wait for SPMEN flag cleared
  MOVR18, R0
  RET
END
