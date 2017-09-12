// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/matrix_scanner.h"

#include "config.h"

#include <string.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <util/delay_basic.h>

#include "core/hardware.h"
#include "core/timer.h"

#include "xmega_hardware.h"

// TODO: make these settings configurable from the settings module

#ifndef DEBOUNCE_PRESS_TIME
#define DEBOUNCE_PRESS_TIME 5
#endif

#ifndef DEBOUNCE_RELEASE_TIME
#define DEBOUNCE_RELEASE_TIME (2*DEBOUNCE_TIME_PRESS)
#endif

#ifndef DEBOUNCE_RELEASE_TRIGGER_TIME
#if DEBOUNCE_RELEASE_TIME < 3
#define DEBOUNCE_RELEASE_TRIGGER_TIME DEBOUNCE_RELEASE_TIME
#else
#endif
#define DEBOUNCE_RELEASE_TRIGGER_TIME 3
#endif

#ifndef DEBOUNCE_PRESS_TRIGGER_TIME
#define DEBOUNCE_PRESS_TRIGGER_TIME 1
#endif

static bool has_scan_irq_triggered;

static uint8_t s_debounce_time[MAX_NUM_ROWS][MAX_NUM_COLS];
static uint8_t s_is_debouncing[MAX_NUM_ROWS][(MAX_NUM_COLS+7)/8];
static uint8_t s_debounce_type[MAX_NUM_ROWS][(MAX_NUM_COLS+7)/8];
static uint8_t s_matrix_number_keys_down;
static uint8_t s_matrix_number_keys_debouncing;

#if !USE_HARDWARE_SPECIFIC_SCAN

// col pin mapping:
// C0-C7: A0-A7
// C8-C11: B0-B4
// C12-C15: C0-C4
// MAX_NUM_COLS 16

// row pin mapping:
// R0-R5: D0-D5
// R6-R9: C3-C0
// MAX_NUM_ROWS 10
//
// NOTE: R6:C3 and R7:C2, overlap with the columns.

// coll settings
static uint8_t col_mask_a;
static uint8_t col_mask_b;
static uint8_t col_mask_c;

static uint8_t col_num_pins_a;
static uint8_t col_num_pins_b;
static uint8_t col_num_pins_c;

// row settings
static uint8_t row_mask_d;
static uint8_t row_mask_c;

static uint8_t row_num_pins_d;
static uint8_t row_num_pins_c;

static uint8_t bytes_per_row;

// Setup the columns
// As inputs with pull ups
static void setup_columns(void) {
    // Note: DIR: 0 -> input, 1 -> output

    // Note: PORTCFG.MPCMASK lets us configure multiple PINnCTRL regs at once
    // It is cleared automatically after any PINnCTRL register is written
    // Note: If MPCMASK=0, then it's feature is disabled, so writing to PIN0CTRL
    // would actually affect update PIN0CTRL instead of updating no pins.
    if (col_mask_a) {
        PORTA.DIRCLR = col_mask_a;
        PORTCFG.MPCMASK = col_mask_a;
        PORTA.PIN0CTRL = PORT_OPC_PULLUP_gc | PORT_ISC_BOTHEDGES_gc; // sense either edge for irq
        PORTA.OUTSET = col_mask_a;
        PORTA.INT0MASK |= col_mask_a;
    }

    if (col_mask_b) {
        PORTB.DIRCLR = col_mask_b;
        PORTCFG.MPCMASK = col_mask_b;
        PORTB.PIN0CTRL = PORT_OPC_PULLUP_gc | PORT_ISC_BOTHEDGES_gc;
        PORTB.OUTSET = col_mask_b;
        PORTB.INT0MASK |= col_mask_b;
    }

    if (col_mask_c) {
        PORTC.DIRCLR = col_mask_c;
        PORTCFG.MPCMASK = col_mask_c;
        PORTC.PIN0CTRL = PORT_OPC_PULLUP_gc | PORT_ISC_BOTHEDGES_gc;
        PORTC.OUTSET = col_mask_c;
        PORTC.INT0MASK |= col_mask_c;
    }
}

