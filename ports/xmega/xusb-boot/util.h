// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)


#pragma once

#include "config.h"

#include <stdint.h>

uint8_t read_production_signature_byte(uint16_t address);
char hexdigit_to_char(uint8_t d);
void software_reset(void);

void wdt_init(void);
void wdt_kick(void);
