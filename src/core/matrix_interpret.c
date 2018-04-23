// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)
///
/// @file core/matrix_interpret.c
/// @brief keyplus matrix interpreter module
///
/// The matrix interpreter is the core module of keyplus.  The code in this
/// module has a several jobs:
///
/// - Maintaining a list of all the active keyboards that are connected to the
///   keyplus device acting as the receiver. Each keyboard's matrix, layer state,
///   and other variables are all tracked separately to allow them to act as
///   independent keyboards.
/// - Provides functions for manipulating the layer state of keyboards.
/// - Provides functions to update the matrix of keyboard devices for the rf and
///   wired modules.
/// - From updates in the keyboard matrices, the interpreter module computes
///   which keys have been pressed and release with the `EVENT_PRESS` and
///   `EVENT_RELEASED` events.
/// - Provides functions for triggering, queuing and handling keycode events.
///

#include "core/matrix_interpret.h"

#include <string.h>

#include "core/error.h"
#include "core/layout.h"
#include "core/packet.h"
#include "core/timer.h"
#include "core/usb_commands.h"
#include "core/util.h"

#include "key_handlers/key_handlers.h"
#include "key_handlers/key_hold.h"

#include "usb_reports/keyboard_report.h"

XRAM keyboard_t g_keyboard_slots[MAX_NUM_KEYBOARD_SLOTS];
XRAM uint8_t s_slot_id_map[MAX_NUM_KEYBOARDS];
XRAM uint8_t s_slot_fifo_pos;

// key event queue are used to trigger events from non-keyboard sources,
// timers, other keycodes.
// Note: instead of recursively calling keyboard_trigger_event, we use this
// event queue. This is important because we have limited stack space on 8051
// and we need to avoid stack overflows.
XRAM uint8_t s_read_event_queue;
XRAM key_event_queue_t s_key_event_queues[2];

#define WRITE_EVENT_QUEUE() (!s_read_event_queue)
#define READ_EVENT_QUEUE() (s_read_event_queue)

XRAM uint8_t s_has_dirty_matrix;
XRAM uint8_t s_has_dirty_event_queue;

XRAM uint8_t s_buffered_key_len;

bit_t g_input_disabled = false;
bit_t dongle_active = true;

// TODO: should probably move this to a variable that is passed as a parameter
// to the keyhandlers instead. Not sure how SDCC copes with this though.
// Active slot id
static XRAM uint8_t s_active_slot;

// queue layer changes, so they do not change in the middle of interpreting the
// matrix
static XRAM layer_mask_t s_pending_layer_state_add;
static XRAM layer_mask_t s_pending_layer_state_del;
static XRAM layer_mask_t s_pending_layer_state_set;
static XRAM layer_mask_t s_pending_layer_state_toggle;
static XRAM layer_mask_t s_pending_layer_state_sticky;
static XRAM uint8_t s_layer_dirty = 0;

static XRAM uint8_t s_clear_sticky_keys;
static XRAM uint16_t s_sticky_clear_start_time;
static XRAM uint8_t s_sticky_mods;

// TODO: move these to keyboard objects
// need dirty bit
// need clear time,
// need
static XRAM layer_mask_t s_sticky_stuck_layer;
static XRAM uint8_t s_sticky_stuck_kb_id;
static XRAM uint8_t s_sticky_has_stuck_layer;

static void keyboard_trigger_event(keycode_t keycode, key_event_t event) REENT;
static void keyboard_reset_event_handlers(void);
static keycode_t get_keycode_from_layer(layer_mask_t layer_mask, uint8_t row, uint8_t col) REENT;

void layer_queue_add(uint8_t layer) {
    s_layer_dirty = 1;
    s_pending_layer_state_add |= (1 << layer);
}

void layer_queue_del(uint8_t layer) {
    s_layer_dirty = 1;
    s_pending_layer_state_del |= (1 << layer);
}

void layer_queue_set(uint8_t layer) {
    s_layer_dirty = 1;
    s_pending_layer_state_set = (1 << layer);
}

void layer_queue_toggle(uint8_t layer) {
    s_layer_dirty = 1;
    s_pending_layer_state_toggle |= (1 << layer);
}