// rows are floating inputs
static void setup_rows(void) {
    // Note: DIR: 0 -> input, 1 -> output
    if (row_mask_d) {
        PORTD.DIRCLR = row_mask_d;
        PORTCFG.MPCMASK = row_mask_d;
        PORTD.PIN0CTRL = PORT_OPC_TOTEM_gc;
    }

    if (row_mask_c) {
        PORTC.DIRCLR = row_mask_c;
        PORTCFG.MPCMASK = row_mask_c;
        PORTC.PIN0CTRL = PORT_OPC_TOTEM_gc;
    }
}

//  makes all floating inputs
static inline void unselect_rows(void) {
    PORTD.DIRCLR = row_mask_d;
    PORTC.DIRCLR = row_mask_c;
}

// make all output low
static inline void select_all_rows(void) {
    PORTD.DIRSET = row_mask_d;
    PORTD.OUTCLR = row_mask_d;

    PORTC.DIRSET = row_mask_c;
    PORTC.OUTCLR = row_mask_c;
}


// make all output low
static inline void float_all_rows(void) {
    PORTD.DIRCLR = row_mask_d;
    PORTC.DIRCLR = row_mask_c;
}

bool matrix_has_active_row(void) {
    return (~PORTA.IN & col_mask_a) ||
        (~PORTB.IN & col_mask_b) ||
        (~PORTC.IN & col_mask_c);
}

// selecting a row makes it output 0
static inline void select_row(uint8_t row) {
    if (row < 6) { // row 0-5
        PORTD.DIRSET = (1 << row);
        PORTD.OUTCLR = (1 << row);
    } else if (row >= 6 && row < 10) { // row 6-9
        const uint8_t pin_num = 3-(row-6);
        PORTC.DIRSET = (1 << pin_num);
        PORTC.OUTCLR = (1 << pin_num);
    }
}

// NOTE:
// cols: A0-A7 -> Columns 0-7
// cols: B0-A3 -> Columns 8-11
// cols: C0-C3 -> Columns 12-15
// rows: D0-D5 -> Rows 0-5
// rows: C3-C0 -> Rows 6-9
void matrix_scanner_init(void) {
    int8_t cols = g_scan_plan.cols;
    int8_t rows = g_scan_plan.rows;

    if (cols + rows > 22 || cols > 16 || rows > 10) {
        // TODO: add error message
        cols = 0;
        rows = 0;
        g_scan_plan.rows = 0;
        g_scan_plan.cols = 0;
    }

    bytes_per_row = (g_scan_plan.cols+7)/8;

    col_num_pins_a = (cols < 8) ? cols : 8;
    col_num_pins_b = (cols < 12) ? MAX((int8_t)cols - 8, 0) : 4;
    col_num_pins_c = (cols < 16) ? MAX((int8_t)cols - 12, 0) : 4;

    col_mask_a = ~(0xff << col_num_pins_a);
    col_mask_b = ~(0xff << col_num_pins_b) & 0x0f;
    col_mask_c = ~(0xff << col_num_pins_c) & 0x0f;

    row_num_pins_d = (rows < 6) ? rows : 6;
    row_num_pins_c = (rows < 10) ? MAX((int8_t)rows - 6, 0) : 4;

    row_mask_d = ~(0xff << row_num_pins_d) & 0x3f;
    row_mask_c = ~(0x0f >> row_num_pins_c) & 0x0f; // R6,R7,R8,R9 <-> C3,C2,C1,C0

    memset(s_is_debouncing, 0, sizeof(s_is_debouncing));
    s_matrix_number_keys_down = 0;
    s_matrix_number_keys_debouncing = 0;

    // set the rows and columns to their inital state.
    matrix_scan_irq_disable();
    setup_columns();
    setup_rows();
    unselect_rows();

    init_matrix_scanner();
}

static void matrix_scan_irq_clear_flags(void) {
    PORTA.INTFLAGS |= PORT_INT0IF_bm; // clear the interrupt flags
    PORTB.INTFLAGS |= PORT_INT0IF_bm;
    PORTC.INTFLAGS |= PORT_INT0IF_bm;
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
    PORTA.INTCTRL = PORT_INT0LVL_LO_gc;
    PORTB.INTCTRL = PORT_INT0LVL_LO_gc;
    PORTC.INTCTRL = PORT_INT0LVL_LO_gc;
}

