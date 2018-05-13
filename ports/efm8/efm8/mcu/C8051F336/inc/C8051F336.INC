;------------------------------------------------------------------------------
; C8051F336_defs.inc
;------------------------------------------------------------------------------
; Copyright 2007 Silicon Laboratories, Inc.
; http://www.silabs.com
;
; Program Description:
;
; Register/bit definitions for the C8051F336 family.
;
;
; Target:         C8051F336, 'F337, 'F338, 'F339
; Tool chain:     Generic
; Command Line:   None
;
; Release 0.1
;    -All changes by PKC
;    -21 MAY 2007
;    -Initial revision (beta)
;

;------------------------------------------------------------------------------
; Byte Registers
;------------------------------------------------------------------------------

P0          DATA 080H                  ; Port 0 Latch
SP          DATA 081H                  ; Stack Pointer
DPL         DATA 082H                  ; Data Pointer Low
DPH         DATA 083H                  ; Data Pointer High
PCON        DATA 087H                  ; Power Control
TCON        DATA 088H                  ; Timer/Counter Control
TMOD        DATA 089H                  ; Timer/Counter Mode
TL0         DATA 08AH                  ; Timer/Counter 0 Low
TL1         DATA 08BH                  ; Timer/Counter 1 Low
TH0         DATA 08CH                  ; Timer/Counter 0 High
TH1         DATA 08DH                  ; Timer/Counter 1 High
CKCON       DATA 08EH                  ; Clock Control
PSCTL       DATA 08FH                  ; Program Store R/W Control
P1          DATA 090H                  ; Port 1 Latch
TMR3CN      DATA 091H                  ; Timer/Counter 3 Control
TMR3RLL     DATA 092H                  ; Timer/Counter 3 Reload Low
TMR3RLH     DATA 093H                  ; Timer/Counter 3 Reload High
TMR3L       DATA 094H                  ; Timer/Counter 3 Low
TMR3H       DATA 095H                  ; Timer/Counter 3 High
IDA0L       DATA 096H                  ; Current Mode Dac0 Low
IDA0H       DATA 097H                  ; Current Mode Dac0 High
SCON0       DATA 098H                  ; UART0 Control
SBUF0       DATA 099H                  ; UART0 Data Buffer
CPT0CN      DATA 09BH                  ; Comparator0 Control
CPT0MD      DATA 09DH                  ; Comparator0 Mode Selection
CPT0MX      DATA 09FH                  ; Comparator0 Mux Selection
P2          DATA 0A0H                  ; Port 2 Latch
SPI0CFG     DATA 0A1H                  ; SPI0 Configuration
SPI0CKR     DATA 0A2H                  ; SPI0 Clock Rate Control
SPI0DAT     DATA 0A3H                  ; SPI0 Data
P0MDOUT     DATA 0A4H                  ; Port 0 Output Mode Configuration
P1MDOUT     DATA 0A5H                  ; Port 1 Output Mode Configuration
P2MDOUT     DATA 0A6H                  ; Port 2 Output Mode Configuration
IE          DATA 0A8H                  ; Interrupt Enable
CLKSEL      DATA 0A9H                  ; Clock Select
EMI0CN      DATA 0AAH                  ; External Memory Interface Control
OSCXCN      DATA 0B1H                  ; External Oscillator Control
OSCICN      DATA 0B2H                  ; Internal Oscillator Control
OSCICL      DATA 0B3H                  ; Internal Oscillator Calibration
FLSCL       DATA 0B6H                  ; Flash Scale
FLKEY       DATA 0B7H                  ; Flash Lock And Key
IP          DATA 0B8H                  ; Interrupt Priority
IDA0CN      DATA 0B9H                  ; Current Mode DAC0 Control
AMX0N       DATA 0BAH                  ; AMUX0 Negative Channel Select
AMX0P       DATA 0BBH                  ; AMUX0 Positive Channel Select
ADC0CF      DATA 0BCH                  ; ADC0 Configuration
ADC0L       DATA 0BDH                  ; ADC0 Low
ADC0H       DATA 0BEH                  ; ADC0 High
SMB0CN      DATA 0C0H                  ; SMBus0 Control
SMB0CF      DATA 0C1H                  ; SMBus0 Configuration
SMB0DAT     DATA 0C2H                  ; SMBus0 Data
ADC0GTL     DATA 0C3H                  ; ADC0 Greater-Than Compare Low
ADC0GTH     DATA 0C4H                  ; ADC0 Greater-Than Compare High
ADC0LTL     DATA 0C5H                  ; ADC0 Less-Than Compare Word Low
ADC0LTH     DATA 0C6H                  ; ADC0 Less-Than Compare Word High
TMR2CN      DATA 0C8H                  ; Timer/Counter 2 Control
TMR2RLL     DATA 0CAH                  ; Timer/Counter 2 Reload Low
TMR2RLH     DATA 0CBH                  ; Timer/Counter 2 Reload High
TMR2L       DATA 0CCH                  ; Timer/Counter 2 Low
TMR2H       DATA 0CDH                  ; Timer/Counter 2 High
PSW         DATA 0D0H                  ; Program Status Word
REF0CN      DATA 0D1H                  ; Voltage Reference Control
P0SKIP      DATA 0D4H                  ; Port 0 Skip
P1SKIP      DATA 0D5H                  ; Port 1 Skip
P2SKIP      DATA 0D6H                  ; Port 2 Skip *NEW*
SMB0ADR     DATA 0D7H                  ; SMBus0 Address *NEW*
PCA0CN      DATA 0D8H                  ; PCA0 Control
PCA0MD      DATA 0D9H                  ; PCA0 Mode
PCA0CPM0    DATA 0DAH                  ; PCA0 Module 0 Mode Register
PCA0CPM1    DATA 0DBH                  ; PCA0 Module 1 Mode Register
PCA0CPM2    DATA 0DCH                  ; PCA0 Module 2 Mode Register
ACC         DATA 0E0H                  ; Accumulator
XBR0        DATA 0E1H                  ; Port I/O Crossbar Control 0
XBR1        DATA 0E2H                  ; Port I/O Crossbar Control 1
OSCLCN      DATA 0E3H                  ; Low-Frequency Oscillator Control
IT01CF      DATA 0E4H                  ; INT0/INT1 Configuration
EIE1        DATA 0E6H                  ; Extended Interrupt Enable 1
SMB0ADM     DATA 0E7H                  ; SMBus0 Address Match *NEW*
ADC0CN      DATA 0E8H                  ; ADC0 Control
PCA0CPL1    DATA 0E9H                  ; PCA0 Capture 1 Low
PCA0CPH1    DATA 0EAH                  ; PCA0 Capture 1 High
PCA0CPL2    DATA 0EBH                  ; PCA0 Capture 2 Low
PCA0CPH2    DATA 0ECH                  ; PCA0 Capture 2 High
P1MAT       DATA 0EDH                  ; Port 1 Match Register *NEW*
P1MASK      DATA 0EEH                  ; Port 1 Mask Register *NEW*
RSTSRC      DATA 0EFH                  ; Reset Source Configuration/Status
B           DATA 0F0H                  ; B Register
P0MDIN      DATA 0F1H                  ; Port 0 Input Mode Configuration
P1MDIN      DATA 0F2H                  ; Port 1 Input Mode Configuration
P2MDIN      DATA 0F3H                  ; Port 2 Input Mode Configuration *NEW*
EIP1        DATA 0F6H                  ; Extended Interrupt Priority 1
PCA0PWM     DATA 0F7H                  ; PCA0 PWM Configuration Register *NEW*
SPI0CN      DATA 0F8H                  ; SPI0 Control
PCA0L       DATA 0F9H                  ; PCA0 Counter Low
PCA0H       DATA 0FAH                  ; PCA0 Counter High
PCA0CPL0    DATA 0FBH                  ; PCA0 Capture 0 Low
PCA0CPH0    DATA 0FCH                  ; PCA0 Capture 0 High
P0MAT       DATA 0FDH                  ; Port 0 Match Register *NEW*
P0MASK      DATA 0FEH                  ; Port 1 Mask Register *NEW*
VDM0CN      DATA 0FFH                  ; VDD Monitor Control

