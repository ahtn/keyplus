;------------------------------------------------------------------------------
; C8051F560.INC
;------------------------------------------------------------------------------
; Copyright 2010, Silicon Laboratories, Inc.
; http://www.silabs.com
;
; Program Description:
;
; Register/bit definitions for the C8051F56x family.
;
; Target:         C8051F550/1/2/3/4/5/6/7
;                 C8051F560/1/2/3/4/5/6/7/8/9
;                 C8051F570/1/2/3/4/5
; Tool chain:     Keil
; Command Line:   None
;
; Release 1.0 - 10 MAR 2010 (GP)
;    -Updated to use EQU instead of #define
;
; Release 0.1 - 22 AUG 2008 (GP)
;    -Initial release

;------------------------------------------------------------------------------
; Page 0 and Page F Registers
;------------------------------------------------------------------------------

P0          DATA 080H                  ; Port 0 Latch
SP          DATA 081H                  ; Stack Pointer
DPL         DATA 082H                  ; Data Pointer Low
DPH         DATA 083H                  ; Data Pointer High
SFR0CN      DATA 084H                  ; SFR Page Control
SFRNEXT     DATA 085H                  ; SFR stack next page
SFRLAST     DATA 086H                  ; SFR stack last page
PCON        DATA 087H                  ; Power Control
TCON        DATA 088H                  ; Timer/Counter Control
TMOD        DATA 089H                  ; Timer/Counter Mode
TL0         DATA 08AH                  ; Timer/Counter 0 Low
TL1         DATA 08BH                  ; Timer/Counter 1 Low
TH0         DATA 08CH                  ; Timer/Counter 0 High
TH1         DATA 08DH                  ; Timer/Counter 1 High
CKCON       DATA 08EH                  ; Clock Control
PSCTL       DATA 08FH                  ; Program Store R/W Control
CLKSEL      DATA 08FH                  ; System clock select
P1          DATA 090H                  ; Port 1 Latch
TMR3CN      DATA 091H                  ; Timer/Counter 3 Control
TMR3RLL     DATA 092H                  ; Timer/Counter 3 Reload Low
TMR3RLH     DATA 093H                  ; Timer/Counter 3 Reload High
TMR3L       DATA 094H                  ; Timer/Counter 3 Low
TMR3H       DATA 095H                  ; Timer/Counter 3 High
CLKMUL      DATA 097H                  ; Clock Multiplier
SCON0       DATA 098H                  ; UART0 Control
SBUF0       DATA 099H                  ; UART0 Data Buffer
CPT0CN      DATA 09AH                  ; Comparator 0 Control
CPT0MD      DATA 09BH                  ; Comparator 0 Mode
CPT0MX      DATA 09CH                  ; Comparator 0 Mux
CPT1CN      DATA 09DH                  ; Comparator 1 Control
CPT1MD      DATA 09EH                  ; Comparator 0 Mode
OSCIFIN     DATA 09EH                  ; Internal Oscillator Fine Control
CPT1MX      DATA 09FH                  ; Comparator 1 Mux
OSCXCN      DATA 09FH                  ; External Oscillator Control
P2          DATA 0A0H                  ; Port 2 Latch
SPI0CFG     DATA 0A1H                  ; SPI0 Configuration
OSCICN      DATA 0A1H                  ; Internal Oscillator Control
SPI0CKR     DATA 0A2H                  ; SPI0 Clock rate control
OSCICRS     DATA 0A2H                  ; Internal Oscillator Coarse Control
SPI0DAT     DATA 0A3H                  ; SPI0 Data Buffer
P0MDOUT     DATA 0A4H                  ; Port 0 Output Mode
P1MDOUT     DATA 0A5H                  ; Port 1 Output Mode
P2MDOUT     DATA 0A6H                  ; Port 2 Output Mode
SFRPAGE     DATA 0A7H                  ; SFR Page Select
IE          DATA 0A8H                  ; Interrupt Enable
SMOD0       DATA 0A9H                  ; Serial Port 0 Control
EMI0CN      DATA 0AAH                  ; EMIF control
EMI0TC      DATA 0AAH                  ; EMIF Timing control
SBCON0      DATA 0ABH                  ; UART0 Baud Rate Generator Control
SBRLL0      DATA 0ACH                  ; UART0 Baud Rate Generator Low
SBRLH0      DATA 0ADH                  ; UART0 Baud Rate Generator High
P3MAT       DATA 0AEH                  ; Port 3 Match
P3MDOUT     DATA 0AEH                  ; Port 3 Mode
P3MASK      DATA 0AFH                  ; Port 3 Mask
P4MDOUT     DATA 0AFH                  ; Port 4 Mode
P3          DATA 0B0H                  ; Port 3 Latch
P2MAT       DATA 0B1H                  ; Port 2 Match
P2MASK      DATA 0B2H                  ; Port 2 Mask
EMI0CF      DATA 0B2H                  ; EMIF Configuration
P4          DATA 0B5H                  ; Port 4 Latch
FLSCL       DATA 0B6H                  ; Flash Scale
FLKEY       DATA 0B7H                  ; Flash access limit
IP          DATA 0B8H                  ; Interrupt Priority
SMB0ADR     DATA 0B9H                  ; SMBus0 Slave address
ADC0TK      DATA 0BAH                  ; ADC0 Tracking Select
SMB0ADM     DATA 0BAH                  ; SMBus0 Address Mask
ADC0MX      DATA 0BBH                  ; AMUX0 Channel select
ADC0CF      DATA 0BCH                  ; AMUX0 Channel configuration
ADC0L       DATA 0BDH                  ; ADC0 Data Low
ADC0H       DATA 0BEH                  ; ADC0 Data High
SMB0CN      DATA 0C0H                  ; SMBus0 Control
SMB0CF      DATA 0C1H                  ; SMBus0 Configuration
SMB0DAT     DATA 0C2H                  ; SMBus0 Data
ADC0GTL     DATA 0C3H                  ; ADC0 Greater-Than Compare Low
ADC0GTH     DATA 0C4H                  ; ADC0 Greater-Than Compare High
ADC0LTL     DATA 0C5H                  ; ADC0 Less-Than Compare Word Low
ADC0LTH     DATA 0C6H                  ; ADC0 Less-Than Compare Word High
XBR2        DATA 0C7H                  ; Port I/O Crossbar Control 2
TMR2CN      DATA 0C8H                  ; Timer/Counter 2 Control
REG0CN      DATA 0C9H                  ; Regulator Control
LIN0CF      DATA 0C9H                  ; LIN 0 Configuration
TMR2RLL     DATA 0CAH                  ; Timer/Counter 2 Reload Low
TMR2RLH     DATA 0CBH                  ; Timer/Counter 2 Reload High
TMR2L       DATA 0CCH                  ; Timer/Counter 2 Low
TMR2H       DATA 0CDH                  ; Timer/Counter 2 High
PCA0CPL5    DATA 0CEH                  ; PCA0 Capture 5 Low
PCA0CPH5    DATA 0CFH                  ; PCA0 Capture 5 High
PSW         DATA 0D0H                  ; Program Status Word
REF0CN      DATA 0D1H                  ; Voltage Reference Control
LIN0DAT     DATA 0D2H                  ; LIN0 Data
LIN0ADR     DATA 0D3H                  ; LIN0 Address
P0SKIP      DATA 0D4H                  ; Port 0 Skip
P1SKIP      DATA 0D5H                  ; Port 1 Skip
P2SKIP      DATA 0D6H                  ; Port 2 Skip
P3SKIP      DATA 0D7H                  ; Port 3 Skip
PCA0CN      DATA 0D8H                  ; PCA0 Control
PCA0MD      DATA 0D9H                  ; PCA0 Mode
PCA0PWM     DATA 0D9H                  ; PCA0 PWM Control
PCA0CPM0    DATA 0DAH                  ; PCA0 Module 0 Mode Register
PCA0CPM1    DATA 0DBH                  ; PCA0 Module 1 Mode Register
PCA0CPM2    DATA 0DCH                  ; PCA0 Module 2 Mode Register
PCA0CPM3    DATA 0DDH                  ; PCA0 Module 3 Mode Register
PCA0CPM4    DATA 0DEH                  ; PCA0 Module 4 Mode Register
PCA0CPM5    DATA 0DFH                  ; PCA0 Module 5 Mode Register
ACC         DATA 0E0H                  ; Accumulator
XBR0        DATA 0E1H                  ; Port I/O Crossbar Control 0
XBR1        DATA 0E2H                  ; Port I/O Crossbar Control 1
CCH0CN      DATA 0E3H                  ; Cache control
IT01CF      DATA 0E4H                  ; INT0/INT1 Configuration
EIE1        DATA 0E6H                  ; Extended Interrupt Enable 2
EIE2        DATA 0E7H                  ; Extended Interrupt Enable 2
ADC0CN      DATA 0E8H                  ; ADC0 Control
PCA0CPL1    DATA 0E9H                  ; PCA0 Capture 2 Low
PCA0CPH1    DATA 0EAH                  ; PCA0 Capture 2 High
PCA0CPL2    DATA 0EBH                  ; PCA0 Capture 3 Low
PCA0CPH2    DATA 0ECH                  ; PCA0 Capture 3 High
PCA0CPL3    DATA 0EDH                  ; PCA0 Capture 4 Low
PCA0CPH3    DATA 0EEH                  ; PCA0 Capture 4 High
RSTSRC      DATA 0EFH                  ; Reset Source Configuration/Status
B           DATA 0F0H                  ; B Register
P0MAT       DATA 0F1H                  ; Port 0 Match
P0MDIN      DATA 0F1H                  ; Port 0 Input Mode
P0MASK      DATA 0F2H                  ; Port 0 Mask
P1MDIN      DATA 0F2H                  ; Port 1 Input Mode
P1MAT       DATA 0F3H                  ; Port 1 Match
P2MDIN      DATA 0F3H                  ; Port 2 Input Mode
P1MASK      DATA 0F4H                  ; Port 1 Mask
P3MDIN      DATA 0F4H                  ; Port 3 Input Mode
EIP1        DATA 0F6H                  ; External Interrupt Priority 1
EIP2        DATA 0F7H                  ; External Interrupt Priority 2
SPI0CN      DATA 0F8H                  ; SPI0 Control
PCA0L       DATA 0F9H                  ; PCA0 Counter Low
PCA0H       DATA 0FAH                  ; PCA0 Counter High
PCA0CPL0    DATA 0FBH                  ; PCA0 Capture 0 Low
PCA0CPH0    DATA 0FCH                  ; PCA0 Capture 0 High
PCA0CPL4    DATA 0FDH                  ; PCA0 Capture 4 Low
PCA0CPH4    DATA 0FEH                  ; PCA0 Capture 4 High
VDM0CN      DATA 0FFH                  ; VDD Monitor Control

