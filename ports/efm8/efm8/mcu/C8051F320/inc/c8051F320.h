//-----------------------------------------------------------------------------
// C8051F320.h
//-----------------------------------------------------------------------------
// Copyright 2005 Silicon Laboratories, Inc.
// http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
//
// Program Description:
//
// Register/bit definitions for the C8051F32x family.
//
//
// FID:            32X000008
// Target:         C8051F320, 'F321
// Tool chain:     Keil
// Command Line:   None
//
// Release 2.1
//    -All changes by GRP
//    -09 DEC 2005
//    -added EMI0CN
//
// Release 2.0
//    -All changes by PKC
//    -09 NOV 2005
//    -Converted file to new coding guidelines
//    -Added #defines for interrupt priorities
//    -Added #ifndef/#define to allow multiple includes of file
//
// Release 1.5
//    -Latest release before new firmware coding standard
//

//-----------------------------------------------------------------------------
// Header File Preprocessor Directive
//-----------------------------------------------------------------------------

#ifndef C8051F320_H
#define C8051F320_H

//-----------------------------------------------------------------------------
// Byte Registers
//-----------------------------------------------------------------------------

sfr P0       = 0x80;                   // Port0
sfr SP       = 0x81;                   // Stack pointer
sfr DPL      = 0x82;                   // Data pointer - Low byte
sfr DPH      = 0x83;                   // Data pointer - High byte
sfr PCON     = 0x87;                   // Power control register
sfr TCON     = 0x88;                   // Timer control register
sfr TMOD     = 0x89;                   // Timer mode register
sfr TL0      = 0x8A;                   // Timer0 - Low byte
sfr TL1      = 0x8B;                   // Timer1 - Low byte
sfr TH0      = 0x8C;                   // Timer0 - High byte
sfr TH1      = 0x8D;                   // Timer1 - High byte
sfr CKCON    = 0x8E;                   // Clock control register
sfr PSCTL    = 0x8F;                   // Program store r/w control
sfr P1       = 0x90;                   // Port1
sfr TMR3CN   = 0x91;                   // Timer3 control register
sfr TMR3RLL  = 0x92;                   // Timer3 reload register - Low byte
sfr TMR3RLH  = 0x93;                   // Timer3 reload register - High byte
sfr TMR3L    = 0x94;                   // Timer3 - Low byte
sfr TMR3H    = 0x95;                   // Timer3 - High byte
sfr USB0ADR  = 0x96;                   // USB0 address port
sfr USB0DAT  = 0x97;                   // USB0 data port
sfr SCON0    = 0x98;                   // UART0 control register
sfr SBUF0    = 0x99;                   // UART0 data buffer register
sfr CPT1CN   = 0x9A;                   // Comparator1 control register
sfr CPT0CN   = 0x9B;                   // Comparator0 control register
sfr CPT1MD   = 0x9C;                   // Comparator1 mode selection register
sfr CPT0MD   = 0x9D;                   // Comparator0 mode selection register
sfr CPT1MX   = 0x9E;                   // Comparator1 mux selection register
sfr CPT0MX   = 0x9F;                   // Comparator0 mux selection register
sfr P2       = 0xA0;                   // Port2
sfr SPICFG   = 0xA1;                   // SPI0 configuration register
sfr SPI0CFG  = 0xA1;                   // SPI0 configuration register
sfr SPICKR   = 0xA2;                   // SPI0 clock configuration register
sfr SPI0CKR  = 0xA2;                   // SPI0 clock configuration register
sfr SPIDAT   = 0xA3;                   // SPI0 data register
sfr SPI0DAT  = 0xA3;                   // SPI0 data register
sfr P0MDOUT  = 0xA4;                   // Port0 output mode register
sfr P1MDOUT  = 0xA5;                   // Port1 output mode register
sfr P2MDOUT  = 0xA6;                   // Port2 output mode register
sfr P3MDOUT  = 0xA7;                   // Port3 output mode register
sfr IE       = 0xA8;                   // Interrupt enable
sfr CLKSEL   = 0xA9;                   // Clock source select
sfr EMI0CN   = 0xAA;                   // External Memory Interface Control
sfr P3       = 0xB0;                   // Port3
sfr OSCXCN   = 0xB1;                   // External oscillator control
sfr OSCICN   = 0xB2;                   // Internal oscillator control
sfr OSCICL   = 0xB3;                   // Internal oscillator calibration
sfr FLSCL    = 0xB6;                   // Flash scale register
sfr FLKEY    = 0xB7;                   // Flash lock & key register
sfr IP       = 0xB8;                   // Interrupt priority
sfr CLKMUL   = 0xB9;                   // Clock multiplier control register
sfr AMX0N    = 0xBA;                   // ADC0 mux negative channel selection
sfr AMX0P    = 0xBB;                   // ADC0 mux positive channel selection
sfr ADC0CF   = 0xBC;                   // ADC0 configuration
sfr ADC0L    = 0xBD;                   // ADC0 data low
sfr ADC0H    = 0xBE;                   // ADC0 data high
sfr SMB0CN   = 0xC0;                   // SMBus control
sfr SMB0CF   = 0xC1;                   // SMBus configuration
sfr SMB0DAT  = 0xC2;                   // SMBus data
sfr ADC0GTL  = 0xC3;                   // ADC0 greater-than data low register
sfr ADC0GTH  = 0xC4;                   // ADC0 greater-than data high register
sfr ADC0LTL  = 0xC5;                   // ADC0 less-than data low register
sfr ADC0LTH  = 0xC6;                   // ADC0 less-than data high register
sfr TMR2CN   = 0xC8;                   // Timer2 control register
sfr REG0CN   = 0xC9;                   // Regulator control register
sfr TMR2RLL  = 0xCA;                   // Timer2 reload register - Low byte
sfr TMR2RLH  = 0xCB;                   // Timer2 reload register - High byte
sfr TMR2L    = 0xCC;                   // Timer2 - Low byte
sfr TMR2H    = 0xCD;                   // Timer2 - High byte
sfr PSW      = 0xD0;                   // Program Status Word
sfr REF0CN   = 0xD1;                   // Voltage reference control register
sfr P0SKIP   = 0xD4;                   // Port0 crossbar skip register
sfr P1SKIP   = 0xD5;                   // Port1 crossbar skip register
sfr P2SKIP   = 0xD6;                   // Port2 crossbar skip register
sfr USB0XCN  = 0xD7;                   // USB0 tranceiver control register
sfr PCA0CN   = 0xD8;                   // PCA0 control register
sfr PCA0MD   = 0xD9;                   // PCA0 mode register
sfr PCA0CPM0 = 0xDA;                   // Capture/compare module0 mode
sfr PCA0CPM1 = 0xDB;                   // Capture/compare module1 mode
sfr PCA0CPM2 = 0xDC;                   // Capture/compare module2 mode
sfr PCA0CPM3 = 0xDD;                   // Capture/compare module3 mode
sfr PCA0CPM4 = 0xDE;                   // Capture/compare module4 mode
sfr ACC      = 0xE0;                   // Accumulator
sfr XBR0     = 0xE1;                   // Port I/O crossbar register 0
sfr XBR1     = 0xE2;                   // Port I/O crossbar register 1
sfr IT01CF   = 0xE4;                   // Int0/int1 configuration register
sfr EIE1     = 0xE6;                   // Extended interrupt enable 1
sfr EIE2     = 0xE7;                   // Extended interrupt enable 2
sfr ADC0CN   = 0xE8;                   // ADC0 control register
sfr PCA0CPL1 = 0xE9;                   // Capture/compare module1 - Low byte
sfr PCA0CPH1 = 0xEA;                   // Capture/compare module1 - High byte
sfr PCA0CPL2 = 0xEB;                   // Capture/compare module2 - Low byte
sfr PCA0CPH2 = 0xEC;                   // Capture/compare module2 - High byte
sfr PCA0CPL3 = 0xED;                   // Capture/compare module3 - Low byte
sfr PCA0CPH3 = 0xEE;                   // Capture/compare module3 - High byte
sfr RSTSRC   = 0xEF;                   // Reset source register
sfr B        = 0xF0;                   // B register
sfr P0MDIN   = 0xF1;                   // Port0 input mode register
sfr P1MDIN   = 0xF2;                   // Port1 input mode register
sfr P2MDIN   = 0xF3;                   // Port2 input mode register
sfr P3MDIN   = 0xF4;                   // Port3 input mode register
sfr EIP1     = 0xF6;                   // Extended interrupt priority 1
sfr EIP2     = 0xF7;                   // Extended interrupt priority 2
sfr SPI0CN   = 0xF8;                   // SPI0 control register
sfr PCA0L    = 0xF9;                   // PCA0 counter/timer - Low byte
sfr PCA0H    = 0xFA;                   // PCA0 counter/timer - High byte
sfr PCA0CPL0 = 0xFB;                   // Capture/compare module0 - Low byte
sfr PCA0CPH0 = 0xFC;                   // Capture/compare module0 - High byte
sfr PCA0CPL4 = 0xFD;                   // Capture/compare module4 - Low byte
sfr PCA0CPH4 = 0xFE;                   // Capture/compare module4 - High byte
sfr VDM0CN   = 0xFF;                   // Vdd monitor control

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

//-----------------------------------------------------------------------------
// Header File Preprocessor Directive
//-----------------------------------------------------------------------------

#endif                                 // #define C8051F320_H

//-----------------------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------------------