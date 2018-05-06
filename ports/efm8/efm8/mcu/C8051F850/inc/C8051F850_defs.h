//-----------------------------------------------------------------------------
// C8051F850_defs.h
//-----------------------------------------------------------------------------
// Copyright 2014 Silicon Laboratories, Inc.
// http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
//
// Program Description:
//
// Register/bit definitions for the C8051F85x family.
// **Important Note**: The compiler_defs.h header file should be included
// before including this header file.
//
// Target:         C8051F85x
// Tool chain:     Generic
// Command Line:   None
//
// Release 0.2 - 21 June 2013
//    -Updated all registers and bit names to match the datasheet.
// Release 0.1 - 18 May 2012
//    -Initial revision

//-----------------------------------------------------------------------------
// Header File Preprocessor Directive
//-----------------------------------------------------------------------------

#ifndef C8051F850_DEFS_H
#define C8051F850_DEFS_H

// DO NOT EDIT BETWEEN MARKERS @@@xxx_START and @@@xxx_END

//-----------------------------------------------------------------------------
// Byte Registers
//-----------------------------------------------------------------------------


//@@@SFR_START
SFR (P0             , 0x80);
SFR (SP             , 0x81);
SFR (DPL            , 0x82);
SFR (DPH            , 0x83);
SFR (PCON           , 0x87);
SFR (TCON           , 0x88);
SFR (TMOD           , 0x89);
SFR (TL0            , 0x8A);
SFR (TL1            , 0x8B);
SFR (TH0            , 0x8C);
SFR (TH1            , 0x8D);
SFR (CKCON          , 0x8E);
SFR (PSCTL          , 0x8F);
SFR (P1             , 0x90);
SFR (TMR3CN         , 0x91);
SFR (TMR3RLL        , 0x92);
SFR (TMR3RLH        , 0x93);
SFR (TMR3L          , 0x94);
SFR (TMR3H          , 0x95);
SFR (PCA0POL        , 0x96);
SFR (WDTCN          , 0x97);
SFR (SCON0          , 0x98);
SFR (SBUF0          , 0x99);
SFR (CPT0CN         , 0x9B);
SFR (PCA0CLR        , 0x9C);
SFR (CPT0MD         , 0x9D);
SFR (PCA0CENT       , 0x9E);
SFR (CPT0MX         , 0x9F);
SFR (P2             , 0xA0);
SFR (SPI0CFG        , 0xA1);
SFR (SPI0CKR        , 0xA2);
SFR (SPI0DAT        , 0xA3);
SFR (P0MDOUT        , 0xA4);
SFR (P1MDOUT        , 0xA5);
SFR (P2MDOUT        , 0xA6);
SFR (IE             , 0xA8);
SFR (CLKSEL         , 0xA9);
SFR (CPT1MX         , 0xAA);
SFR (CPT1MD         , 0xAB);
SFR (SMB0TC         , 0xAC);
SFR (DERIVID        , 0xAD);
SFR (OSCLCN         , 0xB1);
SFR (ADC0CN1        , 0xB2);
SFR (ADC0AC         , 0xB3);
SFR (DEVICEID       , 0xB5);
SFR (REVID          , 0xB6);
SFR (FLKEY          , 0xB7);
SFR (IP             , 0xB8);
SFR (ADC0TK         , 0xB9);
SFR (ADC0MX         , 0xBB);
SFR (ADC0CF         , 0xBC);
SFR (ADC0L          , 0xBD);
SFR (ADC0H          , 0xBE);
SFR (CPT1CN         , 0xBF);
SFR (SMB0CN         , 0xC0);
SFR (SMB0CF         , 0xC1);
SFR (SMB0DAT        , 0xC2);
SFR (ADC0GTL        , 0xC3);
SFR (ADC0GTH        , 0xC4);
SFR (ADC0LTL        , 0xC5);
SFR (ADC0LTH        , 0xC6);
SFR (OSCICL         , 0xC7);
SFR (TMR2CN         , 0xC8);
SFR (REG0CN         , 0xC9);
SFR (TMR2RLL        , 0xCA);
SFR (TMR2RLH        , 0xCB);
SFR (TMR2L          , 0xCC);
SFR (TMR2H          , 0xCD);
SFR (CRC0CN         , 0xCE);
SFR (CRC0FLIP       , 0xCF);
SFR (PSW            , 0xD0);
SFR (REF0CN         , 0xD1);
SFR (CRC0AUTO       , 0xD2);
SFR (CRC0CNT        , 0xD3);
SFR (P0SKIP         , 0xD4);
SFR (P1SKIP         , 0xD5);
SFR (SMB0ADM        , 0xD6);
SFR (SMB0ADR        , 0xD7);
SFR (PCA0CN         , 0xD8);
SFR (PCA0MD         , 0xD9);
SFR (PCA0CPM0       , 0xDA);
SFR (PCA0CPM1       , 0xDB);
SFR (PCA0CPM2       , 0xDC);
SFR (CRC0IN         , 0xDD);
SFR (CRC0DAT        , 0xDE);
SFR (ADC0PWR        , 0xDF);
SFR (ACC            , 0xE0);
SFR (XBR0           , 0xE1);
SFR (XBR1           , 0xE2);
SFR (XBR2           , 0xE3);
SFR (IT01CF         , 0xE4);
SFR (EIE1           , 0xE6);
SFR (ADC0CN0        , 0xE8);
SFR (PCA0CPL1       , 0xE9);
SFR (PCA0CPH1       , 0xEA);
SFR (PCA0CPL2       , 0xEB);
SFR (PCA0CPH2       , 0xEC);
SFR (P1MAT          , 0xED);
SFR (P1MASK         , 0xEE);
SFR (RSTSRC         , 0xEF);
SFR (B              , 0xF0);
SFR (P0MDIN         , 0xF1);
SFR (P1MDIN         , 0xF2);
SFR (EIP1           , 0xF3);
SFR (PRTDRV         , 0xF6);
SFR (PCA0PWM        , 0xF7);
SFR (SPI0CN         , 0xF8);
SFR (PCA0L          , 0xF9);
SFR (PCA0H          , 0xFA);
SFR (PCA0CPL0       , 0xFB);
SFR (PCA0CPH0       , 0xFC);
SFR (P0MAT          , 0xFD);
SFR (P0MASK         , 0xFE);
SFR (VDM0CN         , 0xFF);
//@@@SFR_END

