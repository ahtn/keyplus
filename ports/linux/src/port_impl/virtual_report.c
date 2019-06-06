// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "hid_reports/virtual_reports.h"

#include <string.h>

#include "hid_reports/hid_reports.h"
#include "debug.h"
#include "virtual_input.h"
#include "hid_to_ev.h"
#include "core/keycode.h"

static hid_report_boot_keyboard_t s_last_boot_report;
static hid_report_nkro_keyboard_t s_last_nkro_report;
static hid_report_mouse_t s_last_mouse_report;
static uint8_t s_last_report_id;
static uint16_t s_last_system;
static uint16_t s_last_consumer;

void kp_virtual_hid_reports_reset(void) {
    memset(&s_last_boot_report, 0, sizeof(s_last_boot_report));
    memset(&s_last_nkro_report, 0, sizeof(s_last_nkro_report));
    memset(&s_last_mouse_report, 0, sizeof(s_last_mouse_report));
    s_last_report_id = 0;
    s_last_system = 0;
    s_last_consumer = 0;
}

static int handle_mods(uint8_t old_mods, uint8_t new_mods) {
    uint8_t updated = 0;
    uint8_t changed_mods = old_mods ^ new_mods;

    if (changed_mods) {
        updated = 1;

        if (changed_mods & MOD_LCTL) {
            const int value = (new_mods & MOD_LCTL) ? 1 : 0;
            kp_virtual_keyboard_send(EV_KEY, KEY_LEFTCTRL, value);
        }
        if (changed_mods & MOD_LSFT) {
            const int value = (new_mods & MOD_LSFT) ? 1 : 0;
            kp_virtual_keyboard_send(EV_KEY, KEY_LEFTSHIFT, value);
        }
        if (changed_mods & MOD_LALT) {
            const int value = (new_mods & MOD_LALT) ? 1 : 0;
            kp_virtual_keyboard_send(EV_KEY, KEY_LEFTALT, value);
        }
        if (changed_mods & MOD_LGUI) {
            const int value = (new_mods & MOD_LGUI) ? 1 : 0;
            kp_virtual_keyboard_send(EV_KEY, KEY_LEFTMETA, value);
        }
        if (changed_mods & MOD_RCTL) {
            const int value = (new_mods & MOD_RCTL) ? 1 : 0;
            kp_virtual_keyboard_send(EV_KEY, KEY_RIGHTCTRL, value);
        }
        if (changed_mods & MOD_RSFT) {
            const int value = (new_mods & MOD_RSFT) ? 1 : 0;
            kp_virtual_keyboard_send(EV_KEY, KEY_RIGHTSHIFT, value);
        }
        if (changed_mods & MOD_RALT) {
            const int value = (new_mods & MOD_RALT) ? 1 : 0;
            kp_virtual_keyboard_send(EV_KEY, KEY_RIGHTALT, value);
        }
        if (changed_mods & MOD_RGUI) {
            const int value = (new_mods & MOD_RGUI) ? 1 : 0;
            kp_virtual_keyboard_send(EV_KEY, KEY_RIGHTMETA, value);
        }
    }

    return updated;
}

void kp_virtual_hid_boot_keyboard_report_send(void) {
    int updated = 0;
#if DEBUG > 5
    hexDump("boot_kb_report", &g_boot_keyboard_report, sizeof(g_boot_keyboard_report));
#endif

    updated |= handle_mods(s_last_boot_report.modifiers, g_boot_keyboard_report.modifiers);

    for (int i = 0; i < BOOT_REPORT_KEY_COUNT; ++i) {
        int old_key = s_last_boot_report.keys[i];
        int new_key = g_boot_keyboard_report.keys[i];
        if ( old_key != new_key ) {
            updated = 1;
            if (old_key == 0 && new_key != 0) { // press new key
                kp_virtual_keyboard_send(EV_KEY, HID_KB_TO_EV[new_key], 1);
            } else if (old_key != 0 && new_key == 0) { // release old key
                kp_virtual_keyboard_send(EV_KEY, HID_KB_TO_EV[old_key], 0);
            } else { // release old_key and press new_key
                kp_virtual_keyboard_send(EV_KEY, HID_KB_TO_EV[old_key], 0);
                kp_virtual_keyboard_send(EV_KEY, HID_KB_TO_EV[new_key], 1);
            }
        }
    }

    if (updated) {
        memcpy(&s_last_boot_report, &g_boot_keyboard_report, sizeof(s_last_boot_report));
        kp_virtual_keyboard_send(EV_SYN, SYN_REPORT, 0);
    }
}

