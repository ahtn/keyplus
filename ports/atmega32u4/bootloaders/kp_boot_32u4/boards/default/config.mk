ifndef MCU
  MCU = atmega32u4
endif

ifndef BOOT_SIZE
  BOOT_SIZE = 1024
endif

TARGET_BASE_NAME := $(TARGET_BASE_NAME)-$(BOOT_SIZE)
