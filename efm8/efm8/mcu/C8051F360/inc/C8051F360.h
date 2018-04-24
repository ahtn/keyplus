//-----------------------------------------------------------------------------
// C8051F360.h
//-----------------------------------------------------------------------------
// Copyright 2006 Silicon Laboratories, Inc.
// http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
//
// Program Description:
//
// Register/bit definitions for the C8051F36x/F37x product family.
//
//
// FID:
// Target:         C8051F360, F361, F362, F363, F364, F365, F366, F367, F368
//                 C8051F370, F371, F372, F373
// Tool chain:     Keil
// Command Line:   None
//
//
// Release 1.0
//    -Initial Release (TP)
//    -29 MAR 2006
//

//-----------------------------------------------------------------------------
// Header File Preprocessor Directive
//-----------------------------------------------------------------------------

#ifndef C8051F360_H
#define C8051F360_H

//-----------------------------------------------------------------------------
// Byte Registers
//-----------------------------------------------------------------------------

sfr P0              = 0x80;            // Port 0 latch
sfr SP              = 0x81;            // Stack pointer
sfr DPL             = 0x82;            // Data pointer low
sfr DPH             = 0x83;            // Data pointer high
sfr CCH0CN          = 0x84;            // Cache control
sfr SFRNEXT         = 0x85;            // SFR stack next page
sfr SFRLAST         = 0x86;            // SFR stack last page
sfr PCON            = 0x87;            // Power control
sfr TCON            = 0x88;            // Timer/counter control
sfr TMOD            = 0x89;            // Timer/counter mode
sfr TL0             = 0x8A;            // Timer/counter 0 low
sfr TL1             = 0x8B;            // Timer/counter 1 low
sfr TH0             = 0x8C;            // Timer/counter 0 high
sfr TH1             = 0x8D;            // Timer/counter 1 high
sfr CKCON           = 0x8E;            // Clock control
sfr PSCTL           = 0x8F;            // Program store R/W control
sfr CLKSEL          = 0x8F;            // Clock select
sfr P1              = 0x90;            // Port 1 latch
sfr TMR3CN          = 0x91;            // Timer/counter 3 control
sfr TMR3RLL         = 0x92;            // Timer/counter 3 reload low
sfr TMR3RLH         = 0x93;            // Timer/counter 3 reload high
sfr TMR3L           = 0x94;            // Timer/counter 3 low
sfr TMR3H           = 0x95;            // Timer/counter 3 high
sfr IDA0L           = 0x96;            // Current mode DAC0 low
sfr IDA0H           = 0x97;            // Current mode DAC0 high
sfr SCON0           = 0x98;            // UART0 control
sfr SBUF0           = 0x99;            // UART0 data buffer
sfr CPT1CN          = 0x9A;            // Comparator1 control
sfr CPT0CN          = 0x9B;            // Comparator0 control
sfr CPT1MD          = 0x9C;            // Comparator1 mode selection
sfr CPT0MD          = 0x9D;            // Comparator0 mode selection
sfr CPT1MX          = 0x9E;            // Comparator1 mux selection
sfr CPT0MX          = 0x9F;            // Comparator0 mux selection
sfr P2              = 0xA0;            // Port 2 latch
sfr SPI0CFG         = 0xA1;            // SPI0 configuration
sfr SPI0CKR         = 0xA2;            // SPI0 clock rate control
sfr SPI0DAT         = 0xA3;            // SPI0 data
sfr MAC0AL          = 0xA4;            // MAC0 A register low byte
sfr P0MDOUT         = 0xA4;            // Port 0 output mode configuration
sfr MAC0AH          = 0xA5;            // MAC0 A register high byte
sfr P1MDOUT         = 0xA5;            // Port 1 output mode configuration
sfr P2MDOUT         = 0xA6;            // Port 2 output mode configuration
sfr SFRPAGE         = 0xA7;            // SFR page select
sfr IE              = 0xA8;            // Interrupt enable
sfr PLL0DIV         = 0xA9;            // PLL divider
sfr EMI0CN          = 0xAA;            // External memory interface control
sfr FLSTAT          = 0xAC;            // Flash status
sfr OSCLCN          = 0xAD;            // Low-frequency oscillator control
sfr MAC0RNDL        = 0xAE;            // MAC0 rounding register low byte
sfr P4MDOUT         = 0xAE;            // Port 4 output mode configuration
sfr MAC0RNDH        = 0xAF;            // MAC0 rounding register high byte
sfr P3MDOUT         = 0xAF;            // Port 3 output mode configuration
sfr P3              = 0xB0;            // Port 3 latch
sfr P2MAT           = 0xB1;            // Port 2 match
sfr PLL0MUL         = 0xB1;            // PLL multiplier
sfr P2MASK          = 0xB2;            // Port 2 mask
sfr PLL0FLT         = 0xB2;            // PLL filter
sfr PLL0CN          = 0xB3;            // PLL control
sfr P4              = 0xB5;            // Port 4 latch
sfr FLSCL           = 0xB6;            // Flash scale
sfr OSCXCN          = 0xB6;            // External oscillator control
sfr FLKEY           = 0xB7;            // Flash lock and key
sfr OSCICN          = 0xB7;            // Internal oscillator control
sfr IP              = 0xB8;            // Interrupt priority
sfr IDA0CN          = 0xB9;            // Current mode DAC0 control
sfr AMX0N           = 0xBA;            // AMUX0 negative channel select
sfr AMX0P           = 0xBB;            // AMUX0 positive channel select
sfr ADC0CF          = 0xBC;            // ADC0 configuration
sfr ADC0L           = 0xBD;            // ADC0 data low
sfr ADC0H           = 0xBE;            // ADC0 data high
sfr OSCICL          = 0xBF;            // Internal oscillator calibration
sfr SMB0CN          = 0xC0;            // SMBus0 control
sfr SMB0CF          = 0xC1;            // SMBus0 configuration
sfr SMB0DAT         = 0xC2;            // SMBus0 data
sfr ADC0GTL         = 0xC3;            // ADC0 window greater than low byte
sfr ADC0GTH         = 0xC4;            // ADC0 window greater than high byte
sfr ADC0LTL         = 0xC5;            // ADC0 window less than low byte
sfr ADC0LTH         = 0xC6;            // ADC0 window less than high byte
sfr ONESHOT         = 0xC7;            // Flash oneshot timing
sfr EMI0CF          = 0xC7;            // EMIF configuration
sfr TMR2CN          = 0xC8;            // Timer/counter 2 control
sfr CCH0TN          = 0xC9;            // Cache tuning
sfr TMR2RLL         = 0xCA;            // Timer/counter 2 reload low
sfr TMR2RLH         = 0xCB;            // Timer/counter 2 reload high
sfr TMR2L           = 0xCC;            // Timer/counter 2 low
sfr TMR2H           = 0xCD;            // Timer/counter 2 high
sfr EIP1            = 0xCE;            // Extended interrupt priority 1
sfr MAC0STA         = 0xCF;            // MAC0 status
sfr EIP2            = 0xCF;            // Extended interrupt priority 2
sfr PSW             = 0xD0;            // Program status word
sfr REF0CN          = 0xD1;            // Voltage reference control
sfr MAC0ACC0        = 0xD2;            // MAC0 accumulator byte 0
sfr CCH0LC          = 0xD2;            // Cache lock
sfr MAC0ACC1        = 0xD3;            // MAC0 accumulator byte 1
sfr CCH0MA          = 0xD3;            // Cache miss accumulator
sfr MAC0ACC2        = 0xD4;            // MAC0 accumulator byte 2
sfr P0SKIP          = 0xD4;            // Port 0 skip
sfr MAC0ACC3        = 0xD5;            // MAC0 accumulator byte 3
sfr P1SKIP          = 0xD5;            // Port 1 skip
sfr MAC0OVR         = 0xD6;            // MAC0 accumulator overflow byte
sfr P2SKIP          = 0xD6;            // Port 2 skip
sfr MAC0CF          = 0xD7;            // MAC0 configuration register
sfr P3SKIP          = 0xD7;            // Port 3 skip
sfr PCA0CN          = 0xD8;            // PCA0 control
sfr PCA0MD          = 0xD9;            // PCA0 mode
sfr PCA0CPM0        = 0xDA;            // PCA0 module 0 mode
sfr PCA0CPM1        = 0xDB;            // PCA0 module 1 mode
sfr PCA0CPM2        = 0xDC;            // PCA0 module 2 mode
sfr PCA0CPM3        = 0xDD;            // PCA0 module 3 mode
sfr PCA0CPM4        = 0xDE;            // PCA0 module 4 mode
sfr PCA0CPM5        = 0xDF;            // PCA0 module 5 mode
sfr ACC             = 0xE0;            // Accumulator
sfr P1MAT           = 0xE1;            // Port 1 match
sfr XBR0            = 0xE1;            // Port I/O crossbar control 0
sfr P1MASK          = 0xE2;            // Port 1 mask
sfr XBR1            = 0xE2;            // Port I/O crossbar control 1
sfr IT01CF          = 0xE4;            // INT0/INT1 configuration
sfr SFR0CN          = 0xE5;            // SFR page control
sfr EIE1            = 0xE6;            // Extended interrupt enable 1
sfr EIE2            = 0xE7;            // Extended interrupt enable 2
sfr ADC0CN          = 0xE8;            // ADC0 control
sfr PCA0CPL1        = 0xE9;            // PCA0 module 1 capture low
sfr PCA0CPH1        = 0xEA;            // PCA0 module 1 capture high
sfr PCA0CPL2        = 0xEB;            // PCA0 module 2 capture low
sfr PCA0CPH2        = 0xEC;            // PCA0 module 2 capture high
sfr PCA0CPL3        = 0xED;            // PCA0 module 3 capture low
sfr PCA0CPH3        = 0xEE;            // PCA0 module 3 capture high
sfr RSTSRC          = 0xEF;            // Reset source configuration/status
sfr B               = 0xF0;            // B register
sfr MAC0BL          = 0xF1;            // MAC0 B register low byte
sfr P0MDIN          = 0xF1;            // Port 0 input mode configuration
sfr MAC0BH          = 0xF2;            // MAC0 B register high byte
sfr P1MDIN          = 0xF2;            // Port 1 input mode configuration
sfr P0MAT           = 0xF3;            // Port 0 match
sfr P2MDIN          = 0xF3;            // Port 2 input mode configuration
sfr P0MASK          = 0xF4;            // Port 0 mask
sfr P3MDIN          = 0xF4;            // Port 3 input mode configuration
sfr PCA0CPL5        = 0xF5;            // PCA0 module 5 capture low
sfr PCA0CPH5        = 0xF6;            // PCA0 module 5 capture high
sfr EMI0TC          = 0xF7;            // EMIF timing control
sfr SPI0CN          = 0xF8;            // SPI0 control
sfr PCA0L           = 0xF9;            // PCA0 counter low
sfr PCA0H           = 0xFA;            // PCA0 counter high
sfr PCA0CPL0        = 0xFB;            // PCA0 module 0 capture low
sfr PCA0CPH0        = 0xFC;            // PCA0 module 0 capture high
sfr PCA0CPL4        = 0xFD;            // PCA0 module 4 capture low
sfr PCA0CPH4        = 0xFE;            // PCA0 module 4 capture high
sfr VDM0CN          = 0xFF;            // VDD monitor control

