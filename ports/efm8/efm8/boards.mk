# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

#######################################################################
#                        board config options                         #
#######################################################################

# Note: Specific board configs are stored in the `boards` directory.

ifndef BOARD_DIR
    BOARD_DIR = boards
endif

ifndef BOARD
    BOARD = default
endif

ifndef BUILD_DIR
    BUILD_DIR = build
endif

ifneq ("$(wildcard boards/$(BOARD)/config.mk)","")
    BOARD_MAKEFILE=$(BOARD_DIR)/$(BOARD)/config.mk
    INC_PATHS += -I$(BOARD_DIR)/$(BOARD)
    include $(BOARD_MAKEFILE)
    MAKEFILE_INC += $(BOARD_MAKEFILE)
    TARGET_TMP = $(TARGET_BASE_NAME)-$(BOARD)
else
    $(error "Unknown board $(BOARD)")
endif

#######################################################################
#                             binary dirs                             #
#######################################################################

# Object files directory
OBJ_DIR = $(BUILD_DIR)/$(BOARD)/obj

# Director were output files are placed
BUILD_TARGET_DIR = $(BUILD_DIR)/$(BOARD)

# Where dependency files are placed
DEP_DIR = $(OBJ_DIR)/.dep

#######################################################################
#                         Target output files                         #
#######################################################################

TARG_OBJ = $(BUILD_TARGET_DIR)/obj/$(TARGET_TMP)
TARGET = $(BUILD_TARGET_DIR)/$(TARGET_TMP)

TARGET_HEX = $(TARGET).hex
TARGET_ELF = $(TARGET).elf
