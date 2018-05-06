# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

XMEGA_HARDWARE_PATH = xmega_hardware

ifeq ($(USE_I2C), 1)
C_SRC += $(XMEGA_HARDWARE_PATH)/twi_slave_driver.c
C_SRC += $(XMEGA_HARDWARE_PATH)/twi_master_driver.c
endif

ifeq ($(USE_NRF24), 1)
C_SRC += $(XMEGA_HARDWARE_PATH)/aes.c
endif
INC_PATHS += -I $(XMEGA_HARDWARE_PATH)
