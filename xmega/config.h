// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#ifndef USB_VID
#define USB_VID 0x6666
#endif

#ifndef USB_PID
#define USB_PID 0x1111
#endif

#ifndef DEVICE_ID
#define DEVICE_ID 0
#endif

#ifndef USB_DEVICE_VERSION
#define USB_DEVICE_VERSION 0x0000
#endif

#ifndef VBUS_PORT
#define VBUS_PORT CHECK_PORT
#endif

#ifndef VBUS_PIN_MASK
#define VBUS_PIN_MASK CHECK_PIN
#endif

#define BOOTLOADER_VID 0x6666
#define BOOTLOADER_PID 0xB007


// TODO: move to settings
// TODO: an option to enter deep sleep when there has been no change in the matrix
// state for a long time
#define DEEP_SLEEP_TIME 3000

#define CONFIG_MATRIX_SCAN_MODE MATRIX_SCANNER_MODE_COL_ROW
#define CONFIG_MATRIX_ROW_COUNT 4
#define CONFIG_MATRIX_COL_COUNT 6

// TODO: Probably shouldn't do something else. Seems dangerous. Pull down and
// input?
// WARNING: Unused pins are pull low to save power. Before adding new
// hardware make sure these values are changed to prevent hardware damage.
// Note: this is only used if SET_FLOATING_PINS_LOW is nonzero.
#define SET_FLOATING_PINS_LOW 0
#define PORTA_FLOATING_PINS 0xff
#define PORTB_FLOATING_PINS 0x0f
#define PORTC_FLOATING_PINS 0x0f
#define PORTD_FLOATING_PINS 0x3f
/* #define PORTE_FLOATING_PINS 0x0c */
#define PORTE_FLOATING_PINS 0x00
#define PORTR_FLOATING_PINS 0x01

// 0ms trigger tim on release, 8ms debounce time
#define DEBOUNCE_PRESS_TIME 8
#define DEBOUNCE_PRESS_TRIGGER_TIME 0

// 0ms trigger time on release, 10ms debounce time
#define DEBOUNCE_RELEASE_TIME 20
#define DEBOUNCE_RELEASE_TRIGGER_TIME 2

#define SCANNER_MATRIX_DELTA 1
#define RF_POLLING 1