void matrix_scan_irq_disable(void) {
    PORTA.INTCTRL = PORT_INT0LVL_OFF_gc;
    PORTB.INTCTRL = PORT_INT0LVL_OFF_gc;
    PORTC.INTCTRL = PORT_INT0LVL_OFF_gc;
    unselect_rows();
}

static void matrix_scan_irq(void) {
    matrix_scan_irq_clear_flags();
    has_scan_irq_triggered = 1;
}

ISR(PORTA_INT0_vect) { matrix_scan_irq(); }
ISR(PORTB_INT0_vect) { matrix_scan_irq(); }
ISR(PORTC_INT0_vect) { matrix_scan_irq(); }

static inline uint8_t scan_row(uint8_t row) {
    uint8_t has_updated = 0;
    const uint8_t old_row[2] = {
        g_matrix[row][0],
        g_matrix[row][1]
    };

    const uint8_t new_row[2] = {
        ~PORTA.IN & col_mask_a,
        ((~PORTC.IN & col_mask_c) << 4) | (~PORTB.IN & col_mask_b),
    };

    const uint8_t cur_time = timer_read8_ms();

    for (uint8_t i = 0; i < bytes_per_row; ++i) {
        uint8_t changed_pins = old_row[i] ^ new_row[i];

        if (s_is_debouncing[row][i]==0 && !changed_pins) {
            // not debouncing and nothing changed, so nothing to do for this row
            continue;
        }

        uint8_t pin_mask = 0x01;
        uint8_t col = i*8;
        for ( ; pin_mask != 0 ; col++, pin_mask<<=1 ) {
            if (s_is_debouncing[row][i] & pin_mask) {
                // debouncing
                if (s_debounce_type[row][i] & pin_mask) {
                    // debouncing key press
                    const uint8_t bounce_duration = (uint8_t)(cur_time - s_debounce_time[row][col]);
                    if (!(old_row[i] & pin_mask)) {
                        // key press not registered yet
                        if (bounce_duration >= DEBOUNCE_PRESS_TRIGGER_TIME) {
                            if (new_row[i] & pin_mask) {
                                // if still down after DEBOUNCE_PRESS_TRIGGER_TIME
                                // register the key press
                                g_matrix[row][i] |= pin_mask;
                                s_matrix_number_keys_down++;
                                scanner_add_matrix_key(row, col);
                                has_updated = 1;
                            } else {
                                // reject key press and reset debouncing state
                                s_is_debouncing[row][i] &= ~pin_mask;
                                s_matrix_number_keys_debouncing--;
                            }
                        }
                    } else {
                        // key press has already been registered, wait until the
                        // debounce time is over
                        if ( bounce_duration >= DEBOUNCE_PRESS_TIME) {
                            // debounce time is now over
                            s_is_debouncing[row][i] &= ~pin_mask;
                            s_matrix_number_keys_debouncing--;
                        }
                    }
                } else {
                    // debouncing key release
                    if (new_row[i] & pin_mask) {
                        // key bounced back to the down state, reset timer
                        s_debounce_time[row][col] = cur_time;
                    } else {
                        // key in up state
                        const uint8_t bounce_duration = (uint8_t)(cur_time - s_debounce_time[row][col]);

                        // if we have triggered the key release
                        if ((old_row[i] & pin_mask) && bounce_duration >= DEBOUNCE_RELEASE_TRIGGER_TIME) {
                            // key has been in the up state for DEBOUNCE_RELEASE_TRIGGER_TIME,
                            // accept that the key has actual been release now
                            g_matrix[row][i] &= ~pin_mask;
                            s_matrix_number_keys_down--;
                            scanner_del_matrix_key(row, col);
                            has_updated = 1;
                        } else if (bounce_duration >= DEBOUNCE_RELEASE_TIME ) {
                            // debounce over
                            s_is_debouncing[row][i] &= ~pin_mask;
                            s_matrix_number_keys_debouncing--;
                        }
                    }
                }
            } else {
                // not debouncing

                if (!(changed_pins & pin_mask)) {
                    // ignore pins that haven't changed
                    continue;
                }

                // If the key press/release trigger time is 0, then that means
                // we should trigger the key immediately after seeing that it
                // has changed state.
                bool is_key_down = new_row[i] & pin_mask;
                if (DEBOUNCE_PRESS_TRIGGER_TIME == 0 && is_key_down) {
                    // debounce press trigger time is 0, so register he key press
                    // immediately. The debouncing algorithm then waits until
                    // DEBOUNCE_PRESS_TIME has elapsed before accepting any more
                    // changes in key state.
                    // state.
                    g_matrix[row][i] |= pin_mask;
                    s_matrix_number_keys_down++;
                    scanner_add_matrix_key(row, col);
                    has_updated = 1;
                } else if (DEBOUNCE_RELEASE_TRIGGER_TIME == 0 && !is_key_down) {
                    // debounce release trigger time is 0, so register the key press
                    // immediately. The debouncing algorithm then waits until
                    // DEBOUNCE_RELEASE_TIME has elapsed before accepting any
                    // more changes in key state.
                    g_matrix[row][i] &= ~pin_mask;
                    s_matrix_number_keys_down--;
                    scanner_del_matrix_key(row, col);
                    has_updated = 1;
                }

                // this pin has changed, and we are not debouncing, so update it
                if (is_key_down) {
                    s_debounce_type[row][i] |= pin_mask; // indicates key press debounce

                } else {
                    s_debounce_type[row][i] &= ~pin_mask; // indicates key release debounce
                }

                s_is_debouncing[row][i] |= pin_mask;
                s_debounce_time[row][col] = cur_time;
                s_matrix_number_keys_debouncing++;
            }
        }
    }

    return has_updated;
}

