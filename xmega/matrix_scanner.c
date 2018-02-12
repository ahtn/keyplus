// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/matrix_scanner.h"

#include "config.h"

#include <string.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <util/delay_basic.h>

#include "core/error.h"
#include "core/hardware.h"
#include "core/io_map.h"
#include "core/timer.h"

#include "core/usb_commands.h"

#include "xmega_hardware.h"

// TODO: make these settings configurable from the settings module

static bool has_scan_irq_triggered;

#if F_CPU == 48000000UL
#define PARASITIC_DISCHARGE_DELAY_FAST_CLOCK(x) do {\
    _delay_loop_1(x); \
    _delay_loop_1(x); \
    _delay_loop_1(x); \
} while(0)
#elif F_CPU == 32000000UL
#define PARASITIC_DISCHARGE_DELAY_FAST_CLOCK(x) do {\
    _delay_loop_1(x); \
    _delay_loop_1(x); \
} while(0)
#elif F_CPU == 16000000UL
#define PARASITIC_DISCHARGE_DELAY_FAST_CLOCK(x) do {\
    _delay_loop_1(x); \
} while(0)
#else
#error "Unsupported clock speed for PARASITIC_DISCHARGE_DELAY"
#endif

#define PARASITIC_DISCHARGE_DELAY_SLOW_CLOCK(x) do {\
    _delay_loop_1(x); \
} while(0)


#if !USE_HARDWARE_SPECIFIC_SCAN

static uint8_t s_col_masks[IO_PORT_COUNT];

static uint8_t s_row_port_masks[IO_PORT_COUNT];
static uint8_t s_row_pin_mask[MAX_NUM_ROWS];
static io_port_t *s_row_ports[MAX_NUM_ROWS];

static uint8_t s_bytes_per_row;

static uint8_t s_parasitic_discharge_delay_idle;
static uint8_t s_parasitic_discharge_delay_debouncing;

// Setup the columns as inputs with pull ups
static void setup_columns(void) {
    // Note: DIR: 0 -> input, 1 -> output

    // Note: PORTCFG.MPCMASK lets us configure multiple PINnCTRL regs at once
    // It is cleared automatically after any PINnCTRL register is written
    // Note: If MPCMASK=0, then its function is disabled, so writing to PIN0CTRL
    // would actually affect update PIN0CTRL instead of updating no pins.
    const uint8_t max_col_num = g_scan_plan.max_col;
    const uint8_t max_port_num = (max_col_num + (IO_PORT_SIZE-1)) / IO_PORT_SIZE;
    uint8_t port_ii;
    for (port_ii = 0; port_ii < max_port_num; ++port_ii) {
        io_port_t *port = IO_MAP_GET_PORT(port_ii);
        uint8_t col_mask = io_map_get_col_port_mask(port_ii);

        // Nothing is set in this col
        if (col_mask == 0) {
            continue;
        }

        // Try to claim the pins
        if (io_map_claim_pins(port_ii, col_mask)) {
            return; // return on error
        }

        s_col_masks[port_ii] = col_mask;

        // Hardware setup for the pin
        //
        // Initialize the pins, as inputs with pull-up resistors and
        // enable the interrupts on both rising/falling edges
        {
            port->DIRCLR = col_mask;
            PORTCFG.MPCMASK = col_mask;
            port->PIN0CTRL = PORT_OPC_PULLUP_gc | PORT_ISC_BOTHEDGES_gc;
            port->INT0MASK |= col_mask;
        }
    }
}

/// Setup rows for matrix scaning
///
/// Rows will use the Wired-AND pin configuration in output mode. When an
/// output pin is in Wired-AND mode, writting 1 to the pin disconnects it and
/// writting 0 to the pin connects it to GND.
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
            // failed to claim
            return;
        }

        s_row_port_masks[row_port_num] |= row_bit_mask;
        s_row_pin_mask[row_pin_i] = row_bit_mask;
        s_row_ports[row_pin_i] = port;

        // Hardware setup for the pin
        {
            port->DIRSET = row_bit_mask; // output
            PORTCFG.MPCMASK = row_bit_mask;
            port->PIN0CTRL = PORT_OPC_WIREDAND_gc;
            port->OUTSET = row_bit_mask;
        }
    }

}

