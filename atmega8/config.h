// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#define ROWS_PER_HAND 4
#define MATRIX_ROWS (ROWS_PER_HAND*2)
#define MATRIX_COLS 6

#define DEBOUNCE    5

#ifndef DEVICE_ID
#error "Need to set DEVICE_ID to build"
#endif
// If the master doesn't receive a response from a slave in this time,
// it will consider it disconnected, and reset its key state.
#define DISCONNECT_TIME 2

#define SCANNER_MATRIX_DELTA 0

#define CONFIG_MATRIX_SCAN_MODE MATRIX_SCANNER_MODE_COL_ROW
#define CONFIG_MATRIX_ROW_COUNT 4
#define CONFIG_MATRIX_COL_COUNT 6

#define NO_USB
