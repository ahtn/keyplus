;-----------------------------------------------------------------------------
; C8051F360.INC
;-----------------------------------------------------------------------------
; Copyright 2006 Silicon Laboratories, Inc.
; http://www.silabs.com
;
; Program Description:
;
; Register/bit definitions for the C8051F36x/F37x product family.
;
;
; FID:
; Target:         C8051F360, F361, F362, F363, F364, F365, F366, F367, F368
;                 C8051F370, F371, F372, F373
; Tool chain:     Keil
; Command Line:   None
;
;
; Release 1.0
;    -Initial Release (TP)
;    -29 MAR 2006
;

;-----------------------------------------------------------------------------
; Byte Registers
;-----------------------------------------------------------------------------

P0          DATA     080H              ; Port 0 latch
SP          DATA     081H              ; Stack pointer
DPL         DATA     082H              ; Data pointer low
DPH         DATA     083H              ; Data pointer high
CCH0CN      DATA     084H              ; Cache control
SFRNEXT     DATA     085H              ; SFR stack next page
SFRLAST     DATA     086H              ; SFR stack last page
PCON        DATA     087H              ; Power control
TCON        DATA     088H              ; Timer/counter control
TMOD        DATA     089H              ; Timer/counter mode
TL0         DATA     08AH              ; Timer/counter 0 low
TL1         DATA     08BH              ; Timer/counter 1 low
TH0         DATA     08CH              ; Timer/counter 0 high
TH1         DATA     08DH              ; Timer/counter 1 high
CKCON       DATA     08EH              ; Clock control
PSCTL       DATA     08FH              ; Program store R/W control
CLKSEL      DATA     08FH              ; Clock select
P1          DATA     090H              ; Port 1 latch
TMR3CN      DATA     091H              ; Timer/counter 3 control
TMR3RLL     DATA     092H              ; Timer/counter 3 reload low
TMR3RLH     DATA     093H              ; Timer/counter 3 reload high
TMR3L       DATA     094H              ; Timer/counter 3 low
TMR3H       DATA     095H              ; Timer/counter 3 high
IDA0L       DATA     096H              ; Current mode DAC0 low
IDA0H       DATA     097H              ; Current mode DAC0 high
SCON0       DATA     098H              ; UART0 control
SBUF0       DATA     099H              ; UART0 data buffer
CPT1CN      DATA     09AH              ; Comparator1 control
CPT0CN      DATA     09BH              ; Comparator0 control
CPT1MD      DATA     09CH              ; Comparator1 mode selection
CPT0MD      DATA     09DH              ; Comparator0 mode selection
CPT1MX      DATA     09EH              ; Comparator1 mux selection
CPT0MX      DATA     09FH              ; Comparator0 mux selection
P2          DATA     0A0H              ; Port 2 latch
SPI0CFG     DATA     0A1H              ; SPI0 configuration
SPI0CKR     DATA     0A2H              ; SPI0 clock rate control
SPI0DAT     DATA     0A3H              ; SPI0 data
MAC0AL      DATA     0A4H              ; MAC0 A register low byte
P0MDOUT     DATA     0A4H              ; Port 0 output mode configuration
MAC0AH      DATA     0A5H              ; MAC0 A register high byte
P1MDOUT     DATA     0A5H              ; Port 1 output mode configuration
P2MDOUT     DATA     0A6H              ; Port 2 output mode configuration
SFRPAGE     DATA     0A7H              ; SFR page select
IE          DATA     0A8H              ; Interrupt enable
PLL0DIV     DATA     0A9H              ; PLL divider
EMI0CN      DATA     0AAH              ; External memory interface control
FLSTAT      DATA     0ACH              ; Flash status
OSCLCN      DATA     0ADH              ; Low-frequency oscillator control
MAC0RNDL    DATA     0AEH              ; MAC0 rounding register low byte
P4MDOUT     DATA     0AEH              ; Port 4 output mode configuration
MAC0RNDH    DATA     0AFH              ; MAC0 rounding register high byte
P3MDOUT     DATA     0AFH              ; Port 3 output mode configuration
P3          DATA     0B0H              ; Port 3 latch
P2MAT       DATA     0B1H              ; Port 2 match
PLL0MUL     DATA     0B1H              ; PLL multiplier
P2MASK      DATA     0B2H              ; Port 2 mask
PLL0FLT     DATA     0B2H              ; PLL filter
PLL0CN      DATA     0B3H              ; PLL control
P4          DATA     0B5H              ; Port 4 latch
FLSCL       DATA     0B6H              ; Flash scale
OSCXCN      DATA     0B6H              ; External oscillator control
FLKEY       DATA     0B7H              ; Flash lock and key
OSCICN      DATA     0B7H              ; Internal oscillator control
IP          DATA     0B8H              ; Interrupt priority
IDA0CN      DATA     0B9H              ; Current mode DAC0 control
AMX0N       DATA     0BAH              ; AMUX0 negative channel select
AMX0P       DATA     0BBH              ; AMUX0 positive channel select
ADC0CF      DATA     0BCH              ; ADC0 configuration
ADC0L       DATA     0BDH              ; ADC0 data low
ADC0H       DATA     0BEH              ; ADC0 data high
OSCICL      DATA     0BFH              ; Internal oscillator calibration
SMB0CN      DATA     0C0H              ; SMBus0 control
SMB0CF      DATA     0C1H              ; SMBus0 configuration
SMB0DAT     DATA     0C2H              ; SMBus0 data
ADC0GTL     DATA     0C3H              ; ADC0 window greater than low byte
ADC0GTH     DATA     0C4H              ; ADC0 window greater than high byte
ADC0LTL     DATA     0C5H              ; ADC0 window less than low byte
ADC0LTH     DATA     0C6H              ; ADC0 window less than high byte
ONESHOT     DATA     0C7H              ; Flash oneshot timing
EMI0CF      DATA     0C7H              ; EMIF configuration
TMR2CN      DATA     0C8H              ; Timer/counter 2 control
CCH0TN      DATA     0C9H              ; Cache tuning
TMR2RLL     DATA     0CAH              ; Timer/counter 2 reload low
TMR2RLH     DATA     0CBH              ; Timer/counter 2 reload high
TMR2L       DATA     0CCH              ; Timer/counter 2 low
TMR2H       DATA     0CDH              ; Timer/counter 2 high
EIP1        DATA     0CEH              ; Extended interrupt priority 1
MAC0STA     DATA     0CFH              ; MAC0 status
EIP2        DATA     0CFH              ; Extended interrupt priority 2
PSW         DATA     0D0H              ; Program status word
REF0CN      DATA     0D1H              ; Voltage reference control
MAC0ACC0    DATA     0D2H              ; MAC0 accumulator byte 0
CCH0LC      DATA     0D2H              ; Cache lock
MAC0ACC1    DATA     0D3H              ; MAC0 accumulator byte 1
CCH0MA      DATA     0D3H              ; Cache miss accumulator
MAC0ACC2    DATA     0D4H              ; MAC0 accumulator byte 2
P0SKIP      DATA     0D4H              ; Port 0 skip
MAC0ACC3    DATA     0D5H              ; MAC0 accumulator byte 3
P1SKIP      DATA     0D5H              ; Port 1 skip
MAC0OVR     DATA     0D6H              ; MAC0 accumulator overflow byte
P2SKIP      DATA     0D6H              ; Port 2 skip
MAC0CF      DATA     0D7H              ; MAC0 configuration register
P3SKIP      DATA     0D7H              ; Port 3 skip
PCA0CN      DATA     0D8H              ; PCA0 control
PCA0MD      DATA     0D9H              ; PCA0 mode
PCA0CPM0    DATA     0DAH              ; PCA0 module 0 mode
PCA0CPM1    DATA     0DBH              ; PCA0 module 1 mode
PCA0CPM2    DATA     0DCH              ; PCA0 module 2 mode
PCA0CPM3    DATA     0DDH              ; PCA0 module 3 mode
PCA0CPM4    DATA     0DEH              ; PCA0 module 4 mode
PCA0CPM5    DATA     0DFH              ; PCA0 module 5 mode
ACC         DATA     0E0H              ; Accumulator
P1MAT       DATA     0E1H              ; Port 1 match
XBR0        DATA     0E1H              ; Port I/O crossbar control 0
P1MASK      DATA     0E2H              ; Port 1 mask
XBR1        DATA     0E2H              ; Port I/O crossbar control 1
IT01CF      DATA     0E4H              ; INT0/INT1 configuration
SFR0CN      DATA     0E5H              ; SFR page control
EIE1        DATA     0E6H              ; Extended interrupt enable 1
EIE2        DATA     0E7H              ; Extended interrupt enable 2
ADC0CN      DATA     0E8H              ; ADC0 control
PCA0CPL1    DATA     0E9H              ; PCA0 module 1 capture low
PCA0CPH1    DATA     0EAH              ; PCA0 module 1 capture high
PCA0CPL2    DATA     0EBH              ; PCA0 module 2 capture low
PCA0CPH2    DATA     0ECH              ; PCA0 module 2 capture high
PCA0CPL3    DATA     0EDH              ; PCA0 module 3 capture low
PCA0CPH3    DATA     0EEH              ; PCA0 module 3 capture high
RSTSRC      DATA     0EFH              ; Reset source configuration/status
B           DATA     0F0H              ; B register
MAC0BL      DATA     0F1H              ; MAC0 B register low byte
P0MDIN      DATA     0F1H              ; Port 0 input mode configuration
MAC0BH      DATA     0F2H              ; MAC0 B register high byte
P1MDIN      DATA     0F2H              ; Port 1 input mode configuration
P0MAT       DATA     0F3H              ; Port 0 match
P2MDIN      DATA     0F3H              ; Port 2 input mode configuration
P0MASK      DATA     0F4H              ; Port 0 mask
P3MDIN      DATA     0F4H              ; Port 3 input mode configuration
PCA0CPL5    DATA     0F5H              ; PCA0 module 5 capture low
PCA0CPH5    DATA     0F6H              ; PCA0 module 5 capture high
EMI0TC      DATA     0F7H              ; EMIF timing control
SPI0CN      DATA     0F8H              ; SPI0 control
PCA0L       DATA     0F9H              ; PCA0 counter low
PCA0H       DATA     0FAH              ; PCA0 counter high
PCA0CPL0    DATA     0FBH              ; PCA0 module 0 capture low
PCA0CPH0    DATA     0FCH              ; PCA0 module 0 capture high
PCA0CPL4    DATA     0FDH              ; PCA0 module 4 capture low
PCA0CPH4    DATA     0FEH              ; PCA0 module 4 capture high
VDM0CN      DATA     0FFH              ; VDD monitor control

