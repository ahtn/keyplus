// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "usb_reports/keyboard_report.h"

#include <string.h>

#include "core/settings.h"
#include "core/matrix_interpret.h"
#include "core/mods.h"

#include "usb_reports/usb_reports.h"

#define KEY_AGE_LIST_LEN BOOT_REPORT_KEY_COUNT

// Boot keyboard report (6kro)
// TODO: put these into an init function
XRAM hid_report_boot_keyboard_t g_boot_keyboard_report;
XRAM hid_report_nkro_keyboard_t g_nkro_keyboard_report;
static XRAM uint8_t key_age[KEY_AGE_LIST_LEN];
static XRAM uint8_t s_keyboard_report_mode = KEYBOARD_REPORT_MODE_AUTO;
static XRAM uint8_t keyboard_report_dirty;
static bit_t boot_protocol = false;

#define MAX_NUMBER_RETRIGGER_KEYS 6
static XRAM uint8_t retrigger_list[MAX_NUMBER_RETRIGGER_KEYS];
static XRAM uint8_t retrigger_list_len;

void reset_keyboard_reports(void) {
    memset(key_age, 0, KEY_AGE_LIST_LEN);
    memset(&g_boot_keyboard_report, 0, sizeof(hid_report_boot_keyboard_t));
    memset(&g_nkro_keyboard_report, 0, sizeof(hid_report_nkro_keyboard_t));
    retrigger_list_len = 0;
    touch_keyboard_report();
}

void touch_keyboard_report(void) {
    keyboard_report_dirty = 1;
}

void set_keyboard_report_mode(uint8_t mode) {
    s_keyboard_report_mode = mode;
}

uint8_t get_keyboard_report_mode(void) {
    return s_keyboard_report_mode;
}

void set_keyboard_protocol(uint8_t proto) {
    clear_keyboard_report();
    if (proto == PROTOCOL_BOOT) {
        boot_protocol = true;
    } else if (proto == PROTOCOL_REPORT) {
        boot_protocol = false;
    }
}

uint8_t get_keyboard_protocol(void) {
    return (uint8_t)boot_protocol;
}

void nkro_add_keycode(uint8_t kc) {
    const uint8_t byte_offset = kc / 8;
    const uint8_t bit_offset = kc % 8;
    g_nkro_keyboard_report.bitmask[byte_offset] |= (1 << bit_offset);
}

void nkro_del_keycode(uint8_t kc) {
    const uint8_t byte_offset = kc / 8;
    const uint8_t bit_offset = kc % 8;
    g_nkro_keyboard_report.bitmask[byte_offset] &= ~(1 << bit_offset);
}

uint8_t is_boot_report_empty(void) {
    uint8_t i;
    for (i = 0; i < sizeof(hid_report_boot_keyboard_t); ++i) {
        if (((uint8_t*)&g_boot_keyboard_report)[i] != 0 ) {
            return false;
        }
    }
    return true;
}

// Add's a keycode to the boot keyboard report. If using 6kro mode, and more
// than 6 keys are pressed, then the 'oldest' key pressed is forgotten.
void boot_add_keycode(uint8_t kc) {
    uint8_t i;
    bool is_full;

    // looks for an empty slot in the report. Set kc=0 if it finds one.
    // adds +1 to the age of any other key in the report.
    for (i = 0; i < BOOT_REPORT_KEY_COUNT; ++i) {
        const uint8_t key_i = g_boot_keyboard_report.keys[i];
        if (key_i == 0 || (key_i == kc && kc != 0)) {
            g_boot_keyboard_report.keys[i] = kc;
            key_age[i] = 0;
            kc = 0; // make sure we don't set anything else
        } else {
            // all keycodes != 0 increase age
            key_age[i]++;
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
            if (key_age[i] > oldest_val) {
                oldest_val = key_age[i];
                oldest_i = i;
            }
        }
        g_boot_keyboard_report.keys[oldest_i] = kc;
        key_age[oldest_i] = 0;
    }
}

void boot_del_keycode(uint8_t kc) {
    uint8_t i;
    for (i = 0; i < BOOT_REPORT_KEY_COUNT; ++i) {
        const uint8_t key_i = g_boot_keyboard_report.keys[i];
        if (key_i == kc) {
            g_boot_keyboard_report.keys[i] = 0;
        }
        key_age[i]--;
    }
}

void add_keycode(uint8_t kc) {
    if (kc == 0) {
        return;
    }
    keyboard_report_dirty = 1;

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

void del_keycode(uint8_t kc) {
    if (kc == 0) {
        return;
    }
    keyboard_report_dirty = 1;
    if (s_keyboard_report_mode != KEYBOARD_REPORT_MODE_NKRO) {
        boot_del_keycode(kc);
    }
    nkro_del_keycode(kc);
}

void retrigger_keycode(uint8_t kc) {
    del_keycode(kc);
    if (retrigger_list_len < MAX_NUMBER_RETRIGGER_KEYS) {
        retrigger_list[retrigger_list_len] = kc;
        retrigger_list_len++;
    }
}

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

static void clear_boot_keyboard_report(void) {
    memset(&g_boot_keyboard_report, 0, sizeof(hid_report_boot_keyboard_t));
}

static void clear_nkro_keyboard_report(void) {
    memset(&g_nkro_keyboard_report, 0, sizeof(hid_report_nkro_keyboard_t));
}

void clear_keyboard_report(void) {
    keyboard_report_dirty = 1;
    clear_boot_keyboard_report();
    clear_nkro_keyboard_report();
}

bit_t send_keyboard_report(void) {
    uint8_t result = 0;

    // don't send the report if it hasn't changed
    if (!keyboard_report_dirty) {
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
        keyboard_report_dirty = 0;
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

bit_t is_ready_keyboard_report(void) {
    return is_ready_boot_keyboard_report() && is_ready_nkro_keyboard_report();
}

bit_t is_ready_boot_keyboard_report(void) {
    return is_in_endpoint_ready(EP_NUM_BOOT_KEYBOARD);
}

bit_t is_ready_nkro_keyboard_report(void) {
    return is_in_endpoint_ready(EP_NUM_NKRO_KEYBOARD);
}

bit_t send_boot_keyboard_report(void) {
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
}

bit_t send_nkro_keyboard_report(void) {
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
}
