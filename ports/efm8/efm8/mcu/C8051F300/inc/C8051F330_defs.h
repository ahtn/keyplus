//-----------------------------------------------------------------------------
// C8051F330_defs.h
//-----------------------------------------------------------------------------
// Copyright 2014 Silicon Laboratories, Inc.
// http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
//
// Program Description:
//
// Register/bit definitions for the C8051F33x family.
// **Important Note**: The compiler_defs.h header file should be included
// before including this header file.
//
// Target:         C8051F330, 'F331, 'F333, 'F334, 'F335
// Tool chain:     Generic
// Command Line:   None
//
// Release 1.4 - 20 AUG 2012 (TP)
//    -Added #define for _XPAGE to provide support for SDCC memory paging
//     (pdata)
// Release 1.3 - 07 AUG 2007 (PKC)
//    -Removed #include <compiler_defs.h>. The C source file should include it.
//    -Removed FID and fixed formatting.
// Release 1.2 - 29 SEP 2006 (PKC)
//    -Reformatted header file to enable portable SFR definitions
// Release 1.1 - 11 JAN 2006 (GP)
//    -Converted file to new coding guidelines
//    -Added #defines for interrupt priorities
//    -Added #ifndef/#define to allow multiple includes of file
// Release 1.0
//    -Latest release before new firmware coding standard

//-----------------------------------------------------------------------------
// Header File Preprocessor Directive
//-----------------------------------------------------------------------------

#ifndef C8051F330_DEFS_H
#define C8051F330_DEFS_H

//-----------------------------------------------------------------------------
// Byte Registers
//-----------------------------------------------------------------------------

