# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

TARGET_BASE_NAME = usb_keyboard

F_CPU            = 48000000

EFM8_PATH        = ./efm8
PROJECT_PATH     = ./src
KEYPLUS_PATH	 = ../src

VPATH += $(PROJECT_PATH)
VPATH += $(KEYPLUS_PATH)

# Provide install location of Simplicity Studio for CLI flashing tools
SIMPLICITY_STUDIO_PATH = $(HOME)/local/SimplicityStudio_v4

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

include $(EFM8_PATH)/boards.mk

# include $(KEYPLUS)

# include $(KEYPLUS_PATH)/core/core.mk
# include $(KEYPLUS_PATH)/usb/usb.mk
# include $(KEYPLUS_PATH)/key_handlers/key_handlers.mk


INC_PATHS += -I$(KEYPLUS_PATH)
INC_PATHS += -I$(EFM8_PATH)
INC_PATHS += -I$(PROJECT_PATH)

#######################################################################
#                            source files                             #
#######################################################################

include $(EFM8_PATH)/efm8.mk

# project source
C_SRC += \
	main.c \
	usb_test.c \
	usb_desc/device_descriptors.c \

# lib source
C_SRC += \
	$(EFM8_PATH)/efm8_util/delay.c \
	peripheral_driver/src/wdt_0.c \
	peripheral_driver/src/usb_0.c \

ASM_SRC = \


INC_PATHS += -I$(PROJECT_PATH)/src

INC_PATHS += -I$(EFM8_PATH)/lib
INC_PATHS += -I$(EFM8_PATH)/lib/efm8_assert/

#######################################################################
#                          compiler settings                          #
#######################################################################

# Using optimize for speed can result in a smaller binary in sdcc
OPTIMIZATION = --opt-code-size

# Compiler, assembler and preprocessor to use
AS = sdas8051
CC = sdcc
PP = sdcpp

# Memory model: small recommended by sdcc, only use larger if necessary
# Options: small, medium, large, huge
MEMORY_MODEL = small

# Extra compiler options
CFLAGS += -DNDEBUG
CFLAGS += $(CDEFS)

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
