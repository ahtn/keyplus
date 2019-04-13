// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/flash.h"

#include <stdint.h>
#include <string.h>

#include "nrf_nvmc.h"

uint8_t flash_read_byte(flash_addr_t addr) {
    return *(uint8_t*)addr;
}

// TODO: rename this, since ARM has 32 bit word size, but this is 16 bit
uint16_t flash_read_word(flash_addr_t addr) {
    return *(uint16_t*)addr;
}

void flash_read(uint8_t* dest, flash_addr_t addr, flash_size_t len) {
    memcpy(dest, (uint8_t*)addr, len);
}

void flash_modify_enable(void) {
}

void flash_modify_disable(void) {
}

void flash_erase_page(flash_addr_t page_num) {
    nrf_nvmc_page_erase(page_num * PAGE_SIZE);
}

void flash_write(const uint8_t* src, flash_addr_t addr, flash_size_t len) {
    // First write bytes that are not aligned (if any)
    uint32_t alignment = addr & (uint32_t)0x03;
    if (alignment != 0) {
        uint32_t word = 0xFFFFFFFF;
        uint32_t size = MIN(len, 4-alignment);
        for (uint32_t i=0; i < size; i++) {
            ((uint8_t*)&word)[alignment+i] = src[i];
        }
        nrf_nvmc_write_word(addr & (uint32_t)~0x03, word);
        addr += size;
        src += size;
        len -= size;
    }

    // Now write as much as we can that is 32 bit aligned
    uint32_t aligned_section_size = len & (uint32_t)~0x03;
    nrf_nvmc_write_words(addr, (uint32_t*)(src), aligned_section_size / 4);
    addr += aligned_section_size;
    src += aligned_section_size;
    len -= aligned_section_size;

    // Group the remaining bytes (if any) in one final word write
    uint32_t remaining = len & 0x03;
    if (remaining != 0) { // 1-3 bytes remaining
        // Assume little endian
        uint32_t word = 0xFFFFFFFF;
        ((uint8_t*)&word)[0] = *src++;
        if (remaining >= 2) { ((uint8_t*)&word)[1] = *src++;}
        if (remaining >= 3) { ((uint8_t*)&word)[2] = *src++;}
        nrf_nvmc_write_word(addr, word);
    }
}
