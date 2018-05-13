;------------------------------------------------------------------------------
; C8051F320.INC
;------------------------------------------------------------------------------
; Copyright 2005 Silicon Laboratories, Inc.
; http://www.silabs.com
;
; Program Description:
;
; Register/bit definitions for the C8051F32x family.
;
;
; FID:            32X000009
; Target:         C8051F320, 'F321
; Tool chain:     Keil
; Command Line:   None
;
; Release 1.5
;    -All changes by PKC
;    -13 DEC 2005
;    -Added T2SOF to TMR2CN bit definition
;    -Changed formatting
;
; Release 1.4
;    -Added 'ESPI0' and 'PSPI0'
;

;------------------------------------------------------------------------------
; Byte Registers
;------------------------------------------------------------------------------

P0       DATA  080H                    ; Port 0
SP       DATA  081H                    ; Stack Pointer
DPL      DATA  082H                    ; Data pointer - Low byte
DPH      DATA  083H                    ; Data pointer - High byte
PCON     DATA  087H                    ; Power control
TCON     DATA  088H                    ; Timer control
TMOD     DATA  089H                    ; Timer mode
TL0      DATA  08AH                    ; Timer0 - Low byte
TL1      DATA  08BH                    ; Timer1 - Low byte
TH0      DATA  08CH                    ; Timer0 - High byte
TH1      DATA  08DH                    ; Timer1 - High byte
CKCON    DATA  08EH                    ; Clock control register
PSCTL    DATA  08FH                    ; Program store r/w control
P1       DATA  090H                    ; Port1
TMR3CN   DATA  091H                    ; Timer3 control register
TMR3RLL  DATA  092H                    ; Timer3 reload register - Low byte
TMR3RLH  DATA  093H                    ; Timer3 reload register - High byte
TMR3L    DATA  094H                    ; Timer3 - Low byte
TMR3H    DATA  095H                    ; Timer3 - High byte
USB0ADR  DATA  096H                    ; USB0 address port
USB0DAT  DATA  097H                    ; USB0 data port
SCON0    DATA  098H                    ; UART0 control register
SBUF0    DATA  099H                    ; UART0 data buffer register
CPT1CN   DATA  09AH                    ; Comparator1 control register
CPT0CN   DATA  09BH                    ; Comparator0 control register
CPT1MD   DATA  09CH                    ; Comparator1 mode selection register
CPT0MD   DATA  09DH                    ; Comparator0 mode selection register
CPT1MX   DATA  09EH                    ; Comparator1 mux selection register
CPT0MX   DATA  09FH                    ; Comparator0 mux selection register
P2       DATA  0A0H                    ; Port2
SPI0CFG  DATA  0A1H                    ; SPI0 configuration register
SPI0CKR  DATA  0A2H                    ; SPI0 clock configuration register
SPI0DAT  DATA  0A3H                    ; SPI0 data register
P0MDOUT  DATA  0A4H                    ; Port0 output mode register
P1MDOUT  DATA  0A5H                    ; Port1 output mode register
P2MDOUT  DATA  0A6H                    ; Port2 output mode register
P3MDOUT  DATA  0A7H                    ; Port3 output mode register
IE       DATA  0A8H                    ; Interrupt enable
CLKSEL   DATA  0A9H                    ; Clock source select
EMI0CN   DATA  0AAH                    ; External Memory Interface Control
P3       DATA  0B0H                    ; Port3
OSCXCN   DATA  0B1H                    ; External oscillator control
OSCICN   DATA  0B2H                    ; Internal oscillator control
OSCICL   DATA  0B3H                    ; Internal oscillator calibration
FLSCL    DATA  0B6H                    ; Flash scale register
FLKEY    DATA  0B7H                    ; Flash lock & key register
IP       DATA  0B8H                    ; Interrupt priority
CLKMUL   DATA  0B9H                    ; Clock multiplier control register
AMX0N    DATA  0BAH                    ; ADC0 mux negative channel selection
AMX0P    DATA  0BBH                    ; ADC0 mux positive channel selection
ADC0CF   DATA  0BCH                    ; ADC0 configuration
ADC0L    DATA  0BDH                    ; ADC0 data low
ADC0H    DATA  0BEH                    ; ADC0 data high
SMB0CN   DATA  0C0H                    ; SMBus control
SMB0CF   DATA  0C1H                    ; SMBus configuration
SMB0DAT  DATA  0C2H                    ; SMBus data
ADC0GTL  DATA  0C3H                    ; ADC0 greater-than data low register
ADC0GTH  DATA  0C4H                    ; ADC0 greater-than data high register
ADC0LTL  DATA  0C5H                    ; ADC0 less-than data low register
ADC0LTH  DATA  0C6H                    ; ADC0 less-than data high register
TMR2CN   DATA  0C8H                    ; Timer2 control register
REG0CN   DATA  0C9H                    ; Regulator control register
TMR2RLL  DATA  0CAH                    ; Timer2 reload register - Low byte
TMR2RLH  DATA  0CBH                    ; Timer2 reload register - High byte
TMR2L    DATA  0CCH                    ; Timer2 - Low byte
TMR2H    DATA  0CDH                    ; Timer2 - High byte
PSW      DATA  0D0H                    ; Program Status Word
REF0CN   DATA  0D1H                    ; Voltage reference control register
P0SKIP   DATA  0D4H                    ; Port0 crossbar skip register
P1SKIP   DATA  0D5H                    ; Port1 crossbar skip register
P2SKIP   DATA  0D6H                    ; Port2 crossbar skip register
USB0XCN  DATA  0D7H                    ; USB0 tranceiver control register
PCA0CN   DATA  0D8H                    ; PCA0 control register
PCA0MD   DATA  0D9H                    ; PCA0 mode register
PCA0CPM0 DATA  0DAH                    ; Capture/compare module0 mode
PCA0CPM1 DATA  0DBH                    ; Capture/compare module1 mode
PCA0CPM2 DATA  0DCH                    ; Capture/compare module2 mode
PCA0CPM3 DATA  0DDH                    ; Capture/compare module3 mode
PCA0CPM4 DATA  0DEH                    ; Capture/compare module4 mode
ACC      DATA  0E0H                    ; Accumulator
XBR0     DATA  0E1H                    ; Port I/O crossbar register 0
XBR1     DATA  0E2H                    ; Port I/O crossbar register 1
IT01CF   DATA  0E4H                    ; Int0/int1 configuration register
EIE1     DATA  0E6H                    ; Extended interrupt enable 1
EIE2     DATA  0E7H                    ; Extended interrupt enable 2
ADC0CN   DATA  0E8H                    ; ADC0 control register
PCA0CPL1 DATA  0E9H                    ; Capture/compare module1 - Low byte
PCA0CPH1 DATA  0EAH                    ; Capture/compare module1 - High byte
PCA0CPL2 DATA  0EBH                    ; Capture/compare module2 - Low byte
PCA0CPH2 DATA  0ECH                    ; Capture/compare module2 - High byte
PCA0CPL3 DATA  0EDH                    ; Capture/compare module3 - Low byte
PCA0CPH3 DATA  0EEH                    ; Capture/compare module3 - High byte
RSTSRC   DATA  0EFH                    ; Reset source register
B        DATA  0F0H                    ; B register
P0MDIN   DATA  0F1H                    ; Port0 input mode register
P1MDIN   DATA  0F2H                    ; Port1 input mode register
P2MDIN   DATA  0F3H                    ; Port2 input mode register
P3MDIN   DATA  0F4H                    ; Port3 input mode register
EIP1     DATA  0F6H                    ; Extended interrupt priority 1
EIP2     DATA  0F7H                    ; Extended interrupt priority 2
SPI0CN   DATA  0F8H                    ; SPI0 control register
PCA0L    DATA  0F9H                    ; PCA0 counter/timer - Low byte
PCA0H    DATA  0FAH                    ; PCA0 counter/timer - High byte
PCA0CPL0 DATA  0FBH                    ; Capture/compare module0 - Low byte
PCA0CPH0 DATA  0FCH                    ; Capture/compare module0 - High byte
PCA0CPL4 DATA  0FDH                    ; Capture/compare module4 - Low byte
PCA0CPH4 DATA  0FEH                    ; Capture/compare module4 - High byte
VDM0CN   DATA  0FFH                    ; Vdd monitor control

