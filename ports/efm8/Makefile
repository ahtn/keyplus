# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

TARGET_BASE_NAME   = usb_keyboard

F_CPU              = 48000000

EFM8_PATH          = ./efm8
PROJECT_PATH       = ./src
KEYPLUS_PATH       = ../../src

VPATH += $(PROJECT_PATH)
VPATH += $(KEYPLUS_PATH)

# Provide install location of Simplicity Studio for CLI flashing tools
SIMPLICITY_STUDIO_PATH = $(HOME)/local/SimplicityStudio_v4

USE_USB := 1
USE_SCANNER := 1
USE_NRF24 := 0
USE_CHECK_PIN := 0
USE_I2C := 0
USE_HARDWARE_SPECIFIC_SCAN := 0

USB_DESCRIPTOR_ARRANGEMENT = compact

#######################################################################
#                             programing                              #
#######################################################################

ifndef SERIAL_NUM
  # The serial number of the device to program
  # Can also be passed on the command line
  SERIAL_NUM = EC3005481E8
endif

#######################################################################
#                               boards                                #
#######################################################################

# Load board information
include $(EFM8_PATH)/boards.mk

MCU_STRING = $(MCU_SPECIFIC)

# Include keyplus common makefiles
include $(KEYPLUS_PATH)/core/core.mk
include $(KEYPLUS_PATH)/usb/usb.mk
include $(KEYPLUS_PATH)/key_handlers/key_handlers.mk

INC_PATHS += -I$(KEYPLUS_PATH)
INC_PATHS += -I$(EFM8_PATH)
INC_PATHS += -I$(PROJECT_PATH)
INC_PATHS += -I$(PROJECT_PORT_PATH)

include $(EFM8_PATH)/efm8.mk

#######################################################################
#                            source files                             #
#######################################################################

# project source
C_SRC += \
	main.c \
	usb_test.c \
	$(EFM8_PATH)/lib/efm8_assert/assert.c \
	matrix_scanner.c \
	efm8_port_util.c \
	port_impl/flash.c \
	port_impl/hardware.c \
	port_impl/led.c \
	port_impl/timer.c \
	port_impl/usb_reports.c \

# lib source
C_SRC += \
	$(EFM8_PATH)/efm8_util/delay.c \
	peripheral_driver/src/wdt_0.c \
	peripheral_driver/src/usb_0.c \

ASM_SRC = \


INC_PATHS += -I$(PROJECT_PATH)/src
INC_PATHS += -I$(EFM8_PATH)/lib
INC_PATHS += -I$(EFM8_PATH)/lib/efm8_assert

#######################################################################
#                          compiler settings                          #
#######################################################################

# Using optimize for speed can result in a smaller binary in sdcc
OPTIMIZATION = --opt-code-size

# Compiler, assembler and preprocessor to use
ifdef SDCC_PATH
  # when this variable is set, we use a custom path to the SDCC
  # internal libraries/header files.
  # NOTE: We add this values to the start of INC_PATHS, because values
  # near the end seem to take precedence in SDCC.
  INC_PATHS += \
	-I"$(SDCC_PATH)/share/sdcc/include" \
	-I"$(SDCC_PATH)/share/sdcc/include/mcs51"

  LIB_PATHS += \
	-L"$(SDCC_PATH)/share/sdcc/lib/small"

  CFLAGS += --nostdlib
  CFLAGS += --nostdinc
  CFLAGS += -llibsdcc -lmcs51 -llibint

  AS = $(SDCC_PATH)/bin/sdas8051
  CC = $(SDCC_PATH)/bin/sdcc
  PP = $(SDCC_PATH)/bin/sdcpp
else
  AS = sdas8051
  CC = sdcc
  PP = sdcpp
endif

# Memory model: small recommended by sdcc, only use larger if necessary
# Options: small, medium, large, huge
MEMORY_MODEL = small

# Extra compiler options
# CDEFS += -DNDEBUG

# Extra linking options
LFLAGS +=

# Assembler options
ASFLAGS  = -xglospff

#######################################################################
#                              recipes                               #
#######################################################################

include $(EFM8_PATH)/sdcc.mk
include $(EFM8_PATH)/efm8_program.mk

-include $(DEP_FILES)

.PHONY: clean flash program all size
