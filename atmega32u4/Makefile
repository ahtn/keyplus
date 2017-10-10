# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

# TODO: build system needs cleanup for building for different hardware

MCU = atmega32u4
ARCH = XMEGA
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

AVRDUDE_PART = 32u4
MCU_STRING = "ATmega32u4"
# LD_SCRIPT = avrxmega2.xn

ATMEL_VID=0x03EB
FLIP_USB_DFU_32u4=0x2FF

# see avr-gcc for information on avrxmega2, avrxmega4, etc
# NOTE: haven't tested on all these chips
ifeq ($(BOOTLOADER), atmel_dfu)
  BOOT_SECTION_START = 0x007800
  BOOTLOADER_SIZE = 0x0800
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
CFLAGS += -Wno-error=unused-but-set-variable

# workaround for bad code generation on avr-gcc on linux (as of version 6.2.0)
CFLAGS += -fno-jump-tables

# Place -D or -U options here for ASM sources
ADEFS  = -DF_CPU=$(F_CPU)
ADEFS += -DF_USB=$(F_USB)UL
ADEFS += -DBOARD=BOARD_$(BOARD)
ADEFS += $(USB_OPTS)

all: hex fuse lock

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
	avrdude-pdi -C ~/local/etc/avrdude-pdi.conf -c usbasp -p x32a4 -U flash:w:$<:i -E noreset

$(TARGET).fuse: $(TARGET).elf
	avr-objcopy -O $(FORMAT) -j .fuse --change-section-lma .fuse=$(FUSE_SECTION_START) $< $@

# fuse options, see fuses.c (fuses values generated in $(TARGET).fuse)

FUSE0 = CC # JTAG_UID
FUSE1 = 00 # Watchdog settings
# b6 = BOOTRST, b5 = TOSCSEL, b1:0 = BODPD
FUSE2 = BD
# b4 = RSTDISBL, b3:2 = STARTUPTIME, b1 = WDLOCK, b0 = JTAGEN
FUSE4 = FF
# b5:4 = BODACT, b3 = EESAVE, b2:0 = BODLEVEL
FUSE5 = D6

program-fuses:
	avrdude-pdi -c usbasp -p $(MCU_STRING) \
		-U fuse0:w:0x$(FUSE0):m \
		-U fuse1:w:0x$(FUSE1):m \
		-U fuse2:w:0x$(FUSE2):m \
		-U fuse4:w:0x$(FUSE4):m \
		-U fuse5:w:0x$(FUSE5):m

# lock options, see fuses.c (lock bit values generated in $(TARGET).lock)
LOCKBITS_DEBUG := BF # RW enabled for external programmer
LOCKBITS_RELEASE := BC # RW disabled for external programmer
LOCKBITS = $(LOCKBITS_RELEASE)
program-lock:
	avrdude-pdi -c usbasp -p $(MCU_STRING) -U lock:w:0x$(LOCKBITS):m

-include ../xmega/avr.mk

# Listing of phony targets.
.PHONY : all program bootload_only bootload program-fuses program-boot \
program-hard
