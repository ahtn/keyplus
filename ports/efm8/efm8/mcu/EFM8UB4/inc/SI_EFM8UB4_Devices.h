//------------------------------------------------------------------------------
// Copyright 2014 Silicon Laboratories, Inc.
// All rights reserved. This program and the accompanying materials
// are made available under the terms of the Silicon Laboratories End User
// License Agreement which accompanies this distribution, and is available at
// http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
// Original content and implementation provided by Silicon Laboratories.
//------------------------------------------------------------------------------
//Supported Devices:
//  EFM8UB40F40G_QFN20
//  EFM8UB41F40G_QFN20
//  EFM8UB42F40G_QFN24
//  EFM8UB42F40G_QFN32
//  EFM8UB42F40G_QSOP24
//  EFM8UB44F40G_QFN32

#ifndef SI_EFM8UB4_DEVICES_H
#define SI_EFM8UB4_DEVICES_H

#define EFM8UB40F40G_QFN20 0x40
#define EFM8UB41F40G_QFN20 0x41
#define EFM8UB42F40G_QFN24 0x42
#define EFM8UB42F40G_QFN32 0x44
#define EFM8UB42F40G_QSOP24 0x43
#define EFM8UB44F40G_QFN32 0xD0

#if (EFM8UB4_DEVICE == EFM8UB40F40G_QFN20)
#define DEVICE_DERIVID EFM8UB40F40G_QFN20
#define DEVICE_FLASH_SIZE 0x9E00
#define DEVICE_XRAM_SIZE 0x0C00
#define DEVICE_PKG_QFN20 1

#elif (EFM8UB4_DEVICE == EFM8UB41F40G_QFN20)
#define DEVICE_DERIVID EFM8UB41F40G_QFN20
#define DEVICE_FLASH_SIZE 0x9E00
#define DEVICE_XRAM_SIZE 0x0C00
#define DEVICE_PKG_QFN20 1

#elif (EFM8UB4_DEVICE == EFM8UB42F40G_QFN24)
#define DEVICE_DERIVID EFM8UB42F40G_QFN24
#define DEVICE_FLASH_SIZE 0x9E00
#define DEVICE_XRAM_SIZE 0x0C00
#define DEVICE_PKG_QFN24 1

#elif (EFM8UB4_DEVICE == EFM8UB42F40G_QFN32)
#define DEVICE_DERIVID EFM8UB42F40G_QFN32
#define DEVICE_FLASH_SIZE 0x9E00
#define DEVICE_XRAM_SIZE 0x0C00
#define DEVICE_PKG_QFN32 1

#elif (EFM8UB4_DEVICE == EFM8UB42F40G_QSOP24)
#define DEVICE_DERIVID EFM8UB42F40G_QSOP24
#define DEVICE_FLASH_SIZE 0x9E00
#define DEVICE_XRAM_SIZE 0x0C00
#define DEVICE_PKG_QSOP24 1

#elif (EFM8UB4_DEVICE == EFM8UB44F40G_QFN32)
#define DEVICE_DERIVID EFM8UB44F40G_QFN32
#define DEVICE_FLASH_SIZE 0x9E00
#define DEVICE_XRAM_SIZE 0x0C00
#define DEVICE_PKG_QFN32 1

#endif

#endif // SI_EFM8UB4_DEVICES_H

//-eof--------------------------------------------------------------------------

