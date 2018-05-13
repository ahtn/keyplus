;-----------------------------------------------------------------------------
; C8051F700.INC
;-----------------------------------------------------------------------------
; Copyright 2008 Silicon Laboratories, Inc.
; http://www.silabs.com
;
; Program Description:
;
; Register/bit definitions for the C8051F70x family.
;
;
; FID:
; Target:         C8051F70x
; Tool chain:     Keil, SDCC
; Command Line:   None
;
; Release 1.1 - BD
;    -Corrected CRCAUTO0 and CRCAUTO1 Register Names to CRC0AUTO and CRC0CNT
;    -Shortened HARDWAREID and REVISIONID Register Names to HWID and REVID
;    -11 FEB 2009
; Release 1.0
;    -Ported from 'F93x DEFS rev 1.0 by FB
;    -2 JUL 2008
;

;-----------------------------------------------------------------------------
; Header File Preprocessor Directive
;-----------------------------------------------------------------------------



;-----------------------------------------------------------------------------
; Byte Registers
;-----------------------------------------------------------------------------

P0         DATA 080H                   ; Port 0 Latch
SP         DATA 081H                   ; Stack Pointer
DPL        DATA 082H                   ; Data Pointer Low
DPH        DATA 083H                   ; Data Pointer High
SFRNEXT    DATA 085H                   ; SFR Next
SFRLAST    DATA 086H                   ; SFR Last
PCON       DATA 087H                   ; Power Control
TCON       DATA 088H                   ; Timer/Counter Control
TMOD       DATA 089H                   ; Timer/Counter Mode
TL0        DATA 08AH                   ; Timer/Counter 0 Low
TL1        DATA 08BH                   ; Timer/Counter 1 Low
TH0        DATA 08CH                   ; Timer/Counter 0 High
TH1        DATA 08DH                   ; Timer/Counter 1 High
CKCON      DATA 08EH                   ; Clock Control
PSCTL      DATA 08FH                   ; Program Store R/W Control
P1         DATA 090H                   ; Port 1 Latch
TMR3CN     DATA 091H                   ; Timer/Counter 3 Control
CRCCN      DATA 091H                   ; CRC Control
TMR3RLL    DATA 092H                   ; Timer/Counter 3 Reload Low
CS0SS      DATA 092H                   ; CS0 Auto-Scan Start Channel
TMR3RLH    DATA 093H                   ; Timer/Counter 3 Reload High
CS0SE      DATA 093H                   ; CS0 Auto-Scan End Channel
TMR3L      DATA 094H                   ; Timer/Counter 3 Low
CRCIN      DATA 094H                   ; CRC Data Input
TMR3H      DATA 095H                   ; Timer/Counter 3 High
CRCFLIP    DATA 095H                   ; CRC Flip
CS0THL     DATA 096H                   ; CS0 Comparator Threshold Low Byte
CRC0AUTO   DATA 096H                   ; CRC Automatic Control
CS0THH     DATA 097H                   ; CS0 Comparator Threshold High Byte
CRC0CNT    DATA 097H                   ; CRC Automatic Flash Sector Count
SCON0      DATA 098H                   ; UART0 Control
SBUF0      DATA 099H                   ; UART0 Data Buffer
CS0CN      DATA 09AH                   ; CS0 Control
P4MDOUT    DATA 09AH                   ; Port 4 Output Mode
CPT0CN     DATA 09BH                   ; Comparator0 Control
P5MDOUT    DATA 09BH                   ; Port 5 Output Mode
CS0MX      DATA 09CH                   ; CS0 Mux Channel Select
P6MDOUT    DATA 09CH                   ; Port 6 Output Mode
CPT0MD     DATA 09DH                   ; Comparator0 Mode Selection
CS0CF      DATA 09EH                   ; CS0 Configuration
CPT0MX     DATA 09FH                   ; Comparator0 Mux Selection
P2         DATA 0A0H                   ; Port 2 Latch
SPI0CFG    DATA 0A1H                   ; SPI0 Configuration
PCA0PWM    DATA 0A1H                   ; PCA PWM Configuration
SPI0CKR    DATA 0A2H                   ; SPI0 Clock Rate Control
SPI0DAT    DATA 0A3H                   ; SPI0 Data
P0MDOUT    DATA 0A4H                   ; Port 0 Output Mode Configuration
P1MDOUT    DATA 0A5H                   ; Port 1 Output Mode Configuration
P2MDOUT    DATA 0A6H                   ; Port 2 Output Mode Configuration
SFRPAGE    DATA 0A7H                   ; SFR Page
IE         DATA 0A8H                   ; Interrupt Enable
CS0DL      DATA 0A9H                   ; CS0 Data Low Byte
OSCICN     DATA 0A9H                   ; Internal H-F Oscillator Control
CS0DH      DATA 0AAH                   ; CS0 Data High Byte
EMI0CN     DATA 0AAH                   ; EMIF Control
P4         DATA 0ACH                   ; Port 4
REVID      DATA 0ADH                   ; Hardware Revision Identification Byte
P3MDOUT    DATA 0AFH                   ; Port 3 Output Mode Configuration
P3         DATA 0B0H                   ; Port 3
P6         DATA 0B2H                   ; Port 6
P5         DATA 0B3H                   ; Port 5
OSCXCN     DATA 0B5H                   ; External Oscillator Control
EEADDR     DATA 0B6H                   ; EEPROM Byte Address
FLKEY      DATA 0B7H                   ; Flash Lock And Key
IP         DATA 0B8H                   ; Interrupt Priority
REG0CN     DATA 0B9H                   ; Voltage Regulator Control
SMB0ADR    DATA 0BAH                   ; SMBus Slave Address
AMX0SL     DATA 0BBH                   ; AMUX0 Positive Channel Select
SMB0ADM    DATA 0BBH                   ; SMBus Slave Address Mask
ADC0CF     DATA 0BCH                   ; ADC0 Configuration
ADC0L      DATA 0BDH                   ; ADC0 Low
CLKSEL     DATA 0BDH                   ; Clock Select
ADC0H      DATA 0BEH                   ; ADC0 High
OSCICL     DATA 0BFH                   ; Internal Oscillator Calibration
SMB0CN     DATA 0C0H                   ; SMBus0 Control
SMB0CF     DATA 0C1H                   ; SMBus0 Configuration
P6DRV      DATA 0C1H                   ; Port 6 Drive Strength
SMB0DAT    DATA 0C2H                   ; SMBus0 Data
ADC0GTL    DATA 0C3H                   ; ADC0 Greater-Than Compare Low
ADC0GTH    DATA 0C4H                   ; ADC0 Greater-Than Compare High
HWID       DATA 0C4H                   ; Hardware Identification
ADC0LTL    DATA 0C5H                   ; ADC0 Less-Than Compare Word Low
EECNTL     DATA 0C5H                   ; EEPROM Control
ADC0LTH    DATA 0C6H                   ; ADC0 Less-Than Compare Word High
EEKEY      DATA 0C6H                   ; EEPROM Protect Key
EMI0CF     DATA 0C7H                   ; EMIF Configuration
TMR2CN     DATA 0C8H                   ; Timer/Counter 2 Control
TMR2RLL    DATA 0CAH                   ; Timer/Counter 2 Reload Low
TMR2RLH    DATA 0CBH                   ; Timer/Counter 2 Reload High
TMR2L      DATA 0CCH                   ; Timer/Counter 2 Low
TMR2H      DATA 0CDH                   ; Timer/Counter 2 High
EIP1       DATA 0CEH                   ; Extended Interrupt Priority 1
EIP2       DATA 0CFH                   ; Extended Interrupt Priority 2
PSW        DATA 0D0H                   ; Program Status Word
EEDATA     DATA 0D1H                   ; EEPROM Byte Data
REF0CN     DATA 0D2H                   ; Voltage Reference Control
P0SKIP     DATA 0D4H                   ; Port 0 Skip
P1SKIP     DATA 0D5H                   ; Port 1 Skip
P2SKIP     DATA 0D6H                   ; Port 2 Skip
PCA0CN     DATA 0D8H                   ; PCA0 Control
CRCDATA    DATA 0D9H                   ; CRC Data Output
PCA0CPM0   DATA 0DAH                   ; PCA0 Module 0 Mode Register
PCA0CPM1   DATA 0DBH                   ; PCA0 Module 1 Mode Register
PCA0CPM2   DATA 0DCH                   ; PCA0 Module 2 Mode Register
ACC        DATA 0E0H                   ; Accumulator
P1MAT      DATA 0E1H                   ; Port 1 Match
XBR0       DATA 0E1H                   ; Port I/O Crossbar Control 0
XBR1       DATA 0E2H                   ; Port I/O Crossbar Control 1
P1MASK     DATA 0E2H                   ; Port 1 Mask Register
WDTCN      DATA 0E3H                   ; Watchdog Timer Control
IT01CF     DATA 0E4H                   ; INT0/INT1 Configuration
SFR0CN     DATA 0E5H                   ; SFR Page Control
EIE1       DATA 0E6H                   ; Extended Interrupt Enable 1
EIE2       DATA 0E7H                   ; Extended Interrupt Enable 2
ADC0CN     DATA 0E8H                   ; ADC0 Control
PCA0CPL1   DATA 0E9H                   ; PCA0 Capture 1 Low
PCA0CPH1   DATA 0EAH                   ; PCA0 Capture 1 High
PCA0CPL2   DATA 0EBH                   ; PCA0 Capture 2 Low
PCA0CPH2   DATA 0ECH                   ; PCA0 Capture 2 High
DERIVID    DATA 0ECH                   ; Derivitive Identification
PCA0MD     DATA 0EDH                   ; PCA0 Mode
EMI0TC     DATA 0EEH                   ; EMIF Timing Control
RSTSRC     DATA 0EFH                   ; Reset Source Configuration/Status
B          DATA 0F0H                   ; B Register
P0MDIN     DATA 0F1H                   ; Port 0 Input Mode Configuration
P1MDIN     DATA 0F2H                   ; Port 1 Input Mode Configuration
P0MAT      DATA 0F3H                   ; Port 0 Match
P2MDIN     DATA 0F3H                   ; Port 2 Input Mode Configuration
P0MASK     DATA 0F4H                   ; Port 0 Mask
P3MDIN     DATA 0F4H                   ; Port 3 Input Mode Configuration
P4MDIN     DATA 0F5H                   ; Port 4 Input Mode Configuration
P5MDIN     DATA 0F6H                   ; Port 5 Input Mode Configuration
SPI0CN     DATA 0F8H                   ; SPI0 Control
PCA0L      DATA 0F9H                   ; PCA0 Counter Low
P0DRV      DATA 0F9H                   ; Port 0 Drive Strength
PCA0H      DATA 0FAH                   ; PCA0 Counter High
P1DRV      DATA 0FAH                   ; Port 1 Drive Strength
PCA0CPL0   DATA 0FBH                   ; PCA0 Capture 0 Low
P2DRV      DATA 0FBH                   ; Port 2 Drive Strength
PCA0CPH0   DATA 0FCH                   ; PCA0 Capture 0 High
P3DRV      DATA 0FCH                   ; Port 3 Drive Strength
P4DRV      DATA 0FDH                   ; Port 4 Drive Strength
P5DRV      DATA 0FEH                   ; Port 5 Drive Strength
VDM0CN     DATA 0FFH                   ; VDD Monitor Control



