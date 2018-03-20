// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/hardware.h"
#include "core/aes.h"
#include "core/rf.h"
#include "core/settings.h"
#include "core/matrix_scanner.h"
#include "core/led.h"
#include "core/usb_commands.h"
#include "core/error.h"

bit_t g_slow_clock_mode = 1;

#if USE_I2C && USE_USB
bit_t g_has_usb_port;
#endif

void software_reset(void) {
    init_error_system();
    settings_load_from_flash();
#if USE_SCANNER
    io_map_init();
    matrix_scanner_init();
#endif
#if USE_RF
    aes_key_init(g_rf_settings.ekey, g_rf_settings.dkey);

    if (!g_runtime_settings.feature.ctrl.rf_disabled) {
        rf_init_receive();
    }
#endif
#if USE_WIRED
    if (g_has_usb_port && !g_runtime_settings.feature.ctrl.wired_disabled) {
        i2c_init();
    }
#endif
    led_init();
    reset_usb_reports();
    keyboards_init();
}
