// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#define DEVICE_ID 0

#define CONFIG_MATRIX_SCAN_MODE MATRIX_SCANNER_MODE_COL_ROW
#define CONFIG_MATRIX_ROW_COUNT 4
#define CONFIG_MATRIX_COL_COUNT 6

#ifndef USB_DEVICE_VERSION
#define USB_DEVICE_VERSION 0x0000
#endif

// 0ms trigger tim on release, 8ms debounce time
#define DEBOUNCE_PRESS_TIME 8
#define DEBOUNCE_PRESS_TRIGGER_TIME 0

// 0ms trigger time on release, 10ms debounce time
#define DEBOUNCE_RELEASE_TIME 20
#define DEBOUNCE_RELEASE_TRIGGER_TIME 2

#define SCANNER_MATRIX_DELTA 1
