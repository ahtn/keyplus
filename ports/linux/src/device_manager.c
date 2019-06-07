// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)
/// @file linux/device_manager.c
/// @brief Manage udev and evdev events.

#include "device_manager.h"

#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>
#include <errno.h>

// See: https://www.freedesktop.org/software/libevdev/doc/latest/libevdev_8h.html
#include <libevdev/libevdev.h>

#include "core/timer.h"
#include "core/mouse.h"
#include "core/matrix_interpret.h"

#include "udev_helpers.h"
#include "virtual_input.h"
#include "event_mapper.h"
#include "debug.h"

#define MAX_EVENT_COUNT (MAX_NUM_DEVICES+1)
#define UNMAPPED_KEY 0xff

// TODO: move exit ability to a key_handler
#ifndef DEBUG_EXIT_KEY
    #define DEBUG_EXIT_KEY KEY_GRAVE
#endif
extern bool g_running;

static struct udev *m_udev = NULL;

static struct udev_monitor *m_udev_mon = NULL;
static int m_fd_udevmon;

/// List of file descriptors that we receive events from.
///
/// The first entry in the list is for the `udev_monitor` which detects when
/// devices are added/removed.
///
/// The entries after the first are fd to /dev/input/event devices which we
/// receive input from.
///
/// This array is used to directly in calls to `poll()`.
static struct pollfd m_event_fds[MAX_EVENT_COUNT];

/// The list of /dev/input/eventX devices that we are managing.
///
/// Note: the first entry in this array cannot be used. It is just a dummy
/// value so the indices in this array match to the file descriptors in the
/// `m_event_fds` array.
static struct kp_evdev_device m_dev_array[MAX_EVENT_COUNT];

/// The highest index in the `m_events_fds` array that points to a valid fd.
static unsigned int m_highest_event_count;

/// The number of devices being tracket
static size_t m_udev_targets_len;
/// The list of devices being tracket
virtual_device_header_t m_udev_targets[MAX_NUM_DEVICES];

/// Reset the list of tracked devices
void device_manager_targets_reset(void) {
    m_udev_targets_len = 0;
    memset(m_udev_targets, 0, sizeof(m_udev_targets));
}

/// Add a new device target to track
void device_manager_targets_add(virtual_device_header_t *target) {
    if (m_udev_targets_len == MAX_NUM_DEVICES) {
        KP_LOG_ERROR("too many devices added");
        exit(EXIT_FAILURE);
    }

    memcpy(&m_udev_targets[m_udev_targets_len],
           target,
           sizeof(virtual_device_header_t));
#if DEBUG >= 3
    hexDump ("virt_header", target, sizeof(virtual_device_header_t));
#endif

    m_udev_targets_len++;

}

/// Create a new `kp_evdev_device` with the given path
///
/// @param path         path to the /dev/input/eventX device
/// @param match_id     index into m_udev_targets array for the corresponding keyplus device
///
/// @return the index where it was placed in the device arrary, a negative value
///   on error
static int kp_evdev_array_add(const char *path, int match_id) {
    int rc;
    int fd = -1;
    struct libevdev *evdev = NULL;

    for (int i = 1; i < MAX_EVENT_COUNT; ++i) {
        if (m_event_fds[i].fd != -1) {
            continue;
        }

        // KP_ASSERT(m_dev_array[i] == NULL);

        fd = open(path, O_RDONLY);
        if (fd == -1) {
            KP_DEBUG_PRINT(1, "open() failed (%s)\n", strerror(-errno));
            rc = -errno;
            goto error;
        }

        rc = libevdev_new_from_fd(fd, &evdev);
        if (rc < 0) {
            KP_DEBUG_PRINT(1, "libevdev_new_from_fd() failed (%s)\n", strerror(-errno));
            goto error;
        }

        rc = libevdev_grab(evdev, LIBEVDEV_GRAB);
        if (rc < 0) {
            KP_DEBUG_PRINT(1, "libevdev_grab() failed (%s)\n", strerror(-errno));
            goto error;
        }

        m_dev_array[i].path = strdup(path);
        if (m_dev_array[i].path == NULL) {
            KP_LOG_ERROR("strdup failed (%s)", strerror(errno));
            rc = -errno;
            goto error;
        }

        {
            const uint8_t dev_id = m_udev_targets[match_id].dev_id;
            const uint8_t layout_id = GET_LAYOUT_ID_FOR_DEVICE(dev_id);

            m_event_fds[i].fd = fd;
            m_event_fds[i].events = POLLIN;
            m_event_fds[i].revents = 0;
            m_dev_array[i].evdev = evdev;
            m_dev_array[i].dev_id = dev_id;
            m_dev_array[i].layout_id = layout_id;
            m_highest_event_count = KP_MAX(m_highest_event_count, i+1);
        }

        return i;
    }

    rc = -ENOSPC;

error:
    if (evdev != NULL) {
        libevdev_free(evdev);
    }
    if (fd > 0) {
        close(fd);
    }
    return rc;
}

