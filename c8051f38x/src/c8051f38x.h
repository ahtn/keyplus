// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <mcs51/compiler.h>

#include "c8051f38x_defs.h"
#include "c8051f38x_usb.h"

///////////////////////////////////////////////////////////////////////////////
//                            PAGE 0x00                                      //
///////////////////////////////////////////////////////////////////////////////

// 8 bit registers (page 0x0)
#define _P0 0x80
SFR(P0              , 0x80);
    SBIT(P0_7  , _P0 , 7);
    SBIT(P0_6  , _P0 , 6);
    SBIT(P0_5  , _P0 , 5);
    SBIT(P0_4  , _P0 , 4);
    SBIT(P0_3  , _P0 , 3);
    SBIT(P0_2  , _P0 , 2);
    SBIT(P0_1  , _P0 , 1);
    SBIT(P0_0  , _P0 , 0);
SFR(SP              , 0x81);
SFR(DPL             , 0x82);
SFR(DPH             , 0x83);
SFR(EMI0TC          , 0x84);
SFR(EMI0CF          , 0x85);
SFR(OSCLCN          , 0x86);
SFR(PCON            , 0x87);

#define _TCON 0x88
SFR(TCON            , 0x88);
    SBIT(TF1 , _TCON , 7);
    SBIT(TR1 , _TCON , 6);
    SBIT(TF0 , _TCON , 5);
    SBIT(TR0 , _TCON , 4);
    SBIT(IE1 , _TCON , 3);
    SBIT(IT1 , _TCON , 2);
    SBIT(IE0 , _TCON , 1);
    SBIT(IT0 , _TCON , 0);
SFR(TMOD            , 0x89);
SFR(TL0             , 0x8A);
SFR(TL1             , 0x8B);
SFR(TH0             , 0x8C);
SFR(TH1             , 0x8D);
SFR(CKCON           , 0x8E);
SFR(PSCTL           , 0x8F);

#define _P1 0x90
SFR(P1              , 0x90);
    SBIT(P1_7 , _P1 , 7);
    SBIT(P1_6 , _P1 , 6);
    SBIT(P1_5 , _P1 , 5);
    SBIT(P1_4 , _P1 , 4);
    SBIT(P1_3 , _P1 , 3);
    SBIT(P1_2 , _P1 , 2);
    SBIT(P1_1 , _P1 , 1);
    SBIT(P1_0 , _P1 , 0);
SFR(TMR3CN          , 0x91);
SFR(TMR3RLL         , 0x92);
SFR(TMR3RLH         , 0x93);
SFR(TMR3L           , 0x94);
SFR(TMR3H           , 0x95);
SFR(USB0ADR         , 0x96);
SFR(USB0DAT         , 0x97);

#define _SCON0 0x98
SFR(SCON0           , 0x98);
    SBIT(S0MODE , _SCON0 , 7);
    // SBIT(       , _SCON0 , 6);
    SBIT(MCE0   , _SCON0 , 5);
    SBIT(REN0   , _SCON0 , 4);
    SBIT(TB80   , _SCON0 , 3);
    SBIT(RB80   , _SCON0 , 2);
    SBIT(TI0    , _SCON0 , 1);
    SBIT(RI0    , _SCON0 , 0);
SFR(SBUF0           , 0x99);
SFR(CPT1CN          , 0x9A);
SFR(CPT0CN          , 0x9B);
SFR(CPT1MD          , 0x9C);
SFR(CPT0MD          , 0x9D);
SFR(CPT1MX          , 0x9E);
SFR(CPT0MX          , 0x9F);

#define _P2 0xA0
SFR(P2              , 0xA0);
    SBIT(P2_7 , _P2 , 7);
    SBIT(P2_6 , _P2 , 6);
    SBIT(P2_5 , _P2 , 5);
    SBIT(P2_4 , _P2 , 4);
    SBIT(P2_3 , _P2 , 3);
    SBIT(P2_2 , _P2 , 2);
    SBIT(P2_1 , _P2 , 1);
    SBIT(P2_0 , _P2 , 0);
SFR(SPI0CFG         , 0xA1);
SFR(SPI0CKR         , 0xA2);
SFR(SPI0DAT         , 0xA3);
SFR(P0MDOUT         , 0xA4);
SFR(P1MDOUT         , 0xA5);
SFR(P2MDOUT         , 0xA6);
SFR(P3MDOUT         , 0xA7);

