// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)
/// @file
/// @brief 6KRO and NKRO USB reports

#include "hid_reports/keyboard_report.h"

#include <string.h>

#include "core/settings.h"
#include "core/matrix_interpret.h"
#include "core/mods.h"
#include "core/error.h"

#include "hid_reports/usb_reports.h"
#include "hid_reports/ble_reports.h"
#include "hid_reports/virtual_reports.h"

#define KEY_AGE_LIST_LEN BOOT_REPORT_KEY_COUNT

/// The 6KRO boot keyboard report
XRAM hid_report_boot_keyboard_t g_boot_keyboard_report;
/// The NKRO keyboard report
XRAM hid_report_nkro_keyboard_t g_nkro_keyboard_report;

static XRAM uint8_t s_key_age[KEY_AGE_LIST_LEN];
static XRAM uint8_t s_keyboard_report_mode;
static XRAM uint8_t s_keyboard_report_dirty;
static bit_t boot_protocol = false;

/// Maximum number of retrigger keys that can be queued
#define MAX_NUMBER_RETRIGGER_KEYS 6

/// The keys in the retrigger list
static XRAM uint8_t retrigger_list[MAX_NUMBER_RETRIGGER_KEYS];

/// The length of the retrigger list
static XRAM uint8_t retrigger_list_len;

/// @brief reset the keyboard reports to their start-up state.
void reset_keyboard_reports(void) {
    memset(s_key_age, 0, KEY_AGE_LIST_LEN);
    memset(&g_boot_keyboard_report, 0, sizeof(hid_report_boot_keyboard_t));
    memset(&g_nkro_keyboard_report, 0, sizeof(hid_report_nkro_keyboard_t));
    retrigger_list_len = 0;
    touch_keyboard_report();
#if SHARED_HID_DESCRIPTOR
    g_nkro_keyboard_report.report_id = REPORT_ID_NKRO;
#endif
    if (GET_SETTING(default_report_mode) <= KEYBOARD_REPORT_MODE_VALID) {
        set_keyboard_report_mode(GET_SETTING(default_report_mode));
    } else {
        set_keyboard_report_mode(KEYBOARD_REPORT_MODE_AUTO);
        register_error(ERROR_SETTINGS_INVALID_VALUE);
    }
}

/// @brief Mark the keyboard report as modified and needs an update.
///
/// If you modify the keyboard reports directly, then you need to mark them as
/// being update, so that send_keyboard_report() report knows that they have
/// changed.
void touch_keyboard_report(void) {
    s_keyboard_report_dirty = 1;
}

/// Set the active keyboard report mode.
///
/// @param mode the new keyboard report mode to use
void set_keyboard_report_mode(keyboard_report_mode_t mode) {
    s_keyboard_report_mode = mode;
}

/// Get the active keyboard report mode
///
/// @return A @ref keyboard_report_mode_t value corresponding to the current report mode.
uint8_t get_keyboard_report_mode(void) {
    return s_keyboard_report_mode;
}

/// Set the protocol for the NKRO report for the HID GET/SET_PROTOCOL feature
void set_keyboard_protocol(uint8_t proto) {
    clear_keyboard_report();
    if (proto == PROTOCOL_BOOT) {
        boot_protocol = true;
    } else if (proto == PROTOCOL_REPORT) {
        boot_protocol = false;
    }
}

/// Get the protocol for the NKRO report for the HID GET/SET_PROTOCOL feature
uint8_t get_keyboard_protocol(void) {
    return (uint8_t)boot_protocol;
}

/// Add a key to the NKRO report
void nkro_add_keycode(uint8_t kc) {
    const uint8_t byte_offset = kc / 8;
    const uint8_t bit_offset = kc % 8;
    g_nkro_keyboard_report.bitmask[byte_offset] |= (1 << bit_offset);
}

/// Delete a key from the NKRO report
void nkro_del_keycode(uint8_t kc) {
    const uint8_t byte_offset = kc / 8;
    const uint8_t bit_offset = kc % 8;
    g_nkro_keyboard_report.bitmask[byte_offset] &= ~(1 << bit_offset);
}

/// Checks if the 6KRO report is empty
uint8_t is_boot_report_empty(void) {
    uint8_t i;
    for (i = 0; i < sizeof(hid_report_boot_keyboard_t); ++i) {
        if (((uint8_t*)&g_boot_keyboard_report)[i] != 0 ) {
            return false;
        }
    }
    return true;
}