SFR (P0, 0x80);                        // Port 0 Latch
SFR (SP, 0x81);                        // Stack Pointer
SFR (DPL, 0x82);                       // Data Pointer Low
SFR (DPH, 0x83);                       // Data Pointer High
SFR (PCON, 0x87);                      // Power Control
SFR (TCON, 0x88);                      // Timer/Counter Control
SFR (TMOD, 0x89);                      // Timer/Counter Mode
SFR (TL0, 0x8A);                       // Timer/Counter 0 Low
SFR (TL1, 0x8B);                       // Timer/Counter 1 Low
SFR (TH0, 0x8C);                       // Timer/Counter 0 High
SFR (TH1, 0x8D);                       // Timer/Counter 1 High
SFR (CKCON, 0x8E);                     // Clock Control
SFR (PSCTL, 0x8F);                     // Program Store R/W Control
SFR (P1, 0x90);                        // Port 1 Latch
SFR (TMR3CN, 0x91);                    // Timer/Counter 3 Control
SFR (TMR3RLL, 0x92);                   // Timer/Counter 3 Reload Low
SFR (TMR3RLH, 0x93);                   // Timer/Counter 3 Reload High
SFR (TMR3L, 0x94);                     // Timer/Counter 3 Low
SFR (TMR3H, 0x95);                     // Timer/Counter 3 High
SFR (IDA0L, 0x96);                     // Current Mode Dac0 Low
SFR (IDA0H, 0x97);                     // Current Mode Dac0 High
SFR (SCON0, 0x98);                     // UART0 Control
SFR (SBUF0, 0x99);                     // UART0 Data Buffer
SFR (CPT0CN, 0x9B);                    // Comparator0 Control
SFR (CPT0MD, 0x9D);                    // Comparator0 Mode Selection
SFR (CPT0MX, 0x9F);                    // Comparator0 Mux Selection
SFR (P2, 0xA0);                        // Port 2 Latch
SFR (SPI0CFG, 0xA1);                   // SPI0 Configuration
SFR (SPI0CKR, 0xA2);                   // SPI0 Clock Rate Control
SFR (SPI0DAT, 0xA3);                   // SPI0 Data
SFR (P0MDOUT, 0xA4);                   // Port 0 Output Mode Configuration
SFR (P1MDOUT, 0xA5);                   // Port 1 Output Mode Configuration
SFR (P2MDOUT, 0xA6);                   // Port 2 Output Mode Configuration
SFR (IE, 0xA8);                        // Interrupt Enable
SFR (CLKSEL, 0xA9);                    // Clock Select
SFR (EMI0CN, 0xAA);                    // External Memory Interface Control
SFR (OSCXCN, 0xB1);                    // External Oscillator Control
SFR (OSCICN, 0xB2);                    // Internal Oscillator Control
SFR (OSCICL, 0xB3);                    // Internal Oscillator Calibration
SFR (FLSCL, 0xB6);                     // Flash Scale
SFR (FLKEY, 0xB7);                     // Flash Lock And Key
SFR (IP, 0xB8);                        // Interrupt Priority
SFR (IDA0CN, 0xB9);                    // Current Mode DAC0 Control
SFR (AMX0N, 0xBA);                     // AMUX0 Negative Channel Select
SFR (AMX0P, 0xBB);                     // AMUX0 Positive Channel Select
SFR (ADC0CF, 0xBC);                    // ADC0 Configuration
SFR (ADC0L, 0xBD);                     // ADC0 Low
SFR (ADC0H, 0xBE);                     // ADC0 High
SFR (SMB0CN, 0xC0);                    // SMBus0 Control
SFR (SMB0CF, 0xC1);                    // SMBus0 Configuration
SFR (SMB0DAT, 0xC2);                   // SMBus0 Data
SFR (ADC0GTL, 0xC3);                   // ADC0 Greater-Than Compare Low
SFR (ADC0GTH, 0xC4);                   // ADC0 Greater-Than Compare High
SFR (ADC0LTL, 0xC5);                   // ADC0 Less-Than Compare Word Low
SFR (ADC0LTH, 0xC6);                   // ADC0 Less-Than Compare Word High
SFR (TMR2CN, 0xC8);                    // Timer/Counter 2 Control
SFR (TMR2RLL, 0xCA);                   // Timer/Counter 2 Reload Low
SFR (TMR2RLH, 0xCB);                   // Timer/Counter 2 Reload High
SFR (TMR2L, 0xCC);                     // Timer/Counter 2 Low
SFR (TMR2H, 0xCD);                     // Timer/Counter 2 High
SFR (PSW, 0xD0);                       // Program Status Word
SFR (REF0CN, 0xD1);                    // Voltage Reference Control
SFR (P0SKIP, 0xD4);                    // Port 0 Skip
SFR (P1SKIP, 0xD5);                    // Port 1 Skip
SFR (PCA0CN, 0xD8);                    // PCA0 Control
SFR (PCA0MD, 0xD9);                    // PCA0 Mode
SFR (PCA0CPM0, 0xDA);                  // PCA0 Module 0 Mode Register
SFR (PCA0CPM1, 0xDB);                  // PCA0 Module 1 Mode Register
SFR (PCA0CPM2, 0xDC);                  // PCA0 Module 2 Mode Register
SFR (ACC, 0xE0);                       // Accumulator
SFR (XBR0, 0xE1);                      // Port I/O Crossbar Control 0
SFR (XBR1, 0xE2);                      // Port I/O Crossbar Control 1
SFR (OSCLCN, 0xE3);                    // Low-Frequency Oscillator Control
SFR (IT01CF, 0xE4);                    // INT0/INT1 Configuration
SFR (EIE1, 0xE6);                      // Extended Interrupt Enable 1
SFR (ADC0CN, 0xE8);                    // ADC0 Control
SFR (PCA0CPL1, 0xE9);                  // PCA0 Capture 1 Low
SFR (PCA0CPH1, 0xEA);                  // PCA0 Capture 1 High
SFR (PCA0CPL2, 0xEB);                  // PCA0 Capture 2 Low
SFR (PCA0CPH2, 0xEC);                  // PCA0 Capture 2 High
SFR (RSTSRC, 0xEF);                    // Reset Source Configuration/Status
SFR (B, 0xF0);                         // B Register
SFR (P0MDIN, 0xF1);                    // Port 0 Input Mode Configuration
SFR (P1MDIN, 0xF2);                    // Port 1 Input Mode Configuration
SFR (EIP1, 0xF6);                      // Extended Interrupt Priority 1
SFR (SPI0CN, 0xF8);                    // SPI0 Control
SFR (PCA0L, 0xF9);                     // PCA0 Counter Low
SFR (PCA0H, 0xFA);                     // PCA0 Counter High
SFR (PCA0CPL0, 0xFB);                  // PCA0 Capture 0 Low
SFR (PCA0CPH0, 0xFC);                  // PCA0 Capture 0 High
SFR (VDM0CN, 0xFF);                    // VDD Monitor Control

//-----------------------------------------------------------------------------
// 16-bit Register Definitions (might not be supported by all compilers)
//-----------------------------------------------------------------------------

SFR16 (DP, 0x82);                      // Data Pointer
SFR16 (TMR3RL, 0x92);                  // Timer 3 Reload
SFR16 (TMR3, 0x94);                    // Timer 3 Counter
SFR16 (IDA0, 0x96);                    // IDAC0 Data
SFR16 (ADC0, 0xBD);                    // ADC0 Data
SFR16 (ADC0GT, 0xC3);                  // ADC0 Greater-Than Compare
SFR16 (ADC0LT, 0xC5);                  // ADC0 Less-Than Compare
SFR16 (TMR2RL, 0xCA);                  // Timer 2 Reload
SFR16 (TMR2, 0xCC);                    // Timer 2 Counter
SFR16 (PCA0CP1, 0xE9);                 // PCA0 Module 1 Capture/Compare
SFR16 (PCA0CP2, 0xEB);                 // PCA0 Module 2 Capture/Compare
SFR16 (PCA0, 0xF9);                    // PCA0 Counter
SFR16 (PCA0CP0, 0xFB);                 // PCA0 Module 0 Capture/Compare