//  makes all rows floating inputs
static inline void unselect_all_rows(void) {
    PORTA.OUTSET = s_row_port_masks[PORT_A_NUM];
    PORTB.OUTSET = s_row_port_masks[PORT_B_NUM];
    PORTC.OUTSET = s_row_port_masks[PORT_C_NUM];
    PORTD.OUTSET = s_row_port_masks[PORT_D_NUM];
    PORTE.OUTSET = s_row_port_masks[PORT_E_NUM];
    PORTR.OUTSET = s_row_port_masks[PORT_R_NUM];
}

// make all rows output low
static inline void select_all_rows(void) {
    PORTA.OUTCLR = s_row_port_masks[PORT_A_NUM];
    PORTB.OUTCLR = s_row_port_masks[PORT_B_NUM];
    PORTC.OUTCLR = s_row_port_masks[PORT_C_NUM];
    PORTD.OUTCLR = s_row_port_masks[PORT_D_NUM];
    PORTE.OUTCLR = s_row_port_masks[PORT_E_NUM];
    PORTR.OUTCLR = s_row_port_masks[PORT_R_NUM];
}

bool matrix_has_active_row(void) {
    return (~PORTA.IN & s_row_port_masks[PORT_A_NUM]) ||
           (~PORTB.IN & s_row_port_masks[PORT_B_NUM]) ||
           (~PORTC.IN & s_row_port_masks[PORT_C_NUM]) ||
           (~PORTD.IN & s_row_port_masks[PORT_D_NUM]) ||
           (~PORTE.IN & s_row_port_masks[PORT_E_NUM]) ||
           (~PORTR.IN & s_row_port_masks[PORT_R_NUM]);
}

// selecting a row makes it output 0
static inline void select_row(uint8_t row) {
    io_port_t *port = s_row_ports[row];
    const uint8_t mask = s_row_pin_mask[row];
    port->OUTCLR = mask;
}

// unselecting a row disconnects it
static inline void unselect_row(uint8_t row) {
    io_port_t *const port = s_row_ports[row];
    const uint8_t mask = s_row_pin_mask[row];
    port->OUTSET = mask;
}

void matrix_scanner_init(void) {
#if 1
    g_scan_plan.mode = MATRIX_SCANNER_MODE_COL_ROW;
    g_scan_plan.cols = 6;
    g_scan_plan.rows = 4;
    g_scan_plan.debounce_time_press = 5;
    g_scan_plan.debounce_time_release = 5;
    g_scan_plan.trigger_time_press = 3;
    g_scan_plan.trigger_time_release = 3;
    g_scan_plan.parasitic_discharge_delay_idle = 20;
    g_scan_plan.parasitic_discharge_delay_debouncing = 40;
    g_scan_plan.max_col = 6;
    g_scan_plan.max_key_num = 24;
#endif

    int8_t cols = g_scan_plan.cols;
    int8_t rows = g_scan_plan.rows;

    if (
        cols > MAX_NUM_COLS ||
        rows > MAX_NUM_ROWS ||
        g_scan_plan.max_col > MAX_NUM_COLS
    ) {
        memset((uint8_t*)&g_scan_plan, 0, sizeof(matrix_scan_plan_t));
        register_error(ERROR_MATRIX_PINS_CONFIG_TOO_LARGE);
        return;
    }

    s_bytes_per_row = (g_scan_plan.max_col+7)/8;

    setup_rows();
    setup_columns();

    scanner_init_debouncer();

    // set the rows and columns to their inital state.
    matrix_scan_irq_disable();
    unselect_all_rows();

    init_matrix_scanner_utils();

    // Configure the parasitic discharge delay based on how fast the mcu clock
    // is running
    if (g_slow_clock_mode) {
        const uint8_t base_factor = (16000000/1000000);
        const uint8_t slow_factor = (CLOCK_SPEED_SLOW/1000000);
        s_parasitic_discharge_delay_idle =
            (((uint16_t)g_scan_plan.parasitic_discharge_delay_idle * slow_factor) / base_factor);
        s_parasitic_discharge_delay_debouncing =
            (((uint16_t)g_scan_plan.parasitic_discharge_delay_debouncing * slow_factor) /base_factor);
    } else {
        s_parasitic_discharge_delay_idle = g_scan_plan.parasitic_discharge_delay_idle;
        s_parasitic_discharge_delay_debouncing = g_scan_plan.parasitic_discharge_delay_debouncing;
    }
}