//-----------------------------------------------------------------------------
// Bit Definitions
//-----------------------------------------------------------------------------

// TCON 0x88
sbit TF1       = 0x8F;                 // Timer 1 overflow flag
sbit TR1       = 0x8E;                 // Timer 1 on/off control
sbit TF0       = 0x8D;                 // Timer 0 overflow flag
sbit TR0       = 0x8C;                 // Timer 0 on/off control
sbit IE1       = 0x8B;                 // Ext. Interrupt 1 edge flag
sbit IT1       = 0x8A;                 // Ext. Interrupt 1 type
sbit IE0       = 0x89;                 // Ext. Interrupt 0 edge flag
sbit IT0       = 0x88;                 // Ext. Interrupt 0 type

// SCON0 0x98
sbit S0MODE    = 0x9F;                 // UART0 mode
                                       // Bit 6 Unused
sbit MCE0      = 0x9D;                 // UART0 mce
sbit REN0      = 0x9C;                 // UART0 RX enable
sbit TB80      = 0x9B;                 // UART0 TX bit 8
sbit RB80      = 0x9A;                 // UART0 RX bit 8
sbit TI0       = 0x99;                 // UART0 TX interrupt flag
sbit RI0       = 0x98;                 // UART0 RX interrupt flag

// IE 0xA8
sbit EA        = 0xAF;                 // Global interrupt enable
sbit ESPI0     = 0xAE;                 // SPI0 interrupt enable
sbit ET2       = 0xAD;                 // Timer 2 interrupt enable
sbit ES0       = 0xAC;                 // UART0 interrupt enable
sbit ET1       = 0xAB;                 // Timer 1 interrupt enable
sbit EX1       = 0xAA;                 // External interrupt 1 enable
sbit ET0       = 0xA9;                 // Timer 0 interrupt enable
sbit EX0       = 0xA8;                 // External interrupt 0 enable