//-----------------------------------------------------------------------------
// Address Definitions for Bit-addressable Registers
//-----------------------------------------------------------------------------

#define SFR_P0       0x80
#define SFR_TCON     0x88
#define SFR_P1       0x90
#define SFR_SCON0    0x98
#define SFR_P2       0xA0
#define SFR_IE       0xA8
// Address 0xB0 UNUSED
#define SFR_IP       0xB8
#define SFR_SMB0CN   0xC0
#define SFR_TMR2CN   0xC8
#define SFR_PSW      0xD0
#define SFR_PCA0CN   0xD8
#define SFR_ACC      0xE0
#define SFR_ADC0CN   0xE8
#define SFR_B        0xF0
#define SFR_SPI0CN   0xF8

//-----------------------------------------------------------------------------
// Bit Definitions
//-----------------------------------------------------------------------------

// TCON 0x88
SBIT (TF1, SFR_TCON, 7);               // Timer 1 Overflow Flag
SBIT (TR1, SFR_TCON, 6);               // Timer 1 On/Off Control
SBIT (TF0, SFR_TCON, 5);               // Timer 0 Overflow Flag
SBIT (TR0, SFR_TCON, 4);               // Timer 0 On/Off Control
SBIT (IE1, SFR_TCON, 3);               // Ext. Interrupt 1 Edge Flag
SBIT (IT1, SFR_TCON, 2);               // Ext. Interrupt 1 Type
SBIT (IE0, SFR_TCON, 1);               // Ext. Interrupt 0 Edge Flag
SBIT (IT0, SFR_TCON, 0);               // Ext. Interrupt 0 Type

// SCON0 0x98
SBIT (S0MODE, SFR_SCON0, 7);           // UART0 Mode
                                       // Bit6 UNUSED
SBIT (MCE0, SFR_SCON0, 5);             // UART0 MCE
SBIT (REN0, SFR_SCON0, 4);             // UART0 RX Enable
SBIT (TB80, SFR_SCON0, 3);             // UART0 TX Bit 8
SBIT (RB80, SFR_SCON0, 2);             // UART0 RX Bit 8
SBIT (TI0, SFR_SCON0, 1);              // UART0 TX Interrupt Flag
SBIT (RI0, SFR_SCON0, 0);              // UART0 RX Interrupt Flag

// IE 0xA8
SBIT (EA, SFR_IE, 7);                  // Global Interrupt Enable
SBIT (ESPI0, SFR_IE, 6);               // SPI0 Interrupt Enable
SBIT (ET2, SFR_IE, 5);                 // Timer 2 Interrupt Enable
SBIT (ES0, SFR_IE, 4);                 // UART0 Interrupt Enable
SBIT (ET1, SFR_IE, 3);                 // Timer 1 Interrupt Enable
SBIT (EX1, SFR_IE, 2);                 // External Interrupt 1 Enable
SBIT (ET0, SFR_IE, 1);                 // Timer 0 Interrupt Enable
SBIT (EX0, SFR_IE, 0);                 // External Interrupt 0 Enable

// IP 0xB8
                                       // Bit7 UNUSED
SBIT (PSPI0, SFR_IP, 6);               // SPI0 Priority
SBIT (PT2, SFR_IP, 5);                 // Timer 2 Priority
SBIT (PS0, SFR_IP, 4);                 // UART0 Priority
SBIT (PT1, SFR_IP, 3);                 // Timer 1 Priority
SBIT (PX1, SFR_IP, 2);                 // External Interrupt 1 Priority
SBIT (PT0, SFR_IP, 1);                 // Timer 0 Priority
SBIT (PX0, SFR_IP, 0);                 // External Interrupt 0 Priority

// SMB0CN 0xC0
SBIT (MASTER, SFR_SMB0CN, 7);          // SMBus0 Master/Slave
SBIT (TXMODE, SFR_SMB0CN, 6);          // SMBus0 Transmit Mode
SBIT (STA, SFR_SMB0CN, 5);             // SMBus0 Start Flag
SBIT (STO, SFR_SMB0CN, 4);             // SMBus0 Stop Flag
SBIT (ACKRQ, SFR_SMB0CN, 3);           // SMBus0 Acknowledge Request
SBIT (ARBLOST, SFR_SMB0CN, 2);         // SMBus0 Arbitration Lost
SBIT (ACK, SFR_SMB0CN, 1);             // SMBus0 Acknowledge Flag
SBIT (SI, SFR_SMB0CN, 0);              // SMBus0 Interrupt Pending Flag

