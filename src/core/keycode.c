// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/keycode.h"

#include <string.h>

#include "core/error.h"

XRAM flash_ptr_t g_ekc_storage_ptr;
XRAM uint32_t g_ekc_storage_size;

keycode_t get_ekc_class(keycode_t kc) {
    if (kc & KC_EXTERNAL_FLAG) {
        keycode_t result;
        uint16_t addr = EKC_ADDR(kc);
        get_ekc_data((uint8_t*)&result, addr, sizeof(keycode_t));
        return result;
    } else {
        return kc;
    }
}

uint8_t get_ekc_data(void *dest, uint16_t offset, uint16_t size) REENT {
    if (is_valid_storage_pos((flash_ptr_t)g_ekc_storage_ptr + offset) &&
        is_valid_storage_pos((flash_ptr_t)g_ekc_storage_ptr + offset + size - 1)
       ) {
        flash_read(dest, g_ekc_storage_ptr + offset, size);
        return 0;
    } else {
        register_error(ERROR_EKC_OUT_OF_BOUNDS_ACCESS);
        memset(dest, 0, size);
        return 1;
    }
}
