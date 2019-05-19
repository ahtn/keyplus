// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/nonce.h"
#include "core/flash.h"

#include "app_error.h"
#include "nrf_nvmc.h"

#if USE_SOFTDEVICE
#include "app_scheduler.h"
#include "nrf_pwr_mgmt.h"
#endif

#include "esb_timeslot.h"

#define NONCE_PAGE0_ADDR (NONCE_ADDR)
#define NONCE_PAGE1_ADDR (NONCE_ADDR + PAGE_SIZE)

#define SID_MAGIC (0x268e8728UL)

#define SID_ADDR_MAGIC 0
#define SID_ADDR_VALUE 4
#define SID_ADDR_TALLY 8 // tally mark array

#define TALLY_VALUES_PER_PAGE ((PAGE_SIZE - SID_ADDR_TALLY)/4)
#define TALLY_COUNT_MAX (TALLY_VALUES_PER_PAGE *2)

#define TALLY_VALUE_0 0xFFFFFFFF
#define TALLY_VALUE_1 0xFFFFFFFE
#define TALLY_VALUE_2 0xFFFFFFFC

#define FLASH_READ_U16(ADDR) (*(uint16_t*)(ADDR))
#define FLASH_READ_U32(ADDR) (*(uint32_t*)(ADDR))

bool m_write_enabled = true;

static void flash_page_erase(flash_addr_t page_addr) {
#if USE_SOFTDEVICE
    uint32_t err;
    if (m_write_enabled) {
        do {
            err = sd_flash_page_erase(page_addr / PAGE_SIZE);
            set_flash_busy_bit();
            if (err == NRF_ERROR_BUSY) {
                app_sched_execute();
                nrf_pwr_mgmt_run();
            }
        } while( err == NRF_ERROR_BUSY );
        APP_ERROR_CHECK(err);

        while (is_flash_busy()) {
            app_sched_execute();
            nrf_pwr_mgmt_run();
        }

        m_write_enabled = true;
    }
#else
    nrf_nvmc_page_erase(page_addr);
#endif

}

static void flash_write_word(flash_addr_t addr, uint32_t value) {
#if USE_SOFTDEVICE
    uint32_t err;
    do {
        err = sd_flash_write((uint32_t*)addr, &value, 1);
        set_flash_busy_bit();
        if (err == NRF_ERROR_BUSY) {
            app_sched_execute();
            nrf_pwr_mgmt_run();
        }
    } while (err == NRF_ERROR_BUSY);
    APP_ERROR_CHECK(err);

    while (is_flash_busy()) {
        app_sched_execute();
        nrf_pwr_mgmt_run();
    }
#else
    nrf_nvmc_write_word(addr, value);
#endif
}

/// Returns -1 on error
int16_t count_tally(flash_addr_t nonce_addr) {
    uint_fast16_t i;
    uint16_t result = 0;
    flash_addr_t addr = nonce_addr + SID_ADDR_TALLY;

    for (i = 0; i < TALLY_VALUES_PER_PAGE; ++i) {
        uint32_t tally_mark = ((uint32_t *)addr)[i];
        switch(tally_mark) {
            case TALLY_VALUE_0: {
                return result+1;
            } break;
            case TALLY_VALUE_1: {
                return result+2;
            } break;
            case TALLY_VALUE_2: {
                result += 2;
                continue;
            } break;
            default: { // error
                return -1;
            } break;
        }
    }
    return result;
}

int16_t inc_tally(flash_addr_t nonce_addr) {
    uint_fast16_t i;
    int16_t result = 0;
    flash_addr_t addr = nonce_addr + SID_ADDR_TALLY;

    for (i = 0; i < TALLY_VALUES_PER_PAGE; ++i) {
        uint32_t tally_mark = ((uint32_t *)addr)[i];
        switch(tally_mark) {
            case TALLY_VALUE_0: {
                flash_write_word(addr+sizeof(uint32_t)*i, TALLY_VALUE_1);
                return result+1;
            } break;
            case TALLY_VALUE_1: {
                flash_write_word(addr+sizeof(uint32_t)*i, TALLY_VALUE_2);
                return result+2;
            } break;
            case TALLY_VALUE_2: {
                result += 2;
                continue;
            } break;
            default: { // error
                return -1;
            } break;
        }
    }
    return result;
}

static inline uint16_t read_value(uint8_t page_id) {
    return FLASH_READ_U16(
        (NONCE_PAGE0_ADDR + PAGE_SIZE*page_id) + SID_ADDR_VALUE
    );
}

static inline uint32_t read_magic(uint8_t page_id) {
    return FLASH_READ_U32(
        (NONCE_PAGE0_ADDR + PAGE_SIZE*page_id) + SID_ADDR_MAGIC
    );
}

static void reset_nonce_value(uint8_t page_id, uint16_t value) {
    const flash_addr_t page_addr = NONCE_PAGE0_ADDR + PAGE_SIZE*page_id;
    flash_page_erase(page_addr);
    flash_write_word(page_addr + SID_ADDR_VALUE, value);
    flash_write_word(page_addr + SID_ADDR_MAGIC, SID_MAGIC);
}

uint16_t load_session_id(void) {
    uint32_t magic0 = read_magic(0);
    uint16_t value0 = read_value(0);
    uint32_t magic1 = read_magic(1);
    uint16_t value1 = read_value(1);

    if (magic0 == SID_MAGIC) {
        int16_t tally_value = count_tally(NONCE_PAGE0_ADDR);
        return value0 + tally_value;
    } else if (magic1 == SID_MAGIC) {
        return value1 + TALLY_COUNT_MAX + 1;
    } else {
        return 0;
    }
}

uint16_t increment_session_id(void) {
    uint32_t magic0 = read_magic(0);
    uint16_t value0 = read_value(0);
    uint32_t magic1 = read_magic(1);
    uint16_t value1 = read_value(1);

    if (magic0 == SID_MAGIC) {
        int16_t tally_value = count_tally(NONCE_PAGE0_ADDR);

        if (magic1 != SID_MAGIC) {
            // backup value corrupt, so fix it
            reset_nonce_value(1, value0);
        }

        if (tally_value == -1 || tally_value == TALLY_COUNT_MAX) {
            reset_nonce_value(0, value0 + TALLY_COUNT_MAX + 1);
            reset_nonce_value(1, value0 + TALLY_COUNT_MAX + 1);
            return value0 + TALLY_COUNT_MAX + 1;
        } else {
            tally_value = inc_tally(NONCE_PAGE0_ADDR);
            return value0 + tally_value;
        }
    } else if (magic0 != SID_MAGIC && magic1 == SID_MAGIC) {
        // page0 is corrupt, so use backup value from page1
        uint16_t new_value = value1 + TALLY_COUNT_MAX + 1;

        reset_nonce_value(0, new_value);
        reset_nonce_value(1, new_value);

        return new_value;
    } else {
        // both pages are either corrupt or uninitialized
        reset_nonce_value(0, 0);
        reset_nonce_value(1, 0);
        return 0;
    }
}
