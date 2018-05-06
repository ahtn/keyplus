// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "util.h"

#include <avr/io.h>
#include <avr/pgmspace.h>

uint8_t read_production_signature_byte(uint16_t address) {
    uint8_t result;
    NVM_CMD = NVM_CMD_READ_CALIB_ROW_gc;
    result = pgm_read_byte(address);
    NVM_CMD = NVM_CMD_NO_OPERATION_gc;
    return result;
}

char hexdigit_to_char(uint8_t d) {
    d = d & 0x0f;
    if (d < 0x0a) {
        return '0' + d;
    } else {
        return 'a' + (d - 0x0a);
    }
}

void software_reset(void) {
    // use xmega software reset functionality
    asm volatile("cli\n\t"          // disable interrupts
                "ldi r24, 0xD8\n\t" // value to write to CCP
                "ldi r25, 0x01\n\t" // value to write to SWRST
                "ldi r30, 0x78\n\t" // base address of RST peripheral
                "ldi r31, 0\n\t"
                "out __CCP__, r24\n\t"
                "std Z+1, r25\n\t"  // +1 is the offset of RST.CTRL
                ::); // no clobber list because we don't return
}

void wdt_init(void) {
    uint8_t temp = WDT_ENABLE_bm | WDT_CEN_bm | WATCH_DOG_PERIOD;
    CCP = CCP_IOREG_gc;
    WDT.CTRL = temp;

    // wait for changes to take effect
    while(WDT.STATUS & WDT_SYNCBUSY_bm) {}
}

void wdt_kick(void) {
    asm("wdr");
}
