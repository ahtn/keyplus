// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <stdint.h>

#include "core/keycode.h"
#include "core/util.h"

void add_pure_mods(uint8_t mods);
void del_pure_mods(uint8_t mods);
void add_fake_mods(uint8_t mods);
void del_fake_mods(uint8_t mods);

void reset_mods(void);
uint8_t get_mods(void);
uint8_t has_pure_mods(void);
void apply_mods(void);
