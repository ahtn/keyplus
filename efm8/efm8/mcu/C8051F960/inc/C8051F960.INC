;-----------------------------------------------------------------------------
; C8051F960.INC
;-----------------------------------------------------------------------------
; Copyright 2014 Silicon Laboratories, Inc.
; http:;www.silabs.com
;
; Program Description:
;
; Register/bit definitions for the C8051F96x family.
;
;
; Target:         C8051F96x
; Tool chain:     Keil, Raisonance, SDCC
; Command Line:   None
;
;
; Version 0.4
;    - Initial Release - KB
; Version 0.5
;    - Corrections to ADC0PWR and ADC0TK - KB
;
;-----------------------------------------------------------------------------
;-----------------------------------------------------------------------------
; Page 0x0 sfrs
;-----------------------------------------------------------------------------
P0          DATA  080H                 ; Port 0 Latch
SP          DATA  081H                 ; Stack Pointer
DPL         DATA  082H                 ; Data Pointer Low
DPH         DATA  083H                 ; Data Pointer High
PSBANK      DATA  084H                 ; Flash Page Switch Bank SFR
SFRNEXT     DATA  085H                 ; SFR Page Stack Next
SFRLAST     DATA  086H                 ; SFR Page Stack Last
PCON        DATA  087H                 ; Power Control
TCON        DATA  088H                 ; Timer/Counter Control
TMOD        DATA  089H                 ; Timer/Counter Mode
TL0         DATA  08AH                 ; Timer/Counter 0 Low
TL1         DATA  08BH                 ; Timer/Counter 1 Low
TH0         DATA  08CH                 ; Timer/Counter 0 High
TH1         DATA  08DH                 ; Timer/Counter 1 High
CKCON       DATA  08EH                 ; Clock Control
PSCTL       DATA  08FH                 ; Program Store R/W Control
P1          DATA  090H                 ; Port 1 Latch
TMR3CN      DATA  091H                 ; Timer/Counter 3 Control
TMR3RLL     DATA  092H                 ; Timer/Counter 3 Reload Low
TMR3RLH     DATA  093H                 ; Timer/Counter 3 Reload High
TMR3L       DATA  094H                 ; Timer/Counter 3 Low
TMR3H       DATA  095H                 ; Timer/Counter 3 High
SCON0       DATA  098H                 ; UART0 Control
SBUF0       DATA  099H                 ; UART0 Data Buffer
CPT1CN      DATA  09AH                 ; Comparator1 Control
CPT0CN      DATA  09BH                 ; Comparator0 Control
CPT1MD      DATA  09CH                 ; Comparator1 Mode Selection
CPT0MD      DATA  09DH                 ; Comparator0 Mode Selection
CPT1MX      DATA  09EH                 ; Comparator1 Mux Selection
CPT0MX      DATA  09FH                 ; Comparator0 Mux Selection
P2          DATA  0A0H                 ; Port 2 Latch
SPI0CFG     DATA  0A1H                 ; SPI0 Configuration
SPI0CKR     DATA  0A2H                 ; SPI0 Clock Rate Control
SPI0DAT     DATA  0A3H                 ; SPI0 Data
P0MDOUT     DATA  0A4H                 ; Port 0 Output Mode Configuration
P1MDOUT     DATA  0A5H                 ; Port 1 Output Mode Configuration
P2MDOUT     DATA  0A6H                 ; Port 2 Output Mode Configuration
SFRPAGE     DATA  0A7H                 ; SFR Page
IE          DATA  0A8H                 ; Interrupt Enable
CLKSEL      DATA  0A9H                 ; Clock Select
EMI0CN      DATA  0AAH                 ; EMIF Control
EMI0CF      DATA  0ABH                 ; EMIF Configuration
RTC0ADR     DATA  0ACH                 ; RTC0 Address
RTC0DAT     DATA  0ADH                 ; RTC0 Data
RTC0KEY     DATA  0AEH                 ; RTC0 Key
EMI0TC      DATA  0AFH                 ; EMIF Timing Control
P3          DATA  0B0H                 ; Port 3
OSCXCN      DATA  0B1H                 ; External Oscillator Control
OSCICN      DATA  0B2H                 ; Internal Oscillator Control
PMU0MD      DATA  0B3H                 ; Internal Oscillator Calibration
PMU0CF      DATA  0B5H                 ; PMU0 Configuration 0
PMU0FL      DATA  0B6H                 ; PMU0 flag
FLKEY       DATA  0B7H                 ; Flash Lock And Key
IP          DATA  0B8H                 ; Interrupt Priority
IREF0CN     DATA  0B9H                 ; Current Reference IREF0 Configuration
ADC0AC      DATA  0BAH                 ; ADC0 Accumulator Configuration
ADC0MX      DATA  0BBH                 ; ADC0 MUX
ADC0CF      DATA  0BCH                 ; ADC0 Configuration
ADC0L       DATA  0BDH                 ; ADC0 Low
ADC0H       DATA  0BEH                 ; ADC0 High
P1MASK      DATA  0BFH                 ; Port 1 Mask
SMB0CN      DATA  0C0H                 ; SMBus0 Control
SMB0CF      DATA  0C1H                 ; SMBus0 Configuration
SMB0DAT     DATA  0C2H                 ; SMBus0 Data
ADC0GTL     DATA  0C3H                 ; ADC0 Greater-Than Compare Low
ADC0GTH     DATA  0C4H                 ; ADC0 Greater-Than Compare High
ADC0LTL     DATA  0C5H                 ; ADC0 Less-Than Compare Word Low
ADC0LTH     DATA  0C6H                 ; ADC0 Less-Than Compare Word High
P0MASK      DATA  0C7H                 ; Port 0 Mask
TMR2CN      DATA  0C8H                 ; Timer/Counter 2 Control
REG0CN      DATA  0C9H                 ; Voltage Regulator (REG0) Control
TMR2RLL     DATA  0CAH                 ; Timer/Counter 2 Reload Low
TMR2RLH     DATA  0CBH                 ; Timer/Counter 2 Reload High
TMR2L       DATA  0CCH                 ; Timer/Counter 2 Low
TMR2H       DATA  0CDH                 ; Timer/Counter 2 High
PCA0CPM5    DATA  0CEH                 ; PCA0 Module 5 Mode Register
P1MAT       DATA  0CFH                 ; Port 1 Match
PSW         DATA  0D0H                 ; Program Status Word
REF0CN      DATA  0D1H                 ; Voltage Reference Control
PCA0CPL5    DATA  0D2H                 ; PCA0 Capture 5 Low
PCA0CPH5    DATA  0D3H                 ; PCA0 Capture 5 High
P0SKIP      DATA  0D4H                 ; Port 0 Skip
P1SKIP      DATA  0D5H                 ; Port 1 Skip
P2SKIP      DATA  0D6H                 ; Port 2 Skip
P0MAT       DATA  0D7H                 ; Port 0 Match
PCA0CN      DATA  0D8H                 ; PCA0 Control
PCA0MD      DATA  0D9H                 ; PCA0 Mode
PCA0CPM0    DATA  0DAH                 ; PCA0 Module 0 Mode Register
PCA0CPM1    DATA  0DBH                 ; PCA0 Module 1 Mode Register
PCA0CPM2    DATA  0DCH                 ; PCA0 Module 2 Mode Register
PCA0CPM3    DATA  0DDH                 ; PCA0 Module 3 Mode Register
PCA0CPM4    DATA  0DEH                 ; PCA0 Module 4 Mode Register
PCA0PWM     DATA  0DFH                 ; PCA0 PWM Configuration
ACC         DATA  0E0H                 ; Accumulator
XBR0        DATA  0E1H                 ; Port I/O Crossbar Control 0
XBR1        DATA  0E2H                 ; Port I/O Crossbar Control 1
XBR2        DATA  0E3H                 ; Port I/O Crossbar Control 2
IT01CF      DATA  0E4H                 ; INT0/INT1 Configuration
FLWR        DATA  0E5H                 ; Flash Write Only Register
EIE1        DATA  0E6H                 ; Extended Interrupt Enable 1
EIE2        DATA  0E7H                 ; Extended Interrupt Enable 2
ADC0CN      DATA  0E8H                 ; ADC0 Control
PCA0CPL1    DATA  0E9H                 ; PCA0 Capture 1 Low
PCA0CPH1    DATA  0EAH                 ;  PCA0 Capture 1 High
PCA0CPL2    DATA  0EBH                 ; PCA0 Capture 2 Low
PCA0CPH2    DATA  0ECH                 ; PCA0 Capture 2 High
PCA0CPL3    DATA  0EDH                 ; PCA0 Capture 3 Low
PCA0CPH3    DATA  0EEH                 ; PCA0 Capture 3 High
RSTSRC      DATA  0EFH                 ; Reset Source Configuration/Status
B           DATA  0F0H                 ; B Register
P0MDIN      DATA  0F1H                 ; Port 0 Input Mode Configuration
P1MDIN      DATA  0F2H                 ; Port 1 Input Mode Configuration
P2MDIN      DATA  0F3H                 ; Port 2 Input Mode Configuration
SMB0ADR     DATA  0F4H                 ; SMBus Slave Address
SMB0ADM     DATA  0F5H                 ; SMBus Slave Address Mask
EIP1        DATA  0F6H                 ; Extended Interrupt Priority 1
EIP2        DATA  0F7H                 ; Extended Interrupt Priority 2
SPI0CN      DATA  0F8H                 ; SPI0 Control
PCA0L       DATA  0F9H                 ; PCA0 Counter Low
PCA0H       DATA  0FAH                 ; PCA0 Counter High
PCA0CPL0    DATA  0FBH                 ; PCA0 Capture 0 Low
PCA0CPH0    DATA  0FCH                 ; PCA0 Capture 0 High
PCA0CPL4    DATA  0FDH                 ; PCA0 Capture 4 Low
PCA0CPH4    DATA  0FEH                 ; PCA0 Capture 4 High
VDM0CN      DATA  0FFH                 ; VDD Monitor Control
;-----------------------------------------------------------------------------
; Page 0x2 sfrs
;-----------------------------------------------------------------------------
LCD0D0      DATA  089H                 ; LCD0 Data 0
LCD0D1      DATA  08AH                 ; LCD0 Data 1
LCD0D2      DATA  08BH                 ; LCD0 Data 2
LCD0D3      DATA  08CH                 ; LCD0 Data 3
LCD0D4      DATA  08DH                 ; LCD0 Data 4
LCD0D5      DATA  08EH                 ; LCD0 Data 5
LCD0D6      DATA  091H                 ; LCD0 Data 6
LCD0D7      DATA  092H                 ; LCD0 Data 7
LCD0D8      DATA  093H                 ; LCD0 Data 8
LCD0D9      DATA  094H                 ; LCD0 Data 9
LCD0DA      DATA  095H                 ; LCD0 Data A
LCD0DB      DATA  096H                 ; LCD0 Data B
LCD0DC      DATA  097H                 ; LCD0 Data C
LCD0DD      DATA  099H                 ; LCD0 Data D
LCD0DE      DATA  09AH                 ; LCD0 Data E
LCD0DF      DATA  09BH                 ; LCD0 Data F
LCD0CNTRST  DATA  09CH                 ; LCD0 Contrast
LCD0CN      DATA  09DH                 ; LCD0 Control
LCD0BLINK   DATA  09EH                 ; LCD0 Blink Mask
LCD0TOGR    DATA  09FH                 ; LCD0 Toggle Rate
SPI1CFG     DATA  0A1H                 ; SPI1 Configuration
SPI1CKR     DATA  0A2H                 ; SPI1 Clock Rate Control
SPI1DAT     DATA  0A3H                 ; SPI1 Data
LCD0PWR     DATA  0A4H                 ; LCD0 Power
LCD0CF      DATA  0A5H                 ; LCD0 Configuration
LCD0VBMCN   DATA  0A6H                 ; LCD0 VBAT Monitor Control
LCD0CLKDIVL DATA  0A9H                 ; LCD0 Clock Divider Low
LCD0CLKDIVH DATA  0AAH                 ; LCD0 Clock Divider High
LCD0MSCN    DATA  0ABH                 ; LCD0 Master Control
LCD0MSCF    DATA  0ACH                 ; LCD0 Master Configuration
LCD0CHPCF   DATA  0ADH                 ; LCD0 Charge Pump Configuration
LCD0CHPMD   DATA  0AEH                 ; LCD0 Charge Pump Mode
LCD0VBMCF   DATA  0AFH                 ; LCD0 VBAT Monitor Configuration
DC0CN       DATA  0B1H                 ; DC0 Control
DC0CF       DATA  0B2H                 ; DC0 Configuration
DC0MD       DATA  0B3H                 ; DC0 Mode
LCD0CHPCN   DATA  0B5H                 ; LCD0 Charge Pump Control
LCD0BUFMD   DATA  0B6H                 ; LCD0 Buffer Mode
CRC1IN      DATA  0B9H                 ; CRC1 In
CRC1OUTL    DATA  0BAH                 ; CRC1 Out Low
CRC1OUTH    DATA  0BBH                 ; CRC1 Out High
CRC1POLL    DATA  0BCH                 ; CRC1 Polynomial Low
CRC1POLH    DATA  0BDH                 ; CRC1 Polynomial High
CRC1CN      DATA  0BEH                 ; CRC1 Control
PC0STAT     DATA  0C1H                 ; PC0 Status
ENC0L       DATA  0C2H                 ; ENC0 Low
ENC0M       DATA  0C3H                 ; ENC0 Middle
ENC0H       DATA  0C4H                 ; ENC0 High
ENC0CN      DATA  0C5H                 ; ENC0 Control
VREGINSDL   DATA  0C6H                 ; VREGIN Switch Delay Low
VREGINSDH   DATA  0C7H                 ; VREGIN Switch Delay High
DMA0NCF     DATA  0C9H                 ; DMA0 Configuration
DMA0NBAL    DATA  0CAH                 ; DMA0 Base Address Low (Selected Channel)
DMA0NBAH    DATA  0CBH                 ; DMA0 Base Address High (Selected Channel)
DMA0NAOL    DATA  0CCH                 ; DMA0 Address Offset Low (Selected Channel)
DMA0NAOH    DATA  0CDH                 ; DMA0 Address Offset High (Selected Channel)
DMA0NSZL    DATA  0CEH                 ; DMA0 Size Low (Selected Channel)
DMA0NSZH    DATA  0CFH                 ; DMA0 Size High (Selected Channel)
DMA0SEL     DATA  0D1H                 ; DMA0 Channel Select
DMA0EN      DATA  0D2H                 ; DMA0 Enable
DMA0INT     DATA  0D3H                 ; DMA0 Interrupt
DMA0MINT    DATA  0D4H                 ; DMA0 Middle Interrupt
DMA0BUSY    DATA  0D5H                 ; DMA0 Busy
DMA0NMD     DATA  0D6H                 ; DMA0 Mode (Selected Channel)
PC0PCF      DATA  0D7H                 ; PC0 Pull-up Configuration
PC0MD       DATA  0D9H                 ; PC0 Mode
PC0CTR0L    DATA  0DAH                 ; PC0 Counter 0 Low
PC0CTR0M    DATA  0DBH                 ; PC0 Counter 0 Middle
PC0CTR0H    DATA  0DCH                 ; PC0 Counter 0 High
PC0CTR1L    DATA  0DDH                 ; PC0 Counter 1 Low
PC0CTR1M    DATA  0DEH                 ; PC0 Counter 1 Middle
PC0CTR1H    DATA  0DFH                 ; PC0 Counter 1 High
PC0CMP0L    DATA  0E1H                 ; PC0 Comparator 0 Low
PC0CMP0M    DATA  0E2H                 ; PC0 Comparator 0 Middle
PC0CMP0H    DATA  0E3H                 ; PC0 Comparator 0 High
PC0TH       DATA  0E4H                 ; PC0 Threshold
AES0BCFG    DATA  0E9H                 ; AES0 Block Configuration
AES0DCFG    DATA  0EAH                 ; AES0 Data Configuration
AES0BIN     DATA  0EBH                 ; AES0 Block Input
AES0XIN     DATA  0ECH                 ; AES0 XOR Input
AES0KIN     DATA  0EDH                 ; AES0 Key Input
AES0DBA     DATA  0EEH                 ; AES0 Data Byte Address
AES0KBA     DATA  0EFH                 ; AES0 Key Byte Address
PC0CMP1L    DATA  0F1H                 ; PC0 Comparator 1 Low
PC0CMP1M    DATA  0F2H                 ; PC0 Comparator 1 Middle
PC0CMP1H    DATA  0F3H                 ; PC0 Comparator 1 High
PC0HIST     DATA  0F4H                 ; PC0 History
AES0YOUT    DATA  0F5H                 ; AES Y Out
SPI1CN      DATA  0F8H                 ; SPI1 Control
PC0DCL      DATA  0F9H                 ; PC0 Debounce Configuration Low
PC0DCH      DATA  0FAH                 ; PC0 Debounce Configuration high
PC0INT0     DATA  0FBH                 ; PC0 Interrupt 0
PC0INT1     DATA  0FCH                 ; PC0 Interrupt 1
DC0RDY      DATA  0FDH                 ; DC0 Ready
;-----------------------------------------------------------------------------
; Page 0xF sfrs
;-----------------------------------------------------------------------------
SFRPGCN     DATA  08EH                 ; SFR Page Control
CRC0DAT     DATA  091H                 ; CRC0 Data
CRC0CN      DATA  092H                 ; CRC0 Control
CRC0IN      DATA  093H                 ; CRC0 Input
CRC0FLIP    DATA  094H                 ; CRC0 Flip
CRC0AUTO    DATA  096H                 ; CRC0 Automatic Control
CRC0CNT     DATA  097H                 ; CRC0 Automatic Flash Sector Count
LCD0BUFCN   DATA  09CH                 ; LCD0 Buffer Control
P3DRV       DATA  0A1H                 ; Port 3 Drive Strength
P4DRV       DATA  0A2H                 ; Port 4 Drive Strength
P5DRV       DATA  0A3H                 ; Port 5 Drive Strength
P0DRV       DATA  0A4H                 ; Port 0 Drive Strength
P1DRV       DATA  0A5H                 ; Port 1 Drive Strength
P2DRV       DATA  0A6H                 ; Port 2 Drive Strength
P6DRV       DATA  0AAH                 ; Port 6 Drive Strength
P7DRV       DATA  0ABH                 ; Port 7 Drive Strength
LCD0BUFCF   DATA  0ACH                 ; LCD0 Buffer Configuration
P3MDOUT     DATA  0B1H                 ; P3 Mode Out
OSCIFL      DATA  0B2H                 ; Internal Oscillator Flash
OSCICL      DATA  0B3H                 ; Internal Oscillator Calibration
FLSCL       DATA  0B6H                 ; Flash Scale Register
IREF0CF     DATA  0B9H                 ; Current Reference IREF0 Configuration
ADC0PWR     DATA  0BAH                 ; ADC0 Burst Mode Power-Up Time
ADC0TK      DATA  0BBH                 ; ADC0 Tracking Control
TOFFL       DATA  0BDH                 ; Temperature Offset Low
TOFFH       DATA  0BEH                 ; Temperature Offset High
P4          DATA  0D9H                 ; Port 4 Latch
P5          DATA  0DAH                 ; Port 4 Latch
P6          DATA  0DBH                 ; Port 4 Latch
P7          DATA  0DCH                 ; Port 4 Latch
HWID        DATA  0E9H                 ; Hardware ID
REVID       DATA  0EAH                 ; Revision ID
DEVICEID    DATA  0EBH                 ; Device ID
P3MDIN      DATA  0F1H                 ; Port 3 Input Mode Configuration
P4MDIN      DATA  0F2H                 ; Port 4 Input Mode Configuration
P5MDIN      DATA  0F3H                 ; Port 5 Input Mode Configuration
P6MDIN      DATA  0F4H                 ; Port 6 Input Mode Configuration
PCLKACT     DATA  0F5H                 ; Peripheral Clock Enable Active Mode
P4MDOUT     DATA  0F9H                 ; P4 Mode Out
P5MDOUT     DATA  0FAH                 ; P5 Mode Out
P6MDOUT     DATA  0FBH                 ; P6 Mode Out
P7MDOUT     DATA  0FCH                 ; P7 Mode Out
CLKMODE     DATA  0FDH                 ; Clock Mode
PCLKEN      DATA  0FEH                 ; Peripheral Clock Enables (LP Idle)
;-----------------------------------------------------------------------------
; Bit Definitions
;-----------------------------------------------------------------------------

