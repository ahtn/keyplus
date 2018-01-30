// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "config.h"

#include "core/matrix_scanner.h"

#include <string.h>

#include "core/layout.h"
#include "core/packet.h"
#include "core/settings.h"
#include "core/timer.h"

#define MAX_UPDATE_LIST 16
#define MAX_DOWN_LIST 16

// can probably make this static
XRAM uint8_t g_matrix[MAX_NUM_ROWS][(MAX_NUM_COLS+7)/8];

static uint8_t s_debounce_time[MAX_NUM_ROWS][MAX_NUM_COLS];
static uint8_t s_is_debouncing[MAX_NUM_ROWS][(MAX_NUM_COLS+7)/8];
static uint8_t s_debounce_type[MAX_NUM_ROWS][(MAX_NUM_COLS+7)/8];
static uint8_t s_matrix_number_keys_down;
static uint8_t s_matrix_number_keys_debouncing;

XRAM matrix_scan_plan_t g_scan_plan;

XRAM uint8_t g_delta_list[MAX_UPDATE_LIST];
XRAM uint8_t g_delta_list_len;

XRAM uint8_t g_down_list[MAX_DOWN_LIST];
XRAM uint8_t g_down_list_len;

#define KEY_NUMBER_BITMAP_SIZE (MAX_NUM_KEYS/8)
XRAM uint8_t g_key_num_bitmap[KEY_NUMBER_BITMAP_SIZE];

// TODO: probably change this
uint8_t get_matrix_compressed_size(void) {
    return (g_scan_plan.rows*g_scan_plan.cols + 7)/8;
}

static inline uint8_t get_key_number(uint8_t row, uint8_t col) {
    // return g_layout_storage[row*g_scan_plan.cols + col];
    return flash_read_byte(LAYOUT_ADDR + row*g_scan_plan.cols + col);
}

void init_matrix_scanner_utils(void) {
    g_delta_list_len = 0;
    g_down_list_len = 0;
    // TODO: load scan key map
    memset(g_key_num_bitmap, 0, KEY_NUMBER_BITMAP_SIZE);
}

// TODO:
void scanner_add_matrix_key(uint8_t row, uint8_t col) {
    uint8_t key_num = get_key_number(row, col);

    // add then key to the delta list
    if (g_delta_list_len < MAX_UPDATE_LIST) {
        g_delta_list[g_delta_list_len] = MATRIX_DELTA_TYPE_PRESSED | key_num;
        g_delta_list_len++;
    }

    if (g_down_list_len < MAX_DOWN_LIST) {
        g_down_list[g_down_list_len] = key_num;
        g_down_list_len++;
    }

    { // add key code to the key number bitmap
        g_key_num_bitmap[key_num / 8] |= (1 << (key_num % 8));
    }
}

void scanner_del_matrix_key(uint8_t row, uint8_t col) {
    uint8_t key_num = get_key_number(row, col);

    // add then key to the delta list
    if (g_delta_list_len < MAX_UPDATE_LIST) {
        g_delta_list[g_delta_list_len] = MATRIX_DELTA_TYPE_RELEASED | key_num;
        g_delta_list_len++;
    }

    // delete key from the down key list
    if (g_down_list_len > 0) { // sanity check
        uint8_t i;
        // find key, and replace it with the last key in the list
        for (i = 0; i < g_down_list_len; ++i) {
            if (g_down_list[i] == key_num) {
                g_down_list[i] = g_down_list[g_down_list_len - 1];
                g_down_list_len--;
                break;
            }
        }
    }

    { // delete key code from the key number bitmap
        g_key_num_bitmap[key_num / 8] &= ~(1 << (key_num % 8));
    }
}

