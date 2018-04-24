$NOMOD51 NOLINES
$NOCOND
;------------------------------------------------------------------------------
;  This file is part of the BL51 / LX51 Banked Linker/Locater package
;  Copyright (c) 1988 - 2000 Keil Elektronik GmbH and Keil Software, Inc.
;  Version 2.08 (Code and Variable Banking for Classic 8051 Derivatives)
;
;------------------------------------------------------------------------------
$include (SI_C8051F960_Defs.inc) ; Include register definitions                 

;************************ Configuration Section *******************************
?B_NBANKS       EQU  NUMBANKS    ; Define max. Number of Banks                *
;                         ; The following values are allowed: 2, 4, 8, 16, 32 *
;                         ; the max. value for ?B_BANKS is 32                 *
;                                                                             *
?B_MODE         EQU  4    ; 0 for Bank-Switching via 8051 Port                *
;                         ; 1 for Bank-Switching via XDATA Port               *
;                         ; 4 for user-provided bank switch code              *
;                                                                             *
?B_RTX          EQU  0    ; 0 for applications without RTX-51 FULL            *
;                         ; 1 for applications using RTX-51 FULL              *
;                                                                             *
?B_VAR_BANKING  EQU  0    ; Enable Variable Banking in XDATA and CODE memory  *
;                         ; 0 Variable Banking is disabled                    *
;                         ; 1 XDATA and CODE banking with same address lines  *
;                         ; 2 XDATA uses a different banking port             *
; Note Variable Banking is only supported with the LX51 linker/locater        *
;                                                                             *
?B_RST_BANK     EQU  0FFh ; specifies the active code bank number after CPU   *
;                         ; Reset.  Used to reduce the entries in the         *
;                         ; INTERBANK CALL TABLE.  The value 0xFF disables    *
;                         ; this LX51 linker/locater optimization.            *
; Note interbank call table optimization is only possible with LX51.          *
;                                                                             *
;-----------------------------------------------------------------------------*
;                                                                             *
IF  ?B_MODE = 4;                                                              *
;-----------------------------------------------------------------------------*
; if ?BANK?MODE is 4 define the following switch macros                       *
; For bank switching via user-provided bank switch code you must define for   *
; each memory bank a own macro which contains the bank switch code.  The      *
; following example shows how to use the I/O lines P1.4 and P1.7 for bank     *
; switching.  Since you can select just 4 banks with two address lines, just  *
; four macros are defined.  The number of macros must conform with the number *
; ?B_NBANKS number, i.e. for an application with 16 memory banks you must     *
; define 16 macros.                                                           *
;                                                                             *
; IMPORTANT NOTES:                                                            *
; 1.  Eeach SWITCH macro must generate the same code size, otherwise the      *
;     BANKSWITCH code does not work correctly.                                *
; 2.  The bankswitch logic must be initialized before using it. Please add    *
;     the following two lines of code at the end of the STARTUP.A51 file:     *
;                :                                                            *
;      EXTRN CODE (?B_SWITCH0)
;               CALL    ?B_SWITCH0    ; init bank mechanism to code bank 0
;               LJMP    ?C_START      ; line already exits at the end of file *
;                :                                                            *
; 3.  If you are using the RTX-51 real-time operating system this banking     *
;     mode cannot be used.                                                    *
;                                                                             *
;                                                                             *
SWITCH0         MACRO                  ; Switch to Memory Bank #0             *
                MOV     PSBANK, #00h   ; Set PSBANK                           *
                ENDM                                                          *
;                                                                             *
SWITCH1         MACRO                  ; Switch to Memory Bank #1             *
                MOV     PSBANK, #11h   ; Set PSBANK                           *
                ENDM                                                          *
;                                                                             *
SWITCH2         MACRO                  ; Switch to Memory Bank #2             *
                MOV     PSBANK, #22h   ; Set PSBANK                           *
                ENDM                                                          *
;                                                                             *
SWITCH3         MACRO                  ; Switch to Memory Bank #3             *
                MOV     PSBANK, #33h   ; Set PSBANK                           *
                ENDM                                                          *