; TCON 088H
TF1      BIT   TCON.7                  ; Timer 1 Overflow Flag
TR1      BIT   TCON.6                  ; Timer 1 On/Off Control
TF0      BIT   TCON.5                  ; Timer 0 Overflow Flag
TR0      BIT   TCON.4                  ; Timer 0 On/Off Control
IE1      BIT   TCON.3                  ; External Interrupt 1 Edge Flag
IT1      BIT   TCON.2                  ; External Interrupt 1 Type
IE0      BIT   TCON.1                  ; External Interrupt 0 Edge Flag
IT0      BIT   TCON.0                  ; External Interrupt 0 Type

; SCON0 098H
S0MODE   BIT   SCON0.7                 ; UART0 Mode
                                       ; Bit6 UNUSED
MCE0     BIT   SCON0.5                 ; UART0 MCE
REN0     BIT   SCON0.4                 ; UART0 RX Enable
TB80     BIT   SCON0.3                 ; UART0 TX Bit 8
RB80     BIT   SCON0.2                 ; UART0 RX Bit 8
TI0      BIT   SCON0.1                 ; UART0 TX Interrupt Flag
RI0      BIT   SCON0.0                 ; UART0 RX Interrupt Flag

; IE 0A8H
EA       BIT   IE.7                    ; Global Interrupt Enable
ESPI0    BIT   IE.6                    ; SPI0 Interrupt Enable
ET2      BIT   IE.5                    ; Timer 2 Interrupt Enable
ES0      BIT   IE.4                    ; UART0 Interrupt Enable
ET1      BIT   IE.3                    ; Timer 1 Interrupt Enable
EX1      BIT   IE.2                    ; External Interrupt 1 Enable
ET0      BIT   IE.1                    ; Timer 0 Interrupt Enable
EX0      BIT   IE.0                    ; External Interrupt 0 Enable


