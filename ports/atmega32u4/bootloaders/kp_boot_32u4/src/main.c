// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include <avr/boot.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/wdt.h>
#include <util/delay.h>

#include "usb.h"

#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))

// Note: store in some address that we don't plan on using
#define MAGIC_ADDRESS (0x200-4)
#define MAGIC_ENTER_BOOT (0xda54)
#define MAGIC_ENTER_APPL (~0xda54)

typedef uint16_t magic_t;

void spm_leap_cmd(uint16_t addr, uint8_t spmCmd, uint16_t optValue);

int main(void) {
    cli();

    // set for 16 MHz clock
    CPU_PRESCALE(0);

    const uint8_t magic_start_boot = *(magic_t*)(MAGIC_ADDRESS) == MAGIC_ENTER_BOOT;
    const uint8_t magic_start_app = *(magic_t*)(MAGIC_ADDRESS) == MAGIC_ENTER_APPL;

    // Save the MCUSR register at the MAGIC_ADDRESS so that the application
    // can read it if needed
    *(uint8_t*)(MAGIC_ADDRESS) = MCUSR;
    const uint8_t external_reset = (MCUSR & (1<<EXTRF));
    // MCUSR &= ~((1<<EXTRF) | (1<<WDRF));
    MCUSR = 0;

    const uint8_t is_flash_empty = pgm_read_word(0x0000) == 0xffff;

    // Check if we should enter the bootloader.
    //
    // We will enter the bootloader if one of the following conditions is met:
    //
    // 1. The flash is empty
    // 2. The software wants to enter the bootloader by setting the magic value
    // 3. An external reset was detect
    if (
        ( (!magic_start_boot) && (!external_reset) && (!is_flash_empty) )
        || magic_start_app
    ) {
        // set one bit of the magic data, so next reset will enter bootloader
        asm volatile("jmp 0x0000");
    }

    // Change value at MAGIC_ADDRESS so that a reset from the bootloader will
    // enter the application code.
    *(magic_t*)(MAGIC_ADDRESS) = MAGIC_ENTER_APPL;

    // Setup watch dog timer
    // Prescaler: 0b0100 -> 64k cycles -> 0.5s
    wdt_reset();
    WDTCSR = (1<<WDCE) | (1<<WDE);
    WDTCSR = (1<<WDE) | (0<<WDP3) | (1<<WDP2) | (0<<WDP1) | (1<<WDP0);

    usb_init();

    while (1) {
        usb_poll();
        wdt_reset();
    }
}
