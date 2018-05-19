// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "efm8_util/io.h"

// Disable the watchdog timer
static inline
void efm8_watchdog_disable(void) {
    PCA0MD &= ~PCA0MD_WDTE__BMASK;
}
