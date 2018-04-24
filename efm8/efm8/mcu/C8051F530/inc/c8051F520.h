//-----------------------------------------------------------------------------
// C8051F520.h
//-----------------------------------------------------------------------------
// Copyright 2006 Silicon Laboratories, Inc.
// http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
//
// Program Description:
//
// Register/bit definitions for the C8051F52x/'F53x family.
//
//
// FID:            52X000007
// Target:         C8051F52x, 'F53x
// Tool chain:     Keil
// Command Line:   None
//
// Release 1.0
//    -All changes by CG/PKC
//    -04 OCT 2006
//    -Initial Release
//
// Release 1.1
//    -All changes by CG
//    -07 AUG 2007
//    Changed the name of the register AMX0SL to ADC0MX. (0xBB address)
//

//-----------------------------------------------------------------------------
// Header File Preprocessor Directive
//-----------------------------------------------------------------------------

#ifndef C8051F520_H
#define C8051F520_H

//-----------------------------------------------------------------------------
// Byte Registers
//-----------------------------------------------------------------------------

sfr P0         = 0x80;                 // Port 0 Latch
sfr SP         = 0x81;                 // Stack Pointer
sfr DPL        = 0x82;                 // Data Pointer - Low byte
sfr DPH        = 0x83;                 // Data Pointer - High byte
sfr PCON       = 0x87;                 // Power Control
sfr TCON       = 0x88;                 // Timer Control
sfr TMOD       = 0x89;                 // Timer Mode
sfr TL0        = 0x8A;                 // Timer 0 - Low byte
sfr TL1        = 0x8B;                 // Timer 1 - Low byte
sfr TH0        = 0x8C;                 // Timer 0 - High byte
sfr TH1        = 0x8D;                 // Timer 1 - High byte
sfr CKCON      = 0x8E;                 // Clock Control
sfr PSCTL      = 0x8F;                 // Program Store R/W Control
sfr P1         = 0x90;                 // Port 1 Latch
sfr LINADDR    = 0x92;                 // LIN Indirect Access Address
sfr LINDATA    = 0x93;                 // LIN Indirect Access Data
sfr LINCF      = 0x95;                 // LIN Configuration
sfr SCON0      = 0x98;                 // UART0 Control
sfr SBUF0      = 0x99;                 // UART0 Buffer
sfr CPT0CN     = 0x9B;                 // Comparator 0 Control
sfr CPT0MD     = 0x9D;                 // Comparator 0 Mode
sfr CPT0MX     = 0x9F;                 // Comparator 0 Mux
sfr SPI0CFG    = 0xA1;                 // SPI0 Configuration
sfr SPI0CKR    = 0xA2;                 // SPI0 Clock Rate
sfr SPI0DAT    = 0xA3;                 // SPI0 Data
sfr P0MDOUT    = 0xA4;                 // Port 0 Output Mode Configuration
sfr P1MDOUT    = 0xA5;                 // Port 1 Output Mode Configuration
sfr IE         = 0xA8;                 // Interrupt Enable
sfr CLKSEL     = 0xA9;                 // Clock Select
sfr OSCIFIN    = 0xB0;                 // Internal Fine Oscillator Calibration
sfr OSCXCN     = 0xB1;                 // External Oscillator Control
sfr OSCICN     = 0xB2;                 // Internal Oscillator Control
sfr OSCICL     = 0xB3;                 // Internal Oscillator Calibration
sfr FLKEY      = 0xB7;                 // Flash Lock & Key
sfr IP         = 0xB8;                 // Interrupt Priority
sfr ADC0TK     = 0xBA;                 // ADC0 Tracking
sfr ADC0MX     = 0xBB;                 // ADC0 Mux Channel Selection
sfr ADC0CF     = 0xBC;                 // ADC0 CONFIGURATION
sfr ADC0L      = 0xBD;                 // ADC0 LSB Result
sfr ADC0H      = 0xBE;                 // ADC0 Data
sfr P1MASK     = 0xBF;                 // Port 1 Mask
sfr ADC0GTL    = 0xC3;                 // ADC0 Greater-Than Compare Low
sfr ADC0GTH    = 0xC4;                 // ADC0 Greater-Than Compare High
sfr ADC0LTL    = 0xC5;                 // ADC0 Less-Than Compare Word Low
sfr ADC0LTH    = 0xC6;                 // ADC0 Less-Than Compare Word High
sfr P0MASK     = 0xC7;                 // Port 1 Mask
sfr TMR2CN     = 0xC8;                 // Timer 2 Control
sfr REG0CN     = 0xC9;                 // Regulator Control
sfr TMR2RLL    = 0xCA;                 // Timer 2 Reload Low
sfr TMR2RLH    = 0xCB;                 // Timer 2 Reload High
sfr TMR2L      = 0xCC;                 // Timer 2 Low Byte
sfr TMR2H      = 0xCD;                 // Timer 2 High Byte
sfr P1MAT      = 0xCF;                 // Port1 Match
sfr PSW        = 0xD0;                 // Program Status Word
sfr REF0CN     = 0xD1;                 // Voltage Reference 0 Control
sfr P0SKIP     = 0xD4;                 // Port 0 Skip
sfr P1SKIP     = 0xD5;                 // Port 1 Skip
sfr P0MAT      = 0xD7;                 // Port 0 Match
sfr PCA0CN     = 0xD8;                 // PCA0 Control
sfr PCA0MD     = 0xD9;                 // PCA0 Mode
sfr PCA0CPM0   = 0xDA;                 // PCA0 Module 0 Mode
sfr PCA0CPM1   = 0xDB;                 // PCA0 Module 1 Mode
sfr PCA0CPM2   = 0xDC;                 // PCA0 Module 2 Mode
sfr ACC        = 0xE0;                 // Accumulator
sfr XBR0       = 0xE1;                 // Digital Crossbar Configuration 0
sfr XBR1       = 0xE2;                 // Digital Crossbar Configuration 1
sfr IT01CF     = 0xE4;                 // INT0/INT1 Configuration
sfr EIE1       = 0xE6;                 // Extended Interrupt Enable 1
sfr ADC0CN     = 0xE8;                 // ADC 0 Control
sfr PCA0CPL1   = 0xE9;                 // PCA0 Module 1 Capture/Compare Low Byte
sfr PCA0CPH1   = 0xEA;                 // PCA0 Module 1 Capture/Compare High Byte
sfr PCA0CPL2   = 0xEB;                 // PCA0 Module 2 Capture/Compare Low Byte
sfr PCA0CPH2   = 0xEC;                 // PCA0 Module 2 Capture/Compare High Byte
sfr RSTSRC     = 0xEF;                 // Reset Source Configuration/Status
sfr B          = 0xF0;                 // B Register
sfr P0MDIN     = 0xF1;                 // Port 0 Input Mode
sfr P1MDIN     = 0xF2;                 // Port 1 Input Mode
sfr EIP1       = 0xF6;                 // Extended Interrupt Priority 1
sfr SPI0CN     = 0xF8;                 // SPI0 Control
sfr PCA0L      = 0xF9;                 // PCA0 Counter Low Byte
sfr PCA0H      = 0xFA;                 // PCA0 Counter High Byte
sfr PCA0CPL0   = 0xFB;                 // PCA Module 0 Capture/Compare Low Byte
sfr PCA0CPH0   = 0xFC;                 // PCA Module 0 Capture/Compare High Byte
sfr VDDMON     = 0xFF;                 // VDD Monitor

