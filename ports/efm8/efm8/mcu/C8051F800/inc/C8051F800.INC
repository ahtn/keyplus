;------------------------------------------------------------------------------
; C8051F800.INC
;------------------------------------------------------------------------------
; Copyright 2009, Silicon Laboratories, Inc.
; http:;www.silabs.com
;
; Program Description:
;
; Register/bit definitions for the C8051F80x-83x family.
;
; Target:         C8051F80x, 'F81x, 'F82x, 'F83x
; Tool chain:     Keil
; Command Line:   None
;
; Release 0.1 - 13 JUL 2009 (PKC)
;    -Initial revision (beta)

;------------------------------------------------------------------------------
; Byte Registers
;------------------------------------------------------------------------------

P0       DATA 080H                     ; Port 0 Latch
SP       DATA 081H                     ; Stack Pointer
DPL      DATA 082H                     ; Data Pointer Low
DPH      DATA 083H                     ; Data Pointer High
PCON     DATA 087H                     ; Power Control
TCON     DATA 088H                     ; Timer/Counter Control
TMOD     DATA 089H                     ; Timer/Counter Mode
TL0      DATA 08AH                     ; Timer/Counter 0 Low
TL1      DATA 08BH                     ; Timer/Counter 1 Low
TH0      DATA 08CH                     ; Timer/Counter 0 High
TH1      DATA 08DH                     ; Timer/Counter 1 High
CKCON    DATA 08EH                     ; Clock Control
PSCTL    DATA 08FH                     ; Program Store R/W Control
P1       DATA 090H                     ; Port 1 Latch
CS0THL   DATA 096H                     ; CS0 Comparator Threshold Low Byte
CS0THH   DATA 097H                     ; CS0 Comparator Threshold High Byte
SCON0    DATA 098H                     ; UART0 Control
SBUF0    DATA 099H                     ; UART0 Data Buffer
CPT0CN   DATA 09BH                     ; Comparator0 Control
CS0MX    DATA 09CH                     ; CS0 Mux Channel Select
CPT0MD   DATA 09DH                     ; Comparator0 Mode Selection
CS0CF    DATA 09EH                     ; CS0 Configuration
CPT0MX   DATA 09FH                     ; Comparator0 Mux Selection
P2       DATA 0A0H                     ; Port 2 Latch
SPI0CFG  DATA 0A1H                     ; SPI0 Configuration
SPI0CKR  DATA 0A2H                     ; SPI0 Clock Rate Control
SPI0DAT  DATA 0A3H                     ; SPI0 Data
P0MDOUT  DATA 0A4H                     ; Port 0 Output Mode Configuration
P1MDOUT  DATA 0A5H                     ; Port 1 Output Mode Configuration
P2MDOUT  DATA 0A6H                     ; Port 2 Output Mode Configuration
IE       DATA 0A8H                     ; Interrupt Enable
CLKSEL   DATA 0A9H                     ; Clock Select
CS0DL    DATA 0ABH                     ; CS0 Data Low Byte
CS0DH    DATA 0ACH                     ; CS0 Data High Byte
DERIVID  DATA 0ADH                     ; Derivitive Identification
CS0CN    DATA 0B0H                     ; CS0 Control
OSCXCN   DATA 0B1H                     ; External Oscillator Control
OSCICN   DATA 0B2H                     ; Internal H-F Oscillator Control
OSCICL   DATA 0B3H                     ; Internal Oscillator Calibration
HWID     DATA 0B5H                     ; Hardware Identification
REVID    DATA 0B6H                     ; Hardware Revision Identification Byte
FLKEY    DATA 0B7H                     ; Flash Lock And Key
IP       DATA 0B8H                     ; Interrupt Priority
CS0SS    DATA 0B9H                     ; CS0 Auto-Scan Start Channel
CS0SE    DATA 0BAH                     ; CS0 Auto-Scan End Channel
ADC0MX   DATA 0BBH                     ; AMUX0 Positive Channel Select
ADC0CF   DATA 0BCH                     ; ADC0 Configuration
ADC0L    DATA 0BDH                     ; ADC0 Low
ADC0H    DATA 0BEH                     ; ADC0 High
SMB0CN   DATA 0C0H                     ; SMBus0 Control
SMB0CF   DATA 0C1H                     ; SMBus0 Configuration
SMB0DAT  DATA 0C2H                     ; SMBus0 Data
ADC0GTL  DATA 0C3H                     ; ADC0 Greater-Than Compare Low
ADC0GTH  DATA 0C4H                     ; ADC0 Greater-Than Compare High
ADC0LTL  DATA 0C5H                     ; ADC0 Less-Than Compare Word Low
ADC0LTH  DATA 0C6H                     ; ADC0 Less-Than Compare Word High
TMR2CN   DATA 0C8H                     ; Timer/Counter 2 Control
REG0CN   DATA 0C9H                     ; Voltage Regulator Control
TMR2RLL  DATA 0CAH                     ; Timer/Counter 2 Reload Low
TMR2RLH  DATA 0CBH                     ; Timer/Counter 2 Reload High
TMR2L    DATA 0CCH                     ; Timer/Counter 2 Low
TMR2H    DATA 0CDH                     ; Timer/Counter 2 High
CRC0CN   DATA 0CEH                     ; CRC Control
CRC0FLIP DATA 0CFH                     ; CRC Flip
PSW      DATA 0D0H                     ; Program Status Word
REF0CN   DATA 0D1H                     ; Voltage Reference Control
CRC0AUTO DATA 0D2H                     ; CRC Automatic Control
CRC0CNT  DATA 0D3H                     ; CRC Automatic Flash Sector Count
P0SKIP   DATA 0D4H                     ; Port 0 Skip
P1SKIP   DATA 0D5H                     ; Port 1 Skip
SMB0ADM  DATA 0D6H                     ; SMBus Slave Address Mask
SMB0ADR  DATA 0D7H                     ; SMBus Slave Address
PCA0CN   DATA 0D8H                     ; PCA0 Control
PCA0MD   DATA 0D9H                     ; PCA0 Mode
PCA0CPM0 DATA 0DAH                     ; PCA0 Module 0 Mode Register
PCA0CPM1 DATA 0DBH                     ; PCA0 Module 1 Mode Register
PCA0CPM2 DATA 0DCH                     ; PCA0 Module 2 Mode Register
CRC0IN   DATA 0DDH                     ; CRC Data Input
CRC0DATA DATA 0DEH                     ; CRC Data Output
ACC      DATA 0E0H                     ; Accumulator
XBR0     DATA 0E1H                     ; Port I/O Crossbar Control 0
XBR1     DATA 0E2H                     ; Port I/O Crossbar Control 1
IT01CF   DATA 0E4H                     ; INT0/INT1 Configuration
EIE1     DATA 0E6H                     ; Extended Interrupt Enable 1
EIE2     DATA 0E7H                     ; Extended Interrupt Enable 2
ADC0CN   DATA 0E8H                     ; ADC0 Control
PCA0CPL1 DATA 0E9H                     ; PCA0 Capture 1 Low
PCA0CPH1 DATA 0EAH                     ; PCA0 Capture 1 High
PCA0CPL2 DATA 0EBH                     ; PCA0 Capture 2 Low
PCA0CPH2 DATA 0ECH                     ; PCA0 Capture 2 High
P1MAT    DATA 0EDH                     ; Port 1 Match
P1MASK   DATA 0EEH                     ; Port 1 Mask Register
RSTSRC   DATA 0EFH                     ; Reset Source Configuration/Status
B        DATA 0F0H                     ; B Register
P0MDIN   DATA 0F1H                     ; Port 0 Input Mode Configuration
P1MDIN   DATA 0F2H                     ; Port 1 Input Mode Configuration
EIP1     DATA 0F3H                     ; Extended Interrupt Priority 1
EIP2     DATA 0F4H                     ; Extended Interrupt Priority 2
PCA0PWM  DATA 0F7H                     ; PCA PWM Configuration
SPI0CN   DATA 0F8H                     ; SPI0 Control
PCA0L    DATA 0F9H                     ; PCA0 Counter Low
PCA0H    DATA 0FAH                     ; PCA0 Counter High
PCA0CPL0 DATA 0FBH                     ; PCA0 Capture 0 Low
PCA0CPH0 DATA 0FCH                     ; PCA0 Capture 0 High
P0MAT    DATA 0FDH                     ; Port 0 Match
P0MASK   DATA 0FEH                     ; Port 0 Mask
VDM0CN   DATA 0FFH                     ; VDD Monitor Control

