;------------------------------------------------------------------------------
; C8051F520A.inc
;------------------------------------------------------------------------------
; Copyright 2006 Silicon Laboratories, Inc.
; http:;www.silabs.com
;
; Program Description:
;
; Register/bit definitions for the C8051F52xA/'F53xA family.
;
; Target:         C8051F52xA, 'F53xA
; Tool chain:     Keil
; Command Line:   None
;
; Release 1.0 - 11 MAR 2010 (GP)
;    -Changed // to ; to make compatible with Raisonance
;
; Release 1.0
;    -All changes by TP
;    -29 JAN 2008
;    -Initial Release
;

;------------------------------------------------------------------------------
; Byte Registers
;------------------------------------------------------------------------------

P0          DATA  080H                 ; Port 0 Latch
SP          DATA  081H                 ; Stack Pointer
DPL         DATA  082H                 ; Data Pointer - Low byte
DPH         DATA  083H                 ; Data Pointer - High byte
PCON        DATA  087H                 ; Power Control
TCON        DATA  088H                 ; Timer Control
TMOD        DATA  089H                 ; Timer Mode
TL0         DATA  08AH                 ; Timer 0 - Low byte
TL1         DATA  08BH                 ; Timer 1 - Low byte
TH0         DATA  08CH                 ; Timer 0 - High byte
TH1         DATA  08DH                 ; Timer 1 - High byte
CKCON       DATA  08EH                 ; Clock Control
PSCTL       DATA  08FH                 ; Program Store R/W Control
P1          DATA  090H                 ; Port 1 Latch
LINADDR     DATA  092H                 ; LIN Indirect Access Address
LINDATA     DATA  093H                 ; LIN Indirect Access Data
LINCF       DATA  095H                 ; LIN Configuration
SCON0       DATA  098H                 ; UART0 Control
SBUF0       DATA  099H                 ; UART0 Buffer
CPT0CN      DATA  09BH                 ; Comparator 0 Control
CPT0MD      DATA  09DH                 ; Comparator 0 Mode
CPT0MX      DATA  09FH                 ; Comparator 0 Mux
SPI0CFG     DATA  0A1H                 ; SPI0 Configuration
SPI0CKR     DATA  0A2H                 ; SPI0 Clock Rate
SPI0DAT     DATA  0A3H                 ; SPI0 Data
P0MDOUT     DATA  0A4H                 ; Port 0 Output Mode Configuration
P1MDOUT     DATA  0A5H                 ; Port 1 Output Mode Configuration
IE          DATA  0A8H                 ; Interrupt Enable
CLKSEL      DATA  0A9H                 ; Clock Select
OSCIFIN     DATA  0B0H                 ; Internal Fine Oscillator Calibration
OSCXCN      DATA  0B1H                 ; External Oscillator Control
OSCICN      DATA  0B2H                 ; Internal Oscillator Control
OSCICL      DATA  0B3H                 ; Internal Oscillator Calibration
FLKEY       DATA  0B7H                 ; Flash Lock & Key
IP          DATA  0B8H                 ; Interrupt Priority
ADC0TK      DATA  0BAH                 ; ADC0 Tracking
ADC0MX      DATA  0BBH                 ; ADC0 Mux Channel Selection
ADC0CF      DATA  0BCH                 ; ADC0 CONFIGURATION
ADC0L       DATA  0BDH                 ; ADC0 LSB Result
ADC0H       DATA  0BEH                 ; ADC0 Data
P1MASK      DATA  0BFH                 ; Port 1 Mask
ADC0GTL     DATA  0C3H                 ; ADC0 Greater-Than Compare Low
ADC0GTH     DATA  0C4H                 ; ADC0 Greater-Than Compare High
ADC0LTL     DATA  0C5H                 ; ADC0 Less-Than Compare Word Low
ADC0LTH     DATA  0C6H                 ; ADC0 Less-Than Compare Word High
P0MASK      DATA  0C7H                 ; Port 1 Mask
TMR2CN      DATA  0C8H                 ; Timer 2 Control
REG0CN      DATA  0C9H                 ; Regulator Control
TMR2RLL     DATA  0CAH                 ; Timer 2 Reload Low
TMR2RLH     DATA  0CBH                 ; Timer 2 Reload High
TMR2L       DATA  0CCH                 ; Timer 2 Low Byte
TMR2H       DATA  0CDH                 ; Timer 2 High Byte
P1MAT       DATA  0CFH                 ; Port 1 Match
PSW         DATA  0D0H                 ; Program Status Word
REF0CN      DATA  0D1H                 ; Voltage Reference 0 Control
P0SKIP      DATA  0D4H                 ; Port 0 Skip
P1SKIP      DATA  0D5H                 ; Port 1 Skip
P0MAT       DATA  0D7H                 ; Port 0 Match
PCA0CN      DATA  0D8H                 ; PCA0 Control
PCA0MD      DATA  0D9H                 ; PCA0 Mode
PCA0CPM0    DATA  0DAH                 ; PCA0 Module 0 Mode
PCA0CPM1    DATA  0DBH                 ; PCA0 Module 1 Mode
PCA0CPM2    DATA  0DCH                 ; PCA0 Module 2 Mode
ACC         DATA  0E0H                 ; Accumulator
XBR0        DATA  0E1H                 ; Digital Crossbar Configuration 0
XBR1        DATA  0E2H                 ; Digital Crossbar Configuration 1
IT01CF      DATA  0E4H                 ; INT0/INT1 Configuration
EIE1        DATA  0E6H                 ; Extended Interrupt Enable 1
ADC0CN      DATA  0E8H                 ; ADC 0 Control
PCA0CPL1    DATA  0E9H                 ; PCA0 Module 1 Capture/Compare Low Byte
PCA0CPH1    DATA  0EAH                 ; PCA0 Module 1 Capture/Compare High Byte
PCA0CPL2    DATA  0EBH                 ; PCA0 Module 2 Capture/Compare Low Byte
PCA0CPH2    DATA  0ECH                 ; PCA0 Module 2 Capture/Compare High Byte
RSTSRC      DATA  0EFH                 ; Reset Source Configuration/Status
B           DATA  0F0H                 ; B Register
P0MDIN      DATA  0F1H                 ; Port 0 Input Mode
P1MDIN      DATA  0F2H                 ; Port 1 Input Mode
EIP1        DATA  0F6H                 ; Extended Interrupt Priority 1
SPI0CN      DATA  0F8H                 ; SPI0 Control
PCA0L       DATA  0F9H                 ; PCA0 Counter Low Byte
PCA0H       DATA  0FAH                 ; PCA0 Counter High Byte
PCA0CPL0    DATA  0FBH                 ; PCA Module 0 Capture/Compare Low Byte
PCA0CPH0    DATA  0FCH                 ; PCA Module 0 Capture/Compare High Byte
VDDMON      DATA  0FFH                 ; VDD Monitor

