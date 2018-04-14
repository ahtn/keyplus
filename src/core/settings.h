// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)
/// @file core/settings.h

#pragma once

#include <stdint.h>
#include <stddef.h>

#include "core/chip_id.h"
#include "core/flash.h"
#include "core/matrix_scanner.h"
#include "core/nrf24.h"
#include "core/packet.h"
#include "core/util.h"

#define NUM_KEYBOARD_PIPES 4

#define NRF_ADDR_LEN 5
#define AES_KEY_LEN 16

#define UNPROGRAMMED_DEVIE_ID 0xff

#define MAX_NUM_KEYBOARDS 64
#define MAX_NUM_DEVICES 64

/// Values used for setting the keyboard report mode.
enum {
    KEYBOARD_REPORT_MODE_AUTO = 0, /// 6KRO -> NKRO if more than 6 keys pressed
    KEYBOARD_REPORT_MODE_NKRO = 1, /// NKRO
    KEYBOARD_REPORT_MODE_6KRO = 2, /// 6KRO
    KEYBOARD_REPORT_MODE_UPGRADE, /// transitioning 6KRO -> NKRO
};

#define LAYOUT_ID_NONE 0xfe
#define LAYOUT_ID_INVALID 0xff

/// Contains information on device mapping
typedef struct device_info_t {
    /// the keyboard layout that this device maps to
    uint8_t layout_id;
    /// the component byte offset into the given keyboard
    uint8_t matrix_offset;
    /// the size of this component == ceil(rows*cols/8)
    /// TODO: Change this to a key number value
    uint8_t matrix_size;
} device_info_t;

// TODO: maybe move layout and settings to start of layout_storage
/// Contains information on layout mapping
typedef struct layout_info_t {
    // TODO: change this to a key number value
    // TODO: maybe store in layout section
    /// The size of one layer in the matrix.
    uint8_t matrix_size;
    // TODO: maybe store in layout section
    /// The number of layers in the matrix
    uint8_t layer_count;
} keyboard_info_t;

#define SETTINGS_LAYOUT_INFO_HEADER_SIZE 32
#define SETTINGS_LAYOUT_INFO_OFFSET (offsetof(settings_t, layout))
/// The device and layout tables. This table is used by the device to lookup
/// various settings about the layouts and devices in use.
/// TODO: maybe move some of these settings to the layout section?
typedef struct {
    uint8_t number_layouts;
    uint8_t number_devices;
    uint8_t _reserved[30]; // 32
    keyboard_info_t layouts[MAX_NUM_KEYBOARDS];
    device_info_t devices[MAX_NUM_DEVICES];
} layout_settings_t;

#define SETTINGS_RF_INFO_SIZE 64
#define SETTINGS_RF_INFO_HEADER_SIZE (SETTINGS_RF_INFO_SIZE - AES_KEY_LEN*2)
#define SETTINGS_RF_INFO_OFFSET (offsetof(settings_t, rf))
/// The RF settings used for wireless communication
typedef struct rf_settings_t { // 64 bytes
    /// The pipe0 for nRF24/nrf_esb
    uint8_t pipe_addr_0[NRF_ADDR_LEN];
    /// The pipe1 for nRF24/nrf_esb
    uint8_t pipe_addr_1[NRF_ADDR_LEN];
    /// The pipe2 for nRF24/nrf_esb
    uint8_t pipe_addr_2;
    /// The pipe3 for nRF24/nrf_esb
    uint8_t pipe_addr_3;
    /// The pipe4 for nRF24/nrf_esb (Should be set to 0 for unifying mouse support)
    uint8_t pipe_addr_4;
    /// The pipe5 for nRF24/nrf_esb (Used for connecting a unifying mouse)
    uint8_t pipe_addr_5;
    /// The RF channle for nRF24/nrf_esb communications
    uint8_t channel; // TODO: when using unifying, channel must be ((ch+2)%3 == 0)
                     // this should be enforced somewhere
    /// The automatic retransmit count for packets in the nRF24/rnf_esb protocol.
    uint8_t arc;
    /// The data rate for the nRF24/nrf_esb protocol.
    uint8_t data_rate;
    /// The transmit power for the  nRF24/rnf_esb protocol.
    uint8_t power;
    /// These bytes are reserved for future use.
    uint8_t _reserved[14]; // padding
    /// The AES-128 encryption key used for nRF24/nrf_esb packets.
    uint8_t ekey[AES_KEY_LEN];
    /// The AES-128 decryption key used for nRF24/nrf_esb packets.
    ///
    /// Note: AES is a symmetric encryption algorithm, and so the same key
    /// can be used for both encryption and decryption. However, the hardware
    /// AES peripherals used need to have the final round keys used in the
    /// AES to perform decryption. The round keys can be derived from the
    /// encryption keys. However, the algorithm needed to generate this data
    /// is rather large, so instead the round keys are generated at the
    /// same time as the encryption key in the host software and stored here
    /// as the 'decryption' key. To see how the round keys are generated
    /// in the host software check `@ref host-software/keyplus/utility/round_keys.py`.
    ///
    /// https://en.wikipedia.org/wiki/Rijndael_key_schedule
    uint8_t dkey[AES_KEY_LEN];
} rf_settings_t;

