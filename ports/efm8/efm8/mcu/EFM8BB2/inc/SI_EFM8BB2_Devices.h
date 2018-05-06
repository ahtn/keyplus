//------------------------------------------------------------------------------
// Copyright 2014 Silicon Laboratories, Inc.
// All rights reserved. This program and the accompanying materials
// are made available under the terms of the Silicon Laboratories End User
// License Agreement which accompanies this distribution, and is available at
// http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
// Original content and implementation provided by Silicon Laboratories.
//------------------------------------------------------------------------------
//Supported Devices:
//  EFM8BB21F16A_QFN20
//  EFM8BB21F16G_QFN20
//  EFM8BB21F16G_QSOP24
//  EFM8BB21F16I_QFN20
//  EFM8BB21F16I_QSOP24
//  EFM8BB22F16A_QFN28
//  EFM8BB22F16G_QFN28
//  EFM8BB22F16I_QFN28

#ifndef SI_EFM8BB2_DEVICES_H
#define SI_EFM8BB2_DEVICES_H

#define EFM8BB21F16A_QFN20 0x23
#define EFM8BB21F16G_QFN20 0x03
#define EFM8BB21F16G_QSOP24 0x02
#define EFM8BB21F16I_QFN20 0x13
#define EFM8BB21F16I_QSOP24 0x12
#define EFM8BB22F16A_QFN28 0x21
#define EFM8BB22F16G_QFN28 0x01
#define EFM8BB22F16I_QFN28 0x11

#if (EFM8BB2_DEVICE == EFM8BB21F16A_QFN20)
#define DEVICE_DERIVID EFM8BB21F16A_QFN20
#define DEVICE_FLASH_SIZE 0x4000
#define DEVICE_XRAM_SIZE 0x0800
#define DEVICE_PKG_QFN20 1

#elif (EFM8BB2_DEVICE == EFM8BB21F16G_QFN20)
#define DEVICE_DERIVID EFM8BB21F16G_QFN20
#define DEVICE_FLASH_SIZE 0x4000
#define DEVICE_XRAM_SIZE 0x0800
#define DEVICE_PKG_QFN20 1

#elif (EFM8BB2_DEVICE == EFM8BB21F16G_QSOP24)
#define DEVICE_DERIVID EFM8BB21F16G_QSOP24
#define DEVICE_FLASH_SIZE 0x4000
#define DEVICE_XRAM_SIZE 0x0800
#define DEVICE_PKG_QSOP24 1

#elif (EFM8BB2_DEVICE == EFM8BB21F16I_QFN20)
#define DEVICE_DERIVID EFM8BB21F16I_QFN20
#define DEVICE_FLASH_SIZE 0x4000
#define DEVICE_XRAM_SIZE 0x0800
#define DEVICE_PKG_QFN20 1

#elif (EFM8BB2_DEVICE == EFM8BB21F16I_QSOP24)
#define DEVICE_DERIVID EFM8BB21F16I_QSOP24
#define DEVICE_FLASH_SIZE 0x4000
#define DEVICE_XRAM_SIZE 0x0800
#define DEVICE_PKG_QSOP24 1

#elif (EFM8BB2_DEVICE == EFM8BB22F16A_QFN28)
#define DEVICE_DERIVID EFM8BB22F16A_QFN28
#define DEVICE_FLASH_SIZE 0x4000
#define DEVICE_XRAM_SIZE 0x0800
#define DEVICE_PKG_QFN28 1

#elif (EFM8BB2_DEVICE == EFM8BB22F16G_QFN28)
#define DEVICE_DERIVID EFM8BB22F16G_QFN28
#define DEVICE_FLASH_SIZE 0x4000
#define DEVICE_XRAM_SIZE 0x0800
#define DEVICE_PKG_QFN28 1

#elif (EFM8BB2_DEVICE == EFM8BB22F16I_QFN28)
#define DEVICE_DERIVID EFM8BB22F16I_QFN28
#define DEVICE_FLASH_SIZE 0x4000
#define DEVICE_XRAM_SIZE 0x0800
#define DEVICE_PKG_QFN28 1

#endif

#endif // SI_EFM8BB2_DEVICES_H

//-eof--------------------------------------------------------------------------

