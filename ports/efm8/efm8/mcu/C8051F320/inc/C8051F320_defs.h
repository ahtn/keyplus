//-----------------------------------------------------------------------------
// C8051F320_defs.h
//-----------------------------------------------------------------------------
// Copyright 2014 Silicon Laboratories, Inc.
// http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
//
// Program Description:
//
// Register/bit definitions for the C8051F32x family.
// **Important Note**: The compiler_defs.h header file should be included
// before including this header file.
//
// Target:         C8051F320, 'F321
// Tool chain:     Generic
// Command Line:   None
//
// Release 2.5 - 20 AUG 2012 (TP)
//    -Added #define for _XPAGE to provide support for SDCC memory paging
//     (pdata)
// Release 2.4 - 07 AUG 2007 (PKC)
//    -Removed #include <compiler_defs.h>. The C source file should include it.
//    -Removed FID and fixed formatting.
// Release 2.3 - 29 SEP 2006 (BW)
//    -Added SFR16 defs
// Release 2.2 - 29 SEP 2006 (PKC)
//    -Reformatted header file to enable portable SFR definitions
// Release 2.1 - 09 DEC 2005 (GRP)
//    -Added EMI0CN
// Release 2.0 - 09 NOV 2005 (PKC)
//    -Converted file to new coding guidelines
//    -Added #defines for interrupt priorities
//    -Added #ifndef/#define to allow multiple includes of file
// Release 1.5
//    -Latest release before new firmware coding standard

//-----------------------------------------------------------------------------
// Header File Preprocessor Directive
//-----------------------------------------------------------------------------

#ifndef C8051F320_DEFS_H
#define C8051F320_DEFS_H

//-----------------------------------------------------------------------------
// Byte Registers
//-----------------------------------------------------------------------------

