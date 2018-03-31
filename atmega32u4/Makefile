# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

# TODO: build system needs cleanup for building for different hardware

MCU = atmega32u4
ARCH = AVR
BOOTLOADER = atmel_dfu
# BOOTLOADER = lufa_dfu

# Target file name (without extension).
TARGET = atmega32u4_keyboard

# Output format. (can be srec, ihex, binary)
FORMAT = ihex

# Object files directory
OBJ_DIR = obj

BASE_PATH=../src

VPATH += $(BASE_PATH)

INC_PATHS += \
	-I$(BASE_PATH)

VID = 6666
PID = 2222
F_CPU = 16000000

USE_USB := 0
USE_SCANNER := 1
USE_NRF24 := 0
USE_I2C := 1
USE_HARDWARE_SPECIFIC_SCAN := 1

include $(BASE_PATH)/core/core.mk
include $(BASE_PATH)/usb/usb.mk
include $(BASE_PATH)/key_handlers/key_handlers.mk

# List C source files here.
C_SRC += \
	example.c \
	usb_keyboard.c \
	fuses.c \
	timer.c \

# ifeq ($(USE_I2C), 1)
# 	C_SRC += wired.c
# endif

# # TODO: enable/disable nrf24 and i2c at run time using flash settings
# ifeq ($(USE_NRF24), 1)
# 	C_SRC += nrf24.c
# endif

# List Assembler source files here.
# NOTE: Use *.S for user written asm files. *.s is used for compiler generated
ASM_SRC =


# Optimization level, can be [0, 1, 2, 3, s].
OPT = s

# List any extra directories to look for include files here.
EXTRAINCDIRS = $(XMEGA_PATH)/

FUSE_SECTION_START=0x08F0020

# Compiler flag to set the C Standard level.
CSTANDARD = -std=gnu99

AVRDUDE_PART = m32u4
MCU_STRING = "ATmega32u4"
# LD_SCRIPT = avrxmega2.xn

ATMEL_VID=0x03EB
FLIP_USB_DFU_32u4=0x2FF

# see avr-gcc for information on avrxmega2, avrxmega4, etc
# NOTE: haven't tested on all these chips
ifeq ($(BOOTLOADER), atmel_dfu)
  BOOT_SECTION_START = 0x007000
  BOOTLOADER_SIZE = 0x1000
  C_SRC += atmel_dfu/atmel_bootloader.c
  CFLAGS += -DBOOTLOADER_VID=$(ATMEL_VID)
  CFLAGS += -DBOOTLOADER_PID=$(FLIP_USB_DFU_32u4)
else ifeq ($(BOOTLOADER), lufa_dfu)
  BOOT_SECTION_START = 0x007000
  BOOTLOADER_SIZE = 0x1000
  # lufa dfu uses the same VID/PID as the atmel version
  CFLAGS += -DBOOTLOADER_VID=$(ATMEL_VID)
  CFLAGS += -DBOOTLOADER_PID=$(FLIP_USB_DFU_32u4)
else
  $(error Unsupported bootloader BOOTLOADER='$(BOOTLOADER)')
endif


LD_SCRIPT_DIR = /usr/lib/ldscripts
# LD_SCRIPT_DIR = ./ld-scripts

# LDFLAGS += -T $(LD_SCRIPT_DIR)/$(LD_SCRIPT)
# LDFLAGS += -Wl,--section-start=.key_settings_block=$(SETTING_ADDR)
# LDFLAGS += -Wl,--section-start=.key_layout_block=$(LAYOUT_ADDR)

SETTING_ADDR := 0x5E00
LAYOUT_ADDR := 0x6000
LAYOUT_SIZE := 0x1000

CDEFS += -DSETTINGS_ADDR=$(SETTING_ADDR)
CDEFS += -DLAYOUT_ADDR=$(LAYOUT_ADDR)
CDEFS += -DLAYOUT_SIZE=$(LAYOUT_SIZE)

# Place -D or -U options here for C sources
CDEFS += -DCLOCK_SPEED_SLOW=$(CLOCK_SPEED_SLOW)UL
CDEFS += -DF_CPU=$(F_CPU)UL
CDEFS += -DF_USB=$(F_USB)UL
CDEFS += -DBOARD=BOARD_$(BOARD) -DARCH=ARCH_$(ARCH)
CDEFS += $(USB_OPTS)
CDEFS += -D'HW_VERSION=$(HW_VERSION)'
CDEFS += -D'FW_VERSION=$(FW_VERSION)'
CDEFS += -DUSB_PID=$(PID)
CDEFS += -DUSB_VID=$(VID)
CDEFS += $(INC_PATHS)

CFLAGS += -Wno-error=unused-variable
CFLAGS += -Wno-error=unused-function
CFLAGS += -Wno-error=unused-but-set-variable

# workaround for bad code generation on avr-gcc on linux (as of version 6.2.0)
CFLAGS += -fno-jump-tables

# Place -D or -U options here for ASM sources
ADEFS  = -DF_CPU=$(F_CPU)
ADEFS += -DF_USB=$(F_USB)UL
ADEFS += -DBOARD=BOARD_$(BOARD)
ADEFS += $(USB_OPTS)

AVRDUDE = avrdude
AVRDUDE_PROGRAMMER = usbasp
AVRDUDE_CMD = $(AVRDUDE) -c $(AVRDUDE_PROGRAMMER) -p $(AVRDUDE_PART)

all: hex lock fuse

# program the device using the bootloader

program: hex program-boot

# reset a board into bootloader via usb, then program it via the bootloader
program-boot: $(TARGET).hex
	./scripts/flash_hex.sh $<

# program a board that is already in in bootloader mode
program-boot-2: $(TARGET).hex
	./xusb-boot/scripts/flash.py -f $<


# program a board using an external programmer
program-hard: $(TARGET).hex
	$(AVRDUDE_CMD) -U flash:w:$<:i -E noreset

$(TARGET).fuse: $(TARGET).elf
	avr-objcopy -O $(FORMAT) -j .fuse --change-section-lma .fuse=$(FUSE_SECTION_START) $< $@

# fuse options, see fuses.c (fuses values generated in $(TARGET).fuse)

LFUSE = 0x5E
HFUSE = 0xD9
# EFUSE = 0xF3
EFUSE = 0xc3

program-fuses:
	$(AVRDUDE_CMD) \
		-U lfuse:w:$(LFUSE):m \
		-U hfuse:w:$(HFUSE):m \
		-U efuse:w:$(EFUSE):m \

ATMEL_DFU = atmel_dfu/ATMega32U4-usbdevice_dfu-1_0_0.hex
program-atmel-dfu:
	$(AVRDUDE_CMD) -U flash:w:$(ATMEL_DFU):i

program-dfu:
	dfu-programmer $(MCU) erase
	dfu-programmer $(MCU) flash $(TARGET).hex
	dfu-programmer $(MCU) start

# lock options, see fuses.c (lock bit values written to $(TARGET).lock)
#
# RW enabled for external programmer
# LOCKBITS_DEBUG := 0xEF
LOCKBITS_DEBUG := 0x2F
# RW disabled for external programmer
# LOCKBITS_RELEASE := 0xEC
LOCKBITS_RELEASE := 0x2C
NO_LOCK = 0xFF
# LOCKBITS = $(LOCKBITS_DEBUG)
LOCKBITS = NO_LOCK
program-lock:
	$(AVRDUDE_CMD) -U lock:w:$(LOCKBITS):m

-include ../xmega/avr.mk

# Listing of phony targets.
.PHONY : all program bootload_only bootload program-fuses program-boot \
program-hard
