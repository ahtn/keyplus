// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <stdint.h>
#include <stddef.h>

#include "core/util.h"
#include "core/packet.h"
#include "core/nrf24.h"
#include "core/matrix_scanner.h"

#include "core/flash.h"

#define NUM_KEYBOARD_PIPES 4

#define NRF_ADDR_LEN 5
#define AES_KEY_LEN 16

#define UNPROGRAMMED_DEVIE_ID 0xff

#define MAX_NUM_KEYBOARDS 64
#define MAX_NUM_DEVICES 64

enum {
    KEYBOARD_REPORT_MODE_AUTO = 0, // 6kro -> nkro if more than 6 keys pressed
    KEYBOARD_REPORT_MODE_NKRO = 1, // nkro
    KEYBOARD_REPORT_MODE_6KRO = 2, // 6kro
    KEYBOARD_REPORT_MODE_UPGRADE, // transitioning 6kro -> nkro
};

typedef struct device_info_t {
    uint8_t layout_id; // the keyboard layout that this device maps to
    uint8_t matrix_offset; // the component byte offset into the given keyboard
    uint8_t matrix_size; // the size of this component == ceil(rows*cols/8)
} device_info_t;

// TODO: maybe move layout and settings to start of layout_storage
typedef struct layout_info_t {
    uint8_t matrix_size;
    uint8_t layer_count;
} keyboard_info_t;

#define SETTINGS_LAYOUT_INFO_SIZE 32
#define SETTINGS_LAYOUT_INFO_OFFSET (offsetof(settings_t, layout))
typedef struct {
    uint8_t number_layouts;
    uint8_t number_devices;
    uint8_t _reserved[30]; // 32
    keyboard_info_t layouts[MAX_NUM_KEYBOARDS];
    device_info_t devices[MAX_NUM_DEVICES];
} layout_settings_t;

#define SETTINGS_RF_INFO_SIZE 64
#define SETTINGS_RF_INFO_OFFSET (offsetof(settings_t, rf))
typedef struct rf_settings_t { // 64 bytes
    uint8_t pipe_addr_0[NRF_ADDR_LEN];
    uint8_t pipe_addr_1[NRF_ADDR_LEN];
    uint8_t pipe_addr_2;
    uint8_t pipe_addr_3;
    uint8_t pipe_addr_4;
    uint8_t pipe_addr_5;
    uint8_t channel; // TODO: when using unifying, channel must be ((ch+2)%3 == 0)
                     // this should be enforced somewhere
    uint8_t arc;
    uint8_t data_rate;
    uint8_t power;
    uint8_t _reserved[14]; // padding
    uint8_t ekey[AES_KEY_LEN];
    uint8_t dkey[AES_KEY_LEN];
} rf_settings_t;

typedef struct feature_ctrl_t {
    uint8_t usb_disable: 1;
    uint8_t wired_disable: 1;
    uint8_t rf_disable: 1;
    uint8_t rf_mouse_disable: 1;
    uint8_t bt_disable: 1;
    uint8_t reserved_0: 1;
    uint8_t reserved_1: 1;
    uint8_t reserved_2: 1;
} feature_ctrl_t;

#define SETTINGS_MAIN_INFO_SIZE 96
typedef struct settings_t { // 512 bytes
    uint8_t device_id;
    char device_name[32];
    uint8_t timestamp[8]; // utc time stamp of last update
    uint8_t default_report_mode;
    uint8_t scan_mode;
    uint8_t row_count;
    uint8_t col_count;
    feature_ctrl_t feature_ctrl;
    uint8_t _reserved[48];
    uint16_t crc; // size == 96
    layout_settings_t layout; // size == 352
    rf_settings_t rf; // size == 64
} settings_t;

// Settings that are loaded from flash and/or changeable at run time
typedef struct runtime_settings_t {
    uint8_t device_id;
    feature_ctrl_t feature_ctrl;
} runtime_settings_t;

/*********************************************************************
 *                      firmware build settings                      *
 *********************************************************************/
typedef struct firmware_build_settings_t {
    uint8_t version_major;
    uint8_t version_minor;
    uint8_t version_patch;
    uint32_t layout_flash_size;
    uint8_t timestamp[8]; // utc time stamp of last update
    uint8_t git_hash[8]; // git hash of the firmware

    // supported connectivity features
    uint8_t wireless_support: 1;
    uint8_t i2c_support: 1;
    uint8_t unifying_support: 1;
    uint8_t usb_support: 1;
    uint8_t bt_support: 1;
    uint8_t _reserved0 : 3; // 1 byte

    // supported scanning features
    uint8_t scan_support: 1;
    uint8_t scan_col_row: 1;
    uint8_t scan_row_col: 1;
    uint8_t scan_pins: 1;
    uint8_t scan_arbitrary: 1;
    uint8_t scan_built_in: 1;
    uint8_t _reserved1 : 2; // 1 byte

    // generic keyboard features
    uint8_t kro_6_support: 1;
    uint8_t kro_n_support: 1;
    uint8_t _reserved2: 6; // 1 byte

    // keyhandler_support
    uint8_t key_media: 1;
    uint8_t key_mouse: 1;
    uint8_t key_layers: 1;
    uint8_t key_sticky: 1;
    uint8_t key_tap: 1;
    uint8_t key_hold: 1;
    uint8_t _reserved3: 2; // 1 byte

    // led_features
    uint8_t led_indicators: 1;
    uint8_t led_backlighting: 1;
    uint8_t led_ws2812: 1;
    uint8_t _reserved4: 5; // 1 byte

    uint16_t bootloader_vid;
    uint16_t bootloader_pid;

    uint8_t reserved[30]; // pad to 62 bytes
} firmware_build_settings_t;

#define GET_SETTING(x) (\
    ((ROM const settings_t *)SETTINGS_ADDR)->x \
)

AT__SETTINGS_ADDR extern const settings_t g_settings_storage;

extern XRAM rf_settings_t g_rf_settings;
extern XRAM runtime_settings_t g_runtime_settings;

extern const ROM firmware_build_settings_t g_firmware_build_settings;

void settings_load_from_flash(void);

uint8_t device_id_to_pipe_num(const uint8_t device_id);

void update_settings(void);