;------------------------------------------------------------------------------
; Address Definitions for Bit-addressable Registers
;------------------------------------------------------------------------------

#define SFR_P0       0x80
#define SFR_TCON     0x88
#define SFR_P1       0x90
#define SFR_SCON0    0x98
#define SFR_P2       0xA0
#define SFR_IE       0xA8
#define SFR_CS0CN    0xB0
#define SFR_IP       0xB8
#define SFR_SMB0CN   0xC0
#define SFR_TMR2CN   0xC8
#define SFR_PSW      0xD0
#define SFR_PCA0CN   0xD8
#define SFR_ACC      0xE0
#define SFR_ADC0CN   0xE8
#define SFR_B        0xF0
#define SFR_SPI0CN   0xF8

;------------------------------------------------------------------------------
; Bit Definitions
;------------------------------------------------------------------------------

; TCON 088H
TF1      BIT TCON.7                    ; Timer 1 Overflow Flag
TR1      BIT TCON.6                    ; Timer 1 On/Off Control
TF0      BIT TCON.5                    ; Timer 0 Overflow Flag
TR0      BIT TCON.4                    ; Timer 0 On/Off Control
IE1      BIT TCON.3                    ; Ext. Interrupt 1 Edge Flag
IT1      BIT TCON.2                    ; Ext. Interrupt 1 Type
IE0      BIT TCON.1                    ; Ext. Interrupt 0 Edge Flag
IT0      BIT TCON.0                    ; Ext. Interrupt 0 Type

