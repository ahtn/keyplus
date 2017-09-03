// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <mcs51/compiler.h>

// 8 bit registers
SFR(P0              , 0x80);
SFR(SP              , 0x81);
SFR(DPL             , 0x82);
SFR(DPH             , 0x83);
SFR(DPL1            , 0x84);
SFR(DPH1            , 0x85);
SFR(RESERVED_SFR_0  , 0x86);
SFR(PCON            , 0x87);
SFR(TCON            , 0x88);
SFR(TMOD            , 0x89);
SFR(TL0             , 0x8A);
SFR(TL1             , 0x8B);
SFR(TH0             , 0x8C);
SFR(TH1             , 0x8D);
SFR(CKCON           , 0x8E);
SFR(RESERVED_SFR_1  , 0x8F);
SFR(RFCON           , 0x90);
SFR(RESERVED_SFR_2  , 0x91);
SFR(DPS             , 0x92);
SFR(RESERVED_SFR_3  , 0x93);
SFR(P0DIR           , 0x94);
SFR(P0ALT           , 0x95);
SFR(RESERVED_SFR_4  , 0x96);
SFR(RESERVED_SFR_5  , 0x97);
SFR(S0CON           , 0x98);
SFR(S0BUF           , 0x99);
SFR(RESERVED_SFR_6  , 0x9A);
SFR(RESERVED_SFR_7  , 0x9B);
SFR(RESERVED_SFR_8  , 0x9C);
SFR(RESERVED_SFR_9  , 0x9D);
SFR(RESERVED_SFR_10 , 0x9E);
SFR(RESERVED_SFR_11 , 0x9F);
SFR(USBCON          , 0xA0);
SFR(RESERVED_SFR_12 , 0xA1);
SFR(RESERVED_SFR_13 , 0xA2);
SFR(CLKCTL          , 0xA3);
SFR(PWRDWN          , 0xA4);
SFR(WUCONF          , 0xA5);
SFR(INTEXP          , 0xA6);
SFR(RESERVED_SFR_14 , 0xA7);
SFR(IEN0            , 0xA8);
SFR(IP0             , 0xA9);
SFR(S0RELL          , 0xAA);
SFR(REGXH           , 0xAB);
SFR(REGXL           , 0xAC);
SFR(REGXC           , 0xAD);
SFR(RESERVED_SFR_15 , 0xAE);
SFR(RESERVED_SFR_16 , 0xAF);
SFR(RESERVED_SFR_17 , 0xB0);
SFR(RSTRES          , 0xB1);
SFR(SMDAT           , 0xB2);
SFR(SMCTL           , 0xB3);
SFR(RESERVED_SFR_18 , 0xB4);
SFR(TICKDV          , 0xB5);
SFR(RESERVED_SFR_19 , 0xB6);
SFR(RESERVED_SFR_20 , 0xB7);
SFR(IEN1            , 0xB8);
SFR(IP1             , 0xB9);
SFR(S0RELH          , 0xBA);
SFR(RESERVED_SFR_21 , 0xBB);
SFR(SSCONF          , 0xBC);
SFR(SSDATA          , 0xBD);
SFR(SSSTAT          , 0xBE);
SFR(RESERVED_SFR_22 , 0xBF);
SFR(IRCON           , 0xC0);
SFR(CCEN            , 0xC1);
SFR(CCL1            , 0xC2);
SFR(CCH1            , 0xC3);
SFR(CCL2            , 0xC4);
SFR(CCH2            , 0xC5);
SFR(CCL3            , 0xC6);
SFR(CCH3            , 0xC7);
SFR(T2CON           , 0xC8);
SFR(P0EXP           , 0xC9);
SFR(CRCL            , 0xCA);
SFR(CRCH            , 0xCB);
SFR(TL2             , 0xCC);
SFR(TH2             , 0xCD);
SFR(RESERVED_SFR_23 , 0xCE);
SFR(RESERVED_SFR_24 , 0xCF);
SFR(PSW             , 0xD0);
SFR(RESERVED_SFR_25 , 0xD1);
SFR(RESERVED_SFR_26 , 0xD2);
SFR(RESERVED_SFR_27 , 0xD3);
SFR(RESERVED_SFR_28 , 0xD4);
SFR(RESERVED_SFR_29 , 0xD5);
SFR(RESERVED_SFR_30 , 0xD6);
SFR(RESERVED_SFR_31 , 0xD7);
SFR(WDCON           , 0xD8);
SFR(USBSLP          , 0xD9);
SFR(RESERVED_SFR_32 , 0xDA);
SFR(RESERVED_SFR_33 , 0xDB);
SFR(RESERVED_SFR_34 , 0xDC);
SFR(RESERVED_SFR_35 , 0xDD);
SFR(RESERVED_SFR_36 , 0xDE);
SFR(RESERVED_SFR_37 , 0xDF);
SFR(ACC             , 0xE0);
SFR(RESERVED_SFR_38 , 0xE1);
SFR(RESERVED_SFR_39 , 0xE2);
SFR(RESERVED_SFR_40 , 0xE3);
SFR(RESERVED_SFR_41 , 0xE4);
SFR(RFDAT           , 0xE5);
SFR(RFCTL           , 0xE6);
SFR(RESERVED_SFR_42 , 0xE7);
SFR(AESCS           , 0xE8);
SFR(MD0             , 0xE9);
SFR(MD1             , 0xEA);
SFR(MD2             , 0xEB);
SFR(MD3             , 0xEC);
SFR(MD4             , 0xED);
SFR(MD5             , 0xEE);
SFR(ARCON           , 0xEF);
SFR(B               , 0xF0);
SFR(AESKIN          , 0xF1);
SFR(AESIV           , 0xF2);
SFR(AESD            , 0xF3);
SFR(RESERVED_SFR_43 , 0xF4);
SFR(AESIA1          , 0xF5);
SFR(AESIA2          , 0xF6);
SFR(RESERVED_SFR_44 , 0xF7);
SFR(FSR             , 0xF8);
SFR(FPCR            , 0xF9);
SFR(FCR             , 0xFA);
SFR(RESERVED_SFR_45 , 0xFB);
SFR(RESERVED_SFR_46 , 0xFC);
SFR(RESERVED_SFR_47 , 0xFD);
SFR(RESERVED_SFR_48 , 0xFE);
SFR(RESERVED_SFR_49 , 0xFF);

