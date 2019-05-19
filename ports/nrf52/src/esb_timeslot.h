// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include <stdint.h>

#include "nrf_esb.h"

#include "extra/fifo.h"

typedef struct timeslot_stats_t {
    uint32_t start;
    uint32_t end;
    uint32_t rx;
    uint32_t tx;
    uint32_t extensions;
    uint32_t blocked;
    uint32_t canceled;
} timeslot_stats_t;


struct timeslot_stats_t get_timeslot_stats(void);

/// @brief Initialize timeslot handling
uint32_t esb_timeslot_init(void);

/// @brief Start requesting timeslots
uint32_t esb_timeslot_start(void);

/// @brief Stop requesting timeslots
uint32_t esb_timeslot_stop(void);

void esb_timeslot_ack_payload(nrf_esb_payload_t *tx_payload);

/// @brief handler for system events
void soc_evt_handler(uint32_t sys_evt, void *p_context);

// NOTE: included here because the NRF_SDH_SOC_OBSERVER handler is in this file.
void set_flash_busy_bit(void);
bool is_flash_busy(void);