void layer_queue_sticky(uint8_t layer) {
    s_layer_dirty = 1;
    s_pending_layer_state_sticky |= (1 << layer);
}

void add_sticky_mods(uint8_t mods) {
    /* s_sticky_mods |= mods; // or -> sticky mods only disabled when other key pressed */
    s_sticky_mods ^= mods; // xor -> sticky mods disabled with odd number of presses
}

void clear_sticky_mods(void) {
    s_sticky_mods = 0;
}

uint8_t get_sticky_mods(void) {
    return s_sticky_mods;
}

static void flush_queues(void) {
    s_pending_layer_state_add = 0;
    s_pending_layer_state_del = 0;
    s_pending_layer_state_set = 0;
    s_pending_layer_state_toggle = 0;
    s_pending_layer_state_sticky = 0;
}

// does anything actually break if remove layer queues?
void layer_queue_apply(uint8_t kb_slot_id) {
    if (!s_layer_dirty) {
        return;
    }

    s_layer_dirty = 0;

    // default layer changes
    if (s_pending_layer_state_set) {
        g_keyboard_slots[kb_slot_id].default_layers = s_pending_layer_state_set | 1;
    }

    // active layer changes
    g_keyboard_slots[kb_slot_id].active_layers ^= s_pending_layer_state_toggle;
    g_keyboard_slots[kb_slot_id].active_layers |=  s_pending_layer_state_add;
    g_keyboard_slots[kb_slot_id].active_layers &= ~s_pending_layer_state_del;

    // sticky layer changes
    // g_keyboard_slots[kb_slot_id].sticky_layers |= s_pending_layer_state_sticky;
    g_keyboard_slots[kb_slot_id].sticky_layers ^= s_pending_layer_state_sticky;

    flush_queues();
}

static
bool sticky_relase_timer_done(void) {
    return (uint16_t)(timer_read16_ms() - s_sticky_clear_start_time) > STICKY_KEY_RELEASE_DELAY;
}

uint8_t get_active_slot_id(void) REENT {
    return s_active_slot;
}

uint8_t get_active_keyboard_id(void) REENT {
    return g_keyboard_slots[s_active_slot].kb_id;
}

void queue_keycode_event(keycode_t keycode, uint8_t event_type, uint8_t kb_id) {
    uint8_t len = s_key_event_queues[WRITE_EVENT_QUEUE()].length;
    uint8_t kb_slot_id;

    key_event_trigger_t XRAM* kc_trigger;

    if (len >= MAX_EVENT_QUEUE_LENGTH) {
        register_error(ERROR_KEY_EVENT_QUEUE_FULL);
        return;
    }

    if (kb_id == INVALID_DEVICE_ID) {
        register_error(ERROR_INVALID_KB_ID_USED);
        return;
    }

    kb_slot_id = get_slot_id(kb_id);

    if (kb_slot_id == INVALID_DEVICE_ID) {
        // keyboard was unload from memory before we could process its
        // key events
        // NOTE: This will probably be a rare event, as long as the concurrent
        // number of keyboards used is less than MAX_NUM_KEYBOARD_SLOTS.
        // If for some reason a large number of concurrent keyboards is used,
        // we should look into ways to prevent stuck keys as a result of the
        // keyboard being unloaded from memory before this event could be
        // handled.
        register_error(ERROR_KEY_EVENT_QUEUE_UNLOADED_DEVICE);
        return;
    }

    kc_trigger = &s_key_event_queues[WRITE_EVENT_QUEUE()].events[len];

    kc_trigger->keycode = keycode;
    kc_trigger->type = event_type;
    kc_trigger->keyboard_id = kb_id;

    s_key_event_queues[WRITE_EVENT_QUEUE()].length++;
    g_keyboard_slots[kb_slot_id].is_dirty = 1;
    s_has_dirty_event_queue = 1;
}

