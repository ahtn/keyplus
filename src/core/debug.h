// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)
/// @file core/debug.h
///
/// Utility macros and functions for debugging.
///
/// The `DEBUG_LEVEL` macro can be used to set the amount of debug features
/// compiled into the code (passed from make command). If it is not defined
/// or 0, debug features are disabled.

#pragma once

#include "core/util.h"
#include <stdlib.h>

#if defined(DEBUG_LEVEL) && DEBUG_LEVEL >= 2
/// Initialize debug code
void init_debug(void);

/// Toggle the state of a debug pin for reading with logic analyzer or LED
void debug_toggle(uint8_t x);

/// Set the state of a debug pin for reading with logic analyzer or LED
void debug_set(uint8_t x, uint8_t val);
#else
#define init_debug() ((void) 0)
#define debug_toggle(x) ((void) 0)
#define debug_set(x, y) ((void) 0)
#endif

#if defined(DEBUG_LEVEL) && DEBUG_LEVEL >= 4
#define assert(x) ((x) ? (void)0 : assert_fail(__LINE__))
/// Hang the CPU when an assertion fails.
///
/// Will try to print the cause of the hang if a mechanism is provided on
/// the given firmware port.
void assert_fail(uint16_t line_num) NO_RETURN_ATTR;
#else
#define assert(x) ((void)0)
#endif