;-----------------------------------------------------------------------------
; Address Definitions for Bit-addressable Registers
;-----------------------------------------------------------------------------

#define SFR_P0       0x80
#define SFR_TCON     0x88
#define SFR_P1       0x90
#define SFR_SCON0    0x98
#define SFR_P2       0xA0
#define SFR_IE       0xA8
#define SFR_P3       0xB0
#define SFR_IP       0xB8
#define SFR_SMB0CN   0xC0
#define SFR_TMR2CN   0xC8
#define SFR_PSW      0xD0
#define SFR_PCA0CN   0xD8
#define SFR_ACC      0xE0
#define SFR_ADC0CN   0xE8
#define SFR_B        0xF0
#define SFR_SPI0CN   0xF8

;-----------------------------------------------------------------------------
; Bit Definitions
;-----------------------------------------------------------------------------


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
                                       ; Bit1 UNUSED
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
                                       ; Bit4 UNUSED
                                       ; Bit3 UNUSED
CCF2    BIT     PCA0CN.2               ; PCA0 module2 capture/compare flag
CCF1    BIT     PCA0CN.1               ; PCA0 module1 capture/compare flag
CCF0    BIT     PCA0CN.0               ; PCA0 module0 capture/compare flag

; ADC0CN  0E8H
AD0EN   BIT     ADC0CN.7               ; ADC0 Enable
AD0TM   BIT     ADC0CN.6               ; ADC0 Track Mode Bit 
AD0INT  BIT     ADC0CN.5               ; ADC0 EOC Interrupt Flag
AD0BUSY BIT     ADC0CN.4               ; ADC0 Busy Flag
AD0WINT BIT     ADC0CN.3               ; ADC0 Window Interrupt Flag
AD0CM2  BIT     ADC0CN.2               ; ADC0 Convert Start Mode Bit 2
AD0CM1  BIT     ADC0CN.1               ; ADC0 Convert Start Mode Bit 1
AD0CM0  BIT     ADC0CN.0               ; ADC0 Convert Start Mode Bit 0

; SPI0CN  0F8H
SPIF0    BIT     SPI0CN.7               ; SPI0 interrupt flag
WCOL0    BIT     SPI0CN.6               ; SPI0 write collision flag
MODF0    BIT     SPI0CN.5               ; SPI0 mode fault flag
RXOVRN0  BIT     SPI0CN.4               ; SPI0 rx overrun flag
NSS0MD1  BIT     SPI0CN.3               ; SPI0 slave select mode 1
NSS0MD0  BIT     SPI0CN.2               ; SPI0 slave select mode 0
TXBMT0   BIT     SPI0CN.1               ; SPI0 transmit buffer empty
SPI0EN   BIT     SPI0CN.0               ; SPI0 SPI enable

//-----------------------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------------------