;------------------------------------------------------------------------------
; Page C (CAN0) Registers
;------------------------------------------------------------------------------

CAN0CFG         DATA 092H              ; CAN0 Clock Configuration
CAN0STAT        DATA 094H              ; Status Register Low Byte
CAN0ERRL        DATA 096H              ; Error Counter Low Byte
CAN0ERRH        DATA 097H              ; Error Counter High Byte
CAN0BTL         DATA 09AH              ; Bit Timing Register Low Byte
CAN0BTH         DATA 09BH              ; Bit Timing Register High Byte
CAN0IIDL        DATA 09CH              ; Interrupt Register Low Byte
CAN0IIDH        DATA 09DH              ; Interrupt Register High Byte
CAN0TST         DATA 09EH              ; Test Register Low Byte
CAN0BRPE        DATA 0A1H              ; BRP Extension Register Low Byte
CAN0TR1L        DATA 0A2H              ; Transmission Request 1 Low Byte
CAN0TR1H        DATA 0A3H              ; Transmission Request 1 High Byte
CAN0TR2L        DATA 0A4H              ; Transmission Request 2 Low Byte
CAN0TR2H        DATA 0A5H              ; Transmission Request 2 High Byte
CAN0ND1L        DATA 0AAH              ; New Data 1 Low Byte
CAN0ND1H        DATA 0ABH              ; New Data 1 High Byte
CAN0ND2L        DATA 0ACH              ; New Data 2 Low Byte
CAN0ND2H        DATA 0ADH              ; New Data 2 High Byte
CAN0IP1L        DATA 0AEH              ; Interrupt Pending 1 Low Byte
CAN0IP1H        DATA 0AFH              ; Interrupt Pending 1 High Byte
CAN0IP2L        DATA 0B2H              ; Interrupt Pending 2 Low Byte
CAN0IP2H        DATA 0B3H              ; Interrupt Pending 2 High Byte
CAN0MV1L        DATA 0BAH              ; Message Valid 1 Low Byte
CAN0MV1H        DATA 0BBH              ; Message Valid 1 High Byte
CAN0MV2L        DATA 0BCH              ; Message Valid 2 Low Byte
CAN0MV2H        DATA 0BDH              ; Message Valid 2 High Byte
CAN0IF1CRL      DATA 0BEH              ; IF1 Command Request Low Byte
CAN0IF1CRH      DATA 0BFH              ; IF1 Command Request High Byte
CAN0CN          DATA 0C0H              ; CAN Control Register Low Byte
CAN0IF1CML      DATA 0C2H              ; IF1 Command Mask Low Byte
CAN0IF1CMH      DATA 0C3H              ; IF1 Command Mask High Byte
CAN0IF1M1L      DATA 0C4H              ; IF1 Mask 1 Low Byte
CAN0IF1M1H      DATA 0C5H              ; IF1 Mask 1 High Byte
CAN0IF1M2L      DATA 0C6H              ; IF1 Mask 2 Low Byte
CAN0IF1M2H      DATA 0C7H              ; IF1 Mask 2 High Byte
CAN0IF1A1L      DATA 0CAH              ; IF1 Arbitration 1 Low Byte
CAN0IF1A1H      DATA 0CBH              ; IF1 Arbitration 1 High Byte
CAN0IF1A2L      DATA 0CCH              ; IF1 Arbitration 2 Low Byte
CAN0IF1A2H      DATA 0CDH              ; IF1 Arbitration 2 High Byte
CAN0IF2MCL      DATA 0CEH              ; IF2 Message Control Low Byte
CAN0IF2MCH      DATA 0CFH              ; IF2 Message Control High Byte
CAN0IF1MCL      DATA 0D2H              ; IF1 Message Control Low Byte
CAN0IF1MCH      DATA 0D3H              ; IF1 Message Control High Byte
CAN0IF1DA1L     DATA 0D4H              ; IF1 Data A 1 Low Byte
CAN0IF1DA1H     DATA 0D5H              ; IF1 Data A 1 High Byte
CAN0IF1DA2L     DATA 0D6H              ; IF1 Data A 2 Low Byte
CAN0IF1DA2H     DATA 0D7H              ; IF1 Data A 2 High Byte
CAN0IF1DB1L     DATA 0DAH              ; IF1 Data B 1 Low Byte
CAN0IF1DB1H     DATA 0DBH              ; IF1 Data B 1 High Byte
CAN0IF1DB2L     DATA 0DCH              ; IF1 Data B 2 Low Byte
CAN0IF1DB2H     DATA 0DDH              ; IF1 Data B 2 High Byte
CAN0IF2CRL      DATA 0DEH              ; IF2 Command Request Low Byte
CAN0IF2CRH      DATA 0DFH              ; IF2 Command Request High Byte
CAN0IF2CML      DATA 0E2H              ; IF2 Command Mask Low Byte
CAN0IF2CMH      DATA 0E3H              ; IF2 Command Mask High Byte
CAN0IF2M1L      DATA 0EAH              ; IF2 Mask 1 Low Byte
CAN0IF2M1H      DATA 0EBH              ; IF2 Mask 1 High Byte
CAN0IF2M2L      DATA 0ECH              ; IF2 Mask 2 Low Byte
CAN0IF2M2H      DATA 0EDH              ; IF2 Mask 2 High Byte
CAN0IF2A1L      DATA 0EEH              ; IF2 Arbitration 1 Low Byte
CAN0IF2A1H      DATA 0EFH              ; IF2 Arbitration 1 High Byte
CAN0IF2A2L      DATA 0F2H              ; IF2 Arbitration 2 Low Byte
CAN0IF2A2H      DATA 0F3H              ; IF2 Arbitration 2 High Byte
CAN0IF2DA1L     DATA 0F6H              ; IF2 Data A 1 Low Byte
CAN0IF2DA1H     DATA 0F7H              ; IF2 Data A 1 High Byte
CAN0IF2DA2L     DATA 0FAH              ; IF2 Data A 2 Low Byte
CAN0IF2DA2H     DATA 0FBH              ; IF2 Data A 2 High Byte
CAN0IF2DB1L     DATA 0FCH              ; IF2 Data B 1 Low Byte
CAN0IF2DB1H     DATA 0FDH              ; IF2 Data B 1 High Byte
CAN0IF2DB2L     DATA 0FEH              ; IF2 Data B 2 Low Byte
CAN0IF2DB2H     DATA 0FFH              ; IF2 Data B 2 High Byte

