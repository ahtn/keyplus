# Copyright 2019 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

MCU = nrf52840
MCU_STRING = nRF52840_QIAA
NRF52_LINK_SCRIPT := ld-scripts/plain_nrf52840.ld

C_SRC += \
    $(BOARD_DIR)/$(BOARD)/led.c

CDEFS += -DDEBUG


USE_SOFTDEVICE := 0
USE_BLUETOOTH := 0

USE_USB := 1
USE_SCANNER := 1
USE_NRF24 := 1
USE_NRF52_ESB := 1
USE_UNIFYING := 1
USE_CHECK_PIN := 0
USE_I2C := 0
