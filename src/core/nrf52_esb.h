// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/util.h"

void rf_nrf52_load_sync_ack_payload(uint8_t device_id);

void nrf52_esb_hw_init(void);
uint32_t nrf52_esb_init_rx(void);
uint32_t nrf52_esb_init_tx(void);

#if USE_UNIFYING
uint32_t nrf52_esb_init_unifying_pair(
    const XRAM uint8_t *unifying_pairing_addr,
    const XRAM uint8_t *target_addr,
    uint8_t addr_lsb
);
#endif
