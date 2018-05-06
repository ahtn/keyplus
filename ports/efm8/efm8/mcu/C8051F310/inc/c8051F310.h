/*---------------------------------------------------------------------------
;
;
;
;
;  FILE NAME   : C8051F310.H
;  TARGET MCUs : C8051F310, 'F311
;  DESCRIPTION : Register/bit definitions for the C8051F31x product family.
;
;  REVISION 1.3
;     -- Added ESPI0 and PSPI0
;
;  REVISION 1.2
;     -- Added VDM0CN (0xff)
;
;  REVISION 1.1
;     -- SPICFG --> SPI0CFG
;     -- SPICKR --> SPI0CKR
;     -- SPIDAT --> SPI0DAT
;     -- removed CLKMUL (0xb9)
;     -- AMUX0N --> AMX0N
;     -- AMUX0P --> AMX0P
;
;---------------------------------------------------------------------------*/

/*  BYTE Registers  */
sfr P0       = 0x80;    /* PORT 0                                                   */
sfr SP       = 0x81;    /* STACK POINTER                                            */
sfr DPL      = 0x82;    /* DATA POINTER - LOW BYTE                                  */
sfr DPH      = 0x83;    /* DATA POINTER - HIGH BYTE                                 */
sfr PCON     = 0x87;    /* POWER CONTROL                                            */
sfr TCON     = 0x88;    /* TIMER CONTROL                                            */
sfr TMOD     = 0x89;    /* TIMER MODE                                               */
sfr TL0      = 0x8A;    /* TIMER 0 - LOW BYTE                                       */
sfr TL1      = 0x8B;    /* TIMER 1 - LOW BYTE                                       */
sfr TH0      = 0x8C;    /* TIMER 0 - HIGH BYTE                                      */
sfr TH1      = 0x8D;    /* TIMER 1 - HIGH BYTE                                      */
sfr CKCON    = 0x8E;    /* CLOCK CONTROL                                            */
sfr PSCTL    = 0x8F;    /* PROGRAM STORE R/W CONTROL                                */
sfr P1       = 0x90;    /* PORT 1                                                   */
sfr TMR3CN   = 0x91;    /* TIMER 3 CONTROL                                          */
sfr TMR3RLL  = 0x92;    /* TIMER 3 RELOAD LOW                                       */
sfr TMR3RLH  = 0x93;    /* TIMER 3 RELOAD HIGH                                      */
sfr TMR3L    = 0x94;    /* TIMER 3 LOW BYTE                                         */
sfr TMR3H    = 0x95;    /* TIMER 3 HIGH BYTE                                        */
sfr SCON0    = 0x98;    /* SERIAL PORT 0 CONTROL                                    */
sfr SBUF0    = 0x99;    /* SERIAL PORT 0 BUFFER                                     */
sfr CPT1CN   = 0x9A;    /* COMPARATOR 1 CONTROL                                     */
sfr CPT0CN   = 0x9B;    /* COMPARATOR 0 CONTROL                                     */
sfr CPT1MD   = 0x9C;    /* COMPARATOR 1 MODE                                        */
sfr CPT0MD   = 0x9D;    /* COMPARATOR 0 MODE                                        */
sfr CPT1MX   = 0x9E;    /* COMPARATOR 1 MUX                                         */
sfr CPT0MX   = 0x9F;    /* COMPARATOR 0 MUX                                         */
sfr P2       = 0xA0;    /* PORT 2                                                   */
sfr SPI0CFG  = 0xA1;    /* SPI0 CONFIGURATION                                       */
sfr SPI0CKR  = 0xA2;    /* SPI0 CLOCK CONFIGURATION                                 */
sfr SPI0DAT  = 0xA3;    /* SPI0 DATA                                                */
sfr P0MDOUT  = 0xA4;    /* PORT 0 OUTPUT MODE                                       */
sfr P1MDOUT  = 0xA5;    /* PORT 1 OUTPUT MODE                                       */
sfr P2MDOUT  = 0xA6;    /* PORT 2 OUTPUT MODE                                       */
sfr P3MDOUT  = 0xA7;    /* PORT 3 OUTPUT MODE                                       */
sfr IE       = 0xA8;    /* INTERRUPT ENABLE                                         */
sfr CLKSEL   = 0xA9;    /* CLOCK SOURCE SELECT                                      */
sfr EMI0CN   = 0xAA;    /* EXTERNAL MEMORY INTERFACE CONTROL                        */
sfr P3       = 0xB0;    /* PORT 3                                                   */
sfr OSCXCN   = 0xB1;    /* EXTERNAL OSCILLATOR CONTROL                              */
sfr OSCICN   = 0xB2;    /* INTERNAL OSCILLATOR CONTROL                              */
sfr OSCICL   = 0xB3;    /* INTERNAL OSCILLATOR CALIBRATION                          */
sfr FLACL    = 0xB5;    /* FLASH ACCESS LIMIT                                       */
sfr FLSCL    = 0xB6;    /* FLASH SCALE                                              */
sfr FLKEY    = 0xB7;    /* FLASH LOCK & KEY                                         */
sfr IP       = 0xB8;    /* INTERRUPT PRIORITY                                       */
sfr AMX0N    = 0xBA;    /* ADC0 MUX NEGATIVE CHANNEL SELECTION                      */
sfr AMX0P    = 0xBB;    /* ADC0 MUX POSITIVE CHANNEL SELECTION                      */
sfr ADC0CF   = 0xBC;    /* ADC0 CONFIGURATION                                       */
sfr ADC0L    = 0xBD;    /* ADC0 DATA LOW                                            */
sfr ADC0H    = 0xBE;    /* ADC0 DATA HIGH                                           */
sfr SMB0CN   = 0xC0;    /* SMBUS CONTROL                                            */
sfr SMB0CF   = 0xC1;    /* SMBUS CONFIGURATION                                      */
sfr SMB0DAT  = 0xC2;    /* SMBUS DATA                                               */
sfr ADC0GTL  = 0xC3;    /* ADC0 GREATER-THAN LOW                                    */
sfr ADC0GTH  = 0xC4;    /* ADC0 GREATER-THAN HIGH                                   */
sfr ADC0LTL  = 0xC5;    /* ADC0 LESS-THAN LOW                                       */
sfr ADC0LTH  = 0xC6;    /* ADC0 LESS-THAN HIGH                                      */
sfr TMR2CN   = 0xC8;    /* TIMER 2 CONTROL                                          */
sfr TMR2RLL  = 0xCA;    /* TIMER 2 RELOAD LOW                                       */
sfr TMR2RLH  = 0xCB;    /* TIMER 2 RELOAD HIGH                                      */
sfr TMR2L    = 0xCC;    /* TIMER 2 LOW BYTE                                         */
sfr TMR2H    = 0xCD;    /* TIMER 2 HIGH BYTE                                        */
sfr PSW      = 0xD0;    /* PROGRAM STATUS WORD                                      */
sfr REF0CN   = 0xD1;    /* VOLTAGE REFERENCE 0 CONTROL                              */
sfr P0SKIP   = 0xD4;    /* PORT 0 CROSSBAR SKIP                                     */
sfr P1SKIP   = 0xD5;    /* PORT 1 CROSSBAR SKIP                                     */
sfr P2SKIP   = 0xD6;    /* PORT 2 CROSSBAR SKIP                                     */
sfr PCA0CN   = 0xD8;    /* PCA0 CONTROL                                             */
sfr PCA0MD   = 0xD9;    /* PCA0 MODE                                                */
sfr PCA0CPM0 = 0xDA;    /* PCA0 MODULE 0 MODE                                       */
sfr PCA0CPM1 = 0xDB;    /* PCA0 MODULE 1 MODE                                       */
sfr PCA0CPM2 = 0xDC;    /* PCA0 MODULE 2 MODE                                       */
sfr PCA0CPM3 = 0xDD;    /* PCA0 MODULE 3 MODE                                       */
sfr PCA0CPM4 = 0xDE;    /* PCA0 MODULE 4 MODE                                       */
sfr ACC      = 0xE0;    /* ACCUMULATOR                                              */
sfr XBR0     = 0xE1;    /* DIGITAL CROSSBAR CONFIGURATION REGISTER 0                */
sfr XBR1     = 0xE2;    /* DIGITAL CROSSBAR CONFIGURATION REGISTER 1                */
sfr IT01CF   = 0xE4;    /* INT0/INT1 CONFIGURATION                                  */
sfr EIE1     = 0xE6;    /* EXTERNAL INTERRUPT ENABLE 1                              */
sfr ADC0CN   = 0xE8;    /* ADC 0 CONTROL                                            */
sfr PCA0CPL1 = 0xE9;    /* PCA0 MODULE 1 CAPTURE/COMPARE REGISTER LOW BYTE          */
sfr PCA0CPH1 = 0xEA;    /* PCA0 MODULE 1 CAPTURE/COMPARE REGISTER HIGH BYTE         */
sfr PCA0CPL2 = 0xEB;    /* PCA0 MODULE 2 CAPTURE/COMPARE REGISTER LOW BYTE          */
sfr PCA0CPH2 = 0xEC;    /* PCA0 MODULE 2 CAPTURE/COMPARE REGISTER HIGH BYTE         */
sfr PCA0CPL3 = 0xED;    /* PCA0 MODULE 3 CAPTURE/COMPARE REGISTER LOW BYTE          */
sfr PCA0CPH3 = 0xEE;    /* PCA0 MODULE 3 CAPTURE/COMPARE REGISTER HIGH BYTE         */
sfr RSTSRC   = 0xEF;    /* RESET SOURCE                                             */
sfr B        = 0xF0;    /* B REGISTER                                               */
sfr P0MDIN   = 0xF1;    /* PORT 0 INPUT MODE REGISTER                               */
sfr P1MDIN   = 0xF2;    /* PORT 1 INPUT MODE REGISTER                               */
sfr P2MDIN   = 0xF3;    /* PORT 2 INPUT MODE REGISTER                               */
sfr P3MDIN   = 0xF4;    /* PORT 3 INPUT MODE REGISTER                               */
sfr EIP1     = 0XF6;    /* EXTERNAL INTERRUPT PRIORITY 1                            */
sfr SPI0CN   = 0xF8;    /* SPI0 CONTROL                                             */
sfr PCA0L    = 0xF9;    /* PCA0 COUNTER REGISTER LOW BYTE                           */
sfr PCA0H    = 0xFA;    /* PCA0 COUNTER REGISTER HIGH BYTE                          */
sfr PCA0CPL0 = 0xFB;    /* PCA MODULE 0 CAPTURE/COMPARE REGISTER LOW BYTE           */
sfr PCA0CPH0 = 0xFC;    /* PCA MODULE 0 CAPTURE/COMPARE REGISTER HIGH BYTE          */
sfr PCA0CPL4 = 0xFD;    /* PCA MODULE 4 CAPTURE/COMPARE REGISTER LOW BYTE           */
sfr PCA0CPH4 = 0xFE;    /* PCA MODULE 4 CAPTURE/COMPARE REGISTER HIGH BYTE          */
sfr VDM0CN   = 0xFF;    /* VDD MONITOR CONTROL                                      */