/// Check if an item occupies a given index
static inline bool kp_evdev_array_has_item_at(size_t i) {
    return (m_event_fds[i].fd != -1);
}

/// Get
static inline const char* kp_evdev_array_get_path(size_t i) {
    KP_ASSERT(i != 0);
    KP_ASSERT(i < MAX_EVENT_COUNT);
    KP_ASSERT(m_event_fds[i].fd != -1);

    return m_dev_array[i].path;
}

/// Free the device with the given index
static void kp_evdev_array_free_device(size_t i) {
    int rc;

    KP_ASSERT(i != 0);
    KP_ASSERT(i < MAX_EVENT_COUNT);
    KP_ASSERT(m_event_fds[i].fd != -1);

    libevdev_grab(m_dev_array[i].evdev, LIBEVDEV_UNGRAB);
    libevdev_free(m_dev_array[i].evdev);
    free(m_dev_array[i].path);
    // m_dev_array[i] = NULL;

    rc = close(m_event_fds[i].fd);
    m_event_fds[i].fd = -1;
    KP_CHECK_ERRNO(rc);
}

/// Find the device with the given path
///
/// @return the index of the device, or -1 if it does not exist
static int kp_evdev_array_find_path(const char *path) {
    for (int i = 1; i < m_highest_event_count; ++i) {
        if (!kp_evdev_array_has_item_at(i)) {
            continue;
        }

        if (strcmp(m_dev_array[i].path, path) == 0) {
            return i;
        }
    }
    return -1;
}

/// Free all
static void kp_evdev_array_free_all(void) {
    for (int i = 1; i < MAX_EVENT_COUNT; ++i) {
        if (!kp_evdev_array_has_item_at(i)) {
            continue;
        }
        kp_evdev_array_free_device(i);
    }
}

static void clear_poll_fds(struct pollfd *fds, size_t len) {
    for (int i = 0; i < len; ++i) {
        fds[i].fd = -1;
        fds[i].events = 0;
        fds[i].revents = 0;
    }
}

/// Free all resources used by the device manager
///
/// @return -1 on error, non-negative on success
int device_manager_init(void) {
	m_udev = udev_new();
	if (!m_udev) {
		KP_LOG_ERROR("Can't create udev");
		return -1;
	}

	m_udev_mon = udev_monitor_new_from_netlink(m_udev, "udev");
	udev_monitor_filter_add_match_subsystem_devtype(m_udev_mon, "input", NULL);
	udev_monitor_enable_receiving(m_udev_mon);
	m_fd_udevmon = udev_monitor_get_fd(m_udev_mon);


    clear_poll_fds(m_event_fds, MAX_EVENT_COUNT);

    // first slot in event array is for the udev device monitor
    m_event_fds[0].fd = m_fd_udevmon;
    m_event_fds[0].events = POLLIN;
    m_dev_array[0].path = NULL;
    m_dev_array[0].evdev = NULL;

    m_highest_event_count = 1;

    return 0;
}