; IP 0B8H
                                       ; Bit7 UNUSED
PSPI0    BIT   IP.6                    ; SPI0 Priority
PT2      BIT   IP.5                    ; Timer 2 Priority
PS0      BIT   IP.4                    ; UART0 Priority
PT1      BIT   IP.3                    ; Timer 1 Priority
PX1      BIT   IP.2                    ; External Interrupt 1 Priority
PT0      BIT   IP.1                    ; Timer 0 Priority
PX0      BIT   IP.0                    ; External Interrupt 0 Priority

; SMB0CN 0C0
MASTER   BIT   SMB0CN.7                ; SMBus0 Master/Slave
TXMODE   BIT   SMB0CN.6                ; SMBus0 Transmit Mode
STA      BIT   SMB0CN.5                ; SMBus0 Start Flag
STO      BIT   SMB0CN.4                ; SMBus0 Stop Flag
ACKRQ    BIT   SMB0CN.3                ; SMBus0 Acknowledge Request
ARBLOST  BIT   SMB0CN.2                ; SMBus0 Arbitration Lost
ACK      BIT   SMB0CN.1                ; SMBus0 Acknowledge Flag
SI       BIT   SMB0CN.0                ; SMBus0 Interrupt Pending Flag

; TMR2CN 0C8
TF2H     BIT   TMR2CN.7                ; Timer 2 High Byte Overflow Flag
TF2L     BIT   TMR2CN.6                ; Timer 2 Low Byte Overflow Flag
TF2LEN   BIT   TMR2CN.5                ; Timer 2 Low Byte Interrupt Enable
TF2CEN   BIT   TMR2CN.4                ; Timer 2 LFO Capture Enable
T2SPLIT  BIT   TMR2CN.3                ; Timer 2 Split Mode Enable
TR2      BIT   TMR2CN.2                ; Timer 2 On/Off Control
T2RCLK   BIT   TMR2CN.1                ; Timer 2 Capture Mode
T2XCLK   BIT   TMR2CN.0                ; Timer 2 External Clock Select