/*  BIT Registers  */

/*  TCON  0x88 */
sbit IT0     = TCON ^ 0;   /* EXT INTERRUPT 0 TYPE                                  */
sbit IE0     = TCON ^ 1;   /* EXT INTERRUPT 0 EDGE FLAG                             */
sbit IT1     = TCON ^ 2;   /* EXT INTERRUPT 1 TYPE                                  */
sbit IE1     = TCON ^ 3;   /* EXT INTERRUPT 1 EDGE FLAG                             */
sbit TR0     = TCON ^ 4;   /* TIMER 0 ON/OFF CONTROL                                */
sbit TF0     = TCON ^ 5;   /* TIMER 0 OVERFLOW FLAG                                 */
sbit TR1     = TCON ^ 6;   /* TIMER 1 ON/OFF CONTROL                                */
sbit TF1     = TCON ^ 7;   /* TIMER 1 OVERFLOW FLAG                                 */

/*  SCON0  0x98 */
sbit RI0     = SCON0 ^ 0;  /* RECEIVE INTERRUPT FLAG                                */
sbit TI0     = SCON0 ^ 1;  /* TRANSMIT INTERRUPT FLAG                               */
sbit RB80    = SCON0 ^ 2;  /* RECEIVE BIT 8                                         */
sbit TB80    = SCON0 ^ 3;  /* TRANSMIT BIT 8                                        */
sbit REN0    = SCON0 ^ 4;  /* RECEIVE ENABLE                                        */
sbit MCE0    = SCON0 ^ 5;  /* MULTIPROCESSOR COMMUNICATION ENABLE                   */
sbit S0MODE  = SCON0 ^ 7;  /* SERIAL MODE CONTROL BIT 0                             */

