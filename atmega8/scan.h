// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include "config.h"
#include <stdbool.h>

void matrix_init(void);
bool matrix_scan_slow(void);
void matrix_interrupt_mode(void);
