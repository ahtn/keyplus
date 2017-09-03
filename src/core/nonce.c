// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/nonce.h"

#include "core/util.h"

typedef struct uid_state_t {
    uint16_t counter;
    uint16_t session_id;
} uid_state_t;

static XRAM uid_state_t uid_state;
static XRAM uint8_t sid_is_loaded = false;

/* TODO: For master ID, make sure it updates the session ID
 * when uid_counter overflows. */
uint32_t uid_generate(void) {
    if (!sid_is_loaded) {
        uid_state.session_id = increment_session_id();
        sid_is_loaded = true;
    } else {
        if (uid_state.counter == UINT16_MAX) {
            uid_state.session_id = increment_session_id();
        }
        uid_state.counter++;
    }
    return (((uint32_t)uid_state.session_id) << 16) | uid_state.counter;
}

