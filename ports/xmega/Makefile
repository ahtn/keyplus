# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

#######################################################################
#                        global build defines                         #
#######################################################################

TARGET_BASE_NAME = xmega_keyplus
ARCH             = XMEGA
F_CPU            = 32000000
F_USB            = 48000000
FORMAT           = ihex
SHELL            = /bin/bash

# USB IDs
USB_DESCRIPTOR_ARRANGEMENT = normal

# The clock speed to use when we are running on battery power (12MHz).
# We use 12MHz for battery mode because speeds >12MHz require voltage >1.8V
CLOCK_SPEED_SLOW = 12000000

KEYPLUS_PATH      = ../../src
AVR_MKFILE_PATH   = $(KEYPLUS_PATH)/arch/avr/avr-makefile
XMEGA_PATH        = ./src

VPATH += $(KEYPLUS_PATH)
VPATH += $(XMEGA_PATH)

BOOTLOADER_PATH := ./xusb-boot/
BOOTLOADER_HEX := $(BOOTLOADER_PATH)/build/$(BOARD)-$(MCU)/xusb-boot-$(BOARD)-$(MCU).hex
MERGED_HEX_WITH_BOOT := $(basename $(MERGED_HEX))_with_bootloader.hex

#######################################################################
#                        board config options                         #
#######################################################################

include $(AVR_MKFILE_PATH)/boards.mk

SCAN_METHOD=fast_row_col

#######################################################################
#                        common build settings                        #
#######################################################################

include $(AVR_MKFILE_PATH)/avr-xmega.mk

include $(KEYPLUS_PATH)/core/core.mk
include $(KEYPLUS_PATH)/usb/usb.mk
include $(KEYPLUS_PATH)/key_handlers/key_handlers.mk

include $(XMEGA_PATH)/xusb/makefile
include $(XMEGA_PATH)/xusb/xmega/makefile
include $(XMEGA_PATH)/xmega_hardware/xmega_hardware.mk

include $(KEYPLUS_PATH)/arch/avr/avr.mk

#######################################################################
#                         programmer options                          #
#######################################################################

# AVRDUDE_CMD=avrdude-pdi -C ~/local/etc/avrdude-pdi.conf -c usbasp -p $(AVRDUDE_PART)
AVRDUDE_CMD=avrdude -p $(AVRDUDE_PART) -c avrispmkII

XUSBBOOT_CLI = python3 ./xusb-boot/scripts/bin/xusbboot-cli

#######################################################################
#                             c settings                              #
#######################################################################

CFLAGS += $(INC_PATHS)
CFLAGS += -Wno-error=unused-variable
CFLAGS += -Wno-error=unused-but-set-variable

# workaround for bad code generation on avr-gcc on linux (as of version 6.2.0)
CFLAGS += -fno-jump-tables

# List C source files here.
C_SRC += \
	debug.c \
	fuses.c \
	hardware.c \
	main.c \
	matrix_scanner.c \
	power.c \
	port_impl/io_map.c \
	port_impl/led.c \
	port_impl/timer.c \
	port_impl/flash.c \
	# led_vm.c \
	# ws2812.c \


ifeq ($(USE_USB), 1)
C_SRC += $(SRC_USB) \
	descriptors.c \
	usb_reports.c
endif

# List Assembler source files here.
# NOTE: Use *.S for user written asm files. *.s is used for compiler generated
ASM_SRC =

# Optimization level, can be [0, 1, 2, 3, s].
OPT = 2

# List any extra directories to look for include files here.
EXTRAINCDIRS = $(XMEGA_PATH)/

# Compiler flag to set the C Standard level.
CSTANDARD = -std=gnu99

# Place -D or -U options here for C sources
CDEFS += -DCLOCK_SPEED_SLOW=$(CLOCK_SPEED_SLOW)UL
CDEFS += $(USB_OPTS)
CDEFS += -D'HW_VERSION=$(HW_VERSION)'
CDEFS += -D'FW_VERSION=$(FW_VERSION)'

# Place -D or -U options here for ASM sources
ADEFS += $(USB_OPTS)
ADEFS += -D __$(DEVICE)__

#######################################################################
#                          optional imports                           #
#######################################################################

ifeq ($(USE_I2C), 1)
  C_SRC += wired.c
endif

# TODO: enable/disable nrf24 and i2c at run time using flash settings
ifeq ($(USE_NRF24), 1)
  C_SRC += \
	aes.c \
	nrf24.c
endif

CDEFS += -DUSE_CHECK_PIN=$(USE_CHECK_PIN)

# TODO:
CDEFS += -DUSB_BUFFERED=1

ifdef DUAL_USB
  CDEFS += -DDUAL_USB=1
  C_SRC += dual_usb.c
endif

ifdef DEBUG_LEVEL
  CDEFS += -DDEBUG_LEVEL=$(DEBUG_LEVEL)