/// Free all resources used by the device manager
void device_manager_free(void) {
    // free evdev devices
    kp_evdev_array_free_all();

    // free udev devices
    udev_monitor_unref(m_udev_mon);
    close(m_fd_udevmon);
    udev_unref(m_udev);
}

/// Check all currently connected devices and add them to the input list
///
/// @param targets  the list of devices we are interested
/// @param len  the number of targets
static int enumerate(struct udev *udev, virtual_device_header_t *targets, size_t len) {
    struct udev_enumerate *en;
    struct udev_list_entry *devices;

    int rc;

    en = udev_enumerate_new(udev);
    if (en == NULL) {
        KP_LOG_ERROR("udev_enumerate_new failed");
        return -1;
    }

    rc = udev_enumerate_add_match_subsystem(en, "input");
    if (rc < 0) {
        KP_LOG_ERROR("udev_enumerate_add_match_subsystem() failed");
        return -1;
    }

    rc = udev_enumerate_scan_devices(en);
    if (rc < 0) {
        KP_LOG_ERROR("udev_enumerate_scan_devices() failed");
        return -1;
    }

    devices = udev_enumerate_get_list_entry(en);
    if (!devices) {
        KP_LOG_ERROR("udev_enumerate_get_list_entry() failed");
        return -1;
    }

    struct udev_list_entry *entry;
    udev_list_entry_foreach(entry, devices) {
        const char* path;
        struct udev_device *dev;
        int match_id;
        int rc;

        path = udev_list_entry_get_name(entry);
        dev = udev_device_new_from_syspath(udev, path);

        match_id = kp_udev_match(dev, targets, len);
        if (match_id < 0) {
            udev_device_unref(dev);
            continue;
        }

        path = udev_device_get_property_value(dev, "DEVNAME");
        KP_DEBUG_PRINT(1, "adding %s\n", path);
        rc = kp_evdev_array_add(path, match_id);
        KP_ASSERT(rc > 0);

        #if defined(DEBUG) && DEBUG > 2
        {
            struct udev_list_entry *props;
            props = udev_device_get_properties_list_entry(dev);
            while (props != NULL) {
                KP_DEBUG_PRINT(3, "B: %s=%s\n",
                    udev_list_entry_get_name(props),
                    udev_list_entry_get_value(props));
                props = udev_list_entry_get_next(props);
            }
            KP_DEBUG_PRINT(3, "----------\n");
        }
        #endif

        /* free dev */
        udev_device_unref(dev);
    }

    udev_enumerate_unref(en);

    return 0;
}

/// Add all connected devices to the device manager
///
/// @return -1 on error, or 0 on success
int device_manager_enumerate(void) {
    return enumerate(m_udev, m_udev_targets, m_udev_targets_len);
}

