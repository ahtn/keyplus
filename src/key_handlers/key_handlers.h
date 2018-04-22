// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)
/// @dir src/key_handlers
/// @file key_handlers.h
///
/// @brief The key handlers map keycodes to there functions.
///
/// The key handlers are used to map keycodes to functionality.

#pragma once

#include <stdint.h>
#include "core/keycode.h"
#include "core/mods.h"
#include "core/util.h"

typedef enum event_type_t {
    /// This event will be triggered when the microcontroller is reset
    EVENT_RESET = 0,

    /// This event will be generated when the keycode is pressed
    EVENT_PRESSED = 1,

    /// This event will be generated when the keycode is released
    EVENT_RELEASED = 2,

    EVENT_TIMER_TASK,
    // EVENT_DISABLE, // disable key handler

    /// This event is used to buffer a key press based on the key number,
    /// instead of its keycode. It will not be seen by the key handlers.
    /// Internal use only.
    EVENT_BUFFERED_KEY_PRESS = 64,
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

/// Provides handlers for different key classes of keycodes
typedef struct {
    ///< callback function to decide whether the given keycode should be handled
    key_checker_t checker;

    ///< callback function that handles the keycode based on the given event
    key_handler_t handler;

    ///< When multiple devices act as USB receivers, `active_when_disabled`
    ///< controls whether this key handler still functions on a disabled receiver.
    ///<
    ///< For example, when two dongles are acting as wireless receivers, only
    ///< one will be active at a time. In this case, only the active dongle
    ///< should be parsing keycodes like letters, while the other dongle should
    ///< ignore them. Meanwhile, the keycodes to enable/disable dongles should
    ///< still be parsed by the 'disabled' dongle, so it can be switched back
    ///< on if the other dongle goes offline.
    uint8_t active_when_disabled: 1;

    ///< Preserves sticky keys means that this key handler will not clear sticky
    ///< keys when any of it's keys are pressed.
    ///< TODO: consider adding a clear_sticky key event to refine this behaviour?
    uint8_t preserves_sticky_keys: 1;

    ///< Timer tasks allow a key handler to implement functionality that depend
    ///< on timed events. If `is_timer_task_active` is set, then the timer_task
    ///< event will be generated
    ///< TODO: still need to implement this. It might be better to do this
    ///< generically with just a timer queue with callbacks. If the function needs
    ///< to be called periodically, it could just keep reapplying its callback
    uint8_t is_timer_task_active: 1;
    uint8_t reserved: 5;
} keycode_callbacks_t;

/// The list of keycode handlers used. The handlers near the start of the list
/// will take priority over those near the end.
///

extern XRAM keycode_callbacks_t * XRAM g_keyhandler_list[];
