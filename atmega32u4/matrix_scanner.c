// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/io_map.h"

#include <string.h>

#include "core/matrix_scanner.h"
#include "arch/avr/matrix_scanner.h"

#include "core/error.h"

#include "io_map/avr_port_util.h"

static XRAM uint8_t s_col_masks[IO_PORT_COUNT];

static uint8_t s_row_port_masks[IO_PORT_COUNT];
static uint8_t s_row_pin_mask[MAX_NUM_ROWS];
static io_port_t *s_row_ports[MAX_NUM_ROWS];

static uint8_t s_bytes_per_row;

static uint8_t s_parasitic_discharge_delay_idle;
static uint8_t s_parasitic_discharge_delay_debouncing;

typedef enum {
    COL_PULL_UP = 0,
    COL_PULL_DOWN,
    ROW_PULL_UP,
    ROW_PULL_DOWN
} pin_pull_type_t;

static inline void setup_pin(
    io_port_t *port,
    port_mask_t pin_mask,
    pin_pull_type_t pin_type
) {
    switch (pin_type) {
        case COL_PULL_UP: {
            // Set the column pins as inputs
            port->DDR &= ~pin_mask;

            // Now enable the pull-up resistors
            port->OUT |= pin_mask;
        } break;

        case ROW_PULL_UP: {
            // Initialize the row pins as inputs, will become outputs when
            // they are active
            port->DDR &= ~pin_mask;

            // Now disable pull-up resistors
            port->OUT &= ~pin_mask;
        } break;

        case COL_PULL_DOWN:
        case ROW_PULL_DOWN:
        default: {
            register_error(ERROR_UNSUPPORTED_SCAN_MODE);
        } break;
    }
}


/*********************************************************************
 *                         matrix setup code                         *
 *********************************************************************/

static void setup_columns(void) {
    // Note: DIR: 0 -> input, 1 -> output
    memset(s_col_masks, 0, IO_PORT_COUNT);

    for (uint8_t col_pin_i=0; col_pin_i < g_scan_plan.cols; col_pin_i++) {
        const uint8_t pin_number = io_map_get_col_pin(col_pin_i);
        const uint8_t col_port_num = IO_MAP_GET_PIN_PORT(pin_number);
        const uint8_t col_pin_bit = IO_MAP_GET_PIN_BIT(pin_number);
        s_col_masks[col_port_num] |= (1 << col_pin_bit);
    }

    const uint8_t max_col_pin_num = g_scan_plan.max_col_pin_num;
    const uint8_t max_port_num = INT_DIV_ROUND_UP(max_col_pin_num+1, IO_PORT_SIZE);
    uint8_t port_ii;
    for (port_ii = 0; port_ii < max_port_num; ++port_ii) {
        io_port_t *port = IO_MAP_GET_PORT(port_ii);
        uint8_t col_mask = s_col_masks[port_ii];

        // Nothing is set in this col
        if (col_mask == 0) {
            continue;
        }

        // Try to claim the pins
        //
        if (io_map_claim_pins(port_ii, col_mask)) {
            return; // return on error
        }

        // Hardware setup for the pin
        //
        // Initialize the pins, as inputs with pull-up resistors and
        // enable the interrupts on both rising/falling edges
        switch (g_scan_plan.mode) {
            case MATRIX_SCANNER_MODE_COL_ROW:
            case MATRIX_SCANNER_MODE_PIN_GND: {
                setup_pin( port, col_mask, COL_PULL_UP );
            } break;

            default: {
                register_error(ERROR_UNSUPPORTED_SCAN_MODE);
                return;
            } break;
        }
    }
}

static void setup_rows(void) {
    // Note: DIR: 0 -> input, 1 -> output
    memset(s_row_port_masks, 0, IO_PORT_COUNT);

    for (uint8_t row_pin_i=0; row_pin_i < g_scan_plan.rows; row_pin_i++) {
        const uint8_t pin_number = io_map_get_row_pin(row_pin_i);
        const uint8_t row_port_num = IO_MAP_GET_PIN_PORT(pin_number);
        const uint8_t row_pin_bit = IO_MAP_GET_PIN_BIT(pin_number);

        io_port_t *const port = IO_MAP_GET_PORT(row_port_num);
        const uint8_t row_bit_mask = (1 << row_pin_bit);

        if (io_map_claim_pins(row_port_num, row_bit_mask)) {
            return;
        }

        s_row_port_masks[row_port_num] |= row_bit_mask;
        s_row_pin_mask[row_pin_i] = row_bit_mask;
        s_row_ports[row_pin_i] = port;

        // Hardware setup for the pin
        switch (g_scan_plan.mode) {
            case MATRIX_SCANNER_MODE_COL_ROW:
            case MATRIX_SCANNER_MODE_PIN_GND: {
                setup_pin( port, row_bit_mask, ROW_PULL_UP );
            } break;

            default: {
                register_error(ERROR_UNSUPPORTED_SCAN_MODE);
                return;
            } break;
        }
    }
}

