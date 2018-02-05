# keyplus source code documentation

This is the documentation for the keyplus source code. If all you want to learn
how to flash a layout file, see the [`keyplus_flasher` documentation(TODO)](#TODO).

| firmware module       | functions                                                       |
| --------------------- | --------------------------------------------------------------- |
| @ref src/core         | core components for processing the keyboard matrix              |
| @ref src/key_handlers | key handlers: responsible for mapping keycodes to functionality |
| @ref src/usb          | contains the usb descriptors and other utilities for usb        |

Also, below is a list of different ports of keyplus to different microcontrollers.

| mcu port              | description
| --------------------- | --------------------------------------------------------------- |
| @ref nrf24lu1         | port for nRF24LU1+ wireless dongles                             |
| @ref xmega            | port for the AVR xmega A/B/C series mcu                         |
| @ref atmega32u4       | TODO                                                            |
| @ref nrf52840         | TODO                                                            |
| @ref efm8             | TODO                                                            |


keyplus has a control interface that runs on the host PC written in python.

| python module                     | functions                                                       |
| --------------------------------- | --------------------------------------------------------------- |
| @ref host-software                | TODO                                                            |
| @ref host-software/layout         | TODO                                                            |