else
  CDEFS += -DDEBUG_LEVEL=0
endif

# Treat this makefile as a dependency to all object files
MAKEFILE_INC += Makefile

#######################################################################
#                   xmega flash and memory settings                   #
#######################################################################

# LD_SCRIPT_DIR = /usr/lib/ldscripts
LD_SCRIPT_DIR = ./ld-scripts

SETTINGS_SIZE = 0x200
ifeq ($(MCU_FLASH_SIZE), 32)
  SETTINGS_ADDR := 0x7A00
  LAYOUT_ADDR := 0x7C00
  LAYOUT_SIZE := 0x0400
else ifeq ($(MCU_FLASH_SIZE), 64)
  SETTINGS_ADDR := 0xC000
  LAYOUT_ADDR := 0xC200
  LAYOUT_SIZE := 0x3E00
else ifeq ($(MCU_FLASH_SIZE), 128)
  SETTINGS_ADDR := 0x18000
  LAYOUT_ADDR := 0x18200
  LAYOUT_SIZE := 0x07E00
else ifeq ($(MCU_FLASH_SIZE), 192)
  SETTINGS_ADDR := 0xC000
  LAYOUT_ADDR := 0xC200
  LAYOUT_SIZE := 0x23E00
else ifeq ($(MCU_FLASH_SIZE), 256)
  SETTINGS_ADDR := 0xC000
  LAYOUT_ADDR := 0xC200
  LAYOUT_SIZE := 0x33E00
else
  $(error Error unsupported flash size='$(FLASH_SIZE)')
endif

# The amount  of space left for program code
MAX_FLASH_SIZE = $(shell echo "$$(( $(MCU_FLASH_SIZE)*2**10 - $(LAYOUT_SIZE) - $(SETTINGS_SIZE) ))")

LDFLAGS += -T $(LD_SCRIPT_DIR)/$(LD_SCRIPT)
LDFLAGS += -Wl,--section-start=.key_settings_block=$(SETTINGS_ADDR)
LDFLAGS += -Wl,--section-start=.key_layout_block=$(LAYOUT_ADDR)

#######################################################################
#                              recipes                               #
#######################################################################

include $(KEYPLUS_PATH)/keyplus.mk

.PHONY:
program: program-boot

$(MERGED_HEX): pretty_size

# reset a board into bootloader via usb, then program it via the bootloader
program-boot: $(MERGED_HEX)
	# ./scripts/flash_hex.sh $< $(MCU)
	$(KEYPLUS_CLI) bootloader -p $(MCU_STRING) | sleep 1.5
	$(XUSBBOOT_CLI) -f $< -mcu $(MCU)

# program a board that is already in in bootloader mode
program-boot-2: $(MERGED_HEX)
	$(XUSBBOOT_CLI) -f $< -mcu $(MCU)

program-hard-with-boot: $(MERGED_HEX_WITH_BOOT)
	$(AVRDUDE_CMD) $(AVRDUDE_EXTRA) -U flash:w:$<:i

merge-bootloader: $(MERGED_HEX_WITH_BOOT)

# Make the bootloader
$(BOOTLOADER_HEX):
	cd $(BOOTLOADER_PATH)
	make BOARD=$(BOARD) MCU=$(MCU)

# Merge the bootloader with the program hex file
$(MERGED_HEX_WITH_BOOT): $(MERGED_HEX) $(BOOTLOADER_HEX)
	head -n -1 "$(MERGED_HEX)" > "$(MERGED_HEX_WITH_BOOT)"
	cat "$(BOOTLOADER_HEX)" >> "$(MERGED_HEX_WITH_BOOT)"


.PHONY: check_sizes
check_sizes:
	$(AVR_MKFILE_PATH)/check_elf_sizes.sh $(TARGET_ELF) $(SECTION)

#######################################################################
#                     fuse and lock bit settings                      #
#######################################################################

# fuse options, see fuses.c (fuses values generated in $(TARGET).fuse)

FUSE0 = CC # JTAG_UID
FUSE1 = 00 # Watchdog settings
# b6 = BOOTRST, b5 = TOSCSEL, b1:0 = BODPD
FUSE2 = BD
# b4 = RSTDISBL, b3:2 = STARTUPTIME, b1 = WDLOCK, b0 = JTAGEN
FUSE4 = FF
# b5:4 = BODACT, b3 = EESAVE, b2:0 = BODLEVEL
FUSE5 = D6

# lock options, see fuses.c (lock bit values generated in $(TARGET).lock)
LOCKBITS_DEBUG := BF # RW enabled for external programmer
LOCKBITS_RELEASE := BC # RW disabled for external programmer
LOCKBITS = $(LOCKBITS_RELEASE)

include $(AVR_MKFILE_PATH)/avr.mk
include $(AVR_MKFILE_PATH)/avr-program.mk


# Listing of phony targets.
.PHONY : all program bootload_only bootload program-fuses program-boot \
program-hard
