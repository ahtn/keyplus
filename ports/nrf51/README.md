# NRF51 Support

Support for the common nrf51 modules. Should work for receiving (needs extra hardware such as atmega32u4) and transmitting.

## Features todo

1. Add UART support and integrate with 32u4 for support of [mitosis receivers](https://github.com/reversebias/mitosis-hardware)
2. Encryption/decryption on nrf51 chip as it is faster than the 32u4. NRF51 has AES encryption hardware, but not decryption, so use [cifra](https://github.com/ctz/cifra) for that.
3. Compatibility with ESB protocol to work with all nrf24 based boards
4. *Maybe* write a bootloader for nrf51 so it can be updated over UART for the receiver. People with nrf51 based boards would still have to update the transmitters with a SWD programmer.