#define _IE 0xA8
SFR(IE              , 0xA8);
    SBIT(IE_EA    , _IE , 7);
    SBIT(IE_ESPI0 , _IE , 6);
    SBIT(IE_ET2   , _IE , 5);
    SBIT(IE_ES0   , _IE , 4);
    SBIT(IE_ET1   , _IE , 3);
    SBIT(IE_EX1   , _IE , 2);
    SBIT(IE_ET0   , _IE , 1);
    SBIT(IE_EX0   , _IE , 0);
SFR(CLKSEL          , 0xA9);
SFR(EMI0CN          , 0xAA);
/* SFR(                , 0xAB); */
SFR(SBCON1          , 0xAC);
/* SFR(                , 0xAD); */
SFR(P4MDOUT         , 0xAE);
SFR(PFE0CN          , 0xAF);

#define _P3 0xB0
SFR(P3              , 0xB0);
    SBIT(P3_7 , _P3 , 7);
    SBIT(P3_6 , _P3 , 6);
    SBIT(P3_5 , _P3 , 5);
    SBIT(P3_4 , _P3 , 4);
    SBIT(P3_3 , _P3 , 3);
    SBIT(P3_2 , _P3 , 2);
    SBIT(P3_1 , _P3 , 1);
    SBIT(P3_0 , _P3 , 0);
SFR(OSCXCN          , 0xB1);
SFR(OSCICN          , 0xB2);
SFR(OSCICL          , 0xB3);
SFR(SBRLL1          , 0xB4);
SFR(SBRLH1          , 0xB5);
SFR(FLSCL           , 0xB6);
SFR(FLKEY           , 0xB7);

#define _IP 0xB8
SFR(IP              , 0xB8);
    // SBIT(            , _IP , 7);
    SBIT(PSPI0       , _IP , 6);
    SBIT(PT2         , _IP , 5);
    SBIT(PS0         , _IP , 4);
    SBIT(PT1         , _IP , 3);
    SBIT(PX1         , _IP , 2);
    SBIT(PT0         , _IP , 1);
    SBIT(PX0         , _IP , 0);
SFR(CLKMUL          , 0xB9);
SFR(AMX0N           , 0xBA);
SFR(AMX0P           , 0xBB);
SFR(ADC0CF          , 0xBC);
SFR(ADC0L           , 0xBD);
SFR(ADC0H           , 0xBE);
SFR(SFRPAGE         , 0xBF);

#define _SMB0CN 0xC0
SFR(SMB0CN          , 0xC0);
    SBIT(MASTER0  , _SMB0CN , 7);
    SBIT(TXMODE0  , _SMB0CN , 6);
    SBIT(STA0     , _SMB0CN , 5);
    SBIT(STO0     , _SMB0CN , 4);
    SBIT(ACKRQ0   , _SMB0CN , 3);
    SBIT(ARBLOST0 , _SMB0CN , 2);
    SBIT(ACK0     , _SMB0CN , 1);
    SBIT(SI0      , _SMB0CN , 0);
SFR(SMB0CF          , 0xC1);
SFR(SMB0DAT         , 0xC2);
SFR(ADC0GTL         , 0xC3);
SFR(ADC0GTH         , 0xC4);
SFR(ADC0LTL         , 0xC5);
SFR(ADC0LTH         , 0xC6);
SFR(P4              , 0xC7);

#define _TMR2CN 0xC8
SFR(TMR2CN          , 0xC8);
    SBIT(TF2H    , _TMR2CN , 7);
    SBIT(TF2L    , _TMR2CN , 6);
    SBIT(TF2LEN  , _TMR2CN , 5);
    SBIT(TF2CEN  , _TMR2CN , 4);
    SBIT(T2SPLIT , _TMR2CN , 3);
    SBIT(TR2     , _TMR2CN , 2);
    SBIT(T2CSS   , _TMR2CN , 1);
    SBIT(T2XCLK  , _TMR2CN , 0);
SFR(REG01CN         , 0xC9);
SFR(TMR2RLL         , 0xCA);
SFR(TMR2RLH         , 0xCB);
SFR(TMR2L           , 0xCC);
SFR(TMR2H           , 0xCD);
SFR(SMB0ADM         , 0xCE);
SFR(SMB0ADR         , 0xCF);

#define _PSW 0xD0
SFR(PSW             , 0xD0);
    SBIT(CY     , _PSW , 7);
    SBIT(AC     , _PSW , 6);
    SBIT(F0     , _PSW , 5);
    SBIT(RS1    , _PSW , 4);
    SBIT(RS0    , _PSW , 3);
    SBIT(OV     , _PSW , 2);
    SBIT(F1     , _PSW , 1);
    SBIT(PARITY , _PSW , 0);