;------------------------------------------------------------------------------
; LIN0 Indirect Registers
;------------------------------------------------------------------------------

LIN0DT1         EQU  00H               ; LIN0 Data Byte 1
LIN0DT2         EQU  01H               ; LIN0 Data Byte 2
LIN0DT3         EQU  02H               ; LIN0 Data Byte 3
LIN0DT4         EQU  03H               ; LIN0 Data Byte 4
LIN0DT5         EQU  04H               ; LIN0 Data Byte 5
LIN0DT6         EQU  05H               ; LIN0 Data Byte 6
LIN0DT7         EQU  06H               ; LIN0 Data Byte 7
LIN0DT8         EQU  07H               ; LIN0 Data Byte 8
LIN0CTRL        EQU  08H               ; LIN0 Control
LIN0ST          EQU  09H               ; LIN0 Status
LIN0ERR         EQU  0AH               ; LIN0 Error
LIN0SIZE        EQU  0BH               ; LIN0 Message Size
LIN0DIV         EQU  0CH               ; LIN0 Divider
LIN0MUL         EQU  0DH               ; LIN0 Multiplier
LIN0ID          EQU  0EH               ; LIN0 Identifier

;------------------------------------------------------------------------------
; Address Definitions for Bit-addressable Registers
;------------------------------------------------------------------------------