static void apply_event_trigger_queue(uint8_t keyboard_id) {
    uint8_t i;
    key_event_queue_t XRAM* queue = &s_key_event_queues[READ_EVENT_QUEUE()];

    for (i = 0; i < queue->length; ++i) {
        const uint8_t type = queue->events[i].type;
        if (queue->events[i].keyboard_id != keyboard_id) {
            continue;
        }

        if (type == EVENT_BUFFERED_KEY_PRESS0 ||
            type == EVENT_BUFFERED_KEY_PRESS1) {
            const uint8_t key_num = queue->events[i].keycode;
            const layer_mask_t active_layer =
                keyboard_get_layer_mask(get_slot_id(keyboard_id));
            const keycode_t keycode =
                get_keycode_from_layer(active_layer, key_num/8, key_num%8);
            if (type == EVENT_BUFFERED_KEY_PRESS1) {
                queue_keycode_event(key_num, EVENT_BUFFERED_KEY_PRESS0, keyboard_id);
            } else if (type == EVENT_BUFFERED_KEY_PRESS0) {
                keyboard_trigger_event(keycode, EVENT_PRESSED);
            }
        } else {
            keyboard_trigger_event(
                queue->events[i].keycode,
                queue->events[i].type
            );
        }
    }
}

// static bit_t has_unprocessed_events(void) {
//     return (s_key_event_queues[READ_EVENT_QUEUE()].length != 0);
// }

/// Reset the layer state of a keyboard current loaded into a slot
void reset_layer_state(uint8_t kb_slot_id) {
    // TODO: set the default layer from settings
    g_keyboard_slots[kb_slot_id].default_layers = (1 << 0);
    g_keyboard_slots[kb_slot_id].active_layers = 0;
    g_keyboard_slots[kb_slot_id].sticky_layers = 0;
    g_keyboard_slots[kb_slot_id].num_keys_down = 0;
    s_clear_sticky_keys = false;
    s_sticky_has_stuck_layer = false;
    reset_mods();
    flush_queues();
}

// TODO: add code to get keycodes from different keyboard_group's layouts
keycode_t get_keycode_from_layer(layer_mask_t layer_mask, uint8_t row, uint8_t col) REENT {
    const uint8_t *layer_bytes = (uint8_t*)&layer_mask;
    int8_t i, j;

    // sizeof the layers in of this keyboard
    // TODO: store this value in g_keyboard_slots[s_active_slot] ???
    const flash_size_t layer_size = sizeof(keycode_t)*8*g_keyboard_slots[s_active_slot].matrix_size;
    // offset of the key (row,col) pos into a layer
    const flash_size_t key_offset = sizeof(keycode_t)*(8*row + col);

    for (i = sizeof(layer_mask_t)-1; i >= 0; --i) {
        uint8_t byte = layer_bytes[i];
        if (byte == 0) {
            // most layers are usually inactive, ignore them
            continue;
        } else {
            for (j = 7; j >= 0; --j) {
                if(is_bitn_set(byte, j)) {
                    uint8_t layer = 8*i+j;
                    const flash_ptr_t layout = g_keyboard_slots[s_active_slot].layout;

                    keycode_t code = flash_read_word(
                        layout + (layer_size * layer + key_offset)
                    );

                    if( code != KC_TRNS ) {
                        // TODO: don't extract the external keycode type here.
                        // Instead always pass around the keycode as in its
                        // full form. Only extract the type when necessary.
                        // This will make it easier the handling of ekc that
                        // are called indirectly by another ekc easier.
                        return code;
                    }
                }
            }
        }
    }
    return KC_NONE;
}

static void fill_keyboard_slot(uint8_t kb_slot_id, uint8_t kb_id) {
    g_keyboard_slots[kb_slot_id].kb_id = kb_id;
    g_keyboard_slots[kb_slot_id].layout = g_layout_storage_pos[kb_id];

    g_keyboard_slots[kb_slot_id].matrix_size = GET_SETTING(layout.layouts[kb_id].matrix_size);
    g_keyboard_slots[kb_slot_id].input_disabled = false;
    reset_layer_state(kb_slot_id);
}

uint8_t get_slot_id(uint8_t kb_id) {
    return s_slot_id_map[kb_id];
}

bool is_keyboard_active(uint8_t kb_id) {
    return get_slot_id(kb_id) != INVALID_DEVICE_ID;
}

