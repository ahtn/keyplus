// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <stdint.h>
#include <stdbool.h>

#include <util/atomic.h>

#include "core/flash.h"

enum {
    PTR_DATA = 0,
    PTR_FLASH = 1,
    PTR_EEPROM = 2,
};

typedef flash_ptr_t raw_ptr_t ;

/// The fat pointer type is used to make it easier to pass data from various
/// memory regions between functions. In addition to the address, this pointer
/// includes the size and type of the memory region (ram, flash, eeprom).
typedef struct fat_ptr_t {
    uint8_t type;
    uint16_t len;
    union {
        const uint8_t* data;
        flash_ptr_t flash;
        raw_ptr_t raw;
    } ptr;
} fat_ptr_t;

void usb_write_endpoint(uint8_t ep_number, const uint8_t *src, uint8_t length);
void usb_read_endpoint(uint8_t ep_number, uint8_t *dest, uint8_t *length);

/// Checks if the given USB endpoint is ready
static inline bool usb_is_endpoint_ready(uint8_t ep_num) {
    uint8_t result;
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        UENUM = ep_num;
        result = UEINTX & (1<<RWAL);
    }
    return result;
}