/*  IE  0xA8 */
sbit EX0     = IE ^ 0;     /* EXTERNAL INTERRUPT 0 ENABLE                           */
sbit ET0     = IE ^ 1;     /* TIMER 0 INTERRUPT ENABLE                              */
sbit EX1     = IE ^ 2;     /* EXTERNAL INTERRUPT 1 ENABLE                           */
sbit ET1     = IE ^ 3;     /* TIMER 1 INTERRUPT ENABLE                              */
sbit ES0     = IE ^ 4;     /* UART0 INTERRUPT ENABLE                                */
sbit ET2     = IE ^ 5;     /* TIMER 2 INTERRUPT ENABLE                              */
sbit ESPI0   = IE ^ 6;     /* SPI0 INTERRUPT ENABLE                                 */
sbit EA      = IE ^ 7;     /* GLOBAL INTERRUPT ENABLE                               */

/*  IP  0xB8 */
sbit PX0     = IP ^ 0;     /* EXTERNAL INTERRUPT 0 PRIORITY                         */
sbit PT0     = IP ^ 1;     /* TIMER 0 PRIORITY                                      */
sbit PX1     = IP ^ 2;     /* EXTERNAL INTERRUPT 1 PRIORITY                         */
sbit PT1     = IP ^ 3;     /* TIMER 1 PRIORITY                                      */
sbit PS0     = IP ^ 4;     /* UART0 PRIORITY                                        */
sbit PT2     = IP ^ 5;     /* TIMER 2 PRIORITY                                      */
sbit PSPI0   = IP ^ 6;     /* SPIO PRIORITY                                         */


