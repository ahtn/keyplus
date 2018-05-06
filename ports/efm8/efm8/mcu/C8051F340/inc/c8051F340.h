//-----------------------------------------------------------------------------
// c8051F340.h
//-----------------------------------------------------------------------------
// Copyright 2005 Silicon Laboratories, Inc.
// http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
//
// Program Description:
//
// Register/bit definitions for the C8051F34x family.
//
//
// FID:            34X000000
// Target:         C8051F340, 'F341, 'F342, 'F343, 'F344, 'F345, 'F346, 'F347,
//                 'F348, 'F349, 'F34A, 'F34B
// Tool chain:     Keil
// Command Line:   None
//
// Release 1.2 - 16 SEP 2008 (PKC)
//    -Added 'F348/9/A/B to the target part numbers list.
//
// Release 1.1
//    -All changes by GP
//    -17 NOV 2005
//    -Converted file to new coding guidelines
//    -Added #defines for interrupt priorities
//    -Added #ifndef/#define to allow multiple includes of file
//    -Converted Bit Definitions to absolute addresses for easier porting
//
// Release 1.0
//    -Initial Revision (CM)
//    -08 AUG 2005
//    -Latest release before new firmware coding standard
//

#ifndef C8051F340_H
#define C8051F340_H

//-----------------------------------------------------------------------------
// Byte Registers
//-----------------------------------------------------------------------------