void kp_virtual_hid_nkro_keyboard_report_send(void) {
    int updated = 0;
#if DEBUG > 5
    hexDump("nkro_kb_report:", &g_nkro_keyboard_report, sizeof(g_nkro_keyboard_report));
#endif

    updated |= handle_mods(s_last_nkro_report.modifiers, g_nkro_keyboard_report.modifiers);

    for (int i = 0; i < NKRO_REPORT_BYTES; ++i) {
        int old_bits = s_last_nkro_report.bitmask[i];
        int new_bits = g_nkro_keyboard_report.bitmask[i];
        int changed = old_bits ^ new_bits;

        if (!changed) {
            continue;
        }

        for (int bit = 0; bit < 8; ++bit) {
            int hid;
            int value;
            if (!(changed & (1<<bit))) {
                continue;
            }

            hid = i * 8 + bit;
            value = !!(new_bits & (1<<bit));
            kp_virtual_keyboard_send(EV_KEY, HID_KB_TO_EV[hid], value);
            updated = 1;
        }
    }

    if (updated) {
        memcpy(&s_last_nkro_report, &g_nkro_keyboard_report, sizeof(s_last_nkro_report));
        kp_virtual_keyboard_send(EV_SYN, SYN_REPORT, 0);
    }
}

void kp_virtual_hid_mouse_report_send(void) {
    int changed;
#if DEBUG > 5
    hexDump("mouse_report:", &g_mouse_report, sizeof(g_mouse_report));
#endif

    uint8_t changed_buttons = s_last_mouse_report.buttons_1 ^ g_mouse_report.buttons_1;
    if (changed_buttons) {
        int new_mods = g_mouse_report.buttons_1;
        changed = 1;

        for (int i = 0; i < 8; ++i) {
            int value;
            if (!(changed_buttons & (1 << i))) {
                continue;
            }

            value = !!(new_mods & (1 << i));
            kp_virtual_mouse_send(EV_KEY, HID_MOUSE_TO_EV[i], value);
            changed = 1;
        }
    }

    if (g_mouse_report.x != 0) {
        kp_virtual_mouse_send(EV_REL, REL_X, g_mouse_report.x);
        changed = 1;
    }

    if (g_mouse_report.y != 0) {
        kp_virtual_mouse_send(EV_REL, REL_Y, g_mouse_report.y);
        changed = 1;
    }

    if (g_mouse_report.wheel_x != 0) {
        kp_virtual_mouse_send(EV_REL, REL_HWHEEL, g_mouse_report.wheel_x);
        changed = 1;
    }

    if (g_mouse_report.wheel_y != 0) {
        kp_virtual_mouse_send(EV_REL, REL_WHEEL, g_mouse_report.wheel_y);
        changed = 1;
    }

    if (changed) {
        memcpy(&s_last_mouse_report, &g_mouse_report, sizeof(s_last_mouse_report));
        kp_virtual_mouse_send(EV_SYN, SYN_REPORT, 0);
    }
}

void kp_virtual_hid_media_report_send(void) {
#if DEBUG > 5
    hexDump("media_report", &g_media_report, sizeof(g_media_report));
#endif

    switch (g_media_report.report_id) {
        case REPORT_ID_SYSTEM: {
            uint8_t new_code = g_media_report.code;
            uint8_t old_code = s_last_system;
            s_last_report_id = g_media_report.report_id;;
            s_last_system = g_media_report.code;
            if (new_code == old_code) {
                return;
            } else if (new_code == 0 && old_code != 0) {
                kp_virtual_keyboard_send(EV_KEY, hid_system_to_ev(old_code), 0);
            } else if (new_code != 0 && old_code == 0) {
                kp_virtual_keyboard_send(EV_KEY, hid_system_to_ev(new_code), 1);
            } else {
                kp_virtual_keyboard_send(EV_KEY, hid_system_to_ev(old_code), 0);
                kp_virtual_keyboard_send(EV_KEY, hid_system_to_ev(new_code), 1);
            }
        } break;

        case REPORT_ID_CONSUMER: {
            uint16_t new_code = g_media_report.code;
            uint16_t old_code = s_last_consumer;
            s_last_report_id = g_media_report.report_id;;
            s_last_consumer = g_media_report.code;
            if (new_code == old_code) {
                return;
            } else if (new_code == 0 && old_code != 0) {
                kp_virtual_keyboard_send(EV_KEY, hid_consumer_to_ev(old_code), 0);
            } else if (new_code != 0 && old_code == 0) {
                kp_virtual_keyboard_send(EV_KEY, hid_consumer_to_ev(new_code), 1);
            } else {
                kp_virtual_keyboard_send(EV_KEY, hid_consumer_to_ev(old_code), 0);
                kp_virtual_keyboard_send(EV_KEY, hid_consumer_to_ev(new_code), 1);
            }
        } break;

        default: {
            return;
        } break;
    }
    kp_virtual_keyboard_send(EV_SYN, SYN_REPORT, 0);
}