static void matrix_scan_irq_clear_flags(void) {
    PORTA.INTFLAGS |= PORT_INT0IF_bm; // clear the interrupt flags
    PORTB.INTFLAGS |= PORT_INT0IF_bm;
    PORTC.INTFLAGS |= PORT_INT0IF_bm;
    PORTD.INTFLAGS |= PORT_INT0IF_bm;
    PORTE.INTFLAGS |= PORT_INT0IF_bm;
    PORTR.INTFLAGS |= PORT_INT0IF_bm;
}

bool matrix_scan_irq_has_triggered(void) {
    return has_scan_irq_triggered;
}

// Pins are set like this while scanner is initialized:
// columns: input pull-up
// rows: output-low
// This fuction, then enables intterupts on the
// So when any key is pressed, the columns will be driven low. We use this
// to generate interrupts on the column pins that will be triggered when
// any key is pressed.
void matrix_scan_irq_enable(void) {
    select_all_rows();
    static_delay_variable_clock_us(2); // TODO: check if more error margin is needed
    matrix_scan_irq_clear_flags();
    has_scan_irq_triggered = 0;
    PORTA.INTCTRL = (PORTA.INTCTRL & ~PORT_INT0LVL_gm) | PORT_INT0LVL_LO_gc;
    PORTB.INTCTRL = (PORTB.INTCTRL & ~PORT_INT0LVL_gm) | PORT_INT0LVL_LO_gc;
    PORTC.INTCTRL = (PORTC.INTCTRL & ~PORT_INT0LVL_gm) | PORT_INT0LVL_LO_gc;
    PORTD.INTCTRL = (PORTD.INTCTRL & ~PORT_INT0LVL_gm) | PORT_INT0LVL_LO_gc;
    PORTE.INTCTRL = (PORTE.INTCTRL & ~PORT_INT0LVL_gm) | PORT_INT0LVL_LO_gc;
    PORTR.INTCTRL = (PORTR.INTCTRL & ~PORT_INT0LVL_gm) | PORT_INT0LVL_LO_gc;
}

void matrix_scan_irq_disable(void) {
    PORTA.INTCTRL = (PORTA.INTCTRL & ~PORT_INT0LVL_gm) | PORT_INT0LVL_OFF_gc;
    PORTB.INTCTRL = (PORTB.INTCTRL & ~PORT_INT0LVL_gm) | PORT_INT0LVL_OFF_gc;
    PORTC.INTCTRL = (PORTC.INTCTRL & ~PORT_INT0LVL_gm) | PORT_INT0LVL_OFF_gc;
    PORTD.INTCTRL = (PORTD.INTCTRL & ~PORT_INT0LVL_gm) | PORT_INT0LVL_OFF_gc;
    PORTE.INTCTRL = (PORTE.INTCTRL & ~PORT_INT0LVL_gm) | PORT_INT0LVL_OFF_gc;
    PORTR.INTCTRL = (PORTR.INTCTRL & ~PORT_INT0LVL_gm) | PORT_INT0LVL_OFF_gc;
    unselect_all_rows();
}

static void matrix_scan_irq(void) {
    matrix_scan_irq_clear_flags();
    has_scan_irq_triggered = 1;
}

ISR(PORTA_INT0_vect) { matrix_scan_irq(); }
ISR(PORTB_INT0_vect) { matrix_scan_irq(); }
ISR(PORTC_INT0_vect) { matrix_scan_irq(); }
ISR(PORTD_INT0_vect) { matrix_scan_irq(); }
ISR(PORTE_INT0_vect) { matrix_scan_irq(); }
ISR(PORTR_INT0_vect) { matrix_scan_irq(); }

