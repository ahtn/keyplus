// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <stdbool.h>

#include "core/settings.h"

#include "udev_helpers.h"

struct kp_evdev_device {
    int dev_id;
    int layout_id;
    char *path;
    struct libevdev *evdev;
};

int device_manager_init(void);
void device_manager_free(void);

void device_manager_targets_reset(void);
void device_manager_targets_add(virtual_device_header_t *target);

int device_manager_enumerate(void);
int device_manager_poll(bool block);
