// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)
/// @file ports/efm8/src/matrix_scanner.c
///
/// @brief Default matrix scanner module for EFM8
///
///
///
/// Configurations for column pins:
/// * Px.x==1 -> Weak pull up
/// * Px.x==0 -> Drive low
///
/// Configurations for row pins:
/// * Px.x==1 -> Weak pull up
/// * Px.x==0 -> Drive low
///
/// NOTE: This is the default state for an EFM8 IO pin, so don't actually
/// need to add any functionality to set this up.


#include "core/io_map.h"

#include <string.h>

#include "core/error.h"
#include "core/matrix_scanner.h"

#include "efm8_port_util.h"
#include "efm8_util/delay.h"


static XRAM uint8_t s_col_masks[IO_PORT_COUNT];

static XRAM uint8_t s_parasitic_discharge_delay_idle;
static XRAM uint8_t s_parasitic_discharge_delay_debouncing;

/// Selecting a row makes it outputs
static inline void select_row(uint8_t row) {
    uint8_t pin_number = io_map_get_row_pin(row);
    uint8_t port = IO_MAP_GET_PIN_PORT(pin_number);
    uint8_t bit  = IO_MAP_GET_PIN_BIT(pin_number);
    efm8_port_clear(port, 1<<bit);
}

// unselecting a row disconnects it
static inline void unselect_row(uint8_t row) {
    uint8_t pin_number = io_map_get_row_pin(row);
    uint8_t port = IO_MAP_GET_PIN_PORT(pin_number);
    uint8_t bit  = IO_MAP_GET_PIN_BIT(pin_number);
    efm8_port_set(port, 1<<bit);
}


static void setup_columns(void) {
    memset(s_col_masks, 0, IO_PORT_COUNT);

    for (uint8_t col_pin_i=0; col_pin_i < g_scan_plan.cols; col_pin_i++) {
        const uint8_t pin_number = io_map_get_col_pin(col_pin_i);
        const uint8_t col_port_num = IO_MAP_GET_PIN_PORT(pin_number);
        const uint8_t col_pin_bit = IO_MAP_GET_PIN_BIT(pin_number);
        // g_scan_plan.max_col_pin_num = MAX(pin_number, g_scan_plan.max_col_pin_num);
        s_col_masks[col_port_num] |= (1 << col_pin_bit);
        io_map_claim_pins(col_port_num, (1 << col_pin_bit));
    }
}

void matrix_scanner_init(void) {
    if (
        g_scan_plan.rows > MAX_NUM_ROWS ||
        g_scan_plan.max_col_pin_num > IO_PORT_MAX_PIN_NUM
    ) {
        memset((uint8_t*)&g_scan_plan, 0, sizeof(matrix_scan_plan_t));
        register_error(ERROR_MATRIX_PINS_CONFIG_TOO_LARGE);
        return;
    }

    switch (g_scan_plan.mode) {
            case MATRIX_SCANNER_MODE_COL_ROW:
            case MATRIX_SCANNER_MODE_PIN_GND: {
            } break;
            default: {
                register_error(ERROR_UNSUPPORTED_SCAN_MODE);
                return;
            }
    }

    // Don't need to setup rows
    setup_columns();

    if (g_scan_plan.max_col_pin_num > IO_PORT_MAX_PIN_NUM) {
        register_error(ERROR_MATRIX_PINS_CONFIG_TOO_LARGE);
    }

    init_matrix_scanner_utils();

    // This delay is a value [0, 255] which maps to the [0µs, 48µs]
    s_parasitic_discharge_delay_idle = \
        ((uint16_t)g_scan_plan.parasitic_discharge_delay_idle * 48) / 255;
    s_parasitic_discharge_delay_debouncing = \
        ((uint16_t)g_scan_plan.parasitic_discharge_delay_debouncing * 48) / 255;
}

port_mask_t get_col_mask(uint8_t port_num) {
    return s_col_masks[port_num];
}

static inline uint8_t scan_row(uint8_t row) {
    static XRAM uint8_t new_row[IO_PORT_COUNT];

    new_row[0] = ~P0 & s_col_masks[0];
    new_row[1] = ~P1 & s_col_masks[1];
    new_row[2] = ~P2 & s_col_masks[2];
#if IO_PORT_MAX_PORT_NUM >= 3
    new_row[3] = ~P3 & s_col_masks[3];
#endif
#if IO_PORT_MAX_PORT_NUM >= 4
    new_row[4] = ~P4 & s_col_masks[4];
#endif

    return scanner_debounce_row(row, new_row, IO_PORT_COUNT);
}

static inline bool matrix_scan_row_col_mode(void) {
    uint8_t row;
    bool scan_changed = false;

    // Store in local variables to copy values from XRAM into IRAM
    uint8_t delay_idle = s_parasitic_discharge_delay_idle;
    uint8_t delay_debounce = s_parasitic_discharge_delay_debouncing;

    for (row = 0; row < g_scan_plan.rows; ++row) {
        select_row(row);

        if (get_matrix_num_keys_debouncing()) {
            efm8_delay_us(delay_debounce);
        } else {
            efm8_delay_us(delay_idle);
        }

        scan_changed |= scan_row(row);
        unselect_row(row);
    }

    return scan_changed;
}

static inline bool matrix_scan_pin_mode(void) {
    return scan_row(0);
}

bool matrix_scan(void) {
    switch (g_scan_plan.mode) {
        case MATRIX_SCANNER_MODE_COL_ROW:
        case MATRIX_SCANNER_MODE_ROW_COL: {
            return matrix_scan_row_col_mode();
        }

        case MATRIX_SCANNER_MODE_PIN_GND:
        case MATRIX_SCANNER_MODE_PIN_VCC: {
            return matrix_scan_pin_mode();
        }

        default: {
        } break;
    }

    return false;
}
