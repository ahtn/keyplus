//-----------------------------------------------------------------------------
// C8051F326.h
//-----------------------------------------------------------------------------
// Copyright 2005 Silicon Laboratories, Inc.
// http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
//
// Program Description:
//
// Register/bit definitions for the C8051F326/7 family.
//
//
// FID:            326000002
// Target:         C8051F326, 'F327
// Tool chain:     Keil
// Command Line:   None
//
// Release 1.0
//    -Initial Release (GP/PKC)
//    -13 DEC 2005
//

//-----------------------------------------------------------------------------
// Header File Preprocessor Directive
//-----------------------------------------------------------------------------

#ifndef C8051F326_H
#define C8051F326_H

//-----------------------------------------------------------------------------
// Byte Registers
//-----------------------------------------------------------------------------

sfr P0       = 0x80;                   // Port 0
sfr SP       = 0x81;                   // Stack Pointer
sfr DPL      = 0x82;                   // Data Pointer - Low Byte
sfr DPH      = 0x83;                   // Data Pointer - High Byte
sfr PCON     = 0x87;                   // Power Control
sfr TCON     = 0x88;                   // Timer Control
sfr TMOD     = 0x89;                   // Timer Mode
sfr TL0      = 0x8A;                   // Timer0 - Low Byte
sfr TL1      = 0x8B;                   // Timer1 - Low Byte
sfr TH0      = 0x8C;                   // Timer0 - High Byte
sfr TH1      = 0x8D;                   // Timer1 - High Byte
sfr CKCON    = 0x8E;                   // Clock Control
sfr PSCTL    = 0x8F;                   // Program Store R/W Control
sfr SBCON0   = 0x91;                   // Baud Rate Generator 0 Control
sfr SBRLL0   = 0x93;                   // Baud Rate Generator 0 Low Byte
sfr SBRLH0   = 0x94;                   // Baud Rate Generator 0 High Byte
sfr USB0ADR  = 0x96;                   // USB0 Address Port
sfr USB0DAT  = 0x97;                   // USB0 Data Port
sfr SCON0    = 0x98;                   // Serial Port 0 Control
sfr SBUF0    = 0x99;                   // Serial Port 0 Data Buffer
sfr SMOD0    = 0x9A;                   // Serial Port 0 Mode
sfr P2       = 0xA0;                   // Port 2
sfr P0MDOUT  = 0xA4;                   // Port 0 Output Mode
sfr P2MDOUT  = 0xA6;                   // Port 2 Output Mode
sfr P3MDOUT  = 0xA7;                   // Port 3 Output Mode
sfr IE       = 0xA8;                   // Interrupt Enable
sfr CLKSEL   = 0xA9;                   // Clock Source Select
sfr EMI0CN   = 0xAA;                   // External Memory Interface Control
sfr P3       = 0xB0;                   // Port 3
sfr OSCICN   = 0xB2;                   // Internal Oscillator Control
sfr OSCICL   = 0xB3;                   // Internal Oscillator Calibration
sfr FLSCL    = 0xB6;                   // Flash Scale
sfr FLKEY    = 0xB7;                   // Flash Lock & Key
sfr IP       = 0xB8;                   // Interrupt Priority
sfr CLKMUL   = 0xB9;                   // Clock Multiplier Control
sfr REG0CN   = 0xC9;                   // Regulator Control
sfr PSW      = 0xD0;                   // Program Status Word
sfr USB0XCN  = 0xD7;                   // USB0 Tranceiver Control
sfr ACC      = 0xE0;                   // Accumulator
sfr GPIOCN   = 0xE2;                   // Global Port I/0 Control
sfr OSCLCN   = 0xE3;                   // Low Frequency Internal Osc. Control
sfr EIE1     = 0xE6;                   // Extended Interrupt Enable 1
sfr EIE2     = 0xE7;                   // Extended Interrupt Enable 2
sfr RSTSRC   = 0xEF;                   // Reset Source
sfr B        = 0xF0;                   // B Register
sfr EIP1     = 0xF6;                   // Extended Interrupt Priority 1
sfr EIP2     = 0xF7;                   // Extended Interrupt Priority 2
sfr VDM0CN   = 0xFF;                   // Vdd Monitor Control

