# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

ARCH_AVR_PATH = arch/avr

ifeq ($(USE_NRF24), 1)
C_SRC += \
         $(ARCH_AVR_PATH)/nonce.c
endif