// 16 bit registers
SFR16(CC1 , 0xC2);
SFR16(CC2 , 0xC4);
SFR16(CC3 , 0xC6);
SFR16(CRC , 0xCA);
SFR16(T2  , 0xCC);


// 1 bit registers

// FSR bit registers
#define _FSR 0xF8
SBIT(MCDIS , _FSR , 7);
SBIT(STP   , _FSR , 6);
SBIT(WEN   , _FSR , 5);
SBIT(RDYN  , _FSR , 4);
SBIT(INFEN , _FSR , 3);
SBIT(RDIS  , _FSR , 2);
SBIT(RDEND , _FSR , 1);
SBIT(WPEN  , _FSR , 0);

// PSW bit registers
#define _PSW 0xD0
SBIT(CY  , _PSW , 7);
SBIT(AC  , _PSW , 6);
SBIT(F0  , _PSW , 5);
SBIT(RS1 , _PSW , 4);
SBIT(RS0 , _PSW , 3);
SBIT(OV  , _PSW , 2);
SBIT(F1  , _PSW , 1);
SBIT(P   , _PSW , 0);

// TCON bit registers
#define _TCON 0x88
SBIT(TF1 , _TCON , 7);
SBIT(TR1 , _TCON , 6);
SBIT(TF0 , _TCON , 5);
SBIT(TR0 , _TCON , 4);
SBIT(IE1 , _TCON , 3);
SBIT(IT1 , _TCON , 2);
SBIT(IE0 , _TCON , 1);
SBIT(IT0 , _TCON , 0);

// S0CON bit registers
#define _S0CON 0x98
SBIT(SM0  , _S0CON , 7);
SBIT(SM1  , _S0CON , 6);
SBIT(SM20 , _S0CON , 5);
SBIT(REN0 , _S0CON , 4);
SBIT(TB80 , _S0CON , 3);
SBIT(RB80 , _S0CON , 2);
SBIT(TI0  , _S0CON , 1);
SBIT(RI0  , _S0CON , 0);