;------------------------------------------------------------------------------
; Bit Definitions
;------------------------------------------------------------------------------

; TCON 088H
TF1         BIT 08FH                   ; Timer 1 Overflow Flag
TR1         BIT 08EH                   ; Timer 1 On/Off Control
TF0         BIT 08DH                   ; Timer 0 Overflow Flag
TR0         BIT 08CH                   ; Timer 0 On/Off Control
IE1         BIT 08BH                   ; Ext. Interrupt 1 Edge Flag
IT1         BIT 08AH                   ; Ext. Interrupt 1 Type
IE0         BIT 089H                   ; Ext. Interrupt 0 Edge Flag
IT0         BIT 088H                   ; Ext. Interrupt 0 Type

; SCON0 098H
S0MODE      BIT 09FH                   ; UART0 Mode
                                       ; Bit6 UNUSED
MCE0        BIT 09DH                   ; UART0 MCE
REN0        BIT 09CH                   ; UART0 RX Enable
TB80        BIT 09BH                   ; UART0 TX Bit 8
RB80        BIT 09AH                   ; UART0 RX Bit 8
TI0         BIT 099H                   ; UART0 TX Interrupt Flag
RI0         BIT 098H                   ; UART0 RX Interrupt Flag

; IE 0A8H
EA          BIT 0AFH                   ; Global Interrupt Enable
ESPI0       BIT 0AEH                   ; SPI0 Interrupt Enable
ET2         BIT 0ADH                   ; Timer 2 Interrupt Enable
ES0         BIT 0ACH                   ; UART0 Interrupt Enable
ET1         BIT 0ABH                   ; Timer 1 Interrupt Enable
EX1         BIT 0AAH                   ; External Interrupt 1 Enable
ET0         BIT 0A9H                   ; Timer 0 Interrupt Enable
EX0         BIT 0A8H                   ; External Interrupt 0 Enable

