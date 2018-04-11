// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <util/delay.h>

#if F_CPU == 48000000UL
#define PARASITIC_DISCHARGE_DELAY_FAST_CLOCK(x) do {\
    _delay_loop_1(x); \
    _delay_loop_1(x); \
    _delay_loop_1(x); \
} while(0)
#elif F_CPU == 32000000UL
#define PARASITIC_DISCHARGE_DELAY_FAST_CLOCK(x) do {\
    _delay_loop_1(x); \
    _delay_loop_1(x); \
} while(0)
#elif F_CPU == 16000000UL
#define PARASITIC_DISCHARGE_DELAY_FAST_CLOCK(x) do {\
    _delay_loop_1(x); \
} while(0)
#elif F_CPU ==  8000000UL
#define PARASITIC_DISCHARGE_DELAY_FAST_CLOCK(x) do {\
    _delay_loop_1(x/2); \
} while(0)
#elif F_CPU ==  4000000UL
#define PARASITIC_DISCHARGE_DELAY_FAST_CLOCK(x) do {\
    _delay_loop_1(x/4); \
} while(0)
#elif F_CPU ==  2000000UL
#define PARASITIC_DISCHARGE_DELAY_FAST_CLOCK(x) do {\
    _delay_loop_1(x/8); \
} while(0)
#elif F_CPU ==  1000000UL
#define PARASITIC_DISCHARGE_DELAY_FAST_CLOCK(x) do {\
    _delay_loop_1(x/16); \
} while(0)
#else
#error "Unsupported clock speed for PARASITIC_DISCHARGE_DELAY"
#endif

#define PARASITIC_DISCHARGE_DELAY_SLOW_CLOCK(x) do {\
    _delay_loop_1(x); \
} while(0)