SFR (P0, 0x80);                        // Port0
SFR (SP, 0x81);                        // Stack pointer
SFR (DPL, 0x82);                       // Data pointer - Low byte
SFR (DPH, 0x83);                       // Data pointer - High byte
SFR (PCON, 0x87);                      // Power control register
SFR (TCON, 0x88);                      // Timer control register
SFR (TMOD, 0x89);                      // Timer mode register
SFR (TL0, 0x8A);                       // Timer0 - Low byte
SFR (TL1, 0x8B);                       // Timer1 - Low byte
SFR (TH0, 0x8C);                       // Timer0 - High byte
SFR (TH1, 0x8D);                       // Timer1 - High byte
SFR (CKCON, 0x8E);                     // Clock control register
SFR (PSCTL, 0x8F);                     // Program store r/w control
SFR (P1, 0x90);                        // Port1
SFR (TMR3CN, 0x91);                    // Timer3 control register
SFR (TMR3RLL, 0x92);                   // Timer3 reload register - Low byte
SFR (TMR3RLH, 0x93);                   // Timer3 reload register - High byte
SFR (TMR3L, 0x94);                     // Timer3 - Low byte
SFR (TMR3H, 0x95);                     // Timer3 - High byte
SFR (USB0ADR, 0x96);                   // USB0 address port
SFR (USB0DAT, 0x97);                   // USB0 data port
SFR (SCON0, 0x98);                     // UART0 control register
SFR (SBUF0, 0x99);                     // UART0 data buffer register
SFR (CPT1CN, 0x9A);                    // Comparator1 control register
SFR (CPT0CN, 0x9B);                    // Comparator0 control register
SFR (CPT1MD, 0x9C);                    // Comparator1 mode selection register
SFR (CPT0MD, 0x9D);                    // Comparator0 mode selection register
SFR (CPT1MX, 0x9E);                    // Comparator1 mux selection register
SFR (CPT0MX, 0x9F);                    // Comparator0 mux selection register
SFR (P2, 0xA0);                        // Port2
SFR (SPICFG, 0xA1);                    // SPI0 configuration register
SFR (SPI0CFG, 0xA1);                   // SPI0 configuration register
SFR (SPICKR, 0xA2);                    // SPI0 clock configuration register
SFR (SPI0CKR, 0xA2);                   // SPI0 clock configuration register
SFR (SPIDAT, 0xA3);                    // SPI0 data register
SFR (SPI0DAT, 0xA3);                   // SPI0 data register
SFR (P0MDOUT, 0xA4);                   // Port0 output mode register
SFR (P1MDOUT, 0xA5);                   // Port1 output mode register
SFR (P2MDOUT, 0xA6);                   // Port2 output mode register
SFR (P3MDOUT, 0xA7);                   // Port3 output mode register
SFR (IE, 0xA8);                        // Interrupt enable
SFR (CLKSEL, 0xA9);                    // Clock source select
SFR (EMI0CN, 0xAA);                    // External Memory Interface Control
SFR (P3, 0xB0);                        // Port3
SFR (OSCXCN, 0xB1);                    // External oscillator control
SFR (OSCICN, 0xB2);                    // Internal oscillator control
SFR (OSCICL, 0xB3);                    // Internal oscillator calibration
SFR (FLSCL, 0xB6);                     // Flash scale register
SFR (FLKEY, 0xB7);                     // Flash lock & key register
SFR (IP, 0xB8);                        // Interrupt priority
SFR (CLKMUL, 0xB9);                    // Clock multiplier control register
SFR (AMX0N, 0xBA);                     // ADC0 mux negative channel selection
SFR (AMX0P, 0xBB);                     // ADC0 mux positive channel selection
SFR (ADC0CF, 0xBC);                    // ADC0 configuration
SFR (ADC0L, 0xBD);                     // ADC0 data low
SFR (ADC0H, 0xBE);                     // ADC0 data high
SFR (SMB0CN, 0xC0);                    // SMBus control
SFR (SMB0CF, 0xC1);                    // SMBus configuration
SFR (SMB0DAT, 0xC2);                   // SMBus data
SFR (ADC0GTL, 0xC3);                   // ADC0 greater-than data low register
SFR (ADC0GTH, 0xC4);                   // ADC0 greater-than data high register
SFR (ADC0LTL, 0xC5);                   // ADC0 less-than data low register
SFR (ADC0LTH, 0xC6);                   // ADC0 less-than data high register
SFR (TMR2CN, 0xC8);                    // Timer2 control register
SFR (REG0CN, 0xC9);                    // Regulator control register
SFR (TMR2RLL, 0xCA);                   // Timer2 reload register - Low byte
SFR (TMR2RLH, 0xCB);                   // Timer2 reload register - High byte
SFR (TMR2L, 0xCC);                     // Timer2 - Low byte
SFR (TMR2H, 0xCD);                     // Timer2 - High byte
SFR (PSW, 0xD0);                       // Program Status Word
SFR (REF0CN, 0xD1);                    // Voltage reference control register
SFR (P0SKIP, 0xD4);                    // Port0 crossbar skip register
SFR (P1SKIP, 0xD5);                    // Port1 crossbar skip register
SFR (P2SKIP, 0xD6);                    // Port2 crossbar skip register
SFR (USB0XCN, 0xD7);                   // USB0 tranceiver control register
SFR (PCA0CN, 0xD8);                    // PCA0 control register
SFR (PCA0MD, 0xD9);                    // PCA0 mode register
SFR (PCA0CPM0, 0xDA);                  // Capture/compare module0 mode
SFR (PCA0CPM1, 0xDB);                  // Capture/compare module1 mode
SFR (PCA0CPM2, 0xDC);                  // Capture/compare module2 mode
SFR (PCA0CPM3, 0xDD);                  // Capture/compare module3 mode
SFR (PCA0CPM4, 0xDE);                  // Capture/compare module4 mode
SFR (ACC, 0xE0);                       // Accumulator
SFR (XBR0, 0xE1);                      // Port I/O crossbar register 0
SFR (XBR1, 0xE2);                      // Port I/O crossbar register 1
SFR (IT01CF, 0xE4);                    // Int0/int1 configuration register
SFR (EIE1, 0xE6);                      // Extended interrupt enable 1
SFR (EIE2, 0xE7);                      // Extended interrupt enable 2
SFR (ADC0CN, 0xE8);                    // ADC0 control register
SFR (PCA0CPL1, 0xE9);                  // Capture/compare module1 - Low byte
SFR (PCA0CPH1, 0xEA);                  // Capture/compare module1 - High byte
SFR (PCA0CPL2, 0xEB);                  // Capture/compare module2 - Low byte
SFR (PCA0CPH2, 0xEC);                  // Capture/compare module2 - High byte
SFR (PCA0CPL3, 0xED);                  // Capture/compare module3 - Low byte
SFR (PCA0CPH3, 0xEE);                  // Capture/compare module3 - High byte
SFR (RSTSRC, 0xEF);                    // Reset source register
SFR (B, 0xF0);                         // B register
SFR (P0MDIN, 0xF1);                    // Port0 input mode register
SFR (P1MDIN, 0xF2);                    // Port1 input mode register
SFR (P2MDIN, 0xF3);                    // Port2 input mode register
SFR (P3MDIN, 0xF4);                    // Port3 input mode register
SFR (EIP1, 0xF6);                      // Extended interrupt priority 1
SFR (EIP2, 0xF7);                      // Extended interrupt priority 2
SFR (SPI0CN, 0xF8);                    // SPI0 control register
SFR (PCA0L, 0xF9);                     // PCA0 counter/timer - Low byte
SFR (PCA0H, 0xFA);                     // PCA0 counter/timer - High byte
SFR (PCA0CPL0, 0xFB);                  // Capture/compare module0 - Low byte
SFR (PCA0CPH0, 0xFC);                  // Capture/compare module0 - High byte
SFR (PCA0CPL4, 0xFD);                  // Capture/compare module4 - Low byte
SFR (PCA0CPH4, 0xFE);                  // Capture/compare module4 - High byte
SFR (VDM0CN, 0xFF);                    // Vdd monitor control