;------------------------------------------------------------------------------
; Bit Definitions
;------------------------------------------------------------------------------

; TCON 88H
TF1      BIT   TCON.7                  ; Timer1 overflow flag
TR1      BIT   TCON.6                  ; Timer1 on/off control
TF0      BIT   TCON.5                  ; Timer0 overflow flag
TR0      BIT   TCON.4                  ; Timer0 on/off control
IE1      BIT   TCON.3                  ; Ext interrupt 1 edge flag
IT1      BIT   TCON.2                  ; Ext interrupt 1 type
IE0      BIT   TCON.1                  ; Ext interrupt 0 edge flag
IT0      BIT   TCON.0                  ; Ext interrupt 0 type

; SCON0  0x98
S0MODE   BIT   SCON0.7                 ; Serial mode control bit 0
                                       ; Bit6 UNUSED
MCE0     BIT   SCON0.5                 ; Multiprocessor communication enable
REN0     BIT   SCON0.4                 ; Receive enable
TB80     BIT   SCON0.3                 ; Transmit bit 8
RB80     BIT   SCON0.2                 ; Receive bit 8
TI0      BIT   SCON0.1                 ; Transmit interrupt flag
RI0      BIT   SCON0.0                 ; Receive interrupt flag

; IE  0xA8
EA       BIT   IE.7                    ; Global interrupt enable
ESPI0    BIT   IE.6                    ; SPI0 interrupt enable
ET2      BIT   IE.5                    ; Timer2 interrupt enable
ES0      BIT   IE.4                    ; UART0 interrupt enable
ET1      BIT   IE.3                    ; Timer1 interrupt enable
EX1      BIT   IE.2                    ; External interrupt 1 enable
ET0      BIT   IE.1                    ; Timer0 interrupt enable
EX0      BIT   IE.0                    ; External interrupt 0 enable

