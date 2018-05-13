// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/hardware.h"

#include <avr/io.h>
#include <avr/pgmspace.h>

#include "core/flash.h"
#include "core/hardware.h"
#include "core/led.h"
#include "core/rf.h"
#include "core/timer.h"

#include "xusb-boot/src/spm_interface.h"

void hardware_init(void) {
    NVM.CMD = NVM_CMD_NO_OPERATION_gc;
}

/*********************************************************************
 *                        watch dog functions                        *
 *********************************************************************/

// WDT_PER_8CLK_gc = (0x00<<2),  /* 8 cycles (8ms @ 3.3V) */
// WDT_PER_16CLK_gc = (0x01<<2),  /* 16 cycles (16ms @ 3.3V) */
// WDT_PER_32CLK_gc = (0x02<<2),  /* 32 cycles (32ms @ 3.3V) */
// WDT_PER_64CLK_gc = (0x03<<2),  /* 64 cycles (64ms @ 3.3V) */
// WDT_PER_128CLK_gc = (0x04<<2),  /* 128 cycles (0.128s @ 3.3V) */
// WDT_PER_256CLK_gc = (0x05<<2),  /* 256 cycles (0.256s @ 3.3V) */
// WDT_PER_512CLK_gc = (0x06<<2),  /* 512 cycles (0.512s @ 3.3V) */
// WDT_PER_1KCLK_gc = (0x07<<2),  /* 1K cycles (1s @ 3.3V) */
// WDT_PER_2KCLK_gc = (0x08<<2),  /* 2K cycles (2s @ 3.3V) */
// WDT_PER_4KCLK_gc = (0x09<<2),  /* 4K cycles (4s @ 3.3V) */
// WDT_PER_8KCLK_gc = (0x0A<<2),  /* 8K cycles (8s @ 3.3V) */
#define WATCH_DOG_PERIOD WDT_PER_1KCLK_gc

void wdt_init(void) {
    uint8_t temp = WDT_ENABLE_bm | WDT_CEN_bm | WATCH_DOG_PERIOD;
    CCP = CCP_IOREG_gc;
    WDT.CTRL = temp;

    // wait for changes to take effect
    while(WDT.STATUS & WDT_SYNCBUSY_bm) {}
}

void wdt_disable_(void) {
    uint8_t temp = (WDT.CTRL & ~WDT_ENABLE_bm) | WDT_CEN_bm;
    CCP = CCP_IOREG_gc;
    WDT.CTRL = temp;
}

void wdt_kick(void) {
    asm("wdr");
}

/*********************************************************************
 *                               sleep                               *
 *********************************************************************/

#include "power.h"

// puts the mcu to sleep until an interrupt is fired
void idle_sleep(void) {
    enter_sleep_mode(SLEEP_MODE_IDLE);
}

/*********************************************************************
 *                       bootloader and reset                        *
 *********************************************************************/

void reset_mcu(void) {
    xusb_boot_reset();
}

void bootloader_jmp(void) {
    xusb_boot_jump();
}

/*********************************************************************
 *                          delay functions                          *
 *********************************************************************/

void dynamic_delay_ms(uint16_t ms) {
    uint16_t i;
    if (g_slow_clock_mode) {
        for (i = 0; i < ms; ++i) {
            static_delay_slow_ms(1);
        }
    } else {
        for (i = 0; i < ms; ++i) {
            static_delay_ms(1);
        }
    }
}