;-----------------------------------------------------------------------------
; Bit Definitions
;-----------------------------------------------------------------------------

; TCON 088
TF1     BIT     TCON.7                 ; Timer 1 overflow flag
TR1     BIT     TCON.6                 ; Timer 1 on/off control
TF0     BIT     TCON.5                 ; Timer 0 overflow flag
TR0     BIT     TCON.4                 ; Timer 0 on/off control
IE1     BIT     TCON.3                 ; Ext. Interrupt 1 edge flag
IT1     BIT     TCON.2                 ; Ext. Interrupt 1 type
IE0     BIT     TCON.1                 ; Ext. Interrupt 0 edge flag
IT0     BIT     TCON.0                 ; Ext. Interrupt 0 type

; SCON0 0x98
S0MODE  BIT     SCON0.7                ; UART0 mode
                                       ; Bit 6 Unused
MCE0    BIT     SCON0.5                ; UART0 mce
REN0    BIT     SCON0.4                ; UART0 RX enable
TB80    BIT     SCON0.3                ; UART0 TX bit 8
RB80    BIT     SCON0.2                ; UART0 RX bit 8
TI0     BIT     SCON0.1                ; UART0 TX interrupt flag
RI0     BIT     SCON0.0                ; UART0 RX interrupt flag

; IE 0xA8
EA      BIT     IE.7                   ; Global interrupt enable
ESPI0   BIT     IE.6                   ; SPI0 interrupt enable
ET2     BIT     IE.5                   ; Timer 2 interrupt enable
ES0     BIT     IE.4                   ; UART0 interrupt enable
ET1     BIT     IE.3                   ; Timer 1 interrupt enable
EX1     BIT     IE.2                   ; External interrupt 1 enable
ET0     BIT     IE.1                   ; Timer 0 interrupt enable
EX0     BIT     IE.0                   ; External interrupt 0 enable

