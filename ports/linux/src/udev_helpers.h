// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <libudev.h>

typedef enum udev_action {
    UDEV_ACTION_ADD,
    UDEV_ACTION_REMOVE,
    UDEV_ACTION_CHANGE,
    UDEV_ACTION_ONLINE,
    UDEV_ACTION_OFFLINE,
} udev_action_type;

typedef struct kp_udev_info {
    int kb_id; //< keyboard id to link to
    uint16_t vid; //< usb/hid vendor id
    uint16_t pid; //< usb/hid product id
    const char *serial; //< usb/hid serial number
    const char *name; //< usb/hid device name
} kp_udev_info;

int kp_udev_parse_action(struct udev_device *dev);
int kp_udev_match(struct udev_device *dev, struct kp_udev_info **targets, size_t len);