; SCON0 098H
S0MODE   BIT SCON0.7                   ; UART0 Mode
                                       ; Bit6 UNUSED
MCE0     BIT SCON0.5                   ; UART0 MCE
REN0     BIT SCON0.4                   ; UART0 RX Enable
TB80     BIT SCON0.3                   ; UART0 TX Bit 8
RB80     BIT SCON0.2                   ; UART0 RX Bit 8
TI0      BIT SCON0.1                   ; UART0 TX Interrupt Flag
RI0      BIT SCON0.0                   ; UART0 RX Interrupt Flag

; IE 0A8H
EA       BIT IE.7                      ; Global Interrupt Enable
ESPI0    BIT IE.6                      ; SPI0 Interrupt Enable
ET2      BIT IE.5                      ; Timer 2 Interrupt Enable
ES0      BIT IE.4                      ; UART0 Interrupt Enable
ET1      BIT IE.3                      ; Timer 1 Interrupt Enable
EX1      BIT IE.2                      ; External Interrupt 1 Enable
ET0      BIT IE.1                      ; Timer 0 Interrupt Enable
EX0      BIT IE.0                      ; External Interrupt 0 Enable

; CS0CN 0C0H
CS0EN    BIT CS0CN.7                   ; CS0 Enable
                                       ; Bit6 UNUSED
CS0INT   BIT CS0CN.5                   ; CS0 Interrupt Flag
CS0BUSY  BIT CS0CN.4                   ; CS0 Busy
CS0CMPEN BIT CS0CN.3                   ; CS0 Digital Comparator Enable
                                       ; Bit2 UNUSED
                                       ; Bit1 UNUSED
CS0CMPF  BIT CS0CN.0                   ; CS0 Digital Comparator Interrupt Flag

; IP 0B8H
                                       ; Bit7 UNUSED
PSPI0    BIT IP.6                      ; SPI0 Priority
PT2      BIT IP.5                      ; Timer 2 Priority
PS0      BIT IP.4                      ; UART0 Priority
PT1      BIT IP.3                      ; Timer 1 Priority
PX1      BIT IP.2                      ; External Interrupt 1 Priority
PT0      BIT IP.1                      ; Timer 0 Priority
PX0      BIT IP.0                      ; External Interrupt 0 Priority

