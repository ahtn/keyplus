// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <stdbool.h>
#include "event_codes.h"

struct device_stats {
    uint8_t state;
    uint32_t keys[KEY_CNT];
};

enum {
    STATS_STATE_UNLOADED = 0,
    STATS_STATE_LOADED = 1,
    STATS_STATE_DISABLED = 2,
};

void stats_reset(void);
void stats_add_key(uint8_t dev_id, int event_code);
void stats_set_press_count(uint8_t dev_id, int event_code, uint32_t press_count);
void stats_enable_device(uint8_t dev_id, bool enable);

void stats_load(const char *filename);
void stats_save(const char *filename);