sfr  P0           =  0x80;             // Port 0 Latch
sfr  SP           =  0x81;             // Stack Pointer
sfr  DPL          =  0x82;             // Data Pointer Low
sfr  DPH          =  0x83;             // Data Pointer High
sfr  EMI0TC       =  0x84;             // EMIF Timing
sfr  EMI0CF       =  0x85;             // EMIF Configuration
sfr  OSCLCN       =  0x86;             // Internal Low-Freq Oscillator Control
sfr  PCON         =  0x87;             // Power Control
sfr  TCON         =  0x88;             // Timer/Counter Control
sfr  TMOD         =  0x89;             // Timer/Counter Mode
sfr  TL0          =  0x8A;             // Timer/Counter 0 Low
sfr  TL1          =  0x8B;             // Timer/Counter 1 Low
sfr  TH0          =  0x8C;             // Timer/Counter 0 High
sfr  TH1          =  0x8D;             // Timer/Counter 1 High
sfr  CKCON        =  0x8E;             // Clock Control
sfr  PSCTL        =  0x8F;             // Program Store R/W Control
sfr  P1           =  0x90;             // Port 1 Latch
sfr  TMR3CN       =  0x91;             // Timer/Counter 3Control
sfr  TMR3RLL      =  0x92;             // Timer/Counter 3 Reload Low
sfr  TMR3RLH      =  0x93;             // Timer/Counter 3 Reload High
sfr  TMR3L        =  0x94;             // Timer/Counter 3Low
sfr  TMR3H        =  0x95;             // Timer/Counter 3 High
sfr  USB0ADR      =  0x96;             // USB0 Indirect Address Register
sfr  USB0DAT      =  0x97;             // USB0 Data Register
sfr  SCON0        =  0x98;             // UART0 Control
sfr  SBUF0        =  0x99;             // UART0 Data Buffer
sfr  CPT1CN       =  0x9A;             // Comparator1 Control
sfr  CPT0CN       =  0x9B;             // Comparator0 Control
sfr  CPT1MD       =  0x9C;             // Comparator1 Mode Selection
sfr  CPT0MD       =  0x9D;             // Comparator0 Mode Selection
sfr  CPT1MX       =  0x9E;             // Comparator1 MUX Selection
sfr  CPT0MX       =  0x9F;             // Comparator0 MUX Selection
sfr  P2           =  0xA0;             // Port 2 Latch
sfr  SPI0CFG      =  0xA1;             // SPI Configuration
sfr  SPI0CKR      =  0xA2;             // SPI Clock Rate Control
sfr  SPI0DAT      =  0xA3;             // SPI Data
sfr  P0MDOUT      =  0xA4;             // Port 0 Output Mode Configuration
sfr  P1MDOUT      =  0xA5;             // Port 1 Output Mode Configuration
sfr  P2MDOUT      =  0xA6;             // Port 2 Output Mode Configuration
sfr  P3MDOUT      =  0xA7;             // Port 3 Output Mode Configuration
sfr  IE           =  0xA8;             // Interrupt Enable
sfr  CLKSEL       =  0xA9;             // Clock Select
sfr  EMI0CN       =  0xAA;             // External Memory Interface Control
sfr  SBCON1       =  0xAC;             // UART1 Baud Rate Generator Control
sfr  P4MDOUT      =  0xAE;             // Port 4 Output Mode Configuration
sfr  PFE0CN       =  0xAF;             // Prefetch Engine Control
sfr  P3           =  0xB0;             // Port 3 Latch
sfr  OSCXCN       =  0xB1;             // External Oscillator Control
sfr  OSCICN       =  0xB2;             // Internal Oscillator Control
sfr  OSCICL       =  0xB3;             // Internal Oscillator Calibration
sfr  SBRLL1       =  0xB4;             // UART1 Baud Rate Generator Low
sfr  SBRLH1       =  0xB5;             // UART1 Baud Rate Generator High
sfr  FLSCL        =  0xB6;             // Flash Scale
sfr  FLKEY        =  0xB7;             // Flash Lock and Key
sfr  IP           =  0xB8;             // Interrupt Priority
sfr  CLKMUL       =  0xB9;             // Clock Multiplier
sfr  AMX0N        =  0xBA;             // AMUX0 Negative Channel Select
sfr  AMX0P        =  0xBB;             // AMUX0 Positive Channel Select
sfr  ADC0CF       =  0xBC;             // ADC0 Configuration
sfr  ADC0L        =  0xBD;             // ADC0 Low
sfr  ADC0H        =  0xBE;             // ADC0 High
sfr  SMB0CN       =  0xC0;             // SMBus Control
sfr  SMB0CF       =  0xC1;             // SMBus Configuration
sfr  SMB0DAT      =  0xC2;             // SMBus Data
sfr  ADC0GTL      =  0xC3;             // ADC0 Greater-Than Compare Low
sfr  ADC0GTH      =  0xC4;             // ADC0 Greater-Than Compare High
sfr  ADC0LTL      =  0xC5;             // ADC0 Less-Than Compare Word Low
sfr  ADC0LTH      =  0xC6;             // ADC0 Less-Than Compare Word High
sfr  P4           =  0xC7;             // Port 4 Latch
sfr  TMR2CN       =  0xC8;             // Timer/Counter 2 Control
sfr  REG0CN       =  0xC9;             // Voltage Regulator Control
sfr  TMR2RLL      =  0xCA;             // Timer/Counter 2 Reload Low
sfr  TMR2RLH      =  0xCB;             // Timer/Counter 2 Reload High
sfr  TMR2L        =  0xCC;             // Timer/Counter 2 Low
sfr  TMR2H        =  0xCD;             // Timer/Counter 2 High
sfr  PSW          =  0xD0;             // Program Status Word
sfr  REF0CN       =  0xD1;             // Voltage Reference Control
sfr  SCON1        =  0xD2;             // UART1 Control
sfr  SBUF1        =  0xD3;             // UART1 Data Buffer
sfr  P0SKIP       =  0xD4;             // Port 0 Skip
sfr  P1SKIP       =  0xD5;             // Port 1 Skip
sfr  P2SKIP       =  0xD6;             // Port 2 Skip
sfr  USB0XCN      =  0xD7;             // USB0 Transceiver Control
sfr  PCA0CN       =  0xD8;             // PCA0 Control
sfr  PCA0MD       =  0xD9;             // PCA0 Mode
sfr  PCA0CPM0     =  0xDA;             // PCA0 Module 0 Mode Register
sfr  PCA0CPM1     =  0xDB;             // PCA0 Module 1 Mode Register
sfr  PCA0CPM2     =  0xDC;             // PCA0 Module 2 Mode Register
sfr  PCA0CPM3     =  0xDD;             // PCA0 Module 3 Mode Register
sfr  PCA0CPM4     =  0xDE;             // PCA0 Module 4 Mode Register
sfr  P3SKIP       =  0xDF;             // Port 3 Skip
sfr  ACC          =  0xE0;             // Accumulator
sfr  XBR0         =  0xE1;             // Port I/O Crossbar Control 0
sfr  XBR1         =  0xE2;             // Port I/O Crossbar Control 1
sfr  XBR2         =  0xE3;             // Port I/O Crossbar Control 2
sfr  IT01CF       =  0xE4;             // INT0/INT1 Configuration
sfr  SMOD1        =  0xE5;             // UART1 Mode
sfr  EIE1         =  0xE6;             // Extended Interrupt Enable 1
sfr  EIE2         =  0xE7;             // Extended Interrupt Enable 2
sfr  ADC0CN       =  0xE8;             // ADC0 Control
sfr  PCA0CPL1     =  0xE9;             // PCA0 Capture 1 Low
sfr  PCA0CPH1     =  0xEA;             // PCA0 Capture 1 High
sfr  PCA0CPL2     =  0xEB;             // PCA0 Capture 2 Low
sfr  PCA0CPH2     =  0xEC;             // PCA0 Capture 2 High
sfr  PCA0CPL3     =  0xED;             // PCA0 Capture 3 Low
sfr  PCA0CPH3     =  0xEE;             // PCA0 Capture 3 High
sfr  RSTSRC       =  0xEF;             // Reset Source Configuration/Status
sfr  B            =  0xF0;             // B Register
sfr  P0MDIN       =  0xF1;             // Port 0 Input Mode Configuration
sfr  P1MDIN       =  0xF2;             // Port 1 Input Mode Configuration
sfr  P2MDIN       =  0xF3;             // Port 2 Input Mode Configuration
sfr  P3MDIN       =  0xF4;             // Port 3 Input Mode Configuration
sfr  P4MDIN       =  0xF5;             // Port 4 Input Mode Configuration
sfr  EIP1         =  0xF6;             // Extended Interrupt Priority 1
sfr  EIP2         =  0xF7;             // Extended Interrupt Priority 2
sfr  SPI0CN       =  0xF8;             // SPI0 Control
sfr  PCA0L        =  0xF9;             // PCA0 Counter Low
sfr  PCA0H        =  0xFA;             // PCA0 Counter High
sfr  PCA0CPL0     =  0xFB;             // PCA0 Capture 0 Low
sfr  PCA0CPH0     =  0xFC;             // PCA0 Capture 0 High
sfr  PCA0CPL4     =  0xFD;             // PCA0 Capture 4 Low
sfr  PCA0CPH4     =  0xFE;             // PCA0 Capture 4 High
sfr  VDM0CN       =  0xFF;             // VDD Monitor Control