; PSW 0D0
CY       BIT   PSW.7                   ; Carry Flag
AC       BIT   PSW.6                   ; Auxiliary Carry Flag
F0       BIT   PSW.5                   ; User Flag 0
RS1      BIT   PSW.4                   ; Register Bank Select 1
RS0      BIT   PSW.3                   ; Register Bank Select 0
OV       BIT   PSW.2                   ; Overflow Flag
F1       BIT   PSW.1                   ; User Flag 1
P        BIT   PSW.0                   ; Accumulator Parity Flag

; PCA0CN 0D8
CF       BIT   PCA0CN.7                ; PCA0 Counter Overflow Flag
CR       BIT   PCA0CN.6                ; PCA0 Counter Run Control Bit
CCF5     BIT   PCA0CN.5                ; PCA0 Module 5 Interrupt Flag
CCF4     BIT   PCA0CN.4                ; PCA0 Module 4 Interrupt Flag
CCF3     BIT   PCA0CN.3                ; PCA0 Module 3 Interrupt Flag
CCF2     BIT   PCA0CN.2                ; PCA0 Module 2 Interrupt Flag
CCF1     BIT   PCA0CN.1                ; PCA0 Module 1 Interrupt Flag
CCF0     BIT   PCA0CN.0                ; PCA0 Module 0 Interrupt Flag

