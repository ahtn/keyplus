// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "stats.h"

#include "core/settings.h"

#include <libevdev/libevdev.h>

#include <stdio.h>
#include "event_mapper.h"
#include "debug.h"

#include "stats_parser.h"

#define STATS_UPDATE_COUNT 1000

struct device_stats m_dev_stats[MAX_NUM_DEVICES];

static int m_presses_since_update;
static const char *m_stats_file = NULL;

void stats_reset(void) {
    m_presses_since_update = 0;
    memset(m_dev_stats, 0, sizeof(m_dev_stats));
}

void stats_enable_device(uint8_t dev_id, bool enable) {
    if (enable) {
        m_dev_stats[dev_id].state = STATS_STATE_LOADED;
    } else {
        m_dev_stats[dev_id].state = STATS_STATE_DISABLED;
    }
}

void stats_add_key(uint8_t dev_id, int event_code) {
    if (m_dev_stats[dev_id].state == STATS_STATE_DISABLED) {
        return;
    }

    m_dev_stats[dev_id].state = STATS_STATE_LOADED;
    m_dev_stats[dev_id].keys[event_code] += 1;
    m_presses_since_update++;

    if (m_presses_since_update > STATS_UPDATE_COUNT) {
        stats_save(m_stats_file);
    }
}

void stats_set_press_count(uint8_t dev_id, int event_code, uint32_t press_count) {
    if (m_dev_stats[dev_id].state == STATS_STATE_DISABLED) {
        return;
    }

    m_dev_stats[dev_id].state = STATS_STATE_LOADED;
    m_dev_stats[dev_id].keys[event_code] = press_count;
}

void stats_load(const char* filename) {
    int rc;
    stats_reset();
    m_stats_file = filename;
    rc = parse_stats_file(filename);
    if (rc < 0 && rc != -ENOENT) { // ignore error if filed doesn't exist
        KP_LOG_ERROR("parsing stats file '%s' failed", filename);
    }
}

static int stats_write_dev(FILE *f, uint8_t dev_id) {
    int i, rc;
    char trail[] = ",";
    trail[0] = '\0'; // trail disabled

    rc = fprintf(f, "    {"); if (rc < 0) { return -errno; }
    for (i = 0; i < KEY_CNT; ++i) {
        uint16_t ev_code = i;
        uint16_t hid = mapper_ev_to_hid(ev_code);
        uint32_t press_count = m_dev_stats[dev_id].keys[ev_code];
        const char *hid_name;

        if (press_count == 0) {
            continue;
        }

        if (hid == HID_CODE_UNKNOWN) {
            KP_LOG_WARN("stats ignoring %s(%04x): %d press",
                        libevdev_event_code_get_name(EV_KEY, ev_code),
                        ev_code,
                        press_count);
            continue;
        }

        hid_name = get_hid_code_name(hid);
        if (hid_name == NULL) {
            KP_LOG_WARN("stats ignoring HID(%04x): %d presses", hid, press_count);
            continue;
        }

        rc = fprintf(f, "%s\n      \"%s\": %d",
                     trail,
                     hid_name,
                     press_count);
        if (rc < 0) {
            return -errno;
        }
        trail[0] = ','; // trail enabled
    }

    if (trail[0] == '\0') {
        rc = fprintf(f, "}"); if (rc < 0) { return -errno; }
    } else {
        rc = fprintf(f, "\n    }"); if (rc < 0) { return -errno; }
    }

    return 0;
}

int stats_write(FILE *f) {
    int rc;
    int i;
    int highest_loaded = 0;

    m_presses_since_update = 0;

    for (int i = 0; i < MAX_NUM_DEVICES; ++i) {
        if (m_dev_stats[i].state == STATS_STATE_LOADED) {
            highest_loaded = i;
        }
    }

    rc = fprintf(f, "{\n"); if (rc < 0) { return -errno; }
    rc = fprintf(f, "  \"devices\": [\n"); if (rc < 0) { return -errno; }
    // write the first device
    rc = stats_write_dev(f, 0);
    if (rc < 0) {
        return rc;
    }
    for (i = 1; i <= highest_loaded; ++i) {
        rc = fprintf(f, ",\n"); if (rc < 0) { return -errno; }
        rc = stats_write_dev(f, i);
        if (rc < 0) {
            return rc;
        }
    }
    rc = fprintf(f, "\n  ]\n"); if (rc < 0) if (rc < 0) { return -errno; }
    rc = fprintf(f, "}\n"); if (rc < 0) { return -errno; }

    return 0;
}

/// Save the usage statistics to the given file
///
/// @param filename     The file to save to. If NULL, save to the file that
///     was loaded from when `stats_load()' is called.
void stats_save(const char* filename) {
    FILE *file;
    int rc;

    if (filename == NULL) {
        KP_ASSERT(m_stats_file != NULL);
        filename = m_stats_file;
    }

    // KP_DEBUG_PRINT(1, "writing stats to %s\n", filename);
    file = fopen(filename, "w+");
    if (file == NULL) {
        KP_LOG_ERROR("failed to open stats file %s: %s", filename, strerror(errno));
        return;
    }

    rc = stats_write(file);
    if (rc < 0) {
        KP_LOG_ERROR("failed to write to stats.json: %s", strerror(errno));
    }

    fflush(file);
    fclose(file);
}