// IP 0xB8
                                       // Bit 7 Unused
sbit PSPI0     = 0xBE;                 // SPI0 priority
sbit PT2       = 0xBD;                 // Timer 2 priority
sbit PS0       = 0xBC;                 // UART0 priority
sbit PT1       = 0xBB;                 // Timer 1 priority
sbit PX1       = 0xBA;                 // External interrupt 1 priority
sbit PT0       = 0xB9;                 // Timer 0 priority
sbit PX0       = 0xB8;                 // External interrupt 0 priority

// SMB0CN 0xC0
sbit MASTER    = 0xC7;                 // SMBus0 master/slave
sbit TXMODE    = 0xC6;                 // SMBus0 transmit mode
sbit STA       = 0xC5;                 // SMBus0 start flag
sbit STO       = 0xC4;                 // SMBus0 stop flag
sbit ACKRQ     = 0xC3;                 // SMBus0 acknowledge request
sbit ARBLOST   = 0xC2;                 // SMBus0 arbitration lost
sbit ACK       = 0xC1;                 // SMBus0 acknowledge flag
sbit SI        = 0xC0;                 // SMBus0 interrupt pending flag

// TMR2CN 0xC8
sbit TF2H      = 0xCF;                 // Timer 2 high byte overflow flag
sbit TF2L      = 0xCE;                 // Timer 2 low byte overflow flag
sbit TF2LEN    = 0xCD;                 // Timer 2 low byte interrupt enable
sbit TF2CEN    = 0xCC;                 // Timer 2 capture enable
sbit T2SPLIT   = 0xCB;                 // Timer 2 split mode enable
sbit TR2       = 0xCA;                 // Timer 2 on/off control
                                       // Bit 1 Unused
