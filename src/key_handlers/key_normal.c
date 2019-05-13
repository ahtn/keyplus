// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "key_handlers/key_normal.h"

#include "core/matrix_interpret.h"

#include "hid_reports/keyboard_report.h"

/* TODO: fn keycode */
bit_t is_layer_keycode(keycode_t keycode) {
    return ( keycode >= KC_L0 && keycode <= KC_STICKY_RGUI );
}

void handle_layer_keycode(keycode_t keycode, key_event_t event) REENT {
    /* TODO: change how layer changing is handled */

    if (keycode <= KC_L15) { // KC_LXX
        if (event == EVENT_PRESSED) {
            layer_queue_add(keycode - KC_L0);
        } else if (event == EVENT_RELEASED) {
            layer_queue_del(keycode - KC_L0);
        }
    } else if (keycode <= KC_SET_L15) {
        if (event == EVENT_PRESSED) {
            layer_queue_set(keycode - KC_SET_L0);
        } else {
            // do nothing
        }
    } else if (keycode <= KC_TOGGLE_L15) {
        if (event == EVENT_PRESSED) {
            layer_queue_toggle(keycode - KC_TOGGLE_L0);
        } else {
            // do nothing
        }
    } else if (keycode <= KC_STICKY_L15) {
        if (event == EVENT_PRESSED) {
            layer_queue_add(keycode - KC_STICKY_L0);
            layer_queue_sticky(keycode - KC_STICKY_L0);
        } else if (event == EVENT_RELEASED) {
            layer_queue_del(keycode - KC_STICKY_L0);
        }
    } else if (keycode <= KC_STICKY_RGUI) {
        if (event == EVENT_PRESSED) {
            uint8_t mod_mask = (1 << (keycode - KC_STICKY_LCTRL));
            add_pure_mods(mod_mask);
            add_sticky_mods(mod_mask);
        } else if (event == EVENT_RELEASED) {
            uint8_t mod_mask = (1 << (keycode - KC_STICKY_LCTRL));
            del_pure_mods(mod_mask);
        }
    }
}

XRAM keycode_callbacks_t layer_keycodes = {
    .checker = is_layer_keycode,
    .handler = handle_layer_keycode,
    .active_when_disabled = true,
    .preserves_sticky_keys = true,
};

bit_t is_modkey_keycode(keycode_t keycode) {
    return IS_MODKEY(keycode);
}

void handle_modkey_keycode(keycode_t keycode, key_event_t event) REENT {
    const uint8_t kc = ((uint8_t*)&keycode)[0];
    const uint8_t mod_tag = ((uint8_t*)&keycode)[1];
    const uint8_t mods = MODKEY_TAG_TO_MASK(mod_tag);
    // const uint8_t is_forced = MODKEY_TAG_IS_FORCED(mod_tag);

    if (event == EVENT_PRESSED) {
        // TODO: decide about how to handle modkeys, how they are now seems
        // to be okay for the majority of cases
        // option 1: forced doesn't overide sticky mods
        // if (is_forced && !has_pure_mods() && !get_sticky_mods()) {
        // option 2: forced overides sticky mods
        // if (is_forced && !has_pure_mods()) {
        if (kc == 0) {
            add_pure_mods(mods);
        } else {
            if (
                get_mods() != mods &&
                !has_pure_mods() &&
                !get_sticky_mods()
                // && !is_forced
            ) {
                // The modkey is adding or deleting mods and it's trying to
                // trigger a kc as well.  We delete any modifiers that other
                // modkeys may have pressed, and release the keycode if
                // it is already done, and repress it.
                //
                // For example, if the user tries to type the sequence `(0)`
                // the user will need to press these modkeys:
                //
                // * shift-9
                // * 0
                // * shift-0
                //
                // So if the user pressed this modkey sequence without
                // releasing the keys, then the output would be `()`,
                // so we reset the "fake modifiers" for modkeys on each
                // press, and retrigger the keycode incase the code is
                // already done.
                reset_mods();
                add_fake_mods(mods);
                retrigger_keycode(kc);
                return;
            }

            add_fake_mods(mods);
            add_keycode(kc);
        }
    } else if (event == EVENT_RELEASED) {
        if (kc == 0) {
            del_pure_mods(mods);
        } else {
            del_fake_mods(mods);
            del_keycode(kc);
        }
    }
}

XRAM keycode_callbacks_t modkey_keycodes = {
    .checker = is_modkey_keycode,
    .handler = handle_modkey_keycode,
};
