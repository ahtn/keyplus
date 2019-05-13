// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/mods.h"

#include <string.h>

#include "core/usb_commands.h"

#include "hid_reports/keyboard_report.h"

// NOTE: counts how many keys are "pressing" each modifier. Makes the behaviour
// of modkeys nicer since multiple keyboards are all sharing the mods.
static XRAM uint8_t pure_mod_counts[8];
static XRAM uint8_t fake_mod_counts[8];
static XRAM uint8_t mod_state; // stores the actual computed modifiers
static XRAM uint8_t mods_dirty;

static void _add_mods(uint8_t mods, XRAM uint8_t *mod_counts) {
    uint8_t i;
    if (mods == 0) {
        return;
    }

    mods_dirty = 1;

    for (i = 0; i < 8; ++i) {
        if (mods & 0x01) {
            mod_counts[i]++;
        }
        mods >>= 1;
    }
}

static void _del_mods(uint8_t mods, XRAM uint8_t *mod_counts) {
    uint8_t i;

    if (mods == 0) {
        return;
    }

    mods_dirty = 1;

    for (i = 0; i < 8; ++i) {
        if ((mods & 0x01) && mod_counts[i] != 0) {
            mod_counts[i]--;
        }
        mods >>= 1;
    }
}

void add_pure_mods(uint8_t mods) {
    _add_mods(mods, pure_mod_counts);
}

void del_pure_mods(uint8_t mods) {
    _del_mods(mods, pure_mod_counts);
}

void add_fake_mods(uint8_t mods) {
    _add_mods(mods, fake_mod_counts);
}

void del_fake_mods(uint8_t mods) {
    _del_mods(mods, fake_mod_counts);
}

void reset_mods(void) {
    memset(pure_mod_counts, 0, 8);
    memset(fake_mod_counts, 0, 8);
    mods_dirty = 1;
}

uint8_t has_pure_mods(void) {
    uint8_t i;
    for (i = 0; i < 8; ++i) {
        if (pure_mod_counts[i]) {
            return 1;
        }
    }
    return 0;
}

uint8_t get_mods(void) {
    uint8_t res = 0;
    uint8_t i;

    if (mods_dirty) {
        for (i = 0; i < 8; ++i) {
            if (pure_mod_counts[i] || fake_mod_counts[i]) {
                res = (res >> 1) | 0x80;
            } else {
                res >>= 1;
            }
        }
        return res;
    } else {
        return mod_state;
    }
}

void apply_mods(void) {
    if (mods_dirty) {
        touch_keyboard_report();
        mod_state = get_mods();
        g_boot_keyboard_report.modifiers = mod_state;
        g_nkro_keyboard_report.modifiers = mod_state;
        mods_dirty = 0;
    }
}
