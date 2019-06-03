// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "virtual_input.h"

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

// See: https://www.freedesktop.org/software/libevdev/doc/latest/libevdev_8h.html
#include <libevdev/libevdev.h>
#include <libevdev/libevdev-uinput.h>

#include "debug.h"
#include "hid_to_ev.h"

struct libevdev_uinput *m_virt_mouse;
struct libevdev_uinput *m_virt_kb;

int create_virtual_keyboard(void) {
    int err;
    struct libevdev *dev;
    dev = libevdev_new();
    libevdev_set_name(dev, "keyplus virtual keyboard");
    libevdev_enable_event_type(dev, EV_KEY);

    // load HID keyboard keys
    for (int i = 0; i < KB_EVENT_MAP_LEN; ++i) {
        int ev_code = HID_KB_TO_EV[i];

        if (ev_code == 0 || ev_code == KEY_UNKNOWN) {
            continue;
        }
        libevdev_enable_event_code(dev, EV_KEY, ev_code, NULL);
    }
    // load system keys
    for (int i = 0; i < SYSTEM_EVENT_MAP_LEN; ++i) {
        int ev_code = hid_system_to_ev(i + SYSTEM_MAP_OFFSET);

        if (ev_code == 0 || ev_code == KEY_UNKNOWN) {
            continue;
        }
        libevdev_enable_event_code(dev, EV_KEY, ev_code, NULL);
    }
    // load consumer keys
    for (int i = 0; i < CONSUMER_EVENT_MAP_LEN; ++i) {
        int ev_code = hid_consumer_to_ev(i);

        if (ev_code == 0 || ev_code == KEY_UNKNOWN) {
            continue;
        }
        libevdev_enable_event_code(dev, EV_KEY, ev_code, NULL);
    }
    err = libevdev_uinput_create_from_device(dev,
                                             LIBEVDEV_UINPUT_OPEN_MANAGED,
                                             &m_virt_kb);
    if (err != 0) {
        // Fatal error
        KP_LOG_ERROR("failed to create virtual keyboard: %s\n", strerror(-err));
        exit(EXIT_FAILURE);
    }

    libevdev_free(dev);
}

int create_virtual_mouse(void) {
    int err;
    struct libevdev *dev;
    dev = libevdev_new();
    libevdev_set_name(dev, "keyplus virtual mouse");

    // add mouse buttons
    libevdev_enable_event_type(dev, EV_KEY);
    libevdev_enable_event_code(dev, EV_KEY, BTN_LEFT, NULL);
    libevdev_enable_event_code(dev, EV_KEY, BTN_RIGHT, NULL);
    libevdev_enable_event_code(dev, EV_KEY, BTN_MIDDLE, NULL);
    libevdev_enable_event_code(dev, EV_KEY, BTN_SIDE, NULL);
    libevdev_enable_event_code(dev, EV_KEY, BTN_EXTRA, NULL);
    libevdev_enable_event_code(dev, EV_KEY, BTN_FORWARD, NULL);
    libevdev_enable_event_code(dev, EV_KEY, BTN_BACK, NULL);
    libevdev_enable_event_code(dev, EV_KEY, BTN_TASK, NULL);

    // add mouse
    libevdev_enable_event_type(dev, EV_REL);
    libevdev_enable_event_code(dev, EV_REL, REL_X, NULL);
    libevdev_enable_event_code(dev, EV_REL, REL_Y, NULL);
    libevdev_enable_event_code(dev, EV_REL, REL_HWHEEL, NULL);
    libevdev_enable_event_code(dev, EV_REL, REL_WHEEL, NULL);

    // libevdev_enable_event_type(dev, EV_SYN);

    err = libevdev_uinput_create_from_device(dev,
                                             LIBEVDEV_UINPUT_OPEN_MANAGED,
                                             &m_virt_mouse);
    if (err != 0) {
        // Fatal error
        KP_LOG_ERROR("failed to create virtual keyboard: %s", strerror(-err));
        exit(EXIT_FAILURE);
    }

    libevdev_free(dev);
}

int kp_virtual_keyboard_send(unsigned int type, unsigned int code, int value) {
    return libevdev_uinput_write_event(m_virt_kb, type, code, value);
}

int kp_virtual_mouse_send(unsigned int type, unsigned int code, int value) {
    return libevdev_uinput_write_event(m_virt_mouse, type, code, value);
}

void kp_virtual_keyboard_close(void) {
    libevdev_uinput_destroy(m_virt_kb);
}

void kp_virtual_mouse_close(void) {
    libevdev_uinput_destroy(m_virt_mouse);
}
