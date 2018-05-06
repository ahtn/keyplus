// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once
#include <stdint.h>

// The bootloader uses this magic value to determine if the bootloader was
// reset
#define BOOTLOADER_MAGIC_BOOT_RESET 0x36f51a68
extern uint32_t boot_magic;

enum {
    STATE_WAIT,
    STATE_GET_VERSION,
    STATE_WRITE,
    STATE_ERASE_ALL,
    STATE_GET_CRC,
    STATE_ERROR,
    STATE_WDT_RESET,
};

enum {
    CMD_GET_BOOT_INFO = 0x00,
    CMD_WRITE = 0x01,
    CMD_CRC = 0x02,
    CMD_RESET = 0x03,
    CMD_ERASE = 0x04,
    CMD_TEST = 0x05,
};

enum {
    PACKET_ERROR_STATUS  = 0x00,
    PACKET_CRC  = 0x01,
};

enum {
    OKAY = 0x00,
    ERROR = 0x01,
    ERROR_MISALIGNED = 0x02,
    ERROR_NOT_ERASED = 0x03,
};

typedef struct {
    uint32_t current;
    uint32_t remaining;
    uint16_t page_position;
} write_state_t;

typedef struct {
    uint8_t version_major;
    uint8_t version_minor;
    char mcu_string[32];
    uint32_t flash_size;
    uint16_t page_size;
    char _reserved[24];
} boot_info_t;


void run_bootloader(void);
