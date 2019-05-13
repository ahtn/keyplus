// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include <stdint.h>

#include "extra/fifo.h"

typedef struct timeslot_stats_t {
    uint32_t start;
    uint32_t end;
    uint32_t rx;
    uint32_t extensions;
} timeslot_stats_t;


/**@brief Data handler type. */
typedef void (*timeslot_data_handler_t)(void * p_data, uint16_t length);

struct timeslot_stats_t get_timeslot_stats(void);

/// @brief Initialize timeslot handling
uint32_t esb_timeslot_init(timeslot_data_handler_t evt_handler);

/// @brief Start requesting timeslots
uint32_t esb_timeslot_start(void);

/// @brief Stop requesting timeslots
uint32_t esb_timeslot_stop(void);
