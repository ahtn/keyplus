// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

/// Refrences:
/// https://lekensteyn.nl/files/logitech/logitech_hidpp_2.0_specification_draft_2012-06-04.pdf
/// https://lekensteyn.nl/files/logitech/

#pragma once

typedef struct hidpp20_packet_long_t {
    uint8_t report_type; //< short (0x10) or long (0x11)
    uint8_t device_index;
    uint8_t feature_index;
    uint8_t software_id : 4;
    uint8_t function_id : 4;
    uint8_t parameters[16];
} hidpp20_packet_long_t;


// Error packet example:
// Request =>
// 00000000: 00 10 01 F5 00 00 00 00  00 FA                    ..........
//
// Response =>
// 00000000: 00 51 01 FF F5 00 06 00  00 00 00 00 00 00 00 00  .Q..............
// 00000010: 00 00 00 00 00 B4                                 ......
typedef struct hidpp20_packet_error_t {
    uint8_t report_type; //< short (0x10) or long (0x11)
    uint8_t device_index;
    uint8_t feature_index; //< HIDPP20_FEATURE_ERROR == 0xff
    uint8_t failed_feature_index;
    uint8_t software_id : 4;
    uint8_t function_id : 4;
    uint8_t error_code;
    uint8_t parameters[14];
} hidpp20_packet_error_t;


typedef enum hidpp20_features_t {
    HIDPP20_ROOT_INDEX = 0x00,
    HIDPP20_ERROR_INDEX = 0xFF,

    HIDPP20_ROOT                   = 0x0000,
    HIDPP20_FEATURE_SET            = 0x0001,
    HIDPP20_FEATURE_INFO           = 0x0002,
    HIDPP20_DEVICE_FW_VERSION      = 0x0003,
    HIDPP20_DEVICE_NAME            = 0x0005,
    HIDPP20_DEVICE_GROUPS          = 0x0006,
    HIDPP20_RESET                  = 0x0020,
    HIDPP20_CRYPTO_ID              = 0x0021,
    HIDPP20_DFUCONTROL             = 0x00C0,
    HIDPP20_DFUCONTROL_2           = 0x00C1,
    HIDPP20_DFUCONTROL_3           = 0x00C2,
    HIDPP20_DFU                    = 0x00D0,
    HIDPP20_BATTERY_STATUS         = 0x1000,
    HIDPP20_LED_CONTROL            = 0x1300,
    HIDPP20_CHANGE_HOST            = 0x1814,
    HIDPP20_HOST_CAPABILITIES      = 0x1815,
    HIDPP20_BACKLIGHT              = 0x1981,
    HIDPP20_REPROG_CONTROLS        = 0x1B00,
    HIDPP20_REPROG_CONTROLS_V2     = 0x1B01,
    HIDPP20_REPROG_CONTROLS_V2_2   = 0x1B02,
    HIDPP20_REPROG_CONTROLS_V3     = 0x1B03,
    HIDPP20_REPROG_CONTROLS_V4     = 0x1B04,
    HIDPP20_WIRELESS_DEVICE_STATUS = 0x1D4B,
    HIDPP20_LEFT_RIGHT_SWAP        = 0x2001,
    HIDPP20_SWAP_BUTTON            = 0x2005,
    HIDPP20_VERTICAL_SCROLLING     = 0x2100,
    HIDPP20_SMART_SHIFT            = 0x2110,
    HIDPP20_HI_RES_SCROLLING       = 0x2120,
    HIDPP20_HIRES_WHEEL            = 0x2121,
    HIDPP20_LOWRES_WHEEL           = 0x2130,
    HIDPP20_MOUSE_POINTER          = 0x2200,
    HIDPP20_ADJUSTABLE_DPI         = 0x2201,
    HIDPP20_POINTER_SPEED          = 0x2205,
    HIDPP20_ANGLE_SNAPPING         = 0x2230,
    HIDPP20_SURFACE_TUNING         = 0x2240,
    HIDPP20_HYBRID_TRACKING        = 0x2400,
    HIDPP20_FN_INVERSION           = 0x40A0,
    HIDPP20_NEW_FN_INVERSION       = 0x40A2,
    HIDPP20_NEW_FN_INVERSION_2     = 0x40A3,
    HIDPP20_K375S_FN_INVERSION     = 0x40A3,
    HIDPP20_ENCRYPTION             = 0x4100,
    HIDPP20_LOCK_KEY_STATE         = 0x4220,
    HIDPP20_SOLAR_DASHBOARD        = 0x4301,
    HIDPP20_KEYBOARD_LAYOUT        = 0x4520,
    HIDPP20_KEYBOARD_DISABLE       = 0x4521,
    HIDPP20_DUALPLATFORM           = 0x4530,
    HIDPP20_KEYBOARD_LAYOUT_2      = 0x4540,
    HIDPP20_TOUCHPAD_FW_ITEMS      = 0x6010,
    HIDPP20_TOUCHPAD_SW_ITEMS      = 0x6011,
    HIDPP20_TOUCHPAD_WIN8_FW_ITEMS = 0x6012,
    HIDPP20_TOUCHPAD_RAW_XY        = 0x6100,
    HIDPP20_TOUCHMOUSE_RAW_POINTS  = 0x6110,
    HIDPP20_TOUCHMOUSE_6120        = 0x6120,
    HIDPP20_GESTURE                = 0x6500,
    HIDPP20_GESTURE_2              = 0x6501,
    HIDPP20_GKEY                   = 0x8010,
    HIDPP20_MKEYS                  = 0x8020,
    HIDPP20_MR                     = 0x8030,
    HIDPP20_REPORT_RATE            = 0x8060,
    HIDPP20_COLOR_LED_EFECTS       = 0x8070,
    HIDPP20_PER_KEY_LIGHTING       = 0x8080,
    HIDPP20_ONBOARD_PROFILES       = 0x8100,
    HIDPP20_MOUSE_BUTTON_SPY       = 0x8110,

    // Unknown/documented features
    HIDPP20_FEATURE_0007 = 0x0007,
    HIDPP20_FEATURE_1E22 = 0x1E22,
    HIDPP20_FEATURE_1802 = 0x1802, // (hidden, internal)
    HIDPP20_FEATURE_1803 = 0x1803, // (hidden, internal)
    HIDPP20_FEATURE_1806 = 0x1806, // (hidden, internal)
    HIDPP20_FEATURE_1805 = 0x1805, // (hidden, internal)
    HIDPP20_FEATURE_1813 = 0x1813, // (hidden, internal)
    HIDPP20_FEATURE_1861 = 0x1861, // (hidden, internal)
    HIDPP20_FEATURE_1890 = 0x1890, // (hidden, internal)
    HIDPP20_FEATURE_1891 = 0x1891, // (hidden, internal)
    HIDPP20_FEATURE_18B1 = 0x18B1, // (hidden, internal)
    HIDPP20_FEATURE_1850 = 0x1850, // (hidden, internal)
    HIDPP20_FEATURE_1DF3 = 0x1DF3, // (hidden, internal)
    HIDPP20_FEATURE_1E00 = 0x1E00, // (hidden)
    HIDPP20_FEATURE_1EB0 = 0x1EB0, // (hidden, internal)
    HIDPP20_FEATURE_1F03 = 0x1F03, // (hidden, internal)
} hidpp20_features_t;

