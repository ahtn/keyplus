// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "settings_loader.h"

#include "event_mapper.h"
#include "device_manager.h"

#include "debug.h"

void load_virtual_device_settings(void) {
    flash_addr_t pos;
    uint32_t size;

    mapper_reset();
    device_manager_targets_reset();

    pos = LAYOUT_ADDR;
    flash_read((uint8_t*)&size, pos, sizeof(uint32_t));
    pos += sizeof(uint32_t);

    KP_ASSERT(is_valid_storage_pos(pos + size));

    while (pos < size) {
        struct virtual_device_header_t dev;
        flash_read((uint8_t*)&dev, pos, sizeof(dev));
        device_manager_targets_add(&dev);
        pos += sizeof(virtual_device_header_t);

        mapper_set_map(dev.dev_id, virtual_storage_get_address(pos));
        pos += KEY_MAP_SIZE;
    }
}