uint8_t acquire_slot(uint8_t kb_id) {
    uint8_t kb_slot_id = get_slot_id(kb_id);
    uint8_t i;

    if (kb_slot_id != INVALID_DEVICE_ID) {
        return kb_slot_id;
    }

    // We now need to free a slot for the keyboard if all the slots are full.
    for (i = 0; i < MAX_NUM_KEYBOARDS; ++i) {
        if (s_slot_id_map[i] == s_slot_fifo_pos) {
            const uint8_t stale_kb_id = i;
            s_slot_id_map[stale_kb_id] = INVALID_DEVICE_ID;
            // TODO: need to perform cleanup for this slot
            // TODO: release all the keys of the keyboard that we are evicting
            // from a slot.
            // TODO: invalidate any tap and hold keys that are pending
            // for this slot.
            break;
        }
    }

    // Use a first-in-first-out queue for the new slot
    kb_slot_id = s_slot_fifo_pos;
    s_slot_id_map[kb_id] = kb_slot_id;

    // load the new keyboard into the slot we found
    fill_keyboard_slot(kb_slot_id, kb_id);

    // advance slot FIFO
    s_slot_fifo_pos = (s_slot_fifo_pos + 1) % MAX_NUM_KEYBOARD_SLOTS;
    return kb_slot_id;
}

void keyboards_init(void) {
    if (has_critical_error()) {
        // Can't initialize if flash is corrupt
        return;
    }

    // TODO: probably set default layers

    keyboard_layouts_init();
    memset(s_slot_id_map, INVALID_DEVICE_ID, MAX_NUM_KEYBOARDS);

    {
        uint8_t slot_id;
        for (slot_id = 0; slot_id < MAX_NUM_KEYBOARD_SLOTS; ++slot_id) {
            g_keyboard_slots[slot_id].kb_id = INVALID_DEVICE_ID;
        }
    }

    s_slot_fifo_pos = 0;
    s_has_dirty_matrix = true;

    s_key_event_queues[0].length = 0;
    s_key_event_queues[1].length = 0;
    s_read_event_queue = 0;

    keyboard_reset_event_handlers();
    clear_keyboard_report();
}

// TODO: update this
// NOTE: this should not be called from an interrupt, as it will break
// how the matrix interpreting step.
void keyboard_update_device_matrix(uint8_t device_id, const uint8_t *matrix_packet) REENT {
    // first figure out what sort of packet was received and
    const uint8_t packet_type = matrix_packet[0] >> PACKET_MATRIX_TYPE_BIT_POS;
    const uint8_t packet_data_size = matrix_packet[0] & PACKET_MATRIX_SIZE_MASK;

    const uint8_t kb_id = GET_SETTING(layout.devices[device_id].layout_id);
    const uint8_t device_matrix_offset = GET_SETTING(layout.devices[device_id].matrix_offset);
    const uint8_t device_matrix_size = GET_SETTING(layout.devices[device_id].matrix_size);

    // matrix_data now points to the start of the key list
    const uint8_t* matrix_data = &matrix_packet[1];

    // get matrix slot from kb_id

    uint8_t *matrix_write_pos;

    uint8_t kb_slot_id = get_slot_id(kb_id);

    if (kb_id >= MAX_NUM_KEYBOARDS) {
        return;
    }

    if (kb_slot_id == INVALID_DEVICE_ID) {
        kb_slot_id = acquire_slot(kb_id);
    }

    matrix_write_pos = g_keyboard_slots[kb_slot_id].matrix + device_matrix_offset;

    if (device_id > MAX_NUM_DEVICES) {
        register_error(ERROR_RECEIVED_TOO_LARGE_DEVICE_ID);
        return ;
    }

    // TODO: probably move this to an initialization function
    // check that the device is configured properly and doesn't write outside its given matrix
    if (device_matrix_offset + device_matrix_size > g_keyboard_slots[kb_slot_id].matrix_size) {
        register_error(ERROR_RECEIVED_TOO_LARGE_MATRIX);
        return;
    }

    if (packet_type == PACKET_MATRIX_DELTA_LIST) {
        // A delta list packet lists keys that have change state, so only need
        // to update those keys.
        uint8_t key_list_pos = 0;

        while (key_list_pos < packet_data_size) {
            const uint8_t key_num = matrix_data[key_list_pos] & MATRIX_DELTA_KEY_MASK;
            const uint8_t delta_type = matrix_data[key_list_pos] & MATRIX_DELTA_TYPE_MASK;
            if (delta_type) { // key pressed
                matrix_write_pos[key_num/8] |= (1 << (key_num % 8));
            } else { // key released
                matrix_write_pos[key_num/8] &= ~(1 << (key_num % 8));
            }
            key_list_pos++;
        }
    } else if (packet_type == PACKET_MATRIX_KEY_LIST) {
        // A key list packet is a list of all the keys that are DOWN in the
        // matrix. The rest of the keys are assumed to be UP.
        uint8_t key_list_pos = 0;

        // first clear the matrix area (i.e. make all keys UP)
        memset(matrix_write_pos, 0, device_matrix_size);

        while (key_list_pos < packet_data_size) {
            const uint8_t key_num = matrix_data[key_list_pos];
            matrix_write_pos[key_num/8] |= (1 << (key_num % 8));
            key_list_pos++;
        }
    } else if (packet_type == PACKET_MATRIX_RAW) {
        // A raw matrix packet, simply contains raw matrix data.
        memcpy(matrix_write_pos, matrix_data, device_matrix_size);
    }

    g_keyboard_slots[kb_slot_id].is_dirty = 1;
    s_has_dirty_matrix = true;
}