// Function ids for IRoot feature
typedef enum HIDPP20_IRoot_t {
    HIDPP20_IRoot_GetFeature = 0,
    HIDPP20_IRoot_Ping = 1,
} HIDPP20_IRoot_t ;

// Function ids for IFeatureSet feature
typedef enum HIDPP20_IFeatureSet_t {
    HIDPP20_IFeatureSet_GetCount = 0,
    HIDPP20_IFeatureSet_GetFeatureID = 1,
} HIDPP20_IFeatureSet_t;

// Function ids for IFirmwareInfo feature
typedef enum HIDPP20_IFirmwareInfo_t {
    HIDPP20_IFirmwareInfo_GetEntityCount = 0,
    HIDPP20_IFirmwareInfo_GetFwInfo = 1,
} HIDPP20_IFirmwareInfo_t;

// Function ids for GetDeviceNameType feature
typedef enum HIDPP20_GetDeviceNameType_t {
    HIDPP20_GetDeviceNameType_GetCount = 0,
    HIDPP20_GetDeviceNameType_GetDeviceName = 1,
    HIDPP20_GetDeviceNameType_GetDeviceType = 2,
} HIDPP20_GetDeviceNameType_t;

// Function ids for BatteryLevelStatus feature
typedef enum HIDPP20_BatteryLevelStatus_t {
    HIDPP20_BatteryLevelStatus_GetBatteryLevelStatus = 0,
    HIDPP20_BatteryLevelStatus_GetBatteryCapability = 1,

    HIDPP20_BatteryLevelStatus_BatteryLevelStatusBroadcastEvent = 0,
} HIDPP20_BatteryLevelStatus_t;

