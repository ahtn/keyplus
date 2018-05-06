
#######################################################################
#                            USB AVR megas                            #
#######################################################################

ifeq ($(MCU), atmega8u2)
  MCU_STRING = ATmega8U2
  FLASH_SIZE = 0x2000
  BOOTSZ_TYPE = 0
else ifeq ($(MCU), atmega16u2)
  MCU_STRING = ATmega16U2
  FLASH_SIZE = 0x4000
  BOOTSZ_TYPE = 0
else ifeq ($(MCU), atmega32u2)
  MCU_STRING = ATmega32U2
  FLASH_SIZE = 0x8000
  BOOTSZ_TYPE = 0
else ifeq ($(MCU), atmega16u4)
  MCU_STRING = ATmega16U4
  FLASH_SIZE = 0x4000
  BOOTSZ_TYPE = 0
else ifeq ($(MCU), atmega32u4)
  MCU_STRING = ATmega32U4
  FLASH_SIZE = 0x8000
  BOOTSZ_TYPE = 0
else ifeq ($(MCU), atmega32u6)
  MCU_STRING = ATmega32U6
  FLASH_SIZE = 0x8000
  BOOTSZ_TYPE = 0
else ifeq ($(MCU), at90usb646)
  MCU_STRING = AT90USB646
  FLASH_SIZE = 0x10000
  BOOTSZ_TYPE = 1
else ifeq ($(MCU), at90usb647)
  MCU_STRING = AT90USB647
  FLASH_SIZE = 0x10000
  BOOTSZ_TYPE = 1
else ifeq ($(MCU), at90usb1286)
  MCU_STRING = AT90USB1286
  FLASH_SIZE = 0x20000
  BOOTSZ_TYPE = 1
else ifeq ($(MCU), at90usb1287)
  MCU_STRING = AT90USB1287
  FLASH_SIZE = 0x20000
  BOOTSZ_TYPE = 1
else
  $(error Error unsupported mcu='$(MCU)')
endif

ifeq ($(BOOTSZ_TYPE), 0)
  ifeq ($(BOOT_SIZE), 512)
    BOOTSZ = 11
  else ifeq ($(BOOT_SIZE), 1024)
    BOOTSZ = 10
  else ifeq ($(BOOT_SIZE), 2048)
    BOOTSZ = 01
  else ifeq ($(BOOT_SIZE), 4096)
    BOOTSZ = 00
  else
    $(error Unsupported BOOT_SIZE='$(BOOT_SIZE)')
  endif
else ifeq ($(BOOTSZ_TYPE), 1)
  ifeq ($(BOOT_SIZE), 1024)
    BOOTSZ = 11
  else ifeq ($(BOOT_SIZE), 2048)
    BOOTSZ = 10
  else ifeq ($(BOOT_SIZE), 4096)
    BOOTSZ = 01
  else ifeq ($(BOOT_SIZE), 8192)
    BOOTSZ = 00
  else
    $(error Unsupported BOOT_SIZE='$(BOOT_SIZE)')
  endif
endif

ifndef AVRDUDE_DEVICE_FUSES
    AVRDUDE_DEVICE_FUSES=\
        -U lfuse:w:"0x$(LFUSE)":m \
        -U hfuse:w:"0x$(HFUSE)":m \
        -U efuse:w:"0x$(EFUSE)":m
endif

ifndef AVRDUDE_DEVICE_LOCK
    AVRDUDE_DEVICE_LOCK=-U lock:w:"0x$(LOCKBITS)":m
endif
