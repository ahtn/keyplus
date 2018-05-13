// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include <stdint.h>

#include <avr/io.h>

// NOTE: we store each nonce value in a different page, to reduce the chance
// that all the values get corrupted at once.
#define EEPROM_NONCE_0       (uint16_t*)(EEPROM_PAGE_SIZE*1 + 0)
#define EEPROM_NONCE_1       (uint16_t*)(EEPROM_PAGE_SIZE*2 + 0)
#define EEPROM_NONCE_2       (uint16_t*)(EEPROM_PAGE_SIZE*3 + 0)