; ADC0CN 0E8
AD0EN    BIT   ADC0CN.7                   ; ADC0 Enable
BURSTEN  BIT   ADC0CN.6                ; ADC0 Burst Enable
AD0INT   BIT   ADC0CN.5                ; ADC0 EOC Interrupt Flag
AD0BUSY  BIT   ADC0CN.4                ; ADC0 Busy Flag
AD0WINT  BIT   ADC0CN.3                ; ADC0 Window Interrupt Flag
AD0CM2   BIT   ADC0CN.2                ; ADC0 Convert Start Mode Bit 2
AD0CM1   BIT   ADC0CN.1                ; ADC0 Convert Start Mode Bit 1
AD0CM0   BIT   ADC0CN.0                ; ADC0 Convert Start Mode Bit 0

; SPI0CN 0F8H
SPIF0    BIT   SPI0CN.7                ; SPI0 Interrupt Flag
WCOL0    BIT   SPI0CN.6                ; SPI0 Write Collision Flag
MODF0    BIT   SPI0CN.5                ; SPI0 Mode Fault Flag
RXOVRN0  BIT   SPI0CN.4                ; SPI0 RX Overrun Flag
NSS0MD1  BIT   SPI0CN.3                ; SPI0 Slave Select Mode 1
NSS0MD0  BIT   SPI0CN.2                ; SPI0 Slave Select Mode 0
TXBMT0   BIT   SPI0CN.1                ; SPI0 TX Buffer Empty Flag
SPI0EN   BIT   SPI0CN.0                ; SPI0 Enable

