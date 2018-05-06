//------------------------------------------------------------------------------
// Copyright 2014 Silicon Laboratories, Inc.
// All rights reserved. This program and the accompanying materials
// are made available under the terms of the Silicon Laboratories End User
// License Agreement which accompanies this distribution, and is available at
// http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
// Original content and implementation provided by Silicon Laboratories.
//------------------------------------------------------------------------------
//Supported Devices:
//  EFM8UB10F16G_QFN20
//  EFM8UB10F16G_QFN28
//  EFM8UB10F8G_QFN20
//  EFM8UB11F16G_QFN24
//  EFM8UB11F16G_QSOP24

#ifndef SI_EFM8UB1_DEVICES_H
#define SI_EFM8UB1_DEVICES_H

#define EFM8UB10F16G_QFN20 0x43
#define EFM8UB10F16G_QFN28 0x41
#define EFM8UB10F8G_QFN20 0x49
#define EFM8UB11F16G_QFN24 0x4A
#define EFM8UB11F16G_QSOP24 0x45

#if (EFM8UB1_DEVICE == EFM8UB10F16G_QFN20)
#define DEVICE_DERIVID EFM8UB10F16G_QFN20
#define DEVICE_FLASH_SIZE 0x4000
#define DEVICE_XRAM_SIZE 0x0400
#define DEVICE_PKG_QFN20 1

#elif (EFM8UB1_DEVICE == EFM8UB10F16G_QFN28)
#define DEVICE_DERIVID EFM8UB10F16G_QFN28
#define DEVICE_FLASH_SIZE 0x4000
#define DEVICE_XRAM_SIZE 0x0400
#define DEVICE_PKG_QFN28 1

#elif (EFM8UB1_DEVICE == EFM8UB10F8G_QFN20)
#define DEVICE_DERIVID EFM8UB10F8G_QFN20
#define DEVICE_FLASH_SIZE 0x2000
#define DEVICE_XRAM_SIZE 0x0400
#define DEVICE_PKG_QFN20 1

#elif (EFM8UB1_DEVICE == EFM8UB11F16G_QFN24)
#define DEVICE_DERIVID EFM8UB11F16G_QFN24
#define DEVICE_FLASH_SIZE 0x4000
#define DEVICE_XRAM_SIZE 0x0400
#define DEVICE_PKG_QFN24 1

#elif (EFM8UB1_DEVICE == EFM8UB11F16G_QSOP24)
#define DEVICE_DERIVID EFM8UB11F16G_QSOP24
#define DEVICE_FLASH_SIZE 0x4000
#define DEVICE_XRAM_SIZE 0x0400
#define DEVICE_PKG_QSOP24 1

#endif

#endif // SI_EFM8UB1_DEVICES_H

//-eof--------------------------------------------------------------------------

