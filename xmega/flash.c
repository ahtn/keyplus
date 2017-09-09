// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/flash.h"

#include "xusb-boot/spm_interface.h"

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
}

void flash_erase_page(uint8_t page_num) {
    uint32_t page_addr = page_num * APP_SECTION_PAGE_SIZE;
    SP_EraseApplicationPage(page_addr);
    SP_WaitForSPM();
}

void flash_modify_enable(void) {
}

void flash_modify_disable(void) {
}

static inline void sp_load_flash_byte(uint16_t offset, uint8_t byte) {
    if (offset % 2 == 0) {
        SP_LoadFlashWord(offset, (0xff00 | byte));
    } else {
        SP_LoadFlashWord(offset, (0x00ff | byte << 8 ));
    }
}

static inline void sp_write_flash_buffer(uint8_t *data, uint16_t offset, uint16_t len) {
    uint16_t pos = 0;

    SP_EraseFlashBuffer();
    SP_WaitForSPM();

    while (pos + offset < APP_SECTION_PAGE_SIZE && pos < len) {
        sp_load_flash_byte(offset + pos, data[pos]);
        pos++;
    }
}

void flash_write(uint8_t* src, flash_ptr_t addr, flash_size_t len) {
    uint32_t pos = 0;

    while (pos < len) {
        uint16_t write_len;
        uint32_t write_pos = addr + pos;
        uint16_t buffer_write_offset = (write_pos) % APP_SECTION_PAGE_SIZE;
        if (len - pos < APP_SECTION_PAGE_SIZE) {
            write_len = len - pos;
        } else {
            write_len = APP_SECTION_PAGE_SIZE - buffer_write_offset;
        }

        sp_write_flash_buffer(src, buffer_write_offset, write_len);

        SP_WriteApplicationPage(write_pos);
        SP_WaitForSPM();

        src += write_len;
        pos += write_len;
    }
}