//-----------------------------------------------------------------------------
// Bit Definitions
//-----------------------------------------------------------------------------

// TCON 0x88
sbit TF1     = 0x8F;                   // Timer1 overflow flag
sbit TR1     = 0x8E;                   // Timer1 on/off control
sbit TF0     = 0x8D;                   // Timer0 overflow flag
sbit TR0     = 0x8C;                   // Timer0 on/off control
sbit IE1     = 0x8B;                   // Ext interrupt 1 edge flag
sbit IT1     = 0x8A;                   // Ext interrupt 1 type
sbit IE0     = 0x89;                   // Ext interrupt 0 edge flag
sbit IT0     = 0x88;                   // Ext interrupt 0 type

// SCON0 0x98
sbit S0MODE  = 0x9F;                   // Serial mode control bit 0
                                       // Bit6 UNUSED
sbit MCE0    = 0x9D;                   // Multiprocessor communication enable
sbit REN0    = 0x9C;                   // Receive enable
sbit TB80    = 0x9B;                   // Transmit bit 8
sbit RB80    = 0x9A;                   // Receive bit 8
sbit TI0     = 0x99;                   // Transmit interrupt flag
sbit RI0     = 0x98;                   // Receive interrupt flag

// IE 0xA8
sbit EA      = 0xAF;                   // Global interrupt enable
sbit ESPI0   = 0xAE;                   // SPI0 interrupt enable
sbit ET2     = 0xAD;                   // Timer2 interrupt enable
sbit ES0     = 0xAC;                   // UART0 interrupt enable
sbit ET1     = 0xAB;                   // Timer1 interrupt enable
sbit EX1     = 0xAA;                   // External interrupt 1 enable
sbit ET0     = 0xA9;                   // Timer0 interrupt enable
sbit EX0     = 0xA8;                   // External interrupt 0 enable

// IP 0xB8
                                       // Bit7 UNUSED
sbit PSPI0   = 0xBE;                   // SPI0 interrupt priority
sbit PT2     = 0xBD;                   // Timer2 priority
sbit PS0     = 0xBC;                   // UART0 priority
sbit PT1     = 0xBB;                   // Timer1 priority
sbit PX1     = 0xBA;                   // External interrupt 1 priority
sbit PT0     = 0xB9;                   // Timer0 priority
sbit PX0     = 0xB8;                   // External interrupt 0 priority

// SMB0CN 0xC0
sbit MASTER  = 0xC7;                   // Master/slave indicator
sbit TXMODE  = 0xC6;                   // Transmit mode indicator
sbit STA     = 0xC5;                   // Start flag
sbit STO     = 0xC4;                   // Stop flag
sbit ACKRQ   = 0xC3;                   // Acknowledge request
sbit ARBLOST = 0xC2;                   // Arbitration lost indicator
sbit ACK     = 0xC1;                   // Acknowledge flag
sbit SI      = 0xC0;                   // SMBus interrupt flag

