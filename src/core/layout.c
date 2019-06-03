// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/layout.h"

#include "config.h"

#include "core/error.h"
#include "core/keycode.h"
#include "core/macro.h"
#include "core/settings.h"
#include "core/flash.h"

// layout storage structure is like this:
//
// The first section is for storing the (row, col) -> (key number map). It's
// size is `g_settings.row_count * g_settings.col_count`.
//  `flash_addr_t storage_pos = (g_settings.row_count * g_settings.col_count + 1) / 2;`
//
// The second section is for the extended keycode data. It's size is given in the
// first 2 bytes of the section.
//
// The third section is for the layout data. The structure of the layout section
// is determined by the g_settings.layout[].
//
//
// layout_storage: {
//    // maps (row, column) -> key number
//    uint8_t matrix_to_key_num_map[rows * (col+1)];
//
//    uint16_t ekc_data_size;
//    uint8_t ekc_data[ekc_data_size];
//
//    layout_array[num_layouts] = {
//        layout_header_t header;
//        keycode_t keycode_array[8 * matrix_size * layer_count]; // matrix_size = ceil(num_keys/8)
//    }
// }
#if USE_VIRTUAL_MODE
    //
#else
AT__LAYOUT_ADDR const uint8_t g_layout_storage[LAYOUT_SIZE] = { 0 };
#endif

// Lookup table for the address where a layout starts:
// maps layout id -> start of layout in flash
XRAM flash_addr_t g_layout_storage_pos[MAX_NUM_KEYBOARDS];

void keyboard_layouts_init(void) {
    uint8_t i;

    flash_addr_t storage_pos = LAYOUT_PORT_KEY_NUM_MAP_ADDR;

#if !defined(NO_MATRIX) && !USE_VIRTUAL_MODE
    // key num map section
    {
        // skip the key num map section, since it is in a known location at compile
        // time.
        flash_addr_t key_num_map_size = g_scan_plan.rows * (g_scan_plan.max_col_pin_num+1);
        storage_pos += key_num_map_size;
    }
#endif

#if USE_VIRTUAL_MODE && !defined(NO_MATRIX)
    #error "should use `NO_MATRIX` with `USE_VIRTUAL_MODE`"
#endif

#if USE_VIRTUAL_MODE
    // virtual mode includes the key number maps for all devices
    {
        // skip the key num map section, since it is in a known location at compile
        // time.
        flash_addr_t key_num_map_size = VIRTUAL_KEYNUM_MAP_SIZE * GET_SETTING(layout.number_devices);
        storage_pos += key_num_map_size;
    }
#endif

    // extended keycode section
    {
        flash_read((uint8_t*)&g_ekc_storage_size, storage_pos, sizeof(uint16_t));
        storage_pos += sizeof(uint16_t);

        if (!is_valid_storage_pos(storage_pos + g_ekc_storage_size)) {
            g_ekc_storage_size = 0;
            register_error(ERROR_EKC_STORAGE_TOO_LARGE);
            return;
        } else {
            g_ekc_storage_ptr = storage_pos;
        }

        storage_pos += g_ekc_storage_size;
    }


    // layout section
    {
       uint8_t num_layouts;

       storage_pos += LAYOUT_HEADER_SIZE;
#if NO_SPLIT
        g_layout_storage_pos[0] = storage_pos;
#else
        num_layouts = GET_SETTING(layout.number_layouts);
        g_layout_storage_pos[0] = storage_pos;

        if (num_layouts > MAX_NUM_KEYBOARDS) {
            register_error(ERROR_NUM_LAYOUTS_TOO_LARGE);
            return;
        } else {
            // calculate the start of the keyload positions and save them for later
            for (i = 1; i < num_layouts; ++i) {
                const uint8_t matrix_size = GET_SETTING(layout.layouts[i-1].matrix_size);
                const uint8_t layer_count = GET_SETTING(layout.layouts[i-1].layer_count);
                const flash_addr_t this_layout_size = GET_SETTING(layout.layouts[i].matrix_size);

                // skip the layout HEADER
                storage_pos += LAYOUT_HEADER_SIZE;

                // skip the layout body, pos should now be set to the start
                // of the next layout
                storage_pos += 8*sizeof(keycode_t) * matrix_size * layer_count;

                if (is_valid_storage_pos(storage_pos + this_layout_size - 1)) {
                    g_layout_storage_pos[i] = storage_pos;
                } else {
                    register_error(ERROR_LAYOUT_STORAGE_OUT_OF_BOUNDS);
                    break;
                }
            }
        }
#endif
    }
}

bool has_mouse_layers(uint8_t layout_id) {
   return flash_read_byte(
      g_layout_storage_pos[layout_id] - LAYOUT_HEADER_SIZE + 0
   );
}
