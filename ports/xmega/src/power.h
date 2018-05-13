// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <stdbool.h>
#include <stdint.h>

#if USE_CHECK_PIN

#include "avr_util.h"

#ifndef VBUS_PORT
#define VBUS_PORT         DEF_AVR_PORT(VBUS_PIN_PORT)
#define VBUS_PIN_MASK     DEF_AVR_PIN_MASK(VBUS_PIN_NUM)
#define VBUS_INT_LVL      DEF_AVR_INT_LVL(VBUS_PIN_INT_NUM, HI)
#define VBUS_INT_LVL_MASK DEF_AVR_INT_LVL_MASK(VBUS_PIN_INT_NUM)
#define VBUS_INT_INTMASK  DEF_AVR_INT_INTMASK(VBUS_PIN_PORT, VBUS_PIN_INT_NUM)
#define VBUS_INT_VECT     DEF_AVR_INT_VECT(VBUS_PIN_PORT, VBUS_PIN_INT_NUM)
#endif

#endif

typedef enum {
    MODE_BATTERY,
    MODE_WIRED,
    MODE_USB,
    MODE_INIT,
} power_mode_t;

void set_power_mode(power_mode_t mode);
power_mode_t get_power_mode(void);

void vbus_pin_init(void);
bool has_vbus_power(void);
void check_pins_init(void);

void battery_mode_clock_init(void);
void enter_sleep_mode(uint8_t sleep_mode);
void deep_sleep(void);
