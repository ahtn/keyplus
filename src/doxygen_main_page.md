# keyplus source code documentation

This is the documentation for the keyplus source code. If all you want to learn
how to do is flash a layout file, see the [`keyplus_flasher` documentation(TODO)](#TODO).

| firmware module       | functions                                                          |
| --------------------- | ------------------------------------------------------------------ |
| @ref src/arch         | shared code for microcontroller architectures                      |
| @ref src/core         | core components for processing the keyboard matrix                 |
| @ref src/key_handlers | key handlers: responsible for mapping keycodes to functionality    |
| @ref src/settings     | (obsolete) configuration settings in c, replaced by python modules |
| @ref src/usb          | contains the USB descriptors and other utilities for usb           |
| @ref src/usb_reports  | code for sending/receiving USB reports                             |

Also, below is a list of different ports of keyplus to different microcontrollers.

| Microcontroller port  | description
| --------------------- | --------------------------------------------------------------- |
| @ref ports/xmega            | port for the AVR XMEGA A/B/C series microcontrollers            |
| @ref ports/nrf24lu1         | port for nRF24LU1+ wireless dongles                             |
| @ref ports/atmega32u4       | port for AVR MEGA usb microcontrollers                          |
| @ref ports/efm8             | port for EFM8 microcontrollers from Silicon Labs                |
| @ref ports/nrf52            | TODO                                                            |


keyplus has a software interface that runs on the host PC written in python.

| python module                     | functions                                                       |
| --------------------------------- | --------------------------------------------------------------- |
| @ref host-software                | TODO                                                            |