SFR(REF0CN          , 0xD1);
SFR(SCON1           , 0xD2);
SFR(SBUF1           , 0xD3);
SFR(P0SKIP          , 0xD4);
SFR(P1SKIP          , 0xD5);
SFR(P2SKIP          , 0xD6);
SFR(USB0XCN         , 0xD7);

#define _PCA0CN 0xD8
SFR(PCA0CN          , 0xD8);
    SBIT(CF   , _PCA0CN , 7);
    SBIT(CR   , _PCA0CN , 6);
    // SBIT(     , _PCA0CN , 5);
    SBIT(CCF4 , _PCA0CN , 4);
    SBIT(CCF3 , _PCA0CN , 3);
    SBIT(CCF2 , _PCA0CN , 2);
    SBIT(CCF1 , _PCA0CN , 1);
    SBIT(CCF0 , _PCA0CN , 0);
SFR(PCA0MD          , 0xD9);
SFR(PCA0CPM0        , 0xDA);
SFR(PCA0CPM1        , 0xDB);
SFR(PCA0CPM2        , 0xDC);
SFR(PCA0CPM3        , 0xDD);
SFR(PCA0CPM4        , 0xDE);
SFR(P3SKIP          , 0xDF);

#define _ACC 0xE0
SFR(ACC             , 0xE0);
    SBIT(ACC_7 , _ACC , 7);
    SBIT(ACC_6 , _ACC , 6);
    SBIT(ACC_5 , _ACC , 5);
    SBIT(ACC_4 , _ACC , 4);
    SBIT(ACC_3 , _ACC , 3);
    SBIT(ACC_2 , _ACC , 2);
    SBIT(ACC_1 , _ACC , 1);
    SBIT(ACC_0 , _ACC , 0);
SFR(XBR0            , 0xE1);
SFR(XBR1            , 0xE2);
SFR(XBR2            , 0xE3);
SFR(IT01CF          , 0xE4);
SFR(SMOD1           , 0xE5);
SFR(EIE1            , 0xE6);
SFR(EIE2            , 0xE7);

#define _ADC0CN 0xE8
SFR(ADC0CN          , 0xE8);
    SBIT(AD0EN     , _ADC0CN , 7);
    SBIT(AD0TM     , _ADC0CN , 6);
    SBIT(AD0INT    , _ADC0CN , 5);
    SBIT(AD0BUSY   , _ADC0CN , 4);
    SBIT(AD0WINT   , _ADC0CN , 3);
    SBIT(AD0CM_2   , _ADC0CN , 2);
    SBIT(AD0CM_1   , _ADC0CN , 1);
    SBIT(AD0CM_0   , _ADC0CN , 0);
SFR(PCA0CPL1        , 0xE9);
SFR(PCA0CPH1        , 0xEA);
SFR(PCA0CPL2        , 0xEB);
SFR(PCA0CPH2        , 0xEC);
SFR(PCA0CPL3        , 0xED);
SFR(PCA0CPH3        , 0xEE);
SFR(RSTSRC          , 0xEF);

#define _B 0xF0
SFR(B               , 0xF0);
    SBIT(B_7   , _B , 7);
    SBIT(B_6   , _B , 6);
    SBIT(B_5   , _B , 5);
    SBIT(B_4   , _B , 4);
    SBIT(B_3   , _B , 3);
    SBIT(B_2   , _B , 2);
    SBIT(B_1   , _B , 1);
    SBIT(B_0   , _B , 0);
SFR(P0MDIN          , 0xF1);
SFR(P1MDIN          , 0xF2);
SFR(P2MDIN          , 0xF3);
SFR(P3MDIN          , 0xF4);
SFR(P4MDIN          , 0xF5);
SFR(EIP1            , 0xF6);
SFR(EIP2            , 0xF7);

#define _SPI0CN 0xF8
SFR(SPI0CN          , 0xF8);
    SBIT(SPIF     , _SPI0CN , 7);
    SBIT(WCOL     , _SPI0CN , 6);
    SBIT(MODF     , _SPI0CN , 5);
    SBIT(RXOVRN   , _SPI0CN , 4);
    SBIT(NSSMD1   , _SPI0CN , 3);
    SBIT(NSSMD0   , _SPI0CN , 2);
    SBIT(TXBMT    , _SPI0CN , 1);
    SBIT(SPIEN    , _SPI0CN , 0);
SFR(PCA0L           , 0xF9);
SFR(PCA0H           , 0xFA);
SFR(PCA0CPL0        , 0xFB);
SFR(PCA0CPH0        , 0xFC);
SFR(PCA0CPL4        , 0xFD);
SFR(PCA0CPH4        , 0xFE);
SFR(VDM0CN          , 0xFF);

