// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include "config.h"

#include "core/io_map.h"
#include "core/util.h"

// TODO: support this or not?
/* // 21 bytes */
/* #define MAX_NUM_KEYS 168 */

// 16 bytes
#define MAX_NUM_KEYS 128

// #define MAX_NUM_COLS 16
// #define MAX_NUM_ROWS 10
// #define MATRIX_DATA_SIZE ((MAX_NUM_ROWS) * ((MAX_NUM_COLS+7)/8))

#define MAX_NUM_COLS 16
#define MAX_NUM_ROWS 10
#define MATRIX_DATA_SIZE ((MAX_NUM_ROWS) * (IO_PORT_COUNT))

typedef enum matrix_scanner_mode_t {
    MATRIX_SCANNER_MODE_NONE = 0x00, // doesn't have a matrix
    MATRIX_SCANNER_MODE_COL_ROW = 0x01, // normal col -->|-- row pin matrix
    MATRIX_SCANNER_MODE_ROW_COL = 0x02, // normal row -->|-- col pin matrix
    MATRIX_SCANNER_MODE_PINS = 0x03, // each pin represents a key
} matrix_scanner_mode_t;

typedef enum matrix_internal_scan_method_t {
    MATRIX_SCANNER_INTERNAL_NONE = 0x00,
    MATRIX_SCANNER_INTERNAL_FAST_ROW_COL = 0x01,
    MATRIX_SCANNER_INTERNAL_SLOW_ROW_COL = 0x02,
    MATRIX_SCANNER_INTERNAL_HARD_CODED = 0x03,
    // MATRIX_SCANNER_INTERNAL_IO_EXPANDER = 0x03,
    MATRIX_SCANNER_INTERNAL_CUSTOM = 0xff,
} matrix_internal_scan_method_t;

#define DEFAULT_DEBOUNCE_PRESS_TIME 5
#define DEFAULT_DEBOUNCE_RELEASE_TIME (2*DEFAULT_DEBOUNCE_PRESS_TIME)
#define DEFAULT_RELEASE_TRIGGER_TIME 3
#define DEFAULT_PRESS_TRIGGER_TIME 1
#define DEFAULT_PARASITIC_DISCHARGE_DELAY_PRESS 1
#define DEFAULT_PARASITIC_DISCHARGE_DELAY_DEBOUNCE 10

typedef struct matrix_scan_plan_t {
    uint8_t mode; // scanning method
    uint8_t rows; // number of rows in the scan matrix
    uint8_t cols; // number of cols in the scan matrix
    uint8_t debounce_time_press; // How long to debounce a key when it is pressed (ms)
    uint8_t debounce_time_release; // How long to debounce a key when it is released (ms)
    uint8_t trigger_time_press; // The key must be down this long before being registered (ms)
    uint8_t trigger_time_release; // The key must be up this long before being registered (ms)

    // Both delays are measured on a scale of 0-48µs
    uint8_t parasitic_discharge_delay_idle; // How long to hold a row low before reading the columns
    uint8_t parasitic_discharge_delay_debouncing; // How long to hold a row low when a key is debouncing
    uint8_t max_col; // maximum column pin number used
    uint8_t max_key_num; // highest key number used
} matrix_scan_plan_t;

// setup the matrix for scanning
void matrix_scanner_init(void);

// scan the whole matrix, result stored in g_matrix
bool matrix_scan(void);

// setup the matrix so that any change (press/release) of the matrix will
// cause an interrupt to fire. used for waking the mcu from sleep.
void matrix_scan_irq_enable(void);
void matrix_scan_irq_disable(void);
bool matrix_scan_irq_has_triggered(void);
bool matrix_has_active_row(void);

// How many bytes of data is stored in the matrix (i.e. size=ceil(num_physical_keys/8))
uint8_t get_matrix_data(uint8_t *dest, bool use_deltas);
uint8_t get_matrix_compressed_size(void);
uint8_t get_matrix_num_keys_down(void);
uint8_t get_matrix_num_keys_debouncing(void);

extern uint8_t g_matrix[MAX_NUM_ROWS][IO_PORT_COUNT];

extern const ROM uint8_t *g_scan_key_map;
extern XRAM matrix_scan_plan_t g_scan_plan;

// functions to be called to update the key matrix
void init_matrix_scanner_utils(void);
void scanner_add_matrix_key(uint8_t key_num);
void scanner_del_matrix_key(uint8_t key_num);

void scanner_init_debouncer(void);
bool scanner_debounce_row(
    uint8_t row,
    const uint8_t *old_row,
    const uint8_t *new_row,
    uint8_t bytes_per_row
);

// TODO
bit_t is_matrix_active(void);
