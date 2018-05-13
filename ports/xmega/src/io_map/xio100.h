#define PORT_A_NUM 0
#define PORT_B_NUM 1
#define PORT_C_NUM 2
#define PORT_D_NUM 3
#define PORT_E_NUM 4
#define PORT_F_NUM 5
#define PORT_H_NUM 6
#define PORT_J_NUM 7
#define PORT_K_NUM 8
#define PORT_Q_NUM 9
#define PORT_R_NUM 10

#define IO_PORT_COUNT 11
#define IO_PORT_MAX_PIN_NUM ( IO_MAP_PIN_NUMBER(PORT_R_NUM, 1) )

// #define PORTA    (*(PORT_t *) 0x0600)  /* Port A */
// #define PORTB    (*(PORT_t *) 0x0620)  /* Port B */
// #define PORTC    (*(PORT_t *) 0x0640)  /* Port C */
// #define PORTD    (*(PORT_t *) 0x0660)  /* Port D */
// #define PORTE    (*(PORT_t *) 0x0680)  /* Port E */
// #define PORTF    (*(PORT_t *) 0x06A0)  /* Port F */
// #define PORTH    (*(PORT_t *) 0x06E0)  /* Port H */
// #define PORTJ    (*(PORT_t *) 0x0700)  /* Port J */
// #define PORTK    (*(PORT_t *) 0x0720)  /* Port K */
// #define PORTQ    (*(PORT_t *) 0x07C0)  /* Port Q */
// #define PORTR    (*(PORT_t *) 0x07E0)  /* Port R */

#define PORT_TO_NUM(port) ( \
    (&port == &PORTA) ? (PORT_A_NUM) : \
    (&port == &PORTB) ? (PORT_B_NUM) : \
    (&port == &PORTC) ? (PORT_C_NUM) : \
    (&port == &PORTD) ? (PORT_D_NUM) : \
    (&port == &PORTE) ? (PORT_E_NUM) : \
    (&port == &PORTF) ? (PORT_F_NUM) : \
    (&port == &PORTH) ? (PORT_H_NUM) : \
    (&port == &PORTJ) ? (PORT_J_NUM) : \
    (&port == &PORTK) ? (PORT_K_NUM) : \
    (&port == &PORTQ) ? (PORT_Q_NUM) : \
    (&port == &PORTR) ? (PORT_R_NUM) : 255 \
)

#define PORT_A_USABLE_PINS 0xff
#define PORT_B_USABLE_PINS 0xff
#define PORT_C_USABLE_PINS 0xff
#define PORT_D_USABLE_PINS 0x3f // Can't use 7 and 6 because they are used for USB
#define PORT_E_USABLE_PINS 0xff
#define PORT_F_USABLE_PINS 0xff
#define PORT_H_USABLE_PINS 0xff
#define PORT_J_USABLE_PINS 0xff
#define PORT_K_USABLE_PINS 0xff
#define PORT_Q_USABLE_PINS 0x0f
#define PORT_R_USABLE_PINS 0x03

#define IO_MAP_GPIO_COUNT (78 - 2)

#ifndef IO_USABLE_PINS
#define IO_USABLE_PINS { \
    PORT_A_USABLE_PINS, \
    PORT_B_USABLE_PINS, \
    PORT_C_USABLE_PINS, \
    PORT_D_USABLE_PINS, \
    PORT_E_USABLE_PINS, \
    PORT_F_USABLE_PINS, \
    PORT_H_USABLE_PINS, \
    PORT_J_USABLE_PINS, \
    PORT_K_USABLE_PINS, \
    PORT_Q_USABLE_PINS, \
    PORT_R_USABLE_PINS, \
}
#endif