#define FEATURE_CTRL_USB_DISABLE      (1 << 0)
#define FEATURE_CTRL_WIRED_DISABLE    (1 << 1)
#define FEATURE_CTRL_RF_DISABLE       (1 << 2)
#define FEATURE_CTRL_RF_MOUSE_DISABLE (1 << 3)
#define FEATURE_CTRL_BT_DISABLE       (1 << 4)
#define FEATURE_CTRL_RESERVED_0       (1 << 5)
#define FEATURE_CTRL_RESERVED_1       (1 << 6)
#define FEATURE_CTRL_RESERVED_2       (1 << 7)

#define FEATURE_CTRL_FEATURES_DISABLED_AT_BUILD_TIME \
    (!USE_USB << 0) | \
    (!USE_I2C << 1) | \
    (!USE_NRF24 << 2) | \
    (!USE_UNIFYING << 3) | \
    (!USE_BLUETOOTH << 4)

/// Used to enable/disable hardware features
typedef struct feature_ctrl_t {
    uint8_t usb_disabled: 1;
    uint8_t wired_disabled: 1;
    uint8_t rf_disabled: 1;
    uint8_t rf_mouse_disabled: 1;
    uint8_t bt_disabled: 1;
    uint8_t reserved_0: 1;
    uint8_t reserved_1: 1;
    uint8_t reserved_2: 1;
} feature_ctrl_t;

#define SETTINGS_MAIN_INFO_SIZE 96
/// The settings stored in flash to control this device.
typedef struct settings_t { // 512 bytes
    /// The unique id identifying this device for split keyboard transactions
    uint8_t device_id;
    /// The name of this device. This name will show up when the device is
    /// plugged in via USB.
    /// TODO: Change this string to use UTF-16LE encoding. Also, to make it
    /// easier for devices to use this string in USB descriptors, encode it
    /// in exactly the same way it will be used by the device for USB reports.
    /// This way the device doesn't need to worry about loading it into RAM
    /// before it can be used. Since UFT-16LE encoding needs a minimum of
    /// 2 bytes per a code point, it will probably be good to enlarge this
    /// array slightly.
    char device_name[32];
    /// UTC time stamp of when the settings where last updated.
    uint8_t timestamp[8];
    /// The default keyboard report mode.
    uint8_t default_report_mode;
    /// The matrix scanning settings for this device.
    /// TODO/NOTE: maybe this should be moved to the start of the layout section?
    matrix_scan_plan_t scan_plan; // 11 bytes
    /// These bytes are reserved for future use.
    uint8_t _reserved0[8];
    /// Used to enable/disable hardware features like nRF24 wireless/split I2C
    uint8_t feature_ctrl;
    /// These bytes are reserved for future use.
    uint8_t _reserved1[32];
    /// The CRC over this the previous 94 bytes
    uint16_t crc; // size == 96
    /// The layout settings for the devices
    layout_settings_t layout; // size == 352
    /// The RF settings for this device
    rf_settings_t rf; // size == 64
} settings_t;

/// Settings that are loaded from flash and/or changeable at run time
typedef struct runtime_settings_t {
    uint8_t device_id;
    union {
        uint8_t ctrl_raw;
        feature_ctrl_t ctrl;
    } feature;
} runtime_settings_t;

/*********************************************************************
 *                      firmware build settings                      *
 *********************************************************************/
