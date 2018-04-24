//-----------------------------------------------------------------------------
// C8051F310_defs.h
//-----------------------------------------------------------------------------
// Copyright 2014 Silicon Laboratories, Inc.
// http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
//
// Program Description:
//
// Register/bit definitions for the C8051F31x family.
// **Important Note**: The compiler_defs.h header file should be included
// before including this header file.
//
// Target:         C8051F310, 'F311, 'F312, 'F313, 'F314, 'F315, 'F316, 'F317
// Tool chain:     Generic
// Command Line:   None
//
// Release 1.5 - 20 AUG 2012 (TP)
//    -Added #define for _XPAGE to provide support for SDCC memory paging
//     (pdata)
// Release 1.4 - 22 JULY 2008 (ES)
//    -Updated TMR2CN register bits
// Release 1.3 - 07 AUG 2007 (PKC)
//    -Removed #include <compiler_defs.h>. The C source file should include it.
//    -Removed FID and fixed formatting.
// Release 1.2 - 29 SEP 2006 (PKC/BW)
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

#ifndef C8051F310_DEFS_H
#define C8051F310_DEFS_H

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
SFR (SCON0, 0x98);                     // UART0 Control
SFR (SBUF0, 0x99);                     // UART0 Data Buffer
SFR (CPT1CN, 0x9A);                    // Comparator1 Control
SFR (CPT0CN, 0x9B);                    // Comparator0 Control
SFR (CPT1MD, 0x9C);                    // Comparator1 Mode Selection
SFR (CPT0MD, 0x9D);                    // Comparator0 Mode Selection
SFR (CPT1MX, 0x9E);                    // Comparator1 MUX Selection
SFR (CPT0MX, 0x9F);                    // Comparator0 MUX Selection
SFR (P2, 0xA0);                        // Port 2 Latch
SFR (SPI0CFG, 0xA1);                   // SPI Configuration
SFR (SPI0CKR, 0xA2);                   // SPI Clock Rate Control
SFR (SPI0DAT, 0xA3);                   // SPI Data
SFR (P0MDOUT, 0xA4);                   // Port 0 Output Mode Configuration
SFR (P1MDOUT, 0xA5);                   // Port 1 Output Mode Configuration
SFR (P2MDOUT, 0xA6);                   // Port 2 Output Mode Configuration
SFR (P3MDOUT, 0xA7);                   // Port 3 Output Mode Configuration
SFR (IE, 0xA8);                        // Interrupt Enable
SFR (CLKSEL, 0xA9);                    // Clock Select
SFR (EMI0CN, 0xAA);                    // External Memory Interface Control
SFR (P3, 0xB0);                        // Port 3 Latch
SFR (OSCXCN, 0xB1);                    // External Oscillator Control
SFR (OSCICN, 0xB2);                    // Internal Oscillator Control
SFR (OSCICL, 0xB3);                    // Internal Oscillator Calibration
SFR (FLSCL, 0xB6);                     // Flash Scale
SFR (FLKEY, 0xB7);                     // Flash Lock and Key
SFR (IP, 0xB8);                        // Interrupt Priority
SFR (AMX0N, 0xBA);                     // AMUX0 Negative Channel Select
SFR (AMX0P, 0xBB);                     // AMUX0 Positive Channel Select
SFR (ADC0CF, 0xBC);                    // ADC0 Configuration
SFR (ADC0L, 0xBD);                     // ADC0 Low
SFR (ADC0H, 0xBE);                     // ADC0 High
SFR (SMB0CN, 0xC0);                    // SMBus Control
SFR (SMB0CF, 0xC1);                    // SMBus Configuration
SFR (SMB0DAT, 0xC2);                   // SMBus Data
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
SFR (P2SKIP, 0xD6);                    // Port 2 Skip
SFR (PCA0CN, 0xD8);                    // PCA0 Control
SFR (PCA0MD, 0xD9);                    // PCA0 Mode
SFR (PCA0CPM0, 0xDA);                  // PCA0 Module 0 Mode Register
SFR (PCA0CPM1, 0xDB);                  // PCA0 Module 1 Mode Register
SFR (PCA0CPM2, 0xDC);                  // PCA0 Module 2 Mode Register
SFR (PCA0CPM3, 0xDD);                  // PCA0 Module 3 Mode Register
SFR (PCA0CPM4, 0xDE);                  // PCA0 Module 4 Mode Register
SFR (ACC, 0xE0);                       // Accumulator
SFR (XBR0, 0xE1);                      // Port I/O Crossbar Control 0
SFR (XBR1, 0xE2);                      // Port I/O Crossbar Control 1
SFR (IT01CF, 0xE4);                    // INT0/INT1 Configuration
SFR (EIE1, 0xE6);                      // Extended Interrupt Enable 1
SFR (ADC0CN, 0xE8);                    // ADC0 Control
SFR (PCA0CPL1, 0xE9);                  // PCA0 Capture 1 Low
SFR (PCA0CPH1, 0xEA);                  // PCA0 Capture 1 High
SFR (PCA0CPL2, 0xEB);                  // PCA0 Capture 2 Low
SFR (PCA0CPH2, 0xEC);                  // PCA0 Capture 2 High
SFR (PCA0CPL3, 0xED);                  // PCA0 Capture 3 Low
SFR (PCA0CPH3, 0xEE);                  // PCA0 Capture 3 High
SFR (RSTSRC, 0xEF);                    // Reset Source Configuration/Status
SFR (B, 0xF0);                         // B Register
SFR (P0MDIN, 0xF1);                    // Port 0 Input Mode Configuration
SFR (P1MDIN, 0xF2);                    // Port 1 Input Mode Configuration
SFR (P2MDIN, 0xF3);                    // Port 2 Input Mode Configuration
SFR (P3MDIN, 0xF4);                    // Port 3 Input Mode Configuration
SFR (EIP1, 0xF6);                      // Extended Interrupt Priority 1
SFR (SPI0CN, 0xF8);                    // SPI0 Control
SFR (PCA0L, 0xF9);                     // PCA0 Counter Low
SFR (PCA0H, 0xFA);                     // PCA0 Counter High
SFR (PCA0CPL0, 0xFB);                  // PCA0 Capture 0 Low
SFR (PCA0CPH0, 0xFC);                  // PCA0 Capture 0 High
SFR (PCA0CPL4, 0xFD);                  // PCA0 Capture 4 Low
SFR (PCA0CPH4, 0xFE);                  // PCA0 Capture 4 High
SFR (VDM0CN, 0xFF);                    // VDD Monitor Control