; IP 0B8H
                                       ; Bit7 UNUSED
PSPI0       BIT 0BEH                   ; SPI0 Priority
PT2         BIT 0BDH                   ; Timer 2 Priority
PS0         BIT 0BCH                   ; UART0 Priority
PT1         BIT 0BBH                   ; Timer 1 Priority
PX1         BIT 0BAH                   ; External Interrupt 1 Priority
PT0         BIT 0B9H                   ; Timer 0 Priority
PX0         BIT 0B8H                   ; External Interrupt 0 Priority

; SMB0CN 0C0H
MASTER      BIT 0C7H                   ; SMBus0 Master/Slave
TXMODE      BIT 0C6H                   ; SMBus0 Transmit Mode
STA         BIT 0C5H                   ; SMBus0 Start Flag
STO         BIT 0C4H                   ; SMBus0 Stop Flag
ACKRQ       BIT 0C3H                   ; SMBus0 Acknowledge Request
ARBLOST     BIT 0C2H                   ; SMBus0 Arbitration Lost
ACK         BIT 0C1H                   ; SMBus0 Acknowledge Flag
SI          BIT 0C0H                   ; SMBus0 Interrupt Pending Flag

; TMR2CN 0C8H
TF2H        BIT 0CFH                   ; Timer 2 High Byte Overflow Flag
TF2L        BIT 0CEH                   ; Timer 2 Low Byte Overflow Flag
TF2LEN      BIT 0CDH                   ; Timer 2 Low Byte Interrupt Enable
TF2CEN      BIT 0CCH                   ; Timer 2 Lfo Capture Enable
T2SPLIT     BIT 0CBH                   ; Timer 2 Split Mode Enable
TR2         BIT 0CAH                   ; Timer 2 On/Off Control
                                       ; Bit6 UNUSED
T2XCLK      BIT 0C8H                   ; Timer 2 External Clock Select

; PSW 0D0H
CY          BIT 0D7H                   ; Carry Flag
AC          BIT 0D6H                   ; Auxiliary Carry Flag
F0          BIT 0D5H                   ; User Flag 0
RS1         BIT 0D4H                   ; Register Bank Select 1
RS0         BIT 0D3H                   ; Register Bank Select 0
OV          BIT 0D2H                   ; Overflow Flag
F1          BIT 0D1H                   ; User Flag 1
P           BIT 0D0H                   ; Accumulator Parity Flag

; PCA0CN 0D8H
CF          BIT 0DFH                   ; PCA0 Counter Overflow Flag
CR          BIT 0DEH                   ; PCA0 Counter Run Control Bit
                                       ; Bit5 UNUSED
                                       ; Bit4 UNUSED
                                       ; Bit3 UNUSED
CCF2        BIT 0DAH                   ; PCA0 Module 2 Interrupt Flag
CCF1        BIT 0D9H                   ; PCA0 Module 1 Interrupt Flag
CCF0        BIT 0D8H                   ; PCA0 Module 0 Interrupt Flag

; ADC0CN 0E8H
AD0EN       BIT 0EFH                   ; ADC0 Enable
AD0TM       BIT 0EEH                   ; ADC0 Track Mode
AD0INT      BIT 0EDH                   ; ADC0 EOC Interrupt Flag
AD0BUSY     BIT 0ECH                   ; ADC0 Busy Flag
AD0WINT     BIT 0EBH                   ; ADC0 Window Interrupt Flag
AD0CM2      BIT 0EAH                   ; ADC0 Convert Start Mode Bit 2
AD0CM1      BIT 0E9H                   ; ADC0 Convert Start Mode Bit 1
AD0CM0      BIT 0E8H                   ; ADC0 Convert Start Mode Bit 0

; SPI0CN 0F8H
SPIF        BIT 0FFH                   ; SPI0 Interrupt Flag
WCOL        BIT 0FEH                   ; SPI0 Write Collision Flag
MODF        BIT 0FDH                   ; SPI0 Mode Fault Flag
RXOVRN      BIT 0FCH                   ; SPI0 RX Overrun Flag
NSSMD1      BIT 0FBH                   ; SPI0 Slave Select Mode 1
NSSMD0      BIT 0FAH                   ; SPI0 Slave Select Mode 0
TXBMT       BIT 0F9H                   ; SPI0 TX Buffer Empty Flag
SPIEN       BIT 0F8H                   ; SPI0 SPI0 Enable

;------------------------------------------------------------------------------
; End Of File
;------------------------------------------------------------------------------