/// Information and features of the firmware. This features are baked in at
/// compile time and can be used by the host software to discover what
/// capabilities the firmware supports.
typedef struct firmware_build_settings_t {
    /// The major version number
    uint8_t version_major;
    /// The minor version number
    uint8_t version_minor;
    /// The minor version number
    uint8_t version_patch;
    /// How much storage space the device has for storing layouts.
    uint32_t layout_flash_size;
    /// UTC time stamp of when the firmware was compiled
    uint8_t timestamp[8];
    /// The git hash used when compiling the firmware
    uint8_t git_hash[8];
    /// True if the device was compiled with nRF24 support
    uint8_t nrf24_support: 1;
    /// True if the device was compiled with I²C support
    uint8_t i2c_support: 1;
    /// True if the device was compiled with Unifying mouse support
    uint8_t unifying_support: 1;
    /// True if the device was compiled with USB support
    uint8_t usb_support: 1;
    /// True if the device was compiled with Bluetooth support
    /// TODO/Note: store bluetooth capabilities in a separate block
    uint8_t bt_support: 1;
    uint8_t _reserved0 : 3; // 1 byte

    // supported scanning features
    /// True if the device supports has a key matrix of any kind
    uint8_t scan_support: 1;
    /// True if the device supports matrix scanning with col to row diodes
    uint8_t scan_col_row: 1;
    /// True if the device supports matrix scanning with row to col diodes
    uint8_t scan_row_col: 1;
    uint8_t scan_pins: 1;
    uint8_t scan_arbitrary: 1;
    /// True if the device has a built-in scanning method that can't be changed
    uint8_t scan_built_in: 1;
    uint8_t _reserved1 : 2; // 1 byte

    // generic keyboard features
    /// True if the device supports 6KRO keyboard reports
    uint8_t kro_6_support: 1;
    /// True if the device supports NKRO keyboard reports
    uint8_t kro_n_support: 1;
    uint8_t _reserved2: 6; // 1 byte

    // keyhandler_support
    /// True if the device supports media keycodes
    uint8_t key_media: 1;
    /// True if the device supports mouse keycodes
    uint8_t key_mouse: 1;
    // TODO: As a minimum should probably always build with support for layer
    // keycodes? So removed this?
    /// True if the device supports layer keycodes
    uint8_t key_layers: 1;
    /// True if the device supports sticky keys
    uint8_t key_sticky: 1;
    /// True if the device supports tap keys
    uint8_t key_tap: 1;
    /// True if the device supports hold keys
    uint8_t key_hold: 1;
    uint8_t _reserved3: 2; // 1 byte

    // led_features
    /// True if the device supports indicator LEDs
    uint8_t led_indicators: 1;
    /// True if the device supports LED backlighting
    uint8_t led_backlighting: 1;
    /// True if the device supports ws2812b LEDs
    uint8_t led_ws2812: 1;
    uint8_t _reserved4: 5; // 1 byte

    // offset 28
    /// The USB VID of this devices bootloader. If the VID:PID values for
    /// the bootloader are both set to zero, then the device does not have
    /// a USB bootloader.
    uint16_t bootloader_vid;
    uint16_t bootloader_pid;

    // offset 32
    /// A keyplus specific ID that uniquely identifies the MCU used by the
    /// device. See `@ref src/core/chip_id.h`
    uint32_t chip_id;
    // offset 36
    // TODO: maybe this should be firmware_id instead?
    /// A unique ID identifying the board this firmware was compiled for.
    uint16_t board_id;
    // offset 38
    /// Internal matrix scanning method used by the device. This field
    /// tells the host what format to use for the pin map in the layout section.
    uint8_t internal_scan_method;

    // offset 39
    /// Page size used when writing to layout and data sections
    uint8_t page_size;

    // offset 40
    /// Maximum number of rows supported by the firmware. Some devices my set
    /// this value lower to conserve RAM.
    uint8_t scanner_max_rows;

    uint8_t reserved[21]; // pad to 62 bytes
} firmware_build_settings_t;

/// Lookup a setting from the devices settings table in flash.
#define GET_SETTING(field) (\
    ((ROM const settings_t *)SETTINGS_ADDR)->field \
)

AT__SETTINGS_ADDR extern const settings_t g_settings_storage;

extern XRAM rf_settings_t g_rf_settings;
extern XRAM runtime_settings_t g_runtime_settings;

extern const ROM firmware_build_settings_t g_firmware_build_settings;

/// Read settings from flash, validate the settings and copy any necessary
/// values to RAM.
void settings_load_from_flash(void);

void update_settings(void);
