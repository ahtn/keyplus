// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/hardware.h"

#include "nrf_gpio.h"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_nvic.h"

#include "serial_num.h"

void hardware_init(void) {
    nrf52_init_serial_number();
}

void bootloader_jmp(void) {
#if BOOTLOADER_RESET_PIN
    NRF_LOG_FINAL_FLUSH();
    static_delay_ms(100);

    nrf_gpio_cfg_output(BOOTLOADER_RESET_PIN);
    nrf_gpio_pin_clear(BOOTLOADER_RESET_PIN);
#endif

    while (1) { }
}

void reset_mcu(void) {
    NRF_LOG_FINAL_FLUSH();
    static_delay_ms(100);

#if HAS_SOFTDEVICE
    sd_nvic_systemreset();
#else
    NVIC_SystemReset();
#endif

    while (1) { }
}

void wdt_kick(void) {
    // TODO:
}