SFR_P0          EQU  080H
SFR_TCON        EQU  088H
SFR_P1          EQU  090H
SFR_SCON0       EQU  098H
SFR_P2          EQU  0A0H
SFR_IE          EQU  0A8H
SFR_P3          EQU  0B0H
SFR_IP          EQU  0B8H
SFR_SMB0CN      EQU  0C0H
SFR_TMR2CN      EQU  0C8H
SFR_PSW         EQU  0D0H
SFR_PCA0CN      EQU  0D8H
SFR_ACC         EQU  0E0H
SFR_ADC0CN      EQU  0E8H
SFR_B           EQU  0F0H
SFR_SPI0CN      EQU  0F8H

;------------------------------------------------------------------------------
; Bit Definitions
;------------------------------------------------------------------------------

; TCON 0x88
TF1         BIT TCON.7                 ; Timer 1 Overflow Flag
TR1         BIT TCON.6                 ; Timer 1 On/Off Control
TF0         BIT TCON.5                 ; Timer 0 Overflow Flag
TR0         BIT TCON.4                 ; Timer 0 On/Off Control
IE1         BIT TCON.3                 ; Ext. Interrupt 1 Edge Flag
IT1         BIT TCON.2                 ; Ext. Interrupt 1 Type
IE0         BIT TCON.1                 ; Ext. Interrupt 0 Edge Flag
IT0         BIT TCON.0                 ; Ext. Interrupt 0 Type

