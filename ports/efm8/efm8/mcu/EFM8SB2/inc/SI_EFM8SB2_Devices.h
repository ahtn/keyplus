//------------------------------------------------------------------------------
// Copyright 2014 Silicon Laboratories, Inc.
// All rights reserved. This program and the accompanying materials
// are made available under the terms of the Silicon Laboratories End User
// License Agreement which accompanies this distribution, and is available at
// http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
// Original content and implementation provided by Silicon Laboratories.
//------------------------------------------------------------------------------
//Supported Devices:
//  EFM8SB20F16G_QFN24
//  EFM8SB20F32G_QFN24
//  EFM8SB20F32G_QFN32
//  EFM8SB20F32G_QFP32
//  EFM8SB20F64G_QFN24
//  EFM8SB20F64G_QFN32
//  EFM8SB20F64G_QFP32

#ifndef SI_EFM8SB2_DEVICES_H
#define SI_EFM8SB2_DEVICES_H

#define EFM8SB20F16G_QFN24 0x09
#define EFM8SB20F32G_QFN24 0x06
#define EFM8SB20F32G_QFN32 0x04
#define EFM8SB20F32G_QFP32 0x05
#define EFM8SB20F64G_QFN24 0x03
#define EFM8SB20F64G_QFN32 0x01
#define EFM8SB20F64G_QFP32 0x02

#if (EFM8SB2_DEVICE == EFM8SB20F16G_QFN24)
#define DEVICE_DERIVID EFM8SB20F16G_QFN24
#define DEVICE_FLASH_SIZE 0x4000
#define DEVICE_XRAM_SIZE 0x1000
#define DEVICE_PKG_QFN24 1

#elif (EFM8SB2_DEVICE == EFM8SB20F32G_QFN24)
#define DEVICE_DERIVID EFM8SB20F32G_QFN24
#define DEVICE_FLASH_SIZE 0x8000
#define DEVICE_XRAM_SIZE 0x1000
#define DEVICE_PKG_QFN24 1

#elif (EFM8SB2_DEVICE == EFM8SB20F32G_QFN32)
#define DEVICE_DERIVID EFM8SB20F32G_QFN32
#define DEVICE_FLASH_SIZE 0x8000
#define DEVICE_XRAM_SIZE 0x1000
#define DEVICE_PKG_QFN32 1

#elif (EFM8SB2_DEVICE == EFM8SB20F32G_QFP32)
#define DEVICE_DERIVID EFM8SB20F32G_QFP32
#define DEVICE_FLASH_SIZE 0x8000
#define DEVICE_XRAM_SIZE 0x1000
#define DEVICE_PKG_QFP32 1

#elif (EFM8SB2_DEVICE == EFM8SB20F64G_QFN24)
#define DEVICE_DERIVID EFM8SB20F64G_QFN24
#define DEVICE_FLASH_SIZE 0xFC00
#define DEVICE_XRAM_SIZE 0x1000
#define DEVICE_PKG_QFN24 1

#elif (EFM8SB2_DEVICE == EFM8SB20F64G_QFN32)
#define DEVICE_DERIVID EFM8SB20F64G_QFN32
#define DEVICE_FLASH_SIZE 0xFC00
#define DEVICE_XRAM_SIZE 0x1000
#define DEVICE_PKG_QFN32 1

#elif (EFM8SB2_DEVICE == EFM8SB20F64G_QFP32)
#define DEVICE_DERIVID EFM8SB20F64G_QFP32
#define DEVICE_FLASH_SIZE 0xFC00
#define DEVICE_XRAM_SIZE 0x1000
#define DEVICE_PKG_QFP32 1

#endif

#endif // SI_EFM8SB2_DEVICES_H

//-eof--------------------------------------------------------------------------

