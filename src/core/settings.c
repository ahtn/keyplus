// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/settings.h"

#include "config.h"

#include <string.h>

#include "core/flash.h"
#include "core/util.h"
#include "core/matrix_scanner.h"

/* ekey 792c72c23b3e78e446992d1b498c8c63 */
/* dkey 3fb9f208e390fee70780122117e7e2c2 */
/* addr_0 2aef63473c */
/* addr_1 168d715956 */
// settings loaded into ram
XRAM rf_settings_t g_rf_settings;

AT__SETTINGS_ADDR const settings_t g_settings = {

    .device_id = DEVICE_ID,

    .timestamp = { BUILD_TIME_STAMP },

// TODO: handle custom settings when build from source better
#include "settings/dev_global_settings.c"

#include "settings/dev_layout_settings.c"

#include "settings/dev_rf_settings.c"
};


// TODO: correct the values used here
const ROM firmware_build_settings_t g_firmware_build_settings = {
    .version_major = 0,
    .version_minor = 2,
    .version_patch = 0,

    .layout_flash_size = 1UL << 16, // TODO, set this value properly
    .timestamp = { BUILD_TIME_STAMP },
    .git_hash = { GIT_HASH },

    // connectivity
    .wireless_support = USE_NRF24,
    .i2c_support = USE_I2C,
    .unifying_support = USE_UNIFYING,
    .usb_support = USE_USB,
    .bt_support = USE_BLUETOOTH,

    // matrix scanning
    .scan_support = USE_SCANNER,
    .scan_col_row = (1) && USE_SCANNER && !USE_HARDWARE_SPECIFIC_SCAN,
    .scan_row_col = 0 && USE_SCANNER && !USE_HARDWARE_SPECIFIC_SCAN,
    .scan_pins = 0 && USE_SCANNER && !USE_HARDWARE_SPECIFIC_SCAN,
    .scan_arbitrary = 0 && USE_SCANNER && !USE_HARDWARE_SPECIFIC_SCAN,
    .scan_built_in = USE_HARDWARE_SPECIFIC_SCAN && USE_SCANNER,

    // generic keyboard features
    .kro_n_support = 1,
    .kro_6_support = 1,

    // key handler support
    .key_media = 1,
    .key_mouse = 1,
    .key_layers = 1,
    .key_sticky = 1,
    .key_tap = 0,
    .key_hold = 1,

    // led_features
    .led_indicators = 0,
    .led_backlighting = 0,
    .led_ws2812 = 0,

#ifdef NO_USB
    .bootloader_vid = 0,
    .bootloader_pid = 0,
#else
    .bootloader_vid = BOOTLOADER_VID,
    .bootloader_pid = BOOTLOADER_PID,
#endif
};

uint8_t device_id_to_pipe_num(const uint8_t device_id) {
    return device_id % NUM_KEYBOARD_PIPES;
}


void settings_load_from_flash(void) {
#ifndef CONFIG_NO_MATRIX
    g_scan_plan.mode = GET_SETTING(scan_mode);
    g_scan_plan.rows = GET_SETTING(row_count);
    g_scan_plan.cols = GET_SETTING(col_count);
#endif

    // load rf setings into ram
    flash_read((uint8_t*)&g_rf_settings, (flash_ptr_t)&(GET_SETTING(rf)), sizeof(rf_settings_t));
}
