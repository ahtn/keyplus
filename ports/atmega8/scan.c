// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <string.h>

#include "core/matrix_scanner.h"

#include "scan.h"
#include "clock.h"

#if USE_HARDWARE_SPECIFIC_SCAN
typedef uint8_t matrix_row_t;

static matrix_row_t matrix_debouncing[ROWS_PER_HAND];

static matrix_row_t read_cols(void);
static void init_cols(void);
static void unselect_rows(void);
static void select_row(uint8_t row);

static uint8_t s_num_keys_down;

const uint8_t col_pin_mask = 0b00111111;
const uint8_t row_pin_mask = 0b00001111;

void matrix_init(void) {
    // initialize row and col
    unselect_rows();
    init_cols();

    // initialize matrix state: all keys off
    for (uint8_t i=0; i < ROWS_PER_HAND; i++) {
        g_matrix[i][0] = 0;
        matrix_debouncing[i] = 0;
    }

    s_num_keys_down = 0;

    init_matrix_scanner();
}

// TODO: currently only != 0 when keys are down
uint8_t get_matrix_num_keys_down(void) {
    return s_num_keys_down;
}

/* void get_matrix_data(uint8_t *dest) { */
/*  uint8_t offset = (DEVICE_ID % 4) * ROWS_PER_HAND; */
/*  memcpy(dest, g_matrix+offset, ROWS_PER_HAND); */
/* } */

/* // NOTE: the debouncing time of this scaning method is controlled by */
/* // that rate at which this function is called. */
/* bool matrix_scan_slow(void) { */
/*  matrix_row_t cols; */
/*  bool changed = 0; */
/*  s_num_keys_down = 0; */

/*  for (uint8_t i = 0; i < ROWS_PER_HAND; i++) { */
/*      select_row(i); */
/*      asm volatile("nop"); */
/*      const uint8_t old_row_val = g_matrix[i][0]; */

/*      cols = read_cols(); */
/*      g_matrix[i][0] = matrix_debouncing[i] & cols; */
/*      changed |= (old_row_val != g_matrix[i][0]); */
/*      s_num_keys_down |= g_matrix[i][0]; */
/*      matrix_debouncing[i] = cols; */
/*      unselect_rows(); */
/*  } */
/*  return changed; */
/* } */

bool matrix_scan_slow(void) {
    matrix_row_t cols;
    uint8_t changed = 0;
    uint8_t changed_keys = 0;

    for (uint8_t row = 0; row < ROWS_PER_HAND; row++) {
        select_row(row);
        /* clock_delay_slow_us(30);  // without this wait read unstable value. */
        asm volatile("nop");
        const uint8_t old_row_val = g_matrix[row][0]; // instead of delay

        cols = read_cols();
        g_matrix[row][0] = matrix_debouncing[row] & cols;

        changed_keys = old_row_val ^ g_matrix[row][0];
        if (changed_keys) {
            // changed |= (changed_keys);
            // if (changed_keys) {
            //     scanner_add_matrix_key(2, 2);
            // } else {
            //     scanner_del_matrix_key(2, 2);
            // }

            changed |= (changed_keys);
            uint8_t mask = 0x01;
            uint8_t col = 0;
            while (mask) {
                if (changed_keys & mask) {
                    if (g_matrix[row][0] & mask) {
                        scanner_add_matrix_key(row, col);
                        s_num_keys_down++;
                    } else {
                        scanner_del_matrix_key(row, col);
                        s_num_keys_down--;
                    }
                }
                mask = mask << 1;
                col++;
            }
        }

        matrix_debouncing[row] = cols;
        unselect_rows();
    }
    return changed;
}

matrix_row_t matrix_get_row(uint8_t row) {
    return g_matrix[row][0];
}

uint8_t matrix_get_size(void) {
    return ROWS_PER_HAND;
}

/* uint8_t get_matrix_data_size(void) { */
/*  return MATRIX_ROWS; */
/* } */

/* uint8_t matrix_get_data(uint8_t i) { */
/*  return g_matrix[i][0]; */
/* } */

// Setup the matrix so it will trigger an interrupt when a pin changes
void matrix_interrupt_mode(void) {
#if DEVICE_ID==4 || DEVICE_ID==2 || DEVICE_ID==8 || DEVICE_ID==9
    // cols input, pull-up
    DDRC  &= ~col_pin_mask;
    PORTC |= col_pin_mask;

    // rows output, low
    DDRD  |=  row_pin_mask;
    PORTD &= ~row_pin_mask;

    // cols interrupt, on pin change
    PCICR  =  (1<<PCIE1);
    PCMSK1 = col_pin_mask;
    PCIFR  = 0x00;
#elif DEVICE_ID==5
    // cols input, pull-up
    DDRC  &= ~col_pin_mask;
    PORTC |= col_pin_mask;

    // rows output, low
    DDRD  |=  row_pin_mask;
    PORTD &= ~row_pin_mask;

    // cols interrupt, on pin change
    PCICR  =  (1<<PCIE1);
    PCMSK1 = col_pin_mask;
    PCIFR  = 0x00;
#endif
}

ISR(PCINT0_vect) {
    PCICR  = 0;
    PCMSK0 = 0;
    PCIFR  = 0;
}
ISR(PCINT1_vect) {
    PCICR  = 0;
    PCMSK1 = 0;
    PCIFR  = 0;
}
ISR(PCINT2_vect) {
    PCICR  = 0;
    PCMSK2 = 0;
    PCIFR  = 0;
}

/* TODO: update with *real* values */
/* Column pin configuration
 * left
 *   col: 0   1   2   3   4   5
 *   pin: C0  C1  C2  C3  C4  C5
 * right
 *   col: 0   1   2   3   4   5
 *   pin: C0  C1  C2  C3  C4  C5
 */
inline static void  init_cols(void) {
    // Input with pull-up(DDR:0, PORT:1)
#if DEVICE_ID==4 || DEVICE_ID==2 || DEVICE_ID==8 || DEVICE_ID==9
    DDRC  &= ~(col_pin_mask);
    PORTC |=  (col_pin_mask);
#elif DEVICE_ID==5
    DDRC  &= ~(col_pin_mask);
    PORTC |=  (col_pin_mask);
#endif
}

inline static matrix_row_t read_cols(void) {
#if DEVICE_ID==4 || DEVICE_ID==2 || DEVICE_ID==8 || DEVICE_ID==9
    return ~PINC & col_pin_mask;
#elif DEVICE_ID==5
    return ~PINC & col_pin_mask;
#endif
}

/* Row pin configuration
 * left
 *   row: 0  1  2  3
 *   pin: D0 D1 D2 D3
 * right:
 *   row: 0  1  2  3
 *   pin: D0 D1 D2 D3
 */
inline static void unselect_rows(void) {
    // Hi-Z(DDR:0, PORT:0) to unselect
#if DEVICE_ID==4 || DEVICE_ID==2 || DEVICE_ID==8 || DEVICE_ID==9
    DDRD  &= ~row_pin_mask;
    PORTD &= ~row_pin_mask;
#elif DEVICE_ID==5
    DDRD  &= ~row_pin_mask;
    PORTD &= ~row_pin_mask;
#endif
}

inline static void select_row(uint8_t row) {
    // Output low(DDR:1, PORT:0) to select
#if DEVICE_ID==4 || DEVICE_ID==2 || DEVICE_ID==8 || DEVICE_ID==9
    DDRD  |= (1<<row);
    PORTD &= ~(1<<row);
#elif DEVICE_ID==5
    DDRD  |= (1<<(3-row));
    PORTD &= ~(1<<(3-row));
#endif
}
#endif
