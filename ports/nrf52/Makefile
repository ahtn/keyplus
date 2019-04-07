# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

#######################################################################
#                        global build defines                         #
#######################################################################

TARGET_BASE_NAME = nrf52_keyplus
# ARCH             = XMEGA
# F_CPU            = 32000000
# F_USB            = 48000000
# FORMAT           = ihex
# SHELL            = /bin/bash

EXTRA_TARGET      = nrf52840_xxaa

KEYPLUS_PATH      = ../../src
PROJ_PATH         = .
PROJ_SRC_PATH     = ./src/

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

include $(KEYPLUS_PATH)/boards.mk

#######################################################################
#                        common build settings                        #
#######################################################################

include $(KEYPLUS_PATH)/core/core.mk
include $(KEYPLUS_PATH)/usb/usb.mk
include $(KEYPLUS_PATH)/key_handlers/key_handlers.mk

#######################################################################
#                             c settings                              #
#######################################################################

CFLAGS += $(INC_PATHS)
CFLAGS += -Wno-error=unused-variable
CFLAGS += -Wno-error=unused-but-set-variable

# List C source files here.
C_SRC += \
	$(PROJ_SRC_PATH)/main.c \


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
LD_SCRIPT_DIR = ./ld-scripts

SETTINGS_SIZE = 0x200
ifeq ($(MCU_FLASH_SIZE), 32)
  SETTINGS_ADDR := 0x7A00
  LAYOUT_ADDR := 0x7C00
  LAYOUT_SIZE := 0x0400
else ifeq ($(MCU_FLASH_SIZE), 256)
  SETTINGS_ADDR := 0xC000
  LAYOUT_ADDR := 0xC200
  LAYOUT_SIZE := 0x33E00
else
  $(message Error unsupported flash size='$(FLASH_SIZE)')
endif

LDFLAGS += -T $(LD_SCRIPT_DIR)/$(LD_SCRIPT)
LDFLAGS += -Wl,--section-start=.key_settings_block=$(SETTINGS_ADDR)
LDFLAGS += -Wl,--section-start=.key_layout_block=$(LAYOUT_ADDR)

#######################################################################
#                              recipes                               #
#######################################################################

include $(KEYPLUS_PATH)/keyplus.mk

SRC_FILES += $(C_SRC)
CFLAGS += $(CDEFS)

INC_FOLDERS += $(KEYPLUS_PATH)
INC_FOLDERS += $(PROJ_SRC_PATH)
# INC_FOLDERS += $(INC_PATHS)

include $(PROJ_PATH)/nrf52.mk
