#######################################################################
#                 settings for different xmega chips                  #
#######################################################################

FUSE_SECTION_START=0x08F0020

# see avr-gcc for information on avrxmega2, avrxmega4, etc
# NOTE: haven't tested on all these chips
ifeq ($(MCU), atxmega16a4u)
  BOOT_SECTION_START = 0x004000
  BOOTLOADER_SIZE = 0x1000
  AVRDUDE_PART = x16a4
  LD_SCRIPT = avrxmega2.xn
  MCU_STRING = ATxmega16A4U
  MCU_FLASH_SIZE = 16
  XMEGA_PIN_COUNT = 44
  XMEGA_SERIES = A
else ifeq ($(MCU), atxmega32a4u)
  BOOT_SECTION_START = 0x008000
  BOOTLOADER_SIZE = 0x1000
  AVRDUDE_PART = x32a4
  LD_SCRIPT = avrxmega2.xn
  MCU_STRING = ATxmega32A4U
  MCU_FLASH_SIZE = 32
  XMEGA_PIN_COUNT = 44
  XMEGA_SERIES = A
else ifeq ($(MCU), atxmega64a4u)
  BOOT_SECTION_START = 0x010000
  BOOTLOADER_SIZE = 0x1000
  AVRDUDE_PART = x64a4
  LD_SCRIPT = avrxmega4.xn
  MCU_STRING = ATxmega64A4U
  MCU_FLASH_SIZE = 64
  XMEGA_PIN_COUNT = 44
  XMEGA_SERIES = A
else ifeq ($(MCU), atxmega128a4u)
  BOOT_SECTION_START = 0x020000
  BOOTLOADER_SIZE = 0x2000
  AVRDUDE_PART = x128a4
  MCU_STRING = ATxmega128A4U
  MCU_FLASH_SIZE = 128
  LD_SCRIPT = avrxmega7.xn
  XMEGA_PIN_COUNT = 44
  XMEGA_SERIES = A
else ifeq ($(MCU), atxmega32c3)
  BOOT_SECTION_START = 0x008000
  BOOTLOADER_SIZE = 0x1000
  AVRDUDE_PART = x32c3
  LD_SCRIPT = avrxmega2.xn
  MCU_STRING = ATxmega32C3
  MCU_FLASH_SIZE = 32
  XMEGA_PIN_COUNT = 64
  XMEGA_SERIES = C
else ifeq ($(MCU), atxmega64c3)
  BOOT_SECTION_START = 0x010000
  BOOTLOADER_SIZE = 0x1000
  AVRDUDE_PART = x64c3
  LD_SCRIPT = avrxmega4.xn
  MCU_STRING = ATxmega64C3
  MCU_FLASH_SIZE = 64
  XMEGA_PIN_COUNT = 64
  XMEGA_SERIES = C
else
  $(error No part matches MCU='$(MCU)' (note needs to be lower case))
endif

CDEFS += -DMCU_FLASH_SIZE=$(MCU_FLASH_SIZE)
CDEFS += -DMCU_STRING=\"$(MCU_STRING)\"
CDEFS += -DXMEGA_PIN_COUNT=$(XMEGA_PIN_COUNT)

ifndef AVRDUDE_DEVICE_FUSES
  ifeq ($(XMEGA_SERIES), A)
    # Note: the JTAGEN bit in FUSE4 is not read correctly when changed until
    # after the device is reset. This means that avrdude will fail to verify
    # FUSE4 when writing, but it will still be written correctly. So we write
    # it last so even though it will fail to verify, it will be written still
    # be written corectly.
    AVRDUDE_DEVICE_FUSES=\
          -U fuse0:w:"0x$(FUSE0)":m \
          -U fuse1:w:"0x$(FUSE1)":m \
          -U fuse2:w:"0x$(FUSE2)":m \
          -U fuse5:w:"0x$(FUSE5)":m \
          -U fuse4:w:"0x$(FUSE4)":m
  else ifeq ($(XMEGA_SERIES), C)
  # No jtag fuse in C series (FUSE0)
    AVRDUDE_DEVICE_FUSES=\
          -U fuse1:w:"0x$(FUSE1)":m \
          -U fuse2:w:"0x$(FUSE2)":m \
          -U fuse5:w:"0x$(FUSE5)":m \
          -U fuse4:w:"0x$(FUSE4)":m
  else
    $(error "Unknown xmega series $(XMEGA_SERIES)")
  endif
endif

ifndef AVRDUDE_DEVICE_LOCK
AVRDUDE_DEVICE_LOCK=\
        -U lock:w:"0x$(LOCKBITS)":m
endif
