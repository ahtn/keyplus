# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

#######################################################################
#                        global build defines                         #
#######################################################################

TARGET_BASE_NAME = nrf52_keyplus
# ARCH             = XMEGA
F_CPU            = 64000000
# F_USB            = 48000000
# FORMAT           = ihex
# SHELL            = /bin/bash

KEYPLUS_PATH      = ../../src
PROJ_PATH         = .
PROJ_SRC_PATH     = ./src

VPATH += $(KEYPLUS_PATH)

# ARM GCC paths
GNU_INSTALL_ROOT ?= /usr/bin/
GNU_PREFIX ?= arm-none-eabi

SDK_ROOT ?= $(HOME)/local/nRF5_SDK_15.3.0_59ac345

#######################################################################
#                        board config options                         #
#######################################################################

USB_DESCRIPTOR_ARRANGEMENT = normal
SCAN_METHOD = fast_row_col

ifndef BOARD
	BOARD=nrf52840_dk
endif

include $(KEYPLUS_PATH)/boards.mk

#######################################################################
#                        common build settings                        #
#######################################################################

include $(KEYPLUS_PATH)/core/core.mk
# include $(KEYPLUS_PATH)/usb/usb.mk
# include $(KEYPLUS_PATH)/key_handlers/key_handlers.mk

#######################################################################
#                             c settings                              #
#######################################################################

CFLAGS += -Wno-error=unused-variable
CFLAGS += -Wno-error=unused-but-set-variable

# List C source files here.
#
# NOTE/TODO: Nordic armgcc Makefile doesn't support files with identical
# names in different folders
C_SRC += \
	$(PROJ_SRC_PATH)/main.c \
	$(PROJ_SRC_PATH)/port_impl/matrix_scanner.c \
	$(PROJ_SRC_PATH)/port_impl/io_map.c \
	$(PROJ_SRC_PATH)/port_impl/flash.c \
	$(PROJ_SRC_PATH)/port_impl/aes.c \
	$(PROJ_SRC_PATH)/port_impl/nonce.c \

ifeq ($(USE_USB), 1)
C_SRC += $(SRC_USB) \
	$(PROJ_SRC_PATH)/descriptors.c \
	$(PROJ_SRC_PATH)/usb_reports.c
endif

# List Assembler source files here.
# NOTE: Use *.S for user written asm files. *.s is used for compiler generated
# ASM_SRC =

# Optimization level, can be [0, 1, 2, 3, s].
# OPT = 2

# List any extra directories to look for include files here.
# EXTRAINCDIRS =

# Compiler flag to set the C Standard level.
# CSTANDARD = -std=gnu99

# Place -D or -U options here for C sources
CDEFS += -DCLOCK_SPEED_SLOW=$(CLOCK_SPEED_SLOW)UL
CDEFS += $(USB_OPTS)
CDEFS += -D'HW_VERSION=$(HW_VERSION)'
CDEFS += -D'FW_VERSION=$(FW_VERSION)'

CDEFS += -DF_CPU=$(F_CPU)UL

# Place -D or -U options here for ASM sources
ADEFS += $(USB_OPTS)
ADEFS += -D __$(DEVICE)__

#######################################################################
#                          optional imports                           #
#######################################################################

# Treat this makefile as a dependency to all object files
MAKEFILE_INC += Makefile

#######################################################################
#                      flash and memory settings                      #
#######################################################################


# LD_SCRIPT_DIR = /usr/lib/ldscripts
# LD_SCRIPT_DIR = ./ld-scripts

SETTINGS_SIZE = 0x200

ifeq ($(MCU), nrf52840)
  NONCE_ADDR := 0x40000 # need 2 pages for nonce (1 backup)
  SETTINGS_ADDR := 0x42000
  LAYOUT_ADDR := 0x43000
  LAYOUT_SIZE := 0x1000
else ifeq ($(MCU), nrf52832)
  $(message '$(MCU)' not implemented yet)
else
  $(message Error unsupported flash size='$(FLASH_SIZE)')
endif


# TODO: temp
CDEFS += -DNONCE_ADDR=$(NONCE_ADDR)
CDEFS += -DSETTINGS_ADDR=$(SETTINGS_ADDR)
CDEFS += -DLAYOUT_ADDR=$(LAYOUT_ADDR)
CDEFS += -DLAYOUT_SIZE=$(LAYOUT_SIZE)

# LDFLAGS += -T $(LD_SCRIPT_DIR)/$(LD_SCRIPT)
LDFLAGS += -Wl,--section-start=.key_settings_block=$(SETTINGS_ADDR)
LDFLAGS += -Wl,--section-start=.key_layout_block=$(LAYOUT_ADDR)

#######################################################################
#                              recipes                               #
#######################################################################

ALL_CFLAGS = $(CFLAGS)
include $(KEYPLUS_PATH)/keyplus.mk

ABSOLUTE_PATHS := 1

SRC_FILES += $(C_SRC)
CFLAGS += $(CDEFS)

INC_FOLDERS += $(KEYPLUS_PATH)
INC_FOLDERS += $(PROJ_SRC_PATH)
INC_FOLDERS += $(TARGET_BOARD_DIR)

include $(PROJ_PATH)/nrf52.mk

# $(TARGET_HEX): nrf52840_xxaa
# 	cp $(BUILD_TARGET_DIR)/nrf52840_xxaa.hex $@

.PHONY: program gdb log

# Flash the program
program: $(MERGED_HEX)
	@echo Flashing: $<
	nrfjprog -f nrf52 --program $< --sectorerase
	nrfjprog -f nrf52 --reset

log:
	picocom -b 115200 /dev/ttyACM0

gdb:
	arm-none-eabi-gdb -x .gdbinit