//-----------------------------------------------------------------------------
// Bit Definitions
//-----------------------------------------------------------------------------

// TCON  0x88
sbit TF1       = TCON^7;               // Timer 1 Overflow Flag
sbit TR1       = TCON^6;               // Timer 1 On/Off Control
sbit TF0       = TCON^5;               // Timer 0 Overflow Flag
sbit TR0       = TCON^4;               // Timer 0 On/Off Control
sbit IE1       = TCON^3;               // External Interrupt 1 Edge Flag
sbit IT1       = TCON^2;               // External Interrupt 1 Type
sbit IE0       = TCON^1;               // External Interrupt 0 Edge Flag
sbit IT0       = TCON^0;               // External Interrupt 0 Type

// SCON0  0x98
sbit S0MODE    = SCON0^7;              // Serial Mode Control Bit 0
                                       // Bit6 UNUSED
sbit MCE0      = SCON0^5;              // Multiprocessor Communication Enable
sbit REN0      = SCON0^4;              // Receive Enable
sbit TB80      = SCON0^3;              // Transmit Bit 8
sbit RB80      = SCON0^2;              // Receive Bit 8
sbit TI0       = SCON0^1;              // Transmit Interrupt Flag
sbit RI0       = SCON0^0;              // Receive Interrupt Flag

// IE  0xA8
sbit EA        = IE^7;                 // Global Interrupt Enable
sbit ESPI0     = IE^6;                 // SPI0 Interrupt Enable
sbit ET2       = IE^5;                 // Timer 2 Interrupt Enable
sbit ES0       = IE^4;                 // UART0 Interrupt Enable
sbit ET1       = IE^3;                 // Timer 1 Interrupt Enable
sbit EX1       = IE^2;                 // External Interrupt 1 Enable
sbit ET0       = IE^1;                 // Timer 0 Interrupt Enable
sbit EX0       = IE^0;                 // External Interrupt 0 Enable

// IP  0xB8
                                       // Bit7 UNUSED
sbit PSPI0     = IP^6;                 // SPI0 Interrupt Priority
sbit PT2       = IP^5;                 // Timer 2 Priority
sbit PS0       = IP^4;                 // UART0 Priority
sbit PT1       = IP^3;                 // Timer 1 Priority
sbit PX1       = IP^2;                 // External Interrupt 1 Priority
sbit PT0       = IP^1;                 // Timer 0 Priority
sbit PX0       = IP^0;                 // External Interrupt 0 Priority

