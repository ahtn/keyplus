;------------------------------------------------------------------------------
; C8051F340.INC
;------------------------------------------------------------------------------
; Copyright 2009 Silicon Laboratories, Inc.
; http://www.silabs.com
;
; Program Description:
;
; Register/bit definitions for the C8051F34x family.
;
;
; FID:            34X000003
; Target:         C8051F340, 'F341, 'F342, 'F343, 'F344, 'F345, 'F346, 'F347
;                 'F348, 'F349, 'F34A, 'F34B, 'F34C, 'F34D
; Tool chain:     Keil
; Command Line:   None
;
; Release 1.1
;    -Added 'F348/9/A/B/C/D devices (BD)
;    -21 SEP 2009
; Release 1.0
;    -Initial Revision (GP\PKC)
;    -13 DEC 2005
;

;------------------------------------------------------------------------------
; Byte Registers
;------------------------------------------------------------------------------

P0        DATA  080H                   ; Port 0 Latch
SP        DATA  081H                   ; Stack Pointer
DPL       DATA  082H                   ; Data Pointer Low
DPH       DATA  083H                   ; Data Pointer High
EMI0TC    DATA  084H                   ; External Memory Interface Timing
EMI0CF    DATA  085H                   ; External Memory Interface Config
OSCLCN    DATA  086H                   ; Internal Low-Freq Oscillator Control
PCON      DATA  087H                   ; Power Control
TCON      DATA  088H                   ; Timer/Counter Control
TMOD      DATA  089H                   ; Timer/Counter Mode
TL0       DATA  08AH                   ; Timer/Counter 0 Low
TL1       DATA  08BH                   ; Timer/Counter 1 Low
TH0       DATA  08CH                   ; Timer/Counter 0 High
TH1       DATA  08DH                   ; Timer/Counter 1 High
CKCON     DATA  08EH                   ; Clock Control
PSCTL     DATA  08FH                   ; Program Store R/W Control
P1        DATA  090H                   ; Port 1 Latch
TMR3CN    DATA  091H                   ; Timer/Counter 3Control
TMR3RLL   DATA  092H                   ; Timer/Counter 3 Reload Low
TMR3RLH   DATA  093H                   ; Timer/Counter 3 Reload High
TMR3L     DATA  094H                   ; Timer/Counter 3Low
TMR3H     DATA  095H                   ; Timer/Counter 3 High
USB0ADR   DATA  096H                   ; USB0 Indirect Address Register
USB0DAT   DATA  097H                   ; USB0 Data Register
SCON0     DATA  098H                   ; UART0 Control
SBUF0     DATA  099H                   ; UART0 Data Buffer
CPT1CN    DATA  09AH                   ; Comparator1 Control
CPT0CN    DATA  09BH                   ; Comparator0 Control
CPT1MD    DATA  09CH                   ; Comparator1 Mode Selection
CPT0MD    DATA  09DH                   ; Comparator0 Mode Selection
CPT1MX    DATA  09EH                   ; Comparator1 MUX Selection
CPT0MX    DATA  09FH                   ; Comparator0 MUX Selection
P2        DATA  0A0H                   ; Port 2 Latch
SPI0CFG   DATA  0A1H                   ; SPI Configuration
SPI0CKR   DATA  0A2H                   ; SPI Clock Rate Control
SPI0DAT   DATA  0A3H                   ; SPI Data
P0MDOUT   DATA  0A4H                   ; Port 0 Output Mode Configuration
P1MDOUT   DATA  0A5H                   ; Port 1 Output Mode Configuration
P2MDOUT   DATA  0A6H                   ; Port 2 Output Mode Configuration
P3MDOUT   DATA  0A7H                   ; Port 3 Output Mode Configuration
IE        DATA  0A8H                   ; Interrupt Enable
CLKSEL    DATA  0A9H                   ; Clock Select
EMI0CN    DATA  0AAH                   ; External Memory Interface Control
SBCON1    DATA  0ACH                   ; UART1 Baud Rate Generator Control
P4MDOUT   DATA  0AEH                   ; Port 4 Output Mode Configuration
PFE0CN    DATA  0AFH                   ; Prefetch Engine Control
P3        DATA  0B0H                   ; Port 3 Latch
OSCXCN    DATA  0B1H                   ; External Oscillator Control
OSCICN    DATA  0B2H                   ; Internal Oscillator Control
OSCICL    DATA  0B3H                   ; Internal Oscillator Calibration
SBRLL1    DATA  0B4H                   ; UART1 Baud Rate Generator Low
SBRLH1    DATA  0B5H                   ; UART1 Baud Rate Generator High
FLSCL     DATA  0B6H                   ; Flash Scale
FLKEY     DATA  0B7H                   ; Flash Lock and Key
IP        DATA  0B8H                   ; Interrupt Priority
CLKMUL    DATA  0B9H                   ; Clock Multiplier
AMX0N     DATA  0BAH                   ; AMUX0 Negative Channel Select
AMX0P     DATA  0BBH                   ; AMUX0 Positive Channel Select
ADC0CF    DATA  0BCH                   ; ADC0 Configuration
ADC0L     DATA  0BDH                   ; ADC0 Low
ADC0H     DATA  0BEH                   ; ADC0 High
SMB0CN    DATA  0C0H                   ; SMBus Control
SMB0CF    DATA  0C1H                   ; SMBus Configuration
SMB0DAT   DATA  0C2H                   ; SMBus Data
ADC0GTL   DATA  0C3H                   ; ADC0 Greater-Than Compare Low
ADC0GTH   DATA  0C4H                   ; ADC0 Greater-Than Compare High
ADC0LTL   DATA  0C5H                   ; ADC0 Less-Than Compare Word Low
ADC0LTH   DATA  0C6H                   ; ADC0 Less-Than Compare Word High
P4        DATA  0C7H                   ; Port 4 Latch
TMR2CN    DATA  0C8H                   ; Timer/Counter 2 Control
REG0CN    DATA  0C9H                   ; Voltage Regulator Control
TMR2RLL   DATA  0CAH                   ; Timer/Counter 2 Reload Low
TMR2RLH   DATA  0CBH                   ; Timer/Counter 2 Reload High
TMR2L     DATA  0CCH                   ; Timer/Counter 2 Low
TMR2H     DATA  0CDH                   ; Timer/Counter 2 High
PSW       DATA  0D0H                   ; Program Status Word
REF0CN    DATA  0D1H                   ; Voltage Reference Control
SCON1     DATA  0D2H                   ; UART1 Control
SBUF1     DATA  0D3H                   ; UART1 Data Buffer
P0SKIP    DATA  0D4H                   ; Port 0 Skip
P1SKIP    DATA  0D5H                   ; Port 1 Skip
P2SKIP    DATA  0D6H                   ; Port 2 Skip
USB0XCN   DATA  0D7H                   ; USB0 Transceiver Control
PCA0CN    DATA  0D8H                   ; PCA Control
PCA0MD    DATA  0D9H                   ; PCA Mode
PCA0CPM0  DATA  0DAH                   ; PCA Module 0 Mode Register
PCA0CPM1  DATA  0DBH                   ; PCA Module 1 Mode Register
PCA0CPM2  DATA  0DCH                   ; PCA Module 2 Mode Register
PCA0CPM3  DATA  0DDH                   ; PCA Module 3 Mode Register
PCA0CPM4  DATA  0DEH                   ; PCA Module 4 Mode Register
P3SKIP    DATA  0DFH                   ; Port 3Skip
ACC       DATA  0E0H                   ; Accumulator
XBR0      DATA  0E1H                   ; Port I/O Crossbar Control 0
XBR1      DATA  0E2H                   ; Port I/O Crossbar Control 1
XBR2      DATA  0E3H                   ; Port I/O Crossbar Control 2
IT01CF    DATA  0E4H                   ; INT0/INT1 Configuration
SMOD1     DATA  0E5H                   ; UART1 Mode
EIE1      DATA  0E6H                   ; Extended Interrupt Enable 1
EIE2      DATA  0E7H                   ; Extended Interrupt Enable 2
ADC0CN    DATA  0E8H                   ; ADC0 Control
PCA0CPL1  DATA  0E9H                   ; PCA Capture 1 Low
PCA0CPH1  DATA  0EAH                   ; PCA Capture 1 High
PCA0CPL2  DATA  0EBH                   ; PCA Capture 2 Low
PCA0CPH2  DATA  0ECH                   ; PCA Capture 2 High
PCA0CPL3  DATA  0EDH                   ; PCA Capture 3 Low
PCA0CPH3  DATA  0EEH                   ; PCA Capture 3High
RSTSRC    DATA  0EFH                   ; Reset Source Configuration/Status
B         DATA  0F0H                   ; B Register
P0MDIN    DATA  0F1H                   ; Port 0 Input Mode Configuration
P1MDIN    DATA  0F2H                   ; Port 1 Input Mode Configuration
P2MDIN    DATA  0F3H                   ; Port 2 Input Mode Configuration
P3MDIN    DATA  0F4H                   ; Port 3 Input Mode Configuration
P4MDIN    DATA  0F5H                   ; Port 4 Input Mode Configuration
EIP1      DATA  0F6H                   ; Extended Interrupt Priority 1
EIP2      DATA  0F7H                   ; Extended Interrupt Priority 2
SPI0CN    DATA  0F8H                   ; SPI Control
PCA0L     DATA  0F9H                   ; PCA Counter Low
PCA0H     DATA  0FAH                   ; PCA Counter High
PCA0CPL0  DATA  0FBH                   ; PCA Capture 0 Low
PCA0CPH0  DATA  0FCH                   ; PCA Capture 0 High
PCA0CPL4  DATA  0FDH                   ; PCA Capture 4 Low
PCA0CPH4  DATA  0FEH                   ; PCA Capture 4 High
VDM0CN    DATA  0FFH                   ; VDD Monitor Control