sbit T2XCLK    = 0xC8;                 // Timer 2 external clock select

// PSW 0xD0
sbit CY        = 0xD7;                 // Carry flag
sbit AC        = 0xD6;                 // Auxiliary carry flag
sbit F0        = 0xD5;                 // User flag 0
sbit RS1       = 0xD4;                 // Register bank select 1
sbit RS0       = 0xD3;                 // Register bank select 0
sbit OV        = 0xD2;                 // Overflow flag
sbit F1        = 0xD1;                 // User flag 1
sbit P         = 0xD0;                 // Accumulator parity flag

// PCA0CN 0xD8
sbit CF        = 0xDF;                 // PCA0 counter overflow flag
sbit CR        = 0xDE;                 // PCA0 counter run control bit
sbit CCF5      = 0xDD;                 // PCA0 module 5 interrupt flag
sbit CCF4      = 0xDC;                 // PCA0 module 4 interrupt flag
sbit CCF3      = 0xDB;                 // PCA0 module 3 interrupt flag
sbit CCF2      = 0xDA;                 // PCA0 module 2 interrupt flag
sbit CCF1      = 0xD9;                 // PCA0 module 1 interrupt flag
sbit CCF0      = 0xD8;                 // PCA0 module 0 interrupt flag

// ADC0CN 0xE8
sbit AD0EN     = 0xEF;                 // ADC0 enable
sbit AD0TM     = 0xEE;                 // ADC0 track mode
sbit AD0INT    = 0xED;                 // ADC0 conv. complete interrupt flag
sbit AD0BUSY   = 0xEC;                 // ADC0 busy flag
sbit AD0WINT   = 0xEB;                 // ADC0 window compare interrupt flag
sbit AD0CM2    = 0xEA;                 // ADC0 conversion mode select 2
sbit AD0CM1    = 0xE9;                 // ADC0 conversion mode select 1
sbit AD0CM0    = 0xE8;                 // ADC0 conversion mode select 0