//-----------------------------------------------------------------------------
// Bit Definitions
//-----------------------------------------------------------------------------

//  TCON  0x88
sbit TF1     = 0x8F;                   // Timer1 Overflow Flag
sbit TR1     = 0x8E;                   // Timer1 On/Off Control
sbit TF0     = 0x8D;                   // Timer0 Overflow Flag
sbit TR0     = 0x8C;                   // Timer0 On/Off Control
sbit IE1     = 0x8B;                   // Ext Interrupt 1 Edge Flag
sbit IT1     = 0x8A;                   // Ext Interrupt 1 Type
sbit IE0     = 0x89;                   // Ext Interrupt 0 Edge Flag
sbit IT0     = 0x88;                   // Ext Interrupt 0 Type

//  SCON0  0x98
sbit OVR0    = 0x9F;                   // Receive FIFO Overrun Flag
sbit PERR0   = 0x9E;                   // Parity Error Flag
                                       // Bit5 UNUSED
sbit REN0    = 0x9C;                   // Receive Enable
sbit TBX0    = 0x9B;                   // Transmit Bit 8
sbit RBX0    = 0x9A;                   // Receive Bit 8
sbit TI0     = 0x99;                   // Transmit Interrupt Flag
sbit RI0     = 0x98;                   // Receive Interrupt Flag

//  IE  0xA8
sbit EA      = 0xAF;                   // Global Interrupt Enable
                                       // Bit6 UNUSED
                                       // Bit5 UNUSED
sbit ES0     = 0xAC;                   // UART0 Interrupt Enable
sbit ET1     = 0xAB;                   // Timer1 Interrupt Enable
sbit EX1     = 0xAA;                   // External Interrupt 1 Enable
sbit ET0     = 0xA9;                   // Timer0 Interrupt Enable
sbit EX0     = 0xA8;                   // External Interrupt 0 Enable

//  IP  0xB8
                                       // Bit7 UNUSED
                                       // Bit6 UNUSED
                                       // Bit5 UNUSED
sbit PS0     = 0xBC;                   // UART0 Priority
sbit PT1     = 0xBB;                   // Timer1 Priority
sbit PX1     = 0xBA;                   // External Interrupt 1 Priority
sbit PT0     = 0xB9;                   // Timer0 Priority
sbit PX0     = 0xB8;                   // External Interrupt 0 Priority

//  PSW 0xD0
sbit CY      = 0xD7;                   // Carry Flag
sbit AC      = 0xD6;                   // Auxiliary Carry Flag
sbit F0      = 0xD5;                   // User Flag 0
sbit RS1     = 0xD4;                   // Register Bank Select 1
sbit RS0     = 0xD3;                   // Register Bank Select 0
sbit OV      = 0xD2;                   // Overflow Flag
sbit F1      = 0xD1;                   // User Flag 1
sbit P       = 0xD0;                   // Accumulator Parity Flag


//-----------------------------------------------------------------------------
// Interrupt Priorities
//-----------------------------------------------------------------------------

#define INTERRUPT_INT0             0   // External Interrupt 0
#define INTERRUPT_TIMER0           1   // Timer0 Overflow
#define INTERRUPT_INT1             2   // External Interrupt 1
#define INTERRUPT_TIMER1           3   // Timer1 Overflow
#define INTERRUPT_UART0            4   // Serial Port 0
#define INTERRUPT_USB0             8   // USB Interface
#define INTERRUPT_VBUS_LEVEL       15  // VBUS level-triggered interrupt

//-----------------------------------------------------------------------------
// Header File Preprocessor Directive
//-----------------------------------------------------------------------------

#endif                                 // #define C8051F326_H

//-----------------------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------------------