//-----------------------------------------------------------------------------
// 16-bit Register Definitions (might not be supported by all compilers)
//-----------------------------------------------------------------------------

//@@@SFR16_START
SFR16 (DP             , 0x82);
SFR16 (TMR3RL         , 0x92);
SFR16 (TMR3           , 0x94);
SFR16 (ADC0           , 0xBD);
SFR16 (ADC0GT         , 0xC3);
SFR16 (ADC0LT         , 0xC5);
SFR16 (TMR2RL         , 0xCA);
SFR16 (TMR2           , 0xCC);
SFR16 (PCA0CP1        , 0xE9);
SFR16 (PCA0CP2        , 0xEB);
SFR16 (PCA0           , 0xF9);
SFR16 (PCA0CP0        , 0xFB);
//@@@SFR16_END

//-----------------------------------------------------------------------------
// Address Definitions for Bit-addressable Registers
//-----------------------------------------------------------------------------

//@@@SFRBIT_START
#define SFR_P0                  0x80
#define SFR_TCON                0x88
#define SFR_P1                  0x90
#define SFR_SCON0               0x98
#define SFR_P2                  0xA0
#define SFR_IE                  0xA8
#define SFR_IP                  0xB8
#define SFR_SMB0CN              0xC0
#define SFR_TMR2CN              0xC8
#define SFR_PSW                 0xD0
#define SFR_PCA0CN              0xD8
#define SFR_ACC                 0xE0
#define SFR_ADC0CN0             0xE8
#define SFR_B                   0xF0
#define SFR_SPI0CN              0xF8
//@@@SFRBIT_END

