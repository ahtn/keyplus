// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <stdlib.h>

#ifdef NDEBUG
#define init_debug() ((void) 0)
#define debug_toggle(x) ((void) 0)
#define debug_set(x, y) ((void) 0)
#else
void init_debug(void);
void debug_toggle(uint8_t x);
void debug_set(uint8_t x, uint8_t val);
#endif

#if defined(NDEBUG)
#define assert(x) ((void)0)
#else
#define assert(x) ((x) ? (void)0 : assert_fail())
void assert_fail(void) __ATTR_NORETURN__;
#endif