uint8_t get_matrix_data(uint8_t *dest, bool use_deltas) {
    const uint8_t matrix_size = get_matrix_compressed_size();
    const uint8_t num_keys_down = get_matrix_num_keys_down();

#if SCANNER_MATRIX_DELTA != 0
    const uint8_t num_keys_changed = g_delta_list_len;
    g_delta_list_len = 0; // clear update list even if we don't use it

    if (use_deltas || (matrix_size > (PACKET_PAYLOAD_LENGTH-1) && num_keys_down > PACKET_PAYLOAD_LENGTH-1)) {
        if ( (num_keys_changed < num_keys_down) && (num_keys_changed < matrix_size) ) {
            *dest = (PACKET_MATRIX_DELTA_LIST << PACKET_MATRIX_TYPE_BIT_POS) | (num_keys_changed & PACKET_MATRIX_SIZE_MASK);
            dest++;
            memcpy(dest, g_delta_list, num_keys_changed);
            return num_keys_changed + 1;
        }
    }
#endif

    // A few keys down, send a list of keys instead of the whole matrix.
    if (num_keys_down < matrix_size) {
        *dest = (PACKET_MATRIX_KEY_LIST << PACKET_MATRIX_TYPE_BIT_POS) | (num_keys_down & PACKET_MATRIX_SIZE_MASK);
        dest++;
        memcpy(dest, g_down_list, g_down_list_len);
        return num_keys_down+1;
    }

    // Lots of keys down, more efficient to send the whole matrix.
    else {
        *dest = (PACKET_MATRIX_RAW << PACKET_MATRIX_TYPE_BIT_POS) | (matrix_size & PACKET_MATRIX_SIZE_MASK);
        dest++;
        memcpy(dest, g_key_num_bitmap, matrix_size);
        return matrix_size+1;
    }
}

void scanner_init_debouncer(void) {
    memset(s_is_debouncing, 0, sizeof(s_is_debouncing));
    s_matrix_number_keys_down = 0;
    s_matrix_number_keys_debouncing = 0;
}

bool scanner_debounce_row(
    uint8_t row,
    const uint8_t *old_row,
    const uint8_t *new_row,
    uint8_t bytes_per_row
) {
    const uint8_t cur_time = timer_read8_ms();
    bool has_updated;

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
                // key debouncing:
                // check if the key has finished debouncing
                if (s_debounce_type[row][i] & pin_mask) {
                    // debouncing key press
                    const uint8_t bounce_duration = (uint8_t)(cur_time - s_debounce_time[row][col]);
                    if (!(old_row[i] & pin_mask)) {
                        // key press not registered yet
                        if (bounce_duration >= g_scan_plan.trigger_time_press) {
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
                        if ( bounce_duration >= g_scan_plan.debounce_time_press) {
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
                        if ((old_row[i] & pin_mask) && bounce_duration >= g_scan_plan.trigger_time_release) {
                            // key has been in the up state for DEBOUNCE_RELEASE_TRIGGER_TIME,
                            // accept that the key has actual been release now
                            g_matrix[row][i] &= ~pin_mask;
                            s_matrix_number_keys_down--;
                            scanner_del_matrix_key(row, col);
                            has_updated = 1;
                        } else if (bounce_duration >= g_scan_plan.debounce_time_release ) {
                            // debounce over
                            s_is_debouncing[row][i] &= ~pin_mask;
                            s_matrix_number_keys_debouncing--;
                        }
                    }
                }
            } else {
                // not debouncing, so a key was pressed/released.

                if (!(changed_pins & pin_mask)) {
                    // ignore pins in this row that haven't changed
                    continue;
                }

                // If the key press/release trigger time is 0, then that means
                // we should trigger the key immediately after seeing that it
                // has changed state.
                bool is_key_down = new_row[i] & pin_mask;
                if (g_scan_plan.trigger_time_press == 0 && is_key_down) {
                    // debounce press trigger time is 0, so register he key press
                    // immediately. The debouncing algorithm then waits until
                    // DEBOUNCE_PRESS_TIME has elapsed before accepting any more
                    // changes in key state.
                    // state.
                    g_matrix[row][i] |= pin_mask;
                    s_matrix_number_keys_down++;
                    scanner_add_matrix_key(row, col);
                    has_updated = 1;
                } else if (g_scan_plan.trigger_time_release == 0 && !is_key_down) {
                    // debounce release trigger time is 0, so register the key press
                    // immediately. The debouncing algorithm then waits until
                    // DEBOUNCE_RELEASE_TIME has elapsed before accepting any
                    // more changes in key state.
                    g_matrix[row][i] &= ~pin_mask;
                    s_matrix_number_keys_down--;
                    scanner_del_matrix_key(row, col);
                    has_updated = 1;
                }

                // this pin has changed, so we start it's debounce timer
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