; SCON0 0x98
OVR0        BIT SCON0.7                ; UART0 Receive FIFO Overrun Flag
PERR0       BIT SCON0.6                ; UART0 Parity Error Flag
THRE0       BIT SCON0.5                ; UART0 Transmit Holding Reg. Empty
REN0        BIT SCON0.4                ; UART0 RX Enable
TBX0        BIT SCON0.3                ; UART0 TX Bit 8
RBX0        BIT SCON0.2                ; UART0 RX Bit 8
TI0         BIT SCON0.1                ; UART0 TX Interrupt Flag
RI0         BIT SCON0.0                ; UART0 RX Interrupt Flag

; IE 0xA8
EA          BIT IE.7                   ; Global Interrupt Enable
ESPI0       BIT IE.6                   ; SPI0 Interrupt Enable
ET2         BIT IE.5                   ; Timer 2 Interrupt Enable
ES0         BIT IE.4                   ; UART0 Interrupt Enable
ET1         BIT IE.3                   ; Timer 1 Interrupt Enable
EX1         BIT IE.2                   ; External Interrupt 1 Enable
ET0         BIT IE.1                   ; Timer 0 Interrupt Enable
EX0         BIT IE.0                   ; External Interrupt 0 Enable

; IP 0xB8
                                       ; Bit 7 unused
