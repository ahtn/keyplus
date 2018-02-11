// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/settings.h"

#include "config.h"

#include <string.h>

#include "core/error.h"
#include "core/crc.h"
#include "core/flash.h"
#include "core/util.h"

// settings loaded into ram
XRAM rf_settings_t g_rf_settings;
XRAM runtime_settings_t g_runtime_settings;

#if USE_SCANNER == 0
#include "core/matrix_scanner.h"
XRAM matrix_scan_plan_t g_scan_plan;
#endif

AT__SETTINGS_ADDR const settings_t g_settings_storage = {

    .device_id = DEVICE_ID,

    .timestamp = { BUILD_TIME_STAMP },

// TODO: handle custom settings when build from source better
#include "settings/dev_global_settings.c"

#include "settings/dev_layout_settings.c"

#include "settings/dev_rf_settings.c"

    // NOTE: can't do this at compile time, need to parse the layout file
    // and generate it
    .crc = 0x1234,
};


// TODO: correct the values used here
const ROM firmware_build_settings_t g_firmware_build_settings = {
    .version_major = 0,
    .version_minor = 2,
    .version_patch = 2,

    .layout_flash_size = LAYOUT_SIZE,
    .timestamp = { BUILD_TIME_STAMP },
    .git_hash = { GIT_HASH },

    // connectivity
    .nrf24_support = USE_NRF24,
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

    .chip_id = MCU_CHIP_ID,
    .board_id = 0,
#ifdef NO_MATRIX
    .internal_scan_method = MATRIX_SCANNER_INTERNAL_NONE,
#else
    .internal_scan_method = INTERNAL_SCAN_METHOD,
#endif
};

uint8_t device_id_to_pipe_num(const uint8_t device_id) {
    return device_id % NUM_KEYBOARD_PIPES;
}


void settings_load_from_flash(void) {
    // load rf setings into ram
    flash_read(
        (uint8_t*)&g_rf_settings,
        (flash_ptr_t)&(GET_SETTING(rf)),
        sizeof(rf_settings_t)
    );

    { // validate that the settings are (not corrupt)/(have been initilized)
        const uint16_t flash_checksum = crc16_flash_buffer(
            SETTINGS_ADDR,
            SETTINGS_MAIN_INFO_SIZE-2
        );
        // WARNING: this crc doesn't output 0 when appended with the
        // datastream, so you needed to compare it with the crc value
        if (flash_checksum != GET_SETTING(crc)) {
            register_error(ERROR_SETTINGS_CRC_MISMATCH);
        }
    }

    // Don't show features as enabled that are disabled at build time
    g_runtime_settings.feature_ctrl &= FEATURE_CTRL_FEATURES_DISABLED_AT_BUILD_TIME;

#ifndef NO_MATRIX
    // TODO: validate the settings before returning
    flash_read(
        (uint8_t*)&g_scan_plan,
        ((flash_ptr_t)&GET_SETTING(scan_plan)),
        sizeof(matrix_scan_plan_t)
    );
#endif

}