; SPI1CN 0F8H
SPIF1    BIT   SPI1CN.7                ; SPI1 Interrupt Flag
WCOL1    BIT   SPI1CN.6                ; SPI1 Write Collision Flag
MODF1    BIT   SPI1CN.5                ; SPI1 Mode Fault Flag
RXOVRN1  BIT   SPI1CN.4                ; SPI1 RX Overrun Flag
NSS1MD1  BIT   SPI1CN.3                ; SPI1 Slave Select Mode 1
NSS1MD0  BIT   SPI1CN.2                ; SPI1 Slave Select Mode 0
TXBMT1   BIT   SPI1CN.1                ; SPI1 TX Buffer Empty Flag
SPI1EN   BIT   SPI1CN.0                ; SPI1 Enable

;-----------------------------------------------------------------------------
; Interrupt Priorities
;-----------------------------------------------------------------------------

INTERRUPT_INT0             EQU   0     ; External Interrupt 0
INTERRUPT_TIMER0           EQU   1     ; Timer0 Overflow
INTERRUPT_INT1             EQU   2     ; External Interrupt 1
INTERRUPT_TIMER1           EQU   3     ; Timer1 Overflow
INTERRUPT_UART0            EQU   4     ; Serial Port 0
INTERRUPT_TIMER2           EQU   5     ; Timer2 Overflow
INTERRUPT_SPI0             EQU   6     ; Serial Peripheral Interface 0
INTERRUPT_SMBUS0           EQU   7     ; SMBus0 Interface
INTERRUPT_RTC0ALARM        EQU   8     ; RTC0 (SmaRTClock) Alarm
INTERRUPT_ADC0_WINDOW      EQU   9     ; ADC0 Window Comparison
INTERRUPT_ADC0_EOC         EQU   10    ; ADC0 End Of Conversion
INTERRUPT_PCA0             EQU   11    ; PCA0 Peripheral
INTERRUPT_COMPARATOR0      EQU   12    ; Comparator0
INTERRUPT_COMPARATOR1      EQU   13    ; Comparator1
INTERRUPT_TIMER3           EQU   14    ; Timer3 Overflow
INTERRUPT_VDDMON           EQU   15    ; VDD Monitor Early Warning
INTERRUPT_PORT_MATCH       EQU   16    ; Port Match
INTERRUPT_RTC0_OSC_FAIL    EQU   17    ; RTC0 (smaRTClock) Oscillator Fail
INTERRUPT_SPI1             EQU   18    ; Serial Peripheral Interface 1
INTERRUPT_PC0              EQU   19    ; Pulse Counter 0
INTERRUPT_DMA0             EQU   20    ; Direct Memory Access 0
INTERRUPT_ENC0             EQU   21    ; Encoder/Decoder 0
INTERRUPT_AES0             EQU   22    ; Advanced Encryption Standard 0

