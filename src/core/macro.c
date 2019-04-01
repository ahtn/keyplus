// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/macro.h"

#include <string.h>

#include "core/error.h"
#include "core/hardware.h"
#include "core/layout.h"
#include "core/matrix_interpret.h"
#include "core/timer.h"

#include "key_handlers/key_normal.h"

#include "usb_reports/keyboard_report.h"
#include "usb_reports/mouse_report.h"

/*********************************************************************
 *                        macro repeat stack                         *
 *********************************************************************/
#define REPEAT_STACK_SIZE 8

// NOTE: repeat stack doesn't use the lowest in this array
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

static uint16_t macro_stack_peek(void) {
    return repeat_stack[repeat_stack_ptr];
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
static XRAM uint16_t macro_clear_rate;
static XRAM uint16_t data_offset;
static XRAM uint8_t is_macro_running;
static XRAM uint32_t macro_delay_start;
static XRAM keycode_t macro_clear_kc;
static XRAM uint8_t macro_kb_id;

/// Run the macro program at the given address
void call_macro(uint16_t ekc_addr, uint8_t kb_id) {
    if (!is_macro_running) {
        is_macro_running = true;
        data_offset = ekc_addr;
        macro_rate = 5;
        macro_clear_rate = 2;
        repeat_stack_ptr = 0;
        macro_clear_kc = KC_NONE;
        macro_kb_id = kb_id;
        macro_delay_start = timer_read_ms();

        // set_keyboard_report_mode(KEYBOARD_REPORT_MODE_6KRO);
        // reset_keyboard_reports();
    }
}

static uint8_t macro_get_data(uint8_t* data, uint8_t size) {
    uint8_t err = get_ekc_data(data, data_offset, size);
    if (err) {
        macro_abort();
        return err;
    }
    data_offset += size;
    return 0;
}

void macro_abort(void) {
    if (!is_macro_running) {
        return;
    }

    // reset_keyboard_reports();
    // reset_mouse_report();

    // send_boot_keyboard_report();

    // // restore the keyboard report mode

    is_macro_running = false;
}

// returns nonzero if the macro should immediate process the next step
static uint8_t macro_step(void) REENT {
    uint8_t err;
    keycode_t keycode;
    macro_delay_start = timer_read_ms();

    err = macro_get_data((uint8_t*)&keycode, sizeof(keycode_t));
    if (err) return 0;

    // if (modkey_keycodes.checker(keycode)) {
    if (keycode < KC_MACRO_CMD_START_ADDR) {
        queue_keycode_event(keycode, EVENT_PRESSED, macro_kb_id);
        macro_clear_kc = keycode;
    } else if (keycode == MACRO_CMD_PRESS) {
        err = macro_get_data((uint8_t*)&keycode, sizeof(keycode_t));
        if (err) return 0;
        queue_keycode_event(keycode, EVENT_PRESSED, macro_kb_id);
    } else if (keycode == MACRO_CMD_RELEASE) {
        err = macro_get_data((uint8_t*)&keycode, sizeof(keycode_t));
        if (err) return 0;
        queue_keycode_event(keycode, EVENT_RELEASED, macro_kb_id);
    } else if (keycode == MACRO_CMD_SET_RATE) {
        err = macro_get_data((uint8_t*)&macro_rate, sizeof(macro_rate));
        if (err) return 0;
        return 1;
    } else if (keycode == MACRO_CMD_SET_CLEAR_RATE) {
        err = macro_get_data((uint8_t*)&macro_clear_rate, sizeof(macro_clear_rate));
        if (err) return 0;
        return 1;
    } else if (keycode == MACRO_CMD_CLEAR_MOUSE) {
        reset_mouse_report();
    } else if (keycode == MACRO_CMD_CLEAR_KEYBOARD) {
        reset_keyboard_reports();
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

        if (macro_stack_peek() == 0) {
            // jump forever
            data_offset += rel_jump;
        } else if (macro_stack_dec() > 0) {
            // jump
            data_offset += rel_jump;
        } else {
            // no jump, continue at instruction after jmp command
            macro_stack_pop();
        }
        return 1;
    } else if (keycode == MACRO_CMD_MOUSE_MOVE) {
        err = macro_get_data((uint8_t*)&g_mouse_report.x, sizeof(int16_t)*2);
        if (err) return 0;
        g_report_pending_mouse = true;
    } else if (keycode == MACRO_CMD_MOUSE_WHEEL) {
        err  = macro_get_data((uint8_t*)&g_mouse_report.wheel_x, sizeof(int8_t));
        err  = macro_get_data((uint8_t*)&g_mouse_report.wheel_y, sizeof(int8_t));
        if (err) return 0;
        g_report_pending_mouse = true;
    } else if (keycode == MACRO_CMD_FINISH) {
        macro_abort();
    } else {
        // Unknown command
        register_error(ERROR_MACRO_CMD_ERROR);
        reset_mouse_report();
        reset_keyboard_reports();
        macro_abort();
    }

    return 0;
}

void macro_task(void) {
    if (!is_macro_running) {
        return;
    }

    {
        uint32_t elapsed_time = (uint32_t)(timer_read_ms() - macro_delay_start);

        if (macro_clear_kc != KC_NONE && elapsed_time >= macro_clear_rate) {
            queue_keycode_event(macro_clear_kc, EVENT_RELEASED, macro_kb_id);
            macro_clear_kc = KC_NONE;
        }

        if (elapsed_time >= macro_rate) {
            while ( macro_step() );
        }
    }

    interpret_all_keyboard_matrices();
}