;------------------------------------------------------------------------------
; Bit Definitions
;------------------------------------------------------------------------------

; TCON  088H
TF1     BIT     TCON.7                 ; Timer1 overflow flag
TR1     BIT     TCON.6                 ; Timer1 on/off control
TF0     BIT     TCON.5                 ; Timer0 overflow flag
TR0     BIT     TCON.4                 ; Timer0 on/off control
IE1     BIT     TCON.3                 ; Ext. Interrupt 1 edge flag
IT1     BIT     TCON.2                 ; Ext. Interrupt 1 type
IE0     BIT     TCON.1                 ; Ext. Interrupt 0 edge flag
IT0     BIT     TCON.0                 ; Ext. Interrupt 0 type

; SCON0  098H
S0MODE  BIT     SCON0.7                ; Serial mode control bit 0
                                       ; Bit 6 unused
MCE0    BIT     SCON0.5                ; Multiprocessor communication enable
REN0    BIT     SCON0.4                ; Receive enable
TB80    BIT     SCON0.3                ; Transmit bit 8
RB80    BIT     SCON0.2                ; Receive bit 8
TI0     BIT     SCON0.1                ; Transmit interrupt flag
RI0     BIT     SCON0.0                ; Receive interrupt flag

; IE  0A8H
EA      BIT     IE.7                   ; Global interrupt enable
ESPI0   BIT     IE.6                   ; Bit 6 unused
ET2     BIT     IE.5                   ; Bit 5 unused
ES0     BIT     IE.4                   ; UART0 interrupt enable
ET1     BIT     IE.3                   ; Timer1 interrupt enable
EX1     BIT     IE.2                   ; External interrupt 1 enable
ET0     BIT     IE.1                   ; Timer0 interrupt enable
EX0     BIT     IE.0                   ; External interrupt 0 enable

