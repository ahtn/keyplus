;------------------------------------------------------------------------------
; C8051F326.INC
;------------------------------------------------------------------------------
; Copyright 2005 Silicon Laboratories, Inc.
; http://www.silabs.com
;
; Program Description:
;
; Register/bit definitions for the C8051F326/7 family.
;
;
; FID:            326000003
; Target:         C8051F326, 'F327
; Tool chain:     Keil
; Command Line:   None
;
; Release 1.0
;    -Initial Revision (GP\PKC)
;    -13 DEC 2005
;

;------------------------------------------------------------------------------
; Byte Registers
;------------------------------------------------------------------------------

P0       DATA  080H                    ; Port 0
SP       DATA  081H                    ; Stack pointer
DPL      DATA  082H                    ; Data pointer - low byte
DPH      DATA  083H                    ; Data pointer - high byte
PCON     DATA  087H                    ; Power control
TCON     DATA  088H                    ; Timer control
TMOD     DATA  089H                    ; Timer mode
TL0      DATA  08AH                    ; Timer0 - low byte
TL1      DATA  08BH                    ; Timer1 - low byte
TH0      DATA  08CH                    ; Timer0 - high byte
TH1      DATA  08DH                    ; Timer1 - high byte
CKCON    DATA  08EH                    ; Clock control
PSCTL    DATA  08FH                    ; Program store r/w control
SBCON0   DATA  091H;                   ; Baud rate generator 0 control
SBRLL0   DATA  093H;                   ; Baud rate generator 0 low byte
SBRLH0   DATA  094H;                   ; Baud rate generator 0 high byte
USB0ADR  DATA  096H                    ; USB0 address port
USB0DAT  DATA  097H                    ; USB0 data port
SCON0    DATA  098H                    ; Serial port 0 control
SBUF0    DATA  099H                    ; Serial port 0 buffer
SMOD0    DATA  09AH                    ; Serial port 0 mode
P2       DATA  0A0H                    ; Port 2
P0MDOUT  DATA  0A4H                    ; Port 0 output mode
P2MDOUT  DATA  0A6H                    ; Port 2 output mode
P3MDOUT  DATA  0A7H                    ; Port 3 output mode
IE       DATA  0A8H                    ; Interrupt enable
CLKSEL   DATA  0A9H                    ; Clock source select
EMI0CN   DATA  0AAH                    ; External memory interface control
P3       DATA  0B0H                    ; Port 3
OSCICN   DATA  0B2H                    ; Internal oscillator control
OSCICL   DATA  0B3H                    ; Internal oscillator calibration
FLSCL    DATA  0B6H                    ; Flash scale
FLKEY    DATA  0B7H                    ; Flash lock & key
IP       DATA  0B8H                    ; Interrupt priority
CLKMUL   DATA  0B9H                    ; Clock multiplier control
REG0CN   DATA  0C9H                    ; Regulator control
PSW      DATA  0D0H                    ; Program status word
USB0XCN  DATA  0D7H                    ; USB0 transceiver control
ACC      DATA  0E0H                    ; Accumulator
GPIOCN   DATA  0E2H                    ; Global port I/0 control
OSCLCN   DATA  0E3H                    ; Low freq internal oscillator control
EIE1     DATA  0E6H                    ; External interrupt enable 1
EIE2     DATA  0E7H                    ; External interrupt enable 2
RSTSRC   DATA  0EFH                    ; Reset source
B        DATA  0F0H                    ; B register
EIP1     DATA  0F6H                    ; External interrupt priority 1
EIP2     DATA  0F7H                    ; External interrupt priority 2
VDM0CN   DATA  0FFH                    ; VDD monitor control

;------------------------------------------------------------------------------
; Bit Definitions
;------------------------------------------------------------------------------

; TCON 88H
TF1      BIT   TCON.7                  ; Timer1 overflow flag
TR1      BIT   TCON.6                  ; Timer1 on/off control
TF0      BIT   TCON.5                  ; Timer0 overflow flag
TR0      BIT   TCON.4                  ; Timer0 on/off control
IE1      BIT   TCON.3                  ; Ext. Interrupt 1 edge flag
IT1      BIT   TCON.2                  ; Ext. Interrupt 1 type
IE0      BIT   TCON.1                  ; Ext. Interrupt 0 edge flag
IT0      BIT   TCON.0                  ; Ext. Interrupt 0 type

; SCON0  0x98
OVR0     BIT   SCON0.7                 ; Receive FIFO Overrun flag
PERR0    BIT   SCON0.6                 ; Parity Error flag
                                       ; Bit 5 unused
REN0     BIT   SCON0.4                 ; Receive enable
TBX0     BIT   SCON0.3                 ; Transmit bit 8
RBX0     BIT   SCON0.2                 ; Receive bit 8
TI0      BIT   SCON0.1                 ; Transmit interrupt flag
RI0      BIT   SCON0.0                 ; Receive interrupt flag

; IE  0xA8
EA       BIT   IE.7                    ; Global interrupt enable
                                       ; Bit 6 unused
                                       ; Bit 5 unused
ES0      BIT   IE.4                    ; UART0 interrupt enable
ET1      BIT   IE.3                    ; Timer1 interrupt enable
EX1      BIT   IE.2                    ; External interrupt 1 enable
ET0      BIT   IE.1                    ; Timer0 interrupt enable
EX0      BIT   IE.0                    ; External interrupt 0 enable

; IP  0xB8
                                       ; Bit 7 unused
                                       ; Bit 6 unused
                                       ; Bit 5 unused
PS0      BIT   IP.4                    ; UART0 priority
PT1      BIT   IP.3                    ; Timer1 priority
PX1      BIT   IP.2                    ; External interrupt 1 priority
PT0      BIT   IP.1                    ; Timer0 priority
PX0      BIT   IP.0                    ; External interrupt 0 priority

; PSW 0xD0
CY       BIT   PSW.7                   ; Carry flag
AC       BIT   PSW.6                   ; Auxiliary carry flag
F0       BIT   PSW.5                   ; User flag 0
RS1      BIT   PSW.4                   ; Register bank select 1
RS0      BIT   PSW.3                   ; Register bank select 0
OV       BIT   PSW.2                   ; Overflow flag
F1       BIT   PSW.1                   ; User flag 1
P        BIT   PSW.0                   ; Accumulator parity flag

;------------------------------------------------------------------------------
; End Of File
;------------------------------------------------------------------------------
