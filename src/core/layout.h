// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include "config.h"
#include "core/flash.h"

#include "core/settings.h"

#include "core/flash.h"
#include "core/keycode.h"
#include "core/matrix_interpret.h"
#include "core/util.h"

#ifdef LAYOUT_VARIABLE_LOC
#define __LAYOUT_LOC
#define __LAYOUT_PADDING_LOC
#else
#define __LAYOUT_LOC AT(LAYOUT_ADDR)
#define __LAYOUT_PADDING_LOC AT(LAYOUT_ADDR + sizeof(layout))
#endif

#define LAYOUT_MAX_NUMBER_KEYBOARDS 64
#define LAYOUT_MAX_NUMBER_DEVICES 64

#define KEY_NUMBER_MAP_STORAGE_POS (g_layout_storage + 0)

AT__LAYOUT_ADDR
// extern ROM const keycode_t layout_storage[LAYOUT_SIZE/sizeof(keycode_t)];
extern ROM const uint8_t g_layout_storage[];
extern XRAM flash_ptr_t g_layout_storage_pos[MAX_NUM_KEYBOARDS];


void keyboard_layouts_init(void);