// Function ids for SpecialKeysMSEButtons feature
typedef enum HIDPP20_SpecialKeysMSEButtons_t {
    HIDPP20_SpecialKeysMSEButtons_GetCount = 0,
    HIDPP20_SpecialKeysMSEButtons_GetCidInfo = 1,
    HIDPP20_SpecialKeysMSEButtons_GetCidReporting = 2,
    HIDPP20_SpecialKeysMSEButtons_SetCidReporting = 3,

    HIDPP20_SpecialKeysMSEButtons_DivertedButtonsEvent = 0,
    HIDPP20_SpecialKeysMSEButtons_DivertedRawMouseEvent = 1,
} HIDPP20_SpecialKeysMSEButtons_t;

typedef enum HIDPP20_ControlIDs_t {
    HIDPP20_CID_NONE              = 0x0000,

    HIDPP20_CID_VOLUME_UP         = 0x0001,
    HIDPP20_CID_VOLUME_DOWN       = 0x0002,
    HIDPP20_CID_MUTE              = 0x0003,
    HIDPP20_CID_PLAY_PAUSE        = 0x0004,
    HIDPP20_CID_NEXT              = 0x0005,
    HIDPP20_CID_PREVIOUS          = 0x0006,
    HIDPP20_CID_STOP              = 0x0007,

    HIDPP20_CID_LEFT_MSB          = 0x0050,
    HIDPP20_CID_RIGHT_MSB         = 0x0051,
    HIDPP20_CID_MIDDLE_MSB        = 0x0052,
    HIDPP20_CID_BACK              = 0x0053,
    HIDPP20_CID_FORWARD           = 0x0056,
    HIDPP20_CID_SCROLL_LEFT       = 0x005B,
    HIDPP20_CID_SCROLL_RIGHT      = 0x005D,

    HIDPP20_CID_GESTURE           = 0x00D0,
    HIDPP20_CID_TOGGLE_RF_CHANNEL = 0x00D7,
} HIDPP20_ControlIDs_t;

// Function ids for IOnboardProfiles
typedef enum HIDPP20_IOnboardProfiles_t {
    HIDPP20_IOnboardProfiles_GetDescription = 0,
    HIDPP20_IOnboardProfiles_SetMode = 1,
    HIDPP20_IOnboardProfiles_GetMode = 2,
    HIDPP20_IOnboardProfiles_SetCurrentProfile = 3,
    HIDPP20_IOnboardProfiles_GetCurrentProfile = 4,
    HIDPP20_IOnboardProfiles_MemoryRead = 5,
    HIDPP20_IOnboardProfiles_MemoryAddrWrite = 6,
    HIDPP20_IOnboardProfiles_MemoryWrite = 7,
    HIDPP20_IOnboardProfiles_MemoryWriteEnd = 8,
    HIDPP20_IOnboardProfiles_GetCurrentDPIIndex = 11,
    HIDPP20_IOnboardProfiles_SetCurrentDPIIndex = 12,

    HIDPP20_IOnboardProfiles_CurrentProfileChanged = 0,
    HIDPP20_IOnboardProfiles_CurrentDPIIndexChanged = 1,
} HIDPP20_IOnboardProfiles_t;

typedef enum HIDPP20_DeviceType_t {
    HIDPP20_Keyboard      = 1,
    HIDPP20_RemoteControl = 2,
    HIDPP20_Numpad        = 3,
    HIDPP20_Mouse         = 4,
    HIDPP20_Touchpad      = 5,
    HIDPP20_Trackball     = 6,
    HIDPP20_Presenter     = 7,
} HIDPP20_DeviceType_t;

typedef enum hidpp20_error_codes_t {
    HIDPP20_NO_ERROR              = 0,
    HIDPP20_UNKNOWN               = 1,
    HIDPP20_INVALID_ARGUMENT      = 2,
    HIDPP20_OUT_OF_RANGE          = 3,
    HIDPP20_HW_ERROR              = 4,
    HIDPP20_LOGITECH_INTERNAL     = 5,
    HIDPP20_INVALID_FEATURE_INDEX = 6,
    HIDPP20_INVALID_FUNCTION_ID   = 7,
    HIDPP20_BUSY                  = 8,
    HIDPP20_UNSUPPORTED           = 9,
} hidpp20_error_codes_t;