; SMB0CN 0C0H
MASTER   BIT SMB0CN.7                  ; SMBus0 Master/Slave
TXMODE   BIT SMB0CN.6                  ; SMBus0 Transmit Mode
STA      BIT SMB0CN.5                  ; SMBus0 Start Flag
STO      BIT SMB0CN.4                  ; SMBus0 Stop Flag
ACKRQ    BIT SMB0CN.3                  ; SMBus0 Acknowledge Request
ARBLOST  BIT SMB0CN.2                  ; SMBus0 Arbitration Lost
ACK      BIT SMB0CN.1                  ; SMBus0 Acknowledge Flag
SI       BIT SMB0CN.0                  ; SMBus0 Interrupt Pending Flag

; TMR2CN 0C8H
TF2H     BIT TMR2CN.7                  ; Timer 2 High Byte Overflow Flag
TF2L     BIT TMR2CN.6                  ; Timer 2 Low Byte Overflow Flag
TF2LEN   BIT TMR2CN.5                  ; Timer 2 Low Byte Interrupt Enable
TF2CEN   BIT TMR2CN.4                  ; Timer 2 Lfo Capture Enable
T2SPLIT  BIT TMR2CN.3                  ; Timer 2 Split Mode Enable
TR2      BIT TMR2CN.2                  ; Timer 2 On/Off Control
                                       ; Bit6 UNUSED
T2XCLK   BIT TMR2CN.0                  ; Timer 2 External Clock Select

; PSW 0D0H
CY       BIT PSW.7                     ; Carry Flag
AC       BIT PSW.6                     ; Auxiliary Carry Flag
F0       BIT PSW.5                     ; User Flag 0
RS1      BIT PSW.4                     ; Register Bank Select 1
RS0      BIT PSW.3                     ; Register Bank Select 0
OV       BIT PSW.2                     ; Overflow Flag
F1       BIT PSW.1                     ; User Flag 1
P        BIT PSW.0                     ; Accumulator Parity Flag

; PCA0CN 0D8H
CF       BIT PCA0CN.7                  ; PCA0 Counter Overflow Flag
CR       BIT PCA0CN.6                  ; PCA0 Counter Run Control Bit
                                       ; Bit5 UNUSED
                                       ; Bit4 UNUSED
                                       ; Bit3 UNUSED
CCF2     BIT PCA0CN.2                  ; PCA0 Module 2 Interrupt Flag
CCF1     BIT PCA0CN.1                  ; PCA0 Module 1 Interrupt Flag
CCF0     BIT PCA0CN.0                  ; PCA0 Module 0 Interrupt Flag

; ADC0CN 0E8H
AD0EN    BIT ADC0CN.7                  ; ADC0 Enable
AD0TM    BIT ADC0CN.6                  ; ADC0 Track Mode
AD0INT   BIT ADC0CN.5                  ; ADC0 EOC Interrupt Flag
AD0BUSY  BIT ADC0CN.4                  ; ADC0 Busy Flag
AD0WINT  BIT ADC0CN.3                  ; ADC0 Window Interrupt Flag
AD0CM2   BIT ADC0CN.2                  ; ADC0 Convert Start Mode Bit 2
AD0CM1   BIT ADC0CN.1                  ; ADC0 Convert Start Mode Bit 1
AD0CM0   BIT ADC0CN.0                  ; ADC0 Convert Start Mode Bit 0

; SPI0CN 0F8H
SPIF     BIT SPI0CN.7                  ; SPI0 Interrupt Flag
WCOL     BIT SPI0CN.6                  ; SPI0 Write Collision Flag
MODF     BIT SPI0CN.5                  ; SPI0 Mode Fault Flag
RXOVRN   BIT SPI0CN.4                  ; SPI0 RX Overrun Flag
NSSMD1   BIT SPI0CN.3                  ; SPI0 Slave Select Mode 1
NSSMD0   BIT SPI0CN.2                  ; SPI0 Slave Select Mode 0
TXBMT    BIT SPI0CN.1                  ; SPI0 TX Buffer Empty Flag
SPIEN    BIT SPI0CN.0                  ; SPI0 SPI0 Enable

;------------------------------------------------------------------------------
; End Of File
;------------------------------------------------------------------------------