static inline uint8_t scan_row(uint8_t row) {
    const uint8_t old_row[IO_PORT_COUNT] = {
        g_matrix[row][PORT_A_NUM],
        g_matrix[row][PORT_B_NUM],
        g_matrix[row][PORT_C_NUM],
        g_matrix[row][PORT_D_NUM],
        g_matrix[row][PORT_E_NUM],
        g_matrix[row][PORT_R_NUM],
    };

    const uint8_t new_row[IO_PORT_COUNT] = {
        ~PORTA.IN & s_col_masks[PORT_A_NUM],
        ~PORTB.IN & s_col_masks[PORT_B_NUM],
        ~PORTC.IN & s_col_masks[PORT_C_NUM],
        ~PORTD.IN & s_col_masks[PORT_D_NUM],
        ~PORTE.IN & s_col_masks[PORT_E_NUM],
        ~PORTR.IN & s_col_masks[PORT_R_NUM],
    };

    // usb_print(s_col_masks, 10);
    // usb_print(s_row_masks, 10);
    // usb_print(s_row_pin_mask, 10);
    // if (row == 2) {
    //     usb_print(new_row, 10);
    // }

    return scanner_debounce_row(row, old_row, new_row, s_bytes_per_row);
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
            if (g_slow_clock_mode) {
                PARASITIC_DISCHARGE_DELAY_SLOW_CLOCK(
                    s_parasitic_discharge_delay_debouncing
                );
            } else {
                PARASITIC_DISCHARGE_DELAY_FAST_CLOCK(
                    s_parasitic_discharge_delay_debouncing
                );
            }
        } else {
            // not debouncing
            if (g_slow_clock_mode) {
                PARASITIC_DISCHARGE_DELAY_SLOW_CLOCK(
                    s_parasitic_discharge_delay_idle
                );
            } else {
                PARASITIC_DISCHARGE_DELAY_FAST_CLOCK(
                    s_parasitic_discharge_delay_idle
                );
            }
        }

        scan_changed |= scan_row(row);
        unselect_row(row);
    }

    return scan_changed;
}

static inline bool matrix_scan_pin_mode(void) {
    bool scan_changed = false;

    return scan_changed;
}

bool matrix_scan(void) {
    if (g_scan_plan.mode == MATRIX_SCANNER_MODE_COL_ROW) {
        return matrix_scan_row_col_mode();
    } else if (g_scan_plan.mode == MATRIX_SCANNER_MODE_PINS) {
        return matrix_scan_pin_mode();
    }


    // TODO: add an error event that can be sent over USB for when invalid
    // values are used for scan settings etc.
    return false;
}

#endif

/*********************************************************************
 *           Hardware specific implementation for scanner            *
 *********************************************************************/

// 2 key
// TODO: improve the build system for building for different hardware
#if 0
// #if USE_HARDWARE_SPECIFIC_SCAN

static uint8_t s_bytes_per_row;

// setup the matrix for scanning
void matrix_scanner_init(void) {
    // A3 and D2 are the pins used for the two switches
    PORTA.DIRSET |= PIN3_bm;
    PORTCFG.MPCMASK = PIN3_bm;
    PORTA.PIN0CTRL = PORT_OPC_PULLUP_gc;
    PORTA.OUTSET = PIN3_bm;

    PORTD.DIRSET |= PIN2_bm;
    PORTCFG.MPCMASK = PIN2_bm;
    PORTD.PIN0CTRL = PORT_OPC_PULLUP_gc;
    PORTD.OUTSET = PIN2_bm;

    s_bytes_per_row = 1;
}

#include "core/usb_commands.h"

// scan the whole matrix
bool matrix_scan(void) {
    bool key0 = (~PORTA.IN & PIN3_bm);
    bool key1 = (~PORTD.IN & PIN2_bm);
    uint8_t new_row_data = (key0 << 0) | (key1 << 1);

    const uint8_t row = 0;

    const uint8_t old_row[1] = {
        g_matrix[row][0],
    };

    const uint8_t new_row[1] = {
        new_row_data,
    };

    return scanner_debounce_row(row, old_row, new_row, 1);
}

uint8_t get_matrix_num_keys_down(void) {
    return s_matrix_number_keys_down;
}

uint8_t get_matrix_num_keys_debouncing(void) {
    return s_matrix_number_keys_debouncing;
}

#endif