void keyboard_reset_matrix(uint8_t kb_slot_id) {
    const uint8_t size = g_keyboard_slots[kb_slot_id].matrix_size;

    memset(g_keyboard_slots[kb_slot_id].matrix, 0, size);
    memset(g_keyboard_slots[kb_slot_id].matrix_prev, 0, size);
    g_keyboard_slots[kb_slot_id].num_keys_down = 0;

    reset_layer_state(kb_slot_id);
    reset_mods();

    // now give the callbacks a chance to cleanup
    /* TODO: maybe just give them an init function, and call
     * that when we re-enable the matrix*/
}

static layer_mask_t get_partial_layer_mask(uint8_t kb_slot_id) {
    return g_keyboard_slots[kb_slot_id].active_layers
        | g_keyboard_slots[kb_slot_id].default_layers;
}

layer_mask_t keyboard_get_layer_mask(uint8_t kb_slot_id) {
    return g_keyboard_slots[kb_slot_id].active_layers
        | g_keyboard_slots[kb_slot_id].default_layers
        | g_keyboard_slots[kb_slot_id].sticky_layers;
}

// Triggers the reset event for all the callback handlers
static void keyboard_reset_event_handlers(void) {
    uint8_t callback_num = 0;
    const keycode_callbacks_t * callback;

    while ( (callback = g_keyhandler_list[callback_num++]) ) {
        callback->handler(KC_NONE, EVENT_RESET);
    }
}

static void keyboard_trigger_event(keycode_t keycode, key_event_t event) REENT {
    uint8_t callback_num = 0;
    const keycode_callbacks_t * callback;
    uint16_t keycode_class = get_ekc_class(keycode);

    while ( (callback = g_keyhandler_list[callback_num++]) ) {
        if (!dongle_active && !callback->active_when_disabled) {
            continue;
        }

        if (callback->checker(keycode_class)) {
            // check if any sticky keys are active
            if ( (g_keyboard_slots[s_active_slot].sticky_layers || s_sticky_mods)
                && event == EVENT_PRESSED
                && !callback->preserves_sticky_keys
                && !s_clear_sticky_keys)
            {
                // check if a sticky layer is active, and different from the
                // non-sticky layers
                if (~get_partial_layer_mask(s_active_slot) &
                        g_keyboard_slots[s_active_slot].sticky_layers) {
                    // if it is, then add it to a sticky queue to be RELEASED
                    // later
                    s_sticky_stuck_layer = keyboard_get_layer_mask(s_active_slot);
                    s_sticky_stuck_kb_id = s_active_slot;
                    s_sticky_has_stuck_layer = true;
                    s_clear_sticky_keys = true;
                    s_sticky_clear_start_time = timer_read_ms();
                }

                // check if a sticky modifer is active
                if (s_sticky_mods) {
                    s_clear_sticky_keys = true;
                    s_sticky_clear_start_time = timer_read_ms();
                    add_fake_mods(s_sticky_mods);
                }

                // sticky keys are reset
                g_keyboard_slots[s_active_slot].sticky_layers = 0;
            }

            callback->handler(keycode, event);
            return;
        }
    }

    register_error(ERROR_UNHANDLED_KEYCODE);
}