// TODO: should inline these calls
uint8_t get_matrix_num_keys_down(void) {
    return s_matrix_number_keys_down;
}

uint8_t get_matrix_num_keys_debouncing(void) {
    return s_matrix_number_keys_debouncing;
}

static inline bool matrix_scan_row_col_mode(void) {
    uint8_t row;
    bool scan_changed = false;
    /* static uint8_t last_scan_time; */

    /* if (last_scan_time == timer_read8_half_ms()) { */
    /*  scan_changed = false; */
    /*  return scan_changed; */
    /* } */

    /* last_scan_time = timer_read8_half_ms(); */

    unselect_rows();
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
        static_delay_variable_clock_us(2);

        scan_changed |= scan_row(row);
        unselect_rows();
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
    // values are used
    return false;
}

/* void matrix_scan_mode(uint8_t mode) { */
/*  if (mode == SCAN_MODE_NORMAL) { */
/*      /1* setup_columns(); *1/ */
/*  } else if (mode == SCAN_MODE_INTERRUPT) { */
/*  } */
/* } */

#endif

/*********************************************************************
 *           Hardware specific implementation for scanner            *
 *********************************************************************/

// 2 key
// TODO: improve the build system for building for different hardware
#if USE_HARDWARE_SPECIFIC_SCAN

static uint8_t bytes_per_row;

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

    bytes_per_row = 1;
}

#include "core/usb_commands.h"

