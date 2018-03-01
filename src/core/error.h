// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include "core/util.h"

#define NUM_ERROR_CODES 128
#define SIZE_ERROR_CODE_TABLE (NUM_ERROR_CODES / 8)

typedef enum error_code_type {
    // non-critical errors
    ERROR_EKC_OUT_OF_BOUNDS_ACCESS = 0,
    ERROR_UNHANDLED_KEYCODE = 1,
    ERROR_RECEIVED_TOO_LARGE_DEVICE_ID = 2,
    ERROR_RECEIVED_TOO_LARGE_MATRIX = 3,
    ERROR_KEY_EVENT_QUEUE_FULL = 4,
    ERROR_KEY_EVENT_QUEUE_UNLOADED_DEVICE = 5,
    ERROR_VENDOR_IN_REPORT_CANT_KEEP_UP = 6,
    ERROR_INVALID_KB_ID_USED = 7,

    // critical errors
    CRITICAL_ERROR_START = 64,
    ERROR_EKC_STORAGE_TOO_LARGE = 64,
    ERROR_NUM_LAYOUTS_TOO_LARGE = 65,
    ERROR_SETTINGS_CRC_MISMATCH = 66,
    ERROR_LAYOUT_STORAGE_OUT_OF_BOUNDS = 67,
    ERROR_MATRIX_PINS_CONFIG_TOO_LARGE = 68,
    ERROR_PIN_MAPPING_CONFLICT = 69,
    ERROR_NRF24_BAD_SPI_CONNECTION = 70,
    ERROR_UNSUPPORTED_SCAN_MODE = 71,
    ERROR_MAXIMUM_KEY_NUMBER_EXCEEDED = 72,
} error_code_type;

extern XRAM uint8_t g_error_code_table[SIZE_ERROR_CODE_TABLE];

void init_error_system(void);
bit_t has_critical_error(void);
void register_error(uint8_t code);
void unregister_error(uint8_t code);
// #define init_error_system() do {} while(0)
// #define has_critical_error() true
// #define register_error(code) do {} while(0)
// #define unregister_error(code) do {} while(0)