/* SMB0CN 0xC0 */
sbit SI      = SMB0CN ^ 0; /* SMBUS0 INTERRUPT FLAG                                 */
sbit ACK     = SMB0CN ^ 1; /* ACKNOWLEDGE FLAG                                      */
sbit ARBLOST = SMB0CN ^ 2; /* ARBITRATION LOST INDICATOR                            */
sbit ACKRQ   = SMB0CN ^ 3; /* ACKNOWLEDGE REQUEST                                   */
sbit STO     = SMB0CN ^ 4; /* STOP FLAG                                             */
sbit STA     = SMB0CN ^ 5; /* START FLAG                                            */
sbit TXMODE  = SMB0CN ^ 6; /* TRANSMIT MODE INDICATOR                               */
sbit MASTER  = SMB0CN ^ 7; /* MASTER/SLAVE INDICATOR                                */

/*  TMR2CN 0xC8 */
sbit T2XCLK  = TMR2CN ^ 0; /* TIMER 2 EXTERNAL CLOCK SELECT                         */
sbit TR2     = TMR2CN ^ 2; /* TIMER 2 ON/OFF CONTROL                                */
sbit T2SPLIT = TMR2CN ^ 3; /* TIMER 2 SPLIT MODE ENABLE                             */
sbit TF2LEN  = TMR2CN ^ 5; /* TIMER 2 LOW BYTE INTERRUPT ENABLE                     */
sbit TF2L    = TMR2CN ^ 6; /* TIMER 2 LOW BYTE OVERFLOW FLAG                        */
sbit TF2H    = TMR2CN ^ 7; /* TIMER 2 HIGH BYTE OVERFLOW FLAG                       */

