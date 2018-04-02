// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/flash.h"
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <avr/io.h>

/// Saves the state of the interrupt flags while writing flash
static volatile uint8_t s_irq_state;

uint8_t flash_read_byte(flash_addr_t addr) {
#if FLASHEND < 0x10000
    return pgm_read_byte_near(addr);
#else
    return pgm_read_byte_far(addr);
#endif
}

uint16_t flash_read_word(flash_addr_t addr) {
#if FLASHEND < 0x10000
    return pgm_read_word_near(addr);
#else
    return pgm_read_word_far(addr);
#endif
}

void flash_read(uint8_t* dest, flash_addr_t addr, flash_size_t len) {
#if FLASHEND < 0x10000
    memcpy_P(dest, (uint8_t*)(addr), len);
#else
    memcpy_PF(dest, (uint_farptr_t)(addr), len);
#endif
}

void flash_modify_enable(void) {
    s_irq_state = SREG;
    cli();
}

void flash_modify_disable(void) {
    SREG = s_irq_state;
}

#ifdef BOOTLOADER_ATMEL_DFU

#include "bootloaders/atmel_dfu/atmel_bootloader.h"

void flash_erase_page(flash_addr_t page_num) {
    flash_page_erase(page_num * PAGE_SIZE);
}

static inline void sp_load_flash_byte(uint16_t offset, uint8_t byte) {
    if (offset % 2 == 0) {
        flash_fill_temp_buffer((0xff00 | byte), offset);
    } else {
        flash_fill_temp_buffer((0x00ff | byte << 8 ), offset);
    }
}

static inline void sp_write_flash_buffer(uint8_t *data, uint16_t offset, uint16_t len) {
    uint16_t pos = 0;

    // Erase the temporary buffer.
    // SPMCSR = _BV(RWWSRE):

    while (pos + offset < PAGE_SIZE && pos < len) {
        sp_load_flash_byte(offset + pos, data[pos]);
        pos++;
    }
}

void flash_write(uint8_t* src, flash_addr_t addr, flash_size_t len) {
    uint32_t pos = 0;

    while (pos < len) {
        uint16_t write_len;
        uint32_t write_pos = addr + pos;
        uint16_t buffer_write_offset = (write_pos) % PAGE_SIZE;
        uint32_t data_left = (len-pos);
        uint32_t page_end_addr =
            (write_pos / PAGE_SIZE) * PAGE_SIZE
            + PAGE_SIZE;

        if (
            (data_left < PAGE_SIZE) &&
            (write_pos + data_left < page_end_addr)
        ) {
            // If there is not enough data left to fill the page, and the
            // data doesn't extend over the end of the flash page (writes
            // can't cross page boundaries).
            write_len = len - pos;
        } else {
            // Write enough data to fill the rest of the page
            write_len = PAGE_SIZE - buffer_write_offset;
        }

        sp_write_flash_buffer(src+pos, buffer_write_offset, write_len);

        flash_prg_page(write_pos);

        // src += write_len;
        pos += write_len;
    }
}

#else

#error "No valid bootloader value was specified"

#endif