// SPI0CN 0xF8
sbit SPIF      = 0xFF;                 // SPI0 interrupt flag
sbit WCOL      = 0xFE;                 // SPI0 write collision flag
sbit MODF      = 0xFD;                 // SPI0 mode fault flag
sbit RXOVRN    = 0xFC;                 // SPI0 RX overrun flag
sbit NSSMD1    = 0xFB;                 // SPI0 slave select mode 1
sbit NSSMD0    = 0xFA;                 // SPI0 slave select mode 0
sbit TXBMT     = 0xF9;                 // SPI0 TX buffer empty flag
sbit SPIEN     = 0xF8;                 // SPI0 SPI0 enable

//-----------------------------------------------------------------------------
// SFR Page Definitions
//-----------------------------------------------------------------------------

#define CONFIG_PAGE       0x0F         // SYSTEM AND PORT CONFIGURATION PAGE
#define LEGACY_PAGE       0x00         // LEGACY SFR PAGE
#define TIMER01_PAGE      0x00         // TIMER 0 AND TIMER 1
#define CPT0_PAGE         0x00         // COMPARATOR 0
#define CPT1_PAGE         0x00         // COMPARATOR 1
#define UART0_PAGE        0x00         // UART 0
#define SPI0_PAGE         0x00         // SPI 0
#define EMI0_PAGE         0x0F         // EXTERNAL MEMORY INTERFACE
#define ADC0_PAGE         0x00         // ADC 0
#define SMB0_PAGE         0x00         // SMBUS 0
#define TMR2_PAGE         0x00         // TIMER 2
#define TMR3_PAGE         0x00         // TIMER 3
#define DAC0_PAGE         0x00         // DAC 0
#define PCA0_PAGE         0x00         // PCA 0
#define PLL0_PAGE         0x0F         // PLL 0
#define MAC0_PAGE         0x00         // MAC 0
#define MATCH_PAGE        0x00         // PORT0, PORT1, PORT2 MATCH

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
#define INTERRUPT_ADC0_WINDOW      9   // ADC0 Window Comparison
#define INTERRUPT_ADC0_EOC         10  // ADC0 End Of Conversion
#define INTERRUPT_PCA0             11  // PCA0 Peripheral
#define INTERRUPT_COMPARATOR0      12  // Comparator0
#define INTERRUPT_COMPARATOR1      13  // Comparator1
#define INTERRUPT_TIMER3           14  // Timer3 Overflow
#define INTERRUPT_PORT_MATCH       16  // Port Match

//-----------------------------------------------------------------------------
// Header File Preprocessor Directive
//-----------------------------------------------------------------------------

#endif                                 // #define C8051F360_H

//-----------------------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------------------