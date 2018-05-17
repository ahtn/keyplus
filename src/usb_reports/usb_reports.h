// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)
/// @file
/// @brief USB endpoint abstraction layer.
///
/// These functions need to be implemented for each microcontroller port for
/// USB access.

#pragma once

#include "core/util.h"

/// Checks if a USB IN endpoint is ready to take more data
bit_t is_in_endpoint_ready(uint8_t endpoint_num);

/// Checks if a USB OUT endpoint has data
bit_t is_out_endpoint_ready(uint8_t endpoint_num);

/// Write to a USB IN endpoint
void usb_write_in_endpoint(
    uint8_t endpoint_num,
    const XRAM uint8_t *data,
    uint8_t length
);

/// Read from a USB OUT endpoint
void usb_read_out_endpoint(
    uint8_t endpoint_num,
    XRAM uint8_t *dest,
    uint8_t *length
);
