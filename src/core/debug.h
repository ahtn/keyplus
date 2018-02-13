// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include "core/util.h"
#include <stdlib.h>

#if defined(DEBUG_LEVEL) && DEBUG_LEVEL >= 2
void init_debug(void);
void debug_toggle(uint8_t x);
void debug_set(uint8_t x, uint8_t val);
#else
#define init_debug() ((void) 0)
#define debug_toggle(x) ((void) 0)
#define debug_set(x, y) ((void) 0)
#endif

#if defined(DEBUG_LEVEL) && DEBUG_LEVEL >= 4
#define assert(x) ((x) ? (void)0 : assert_fail(__LINE__))
void assert_fail(uint16_t line_num) NO_RETURN_ATTR;
#else
#define assert(x) ((void)0)
#endif
