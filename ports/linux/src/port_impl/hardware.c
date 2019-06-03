// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/hardware.h"

#include "debug.h"

void hardware_init(void) {

}

NO_RETURN_ATTR void bootloader_jmp(void) {
    KP_LOG_ERROR("called unsupported function bootloader_jmp()");
    exit(EXIT_FAILURE);
}

NO_RETURN_ATTR void reset_mcu(void) {
    KP_LOG_ERROR("called unsupported function reset_mcu()");
    exit(EXIT_FAILURE);
}