/// Decide what to do when an input device has been added/removed
///
/// @return negative on error, 0 if the device was ignored, positive if a
///     device was added/removed
int handle_udev_event(void) {
    int rc;
    struct udev_device *dev = NULL;
    dev = udev_monitor_receive_device(m_udev_mon);

    KP_ASSERT(dev != NULL);

    // ignore devices that we aren't tracking
    int match_id = kp_udev_match(dev, m_udev_targets, m_udev_targets_len);
    if (match_id < 0) {
        rc = 0;
        goto cleanup;
    }

    KP_DEBUG_PRINT(3, "I: ACTION=%s\n", udev_device_get_action(dev));
    KP_DEBUG_PRINT(3, "I: SYSNAME=%s\n", udev_device_get_sysname(dev));
    KP_DEBUG_PRINT(3, "I: DEVPATH=%s\n", udev_device_get_devpath(dev));
    KP_DEBUG_PRINT(3, "I: DEVNAME=%s\n", udev_device_get_property_value(dev, "DEVNAME"));
    KP_DEBUG_PRINT(3, "I: ID_VENDOR_ID=%s\n", udev_device_get_property_value(dev, "ID_VENDOR_ID"));
    KP_DEBUG_PRINT(3, "I: ID_MODEL_ID=%s\n", udev_device_get_property_value(dev, "ID_MODEL_ID"));

    int act = kp_udev_parse_action(dev);
    if (act == UDEV_ACTION_ADD) {
        const char *path = udev_device_get_property_value(dev, "DEVNAME");
        if (path == NULL) {
            KP_LOG_ERROR("couldn't read DEVNAME");
            rc = 0;
        } else {
            KP_LOG_INFO("adding: %s\n", path);
            rc = kp_evdev_array_add(path, match_id);
            if (rc < 0) {
                KP_LOG_ERROR("couldn't open %s: %s", path, strerror(-rc));
            }
        }
    } else if (act == UDEV_ACTION_REMOVE) {
        const char *path;
        path = udev_device_get_property_value(dev, "DEVNAME");

        rc = kp_evdev_array_find_path(path);
        if (rc == -1) {
            KP_DEBUG_PRINT(1, "already removed: %s\n", path);
        } else {
            KP_DEBUG_PRINT(1, "removing: %s\n", path);
            kp_evdev_array_free_device(rc);
        }
    }

cleanup:
    // free dev
    udev_device_unref(dev);
    return rc;
}
static int map_event(int dev_id, struct input_event ev) {
    int rc;

#if DEBUG >= 1
    if (ev.type == EV_KEY && ev.code == DEBUG_EXIT_KEY) {
        g_running = false;
    }
#endif

    if (ev.type == EV_MSC) {
        return 0;
    }

    if (ev.type == EV_SYN) {
        return 0;
    }

    if ( ev.type == EV_REL) {
        const int v = ev.value;
        // rc = kp_virtual_mouse_send(ev.type, ev.code, ev.value);
        // KP_CHECK_ERRNO(rc);
        // rc = kp_virtual_mouse_send(EV_SYN, SYN_REPORT, 0);
        // KP_CHECK_ERRNO(rc);
        switch (ev.code) {
            case REL_X:             { mouse_move(v, 0, 0, 0); } break;
            case REL_Y:             { mouse_move(0, v, 0, 0); } break;
            case REL_WHEEL:         { mouse_move(0, 0, v, 0); } break;
            case REL_HWHEEL:        { mouse_move(0, 0, 0, v); } break;
            // case REL_WHEEL_HI_RES:  { mouse_move(0, 0, v/15, 0); } break;
            // case REL_HWHEEL_HI_RES: { mouse_move(0, 0, 0, v/15); } break;
            case REL_WHEEL_HI_RES:  { /* ignore for now */ } break;
            case REL_HWHEEL_HI_RES: { /* ignore for now */ } break;

            default: {
                KP_LOG_INFO("got unsupported EV_REL == %s<%d>",
                            libevdev_event_code_get_name(ev.type, ev.code),
                            ev.code);
            } break;

        }
    } else if (ev.type == EV_KEY && IS_MOUSE_EVENT(ev.code)) {
        uint8_t button_mask = MOUSE_EVENT_TO_MASK(ev.code);
        switch (ev.value) {
            case 0: mouse_unclick(button_mask); break;
            case 1: mouse_click(button_mask); break;
            case 2: break;
        }
    }

    if (ev.type == EV_KEY) {
        int key_num = mapper_event_to_key_num(dev_id, ev.code);
        if (key_num != UNMAPPED_KEY) {
            KP_DEBUG_PRINT(2, "%06u.%03u: Event(dev:%d): %s<0x%x> -> key_num<%d>, State: %d\n",
                (unsigned int)timer_read_ms() / 1000,
                (unsigned int)timer_read_ms() % 1000,
                dev_id,
                libevdev_event_code_get_name(ev.type, ev.code),
                ev.code,
                key_num,
                ev.value);

            if (ev.value != 2) {
                // Set the key number in its matrix
                keyboard_matrix_set_key(dev_id, key_num, ev.value);
                return 1;
            }
        } else {
            KP_DEBUG_PRINT(2, "%06u.%03u: Event(dev:%d): forwarding %s %d\n",
                (unsigned int)timer_read_ms() / 1000,
                (unsigned int)timer_read_ms() % 1000,
                dev_id,
                libevdev_event_code_get_name(ev.type, ev.code),
                ev.value);

            rc = kp_virtual_keyboard_send(ev.type, ev.code, ev.value);
            KP_CHECK_ERRNO(rc);
            rc = kp_virtual_keyboard_send(EV_SYN, SYN_REPORT, 0);
            KP_CHECK_ERRNO(rc);
        }
    } else {
        KP_DEBUG_PRINT(2,
            "%06u.%03u: Event(dev:%d): %s\t%s\t\t%d\n",
            (unsigned int)timer_read_ms() / 1000,
            (unsigned int)timer_read_ms() % 1000,
            dev_id,
            libevdev_event_type_get_name(ev.type),
            libevdev_event_code_get_name(ev.type, ev.code),
            ev.value);
    }

    return 0;
}

