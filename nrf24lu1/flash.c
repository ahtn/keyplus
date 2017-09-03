// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/flash.h"
#include "core/settings.h"

#include "nrf24lu1.h"

void flash_modify_enable(void) {
    FCR = 0xAA;
    FCR = 0x55;
    WEN = 1;
}

void flash_modify_disable(void) {
    WEN = 0;
}

void flash_erase_page(uint8_t page_num) {
    FCR = page_num;
    while (RDYN);
}

void flash_write(uint8_t * data, uint16_t addr, uint16_t len) {
    uint16_t i;
    uint8_t ckcon_val;
    // __xdata uint8_t*  === pointer into xram
    // uint8_t *__xdata  === uint8_t stored in xram
    XRAM uint8_t *addr_ptr = (XRAM uint8_t *)addr;
    ckcon_val = CKCON;
    CKCON = 0x01;
    F0 = EA;
    EA = 0;
    for (i=0; i < len; i++) {
        addr_ptr[i] = data[i];
        while (RDYN);
    }
    EA = F0;
    CKCON = ckcon_val; //Restore CKCON state
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

