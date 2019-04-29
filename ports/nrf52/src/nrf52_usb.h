// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

void usb_setup_nrf(void);

bool is_usb_configured(void);
bool is_usb_suspended(void);
bool is_usb_remote_wakeup_enabled(void);
void usb_init_power_clock(void);
