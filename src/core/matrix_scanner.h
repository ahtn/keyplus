// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)
/// @file core/matrix_scanner.h

#pragma once

#include "config.h"

#include "core/util.h"

#if USE_SCANNER
#include "core/io_map.h"

#if !defined(MAX_NUM_ROWS)
/// Max number of rows allowed for the matrix scanner
#error "MAX_NUM_ROWS needs to be defined"
#endif

#else
#define MAX_NUM_ROWS 0
#endif

/// Max number of keys a split keyboard device can use (16 bytes)
#define MAX_NUM_KEYS 128

/// Size of the bitmap used to store key numbers
#define KEY_NUMBER_BITMAP_SIZE (MAX_NUM_KEYS/8)

#define MAX_NUM_COLS IO_MAP_GPIO_COUNT

/// How much ram is needed to store the matrix in the matrix scanner module
#define MATRIX_DATA_SIZE ((MAX_NUM_ROWS) * (IO_PORT_COUNT))

#define INVALID_KEY_NUMBER 0xff

/// Different scanning methods that can be loaded from the configuration file
typedef enum matrix_scanner_mode_t {
    MATRIX_SCANNER_MODE_NO_MATRIX = 0x00, ///< doesn't have a matrix
    MATRIX_SCANNER_MODE_COL_ROW = 0x01, ///< normal col -->|-- row pin matrix
    MATRIX_SCANNER_MODE_ROW_COL = 0x02, ///< normal row -->|-- col pin matrix
    MATRIX_SCANNER_MODE_PIN_GND = 0x03, ///< each pin represents a key (active low)
    MATRIX_SCANNER_MODE_PIN_VCC = 0x04, ///< each pin represents a key (active high)
} matrix_scanner_mode_t;

/// Device information about the in-built scanning method used by the device.
///
/// The scanning method will be fixed at compile time, and the flasher software
/// needs to know what format the device uses to correctly load pin configuration.
typedef enum matrix_internal_scan_method_t {
    /// No matrix scanning supported
    MATRIX_SCANNER_INTERNAL_NONE = 0x00,
    /// The FAST_ROW_COL scanner uses a lookup table to map (port, pin) pairs
    /// to key numbers. When used the flasher has to provide a lookup table
    /// that contains `num_rows * max_col_pin_num` key numbers for each pin.
    ///
    /// Also, instead of providing a list of column keys, it should provide
    /// a bit mask for each port indicating which keys are scanned as columns.
    MATRIX_SCANNER_INTERNAL_FAST_ROW_COL = 0x01,
    /// The SLOW_ROW_COL scanner uses a list of rows and columns, and scans
    /// each pin one after the other. The flasher should provide both
    /// the row and column keys as a list of pins. The key number map will be
    /// `num_rows * num_columns` large with one entry for each (row, col) pair.
    MATRIX_SCANNER_INTERNAL_SLOW_ROW_COL = 0x02,
    /// The matrix scanning algorithm is hard coded.
    ///
    /// TODO: decide how the keys are remapped in this case. The key numbers
    /// should still be remappable though.
    MATRIX_SCANNER_INTERNAL_HARD_CODED = 0x03,
    // MATRIX_SCANNER_INTERNAL_IO_EXPANDER = 0x04,
    /// The matrix
    MATRIX_SCANNER_INTERNAL_CUSTOM = 0xff,
} matrix_internal_scan_method_t;

typedef struct matrix_scan_plan_t {
    uint8_t mode; ///< matrix scanning mode
    uint8_t rows; ///< number of rows in the scan matrix
    uint8_t cols; ///< number of cols in the scan matrix
    uint8_t debounce_time_press; ///< How long to debounce a key when it is pressed (ms)
    uint8_t debounce_time_release; ///< How long to debounce a key when it is released (ms)
    uint8_t trigger_time_press; ///< The key must be down this long before being registered (ms)
    uint8_t trigger_time_release; ///< The key must be up this long before being registered (ms)

    /// How long to hold a row low before reading the columns. Measured on a
    /// scale of 0-48μs.
    uint8_t parasitic_discharge_delay_idle;
    /// How long to hold a row low before reading the column pins while a key
    /// is being debounced. Measured on a scale of 0-48μs.
    uint8_t parasitic_discharge_delay_debouncing;
    uint8_t max_col_pin_num; ///< The largest column pin number used.
    uint8_t max_key_num; ///< The largest key number used.
} matrix_scan_plan_t;