; IP 0xB8
                                       ; Bit 7 Unused
PSPI0   BIT     IP.6                   ; SPI0 priority
PT2     BIT     IP.6                   ; Timer 2 priority
PS0     BIT     IP.6                   ; UART0 priority
PT1     BIT     IP.6                   ; Timer 1 priority
PX1     BIT     IP.6                   ; External interrupt 1 priority
PT0     BIT     IP.6                   ; Timer 0 priority
PX0     BIT     IP.6                   ; External interrupt 0 priority

; SMB0CN 0xC0
MASTER  BIT     SMB0CN.7               ; SMBus0 master/slave
TXMODE  BIT     SMB0CN.6               ; SMBus0 transmit mode
STA     BIT     SMB0CN.5               ; SMBus0 start flag
STO     BIT     SMB0CN.4               ; SMBus0 stop flag
ACKRQ   BIT     SMB0CN.3               ; SMBus0 acknowledge request
ARBLOST BIT     SMB0CN.2               ; SMBus0 arbitration lost
ACK     BIT     SMB0CN.1               ; SMBus0 acknowledge flag
SI      BIT     SMB0CN.0               ; SMBus0 interrupt pending flag

; TMR2CN 0xC8
TF2H    BIT     TMR2CN.7               ; Timer 2 high byte overflow flag
TF2L    BIT     TMR2CN.6               ; Timer 2 low byte overflow flag
TF2LEN  BIT     TMR2CN.5               ; Timer 2 low byte interrupt enable
TF2CEN  BIT     TMR2CN.4               ; Timer 2 capture enable
T2SPLIT BIT     TMR2CN.3               ; Timer 2 split mode enable
TR2     BIT     TMR2CN.2               ; Timer 2 on/off control
                                       ; Bit 1 Unused
