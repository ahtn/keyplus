// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/matrix_scanner.h"

#include "core/error.h"

#include <string.h>
#include "nrf_gpio.h"
#include "nrf_delay.h"

static uint32_t s_ports_per_row;
static uint32_t s_bytes_per_row;

static port_mask_t s_col_masks[IO_PORT_COUNT];

static port_mask_t s_row_port_masks[IO_PORT_COUNT];
static port_mask_t s_row_pin_mask[MAX_NUM_ROWS];
static io_port_t *s_row_ports[MAX_NUM_ROWS];

static bool s_col_read_invert;
static bool s_row_drive;

static inline void unselect_all_rows(void);
static inline void select_all_rows(void);

/// Configure all the pins in `port_mask` to the provided settings.
static void gpio_cfg_port_mask(
    uint32_t             port_num,
    uint32_t             port_mask,
    nrf_gpio_pin_dir_t   dir,
    nrf_gpio_pin_input_t input,
    nrf_gpio_pin_pull_t  pull,
    nrf_gpio_pin_drive_t drive,
    nrf_gpio_pin_sense_t sense
) {
    uint32_t pin_num = 0;
    uint32_t mask = port_mask;

    while (mask) {
        if (mask & 1) {
            nrf_gpio_cfg(
                NRF_GPIO_PIN_MAP(port_num, pin_num),
                dir,
                input,
                pull,
                drive,
                sense
            );
        }
        mask >>= 1;
        pin_num++;
    }
}