/*********************************************************************
 *                         global variables                          *
 *********************************************************************/

extern XRAM uint8_t g_matrix[MAX_NUM_ROWS][IO_PORT_COUNT];
extern XRAM uint8_t g_key_num_bitmap[KEY_NUMBER_BITMAP_SIZE];

extern const ROM uint8_t *g_scan_key_map;
extern XRAM matrix_scan_plan_t g_scan_plan;

/*********************************************************************
 *                         public functions                          *
 *********************************************************************/

/// Setup the matrix for scanning.
void matrix_scanner_init(void);

/// scan the whole matrix, result stored in g_matrix
bool matrix_scan(void);

/// Put the matrix into interrupt mode.
///
/// Setup the matrix so that any change (press/release) of the matrix will
/// cause an interrupt to fire. Used for waking the mcu from sleep.
void matrix_scan_irq_enable(void);

/// Disable matrix interrupts
void matrix_scan_irq_disable(void);

/// Checks whether a matrix interrupt has been triggered since `matrix_scan_irq_enable()` was called
/// Can be cleared with `matrix_scan_irq_clear()`
bool matrix_scan_irq_has_triggered(void);

/// Clear the matrix interrupt flag
void matrix_scan_irq_clear(void);

/// Returns true if
bool matrix_has_active_row(void);

/// How many bytes of data is stored in the matrix (i.e. size=ceil(num_physical_keys/8))
uint8_t get_matrix_compressed_size(void);
/// Returns the number of keys currently pressed in the matrix
uint8_t get_matrix_num_keys_down(void);
/// Returns the number of keys currently being debounced in the matrix
uint8_t get_matrix_num_keys_debouncing(void);

/// functions to be called to update the key matrix
void init_matrix_scanner_utils(void);

/// Get a matrix packet that for the most recent matrix scan.
///
/// This function will generate a matrix packet that contains the key state
/// for all keys in the matrix. The result may either be a list of keys,
/// a bitmap of the entire matrix state, or the list of keys that changed in
/// the most recent matrix scan.
///
/// The functions `scanner_add_matrix_key()` and `scanner_del_matrix_key()` are
/// used to update which keys are pressed in the matrix scanner module.
///
/// If the `use_deltas` flag is set, then a matrix delta packet will be generated,
/// that is a packet which lists only the keys that changed and not the entire
/// matrix state. However, the function may choose to ignore the `use_deltas`
/// flag if it is more efficient to transmit the entire matrix state.
uint8_t get_matrix_data(uint8_t *dest, bool use_deltas);

/// Add a pressed key to the matrix scanner, putting it in the pressed state.
///
/// Note: called internally by `scanner_debounce_row()`
void scanner_add_matrix_key(uint8_t key_num);

/// Remove a released key from the matrix scanner, putting it in the released state.
///
/// Note: called internally by `scanner_debounce_row()`
void scanner_del_matrix_key(uint8_t key_num);

/// Matrix debouncer utility function.
///
/// Given a `new row`, this function will perform matrix debouncing on the keys
/// given. If the debouncer detects that any change in key state from the
/// last time this function was called, then it will use
/// `scanner_del_matrix_key()` and `scanner_add_matrix_key()` to add the key
/// press/release event to the matrix scanner module.
///
/// s
bool scanner_debounce_row(
    uint8_t row,
    const uint8_t *new_row,
    uint8_t bytes_per_row
);

/// If passthrough is enabled, this command will send the key matrix to the
/// host when it changes.
void passthrough_keycodes_task(void);