; IP  0xB8
                                       ; Bit7 UNUSED
PSPI0    BIT   IP.6                    ; SPI0 interrupt priority
PT2      BIT   IP.5                    ; Timer2 priority
PS0      BIT   IP.4                    ; UART0 priority
PT1      BIT   IP.3                    ; Timer1 priority
PX1      BIT   IP.2                    ; External interrupt 1 priority
PT0      BIT   IP.1                    ; Timer0 priority
PX0      BIT   IP.0                    ; External interrupt 0 priority

; SMB0CN 0xC0
MASTER   BIT   SMB0CN.7                ; Master/slave indicator
TXMODE   BIT   SMB0CN.6                ; Transmit mode indicator
STA      BIT   SMB0CN.5                ; Start flag
STO      BIT   SMB0CN.4                ; Stop flag
ACKRQ    BIT   SMB0CN.3                ; Acknowledge request
ARBLOST  BIT   SMB0CN.2                ; Arbitration lost indicator
ACK      BIT   SMB0CN.1                ; Acknowledge flag
SI       BIT   SMB0CN.0                ; SMBus interrupt flag

; TMR2CN 0xC8
TF2H     BIT   TMR2CN.7                ; Timer2 high byte overflow flag
TF2L     BIT   TMR2CN.6                ; Timer2 low byte overflow flag
TF2LEN   BIT   TMR2CN.5                ; Timer2 low byte interrupt enable
T2SOF    BIT   TMR2CN.4                ; Timer2 start-of-frame capture enable
T2SPLIT  BIT   TMR2CN.3                ; Timer2 split mode enable
TR2      BIT   TMR2CN.2                ; Timer2 on/off control
                                       ; Bit1 UNUSED
T2XCLK   BIT   TMR2CN.0                ; Timer2 external clock select

; PSW 0xD0
CY       BIT   PSW.7                   ; Carry flag
AC       BIT   PSW.6                   ; Auxiliary carry flag
F0       BIT   PSW.5                   ; User flag 0
RS1      BIT   PSW.4                   ; Register bank select 1
RS0      BIT   PSW.3                   ; Register bank select 0
OV       BIT   PSW.2                   ; Overflow flag
F1       BIT   PSW.1                   ; User flag 1
P        BIT   PSW.0                   ; Accumulator parity flag

; PCA0CN 0xD8H
CF       BIT   PCA0CN.7                ; PCA0 counter overflow flag
CR       BIT   PCA0CN.6                ; PCA0 counter run control
                                       ; Bit5 UNUSED
CCF4     BIT   PCA0CN.4                ; PCA0 module4 capture/compare flag
CCF3     BIT   PCA0CN.3                ; PCA0 module3 capture/compare flag
CCF2     BIT   PCA0CN.2                ; PCA0 module2 capture/compare flag
CCF1     BIT   PCA0CN.1                ; PCA0 module1 capture/compare flag
CCF0     BIT   PCA0CN.0                ; PCA0 module0 capture/compare flag

; ADC0CN 0xE8H
AD0EN    BIT   ADC0CN.7                ; ADC0 enable
AD0TM    BIT   ADC0CN.6                ; ADC0 track mode
AD0INT   BIT   ADC0CN.5                ; ADC0 converision complete interrupt flag
AD0BUSY  BIT   ADC0CN.4                ; ADC0 busy flag
AD0WINT  BIT   ADC0CN.3                ; ADC0 window compare interrupt flag
AD0CM2   BIT   ADC0CN.2                ; ADC0 conversion mode select 2
AD0CM1   BIT   ADC0CN.1                ; ADC0 conversion mode select 1
AD0CM0   BIT   ADC0CN.0                ; ADC0 conversion mode select 0

; SPI0CN 0xF8H
SPIF     BIT   SPI0CN.7                ; SPI0 interrupt flag
WCOL     BIT   SPI0CN.6                ; SPI0 write collision flag
MODF     BIT   SPI0CN.5                ; SPI0 mode fault flag
RXOVRN   BIT   SPI0CN.4                ; SPI0 rx overrun flag
NSSMD1   BIT   SPI0CN.3                ; SPI0 slave select mode 1
NSSMD0   BIT   SPI0CN.2                ; SPI0 slave select mode 0
TXBMT    BIT   SPI0CN.1                ; SPI0 transmit buffer empty
SPIEN    BIT   SPI0CN.0                ; SPI0 SPI enable

;------------------------------------------------------------------------------
; End Of File
;------------------------------------------------------------------------------