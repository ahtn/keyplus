//------------------------------------------------------------------------------
// Copyright 2014 Silicon Laboratories, Inc.
// All rights reserved. This program and the accompanying materials
// are made available under the terms of the Silicon Laboratories End User
// License Agreement which accompanies this distribution, and is available at
// http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
// Original content and implementation provided by Silicon Laboratories.
//------------------------------------------------------------------------------
//Supported Devices:
//  EFM8UB20F32G_QFN32
//  EFM8UB20F32G_QFP32
//  EFM8UB20F32G_QFP48
//  EFM8UB20F64G_QFN32
//  EFM8UB20F64G_QFP32
//  EFM8UB20F64G_QFP48

#ifndef SI_EFM8UB2_DEVICES_H
#define SI_EFM8UB2_DEVICES_H

#define EFM8UB20F32G_QFN32 0x65
#define EFM8UB20F32G_QFP32 0x64
#define EFM8UB20F32G_QFP48 0x63
#define EFM8UB20F64G_QFN32 0x62
#define EFM8UB20F64G_QFP32 0x61
#define EFM8UB20F64G_QFP48 0x60

#if (EFM8UB2_DEVICE == EFM8UB20F32G_QFN32)
#define DEVICE_DERIVID EFM8UB20F32G_QFN32
#define DEVICE_FLASH_SIZE 0x8000
#define DEVICE_XRAM_SIZE 0x0800
#define DEVICE_PKG_QFN32 1

#elif (EFM8UB2_DEVICE == EFM8UB20F32G_QFP32)
#define DEVICE_DERIVID EFM8UB20F32G_QFP32
#define DEVICE_FLASH_SIZE 0x8000
#define DEVICE_XRAM_SIZE 0x0800
#define DEVICE_PKG_QFP32 1

#elif (EFM8UB2_DEVICE == EFM8UB20F32G_QFP48)
#define DEVICE_DERIVID EFM8UB20F32G_QFP48
#define DEVICE_FLASH_SIZE 0x8000
#define DEVICE_XRAM_SIZE 0x0800
#define DEVICE_PKG_QFP48 1

#elif (EFM8UB2_DEVICE == EFM8UB20F64G_QFN32)
#define DEVICE_DERIVID EFM8UB20F64G_QFN32
#define DEVICE_FLASH_SIZE 0xFC00
#define DEVICE_XRAM_SIZE 0x1000
#define DEVICE_PKG_QFN32 1

#elif (EFM8UB2_DEVICE == EFM8UB20F64G_QFP32)
#define DEVICE_DERIVID EFM8UB20F64G_QFP32
#define DEVICE_FLASH_SIZE 0xFC00
#define DEVICE_XRAM_SIZE 0x1000
#define DEVICE_PKG_QFP32 1

#elif (EFM8UB2_DEVICE == EFM8UB20F64G_QFP48)
#define DEVICE_DERIVID EFM8UB20F64G_QFP48
#define DEVICE_FLASH_SIZE 0xFC00
#define DEVICE_XRAM_SIZE 0x1000
#define DEVICE_PKG_QFP48 1

#endif

#endif // SI_EFM8UB2_DEVICES_H

//-eof--------------------------------------------------------------------------