;                                                                             *
;-----------------------------------------------------------------------------*
ENDIF;                                                                        *
;                                                                             *
;******************************************************************************
;                                                                             *
; THEORY OF OPERATION                                                         *
; -------------------                                                         *
; The section below describes the code generated by BL51 or L251 and the      *
; operation of the L51_BANK.A51 module.  BL51/L251 generates for each         *
; function that is located in a code memory bank and called from the common   *
; area or a different code bank and entry into the INTRABANK CALL TABLE.  The *
; INTRABANK CALL TABLE is located in the SEGMENT ?BANK?SELECT and listed in   *
; the Linker MAP file. The entries in that TABLE have the following format:   *
;                                                                             *
;   ?FCT?1:  MOV  DPTR,#FCT     ; Load Address of target FCT                  *
;            JMP  ?B_BANKn      ; Switch to Bank and Jump to Target Code      *
;                                                                             *
; Instead of directly calling the function FCT, the Linker changes the entry  *
; to ?FCT?1.  This entry selects the bank where the function FCT is located   *
; and calls that function via the routines defined in this L51_BANK.A51 file. *
; The L51_BANK.A51 file contains two sets of functions for each bank:         *
;                                                                             *
; ?B_BANKn    is a routine which saves the entry of the ?B_SWITCHn function   *
;             for the current active bank on the STACK and switches to the    *
;             bank 'n'.  Then it jumps to the address specified by the DPTR   *
;             register.  It is allowed to modify the following registers in   *
;             the ?B_BANKn routine:  A, B, R0, DPTR, PSW                      *
;                                                                             *
; ?B_SWITCHn  is a function which selects the bank 'n'.  This function is     *
;             used at the end of a user function to return to the calling     *
;             code bank.  Only the following registers may be altered in the  *
;             ?B_SWITCHn function:  R0, DPTR                                  *
;                                                                             *
; The current active bank is stored in ?B_CURRENTBANK.  RTX-51 uses this      *
; variable to restore the code bank after a task switch.  To get correct      *
; results, ?B_CURRENTBANK must be set to the code bank before the hardware    *
; switch is done, or the code banking sequences must be interrupt protected.  *
;******************************************************************************

                NAME    ?BANK?SWITCHING

                PUBLIC  ?B_NBANKS, ?B_MODE, ?B_CURRENTBANK, ?B_MASK
                PUBLIC  ?B_FACTOR, ?B_RST_BANK

; generate Mask and Bank Number Information
IF      ?B_NBANKS <= 2
  MASK          EQU     00000001B
ELSEIF  ?B_NBANKS <= 4
  MASK          EQU     00000011B
ELSEIF  ?B_NBANKS <= 8
  MASK          EQU     00000111B
ELSEIF  ?B_NBANKS <= 16
  MASK          EQU     00001111B
ELSE
  MASK          EQU     00011111B
ENDIF     


IF  ?B_MODE = 4 ;**************************************************************

?B_FACTOR       EQU     0               ; Dummy Declarations
?B_FIRSTBIT     EQU     0
?B_MASK         EQU     MASK

?BANK?SELECT    SEGMENT CODE
?BANK?DATA      SEGMENT DATA
                RSEG    ?BANK?DATA
?B_CURRENTBANK: DS      1

BANK            MACRO   N
                PUBLIC  ?B_BANK&N
?B_BANK&N:
                PUSH    ?B_CURRENTBANK
                MOV     A,#HIGH ?BANK?SWITCH
                PUSH    ACC
                PUSH    DPL
                PUSH    DPH
                ENDM

SWITCH          MACRO   N
                PUBLIC  ?B_SWITCH&N
?B_SWITCH&N:
                MOV     ?B_CURRENTBANK,#LOW ?B_SWITCH&N
                SWITCH&N
                RET
                ENDM


?BANK?SWITCH    SEGMENT CODE PAGE

                RSEG    ?BANK?SWITCH
B_SWITCH_START  EQU     $
; Generate ?B_SWITCHn functions
CNT             SET     0

                REPT    ?B_NBANKS
                BANK    %CNT
                SWITCH  %CNT
CNT             SET     CNT+1
                ENDM

B_SWITCH_SIZE   EQU     $-B_SWITCH_START

IF (B_SWITCH_SIZE > 256)
__ERROR__ "BANK SWITCH CODE BIGGER THAN 256 BYTES (reduce number of banks or macro code)"
ENDIF



COMMON_XDATA    MACRO     ; Switch back to common XDATA bank
                SWITCH1                        ; Switch to XDATA Bank 1
                ENDM


ENDIF  ; close block IF ?B_MODE = 4 *******************************************

                RSEG    ?BANK?SELECT

;************************  SWITCHBANK FUNCTION  *******************************
;                                                                             *
; SWITCHBANK allows use of bank-switching for C programs                      *
;                                                                             *
; prototype:   extern switchbank (unsigned char bank_number);                 *
;                                                                             *
;******************************************************************************
                PUBLIC  _SWITCHBANK

_SWITCHBANK:    MOV     A,R7

IF  ?B_MODE = 4 ;**************************************************************

S_ENTRY         MACRO   N
                DB      LOW ?B_SWITCH&N
                ENDM

_SWITCHBANK_A:
                ADD     A,#switch_tab+3-$
                MOVC    A,@A+PC
                MOV     DPTR,#?BANK?SWITCH
                JMP     @A+DPTR

switch_tab:     
CNT             SET     0

                REPT    ?B_NBANKS
                S_ENTRY %CNT
CNT             SET     CNT+1
                ENDM
ENDIF  ; close block IF ?B_MODE = 4 *******************************************


                END
