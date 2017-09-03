// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <stdint.h>
#include "core/keycode.h"
#include "core/mods.h"
#include "core/util.h"

typedef enum event_type_t {
    EVENT_RESET = 0,
    EVENT_PRESSED,
    EVENT_RELEASED,
    EVENT_TIMER_TASK,
    // EVENT_DISABLE, // disable key handler
} event_type_t;

typedef struct event_t {
    uint8_t type: 5;
    uint8_t tap_count: 3;
} event_t;

typedef struct timed_event_t {
    keycode_t keycode;
    uint16_t timeout_value;
    uint8_t event_type;
} timed_event_t;

typedef uint8_t key_event_t;

typedef bit_t (*key_checker_t)(keycode_t);
typedef void (*key_handler_t)(keycode_t, key_event_t) REENT;

// handlers for different key classes
typedef struct {
    key_checker_t checker; // decides whether the given keycode should be handled
    key_handler_t handler; // handles the keycode based on the given event

    // When multiple devices act as USB receivers, `active_when_disabled`
    // controls whether this key handler still functions on a disabled receiver.
    uint8_t active_when_disabled: 1;

    // Preserves sticky keys means that this key handler will not clear sticky
    // keys when any of it's keys are pressed.
    // TODO: consider adding a clear_sticky key event to refine this behaviour?
    uint8_t preserves_sticky_keys: 1;

    // Timer tasks allow a key handler to implement functionality that depend
    // on timed events. If `is_timer_task_active` is set, then the timer_task
    // event will be generated
    // TODO: still need to implement this. It might be better to do this
    // generically with just a timer queue with callbacks. If the function needs
    // to be called periodically, it could just keep reapplying its callback
    uint8_t is_timer_task_active: 1;
    uint8_t reserved: 5;
} keycode_callbacks_t;

extern XRAM keycode_callbacks_t * XRAM callbacks[];
