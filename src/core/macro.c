// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/macro.h"

#include <string.h>

#include "core/layout.h"
#include "core/hardware.h"
#include "core/timer.h"

#include "key_handlers/key_normal.h"

#include "usb_reports/keyboard_report.h"
#include "usb_reports/mouse_report.h"


static void blocking_send_boot_report(void) {
    // wait for boot report to be ready for next keycode
    while (!is_ready_boot_keyboard_report()) {
        idle_sleep();
    }

    // send the keycodes
    send_boot_keyboard_report();
}

static void blocking_send_mouse_report(void) {
    // wait for boot report to be ready for next keycode
    while (!is_ready_mouse_report()) {
        idle_sleep();
    }
    g_report_pending_mouse = true;
    send_mouse_report();
}

/*********************************************************************
 *                        macro repeat stack                         *
 *********************************************************************/
#define REPEAT_STACK_SIZE 8
static XRAM uint16_t repeat_stack[REPEAT_STACK_SIZE];
static XRAM uint8_t repeat_stack_ptr;

static uint8_t macro_stack_push(uint16_t x) {
    if (repeat_stack_ptr < (REPEAT_STACK_SIZE-1)) {
        repeat_stack[++repeat_stack_ptr] = x;
        return 0;
    } else {
        return 1;
    }
}

static uint16_t macro_stack_dec(void) {
    repeat_stack[repeat_stack_ptr] -= 1;
    return repeat_stack[repeat_stack_ptr];
}

static void macro_stack_pop(void) {
    if (repeat_stack_ptr > 0) {
        repeat_stack_ptr--;
    }
}

/*********************************************************************
 *                       macro state variables                       *
 *********************************************************************/

static XRAM uint16_t macro_rate;
static XRAM uint16_t data_offset;
static XRAM uint8_t saved_report_mode;
static XRAM uint8_t is_macro_running;
static XRAM uint32_t macro_delay_start;
static XRAM uint8_t macro_delay;
static XRAM uint8_t macro_clear;

// TODO: should probably use the default report mode
void call_macro(uint16_t ekc_addr) {
    if (!is_macro_running) {
        is_macro_running = true;
        data_offset = ekc_addr;
        macro_rate = 0;
        repeat_stack_ptr = 0;
        macro_delay = 0;
        macro_clear = 0;
        macro_delay_start = timer_read_ms();
        saved_report_mode = get_keyboard_report_mode();

        set_keyboard_report_mode(KEYBOARD_REPORT_MODE_6KRO);
        reset_keyboard_reports();
    }
}

static uint8_t macro_get_data(uint8_t* data, uint8_t size) {
    uint8_t err = get_ekc_data(data, data_offset, size);
    if (err) {
        macro_abort();
        return err;
    }
    data_offset += sizeof(keycode_t);
    return 0;
}

// returns nonzero if the macro should immediate process the next step
static uint8_t macro_step(void) REENT {
    uint8_t err;
    keycode_t keycode;
    uint8_t tag;
    macro_delay_start = timer_read_ms();

    err = macro_get_data((uint8_t*)&keycode, sizeof(keycode_t));
    if (err) return 0;

    tag = GET_MACRO_TAG(keycode);
    keycode &= ~MACRO_TAG_MASK;

    if (modkey_keycodes.checker(keycode)) {
        uint8_t hid_kc = MODKEY_KEYCODE(keycode);
        uint8_t mods = MODKEY_MODS(keycode);

        while (!is_ready_boot_keyboard_report()) {
            idle_sleep();
        }

        if (tag == MACRO_TAG_KEY_SEND) {
            reset_keyboard_reports();

            if (hid_kc == g_boot_keyboard_report.keys[0]) {
                g_boot_keyboard_report.keys[0] = 0;
                blocking_send_boot_report();
            }

            g_boot_keyboard_report.keys[0] = hid_kc;
            g_boot_keyboard_report.modifiers = mods;
            blocking_send_boot_report();
            macro_clear = true;
        } else if (tag == MACRO_TAG_KEY_PRESS) {
            boot_add_keycode(hid_kc);
            g_boot_keyboard_report.modifiers |= mods;
            blocking_send_boot_report();
        } else if (tag == MACRO_TAG_KEY_RELEASE) {
            boot_del_keycode(hid_kc);
            g_boot_keyboard_report.modifiers &= ~mods;
            blocking_send_boot_report();
        }
        return 0;
    } else if (keycode == MACRO_CMD_REPEAT_BLOCK) {
        uint16_t repeat_count;
        err = macro_get_data((uint8_t*)&repeat_count, sizeof(uint16_t));
        if (err) return 0;

        err = macro_stack_push(repeat_count);
        if (err) {
            macro_abort();
            return 0;
        }
        return 1;
    } else if (keycode == MACRO_CMD_REPEAT_JMP) {
        int16_t rel_jump;
        err = macro_get_data((uint8_t*)&rel_jump, sizeof(int16_t));
        if (err) return 0;

        if (macro_stack_dec() != 0) {
            data_offset += rel_jump;
        } else {
            macro_stack_pop();
        }
        return 1;
    } else if (keycode == MACRO_CMD_SET_RATE) {
        err = macro_get_data((uint8_t*)&macro_rate, sizeof(macro_rate));
        if (err) return 0;
        return 1;
    } else if (keycode == MACRO_CMD_WAIT) {
        return 1;
    } else if (keycode == MACRO_CMD_FINISH) {
        macro_abort();
    } else if (keycode == MACRO_CMD_MOUSE_SET_POS) {
        uint16_t pos_xy;
        err = macro_get_data((uint8_t*)&pos_xy, sizeof(pos_xy));
        if (err) return 0;

        g_mouse_report.x = sign_extend_8(pos_xy & 0xff);
        g_mouse_report.y = sign_extend_8((pos_xy>>8) & 0xff);
        blocking_send_mouse_report();
    } else if (keycode == MACRO_CMD_MOUSE_SET_BUTTONS) {
        err = macro_get_data((uint8_t*)&g_mouse_report.buttons_1, sizeof(uint16_t));
        if (err) return 0;
        blocking_send_mouse_report();
    } else if (keycode == MACRO_CMD_MOUSE_SET_WHEEL) {
        err = macro_get_data((uint8_t*)&g_mouse_report.wheel_x, sizeof(uint16_t));
        if (err) return 0;
        blocking_send_mouse_report();
    } else if (keycode == MACRO_CMD_MOUSE_CLEAR) {
        reset_mouse_report();
        blocking_send_mouse_report();
    } else {
        // skip other keycodes
    }
    return 0;
}

void macro_task(void) {
    if (!is_macro_running) {
        return;
    }

    if (macro_clear) {
        reset_keyboard_reports();
        blocking_send_boot_report();
        macro_clear = false;
    }

    if ((uint32_t)(timer_read_ms() - macro_delay_start) >= macro_rate) {
        while ( macro_step() );
    }
}

void macro_abort(void) {
    if (!is_macro_running) {
        return;
    }

    reset_keyboard_reports();
    reset_mouse_report();

    send_boot_keyboard_report();

    // restore the keyboard report mode
    set_keyboard_report_mode(saved_report_mode);

    is_macro_running = false;
}