/// Selecting a row makes it outputs
static inline void select_row(uint8_t row) {
    io_port_t *port = s_row_ports[row];
    const uint8_t pin_mask = s_row_pin_mask[row];
    port->DDR |= pin_mask; // make output
    port->OUT &= ~pin_mask; // output low
}

// unselecting a row disconnects it
static inline void unselect_row(uint8_t row) {
    io_port_t *const port = s_row_ports[row];
    const uint8_t pin_mask = s_row_pin_mask[row];
    port->DDR &= ~pin_mask; // make input to disconnect output pin
    port->OUT &= ~pin_mask; // turn pull-up off
}

void matrix_scanner_init(void) {
    if (
        // g_scan_plan.cols > MAX_NUM_COLS ||
        g_scan_plan.rows > MAX_NUM_ROWS ||
        g_scan_plan.max_col_pin_num > IO_PORT_MAX_PIN_NUM
    ) {
        memset((uint8_t*)&g_scan_plan, 0, sizeof(matrix_scan_plan_t));
        register_error(ERROR_MATRIX_PINS_CONFIG_TOO_LARGE);
        return;
    }

    s_bytes_per_row = INT_DIV_ROUND_UP(g_scan_plan.max_col_pin_num+1, IO_PORT_SIZE);

    if (
        g_scan_plan.mode == MATRIX_SCANNER_MODE_COL_ROW ||
        g_scan_plan.mode == MATRIX_SCANNER_MODE_ROW_COL
    ) {
        setup_rows();
    }
    setup_columns();

    init_matrix_scanner_utils();

    // Configure the parasitic discharge delay based on how fast the mcu clock
    // is running
    s_parasitic_discharge_delay_idle = g_scan_plan.parasitic_discharge_delay_idle;
    s_parasitic_discharge_delay_debouncing = g_scan_plan.parasitic_discharge_delay_debouncing;

}

port_mask_t get_col_mask(uint8_t port_num) {
    return s_col_masks[port_num];
}

static inline uint8_t scan_row(uint8_t row) {
    const uint8_t new_row[IO_PORT_COUNT] = {
        ~PORT(B).IN & s_col_masks[PORT_B_NUM],
        ~PORT(C).IN & s_col_masks[PORT_C_NUM],
        ~PORT(D).IN & s_col_masks[PORT_D_NUM],
        ~PORT(E).IN & s_col_masks[PORT_E_NUM],
        ~PORT(F).IN & s_col_masks[PORT_F_NUM],
    };

    return scanner_debounce_row(row, new_row, s_bytes_per_row);
}

static inline bool matrix_scan_row_col_mode(void) {
    uint8_t row;
    bool scan_changed = false;

    for (row = 0; row < g_scan_plan.rows; ++row) {
        select_row(row);

        // After pulling a row low, an input column does not change
        // instantly because of parasitic capacitance.
        //
        // Parasitc capacitance of:
        // Xmega IO pin: 10pF
        // 1n4818 diode: 4pF
        // Cherry MX switch: 2pF
        //
        // The pull-up resistors in the xmega are 24kΩ. So we have a RC
        // circuit in the scanning matrix.
        // The RC circuit will take t=2RC to overcome the parasitic capacitance
        // and reach a low voltage (i.e. V < 0.3Vcc)
        //
        // MX switch and diodes are in series, so assume their combined
        // capacitance is min(4pF, 2pF) = 2pF.
        //
        // All the switch/diode pairs are connected in parallel with the input
        // pin on each row, so
        //
        // t = 2RC = 2 * 24_000 * (10 + 2*16) * 1e-12 == 2.016 µs
        // TODO: check if more error margin is needed
        // TODO: make this variable based on number of columns
        if (get_matrix_num_keys_debouncing()) {
            // Debouncing
            PARASITIC_DISCHARGE_DELAY_FAST_CLOCK(
                s_parasitic_discharge_delay_debouncing
            );
        } else {
            // not debouncing
            PARASITIC_DISCHARGE_DELAY_FAST_CLOCK(
                s_parasitic_discharge_delay_idle
            );
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