//-----------------------------------------------------------------------------
// Bit Definitions
//-----------------------------------------------------------------------------

//@@@SFRBITDEF_START
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
SBIT (SMODE, SFR_SCON0, 7);            // Serial Port 0 Operation Mode
                                       // bit 6 UNUSED
SBIT (MCE, SFR_SCON0, 5);              // Multiprocessor Communication Enable
SBIT (REN, SFR_SCON0, 4);              // Receive Enable
SBIT (TB8, SFR_SCON0, 3);              // Transmit Bit 8
SBIT (RB8, SFR_SCON0, 2);              // Receive Bit 8
SBIT (TI, SFR_SCON0, 1);               // Transmit Interrupt Flag
SBIT (RI, SFR_SCON0, 0);               // Receive Interrupt Flag

// IE 0xA8
SBIT (EA, SFR_IE, 7);                  // Global Interrupt Enable
SBIT (ESPI0, SFR_IE, 6);               // Serial Peripheral Interface Enable
SBIT (ET2, SFR_IE, 5);                 // Timer 2 Interrupt Enable
SBIT (ES0, SFR_IE, 4);                 // Serial Port Interrupt Enable
SBIT (ET1, SFR_IE, 3);                 // Timer 1 Interrupt Enable
SBIT (EX1, SFR_IE, 2);                 // External Interrupt Enable
SBIT (ET0, SFR_IE, 1);                 // Timer 0 Interrupt Enable
SBIT (EX0, SFR_IE, 0);                 // External Interrupt 0 Enable

// IP 0xB8
                                       // bit 7 UNUSED
SBIT (PSPI0, SFR_IP, 6);               // SPI0 Priority
SBIT (PT2, SFR_IP, 5);                 // Timer 2 Priority
SBIT (PS0, SFR_IP, 4);                 // Serial Port Priority
SBIT (PT1, SFR_IP, 3);                 // Timer 1 Priority
SBIT (PX1, SFR_IP, 2);                 // External Interrupt 1 Priority
SBIT (PT0, SFR_IP, 1);                 // Timer 0 Priority
SBIT (PX0, SFR_IP, 0);                 // External Interrupt 0 Priority

// SMB0CN 0xC0
SBIT (MASTER, SFR_SMB0CN, 7);          // SMBus Master/Slave Indicator
SBIT (TXMODE, SFR_SMB0CN, 6);          // SMBus Transmit Mode Indicator
SBIT (STA, SFR_SMB0CN, 5);             // SMBus Start Flag
SBIT (STO, SFR_SMB0CN, 4);             // SMBus Stop Flag
SBIT (ACKRQ, SFR_SMB0CN, 3);           // SMBus Acknowledge Request
SBIT (ARBLOST, SFR_SMB0CN, 2);         // SMBus Arbitration Lost Indicator
SBIT (ACK, SFR_SMB0CN, 1);             // SMBus Acknowledge
SBIT (SI, SFR_SMB0CN, 0);              // SMBus Interrupt

// TMR2CN 0xC8
SBIT (TF2H, SFR_TMR2CN, 7);            // T2 High-Byte Overflow Flag
SBIT (TF2L, SFR_TMR2CN, 6);            // T2 Low-Byte Overflow Flag
SBIT (TF2LEN, SFR_TMR2CN, 5);          // T2 Low Byte Interrupt Enable
SBIT (TF2CEN, SFR_TMR2CN, 4);          // T2 Input Capture Enable
SBIT (T2SPLIT, SFR_TMR2CN, 3);         // T2 Split-Mode Enable
SBIT (TR2, SFR_TMR2CN, 2);             // Timer 2 On/Off Control
                                       // bit 1 UNUSED
