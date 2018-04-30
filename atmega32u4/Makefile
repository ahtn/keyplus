# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

#######################################################################
#                        global build options                         #
#######################################################################

TARGET_BASE_NAME = keyplus_32u4
ARCH             = AVR
MCU              = atmega32u4
F_CPU            = 16000000
FORMAT           = ihex
SHELL            = /bin/bash

# USB IDs
USB_VID = 6666
USB_PID = 2222

KEYPLUS_PATH      = ../src
AVR_MKFILE_PATH   = avr-makefile

VPATH += $(KEYPLUS_PATH)

#######################################################################
#                        board config options                         #
#######################################################################

include $(AVR_MKFILE_PATH)/boards.mk

ifndef LAYOUT_FILE
  LAYOUT_FILE = ../layouts/1key.yaml
endif

ifndef BOOTLOADER
	BOOTLOADER = kp_boot_32u4
# BOOTLOADER = atmel_dfu
# BOOTLOADER = lufa_dfu
endif

ifndef SCANNER_MAX_ROWS
   SCANNER_MAX_ROWS=18
endif

SCAN_METHOD=basic_scan

#######################################################################
#                        common build settings                        #
#######################################################################

include $(KEYPLUS_PATH)/core/core.mk
include $(KEYPLUS_PATH)/usb/usb.mk
include $(KEYPLUS_PATH)/key_handlers/key_handlers.mk

#######################################################################
#                         programming options                         #
#######################################################################

# AVRDUDE_PROGRAMMER = avrispmkII
AVRDUDE_PROGRAMMER = usbasp

AVRDUDE_CMD=avrdude -p $(AVRDUDE_PART) -c $(AVRDUDE_PROGRAMMER)

KEYPLUS_CLI = python3 ../host-software/keyplus-cli

#######################################################################
#                          compiler settings                          #
#######################################################################

CFLAGS += $(INC_PATHS)

# List C source files here.
C_SRC += \
	main.c \
	usb_keyboard.c \
	matrix_scanner.c \
	hardware.c \
	usb_reports.c \
	io_map.c \
	fuses.c \
	timer.c \
	flash.c \

# List Assembler source files here.
# NOTE: Use *.S for user written asm files. *.s is used for compiler generated
ASM_SRC =


# Optimization level, can be [0, 1, 2, 3, s].
OPT = s

# List any extra directories to look for include files here.
# EXTRAINCDIRS = $(XMEGA_PATH)/

FUSE_SECTION_START=0x08F0020

# Compiler flag to set the C Standard level.
CSTANDARD = -std=gnu99

CFLAGS += -Wno-error=unused-variable
CFLAGS += -Wno-error=unused-function
CFLAGS += -Wno-error=unused-but-set-variable

AVRDUDE_PART = m32u4
MCU_STRING = "ATmega32U4"
# LD_SCRIPT = avrxmega2.xn

#######################################################################
#                         bootloader options                          #
#######################################################################

ATMEL_VID=0x03EB
FLIP_USB_DFU_32u4=0x02FF

BOOTLOADER_PATH = bootloaders
CFLAGS += -I$(BOOTLOADER_PATH)

# see avr-gcc for information on avrxmega2, avrxmega4, etc
# NOTE: haven't tested on all these chips
ifeq ($(BOOTLOADER), atmel_dfu)
  BOOT_SECTION_START = 0x007000
  BOOT_SIZE = 4096
  C_SRC += $(BOOTLOADER_PATH)/atmel_dfu/atmel_bootloader.c
  CFLAGS += -DBOOTLOADER_VID=$(ATMEL_VID)
  CFLAGS += -DBOOTLOADER_PID=$(FLIP_USB_DFU_32u4)
  CFLAGS += -DBOOTLOADER_ATMEL_DFU
else ifeq ($(BOOTLOADER), lufa_dfu)
  BOOT_SECTION_START = 0x007000
  BOOT_SIZE = 4096
  # lufa dfu uses the same VID/PID as the atmel version
  CFLAGS += -DBOOTLOADER_VID=$(ATMEL_VID)
  CFLAGS += -DBOOTLOADER_PID=$(FLIP_USB_DFU_32u4)
  $(error Bootloader lufa_dfu not supported yet.)
else ifeq ($(BOOTLOADER), kp_boot_32u4)
  BOOT_SECTION_START = 0x007C00
  BOOT_SIZE = 1024
  CFLAGS += -DBOOTLOADER_VID=0x1209
  CFLAGS += -DBOOTLOADER_PID=0xBB05
  CFLAGS += -DBOOTLOADER_KP_BOOT_32U4
  C_SRC += $(BOOTLOADER_PATH)/kp_boot_32u4/interface/kp_boot_32u4.c
else
  $(error Unsupported bootloader BOOTLOADER='$(BOOTLOADER)')
endif

CFLAGS += -DBOOT_SECTION_START=$(BOOT_SECTION_START)

#######################################################################
#                           linking options                           #
#######################################################################

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

# workaround for bad code generation on avr-gcc on linux (as of version 6.2.0)
CFLAGS += -fno-jump-tables

# Place -D or -U options here for ASM sources
ADEFS += $(USB_OPTS)

#######################################################################
#                              recepies                               #
#######################################################################

# program the device using the bootloader

include $(KEYPLUS_PATH)/keyplus.mk

program: hex program-boot

# reset a board into bootloader via usb, then program it via the bootloader
program-boot: $(TARGET).hex
	./scripts/flash_hex.sh $<

# program a board that is already in in bootloader mode
program-boot-2: $(TARGET).hex
	./xusb-boot/scripts/flash.py -f $<


# program a board using an external programmer
program-hard: $(MERGED_HEX)
	$(AVRDUDE_CMD) -U flash:w:$<:i -E noreset

$(TARGET).fuse: $(TARGET).elf
	avr-objcopy -O $(FORMAT) -j .fuse --change-section-lma .fuse=$(FUSE_SECTION_START) $< $@

# fuse options, see fuses.c (fuses values generated in $(TARGET).fuse)

LFUSE = 5E
HFUSE = D9
EFUSE = C3 # --> EFUSE = F3

ATMEL_DFU = bootloaders/atmel_dfu/ATMega32U4-usbdevice_dfu-1_0_0.hex

program-atmel-dfu-bootloader:
	$(AVRDUDE_CMD) -U flash:w:$(ATMEL_DFU):i

program-kp-boot-32u4:
	$(AVRDUDE_CMD) -U flash:w:$(ATMEL_DFU):i

program-dfu: $(MERGED_HEX)
	dfu-programmer $(MCU) erase --force
	dfu-programmer $(MCU) flash $(MERGED_HEX)
	dfu-programmer $(MCU) start

program-kp-boot: $(MERGED_HEX)
	$(BOOTLOADER_PATH)/kp_boot_32u4/kp_boot_32u4_cli.py -f $(MERGED_HEX)

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

include $(AVR_MKFILE_PATH)/avr-mega.mk
include $(AVR_MKFILE_PATH)/avr.mk
include $(AVR_MKFILE_PATH)/avr-program.mk

# Listing of phony targets.
.PHONY : all program bootload_only bootload program-fuses program-boot \
program-hard