;------------------------------------------------------------------------------
; Bit Definitions
;------------------------------------------------------------------------------

; TCON  0x88
TF1         BIT   TCON.7               ; Timer 1 Overflow Flag
TR1         BIT   TCON.6               ; Timer 1 On/Off Control
TF0         BIT   TCON.5               ; Timer 0 Overflow Flag
TR0         BIT   TCON.4               ; Timer 0 On/Off Control
IE1         BIT   TCON.3               ; External Interrupt 1 Edge Flag
IT1         BIT   TCON.2               ; External Interrupt 1 Type
IE0         BIT   TCON.1               ; External Interrupt 0 Edge Flag
IT0         BIT   TCON.0               ; External Interrupt 0 Type

; SCON0  0x98
S0MODE      BIT   SCON0.7              ; Serial Mode Control Bit 0
                                       ; Bit6 UNUSED
MCE0        BIT   SCON0.5              ; Multiprocessor Communication Enable
REN0        BIT   SCON0.4              ; Receive Enable
TB80        BIT   SCON0.3              ; Transmit Bit 8
RB80        BIT   SCON0.2              ; Receive Bit 8
TI0         BIT   SCON0.1              ; Transmit Interrupt Flag
RI0         BIT   SCON0.0              ; Receive Interrupt Flag

; IE  0xA8
EA          BIT   IE.7                 ; Global Interrupt Enable
ESPI0       BIT   IE.6                 ; SPI0 Interrupt Enable
ET2         BIT   IE.5                 ; Timer 2 Interrupt Enable
ES0         BIT   IE.4                 ; UART0 Interrupt Enable
ET1         BIT   IE.3                 ; Timer 1 Interrupt Enable
EX1         BIT   IE.2                 ; External Interrupt 1 Enable
ET0         BIT   IE.1                 ; Timer 0 Interrupt Enable
EX0         BIT   IE.0                 ; External Interrupt 0 Enable