; IP  0B8H
                                       ; Bit 7 unused
PSPI0   BIT     IP.6                   ; SPI0 interrupt priority
PT2     BIT     IP.5                   ; Timer2 priority
PS0     BIT     IP.4                   ; UART0 priority
PT1     BIT     IP.3                   ; Timer1 priority
PX1     BIT     IP.2                   ; External interrupt 1 priority
PT0     BIT     IP.1                   ; Timer0 priority
PX0     BIT     IP.0                   ; External interrupt 0 priority

; SMB0CN  0C0H
MASTER  BIT     SMB0CN.7               ; Master/slave indicator
TXMODE  BIT     SMB0CN.6               ; Transmit mode indicator
STA     BIT     SMB0CN.5               ; Start flag
STO     BIT     SMB0CN.4               ; Stop flag
ACKRQ   BIT     SMB0CN.3               ; Acknowledge request
ARBLOST BIT     SMB0CN.2               ; Arbitration lost indicator
ACK     BIT     SMB0CN.1               ; Acknowledge flag
SI      BIT     SMB0CN.0               ; SMBus interrupt flag

; TMR2CN  0C8H
TF2H    BIT     TMR2CN.7               ; Timer2 high byte overflow flag
TF2L    BIT     TMR2CN.6               ; Timer2 low byte overflow flag
TF2LEN  BIT     TMR2CN.5               ; Timer2 low byte interrupt enable
T2CE    BIT     TMR2CN.4               ; Timer2 capture enable
T2SPLIT BIT     TMR2CN.3               ; Timer2 split mode enable
TR2     BIT     TMR2CN.2               ; Timer2 on/off control
T2CSS   BIT     TMR2CN.1               ; Timer 2 Capture Source select
T2XCLK  BIT     TMR2CN.0               ; Timer2 external clock select

