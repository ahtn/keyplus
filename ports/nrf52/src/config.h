// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#ifndef USB_VID
#define USB_VID 0x1209
#endif

#ifndef USB_PID
#define USB_PID 0xBB00
#endif

#ifndef DEVICE_ID
#define DEVICE_ID 0
#endif

#ifndef USB_DEVICE_VERSION
#define USB_DEVICE_VERSION 0x0000
#endif

#if !defined(BOOTLOADER_VID) && !defined(BOOTLOADER_PID)
// TODO: lookup values for open and secure bootloader nrf52
#define BOOTLOADER_VID 0x6666
#define BOOTLOADER_PID 0x0001
#endif

#define SCANNER_MATRIX_DELTA 1

#define INTERNAL_SCAN_METHOD (MATRIX_SCANNER_INTERNAL_FAST_ROW_COL)

// Don't use the SPI handling provided by core/nrf24.c
#define NRF24_INBUILT_SPI_HANDLING 0

// Don't use the IRQ pin
#define RF_POLLING 1
