// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#ifndef USB_VID
#define USB_VID 0x6666
#endif

#ifndef DEVICE_ID
#define DEVICE_ID 0x30
#endif

#ifndef USB_PID
#define USB_PID 0x3333
#endif

#if USE_UNIFYING_BOOTLOADER
#define BOOTLOADER_VID 0x046d
#define BOOTLOADER_PID 0xaaaa
#else
#define BOOTLOADER_VID 0x1915
#define BOOTLOADER_PID 0x0101
#endif

#ifndef USB_DEVICE_VERSION
#define USB_DEVICE_VERSION 0x0000
#endif

#define RF_POLLING 0
#define USB_BUFFERED 0

#define CONFIG_NO_MATRIX
