// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/hardware.h"

#include "nrf24lu1.h"

#include "core/util.h"
#include "core/bootloader.h"
#include "core/flash.h"

void hardware_init(void) {
    CKCON = 0x01;
}

/*********************************************************************
 *                       watch dog funcntions                        *
 *********************************************************************/

void wdt_init(void) {
    // T(TICKDV) = (1 + TICKDV) / (32_000 Hz)
    // T(0x00) = 31.25 µs
    // T(0xff) = 8 ms
    TICKDV = 0xff;
    wdt_kick();
}

void wdt_kick(void) {
    // 0x100 * T(TICKDV) = 1.024 s
    REGXH = 0x01;
    REGXL = 0x00;
    REGXC = WWD;
}

void reset_mcu(void) {
    REGXH = 0x00;
    REGXL = 0x01;
    REGXC = WWD;

    while(1);
}

/*********************************************************************
 *                          delay functions                          *
 *********************************************************************/

// don't really care if this isn't accurate
void dynamic_delay_us(uint16_t us) {
    while (us--) {
        __asm
            nop
            nop
            nop
            nop
            nop
        __endasm;
    }
}

void dynamic_delay_ms(uint16_t ms) {
    while (ms--) {
        dynamic_delay_us(1000);
    }
}

/*********************************************************************
 *                       bootloader functions                        *
 *********************************************************************/
#include "nrf24lu1_usb.h"
#include "nrf24lu1_usb_regs.h"

static ROM const char bootloader_reset_string[] = "Enter ICP\0";

void bootloader_jmp(void) {
    usbcs = USBCS_DISCON_bm;
    static_delay_ms(100);

#if USE_UNIFYING_BOOTLOADER
    bootloader_jmp_2();
#else
    __asm
        ljmp #BOOTLOADER_ADDR
    __endasm;
#endif
}

#if USE_UNIFYING_BOOTLOADER
void bootloader_jmp_2(void) {
    uint8_t i = 0;
    // Need to load 16 bytes into AESIV to complete the read, so overflowing the
    // array here is intentional as the remaining bytes are unchecked by the
    // bootloader.
    AESIA1 = 0;
    while (i != 16) {
        // intentional overflow, don't chare about what is outside
        AESIV = bootloader_reset_string[i];
        i++;
    }
    __asm
        ljmp #LOGITECH_BOOTLOADER_ADDR
    __endasm;
}
#endif
