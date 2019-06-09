#include "udev_helpers.h"

#include <string.h>

#include "debug.h"

int kp_udev_parse_action(struct udev_device *dev) {
    if (strcmp("add", udev_device_get_action(dev)) == 0) {
        return UDEV_ACTION_ADD;
    }

    if (strcmp("remove", udev_device_get_action(dev)) == 0) {
        return UDEV_ACTION_REMOVE;
    }

    if (strcmp("change", udev_device_get_action(dev)) == 0) {
        return UDEV_ACTION_CHANGE;
    }

    if (strcmp("online", udev_device_get_action(dev)) == 0) {
        return UDEV_ACTION_ONLINE;
    }

    if (strcmp("offline", udev_device_get_action(dev)) == 0) {
        return UDEV_ACTION_OFFLINE;
    }

    return -1;
}

/* Example struct for bluetooth keyboard device
---------- parent
B: DEVPATH=/devices/virtual/misc/uhid/0005:1209:BB00.0006/input/input15
B: EV=120013
B: ID_BUS=bluetooth
B: ID_INPUT=1
B: ID_INPUT_KEY=1
B: ID_INPUT_KEYBOARD=1
B: KEY=1000000000007 ff980000000007ff febeffdfffefffff fffffffffffffffe
B: LED=1f
B: MODALIAS=input:b0005v1209pBB00e0000-e0,1,4,11,14,k71,72,73,74,75,77,79,7A,7B,7C,7D,7E,7F,80,81,82,83,84,85,86,87,88,89,8A,B3,B4,B7,B8,B9,BA,BB,BC,BD,BE,BF,C0,C1,C2,F0,ram4,l0,1,2,3,4,sfw
B: MSC=10
B: NAME="Nordic_Keyboard"
B: PHYS="A4:C3:F0:88:65:8E"
B: PRODUCT=5/1209/bb00/0
B: PROP=0
B: SUBSYSTEM=input
B: TAGS=:udev-acl:uaccess:seat:
B: UNIQ="CC:12:81:0B:B2:73"
B: USEC_INITIALIZED=122294281
---------- child
B: DEVNAME=/dev/input/event10
B: DEVPATH=/devices/virtual/misc/uhid/0005:1209:BB00.0006/input/input15/event10
B: ID_BUS=bluetooth
B: ID_INPUT=1
B: ID_INPUT_KEY=1
B: ID_INPUT_KEYBOARD=1
B: LIBINPUT_DEVICE_GROUP=5/1209/bb00:A4:C3:F0:88:65:8E
B: MAJOR=13
B: MINOR=74
B: SUBSYSTEM=input
B: TAGS=:seat:udev-acl:uaccess:power-switch:
B: USEC_INITIALIZED=122348771
----------
*/

static void kp_udev_info_bluetooth_get(struct udev_device *dev,
                                       struct kp_udev_info *info) {
    int rc;
    const char *prop;

    // Access the parent input device instead, see example output above
    // for the available information.
    //
    // NOTE: no need to unref this, will be unref with the child
    struct udev_device *parent = udev_device_get_parent(dev);

    // PRODUCT contains VID and PID e.g:  PRODUCT=5/1209/bb00/0
    prop = udev_device_get_property_value(parent, "PRODUCT");
    if (prop != NULL) {
        unsigned int vid, pid;
        rc = sscanf(prop, "%*x/%04x/%04x/%*x", &vid, &pid);
        if (rc <= 0) {
            info->vid = 0;
            info->pid = 0;
        } else {
            info->vid = vid;
            info->pid = pid;
        }
    }

    info->name = udev_device_get_property_value(parent, "NAME");
    info->serial = udev_device_get_property_value(parent, "UNIQ");
}

static void kp_udev_info_usb_get(struct udev_device *dev, struct kp_udev_info *info) {
    int rc;
    const char *prop;

    // NOTE: no need to unref this, will be unref with the child
    struct udev_device *parent = udev_device_get_parent(dev);

    // vendor id
    prop = udev_device_get_property_value(parent, "ID_VENDOR_ID");
    if (prop != NULL) {
        unsigned int vid;
        rc = sscanf(prop, "%04x", &vid);
        if (rc < 0) {
            info->vid = 0;
        } else {
            info->vid = vid;
        }
    }

    // product id
    prop = udev_device_get_property_value(parent, "ID_MODEL_ID");
    if (prop != NULL) {
        unsigned int pid;
        rc = sscanf(prop, "%04x", &pid);
        if (rc < 0) {
            info->pid = 0;
        } else {
            info->pid = pid;
        }
    }

    info->name = udev_device_get_property_value(parent, "NAME");
    info->serial = udev_device_get_property_value(parent, "ID_SERIAL_SHORT");
}

static void kp_udev_info_get(struct udev_device *dev, struct kp_udev_info *info) {
    const char *prop;

    info->vid = 0;
    info->pid = 0;
    info->name = NULL;
    info->serial = NULL;

    prop = udev_device_get_property_value(dev, "ID_BUS");
    if (prop == NULL) {
        return;
    }

    // check what bus type we are using
    if (strcmp(prop, "usb") == 0) {
        kp_udev_info_usb_get(dev, info);
    } else if (strcmp(prop, "bluetooth") == 0) {
        kp_udev_info_bluetooth_get(dev, info);
    }
    // TODO: handle HID over I2C for laptop keyboards
}

/// Check if `dev` matches against any of the elements in `targets`
///
/// @return Return the id of the match or -1 on no match.
int kp_udev_match(struct udev_device *dev, virtual_device_header_t *targets, size_t len) {
    struct kp_udev_info new_dev;

    KP_ASSERT(dev != NULL);

    // keyplus only cares about evdev devices
    if (strncmp("event", udev_device_get_sysname(dev), 5) != 0) {
        return -1;
    }

    kp_udev_info_get(dev, &new_dev);
    KP_DEBUG_PRINT(3, "match against {vid:%x, pid: %x, name:%s, serial%s}\n",
                new_dev.vid, new_dev.pid, new_dev.name, new_dev.serial);

    // Match against each target. If a field is not set, ignore it.
    for (int i = 0; i < len; ++i) {
        int vid, pid;
        const char *target_str;

        KP_ASSERT(dev != NULL);

        KP_DEBUG_PRINT(3, "  cmp {vid:%x, pid: %x, name:%s, serial%s}\n",
                    targets[i].vid, targets[i].pid, targets[i].name, targets[i].serial);

        vid = targets[i].vid;
        if (vid != 0 && vid != new_dev.vid) {
            continue;
        }

        pid = targets[i].pid;
        if (pid != 0 && pid != new_dev.pid) {
            continue;
        }

        target_str = targets[i].name;
        if ((uint8_t)target_str[0] != 0xff && strstr(new_dev.name, target_str) == NULL) {
            KP_DEBUG_PRINT(2, "ignoring %s\n", new_dev.name);
            continue;
        }

        target_str = targets[i].serial;
        if ((uint8_t)target_str[0] != 0xff && strstr(new_dev.serial, target_str) == NULL) {
            continue;
        }

        // if we reach here, all fields matched
        return i;
    }

    // couldn't find a match
    return -1;
}