SBIT (T2XCLK, SFR_TMR2CN, 0);          // T2 External Clock Select

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
SBIT (CF, SFR_PCA0CN, 7);              // PCA 0 Counter Overflow Flag
SBIT (CR, SFR_PCA0CN, 6);              // PCA 0 Counter Run Control Bit
                                       // bit 5 UNUSED
                                       // bit 4 UNUSED
                                       // bit 3 UNUSED
SBIT (CCF2, SFR_PCA0CN, 2);            // PCA 0 Module 2 Interrupt Flag
SBIT (CCF1, SFR_PCA0CN, 1);            // PCA 0 Module 1 Interrupt Flag
SBIT (CCF0, SFR_PCA0CN, 0);            // PCA 0 Module 0 Interrupt Flag

// ADC0CN0 0xE8
SBIT (ADEN, SFR_ADC0CN0, 7);           // ADC0 Enable
SBIT (ADBMEN, SFR_ADC0CN0, 6);         // ADC0 Burst Mode Enable
SBIT (ADINT, SFR_ADC0CN0, 5);          // ADC0 Conversion Complete Int. Flag
SBIT (ADBUSY, SFR_ADC0CN0, 4);         // ADC0 Busy
SBIT (ADWINT, SFR_ADC0CN0, 3);         // ADC0 Windows Compare Interrupt Flag
SBIT (ADCM2, SFR_ADC0CN0, 2);          // ADC0 Start of Conversion Mode Sel 2
SBIT (ADCM1, SFR_ADC0CN0, 1);          // ADC0 Start of Conversion Mode Sel 1
SBIT (ADCM0, SFR_ADC0CN0, 0);          // ADC0 Start of Conversion Mode Sel 0

// SPI0CN 0xF8
SBIT (SPIF, SFR_SPI0CN, 7);            // SPI0 Interrupt Flag
SBIT (WCOL, SFR_SPI0CN, 6);            // SPI0 Write Collision Flag
SBIT (MODF, SFR_SPI0CN, 5);            // SPI0 Mode Fault Flag
SBIT (RXOVRN, SFR_SPI0CN, 4);          // SPI0 RX Overrun Flag
SBIT (NSSMD1, SFR_SPI0CN, 3);          // SPI0 NSS Mode Bit 1
SBIT (NSSMD0, SFR_SPI0CN, 2);          // SPI0 NSS Mode Bit 0
SBIT (TXBMT, SFR_SPI0CN, 1);           // SPI0 Transmit Buffer Empty Flag
SBIT (SPIEN, SFR_SPI0CN, 0);           // SPI0 SPI Enable

//@@@SFRBITDEF_END

//-----------------------------------------------------------------------------
// Interrupt Priorities
//-----------------------------------------------------------------------------

//@@@INTR_START
#define INTERRUPT_INT0             0    // External Interrupt 0
#define INTERRUPT_TIMER0           1    // Timer0 Overflow
#define INTERRUPT_INT1             2    // External Interrupt 1
#define INTERRUPT_TIMER1           3    // Timer1 Overflow
#define INTERRUPT_UART0            4    // Serial Port 0
#define INTERRUPT_TIMER2           5    // Timer2 Overflow
#define INTERRUPT_SPI0             6    // Serial Peripheral Interface 0
#define INTERRUPT_SMBUS0           7    // SMBus0 Interface
#define INTERRUPT_PORT_MATCH       8    // Port Match
#define INTERRUPT_ADC0_WINDOW      9    // ADC0 Window Comparison
#define INTERRUPT_ADC0_EOC         10   // ADC0 End Of Conversion
#define INTERRUPT_PCA0             11   // PCA0 Peripheral
#define INTERRUPT_COMPARATOR0      12   // Comparator0
#define INTERRUPT_COMPARATOR1      13   // Comparator1
#define INTERRUPT_TIMER3           14   // Timer3 Overflow
//@@@INTR_END

//-----------------------------------------------------------------------------
// Header File PreProcessor Directive
//-----------------------------------------------------------------------------

#endif                                 // #define C8051F850_DEFS_H

//-----------------------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------------------
