// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#define USB_VID 0x1209
#define USB_PID 0xBB00
#define USB_DEVICE_VERSION 0x00

#define INTERNAL_SCAN_METHOD MATRIX_SCANNER_INTERNAL_BASIC_SCAN

// #define NO_MATRIX
// #define MAX_NUM_ROWS 0

#define USB_BUFFERED 0

#define NO_SPLIT

#ifndef BOOTLOADER_VID
  #define BOOTLOADER_VID 0x10C4
#endif

#ifndef BOOTLOADER_PID
  #if defined(EFM8UB1_DEVICE)
    #define BOOTLOADER_PID 0xEAC9
  #elif defined(EFM8UB2_DEVICE)
    #define BOOTLOADER_PID 0xEACA
  #elif defined(EFM8UB3_DEVICE)
    #define BOOTLOADER_PID 0xEACB
  #else
    #error "Unknown or unsupported device type."
  #endif
#endif
