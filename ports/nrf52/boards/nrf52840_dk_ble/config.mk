
LAYOUT_FILE ?= $(KEYPLUS_PATH)/../layouts/nrf52_4key.yaml
RF_FILE ?= $(KEYPLUS_PATH)/../layouts/test_rf_config2.yaml

MCU = nrf52840
MCU_STRING = nRF52840_QIAA
NRF52_LINK_SCRIPT := ld-scripts/s140_ble.ld

GDB_CMD_FILE = $(BOARD_DIR)/$(BOARD)/gdb_cmds

C_SRC += \
    $(BOARD_DIR)/$(BOARD)/led.c \


USE_SOFTDEVICE := 1
USE_BLUETOOTH := 1

USE_USB := 1
USE_SCANNER := 1
USE_NRF24 := 1
USE_NRF52_ESB := 1
USE_UNIFYING := 1
USE_CHECK_PIN := 0
USE_I2C := 0