/*  PSW 0xD0 */
sbit P       = PSW ^ 0;    /* ACCUMULATOR PARITY FLAG                               */
sbit F1      = PSW ^ 1;    /* USER FLAG 1                                           */
sbit OV      = PSW ^ 2;    /* OVERFLOW FLAG                                         */
sbit RS0     = PSW ^ 3;    /* REGISTER BANK SELECT 0                                */
sbit RS1     = PSW ^ 4;    /* REGISTER BANK SELECT 1                                */
sbit F0      = PSW ^ 5;    /* USER FLAG 0                                           */
sbit AC      = PSW ^ 6;    /* AUXILIARY CARRY FLAG                                  */
sbit CY      = PSW ^ 7;    /* CARRY FLAG                                            */

/* PCA0CN 0xD8H */
sbit CCF0    = PCA0CN ^ 0; /* PCA0 MODULE 0 CAPTURE/COMPARE FLAG                    */
sbit CCF1    = PCA0CN ^ 1; /* PCA0 MODULE 1 CAPTURE/COMPARE FLAG                    */
sbit CCF2    = PCA0CN ^ 2; /* PCA0 MODULE 2 CAPTURE/COMPARE FLAG                    */
sbit CCF3    = PCA0CN ^ 3; /* PCA0 MODULE 3 CAPTURE/COMPARE FLAG                    */
sbit CCF4    = PCA0CN ^ 4; /* PCA0 MODULE 4 CAPTURE/COMPARE FLAG                    */
sbit CR      = PCA0CN ^ 6; /* PCA0 COUNTER RUN CONTROL                              */
sbit CF      = PCA0CN ^ 7; /* PCA0 COUNTER OVERFLOW FLAG                            */

/* ADC0CN 0xE8H */
sbit AD0CM0  = ADC0CN ^ 0; /* ADC0 CONVERSION MODE SELECT 0                         */
sbit AD0CM1  = ADC0CN ^ 1; /* ADC0 CONVERSION MODE SELECT 1                         */
sbit AD0CM2  = ADC0CN ^ 2; /* ADC0 CONVERSION MODE SELECT 2                         */
sbit AD0WINT = ADC0CN ^ 3; /* ADC0 WINDOW COMPARE INTERRUPT FLAG                    */
sbit AD0BUSY = ADC0CN ^ 4; /* ADC0 BUSY FLAG                                        */
sbit AD0INT  = ADC0CN ^ 5; /* ADC0 CONVERISION COMPLETE INTERRUPT FLAG              */
sbit AD0TM   = ADC0CN ^ 6; /* ADC0 TRACK MODE                                       */
sbit AD0EN   = ADC0CN ^ 7; /* ADC0 ENABLE                                           */

/* SPI0CN 0xF8H */
sbit SPIF    = SPI0CN ^ 7; /* SPI 0 INTERRUPT FLAG                                  */
sbit WCOL    = SPI0CN ^ 6; /* SPI 0 WRITE COLLISION FLAG                            */
sbit MODF    = SPI0CN ^ 5; /* SPI 0 MODE FAULT FLAG                                 */
sbit RXOVRN  = SPI0CN ^ 4; /* SPI 0 RX OVERRUN FLAG                                 */
sbit NSSMD1  = SPI0CN ^ 3; /* SPI 0 SLAVE SELECT MODE 1                             */
sbit NSSMD0  = SPI0CN ^ 2; /* SPI 0 SLAVE SELECT MODE 0                             */
sbit TXBMT   = SPI0CN ^ 1; /* SPI 0 TRANSMIT BUFFER EMPTY                           */
sbit SPIEN   = SPI0CN ^ 0; /* SPI 0 SPI ENABLE                                      */