//-----------------------------------------------------------------------------
// Word Registers
//-----------------------------------------------------------------------------
SFR16 (DP, 0x82);
SFR16 (TMR3RL, 0x92);
SFR16 (TMR3, 0x94);
SFR16 (ADC0, 0xBD);
SFR16 (ADC0GT, 0xC3);
SFR16 (ADC0LT, 0xC5);
SFR16 (TMR2RL, 0xCA);
SFR16 (TMR2, 0xCC);
SFR16 (PCA0CP1, 0xE9);
SFR16 (PCA0CP2, 0xEB);
SFR16 (PCA0CP3, 0xED);
SFR16 (PCA0, 0xF9);
SFR16 (PCA0CP0, 0xFB);
SFR16 (PCA0CP4, 0xFD);

//-----------------------------------------------------------------------------
// Address Definitions for bit-addressable SFRs
//-----------------------------------------------------------------------------
#define SFR_P0     0x80
#define SFR_TCON   0x88
#define SFR_P1     0x90
#define SFR_SCON0  0x98
#define SFR_P2     0xA0
#define SFR_IE     0xA8
#define SFR_P3     0xB0
#define SFR_IP     0xB8
#define SFR_SMB0CN 0xC0
#define SFR_TMR2CN 0xC8
#define SFR_PSW    0xD0
#define SFR_PCA0CN 0xD8
#define SFR_ACC    0xE0
#define SFR_ADC0CN 0xE8
#define SFR_B      0xF0
#define SFR_SPI0CN 0xF8