// TMR2CN 0xC8
SBIT (TF2H, SFR_TMR2CN, 7);            // Timer 2 High Byte Overflow Flag
SBIT (TF2L, SFR_TMR2CN, 6);            // Timer 2 Low Byte Overflow Flag
SBIT (TF2LEN, SFR_TMR2CN, 5);          // Timer 2 Low Byte Interrupt Enable
SBIT (TF2CEN, SFR_TMR2CN, 4);          // Timer 2 Lfo Capture Enable
SBIT (T2SPLIT, SFR_TMR2CN, 3);         // Timer 2 Split Mode Enable
SBIT (TR2, SFR_TMR2CN, 2);             // Timer 2 On/Off Control
                                       // Bit6 UNUSED
SBIT (T2XCLK, SFR_TMR2CN, 0);          // Timer 2 External Clock Select

// PSW 0xD0
SBIT (CY, SFR_PSW, 7);                 // Carry Flag
SBIT (AC, SFR_PSW, 6);                 // Auxiliary Carry Flag
SBIT (F0, SFR_PSW, 5);                 // User Flag 0
SBIT (RS1, SFR_PSW, 4);                // Register Bank Select 1
SBIT (RS0, SFR_PSW, 3);                // Register Bank Select 0
SBIT (OV, SFR_PSW, 2);                 // Overflow Flag
SBIT (F1, SFR_PSW, 1);                 // User Flag 1
SBIT (P, SFR_PSW, 0);                  // Accumulator Parity Flag

// PCA0CN 0xD8
SBIT (CF, SFR_PCA0CN, 7);              // PCA0 Counter Overflow Flag
SBIT (CR, SFR_PCA0CN, 6);              // PCA0 Counter Run Control Bit
                                       // Bit5 UNUSED
                                       // Bit4 UNUSED
                                       // Bit3 UNUSED
SBIT (CCF2, SFR_PCA0CN, 2);            // PCA0 Module 2 Interrupt Flag
SBIT (CCF1, SFR_PCA0CN, 1);            // PCA0 Module 1 Interrupt Flag
SBIT (CCF0, SFR_PCA0CN, 0);            // PCA0 Module 0 Interrupt Flag

// ADC0CN 0xE8
SBIT (AD0EN, SFR_ADC0CN, 7);           // ADC0 Enable
SBIT (AD0TM, SFR_ADC0CN, 6);           // ADC0 Track Mode
SBIT (AD0INT, SFR_ADC0CN, 5);          // ADC0 EOC Interrupt Flag
SBIT (AD0BUSY, SFR_ADC0CN, 4);         // ADC0 Busy Flag
SBIT (AD0WINT, SFR_ADC0CN, 3);         // ADC0 Window Interrupt Flag
SBIT (AD0CM2, SFR_ADC0CN, 2);          // ADC0 Convert Start Mode Bit 2
SBIT (AD0CM1, SFR_ADC0CN, 1);          // ADC0 Convert Start Mode Bit 1
SBIT (AD0CM0, SFR_ADC0CN, 0);          // ADC0 Convert Start Mode Bit 0

// SPI0CN 0xF8
SBIT (SPIF, SFR_SPI0CN, 7);            // SPI0 Interrupt Flag
SBIT (WCOL, SFR_SPI0CN, 6);            // SPI0 Write Collision Flag
SBIT (MODF, SFR_SPI0CN, 5);            // SPI0 Mode Fault Flag
SBIT (RXOVRN, SFR_SPI0CN, 4);          // SPI0 RX Overrun Flag
SBIT (NSSMD1, SFR_SPI0CN, 3);          // SPI0 Slave Select Mode 1
SBIT (NSSMD0, SFR_SPI0CN, 2);          // SPI0 Slave Select Mode 0
SBIT (TXBMT, SFR_SPI0CN, 1);           // SPI0 TX Buffer Empty Flag
SBIT (SPIEN, SFR_SPI0CN, 0);           // SPI0 SPI0 Enable

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
                                       // Interrupt 8 is RESERVED
#define INTERRUPT_ADC0_WINDOW      9   // ADC0 Window Comparison
#define INTERRUPT_ADC0_EOC         10  // ADC0 End Of Conversion
#define INTERRUPT_PCA0             11  // PCA0 Peripheral
#define INTERRUPT_COMPARATOR0      12  // Comparator0
                                       // Interrupt 13 is RESERVED
#define INTERRUPT_TIMER3           14  // Timer3 Overflow

//-----------------------------------------------------------------------------
// SDCC PDATA External Memory Paging Support
//-----------------------------------------------------------------------------

#if defined SDCC

SFR(_XPAGE, 0xAA); // Point to the EMI0CN register

#endif

//-----------------------------------------------------------------------------
// Header File PreProcessor Directive
//-----------------------------------------------------------------------------

#endif                                 // #define C8051F330_DEFS_H

//-----------------------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------------------