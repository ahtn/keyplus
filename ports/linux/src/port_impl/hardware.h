#pragma once

#include <stddef.h>

#define F_CPU 0

#define enable_interrupts()
#define disable_interrupts()

#define MCU_BITNESS 8
#define IO_PORT_MAX_PIN_NUM 0
#define IO_PORT_COUNT 0
#define IO_MAP_GPIO_COUNT 0
#define IO_USABLE_PINS {}

#define SETTINGS_ADDR (0)
#define LAYOUT_ADDR (SETTINGS_SIZE)
#define LAYOUT_SIZE (4096 * 4)

#define PAGE_SIZE 4096

typedef int io_port_t;

typedef size_t flash_addr_t;
typedef size_t flash_size_t;
typedef size_t flash_ptr_t;
