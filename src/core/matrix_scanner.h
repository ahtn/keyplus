// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include "config.h"

#include "core/util.h"

// TODO: support this or not?
/* // 21 bytes */
/* #define MAX_NUM_KEYS 168 */

// 16 bytes
#define MAX_NUM_KEYS 128

#define MAX_NUM_COLS 16
#define MAX_NUM_ROWS 10
#define MATRIX_DATA_SIZE ((MAX_NUM_ROWS) * ((MAX_NUM_COLS+7)/8))

typedef enum matrix_scanner_mode_t {
    MATRIX_SCANNER_MODE_NONE = 0x00, // doesn't have a matrix
    MATRIX_SCANNER_MODE_COL_ROW = 0x01, // normal col -->|-- row pin matrix
    MATRIX_SCANNER_MODE_ROW_COL = 0x02, // normal row -->|-- col pin matrix
    MATRIX_SCANNER_MODE_PINS = 0x03, // each pin represents a key
} matrix_scanner_mode_t;

typedef struct matrix_scan_plan_t {
    uint8_t mode; // scanning method
    uint8_t rows; // number of rows in the scan matrix
    uint8_t cols; // number of cols in the scan matrix
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

#if SCANNER_MATRIX_DELTA
extern uint8_t g_num_updated_keys;
extern uint8_t g_matrix_updated_keys[MAX_NUM_ROWS][(MAX_NUM_COLS+7)/8];
uint8_t get_number_updated_keys(void);
void matrix_clear_updated_keys_list(void);
#endif

extern uint8_t g_matrix[MAX_NUM_ROWS][(MAX_NUM_COLS+7)/8];

extern const ROM uint8_t *g_scan_key_map;
extern XRAM matrix_scan_plan_t g_scan_plan;

// functions to be called to update the key matrix
void init_matrix_scanner_utils(void);
void scanner_add_matrix_key(uint8_t row, uint8_t col);
void scanner_del_matrix_key(uint8_t row, uint8_t col);

// TODO
bit_t is_matrix_active(void);
