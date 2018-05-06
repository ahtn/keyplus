// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)
/// @file
///
/// Interface to the kp_boot_32u4 bootloader.

#include <stdint.h>

#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/wdt.h>

#define MAGIC_ADDRESS (0x200-4)
#define MAGIC_ENTER_BOOT (0xda54)
#define MAGIC_ENTER_APPL (~0xda54)

#define SPM_INTERFACE_SIZE      16
#define SPM_INTERFACE_ADDRESS   ((((uint32_t)FLASHEND+1) - SPM_INTERFACE_SIZE))

/// Jump to the bootloader by using a watch dog reset
static inline
void kp_boot_jmp(void) {
    cli();
    wdt_enable(WDTO_15MS);
    wdt_reset();
    *(uint16_t*)MAGIC_ADDRESS = MAGIC_ENTER_BOOT;
    while (1);
}

/// Jump to the bootloader by using a watch dog reset
static inline
void kp_boot_reset(void) {
    cli();
    wdt_enable(WDTO_15MS);
    wdt_reset();
    *(uint16_t*)MAGIC_ADDRESS = 0;
    while (1);
}

void spm_erase_page(uint16_t addr);
void spm_load_temporary_buffer(uint8_t offset, uint16_t data_word);
void spm_write_page(uint16_t addr);