//-----------------------------------------------------------------------------
// 16-bit Register Definitions (might not be supported by all compilers)
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
// Address Definitions for Bit-addressable Registers
//-----------------------------------------------------------------------------

#define SFR_P0       0x80
#define SFR_TCON     0x88
#define SFR_P1       0x90
#define SFR_SCON0    0x98
#define SFR_P2       0xA0
#define SFR_IE       0xA8
#define SPR_P3       0xB0
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
SBIT (TI0, SFR_SCON0, 1);              // Transmit interrupt flag
SBIT (RI0, SFR_SCON0, 0);              // Receive interrupt flag

// IE 0xA8
SBIT (EA, SFR_IE, 7);                  // Global interrupt enable
SBIT (ESPI0, SFR_IE, 6);               // SPI0 interrupt enable
SBIT (ET2, SFR_IE, 5);                 // Timer2 interrupt enable
SBIT (ES0, SFR_IE, 4);                 // UART0 interrupt enable
SBIT (ET1, SFR_IE, 3);                 // Timer1 interrupt enable
SBIT (EX1, SFR_IE, 2);                 // External interrupt 1 enable
SBIT (ET0, SFR_IE, 1);                 // Timer0 interrupt enable
SBIT (EX0, SFR_IE, 0);                 // External interrupt 0 enable

// IP 0xB8
                                       // Bit7 UNUSED
SBIT (PSPI0, SFR_IP, 6);               // SPI0 interrupt priority
SBIT (PT2, SFR_IP, 5);                 // Timer2 priority
SBIT (PS0, SFR_IP, 4);                 // UART0 priority
SBIT (PT1, SFR_IP, 3);                 // Timer1 priority
SBIT (PX1, SFR_IP, 2);                 // External interrupt 1 priority
SBIT (PT0, SFR_IP, 1);                 // Timer0 priority
SBIT (PX0, SFR_IP, 0);                 // External interrupt 0 priority

