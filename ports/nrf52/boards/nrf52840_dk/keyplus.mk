# Copyright 2019 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

# SDK_ROOT := $(HOME)/local/nRF5_SDK_14.2.0_17b948a
SDK_ROOT := $(HOME)/local/nRF5_SDK_15.3.0_59ac345
PROJ_DIR := ../../..

# Include keyplus files
KEYPLUS_PATH := $(PROJ_DIR)/../src
include $(PROJ_DIR)/keyplus-common.mk


# ARM GCC paths
# GNU_INSTALL_ROOT := /usr/arm-none-eabi/bin/
GNU_INSTALL_ROOT := /usr/bin/
GNU_PREFIX := arm-none-eabi

# Keyplus source files
SRC_FILES += \
  $(PROJ_DIR)/main.c \
  $(C_SRC) \

# Keyplus include folders
INC_FOLDERS += \
  ../config \
  $(PROJ_DIR) \
  $(KEYPLUS_PATH) \


CFLAGS += $(CDEFS)