// TMR2CN 0xC8
sbit TF2H    = 0xCF;                   // Timer2 high byte overflow flag
sbit TF2L    = 0xCE;                   // Timer2 low byte overflow flag
sbit TF2LEN  = 0xCD;                   // Timer2 low byte interrupt enable
sbit T2SOF   = 0xCC;                   // Timer2 start-of-frame capture enable
sbit T2SPLIT = 0xCB;                   // Timer2 split mode enable
sbit TR2     = 0xCA;                   // Timer2 on/off control
                                       // Bit1 UNUSED
sbit T2XCLK  = 0xC8;                   // Timer2 external clock select

// PSW 0xD0
sbit CY      = 0xD7;                   // Carry flag
sbit AC      = 0xD6;                   // Auxiliary carry flag
sbit F0      = 0xD5;                   // User flag 0
sbit RS1     = 0xD4;                   // Register bank select 1
sbit RS0     = 0xD3;                   // Register bank select 0
sbit OV      = 0xD2;                   // Overflow flag
sbit F1      = 0xD1;                   // User flag 1
sbit P       = 0xD0;                   // Accumulator parity flag

// PCA0CN 0xD8
sbit CF      = 0xDF;                   // PCA0 counter overflow flag
sbit CR      = 0xDE;                   // PCA0 counter run control
                                       // Bit5 UNUSED
sbit CCF4    = 0xDC;                   // PCA0 module4 capture/compare flag
sbit CCF3    = 0xDB;                   // PCA0 module3 capture/compare flag
sbit CCF2    = 0xDA;                   // PCA0 module2 capture/compare flag
sbit CCF1    = 0xD9;                   // PCA0 module1 capture/compare flag
sbit CCF0    = 0xD8;                   // PCA0 module0 capture/compare flag

// ADC0CN 0xE8
sbit AD0EN   = 0xEF;                   // ADC0 enable
sbit AD0TM   = 0xEE;                   // ADC0 track mode
sbit AD0INT  = 0xED;                   // ADC0 converision complete interrupt flag
sbit AD0BUSY = 0xEC;                   // ADC0 busy flag
sbit AD0WINT = 0xEB;                   // ADC0 window compare interrupt flag
sbit AD0CM2  = 0xEA;                   // ADC0 conversion mode select 2
sbit AD0CM1  = 0xE9;                   // ADC0 conversion mode select 1
sbit AD0CM0  = 0xE8;                   // ADC0 conversion mode select 0

// SPI0CN 0xF8
sbit SPIF    = 0xFF;                   // SPI0 interrupt flag
sbit WCOL    = 0xFE;                   // SPI0 write collision flag
sbit MODF    = 0xFD;                   // SPI0 mode fault flag
sbit RXOVRN  = 0xFC;                   // SPI0 rx overrun flag
sbit NSSMD1  = 0xFB;                   // SPI0 slave select mode 1
sbit NSSMD0  = 0xFA;                   // SPI0 slave select mode 0
sbit TXBMT   = 0xF9;                   // SPI0 transmit buffer empty
sbit SPIEN   = 0xF8;                   // SPI0 SPI enable


//-----------------------------------------------------------------------------
// Interrupt Priorities
//-----------------------------------------------------------------------------

#define INTERRUPT_INT0             0   // External Interrupt 0
#define INTERRUPT_TIMER0           1   // Timer0 Overflow
#define INTERRUPT_INT1             2   // External Interrupt 1
#define INTERRUPT_TIMER1           3   // Timer1 Overflow
#define INTERRUPT_UART0            4   // Serial Port 0
#define INTERRUPT_TIMER2           5   // Timer2 Overflow
#define INTERRUPT_SPI0             6   // Serial Peripheral Interface 0
#define INTERRUPT_SMBUS0           7   // SMBus0 Interface
#define INTERRUPT_USB0             8   // USB Interface
#define INTERRUPT_ADC0_WINDOW      9   // ADC0 Window Comparison
#define INTERRUPT_ADC0_EOC         10  // ADC0 End Of Conversion
#define INTERRUPT_PCA0             11  // PCA0 Peripheral
#define INTERRUPT_COMPARATOR0      12  // Comparator0
#define INTERRUPT_COMPARATOR1      13  // Comparator1
#define INTERRUPT_TIMER3           14  // Timer3 Overflow
#define INTERRUPT_VBUS_LEVEL       15  // VBUS level-triggered interrupt
#define INTERRUPT_UART1            16  // Serial Port 1

//-----------------------------------------------------------------------------
// Header File PreProcessor Directive
//-----------------------------------------------------------------------------

#endif                                 // #define C8051F340_H

//-----------------------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------------------