/// Releases keys that are were down on the old layer, but that are not present
/// on the new layer. This prevents stuck keys when chaning layers.
static void keyboard_interpret_layer_change(
    uint8_t kb_slot_id,
    layer_mask_t old_layer,
    layer_mask_t new_layer
) REENT {
    uint8_t byte, bit;
    keyboard_t XRAM* keyboard = &g_keyboard_slots[kb_slot_id];

    for (byte = 0; byte < g_keyboard_slots[kb_slot_id].matrix_size; ++byte) {
        uint8_t row_cur = keyboard->matrix[byte];

        // now keys currently down
        if (!row_cur) {
            continue;
        }

        for (bit = 0; bit < 8; ++bit) {
            const bit_t down = is_bitn_set(row_cur, bit);
            keycode_t old_keycode, new_keycode;

            if (!down) {
                continue;
            }


            old_keycode = get_keycode_from_layer(old_layer, byte, bit);
            new_keycode = get_keycode_from_layer(new_layer, byte, bit);

            if (old_keycode != new_keycode) {
                keyboard_trigger_event(old_keycode, EVENT_RELEASED);
            }
        }
    }
}

/// This function releases keys that were PRESSED by a sticky layer/mod.
/// TODO: use a timer based event system as a nicer abstraction
void sticky_key_task(void) {
    if (s_clear_sticky_keys && sticky_relase_timer_done()) {
        if (s_sticky_has_stuck_layer) {
            const layer_mask_t new_layer = get_partial_layer_mask(s_sticky_stuck_kb_id);
            keyboard_interpret_layer_change(
                s_sticky_stuck_kb_id,
                s_sticky_stuck_layer,
                new_layer
            );
            s_sticky_has_stuck_layer = false;
        }


        s_clear_sticky_keys = false;
        del_fake_mods(s_sticky_mods);
        s_sticky_mods = 0;
    }
}

