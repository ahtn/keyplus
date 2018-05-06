// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "efm8_util/delay.h"

// don't care too much if this isn't accurate
void efm8_delay_us(uint16_t us) {
    while (us--) {
		__asm
#if F_CPU >=  8000000ULL
			nop
			nop
#endif
#if F_CPU >= 16000000ULL
			nop
			nop
#endif
#if F_CPU >= 24000000ULL
			nop
			nop
			nop
			nop
#endif
#if F_CPU >= 32000000ULL
			nop
			nop
			nop
			nop
#endif
#if F_CPU >= 40000000ULL
			nop
			nop
			nop
			nop
#endif
#if F_CPU >= 48000000ULL
			nop
			nop
			nop
			nop
#endif
		__endasm;
    }
}

void efm8_delay_ms(uint16_t ms) {
    while (ms--) {
        efm8_delay_us(1000);
    }
}
