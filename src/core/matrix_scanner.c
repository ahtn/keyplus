// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "config.h"

#include "core/matrix_scanner.h"

#include <string.h>

#include "core/packet.h"
#include "core/layout.h"

#define MAX_UPDATE_LIST 16
#define MAX_DOWN_LIST 16

XRAM uint8_t g_matrix[MAX_NUM_ROWS][(MAX_NUM_COLS+7)/8];

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
    return g_layout_storage[row*g_scan_plan.cols + col];
}


void init_matrix_scanner(void) {
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
