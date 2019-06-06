// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <stdint.h>
#include <linux/input-event-codes.h>

#include "core/settings.h"

#define MAX_KB_COUNT (MAX_NUM_DEVICES+1)
#define UNMAPPED_KEY 0xff

#define MAX_EVENT_COUNT (MAX_NUM_DEVICES+1)
// #define MAX_NUM_DEVICES (MAX_EVENT_COUNT-1)

#define KEY_MAP_SIZE (0x300)

#define HID_MAP_KB_START         0x000
#define HID_MAP_KB_END           0x0ff

#define HID_MAP_SYS_START        0x101
#define HID_MAP_SYS_END          0x10f

#define HID_MAP_MOUSE_START      0x110
#define HID_MAP_MOUSE_END        0x117

#define HID_MAP_CONSUMER_START   0x101
#define HID_MAP_CONSUMER_END     0x110

/// Holds information for mapping linux events codes to keyplus key numbers
struct kb_event_map {
    int kb_id;
    /// This maps a linux-event code to the keyboards key number
    uint8_t key_num_map[KEY_CNT];
};

void mapper_init(void);
void mapper_reset(void);
void mapper_clear_map(int kb_id);
void mapper_set_map(int kb_id, uint8_t *map);

int mapper_event_to_key_num(int kb_id, int event_code);