/// When an handle events for a given input device
static int handle_evdev_event(int i) {
    int rc;
    int updated = 0; // number of keys updated
    struct input_event ev;
    // int fd = m_event_fds[i].fd;
    struct libevdev *evdev = m_dev_array[i].evdev;
    m_event_fds[i].revents = 0;

    do {
        rc = libevdev_next_event(evdev, LIBEVDEV_READ_FLAG_BLOCKING, &ev);
        if (rc < 0) {
            KP_LOG_ERROR("error reading event %s", strerror(-rc));
            // exit(EXIT_FAILURE);
            return -1;
        }

        updated += map_event(m_dev_array[i].dev_id, ev);

    } while (libevdev_has_event_pending(evdev));

    return updated;
}

/// Check for any device events (input events, or device attach/remove)
///
/// @param
///
/// @return a negative errno on error, a positive integer if a input event was
///     detected, otherwise 0.
/// @return -EIO when reading on the udev_monitor fd fails
int device_manager_poll(bool block) {
    int rc;
    bool has_update = false;
    int delay_value = block ? -1 : 1;
    int messages_left;

    rc = poll(m_event_fds, m_highest_event_count, delay_value);
    if (rc < 0) {
        if (errno != EINTR) {
            KP_CHECK_ERRNO(rc);
        }
        return -errno;
    } else if (rc == 0) {
        return false;
    }

    messages_left = rc;

    for (int i = 0; messages_left > 0; ++i) {
        short revents = m_event_fds[i].revents;

        // ignore invalid fd value
        if (m_event_fds[i].fd == -1 || revents == 0) {
            continue;
        }

        messages_left--;

        // remove device on read() errors
        if (revents & (POLLERR | POLLHUP | POLLNVAL)) {
            KP_ASSERT(!(revents & POLLNVAL));

            if (i == 0) {
                KP_LOG_ERROR("udev device monitor read error\n");
                // NOTE: maybe we could try and recover here
                return -EIO;
            } else {
                const char* path = kp_evdev_array_get_path(i);

                KP_LOG_INFO("read error on %s, disconnecting it", path);
                // something has gone wrong, so we close the device to be safe
                kp_evdev_array_free_device(i);
            }
            continue;
        }

        // ignore devices without data
        if (!(revents & POLLIN)) {
            continue;
        }

        if (m_event_fds[i].fd == m_fd_udevmon) {
            handle_udev_event();
        } else if (m_event_fds[i].fd > 0) {
            rc = handle_evdev_event(i);
            if (rc > 0) {
                has_update = true;
            }
        }
    }

    return has_update;
}