// @brief Add's a keycode to the boot keyboard report.
//
// If using 6kro mode, and more than 6 keys are pressed, then the 'oldest' key
// pressed is forgotten.
void boot_add_keycode(uint8_t kc) {
    uint8_t i;
    bool is_full;

    // looks for an empty slot in the report. Set kc=0 if it finds one.
    // adds +1 to the age of any other key in the report.
    for (i = 0; i < BOOT_REPORT_KEY_COUNT; ++i) {
        const uint8_t key_i = g_boot_keyboard_report.keys[i];
        if (key_i == 0 || (key_i == kc && kc != 0)) {
            g_boot_keyboard_report.keys[i] = kc;
            s_key_age[i] = 0;
            kc = 0; // make sure we don't set anything else
        } else {
            // all keycodes != 0 increase age
            s_key_age[i]++;
        }
    }

    is_full = (kc != 0);

    // Upgrade to nkro mode if using KEYBOARD_REPORT_MODE_AUTO.
    if (is_full && s_keyboard_report_mode == KEYBOARD_REPORT_MODE_AUTO) {
        s_keyboard_report_mode = KEYBOARD_REPORT_MODE_UPGRADE;
        return;
    }

    // if kc != 0, then report is full. Find oldest key, and replace it.
    if (is_full && s_keyboard_report_mode == KEYBOARD_REPORT_MODE_6KRO) {
        uint8_t oldest_val = 0;
        uint8_t oldest_i = 0;
        for (i = 0; i < BOOT_REPORT_KEY_COUNT; ++i) {
            if (s_key_age[i] > oldest_val) {
                oldest_val = s_key_age[i];
                oldest_i = i;
            }
        }
        g_boot_keyboard_report.keys[oldest_i] = kc;
        s_key_age[oldest_i] = 0;
    }
}

/// Delete a key from the 6KRO report
void boot_del_keycode(uint8_t kc) {
    uint8_t i;
    for (i = 0; i < BOOT_REPORT_KEY_COUNT; ++i) {
        const uint8_t key_i = g_boot_keyboard_report.keys[i];
        if (key_i == kc) {
            g_boot_keyboard_report.keys[i] = 0;
        }
        s_key_age[i]--;
    }
}

/// @brief Add a key to the keyboard report.
void add_keycode(uint8_t kc) {
    if (kc == 0) {
        return;
    }
    s_keyboard_report_dirty = 1;

    if (s_keyboard_report_mode == KEYBOARD_REPORT_MODE_6KRO ||
            s_keyboard_report_mode == KEYBOARD_REPORT_MODE_AUTO) {
        boot_add_keycode(kc);
        // if 6 keys were pressed, we will now be in upgrade mode
        // and should add the keycode to the nkro report instead
        if (s_keyboard_report_mode == KEYBOARD_REPORT_MODE_UPGRADE) {
            nkro_add_keycode(kc);
        }
    } else {
        nkro_add_keycode(kc);
    }
}

/// @brief Delete a from the keyboard report.
void del_keycode(uint8_t kc) {
    if (kc == 0) {
        return;
    }
    s_keyboard_report_dirty = 1;
    if (s_keyboard_report_mode != KEYBOARD_REPORT_MODE_NKRO) {
        boot_del_keycode(kc);
    }
    nkro_del_keycode(kc);
}

/// Resend a key that is already pressed.
///
/// If a key is already pressed in the current keyboard report, release it and
/// then add it again so that the host will see a new key press be generated.
void retrigger_keycode(uint8_t kc) {
    del_keycode(kc);
    if (retrigger_list_len < MAX_NUMBER_RETRIGGER_KEYS) {
        retrigger_list[retrigger_list_len] = kc;
        retrigger_list_len++;
    }
}

/// Checks if a key is pressed in the USB report.
///
/// @retval true The key is pressed in the active keyboard report.
/// @retval false The key is released in the active keyboard report.
bool has_keycode(uint8_t kc) {
    if (s_keyboard_report_mode == KEYBOARD_REPORT_MODE_NKRO) {
        const uint8_t byte_offset = kc / 8;
        const uint8_t bit_offset = kc % 8;
        return g_nkro_keyboard_report.bitmask[byte_offset] & (1 << bit_offset);
    } else { // slight
        uint8_t i;
        for (i = 0; i < BOOT_REPORT_KEY_COUNT; ++i) {
            if (g_boot_keyboard_report.keys[i] == kc) {
                return true;
            }
        }
        return false;
    }
}

/// Remove all keys from the 6KRO keyboard report.
static void clear_boot_keyboard_report(void) {
    memset(&g_boot_keyboard_report, 0, sizeof(hid_report_boot_keyboard_t));
}