PSPI0       BIT IP.6                   ; SPI0 Interrupt Priority
PT2         BIT IP.5                   ; Timer 2 Priority
PS0         BIT IP.4                   ; UART0 Priority
PS          BIT IP.4                   ; UART0 Priority
PT1         BIT IP.3                   ; Timer 1 Priority
PX1         BIT IP.2                   ; External Interrupt 1 Priority
PT0         BIT IP.1                   ; Timer 0 Priority
PX0         BIT IP.0                   ; External Interrupt 0 Priority

; SMB0CN 0xC0
MASTER      BIT SMB0CN.7               ; SMBus0 Master/Slave Indicator
TXMODE      BIT SMB0CN.6               ; SMBus0 Transmit Mode Indicator
STA         BIT SMB0CN.5               ; SMBus0 Start Flag
STO         BIT SMB0CN.4               ; SMBus0 Stop Flag
ACKRQ       BIT SMB0CN.3               ; SMBus0 Acknowledge Request
ARBLOST     BIT SMB0CN.2               ; SMBus0 Arbitration Lost Indicator
ACK         BIT SMB0CN.1               ; SMBus0 Acknowledge
SI          BIT SMB0CN.0               ; SMBus0 Interrupt Flag

; TMR2CN 0xC8
TF2H        BIT TMR2CN.7               ; Timer 2 High-Byte Overflow Flag
TF2L        BIT TMR2CN.6               ; Timer 2 Low-Byte  Overflow Flag
TF2LEN      BIT TMR2CN.5               ; Timer 2 Low-Byte Flag Enable
TF2CEN      BIT TMR2CN.4               ; Timer 2 Capture Enable
T2SPLIT     BIT TMR2CN.3               ; Timer 2 Split-Mode Enable
TR2         BIT TMR2CN.2               ; Timer2 Run Enable
                                       ; Unused
T2XCLK      BIT TMR2CN.0               ; Timer 2 Clk/8 Clock Source

; PSW 0xD0
CY          BIT PSW.7                  ; Carry Flag
AC          BIT PSW.6                  ; Auxiliary Carry Flag
F0          BIT PSW.5                  ; User Flag 0
RS1         BIT PSW.4                  ; Register Bank Select 1
RS0         BIT PSW.3                  ; Register Bank Select 0
OV          BIT PSW.2                  ; Overflow Flag
F1          BIT PSW.1                  ; User Flag 1
P           BIT PSW.0                  ; Accumulator Parity Flag

