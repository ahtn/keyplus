// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/flash.h"

#include "xusb-boot/spm_interface.h"

uint8_t flash_read_byte(flash_addr_t addr) {
    NVM.CMD = NVM_CMD_NO_OPERATION_gc;
#ifdef XMEGA_FAR_FLASH
    return pgm_read_byte_far(addr);
#else
    return pgm_read_byte(addr);
#endif
}

uint16_t flash_read_word(flash_addr_t addr) {
    NVM.CMD = NVM_CMD_NO_OPERATION_gc;
#ifdef XMEGA_FAR_FLASH
    return pgm_read_word_far(addr);
#else
    return pgm_read_word(addr);
#endif
}

void flash_read(uint8_t* dest, flash_addr_t addr, flash_size_t len) {
    NVM.CMD = NVM_CMD_NO_OPERATION_gc;
#ifdef XMEGA_FAR_FLASH
    memcpy_PF(dest, (uint_farptr_t)(addr), len);
#else
    memcpy_P(dest, (uint8_t*)(addr), len);
#endif
}

void flash_erase_page(flash_addr_t page_num) {
    uint32_t page_addr = (uint32_t)page_num * (uint32_t)APP_SECTION_PAGE_SIZE;
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

void flash_write(uint8_t* src, flash_addr_t addr, flash_size_t len) {
    uint32_t pos = 0;

    while (pos < len) {
        uint16_t write_len;
        uint32_t write_pos = addr + pos;
        uint16_t buffer_write_offset = (write_pos) % APP_SECTION_PAGE_SIZE;
        uint32_t data_left = (len-pos);
        uint32_t page_end_addr =
            (write_pos / APP_SECTION_PAGE_SIZE) * APP_SECTION_PAGE_SIZE
            + APP_SECTION_PAGE_SIZE;

        if (
            (data_left < APP_SECTION_PAGE_SIZE) &&
            (write_pos + data_left < page_end_addr)
        ) {
            // If there is not enough data left to fill the page, and the
            // data doesn't extend over the end of the flash page (writes
            // can't cross page boundaries).
            write_len = len - pos;
        } else {
            // Write enough data to fill the rest of the page
            write_len = APP_SECTION_PAGE_SIZE - buffer_write_offset;
        }

        sp_write_flash_buffer(src+pos, buffer_write_offset, write_len);

        SP_WriteApplicationPage(write_pos);
        SP_WaitForSPM();

        // src += write_len;
        pos += write_len;
    }
}
