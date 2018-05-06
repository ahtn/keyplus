// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#define EP0_SIZE 64

// Prototype ID: 6666:B007
// #define USB_VID 0x6666
// #define USB_PID 0xB007

// Keyplus xusb-boot ID: 1209:BB01
#define USB_VID 0x1209
#define USB_PID 0xBB01

#define VERSION_MAJOR 1
#define VERSION_MINOR 0

// When this value is defined, we enter the bootloader regardless of the check
// pin. If a USB detection is not detected in `WATCH_DOG_PERIOD`, then it will
// reset again into the application code.
// #define NO_CHECKPIN

#ifndef CHECK_PIN
#define CHECK_PIN PIN1_bm
#endif

#ifndef CHECK_PORT
#define CHECK_PORT PORTR
#endif

// number ULP OSC cylces (1KHz -> 1s) before watch dog overflow
#define WATCH_DOG_PERIOD WDT_PER_2KCLK_gc