; IP  0xB8
                                       ; Bit7 UNUSED
PSPI0       BIT   IP.6                 ; SPI0 Interrupt Priority
PT2         BIT   IP.5                 ; Timer 2 Priority
PS0         BIT   IP.4                 ; UART0 Priority
PT1         BIT   IP.3                 ; Timer 1 Priority
PX1         BIT   IP.2                 ; External Interrupt 1 Priority
PT0         BIT   IP.1                 ; Timer 0 Priority
PX0         BIT   IP.0                 ; External Interrupt 0 Priority

; TMR2CN 0xC8
TF2H        BIT   TMR2CN.7             ; Timer 2 High-Byte Overflow Flag
TF2L        BIT   TMR2CN.6             ; Timer 2 Low-Byte  Overflow Flag
TF2LEN      BIT   TMR2CN.5             ; Timer 2 Low-Byte Flag Enable
TF2CEN      BIT   TMR2CN.4             ; Timer 2 Capture Enable
T2SPLIT     BIT   TMR2CN.3             ; Timer 2 Split-Mode Enable
TR2         BIT   TMR2CN.2             ; Timer 2 On/Off Control
T2RCLK      BIT   TMR2CN.1             ; Timer 2 Xclk/Rclk Select
T2XCLK      BIT   TMR2CN.0             ; Timer 2 Clk/8 Clock Source

; PSW 0xD0
CY          BIT   PSW.7                ; Carry Flag
AC          BIT   PSW.6                ; Auxiliary Carry Flag
F0          BIT   PSW.5                ; User Flag 0
RS1         BIT   PSW.4                ; Register Bank Select 1
RS0         BIT   PSW.3                ; Register Bank Select 0
OV          BIT   PSW.2                ; Overflow Flag
F1          BIT   PSW.1                ; User Flag 1
P           BIT   PSW.0                ; Accumulator Parity Flag

; PCA0CN 0xD8
CF          BIT   PCA0CN.7             ; PCA0 Counter Overflow Flag
CR          BIT   PCA0CN.6             ; PCA0 Counter Run Control Bit
                                       ; Bit5 UNUSED
                                       ; Bit4 UNUSED
                                       ; Bit3 UNUSED
CCF2        BIT   PCA0CN.2             ; PCA0 Module 2 Interrupt Flag
CCF1        BIT   PCA0CN.1             ; PCA0 Module 1 Interrupt Flag
CCF0        BIT   PCA0CN.0             ; PCA0 Module 0 Interrupt Flag

; ADC0CN 0xE8
AD0EN       BIT   ADC0CN.7             ; ADC0 Enable
BURSTEN     BIT   ADC0CN.6             ; ADC0 Burst Enable
AD0INT      BIT   ADC0CN.5             ; ADC0 Conversion Complete Interrupt Flag
AD0BUSY     BIT   ADC0CN.4             ; ADC0 Busy Flag
AD0WINT     BIT   ADC0CN.3             ; ADC0 Window Compare Interrupt Flag
AD0LJST     BIT   ADC0CN.2             ; ADC0 Left Justified
AD0CM1      BIT   ADC0CN.1             ; ADC0 Start Of Conversion Mode Bit 1
AD0CM0      BIT   ADC0CN.0             ; ADC0 Start Of Conversion Mode Bit 0

; SPI0CN 0xF8
SPIF        BIT   SPI0CN.7             ; SPI0 Interrupt Flag
WCOL        BIT   SPI0CN.6             ; SPI0 Write Collision Flag
MODF        BIT   SPI0CN.5             ; SPI0 Mode Fault Flag
RXOVRN      BIT   SPI0CN.4             ; SPI0 Rx Overrun Flag
NSSMD1      BIT   SPI0CN.3             ; SPI0 NSS Mode Bit 1
NSSMD0      BIT   SPI0CN.2             ; SPI0 NSS Mode Bit 0
TXBMT       BIT   SPI0CN.1             ; SPI0 Transmit Buffer Empty Flag
SPIEN       BIT   SPI0CN.0             ; SPI0 Enable

;------------------------------------------------------------------------------
; End Of File
;------------------------------------------------------------------------------