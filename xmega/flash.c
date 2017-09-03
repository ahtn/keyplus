// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/flash.h"

uint8_t flash_read_byte(flash_ptr_t addr) {
    NVM.CMD = NVM_CMD_NO_OPERATION_gc;
#if flash_ptr_t == uint32_t
    return pgm_read_byte_far(addr);
#else
    return pgm_read_byte(addr);
#endif
}

uint16_t flash_read_word(flash_ptr_t addr) {
    NVM.CMD = NVM_CMD_NO_OPERATION_gc;
#if flash_ptr_t == uint32_t
    return pgm_read_word_far(addr);
#else
    return pgm_read_word(addr);
#endif
}

void flash_read(uint8_t* dest, flash_ptr_t addr, flash_size_t len) {
    NVM.CMD = NVM_CMD_NO_OPERATION_gc;
    memcpy_P(dest, (uint8_t*)(addr), len);
    // while (len != 0) {
    //     *dest++ = flash_read_byte(addr++);
    //     len--;
    // }
}

void flash_erase_page(uint8_t page_num) {

}

void flash_modify_enable(void) {
}

void flash_modify_disable(void) {
}

void flash_write(uint8_t* data, flash_ptr_t addr, flash_size_t len) {
}