;-----------------------------------------------------------------------------
; SFR Page Equates
;-----------------------------------------------------------------------------
LEGACY_PAGE    EQU   000H              ; LEGACY SFR PAGE
DPPE_PAGE      EQU   002H              ; DPPE SFR PAGE
DMA0_PAGE      EQU   002H              ; DMA0 SFR PAGE
AES0_PAGE      EQU   002H              ; AES0 SFR PAGE
ENC0_PAGE      EQU   002H              ; ENC0 SFR PAGE
CRC1_PAGE      EQU   002H              ; CRC1 SFR PAGE
SPI1_PAGE      EQU   002H              ; SPI1 SFR PAGE
LCD0_PAGE      EQU   002H              ; LCD0 SFR PAGE
CONFIG_PAGE    EQU   00FH              ; SYSTEM AND PORT CONFIGURATION PAGE
CRC0_PAGE      EQU   00FH              ; CRC0
TOFF_PAGE      EQU   00FH              ; TEMPERATURE SENSOR OFFSET PAGE
;-----------------------------------------------------------------------------
; Indirect RTC Register Addresses
;-----------------------------------------------------------------------------
CAPTURE0       EQU   000H              ; RTC address of CAPTURE0 register
CAPTURE1       EQU   001H              ; RTC address of CAPTURE1 register
CAPTURE2       EQU   002H              ; RTC address of CAPTURE2 register
CAPTURE3       EQU   003H              ; RTC address of CAPTURE3 register
RTC0CN         EQU   004H              ; RTC address of RTC0CN register
RTC0XCN        EQU   005H              ; RTC address of RTC0XCN register
RTC0XCF        EQU   006H              ; RTC address of RTC0XCF register
RTC0CF         EQU   007H              ; RTC address of RTC0CF register
ALARM0B0       EQU   008H              ; RTC address of ALARM0 Byte 0
ALARM0B1       EQU   009H              ; RTC address of ALARM0 Byte 1
ALARM0B2       EQU   00AH              ; RTC address of ALARM0 Byte 2
ALARM0B3       EQU   00BH              ; RTC address of ALARM0 Byte 3
ALARM1B0       EQU   00CH              ; RTC address of ALARM1 Byte 0
ALARM1B1       EQU   00DH              ; RTC address of ALARM1 Byte 1
ALARM1B2       EQU   00EH              ; RTC address of ALARM1 Byte 2
ALARM1B3       EQU   00FH              ; RTC address of ALARM1 Byte 3
ALARM2B0       EQU   010H              ; RTC address of ALARM2 Byte 0
ALARM2B1       EQU   011H              ; RTC address of ALARM2 Byte 1
ALARM2B2       EQU   012H              ; RTC address of ALARM2 Byte 2
ALARM2B3       EQU   013H              ; RTC address of ALARM2 Byte 3

;-----------------------------------------------------------------------------
; End Of File
;-----------------------------------------------------------------------------