// TMR2CN 0xC8
sbit TF2H      = TMR2CN^7;             // Timer 2 High-Byte Overflow Flag
sbit TF2L      = TMR2CN^6;             // Timer 2 Low-Byte  Overflow Flag
sbit TF2LEN    = TMR2CN^5;             // Timer 2 Low-Byte Flag Enable
sbit TF2CEN    = TMR2CN^4;             // Timer 2 Capture Enable
sbit T2SPLIT   = TMR2CN^3;             // Timer 2 Split-Mode Enable
sbit TR2       = TMR2CN^2;             // Timer 2 On/Off Control
sbit T2RCLK    = TMR2CN^1;             // Timer 2 Xclk/Rclk Select
sbit T2XCLK    = TMR2CN^0;             // Timer 2 Clk/8 Clock Source

// PSW 0xD0
sbit CY        = PSW^7;                // Carry Flag
sbit AC        = PSW^6;                // Auxiliary Carry Flag
sbit F0        = PSW^5;                // User Flag 0
sbit RS1       = PSW^4;                // Register Bank Select 1
sbit RS0       = PSW^3;                // Register Bank Select 0
sbit OV        = PSW^2;                // Overflow Flag
sbit F1        = PSW^1;                // User Flag 1
sbit P         = PSW^0;                // Accumulator Parity Flag

// PCA0CN 0xD8
sbit CF        = PCA0CN^7;             // PCA0 Counter Overflow Flag
sbit CR        = PCA0CN^6;             // PCA0 Counter Run Control Bit
                                       // Bit5 UNUSED
                                       // Bit4 UNUSED
                                       // Bit3 UNUSED
sbit CCF2      = PCA0CN^2;             // PCA0 Module 2 Interrupt Flag
sbit CCF1      = PCA0CN^1;             // PCA0 Module 1 Interrupt Flag
sbit CCF0      = PCA0CN^0;             // PCA0 Module 0 Interrupt Flag

// ADC0CN 0xE8
sbit AD0EN     = ADC0CN^7;             // ADC0 Enable
sbit BURSTEN   = ADC0CN^6;             // ADC0 Burst Enable
sbit AD0INT    = ADC0CN^5;             // ADC0 Conversion Complete Interrupt Flag
sbit AD0BUSY   = ADC0CN^4;             // ADC0 Busy Flag
sbit AD0WINT   = ADC0CN^3;             // ADC0 Window Compare Interrupt Flag
sbit AD0LJST   = ADC0CN^2;             // ADC0 Left Justified
sbit AD0CM1    = ADC0CN^1;             // ADC0 Start Of Conversion Mode Bit 1
sbit AD0CM0    = ADC0CN^0;             // ADC0 Start Of Conversion Mode Bit 0

// SPI0CN 0xF8
sbit SPIF      = SPI0CN^7;             // SPI0 Interrupt Flag
sbit WCOL      = SPI0CN^6;             // SPI0 Write Collision Flag
sbit MODF      = SPI0CN^5;             // SPI0 Mode Fault Flag
sbit RXOVRN    = SPI0CN^4;             // SPI0 Rx Overrun Flag
sbit NSSMD1    = SPI0CN^3;             // SPI0 NSS Mode Bit 1
sbit NSSMD0    = SPI0CN^2;             // SPI0 NSS Mode Bit 0
sbit TXBMT     = SPI0CN^1;             // SPI0 Transmit Buffer Empty Flag
sbit SPIEN     = SPI0CN^0;             // SPI0 Enable

//-----------------------------------------------------------------------------
// Interrupt Priorities
//-----------------------------------------------------------------------------

#define INTERRUPT_INT0                 0  // External Interrupt 0
#define INTERRUPT_TIMER0               1  // Timer0 Overflow
#define INTERRUPT_INT1                 2  // External Interrupt 1
#define INTERRUPT_TIMER1               3  // Timer1 Overflow
#define INTERRUPT_UART0                4  // Serial Port 0
#define INTERRUPT_TIMER2               5  // Timer2 Overflow
#define INTERRUPT_SPI0                 6  // Serial Peripheral Interface 0
#define INTERRUPT_ADC0_WINDOW          7  // ADC0 Window Comparison
#define INTERRUPT_ADC0_EOC             8  // ADC0 End Of Conversion
#define INTERRUPT_PCA0                 9  // PCA0 Peripheral
#define INTERRUPT_COMPARATOR_FALLING  10  // Comparator Falling edge
#define INTERRUPT_COMPARATOR_RISING   11  // Comparator Rising edge
#define INTERRUPT_LIN                 12  // LIN interrupt
#define INTERRUPT_VREG                13  // Voltage Regulator Dropout
#define INTERRUPT_PORT_MATCH          14  // Port Match

//-----------------------------------------------------------------------------
// Header File PreProcessor Directive
//-----------------------------------------------------------------------------

#endif                                 // #define C8051F520_H

//-----------------------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------------------