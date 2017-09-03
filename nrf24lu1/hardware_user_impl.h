// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

// NOTE: not the best solution, but it's good enough
void dynamic_delay_us(uint16_t us);

#define static_delay_us(x) dynamic_delay_us(x)
#define static_delay_ms(x) dynamic_delay_ms(x)
