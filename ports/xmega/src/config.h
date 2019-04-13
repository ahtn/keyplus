// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#ifndef USB_VID
#define USB_VID 0x1209
#endif

#ifndef USB_PID
#define USB_PID 0xBB00
#endif

#ifndef DEVICE_ID
#define DEVICE_ID 0
#endif

#ifndef USB_DEVICE_VERSION
#define USB_DEVICE_VERSION 0x0000
#endif

#if !defined(BOOTLOADER_VID) && !defined(BOOTLOADER_PID)
#define BOOTLOADER_VID 0x1209
#define BOOTLOADER_PID 0xBB01
#endif

// TODO: move to settings
// TODO: an option to enter deep sleep when there has been no change in the matrix
// state for a long time
#define DEEP_SLEEP_TIME 3000

#define SCANNER_MATRIX_DELTA 1

#define INTERNAL_SCAN_METHOD (MATRIX_SCANNER_INTERNAL_FAST_ROW_COL)
#define RF_POLLING 0

#ifndef MAX_NUM_ROWS
#define MAX_NUM_ROWS 18
#endif
