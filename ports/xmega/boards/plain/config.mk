# Build

ifndef MCU
    MCU = atxmega32a4u
endif

C_SRC += # extra includes

USE_USB := 1
USE_SCANNER := 1
USE_NRF24 := 0
USE_UNIFYING := 0
USE_CHECK_PIN := 0
USE_I2C := 0
USE_HARDWARE_SPECIFIC_SCAN := 0