// T2CON bit registers
#define _T2CON 0xC8
SBIT(T2PS , _T2CON , 7);
SBIT(I3FR , _T2CON , 6);
SBIT(I2FR , _T2CON , 5);
SBIT(T2R1 , _T2CON , 4);
SBIT(T2R0 , _T2CON , 3);
SBIT(T2CM , _T2CON , 2);
SBIT(T2I1 , _T2CON , 1);
SBIT(T2I0 , _T2CON , 0);

// IEN0
#define _IEN0 0xA8
SBIT(EA  , _IEN0 , 7);
//               6
SBIT(ET2 , _IEN0 , 5);
SBIT(ES0 , _IEN0 , 4);
SBIT(ET1 , _IEN0 , 3);
SBIT(EX1 , _IEN0 , 2);
SBIT(ET0 , _IEN0 , 1);
SBIT(EX0 , _IEN0 , 0);

/* IEN1  */
#define _IEN1 0xB8
SBIT(EXF2_IRQEN  , _IEN1 , 7);
SBIT(WU_IRQEN    , _IEN1 , 5);
SBIT(USB_IRQEN   , _IEN1 , 4);
SBIT(USBWU_IRQEN , _IEN1 , 3);
SBIT(SPI_IRQEN   , _IEN1 , 2);
SBIT(RF_IRQEN    , _IEN1 , 1);
SBIT(RFSPI_IRQEN , _IEN1 , 0);

// IRCON
#define _IRCON 0xC0
SBIT(EXF2   , _IRCON , 7);
SBIT(TF2    , _IRCON , 6);
SBIT(WUF    , _IRCON , 5);
SBIT(USBIRQ , _IRCON , 4);
SBIT(USBWU  , _IRCON , 3);
SBIT(SPIF   , _IRCON , 2);
SBIT(RFIRQ  , _IRCON , 1);
SBIT(RFSPIF , _IRCON , 0);

// USBCON
#define _USBCON 0xA0
SBIT(SWRST   , _USBCON , 7);
SBIT(WU      , _USBCON , 6);
SBIT(SUSPEND , _USBCON , 5);
SBIT(IV4     , _USBCON , 4);
SBIT(IV3     , _USBCON , 3);
SBIT(IV2     , _USBCON , 2);
SBIT(IV1     , _USBCON , 1);
SBIT(IV0     , _USBCON , 0);

// PORT0
#define _P0 0x80
SBIT(P00  , _P0 , 0);
SBIT(P01  , _P0 , 1);
SBIT(P02  , _P0 , 2);
SBIT(P03  , _P0 , 3);
SBIT(MCSN , _P0 , 3);
SBIT(SCSN , _P0 , 3);
SBIT(P04  , _P0 , 4);
SBIT(P05  , _P0 , 5);

// RFCON
#define _RFCON 0x90
SBIT(RFCE   , _RFCON , 0);
SBIT(RFCSN  , _RFCON , 1);
SBIT(RFCKEN , _RFCON , 2);

// WDCON
#define _WDCON 0xD8
SBIT(BD , _WDCON , 7);

// AESCS
#define _AESCS 0xE8
SBIT(GO   , _AESCS , 0);
SBIT(DECR , _AESCS , 1);

// REGX commands
#define RWD         0x00
#define WWD         0x08
#define RGTIMER     0x01
#define WGTIMER     0x09
#define RRTCLAT     0x02
#define WRTCLAT     0x0A
#define RRTC        0x03
#define WRTCDIS     0x0B
#define RWSTA0      0x04
#define WWCON0      0x0C
#define RWSTA1      0x05
#define WWCON1      0x0D

// info page addresses
#define CHIPID                  0x0B
#define INFO_PAGE_USER_DATA     0x100

#define ISR_EXT_INT0   0   // External interrupt0 (P0.3)
#define ISR_T0         1   // Timer0 overflow interrupt
#define ISR_AES_RDY    2   // AES ready interrupt
#define ISR_T1         3   // Timer1 overflow interrupt
#define ISR_UART0      4   // UART0, receive and transmitt interrupt
#define ISR_T2         5   // Timer2 overflow interrupt
#define ISR_RF_RDY     8   // RF SPI ready interrupt
#define ISR_RFIRQ      9   // RF interrupt
#define ISR_SPI        10  // SPI interrupt
#define ISR_USB_WU     11  // USB wakeup interrupt
#define ISR_USB_INT    12  // USB interrupt
#define ISR_WU         13  // Internal wakeup interrupt