// SMB0CN 0xC0
SBIT (MASTER, SFR_SMB0CN, 7);          // Master/slave indicator
SBIT (TXMODE, SFR_SMB0CN, 6);          // Transmit mode indicator
SBIT (STA, SFR_SMB0CN, 5);             // Start flag
SBIT (STO, SFR_SMB0CN, 4);             // Stop flag
SBIT (ACKRQ, SFR_SMB0CN, 3);           // Acknowledge request
SBIT (ARBLOST, SFR_SMB0CN, 2);         // Arbitration lost indicator
SBIT (ACK, SFR_SMB0CN, 1);             // Acknowledge flag
SBIT (SI, SFR_SMB0CN, 0);              // SMBus interrupt flag

// TMR2CN 0xC8
SBIT (TF2H, SFR_TMR2CN, 7);            // Timer2 high byte overflow flag
SBIT (TF2L, SFR_TMR2CN, 6);            // Timer2 low byte overflow flag
SBIT (TF2LEN, SFR_TMR2CN, 5);          // Timer2 low byte interrupt enable
SBIT (T2SOF, SFR_TMR2CN, 4);           // Timer2 start-of-frame capture enable
SBIT (T2SPLIT, SFR_TMR2CN, 3);         // Timer2 split mode enable
SBIT (TR2, SFR_TMR2CN, 2);             // Timer2 on/off control
                                       // Bit1 UNUSED
SBIT (T2XCLK, SFR_TMR2CN, 0);          // Timer2 external clock select

// PSW 0xD0
SBIT (CY, SFR_PSW, 7);                 // Carry flag
SBIT (AC, SFR_PSW, 6);                 // Auxiliary carry flag
SBIT (F0, SFR_PSW, 5);                 // User flag 0
SBIT (RS1, SFR_PSW, 4);                // Register bank select 1
SBIT (RS0, SFR_PSW, 3);                // Register bank select 0
SBIT (OV, SFR_PSW, 2);                 // Overflow flag
SBIT (F1, SFR_PSW, 1);                 // User flag 1
SBIT (P, SFR_PSW, 0);                  // Accumulator parity flag

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
SBIT (AD0EN, SFR_ADC0CN, 7);           // ADC0 enable
SBIT (AD0TM, SFR_ADC0CN, 6);           // ADC0 track mode
SBIT (AD0INT, SFR_ADC0CN, 5);          // ADC0 converision complete interrupt flag
SBIT (AD0BUSY, SFR_ADC0CN, 4);         // ADC0 busy flag
SBIT (AD0WINT, SFR_ADC0CN, 3);         // ADC0 window compare interrupt flag
SBIT (AD0CM2, SFR_ADC0CN, 2);          // ADC0 conversion mode select 2
SBIT (AD0CM1, SFR_ADC0CN, 1);          // ADC0 conversion mode select 1
SBIT (AD0CM0, SFR_ADC0CN, 0);          // ADC0 conversion mode select 0

// SPI0CN 0xF8
SBIT (SPIF, SFR_SPI0CN, 7);            // SPI0 interrupt flag
SBIT (WCOL, SFR_SPI0CN, 6);            // SPI0 write collision flag
SBIT (MODF, SFR_SPI0CN, 5);            // SPI0 mode fault flag
SBIT (RXOVRN, SFR_SPI0CN, 4);          // SPI0 rx overrun flag
SBIT (NSSMD1, SFR_SPI0CN, 3);          // SPI0 slave select mode 1
SBIT (NSSMD0, SFR_SPI0CN, 2);          // SPI0 slave select mode 0
SBIT (TXBMT, SFR_SPI0CN, 1);           // SPI0 transmit buffer empty
SBIT (SPIEN, SFR_SPI0CN, 0);           // SPI0 SPI enable

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
// SDCC PDATA External Memory Paging Support
//-----------------------------------------------------------------------------

#if defined SDCC

SFR(_XPAGE, 0xAA); // Point to the EMI0CN register

#endif

//-----------------------------------------------------------------------------
// Header File PreProcessor Directive
//-----------------------------------------------------------------------------

#endif                                 // #define C8051F320_DEFS_H

//-----------------------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------------------
