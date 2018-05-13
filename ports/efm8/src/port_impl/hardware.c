// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/hardware.h"

#include "peripheral_driver/inc/usb_0.h"
#include "efm8_util/reset.h"

void reset_mcu(void) {
    // Disable the USB pull-up resistor, and wait a bit so the host has
    // a chance to see the device disconnect.
    USB_DisablePullUpResistor();
    static_delay_ms(50);

    efm8_software_reset();
}

void wdt_init(void) {
}

void wdt_kick(void) {
}

void bootloader_jmp(void) {
    USB_DisablePullUpResistor();
    static_delay_ms(50);

    efm8_factory_bootloader_jump();
}