; PSW  0D0H
CY      BIT     PSW.7                  ; Carry flag
AC      BIT     PSW.6                  ; Auxiliary carry flag
F0      BIT     PSW.5                  ; User flag 0
RS1     BIT     PSW.4                  ; Register bank select 1
RS0     BIT     PSW.3                  ; Register bank select 0
OV      BIT     PSW.2                  ; Overflow flag
F1      BIT     PSW.1                  ; User flag 1
P       BIT     PSW.0                  ; Accumulator parity flag

; PCA0CN  0D8H
CF      BIT     PCA0CN.7               ; PCA0 counter overflow flag
CR      BIT     PCA0CN.6               ; PCA0 counter run control
                                       ; Bit5 UNUSED
CCF4    BIT     PCA0CN.4               ; PCA0 module4 capture/compare flag
CCF3    BIT     PCA0CN.3               ; PCA0 module3 capture/compare flag
CCF2    BIT     PCA0CN.2               ; PCA0 module2 capture/compare flag
CCF1    BIT     PCA0CN.1               ; PCA0 module1 capture/compare flag
CCF0    BIT     PCA0CN.0               ; PCA0 module0 capture/compare flag

; ADC0CN  0E8H
AD0EN   BIT     ADC0CN.7               ; ADC0 enable
AD0TM   BIT     ADC0CN.6               ; ADC0 track mode
AD0INT  BIT     ADC0CN.5               ; ADC0 converision complete interrupt flag
AD0BUSY BIT     ADC0CN.4               ; ADC0 busy flag
AD0WINT BIT     ADC0CN.3               ; ADC0 window compare interrupt flag
AD0CM2  BIT     ADC0CN.2               ; ADC0 conversion mode select 2
AD0CM1  BIT     ADC0CN.1               ; ADC0 conversion mode select 1
AD0CM0  BIT     ADC0CN.0               ; ADC0 conversion mode select 0

; SPI0CN  0F8H
SPIF    BIT     SPI0CN.7               ; SPI0 interrupt flag
WCOL    BIT     SPI0CN.6               ; SPI0 write collision flag
MODF    BIT     SPI0CN.5               ; SPI0 mode fault flag
RXOVRN  BIT     SPI0CN.4               ; SPI0 rx overrun flag
NSSMD1  BIT     SPI0CN.3               ; SPI0 slave select mode 1
NSSMD0  BIT     SPI0CN.2               ; SPI0 slave select mode 0
TXBMT   BIT     SPI0CN.1               ; SPI0 transmit buffer empty
SPIEN   BIT     SPI0CN.0               ; SPI0 SPI enable

;------------------------------------------------------------------------------
; End Of File
;------------------------------------------------------------------------------