// scan the whole matrix
bool matrix_scan(void) {
    bool key0 = (~PORTA.IN & PIN3_bm);
    bool key1 = (~PORTD.IN & PIN2_bm);
    uint8_t new_row_data = (key0 << 0) | (key1 << 1);

    uint8_t has_updated = 0;

    uint8_t row = 0;

    const uint8_t old_row[2] = {
        g_matrix[row][0],
        0,
    };

    const uint8_t new_row[2] = {
        new_row_data,
        0,
    };

    const uint8_t cur_time = timer_read8_ms();

    usb_print((uint8_t*)&new_row_data, 1);

    for (uint8_t i = 0; i < bytes_per_row; ++i) {
        uint8_t changed_pins = old_row[i] ^ new_row[i];

        if (s_is_debouncing[row][i]==0 && !changed_pins) {
            // not debouncing and nothing changed, so nothing to do for this row
            continue;
        }

        uint8_t pin_mask = 0x01;
        uint8_t col = i*8;
        for ( ; pin_mask != 0 ; col++, pin_mask<<=1 ) {
            if (s_is_debouncing[row][i] & pin_mask) {
                // debouncing
                if (s_debounce_type[row][i] & pin_mask) {
                    // debouncing key press
                    const uint8_t bounce_duration = (uint8_t)(cur_time - s_debounce_time[row][col]);
                    if (!(old_row[i] & pin_mask)) {
                        // key press not registered yet
                        if (bounce_duration >= DEBOUNCE_PRESS_TRIGGER_TIME) {
                            if (new_row[i] & pin_mask) {
                                // if still down after DEBOUNCE_PRESS_TRIGGER_TIME
                                // register the key press
                                g_matrix[row][i] |= pin_mask;
                                s_matrix_number_keys_down++;
                                scanner_add_matrix_key(row, col);
                                has_updated = 1;
                            } else {
                                // reject key press and reset debouncing state
                                s_is_debouncing[row][i] &= ~pin_mask;
                                s_matrix_number_keys_debouncing--;
                            }
                        }
                    } else {
                        // key press has already been registered, wait until the
                        // debounce time is over
                        if ( bounce_duration >= DEBOUNCE_PRESS_TIME) {
                            // debounce time is now over
                            s_is_debouncing[row][i] &= ~pin_mask;
                            s_matrix_number_keys_debouncing--;
                        }
                    }
                } else {
                    // debouncing key release
                    if (new_row[i] & pin_mask) {
                        // key bounced back to the down state, reset timer
                        s_debounce_time[row][col] = cur_time;
                    } else {
                        // key in up state
                        const uint8_t bounce_duration = (uint8_t)(cur_time - s_debounce_time[row][col]);

                        // if we have triggered the key release
                        if ((old_row[i] & pin_mask) && bounce_duration >= DEBOUNCE_RELEASE_TRIGGER_TIME) {
                            // key has been in the up state for DEBOUNCE_RELEASE_TRIGGER_TIME,
                            // accept that the key has actual been release now
                            g_matrix[row][i] &= ~pin_mask;
                            s_matrix_number_keys_down--;
                            scanner_del_matrix_key(row, col);
                            has_updated = 1;
                        } else if (bounce_duration >= DEBOUNCE_RELEASE_TIME ) {
                            // debounce over
                            s_is_debouncing[row][i] &= ~pin_mask;
                            s_matrix_number_keys_debouncing--;
                        }
                    }
                }
            } else {
                // not debouncing

                if (!(changed_pins & pin_mask)) {
                    // ignore pins that haven't changed
                    continue;
                }

                // If the key press/release trigger time is 0, then that means
                // we should trigger the key immediately after seeing that it
                // has changed state.
                bool is_key_down = new_row[i] & pin_mask;
                if (DEBOUNCE_PRESS_TRIGGER_TIME == 0 && is_key_down) {
                    // debounce press trigger time is 0, so register he key press
                    // immediately. The debouncing algorithm then waits until
                    // DEBOUNCE_PRESS_TIME has elapsed before accepting any more
                    // changes in key state.
                    // state.
                    g_matrix[row][i] |= pin_mask;
                    s_matrix_number_keys_down++;
                    scanner_add_matrix_key(row, col);
                    has_updated = 1;
                } else if (DEBOUNCE_RELEASE_TRIGGER_TIME == 0 && !is_key_down) {
                    // debounce release trigger time is 0, so register the key press
                    // immediately. The debouncing algorithm then waits until
                    // DEBOUNCE_RELEASE_TIME has elapsed before accepting any
                    // more changes in key state.
                    g_matrix[row][i] &= ~pin_mask;
                    s_matrix_number_keys_down--;
                    scanner_del_matrix_key(row, col);
                    has_updated = 1;
                }

                // this pin has changed, and we are not debouncing, so update it
                if (is_key_down) {
                    s_debounce_type[row][i] |= pin_mask; // indicates key press debounce

                } else {
                    s_debounce_type[row][i] &= ~pin_mask; // indicates key release debounce
                }

                s_is_debouncing[row][i] |= pin_mask;
                s_debounce_time[row][col] = cur_time;
                s_matrix_number_keys_debouncing++;
            }
        }
    }

    return has_updated;
}

uint8_t get_matrix_num_keys_down(void) {
    return s_matrix_number_keys_down;
}

uint8_t get_matrix_num_keys_debouncing(void) {
    return s_matrix_number_keys_debouncing;
}

#endif
