// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "nrf24lu1.h"

#include "core/flash.h"
#include "core/settings.h"

#include "usb_reports/vendor_report.h"

void flash_modify_enable(void) {
    disable_interrupts();
    FCR = 0xAA;
    FCR = 0x55;
    WEN = 1;
    // NOTE: When flash is written on the nRF24LU1+, the CPU is halted. I'm
    // pretty sure this can mess with the USB controller if it is in the middle
    // of sending/receiving a packet. Since it is important that we
    // send/receive the vendor out packets while updating, we make sure the
    // vendor endpoint is not busy before writing to flash.
    while (
        !is_ready_vendor_in_report() && !is_ready_vendor_out_report()
    );
}

void flash_modify_disable(void) {
    WEN = 0;
    enable_interrupts();
}

void flash_erase_page(uint16_t page_num) {
    FCR = page_num;
    while (RDYN);
}

void flash_write(uint8_t * data, uint16_t addr, uint16_t len) REENT {
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
    flash_size_t i;
    for (i = 0; i < len; ++i) {
        dest[i] = ((ROM uint8_t *)addr)[i];
    }
}