/// Generate key press and release events for the keyboard in the given slot.
///
/// This function will check the `matrix` and `matrix_prev` of the selected
/// keyboard to find out which keys have been pressed and released.
///
/// Layer and modifier events will be queued until all keycodes have been
/// processed and then applied all at once at the ended. Deleting
/// layers and modifiers will take priority over adding them.
void keyboard_interpret_matrix(uint8_t kb_slot_id) {
    XRAM layer_mask_t active_layer;
    XRAM layer_mask_t start_layer;
    keyboard_t XRAM* keyboard;
    uint8_t byte, bit;

    // bounds check
    if (kb_slot_id >= MAX_NUM_KEYBOARD_SLOTS) {
        // TODO: maybe report this in error system?
        return;
    }

    keyboard = &g_keyboard_slots[kb_slot_id];

    if (keyboard->kb_id == INVALID_DEVICE_ID) {
        return;
    }

    // exit early if no work needs to be done
    if (!keyboard->is_dirty) {
        return;
    }

    keyboard->layer_changed = false;
    keyboard->is_dirty = 0;

    s_buffered_key_len = 0;
    s_active_slot = kb_slot_id;

    active_layer = keyboard_get_layer_mask(kb_slot_id);
    start_layer = get_partial_layer_mask(kb_slot_id);

    // First interpret the matrix of the keyboard and generate key up and down
    // events
    if (s_has_dirty_matrix) {
        // TODO/NOTE: current notation here is pretty confusing. The matrix is
        // processed in chunks of bytes. However, here a byte is called a row and
        // the bit offset into that byte is called a col.
        for (byte = 0; byte < keyboard->matrix_size; ++byte) {
            const uint8_t row_cur = keyboard->matrix[byte];
            const uint8_t row_prev = keyboard->matrix_prev[byte];
            const uint8_t changed_keys = row_cur ^ row_prev;

            // skip entire rows that have no keys that changed
            if (!changed_keys) {
                continue;
            }

            for (bit = 0; bit < 8; ++bit) {
                const bit_t current = is_bitn_set(row_cur, bit);
                const bit_t previous = is_bitn_set(row_prev, bit);

                const bit_t pressed = current && !previous;
                const bit_t released = !current && previous;
                const bit_t up = !current && !previous;
                // const bit_t down = current && previous;

                key_event_t event;
                keycode_t keycode;

                if (up) {
                    continue;
                } else if (pressed) {
                    event = EVENT_PRESSED;
                    keyboard->num_keys_down += 1;

                    // TODO: make this a more generic mechanism?
                    if (hold_key_buffer_other_keys() || (s_buffered_key_len>0)) {
                        const uint8_t key_num = byte*8 + bit;

                        // If s_buffered_key_len > 0, then that means we have
                        // already started adding keys to the buffer, and don't
                        // need to retrigger the hold key task.
                        if (s_buffered_key_len == 0) {
                            hold_key_task(true);
                        }
                        s_buffered_key_len++;
                        queue_keycode_event(key_num, EVENT_BUFFERED_KEY_PRESS1, keyboard->kb_id);
                        continue;
                    }
                } else if (released) {
                    event = EVENT_RELEASED;
                    keyboard->num_keys_down -= 1;
                // } else if (down) {
                //     // TODO: get ride of this event when you add event system
                //     event = EVENT_DOWN;
                } else {
                    continue;
                }

                keycode = get_keycode_from_layer(active_layer, byte, bit);

                keyboard_trigger_event(keycode, event);
            }
        }
    }

    // Next process the key event queue. These events are not directly genrated
    // by physical key events, but are processed here, so that they will be
    // treated in the same way. So layers change commands, etc. get sent to
    // the correct keyboard.
    apply_event_trigger_queue(keyboard->kb_id);

    // After the key events have been process, update the layer state
    layer_queue_apply(kb_slot_id);

    // If the layer changed, then need to go look at all the keys that are
    // currently down because if a key is down and we change layers, we don't
    // want any keycodes to get "stuck".
    //
    // If a key is down and its keycode on the old layer and the new layer are
    // not the same, need to generate a key_released event for that key
    while (1) { // watchdog will timeout causing a reset if the layout is buggy
        /* layer_mask_t new_layer = keyboard_get_layer_mask(kb_slot_id); */
        layer_mask_t new_layer = get_partial_layer_mask(kb_slot_id);

        if (new_layer != start_layer && !s_clear_sticky_keys) {
            keyboard->layer_changed = true;
            keyboard_interpret_layer_change(kb_slot_id, start_layer, new_layer);
            start_layer = new_layer;
            continue;
        } else {
            break;
        }
    }

    // wait until all layer and key events have been processed before handling
    // modifiers
    apply_mods();


    /* // if we changed layers, notify the host on the custom interface */
    /* if (keyboard->layer_changed) { */
    /*  cmd_send_layer(kb_slot_id); */
    /* } */

    memcpy(keyboard->matrix_prev, keyboard->matrix, keyboard->matrix_size);
}

void interpret_all_keyboard_matrices(void) {
    if (!s_has_dirty_matrix && !s_has_dirty_event_queue) {
        return;
    }

    s_has_dirty_event_queue = 0;

    // swap the writing event queue with the reading one, so we will now read
    // from the events written to the writing event queue
    s_read_event_queue = !s_read_event_queue;

    {
        uint8_t slot_id;
        for (slot_id = 0; slot_id < MAX_NUM_KEYBOARD_SLOTS; ++slot_id) {
            keyboard_interpret_matrix(slot_id);
        }
    }

    // TODO: probably need to loop here until the key event queue is empty / not changed
    s_key_event_queues[READ_EVENT_QUEUE()].length = 0;

    s_has_dirty_matrix = false;
}
