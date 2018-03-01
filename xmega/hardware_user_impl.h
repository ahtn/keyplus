// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>

#include "board_config.h"
#include "xmega_hardware.h"

#define static_delay_us(x) _delay_us(x)
#define static_delay_ms(x) _delay_ms(x)

#define enable_interrupts() do { \
    sei(); \
} while(0);

#define disable_interrupts() do { \
    cli(); \
} while(0);


#define PAGE_SIZE           APP_SECTION_PAGE_SIZE

// define flash pointer sizes
#if MCU_FLASH_SIZE <= 128
typedef uint16_t flash_ptr_t;
typedef uint16_t flash_size_t;
#else
typedef uint32_t flash_ptr_t;
typedef uint32_t flash_size_t;
#endif

#define MCU_BITNESS 8

typedef PORT_t io_port_t;

#if XMEGA_PIN_COUNT == 44

#define PORT_A_NUM 0
#define PORT_B_NUM 1
#define PORT_C_NUM 2
#define PORT_D_NUM 3
#define PORT_E_NUM 4
#define PORT_R_NUM 5

// #define PORTA    (*(PORT_t *) 0x0600)  /* I/O Ports */
// #define PORTB    (*(PORT_t *) 0x0620)  /* I/O Ports */
// #define PORTC    (*(PORT_t *) 0x0640)  /* I/O Ports */
// #define PORTD    (*(PORT_t *) 0x0660)  /* I/O Ports */
// #define PORTE    (*(PORT_t *) 0x0680)  /* I/O Ports */
// #define PORTR    (*(PORT_t *) 0x07E0)  /* I/O Ports */
#define PORT_TO_NUM(port) ( \
    ((uint16_t)&port == (uint16_t)&PORTA) ? (0) : \
    ((uint16_t)&port == (uint16_t)&PORTB) ? (1) : \
    ((uint16_t)&port == (uint16_t)&PORTC) ? (2) : \
    ((uint16_t)&port == (uint16_t)&PORTD) ? (3) : \
    ((uint16_t)&port == (uint16_t)&PORTE) ? (4) : \
    ((uint16_t)&port == (uint16_t)&PORTR) ? (5) : 255 \
)

#define IO_PORT_COUNT 6
#define IO_PORT_MAX_PIN_NUM ( IO_MAP_PIN_NUMBER(PORT_R_NUM, 1) )

#define PORT_A_USABLE_PINS 0xff
#define PORT_B_USABLE_PINS 0x0f
#define PORT_C_USABLE_PINS 0xff
#define PORT_D_USABLE_PINS 0x3f // Can't use 7 and 6 because they are used for USB
#define PORT_E_USABLE_PINS 0x0f
#define PORT_R_USABLE_PINS 0x03

#ifndef IO_USABLE_PINS
#define IO_USABLE_PINS { \
    PORT_A_USABLE_PINS, \
    PORT_B_USABLE_PINS, \
    PORT_C_USABLE_PINS, \
    PORT_D_USABLE_PINS, \
    PORT_E_USABLE_PINS, \
    PORT_R_USABLE_PINS, \
}
#endif

#else
#error "Message unsupported xmega size"
#endif