// 16 bit registers (page 0x0)
SFR16(TMR3RL         , 0x92);
SFR16(TMR3           , 0x94);
SFR16(SBRL1          , 0xB4);
SFR16(ADC0           , 0xBD);
SFR16(ADC0GT         , 0xC3);
SFR16(ADC0LT         , 0xC5);
SFR16(TMR2RL         , 0xCA);
SFR16(TMR2           , 0xCC);
SFR16(PCA0CP1        , 0xE9);
SFR16(PCA0CP2        , 0xEB);
SFR16(PCA0CP3        , 0xED);
SFR16(PCA0           , 0xF9);
SFR16(PCA0CP0        , 0xFB);
SFR16(PCA0CP4        , 0xFD);

///////////////////////////////////////////////////////////////////////////////
//                            PAGE 0x0F                                      //
///////////////////////////////////////////////////////////////////////////////

// 8 bit registers (page 0x0F)
SFR(TMR4CN          , 0x91);
SFR(TMR4RLL         , 0x92);
SFR(TMR4RLH         , 0x93);
SFR(TMR4L           , 0x94);
SFR(TMR4H           , 0x95);

SFR(SMBTC           , 0xB9);

#define _SMB1CN 0xC0
SFR(SMB1CN          , 0xC0);
    SBIT(MASTER1  , _SMB1CN , 7);
    SBIT(TXMODE1  , _SMB1CN , 6);
    SBIT(STA1     , _SMB1CN , 5);
    SBIT(STO1     , _SMB1CN , 4);
    SBIT(ACKRQ1   , _SMB1CN , 3);
    SBIT(ARBLOST1 , _SMB1CN , 2);
    SBIT(ACK1     , _SMB1CN , 1);
    SBIT(SI1      , _SMB1CN , 0);
SFR(SMB1CF          , 0xC1);
SFR(SMB1DAT         , 0xC2);

#define _TMR5CN 0xC8
SFR(TMR5CN          , 0xC8);
    SBIT(TF5H    , _TMR5CN , 7);
    SBIT(TF5L    , _TMR5CN , 6);
    SBIT(TF5LEN  , _TMR5CN , 5);
    // SBIT(        , _TMR5CN , 4);
    SBIT(T5SPLIT , _TMR5CN , 3);
    SBIT(TR5     , _TMR5CN , 2);
    // SBIT(        , _TMR5CN , 1);
    SBIT(T5XCLK  , _TMR5CN , 0);
SFR(TMR5RLL         , 0xCA);
SFR(TMR5RLH         , 0xCB);
SFR(TMR5L           , 0xCC);
SFR(TMR5H           , 0xCD);
SFR(SMB1ADM         , 0xCE);
SFR(SMB1ADR         , 0xCF);

SFR(CKCON1          , 0xE4);

// 16 bit registers (page 0x0F)
SFR16(TMR4RL         , 0x92);
SFR16(TMR4           , 0x94);
SFR16(TMR5RL         , 0xCA);
SFR16(TMR5           , 0xCC);

#define SET_SFR_PAGE(val) (SFRPAGE = val);

// irq addr := irq_num * 0x08 + 0x03
#define IRQ_NUM_TO_ADDR(irq_num) (irq_num*8 + 3)

#define ISR_EXT_INT0  0   // External interrupt0 (INT0)
#define ISR_TIMER0    1   // Timer0 overflow interrupt
#define ISR_EXT_INT1  2   // External interrupt1 (INT1)
#define ISR_TIMER1    3   // Timer1 overflow interrupt
#define ISR_UART0     4   // UART0 receive and transmitt interrupt
#define ISR_TIMER2    5   // Timer2 overflow interrupt
#define ISR_SPI0      6   // SPI0 interrupt
#define ISR_SMB0      7   // SMB0 interrupt
#define ISR_USB0      8   // USB0 interrupt
#define ISR_AD0WINT   9   // ADC0 window compare interrupt
#define ISR_AD0INT    10  // ADC0 conversion complete interrupt
#define ISR_PCA0      11  // Programmable counter array overflow interrupt
#define ISR_CP0       12  // Comparator0
#define ISR_CP1       13  // Comparator1
#define ISR_TIMER3    14  // Timer3 overflow interrupt
#define ISR_VBUS      15  // VBUS Level
#define ISR_UART1     16  // UART1 Level
// #define ISR_VBUS      17  // RESERVED
#define ISR_SMB1      18  // SMB1 interrupt
#define ISR_TIMER4    19  // Timer4 overflow interrupt
#define ISR_TIMER5    20  // Timer5 overflow interrupt
