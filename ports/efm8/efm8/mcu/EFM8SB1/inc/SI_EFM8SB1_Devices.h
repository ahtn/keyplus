//------------------------------------------------------------------------------
// Copyright 2014 Silicon Laboratories, Inc.
// All rights reserved. This program and the accompanying materials
// are made available under the terms of the Silicon Laboratories End User
// License Agreement which accompanies this distribution, and is available at
// http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
// Original content and implementation provided by Silicon Laboratories.
//------------------------------------------------------------------------------
//Supported Devices:
//  EFM8SB10F2G_QFN20
//  EFM8SB10F4G_QFN20
//  EFM8SB10F8A_QFN20
//  EFM8SB10F8A_QFN24
//  EFM8SB10F8G_CSP16
//  EFM8SB10F8G_QFN20
//  EFM8SB10F8G_QFN24
//  EFM8SB10F8G_QSOP24

#ifndef SI_EFM8SB1_DEVICES_H
#define SI_EFM8SB1_DEVICES_H

#define EFM8SB10F2G_QFN20 0x09
#define EFM8SB10F4G_QFN20 0x06
#define EFM8SB10F8A_QFN20 0x23
#define EFM8SB10F8A_QFN24 0x21
#define EFM8SB10F8G_CSP16 0x0A
#define EFM8SB10F8G_QFN20 0x03
#define EFM8SB10F8G_QFN24 0x01
#define EFM8SB10F8G_QSOP24 0x02

#if (EFM8SB1_DEVICE == EFM8SB10F2G_QFN20)
#define DEVICE_DERIVID EFM8SB10F2G_QFN20
#define DEVICE_FLASH_SIZE 0x0800
#define DEVICE_XRAM_SIZE 0x0000
#define DEVICE_PKG_QFN20 1

#elif (EFM8SB1_DEVICE == EFM8SB10F4G_QFN20)
#define DEVICE_DERIVID EFM8SB10F4G_QFN20
#define DEVICE_FLASH_SIZE 0x1000
#define DEVICE_XRAM_SIZE 0x0100
#define DEVICE_PKG_QFN20 1

#elif (EFM8SB1_DEVICE == EFM8SB10F8A_QFN20)
#define DEVICE_DERIVID EFM8SB10F8A_QFN20
#define DEVICE_FLASH_SIZE 0x2000
#define DEVICE_XRAM_SIZE 0x0100
#define DEVICE_PKG_QFN20 1

#elif (EFM8SB1_DEVICE == EFM8SB10F8A_QFN24)
#define DEVICE_DERIVID EFM8SB10F8A_QFN24
#define DEVICE_FLASH_SIZE 0x2000
#define DEVICE_XRAM_SIZE 0x0100
#define DEVICE_PKG_QFN24 1

#elif (EFM8SB1_DEVICE == EFM8SB10F8G_CSP16)
#define DEVICE_DERIVID EFM8SB10F8G_CSP16
#define DEVICE_FLASH_SIZE 0x2000
#define DEVICE_XRAM_SIZE 0x0100
#define DEVICE_PKG_CSP16 1

#elif (EFM8SB1_DEVICE == EFM8SB10F8G_QFN20)
#define DEVICE_DERIVID EFM8SB10F8G_QFN20
#define DEVICE_FLASH_SIZE 0x2000
#define DEVICE_XRAM_SIZE 0x0100
#define DEVICE_PKG_QFN20 1

#elif (EFM8SB1_DEVICE == EFM8SB10F8G_QFN24)
#define DEVICE_DERIVID EFM8SB10F8G_QFN24
#define DEVICE_FLASH_SIZE 0x2000
#define DEVICE_XRAM_SIZE 0x0100
#define DEVICE_PKG_QFN24 1

#elif (EFM8SB1_DEVICE == EFM8SB10F8G_QSOP24)
#define DEVICE_DERIVID EFM8SB10F8G_QSOP24
#define DEVICE_FLASH_SIZE 0x2000
#define DEVICE_XRAM_SIZE 0x0100
#define DEVICE_PKG_QSOP24 1

#endif

#endif // SI_EFM8SB1_DEVICES_H

//-eof--------------------------------------------------------------------------