/// Setup the columns as inputs with pull ups
static void setup_columns(void) {
    // Note: DIR: 0 -> input, 1 -> output

    for (uint8_t col_pin_i=0; col_pin_i < g_scan_plan.cols; col_pin_i++) {
        const uint8_t pin_number = io_map_get_col_pin(col_pin_i);
        const uint8_t col_port_num = IO_MAP_GET_PIN_PORT(pin_number);
        const uint8_t col_pin_bit = IO_MAP_GET_PIN_BIT(pin_number);
        s_col_masks[col_port_num] |= (port_mask_t)(1 << col_pin_bit);
    }

    const uint8_t max_col_pin_num = g_scan_plan.max_col_pin_num;
    const uint8_t max_port_num = INT_DIV_ROUND_UP(max_col_pin_num+1, IO_PORT_SIZE);
    uint8_t port_ii;
    for (port_ii = 0; port_ii < max_port_num; ++port_ii) {
        // io_port_t *port = IO_MAP_GET_PORT(port_ii);
        port_mask_t col_mask = s_col_masks[port_ii];

        // Nothing is set in this col
        if (col_mask == 0) {
            continue;
        }

        // Try to claim the pins
        if (io_map_claim_pins(port_ii, col_mask)) {
            register_error(ERROR_PIN_MAPPING_CONFLICT);
            return; // return on error
        }

        // Hardware setup for the pin
        //
        // Initialize the pins, as inputs with pull-up resistors and
        // enable the interrupts on both rising/falling edges
        switch (g_scan_plan.mode) {
            // These modes need a pull-down resistor and non-inverted input
            case MATRIX_SCANNER_MODE_ROW_COL:
            case MATRIX_SCANNER_MODE_PIN_VCC: {
                // Diodes are facing from row to column ( row -->|-- col)
                // Or pins are connected GPIO --switch--> VCC
                s_col_read_invert = 0;
                gpio_cfg_port_mask(
                    port_ii,
                    col_mask,
                    NRF_GPIO_PIN_DIR_INPUT,
                    NRF_GPIO_PIN_INPUT_CONNECT,
                    NRF_GPIO_PIN_PULLDOWN,
                    NRF_GPIO_PIN_S0S1,
                    NRF_GPIO_PIN_NOSENSE
                );
            } break;

            // These cases need a pull-up resistor and inverted input
            //
            // NOTE: nRF52 doesn't have hardware to invert input like
            // xmega, so have to do it in software while scanning
            case MATRIX_SCANNER_MODE_COL_ROW:
            case MATRIX_SCANNER_MODE_PIN_GND: {
                // Diodes are facing from column to row ( col -->|-- row)
                // Or pins are connected GPIO --switch--> GND
                s_col_read_invert = 1;
                gpio_cfg_port_mask(
                    port_ii,
                    col_mask,
                    NRF_GPIO_PIN_DIR_INPUT,
                    NRF_GPIO_PIN_INPUT_CONNECT,
                    NRF_GPIO_PIN_PULLUP,
                    NRF_GPIO_PIN_S0S1,
                    NRF_GPIO_PIN_NOSENSE
                );
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
    memset(s_row_port_masks, 0, sizeof(port_mask_t)*IO_PORT_COUNT);

    for (uint8_t row_pin_i=0; row_pin_i < g_scan_plan.rows; row_pin_i++) {
        const uint8_t pin_number = io_map_get_row_pin(row_pin_i);
        const uint8_t row_port_num = IO_MAP_GET_PIN_PORT(pin_number);
        const uint8_t row_pin_num = IO_MAP_GET_PIN_BIT(pin_number);
        const port_mask_t row_bit_mask = (1 << row_pin_num);

        if (io_map_claim_pins(row_port_num, row_bit_mask)) {
            // failed to claim
            register_error(ERROR_PIN_MAPPING_CONFLICT);
            return;
        }

        s_row_port_masks[row_port_num] |= row_bit_mask;
        s_row_pin_mask[row_pin_i] = row_bit_mask;
        s_row_ports[row_pin_i] = IO_MAP_GET_PORT(row_port_num);

        // Hardware setup for the pin
        switch (g_scan_plan.mode) {
            // When row is select we output `1`, otherwise disconnect it
            case MATRIX_SCANNER_MODE_ROW_COL: {
                s_row_drive = 1;
                nrf_gpio_cfg(
                    NRF_GPIO_PIN_MAP(row_port_num, row_pin_num),
                    NRF_GPIO_PIN_DIR_OUTPUT,
                    NRF_GPIO_PIN_INPUT_DISCONNECT,
                    NRF_GPIO_PIN_NOPULL,
                    NRF_GPIO_PIN_D0S1, // disconnect '0', Standard '1'
                    NRF_GPIO_PIN_NOSENSE
                );
            } break;

            // When row is select we output `0`, otherwise disconnect it
            case MATRIX_SCANNER_MODE_COL_ROW: {
                s_row_drive = 0;
                nrf_gpio_cfg(
                    NRF_GPIO_PIN_MAP(row_port_num, row_pin_num),
                    NRF_GPIO_PIN_DIR_OUTPUT,
                    NRF_GPIO_PIN_INPUT_DISCONNECT,
                    NRF_GPIO_PIN_NOPULL,
                    NRF_GPIO_PIN_S0D1, // Standard '0', disconnect '1'
                    NRF_GPIO_PIN_NOSENSE
                );
            } break;

            default: {
                register_error(ERROR_UNSUPPORTED_SCAN_MODE);
                return;
            } break;
        }
    }
}

void matrix_scanner_init(void) {
    if (init_matrix_scanner_utils()) {
        // return early on error
        return;
    }

    s_ports_per_row = INT_DIV_ROUND_UP(g_scan_plan.max_col_pin_num+1, IO_PORT_SIZE);
    s_bytes_per_row = INT_DIV_ROUND_UP(g_scan_plan.max_col_pin_num+1, 8);

    if (
        g_scan_plan.mode == MATRIX_SCANNER_MODE_COL_ROW ||
        g_scan_plan.mode == MATRIX_SCANNER_MODE_ROW_COL
    ) {
        setup_rows();
        unselect_all_rows();
    }
    setup_columns();

#if 0
    // set the rows and columns to their inital state.
    matrix_scan_irq_disable();
#endif
}

port_mask_t get_col_mask(uint8_t port_num) {
    return s_col_masks[port_num];
}

/// Selecting a row makes it outputs
static inline void select_row(uint8_t row) {
    if (s_row_drive == 0) {
        nrf_gpio_port_out_clear(s_row_ports[row], s_row_pin_mask[row]);
    } else {
        nrf_gpio_port_out_set(s_row_ports[row], s_row_pin_mask[row]);
    }
}

// unselecting a row disconnects it
static inline void unselect_row(uint8_t row) {
    if (s_row_drive == 0) {
        nrf_gpio_port_out_set(s_row_ports[row], s_row_pin_mask[row]);
    } else {
        nrf_gpio_port_out_clear(s_row_ports[row], s_row_pin_mask[row]);
    }
}

static inline void select_all_rows(void) {
    if (s_row_drive == 0) {
        nrf_gpio_port_out_clear(NRF_P0, s_row_port_masks[0]);
#if IO_PORT_COUNT > 1
        nrf_gpio_port_out_clear(NRF_P1, s_row_port_masks[1]);
#endif
    } else {
        nrf_gpio_port_out_set(NRF_P0, s_row_port_masks[0]);
#if IO_PORT_COUNT > 1
        nrf_gpio_port_out_set(NRF_P1, s_row_port_masks[1]);
#endif
    }
}

static inline void unselect_all_rows(void) {
    if (s_row_drive == 0) {
        nrf_gpio_port_out_set(NRF_P0, s_row_port_masks[0]);
#if IO_PORT_COUNT > 1
        nrf_gpio_port_out_set(NRF_P1, s_row_port_masks[1]);
#endif
    } else {
        nrf_gpio_port_out_clear(NRF_P0, s_row_port_masks[0]);
#if IO_PORT_COUNT > 1
        nrf_gpio_port_out_clear(NRF_P1, s_row_port_masks[1]);
#endif
    }
}

static inline bool scan_row(uint8_t row) {
    if (s_col_read_invert) {
        const port_mask_t new_row[IO_PORT_COUNT] = {
            ~nrf_gpio_port_in_read(NRF_P0) & s_col_masks[0],
#if IO_PORT_COUNT > 1
            ~nrf_gpio_port_in_read(NRF_P1) & s_col_masks[1],
#endif
        };
        return scanner_debounce_row(row, (uint8_t*)new_row, s_bytes_per_row);
    } else {
        const port_mask_t new_row[IO_PORT_COUNT] = {
            nrf_gpio_port_in_read(NRF_P0) & s_col_masks[0],
#if IO_PORT_COUNT > 1
            nrf_gpio_port_in_read(NRF_P1) & s_col_masks[1],
#endif
        };
        return scanner_debounce_row(row, (uint8_t*)new_row, s_bytes_per_row);
    }
}


static inline bool matrix_scan_row_col_mode(void) {
    uint8_t row;
    bool scan_changed = false;

    for (row = 0; row < g_scan_plan.rows; ++row) {
        select_row(row);

        if (get_matrix_num_keys_debouncing()) {
            // Debouncing
            nrf_delay_us(30);
        } else {
            // not debouncing
            // TODO:
            nrf_delay_us(30);
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
    }
    return false;
}

bool matrix_has_active_row(void) {
    return (
        (nrf_gpio_port_in_read(NRF_P0) & s_col_masks[0])
#if IO_PORT_COUNT > 1
        | (nrf_gpio_port_in_read(NRF_P1) & s_col_masks[1])
#endif
    );
}

void matrix_scan_irq_enable(void) {

}

void matrix_scan_irq_disable(void) {

}

bool matrix_scan_irq_has_triggered(void) {
    return false;
}

void matrix_scan_irq_clear(void) {

}


