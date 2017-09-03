// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include "core/util.h"

void timer_init(void);
void timer_disable(void);
void timer_adjust(int32_t adj);

uint8_t timer_read8_ms(void);
uint16_t timer_read16_ms(void);
uint32_t timer_read_ms(void);

// Check to see if we have passed a given time.
// NOTE: To handle the wrapping nature of unsigned integers, we can only correctly
// check times that are less than half the size of data type. If difference is
// greater, it is assumed that this is a result of the `end_time` wrapping
// around instead of the timer expiring.
#define has_passed_time8(current_time, end_time) (\
    (current_time > end_time) && ((uint8_t)(current_time - end_time) < UINT8_MAX/2) \
)

#define has_passed_time16(current_time, end_time) (\
    (current_time > end_time) && ((uint16_t)(current_time - end_time) < UINT16_MAX/2) \
)

#define has_passed_time32(current_time, end_time) (\
    (current_time > end_time) && ((uint32_t)(current_time - end_time) < UINT32_MAX/2) \
)