/// Remove all keys from the NKRO keyboard report.
static void clear_nkro_keyboard_report(void) {
#if SHARED_HID_DESCRIPTOR
    // Don't clear the report id
    memset(
        ((uint8_t*)&g_nkro_keyboard_report)+1,
        0,
        sizeof(hid_report_nkro_keyboard_t)-1
    );
#else
    memset(&g_nkro_keyboard_report, 0, sizeof(hid_report_nkro_keyboard_t));
#endif
}

/// Remove all keys from the keyboard reports.
void clear_keyboard_report(void) {
    s_keyboard_report_dirty = 1;
    clear_boot_keyboard_report();
    clear_nkro_keyboard_report();
}

/// @brief Send any pending keyboard reports.
///
/// This function combines the 6KRO and NKRO reports into one keyboard report.
/// It will select the correct report based on the current report mode.
///
/// If the report has not changed, no data will be sent.
///
/// @retval true A keyboard report is ready but could not be sent and was left pending.
/// @retval false There is no keyboard report left pending.
bit_t send_keyboard_report(void) {
    uint8_t result = 0;

    // don't send the report if it hasn't changed
    if (!s_keyboard_report_dirty) {
        return result;
    }

    switch (s_keyboard_report_mode) {

        case KEYBOARD_REPORT_MODE_AUTO:
        case KEYBOARD_REPORT_MODE_6KRO: {
            result = send_boot_keyboard_report();
        } break;

        case KEYBOARD_REPORT_MODE_UPGRADE: {
            // transitioning from boot report to nkro report
            result |= send_nkro_keyboard_report();
            result |= send_boot_keyboard_report();
            if (is_boot_report_empty()) {
                s_keyboard_report_mode = KEYBOARD_REPORT_MODE_NKRO;
            }
        } break;

        case KEYBOARD_REPORT_MODE_NKRO: {
            result = send_nkro_keyboard_report();
        } break;
    }

    if (result == 0) {
        s_keyboard_report_dirty = 0;
        if (retrigger_list_len) {
            uint8_t i;
            for (i = 0; i < retrigger_list_len; ++i) {
                add_keycode(retrigger_list[i]);
            }
            retrigger_list_len = 0;
        }
    }

    return result;
}

#if USE_USB
/// Check if a keyboard report is ready to be sent.
bit_t is_ready_keyboard_report(void) {
    return is_ready_boot_keyboard_report() && is_ready_nkro_keyboard_report();
}

/// Check if the 6KRO endpoint is ready for more data
bit_t is_ready_boot_keyboard_report(void) {
    return is_in_endpoint_ready(EP_NUM_BOOT_KEYBOARD);
}

/// Check if the NKRO endpoint is ready for more data
bit_t is_ready_nkro_keyboard_report(void) {
    return is_in_endpoint_ready(EP_NUM_NKRO_KEYBOARD);
}
#endif

/// Sends the 6KRO report over its USB endpoint
bit_t send_boot_keyboard_report(void) {
#if USE_VIRTUAL_MODE
    kp_virtual_hid_boot_keyboard_report_send();
    return false;
#endif

#if USE_BLUETOOTH
    if (g_runtime_settings.mode == TRANS_MODE_BLE) {
        kp_ble_hids_input_report_send(
            BLE_INPUT_REPORT_INDEX_BOOT_KB,
            sizeof(hid_report_boot_keyboard_t),
            (uint8_t*)&g_boot_keyboard_report
        );
        return false;
    }
#endif

#if USE_USB
    if (is_ready_boot_keyboard_report()) {
        uint8_t report_size = sizeof(hid_report_boot_keyboard_t);

        usb_write_in_endpoint(
            EP_NUM_BOOT_KEYBOARD,
            (uint8_t*)&g_boot_keyboard_report,
            report_size
        );

        return false;
    } else {
        return true;
    }
#endif
}

/// Sends the NKRO report over its USB endpoint
bit_t send_nkro_keyboard_report(void) {
#if USE_VIRTUAL_MODE
    kp_virtual_hid_nkro_keyboard_report_send();
    return false;
#endif

#if USE_BLUETOOTH
    if (g_runtime_settings.mode == TRANS_MODE_BLE) {
        kp_ble_hids_input_report_send(
            BLE_INPUT_REPORT_INDEX_NKRO,
            sizeof(hid_report_nkro_keyboard_t),
            (uint8_t*)&g_nkro_keyboard_report
        );
        return false;
    }
#endif


#if USE_USB
    if (is_ready_nkro_keyboard_report()) {
        uint8_t report_size = sizeof(hid_report_nkro_keyboard_t);

        usb_write_in_endpoint(
            EP_NUM_NKRO_KEYBOARD,
            (uint8_t*)&g_nkro_keyboard_report,
            report_size
        );

        return false;
    } else {
        return true;
    }
#endif
}
