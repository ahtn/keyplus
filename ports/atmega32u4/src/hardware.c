// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/hardware.h"

#include <avr/io.h>
#include <avr/wdt.h>

#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))

void hardware_init(void) {
    // set for 16 MHz clock
    CPU_PRESCALE(0);

    // NOTE: the security mechanism on the MCUCR register requires that we write
    // The JTD bit twice before changes will take effect.
    {
        uint8_t new_value = MCUCR | _BV(JTD);
        MCUCR = new_value;
        MCUCR = new_value;
    }

    wdt_reset();
    wdt_disable();
}

void led_init(void) {
}

#if defined(BOOTLOADER_ATMEL_DFU)

#include "bootloaders/atmel_dfu/atmel_bootloader.h"

void bootloader_jmp(void) {
    run_bootloader();
}

void reset_mcu(void) {
    wdt_enable(WDTO_15MS);
    wdt_reset();
    while (1);
}


#elif defined(BOOTLOADER_KP_BOOT_32U4)

#include "bootloaders/kp_boot_32u4/interface/kp_boot_32u4.h"

void reset_mcu(void) {
    kp_boot_reset();
}

void bootloader_jmp(void) {
    kp_boot_jmp();
}

#endif

void wdt_init(void) {
    wdt_enable(WDTO_1S);
}

void wdt_kick(void) {
    wdt_reset();
}

void led_testing_set(void) {

}

void idle_sleep(void) {

}
