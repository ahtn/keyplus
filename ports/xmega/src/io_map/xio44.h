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
    (&port == &PORTA) ? (PORT_A_NUM) : \
    (&port == &PORTB) ? (PORT_B_NUM) : \
    (&port == &PORTC) ? (PORT_C_NUM) : \
    (&port == &PORTD) ? (PORT_D_NUM) : \
    (&port == &PORTE) ? (PORT_E_NUM) : \
    (&port == &PORTR) ? (PORT_R_NUM) : 255 \
)

#define IO_PORT_COUNT 6
#define IO_PORT_MAX_PIN_NUM ( IO_MAP_PIN_NUMBER(PORT_R_NUM, 1) )

#define PORT_A_USABLE_PINS 0xff
#define PORT_B_USABLE_PINS 0x0f
#define PORT_C_USABLE_PINS 0xff
#define PORT_D_USABLE_PINS 0x3f // Can't use 7 and 6 because they are used for USB
#define PORT_E_USABLE_PINS 0x0f
#define PORT_R_USABLE_PINS 0x03

#define IO_MAP_GPIO_COUNT (34 - 2)

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