T2XCLK  BIT     TMR2CN.0               ; Timer 2 external clock select

; PSW 0xD0
CY      BIT     PSW.7                  ; Carry flag
AC      BIT     PSW.6                  ; Auxiliary carry flag
F0      BIT     PSW.5                  ; User flag 0
RS1     BIT     PSW.4                  ; Register bank select 1
RS0     BIT     PSW.3                  ; Register bank select 0
OV      BIT     PSW.2                  ; Overflow flag
F1      BIT     PSW.1                  ; User flag 1
P       BIT     PSW.0                  ; Accumulator parity flag

; PCA0CN 0xD8
CF      BIT     PCA0CN.7               ; PCA0 counter overflow flag
CR      BIT     PCA0CN.6               ; PCA0 counter run control bit
CCF5    BIT     PCA0CN.5               ; PCA0 module 5 interrupt flag
CCF4    BIT     PCA0CN.4               ; PCA0 module 4 interrupt flag
CCF3    BIT     PCA0CN.3               ; PCA0 module 3 interrupt flag
CCF2    BIT     PCA0CN.2               ; PCA0 module 2 interrupt flag
CCF1    BIT     PCA0CN.1               ; PCA0 module 1 interrupt flag
CCF0    BIT     PCA0CN.0               ; PCA0 module 0 interrupt flag

; ADC0CN 0xE8
AD0EN   BIT     ADC0CN.7               ; ADC0 enable
AD0TM   BIT     ADC0CN.6               ; ADC0 track mode
AD0INT  BIT     ADC0CN.5               ; ADC0 conv. complete interrupt flag
AD0BUSY BIT     ADC0CN.4               ; ADC0 busy flag
AD0WINT BIT     ADC0CN.3               ; ADC0 window compare interrupt flag
AD0CM2  BIT     ADC0CN.2               ; ADC0 conversion mode select 2
AD0CM1  BIT     ADC0CN.1               ; ADC0 conversion mode select 1
AD0CM0  BIT     ADC0CN.0               ; ADC0 conversion mode select 0

; SPI0CN 0xF8
SPIF    BIT     SPI0CN.7               ; SPI0 interrupt flag
WCOL    BIT     SPI0CN.6               ; SPI0 write collision flag
MODF    BIT     SPI0CN.5               ; SPI0 mode fault flag
RXOVRN  BIT     SPI0CN.4               ; SPI0 RX overrun flag
NSSMD1  BIT     SPI0CN.3               ; SPI0 slave select mode 1
NSSMD0  BIT     SPI0CN.2               ; SPI0 slave select mode 0
TXBMT   BIT     SPI0CN.1               ; SPI0 TX buffer empty flag
SPIEN   BIT     SPI0CN.0               ; SPI0 SPI0 enable

;-----------------------------------------------------------------------------
; SFR Page Definitions
;-----------------------------------------------------------------------------

CONFIG_PAGE                 EQU 0FH    ; SYSTEM AND PORT CONFIGURATION PAGE
LEGACY_PAGE                 EQU 00H    ; LEGACY  PAGE
TIMER01_PAGE                EQU 00H    ; TIMER 0 AND TIMER 1
CPT0_PAGE                   EQU 00H    ; COMPARATOR 0
CPT1_PAGE                   EQU 00H    ; COMPARATOR 1
UART0_PAGE                  EQU 00H    ; UART 0
SPI0_PAGE                   EQU 00H    ; SPI 0
EMI0_PAGE                   EQU 0FH    ; EXTERNAL MEMORY INTERFACE
ADC0_PAGE                   EQU 00H    ; ADC 0
SMB0_PAGE                   EQU 00H    ; SMBUS 0
TMR2_PAGE                   EQU 00H    ; TIMER 2
TMR3_PAGE                   EQU 00H    ; TIMER 3
DAC0_PAGE                   EQU 00H    ; DAC 0
PCA0_PAGE                   EQU 00H    ; PCA 0
PLL0_PAGE                   EQU 0FH    ; PLL 0
MAC0_PAGE                   EQU 00H    ; MAC 0
MATCH_PAGE                  EQU 00H    ; PORT0, PORT1, PORT2 MATCH

;-----------------------------------------------------------------------------
; End Of File
;-----------------------------------------------------------------------------