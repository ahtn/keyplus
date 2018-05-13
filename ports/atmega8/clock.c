// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "clock.h"

inline void clock_fast(void) {
    clock_prescale_set(FAST_SPEED_DIV);
}

inline void clock_slow(void) {
    clock_prescale_set(SLOW_SPEED_DIV);
}
