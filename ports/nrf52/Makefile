# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

#######################################################################
#                        global build defines                         #
#######################################################################

TARGET_BASE_NAME = nrf52_keyplus
F_CPU            = 64000000
CLOCK_SPEED_SLOW = 64000000

KEYPLUS_PATH      = ../../src
PROJ_PATH         = .
PROJ_SRC_PATH     = ./src

VPATH += $(KEYPLUS_PATH)

# ARM GCC paths
GNU_INSTALL_ROOT ?= /usr/bin/
GNU_PREFIX ?= arm-none-eabi

# GDB cmd file for debugging

GDB_CMD_FILE ?= gdb_cmds

# NOTE: if you have the SDK installed somewhere else, you can set this
# in your ~/.profile file with `export NRF52_SDK_ROOT=/path/to/sdk` and the
# makefile will use that version. Changes to ~/.profile may require a restart
# to take effect.
NRF52_SDK_ROOT ?= $(HOME)/local/nRF5_SDK_15.3.0_59ac345

LOG_TTY ?= /dev/ttyACM0

# Disable implicit rules
MAKEFLAGS += --no-builtin-rules

#######################################################################
#                        board config options                         #
#######################################################################

USB_DESCRIPTOR_ARRANGEMENT = normal
SCAN_METHOD = fast_row_col

BOARD_DIR := boards

ifndef BOARD
  $(info Error: BOARD variable not set, use one of:)
  $(info $(shell ls $(BOARD_DIR)))
  $(error BOARD not set)
endif

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

CFLAGS += -Wno-error=unused-variable
CFLAGS += -Wno-error=unused-but-set-variable
CFLAGS += -Wno-error=unused-function

# CDEFS += -DDEBUG
# OPT ?= -Og -g3

CDEFS += -DDEBUG
OPT ?= -O3

# List C source files here.
#
# NOTE/TODO: Nordic armgcc Makefile doesn't support files with identical
# names in different folders
C_SRC += \
	$(PROJ_SRC_PATH)/main.c \
	$(PROJ_SRC_PATH)/nrf52_usb.c \
	$(PROJ_SRC_PATH)/serial_num.c \
	$(PROJ_SRC_PATH)/nrf52_esb.c \
	$(PROJ_SRC_PATH)/port_impl/aes.c \
	$(PROJ_SRC_PATH)/port_impl/flash.c \
	$(PROJ_SRC_PATH)/port_impl/hardware.c \
	$(PROJ_SRC_PATH)/port_impl/io_map.c \
	$(PROJ_SRC_PATH)/port_impl/led.c \
	$(PROJ_SRC_PATH)/port_impl/matrix_scanner.c \
	$(PROJ_SRC_PATH)/port_impl/nonce.c \
	$(PROJ_SRC_PATH)/port_impl/nrf24.c \
	$(PROJ_SRC_PATH)/port_impl/timer.c \
	$(PROJ_SRC_PATH)/port_impl/usb_reports.c \

ifeq ($(USE_BLUETOOTH), 1)
  C_SRC += \
	$(PROJ_SRC_PATH)/kp_ble/hid.c \
    $(PROJ_SRC_PATH)/ble_test.c \
    $(PROJ_SRC_PATH)/esb_timeslot.c \

  USE_SOFTDEVICE := 1
endif

# Place -D or -U options here for C sources
CDEFS += -DCLOCK_SPEED_SLOW=$(CLOCK_SPEED_SLOW)UL
CDEFS += $(USB_OPTS)
CDEFS += -D'HW_VERSION=$(HW_VERSION)'
CDEFS += -D'FW_VERSION=$(FW_VERSION)'

CDEFS += -DF_CPU=$(F_CPU)UL
CDEFS += -DUSE_SOFTDEVICE=$(USE_SOFTDEVICE)

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
  SETTINGS_ADDR := 0x0C0000
  LAYOUT_ADDR := 0x0C1000
  LAYOUT_SIZE := 0x2000
  NONCE_ADDR := 0x0C3000 # need 2 pages for nonce (1 backup)
else ifeq ($(MCU), nrf52832)
  $(info '$(MCU)' not implemented yet)
else
  $(error Error unsupported flash size='$(FLASH_SIZE)')
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

SRC_FILES += $(C_SRC)
CFLAGS += $(CDEFS)

INC_FOLDERS += $(KEYPLUS_PATH)
INC_FOLDERS += $(PROJ_SRC_PATH)
INC_FOLDERS += $(TARGET_BOARD_DIR)

# nrf52.mk uses SDK_ROOT for this value
SDK_ROOT=$(NRF52_SDK_ROOT)

include $(PROJ_PATH)/nrf52.mk

# $(TARGET_HEX): nrf52840_xxaa
# 	cp $(BUILD_TARGET_DIR)/nrf52840_xxaa.hex $@

.PHONY: program program_hex gdb log

# Flash the program
program: $(MERGED_HEX)
	@echo Flashing: $<
	nrfjprog -f nrf52 --program $< --sectorerase
	nrfjprog -f nrf52 --reset

# Flash the hex without settings section
program_hex: $(TARGET_HEX)
	@echo Flashing: $<
	nrfjprog -f nrf52 --program $< --sectorerase
	nrfjprog -f nrf52 --reset

# Repeatedly try to connect to the logging device
#
# Exit picocom by pressing: <c-A> <c-X>
log:
	@while true; do \
		echo "Starting picocom:"; \
		picocom -q -b 115200 $(LOG_TTY); \
		clear -sx; \
		echo "Attempting to reconnect..."; \
		echo ""; \
		sleep 1; \
	done

gdb:
	arm-none-eabi-gdb -x $(GDB_CMD_FILE)

