// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/flash.h"

void flash_modify_enable(void) {
}

void flash_modify_disable(void) {
}

void flash_erase_page(uint16_t page_num) {
}

void flash_write(uint8_t * data, uint16_t addr, uint16_t len) {
}

uint8_t flash_read_byte(flash_ptr_t addr) {
    return *((ROM uint8_t *)addr);
}

uint16_t flash_read_word(flash_ptr_t addr) {
    return *((ROM uint16_t*)addr);
}

void flash_read(uint8_t* dest, flash_ptr_t addr, flash_size_t len) {
    XRAM flash_size_t i;
    for (i = 0; i < len; ++i) {
        dest[i] = ((ROM uint8_t *)addr)[i];
    }
}

// void flash_read(uint8_t* dest, flash_ptr_t addr, flash_size_t len) {
//     while(len--) {
//         *(dest++) = *(ROM uint8_t *)(addr++);
//     }
// }

