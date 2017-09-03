// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <stdint.h>

uint32_t uid_generate(void);

// implementation specific
uint16_t load_session_id(void);
uint16_t increment_session_id(void);