//-----------------------------------------------------------------------------
// Bit Definitions
//-----------------------------------------------------------------------------

// TCON 0x88
SBIT (TF1, SFR_TCON, 7);               // Timer1 overflow flag
SBIT (TR1, SFR_TCON, 6);               // Timer1 on/off control
SBIT (TF0, SFR_TCON, 5);               // Timer0 overflow flag
SBIT (TR0, SFR_TCON, 4);               // Timer0 on/off control
SBIT (IE1, SFR_TCON, 3);               // Ext interrupt 1 edge flag
SBIT (IT1, SFR_TCON, 2);               // Ext interrupt 1 type
SBIT (IE0, SFR_TCON, 1);               // Ext interrupt 0 edge flag
SBIT (IT0, SFR_TCON, 0);               // Ext interrupt 0 type

// SCON0 0x98
SBIT (S0MODE, SFR_SCON0, 7);           // Serial mode control bit 0
                                       // Bit6 UNUSED
SBIT (MCE0, SFR_SCON0, 5);             // Multiprocessor communication enable
SBIT (REN0, SFR_SCON0, 4);             // Receive enable
SBIT (TB80, SFR_SCON0, 3);             // Transmit bit 8
SBIT (RB80, SFR_SCON0, 2);             // Receive bit 8
SBIT (TI0,  SFR_SCON0, 1);             // Transmit interrupt flag
SBIT (RI0,  SFR_SCON0, 0);             // Receive interrupt flag

// IE 0xA8
SBIT (EA,    SFR_IE, 7);               // Global interrupt enable
SBIT (ESPI0, SFR_IE, 6);               // SPI0 interrupt enable
SBIT (ET2,   SFR_IE, 5);               // Timer2 interrupt enable
SBIT (ES0,   SFR_IE, 4);               // UART0 interrupt enable
SBIT (ET1,   SFR_IE, 3);               // Timer1 interrupt enable
SBIT (EX1,   SFR_IE, 2);               // External interrupt 1 enable
SBIT (ET0,   SFR_IE, 1);               // Timer0 interrupt enable
SBIT (EX0,   SFR_IE, 0);               // External interrupt 0 enable

// IP 0xB8
                                       // Bit7 UNUSED
SBIT (PSPI0, SFR_IP, 6);               // SPI0 interrupt priority
SBIT (PT2,   SFR_IP, 5);               // Timer2 priority
SBIT (PS0,   SFR_IP, 4);               // UART0 priority
SBIT (PT1,   SFR_IP, 3);               // Timer1 priority
SBIT (PX1,   SFR_IP, 2);               // External interrupt 1 priority
SBIT (PT0,   SFR_IP, 1);               // Timer0 priority
SBIT (PX0,   SFR_IP, 0);               // External interrupt 0 priority

// SMB0CN 0xC0
SBIT (MASTER,  SFR_SMB0CN, 7);         // Master/slave indicator
SBIT (TXMODE,  SFR_SMB0CN, 6);         // Transmit mode indicator
SBIT (STA,     SFR_SMB0CN, 5);         // Start flag
SBIT (STO,     SFR_SMB0CN, 4);         // Stop flag
SBIT (ACKRQ,   SFR_SMB0CN, 3);         // Acknowledge request
SBIT (ARBLOST, SFR_SMB0CN, 2);         // Arbitration lost indicator
SBIT (ACK,     SFR_SMB0CN, 1);         // Acknowledge flag
SBIT (SI,      SFR_SMB0CN, 0);         // SMBus interrupt flag

// TMR2CN 0xC8
SBIT (TF2H,    SFR_TMR2CN, 7);         // Timer2 high byte overflow flag
SBIT (TF2L,    SFR_TMR2CN, 6);         // Timer2 low byte overflow flag
SBIT (TF2LEN,  SFR_TMR2CN, 5);         // Timer2 low byte interrupt enable
                                       // Bit4 UNUSED
