// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/timer.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

static inline time_t ms_time(void) {
    int rc;
    struct timespec tp;

    rc = clock_gettime(CLOCK_MONOTONIC, &tp);
    if (rc < 0) {
        perror("clock_gettime() failed");
        exit(EXIT_FAILURE);
    }
    return tp.tv_sec*1000 + (tp.tv_nsec / (1000*1000));
}

uint8_t timer_read8_ms(void) {
    return ms_time();
}

uint16_t timer_read16_ms(void) {
    return ms_time();
}

uint32_t timer_read_ms(void) {
    return ms_time();
}
