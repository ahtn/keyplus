// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/flash.h"

#include "efm8_util/io.h"

/// Use to restore IRQ state for flash
static XRAM uint8_t s_irq_state;

/// First flash key for flash security mechanism using FLKEY sfr
static XRAM uint8_t s_flash_key1;

/// Second flash key for flash security mechanism using FLKEY sfr
static XRAM uint8_t s_flash_key2;

void flash_modify_enable(void) {
    s_irq_state = IE_EA;
    IE_EA = 0;

    // Load these values into variables makes it slightly harder for random
    // code execution to enable flash writes.
    s_flash_key1 = FLKEY_FLKEY__KEY1;
    s_flash_key2 = FLKEY_FLKEY__KEY2;
}

void flash_modify_disable(void) {
    s_flash_key1 = 0;
    s_flash_key2 = 0;
    IE_EA = s_irq_state;
}


/// Writes one byte to flash memory.
static void efm8_flash_common(uint16_t addr, uint8_t byte) {
    uint8_t XRAM* write_pos;

    // Unlock flash by writing the key sequence
    FLKEY = s_flash_key1;
    FLKEY = s_flash_key2;

    // load the address to be written into the DPTR register
    write_pos = (uint8_t XRAM*) addr;

    // Enable flash writes, then do the write
    // The movx instructions
    PSCTL |= PSCTL_PSWE__WRITE_ENABLED;
    *write_pos = byte;
    PSCTL &= ~(PSCTL_PSEE__ERASE_ENABLED|PSCTL_PSWE__WRITE_ENABLED);
}

/// Writes one byte to flash memory.
static void efm8_write_byte(uint16_t addr, uint8_t byte) REENT {
    // Don't need to write 0xff, since that's the default value after an erase
    if (byte == 0xFF) {
        return;
    }

    efm8_flash_common(addr, byte);
}

/// Erases one page of flash memory.
void flash_erase_page(uint16_t page_num) {
    // Enable flash erasing, then start a write cycle on the selected page
    PSCTL |= PSCTL_PSEE__ERASE_ENABLED;
    efm8_flash_common(page_num * PAGE_SIZE, 0);
}

void flash_write(uint8_t* data, uint16_t addr, uint16_t len) REENT {
    while (len--) {
        efm8_write_byte(addr++, *(data++));
    }
}

uint8_t flash_read_byte(flash_ptr_t addr) {
    return *((ROM uint8_t *)addr);
}

uint16_t flash_read_word(flash_ptr_t addr) {
    return *((ROM uint16_t*)addr);
}

void flash_read(uint8_t* dest, flash_ptr_t addr, flash_size_t len) {
    while (len--) {
        *dest++ = *((ROM uint8_t *)addr++);
    }
}
