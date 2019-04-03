// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "key_handlers/key_handlers.h"

#include "key_handlers/key_custom.h"
#include "key_handlers/key_hold.h"
#include "key_handlers/key_media.h"
#include "key_handlers/key_mouse.h"
#include "key_handlers/key_normal.h"
#include "key_handlers/key_macro.h"

/* #define MAX_NUM_EVENTS 64 */

/* XRAM uint8_t g_event_count = 0; */
/* XRAM timed_event_t g_event_list[MAX_NUM_EVENTS]; */

// time: the amount of time before the event will happen
// keycode: the keycode associated with the event
// event: the event to be passed to the key_handler
void add_timed_event(keycode_t keycode, uint16_t time, uint8_t event);

/* bit_t has_event_elapsed(uint16_t t) { */
/*  uint16_t t_now = timer_read(); */

/*  if ( */
/* } */

/* void handle_timed_events(void) { */
/*  uint8_t i = 0; */
/*  while (i < g_event_count) { */
/*      if ((uint16_t)(timer_read() - g_event_list[i].time_outvalue) */
/*  } */
/* } */

XRAM keycode_callbacks_t *XRAM g_keyhandler_list[] WEAK = {
    &modkey_keycodes,
    &layer_keycodes,
    &hold_keycodes,
    &mouse_keycodes,
    &media_keycodes,
    &custom_keycodes,
#if SUPPORT_MACRO
    &macro_keycodes,
#endif
    NULL,
};
