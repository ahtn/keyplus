// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "event_mapper.h"

#include <string.h>

#include <libevdev/libevdev.h>

#include "hid_to_ev.h"
#include "debug.h"

static struct kb_event_map m_devices[MAX_NUM_DEVICES];

int mapper_event_to_key_num(int dev_id, int event_code) {
    KP_ASSERT(event_code < KEY_CNT);
    KP_ASSERT(dev_id < MAX_NUM_DEVICES);
    KP_ASSERT(m_devices[dev_id].dev_id != 0xff);

    return m_devices[dev_id].key_num_map[event_code];
}

void mapper_clear_map(int dev_id) {
    m_devices[dev_id].dev_id = 0xff;
    memset(m_devices[dev_id].key_num_map, UNMAPPED_KEY, KEY_CNT*sizeof(uint8_t));
}

/// Clear all the keyboard mappers
void mapper_reset(void) {
    for (int i = 0; i < MAX_NUM_DEVICES; ++i) {
        mapper_clear_map(i);
    }
}

/// Set the key mapping for the given keyboard
///
/// Takes a hid -> key_num map and assigns
///
/// @param map      A hid -> key_num map
void mapper_set_map(int dev_id, uint8_t *map) {
    KP_ASSERT(dev_id < MAX_NUM_DEVICES);
    memset(m_devices[dev_id].key_num_map, UNMAPPED_KEY, KEY_CNT*sizeof(uint8_t));

    m_devices[dev_id].dev_id = dev_id;

    // We want the `key_num_map` to map from linux event codes -> key numbers.
    // However, the `key_map` in "flash" provides HID codes -> key numbers.
    // So need to map HID code -> ev code -> key_num
    //
    // NOTE: the HID codes <= 255 corresponds to their values keyboard usage
    // table.  However values > 255 correspond to values in the System and
    // Consumer usage tables. See ref: TODO
    for (int i = 0; i < KEY_MAP_SIZE; ++i) {
        int key_num;
        int event_code;

        key_num = map[i];
        if (key_num == 0xff) {
            continue;
        }

        if (HID_MAP_KB_START <= i && i <= HID_MAP_KB_END) {
            // HID code equals position in the table
            int hid = i;

            event_code = HID_KB_TO_EV[hid];

            KP_DEBUG_PRINT(2,
                        "Event(%d): mapping %s<%d>/HID<%d> --> key_num<%d> \n",
                        dev_id,
                        libevdev_event_code_get_name(EV_KEY, event_code),
                        event_code,
                        hid,
                        key_num);

            m_devices[dev_id].key_num_map[event_code] = key_num;
        } else if (HID_MAP_SYS_START <= i && i <= HID_MAP_SYS_END) {

        } else if (HID_MAP_MOUSE_START <= i && i <= HID_MAP_MOUSE_END) {
            int mouse_btn = i - HID_MAP_MOUSE_START;
            event_code = hid_mouse_to_ev(mouse_btn);
            KP_DEBUG_PRINT(2,
                        "Event(%d): mapping %s<%d> -> MouseBTN<%d>\n",
                        dev_id,
                        libevdev_event_code_get_name(EV_KEY, event_code),
                        event_code,
                        mouse_btn);
            m_devices[dev_id].key_num_map[event_code] = key_num;
        }
    }
}
