// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <stdint.h>

#include "key_handlers/key_handlers.h"

#include "core/keycode.h"
#include "core/util.h"
#include "core/flash.h"

// Should probably support more.
#define MAX_NUM_LAYERS 16

typedef uint16_t layer_mask_t;

// TODO: calcuate matrix sizes from settings
#ifdef NO_SPLIT
    #define MAX_NUM_KEYBOARD_SLOTS 1
#else
    #define MAX_NUM_KEYBOARD_SLOTS 4
#endif

#define INVALID_DEVICE_ID 0xff

// Stick keys will be held down for this amount of time before the RELEASE
// event is generated.
#define STICKY_KEY_RELEASE_DELAY 5

// TODO: add a keycode to dynamically toggle sticky layers and sticky key functionality

extern XRAM uint8_t num_keys_down;

extern bit_t g_input_disabled;
extern bit_t dongle_active;

typedef struct keyboard_t {
    uint8_t kb_id;
    uint8_t matrix_size;
    flash_ptr_t layout;

    uint8_t matrix[32];
    uint8_t matrix_prev[32];

    uint8_t is_dirty: 1;
    uint8_t input_disabled: 1;
    uint8_t layer_changed: 1;
    uint8_t _reserved0: 5;
    uint8_t num_keys_down;
    layer_mask_t active_layers; // for temporoary layer changes
    layer_mask_t default_layers; // stays active till overridden by something else
    layer_mask_t sticky_layers; // sticky layers gets clear on key press
} keyboard_t;

typedef struct key_event_trigger_t {
    keycode_t keycode;
    uint8_t type;
    uint8_t keyboard_id;
} key_event_trigger_t;

#define MAX_EVENT_QUEUE_LENGTH 4
typedef struct key_event_queue_t {
    uint8_t length;
    key_event_trigger_t events[MAX_EVENT_QUEUE_LENGTH];
} key_event_queue_t;

extern XRAM keyboard_t g_keyboard_slots[MAX_NUM_KEYBOARD_SLOTS];

void keyboards_init(void);
void keyboard_update_device_matrix(uint8_t device_id, const XRAM uint8_t *matrix_packet) REENT;
void update_mouse_matrix(uint8_t buttons);

void keyboard_interpret_matrix(uint8_t keyboard_id) ;
void keyboard_reset_matrix(uint8_t keyboard_id);
layer_mask_t keyboard_get_layer_mask(uint8_t keyboard_id);
void reset_layer_state(uint8_t keyboard_id);
uint8_t get_slot_id(uint8_t kb_id);
// void keyboard_trigger_event(keycode_t keycode, key_event_t event) REENT;

void sticky_key_task(void);

void interpret_all_keyboard_matrices(void);

// NOTE: Most of these functions below rely on static state stored by the matrix
// interpreter. These functions are used in the key handlers, and directly read
// and write to the static state of the matrix configurator.
uint8_t has_active_slot(void);
uint8_t get_active_keyboard_id(void);
uint8_t get_active_slot_id(void);
bit_t is_keyboard_active(uint8_t kb_id);
void queue_keycode_event(keycode_t keycode, uint8_t event_type, uint8_t kb_id);

// Because we don't want the layer to update in the middle of the scan, we
// queue all the layer changes before we apply them. The
void layer_queue_add(uint8_t layer);
void layer_queue_del(uint8_t layer);
void layer_queue_set(uint8_t layer);
void layer_queue_toggle(uint8_t layer);
void layer_queue_sticky(uint8_t layer);
void layer_queue_apply(uint8_t keyboard_id);
void add_sticky_mods(uint8_t mods);
void clear_sticky_mods(void);
uint8_t get_sticky_mods(void);