; PCA0CN 0xD8
CF          BIT PCA0CN.7               ; PCA0 Counter Overflow Flag
CR          BIT PCA0CN.6               ; PCA0 Counter Run Control Bit
CCF5        BIT PCA0CN.5               ; PCA0 Module 5 Interrupt Flag
CCF4        BIT PCA0CN.4               ; PCA0 Module 4 Interrupt Flag
CCF3        BIT PCA0CN.3               ; PCA0 Module 3 Interrupt Flag
CCF2        BIT PCA0CN.2               ; PCA0 Module 2 Interrupt Flag
CCF1        BIT PCA0CN.1               ; PCA0 Module 1 Interrupt Flag
CCF0        BIT PCA0CN.0               ; PCA0 Module 0 Interrupt Flag

; ADC0CN 0xE8
AD0EN       BIT ADC0CN.7               ; ADC0 Enable
BURSTEN     BIT ADC0CN.6               ; ADC0 Burst Enable
AD0INT      BIT ADC0CN.5               ; ADC0 EOC Interrupt Flag
AD0BUSY     BIT ADC0CN.4               ; ADC0 Busy Flag
AD0WINT     BIT ADC0CN.3               ; ADC0 Window Compare Interrupt Flag
AD0LJST     BIT ADC0CN.2               ; ADC0 Left Justified
AD0CM1      BIT ADC0CN.1               ; ADC0 Start Of Conversion Mode Bit 1
AD0CM0      BIT ADC0CN.0               ; ADC0 Start Of Conversion Mode Bit 0

; SPI0CN 0xF8
SPIF        BIT SPI0CN.7               ; SPI0 Interrupt Flag
WCOL        BIT SPI0CN.6               ; SPI0 Write Collision Flag
MODF        BIT SPI0CN.5               ; SPI0 Mode Fault Flag
RXOVRN      BIT SPI0CN.4               ; SPI0 RX Overrun Flag
NSSMD1      BIT SPI0CN.3               ; SPI0 Slave Select Mode 1
NSSMD0      BIT SPI0CN.2               ; SPI0 Slave Select Mode 0
TXBMT       BIT SPI0CN.1               ; SPI0 TX Buffer Empty Flag
SPIEN       BIT SPI0CN.0               ; SPI0 Enable

;-----------------------------------------------------------------------------
; Interrupt Priorities
;-----------------------------------------------------------------------------

INTERRUPT_INT0         EQU      0      ; External Interrupt 0
INTERRUPT_TIMER0       EQU      1      ; Timer0 Overflow
INTERRUPT_INT1         EQU      2      ; External Interrupt 1
INTERRUPT_TIMER1       EQU      3      ; Timer1 Overflow
INTERRUPT_UART0        EQU      4      ; UART0
INTERRUPT_TIMER2       EQU      5      ; Timer2 Overflow
INTERRUPT_SPI0         EQU      6      ; SPI0
INTERRUPT_SMBUS0       EQU      7      ; SMBus0 Interface
INTERRUPT_ADC0_WINDOW  EQU      8      ; ADC0 Window Comparison
INTERRUPT_ADC0_EOC     EQU      9      ; ADC0 End Of Conversion
INTERRUPT_PCA0         EQU     10      ; PCA0 Peripheral
INTERRUPT_COMPARATOR0  EQU     11      ; Comparator0 Comparison
INTERRUPT_COMPARATOR1  EQU     12      ; Comparator1 Comparison
INTERRUPT_TIMER3       EQU     13      ; Timer3 Overflow
INTERRUPT_LIN0         EQU     14      ; LIN Bus Interrupt
INTERRUPT_VREG         EQU     15      ; Voltage Regulator
INTERRUPT_CAN0         EQU     16      ; CAN Bus Interrupt
INTERRUPT_PORT_MATCH   EQU     17      ; Port Match

;------------------------------------------------------------------------------
; SFR Page Definitions
;------------------------------------------------------------------------------

CONFIG_PAGE            EQU    0FH      ; System and Port Configuration Page
ACTIVE_PAGE            EQU    00H      ; Active Use Page
CAN0_PAGE              EQU    0CH      ; CAN0 Registers

;------------------------------------------------------------------------------
; End Of File
;------------------------------------------------------------------------------