SBIT (T2SPLIT, SFR_TMR2CN, 3);         // Timer2 split mode enable
SBIT (TR2,     SFR_TMR2CN, 2);         // Timer2 on/off control
                                       // Bit1 UNUSED
SBIT (T2XCLK,  SFR_TMR2CN, 0);         // Timer2 external clock select

// PSW 0xD0
SBIT (CY,  SFR_PSW, 7);                // Carry flag
SBIT (AC,  SFR_PSW, 6);                // Auxiliary carry flag
SBIT (F0,  SFR_PSW, 5);                // User flag 0
SBIT (RS1, SFR_PSW, 4);                // Register bank select 1
SBIT (RS0, SFR_PSW, 3);                // Register bank select 0
SBIT (OV,  SFR_PSW, 2);                // Overflow flag
SBIT (F1,  SFR_PSW, 1);                // User flag 1
SBIT (P,   SFR_PSW, 0);                // Accumulator parity flag

// PCA0CN 0xD8
SBIT (CF, SFR_PCA0CN, 7);              // PCA0 counter overflow flag
SBIT (CR, SFR_PCA0CN, 6);              // PCA0 counter run control
                                       // Bit5 UNUSED
SBIT (CCF4, SFR_PCA0CN, 4);            // PCA0 module4 capture/compare flag
SBIT (CCF3, SFR_PCA0CN, 3);            // PCA0 module3 capture/compare flag
SBIT (CCF2, SFR_PCA0CN, 2);            // PCA0 module2 capture/compare flag
SBIT (CCF1, SFR_PCA0CN, 1);            // PCA0 module1 capture/compare flag
SBIT (CCF0, SFR_PCA0CN, 0);            // PCA0 module0 capture/compare flag

// ADC0CN 0xE8
SBIT (AD0EN,   SFR_ADC0CN, 7);         // ADC0 enable
SBIT (AD0TM,   SFR_ADC0CN, 6);         // ADC0 track mode
SBIT (AD0INT,  SFR_ADC0CN, 5);         // ADC0 conversion complete interrupt flag
SBIT (AD0BUSY, SFR_ADC0CN, 4);         // ADC0 busy flag
SBIT (AD0WINT, SFR_ADC0CN, 3);         // ADC0 window compare interrupt flag
SBIT (AD0CM2,  SFR_ADC0CN, 2);         // ADC0 conversion mode select 2
SBIT (AD0CM1,  SFR_ADC0CN, 1);         // ADC0 conversion mode select 1
SBIT (AD0CM0,  SFR_ADC0CN, 0);         // ADC0 conversion mode select 0

// SPI0CN 0xF8
SBIT (SPIF,   SFR_SPI0CN, 7);          // SPI0 interrupt flag
SBIT (WCOL,   SFR_SPI0CN, 6);          // SPI0 write collision flag
SBIT (MODF,   SFR_SPI0CN, 5);          // SPI0 mode fault flag
SBIT (RXOVRN, SFR_SPI0CN, 4);          // SPI0 rx overrun flag
SBIT (NSSMD1, SFR_SPI0CN, 3);          // SPI0 slave select mode 1
SBIT (NSSMD0, SFR_SPI0CN, 2);          // SPI0 slave select mode 0
SBIT (TXBMT,  SFR_SPI0CN, 1);          // SPI0 transmit buffer empty
SBIT (SPIEN,  SFR_SPI0CN, 0);          // SPI0 SPI enable

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
                                       // 8 is reserved
#define INTERRUPT_ADC0_WINDOW      9   // ADC0 Window Comparison
#define INTERRUPT_ADC0_EOC         10  // ADC0 End Of Conversion
#define INTERRUPT_PCA0             11  // PCA0 Peripheral
#define INTERRUPT_COMPARATOR0      12  // Comparator0
#define INTERRUPT_COMPARATOR1      13  // Comparator1
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

#endif                                 // #define C8051F310_defs_h

//-----------------------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------------------