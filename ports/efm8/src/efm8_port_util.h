// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)
/// @file
///
/// @brief Functions for accessing the IO pins with indirect addressing
///
/// 8051 has no way to access SFR with indirect addressing. This modules
/// provide some functions for accessing the IO pins indirectly.

#include <stdint.h>

/// @brief Initialize an EFM8 port registers.
///
/// @param port_num The 8051 port number to setup
/// @param mdout The value to set the EFM8 PxMDOUT register for the port.
/// @param mdout The value to set the EFM8 PxMDIN register for the port.
void efm8_port_setup(uint8_t port_num, uint8_t mdout, uint8_t mdin);

/// @brief Reset the EFM8 IO port registers to their default state.
void efm8_reset_ports(void);

/// @brief Set bits in an 8051 port register
///
/// @param port_num The 8051 port number to write
void efm8_port_set(uint8_t port_num, uint8_t pin_mask);

/// @brief Clear bits in an 8051 port register
///
/// @param port_num The 8051 port number to write
void efm8_port_clear(uint8_t port_num, uint8_t pin_mask);

/// @brief Read bits from an 8051 port register
///
/// @param port_num The 8051 port number to read
uint8_t efm8_port_read(uint8_t port_num);
