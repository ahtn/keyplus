# Copyright 2019 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

TARGET := keyplusd

# Disable implicit rules
MAKEFLAGS += --no-builtin-rules

KEYPLUS_PATH      = ../../src

BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
BUILD_TARGET = $(BUILD_DIR)/$(TARGET)

MCU_STRING = VIRTUAL

CONFIG_FILE_PATH ?= /etc/keyplusd.conf
LOCKFILE_PATH ?= /tmp/keyplusd.lock

TEST_CONFIG_LAYOUT ?= ../../layouts/virtual.yaml
TEST_CONFIG_BIN ?= ./test_conf.bin

# SETTINGS_ADDR = 0
# LAYOUT_ADDR = 0
# LAYOUT_SIZE = 0

USE_HID = 1
USE_USB = 0
USE_MOUSE = 1
USE_SCANNER = 0
USE_MOUSE_GESTURE = 1

USE_VIRTUAL_MODE = 1

#######################################################################
#                           c source files                            #
#######################################################################

SRC_PATH = ./src

INC_PATHS += -I$(SRC_PATH)

C_SRC += \
	$(SRC_PATH)/keyplusd.c \
	$(SRC_PATH)/keyplus_mainloop.c \
	$(SRC_PATH)/cmdline.c \
	$(SRC_PATH)/udev_helpers.c \
	$(SRC_PATH)/virtual_input.c \
	$(SRC_PATH)/device_manager.c \
	$(SRC_PATH)/event_mapper.c \
	$(SRC_PATH)/hid_to_ev.c \
	$(SRC_PATH)/port_impl/hardware.c \
	$(SRC_PATH)/port_impl/timer.c \
	$(SRC_PATH)/port_impl/virtual_report.c \
	$(SRC_PATH)/port_impl/unused.c \

LDLIBS += -levdev -ludev
CFLAGS += -I/usr/include/libevdev-1.0/

include $(KEYPLUS_PATH)/core/core.mk
include $(KEYPLUS_PATH)/key_handlers/key_handlers.mk

#######################################################################
#                          c compiler flags                           #
#######################################################################

CC = gcc

# C std to use
CFLAGS += -std=gnu99

CFLAGS += $(CDEFS)

# Compiler flags to generate dependency files.
CFLAGS += -MMD -MP

# Turn on all warnings and treat them as errors
CFLAGS += -Wall
CFLAGS += -Werror
CFLAGS += -Wno-error=unused-variable

# turn on debugging
CFLAGS += -DDEBUG=1
# CFLAGS += -g3
CFLAGS += -ggdb3

CFLAGS += -DCONFIG_FILE_PATH="\"$(CONFIG_FILE_PATH)\""
CFLAGS += -DLOCKFILE_PATH="\"$(LOCKFILE_PATH)\""

#######################################################################
#                               recipes                               #
#######################################################################

all : $(BUILD_TARGET) $(TEST_CONFIG_BIN)

include $(KEYPLUS_PATH)/obj_file.mk

OBJ_FILES = $(call obj_file_list, $(C_SRC),o)
DEP_FILES = $(call obj_file_list, $(C_SRC),d)
INC_PATHS += $(addprefix -I,$(INC_FOLDERS))

define c_file_recipe
	@echo "compiling: $$<"
	@$(CC) $$(CFLAGS) $$(INC_PATHS) -o $$@ -c $$<
endef

# Create the recipes for the object files
$(call create_recipes, $(C_SRC),c_file_recipe,o)

# Include the dependency files
-include $(DEP_FILES)

# Link the target executable
$(BUILD_TARGET): $(OBJ_FILES)
	@echo
	@echo Linking target: $(BUILD_TARGET)
	@# Create a .in file that contains all the linker dependencies
	$(eval LD_INPUT := $(@:=.in))
	@echo $(OBJ_FILES) $(LIB_FILES) > $(LD_INPUT)
	@# link the executable
	$(CC) $(LDFLAGS) @$(LD_INPUT) $(LDLIBS) -Wl,-Map=$(@:=.map) -o $@
	@echo

#######################################################################
#                           utility recipes                           #
#######################################################################

run: $(BUILD_TARGET) $(TEST_CONFIG_BIN)
	./$(BUILD_TARGET) --as-user -c $(TEST_CONFIG_BIN)

run-daemon: $(BUILD_TARGET)
	sudo ./$(BUILD_TARGET)

# Delete all build files
clean:
	rm -r $(BUILD_DIR)

# Create the `keyplusd` user account for running the daemon
setup:
	./setup.sh

gdb: $(BUILD_TARGET)
	gdb --args $(BUILD_TARGET) --as-user -c $(TEST_CONFIG_BIN)

valgrind: $(BUILD_TARGET)
	@# NOTE: lax-ioctls is used to suppress false positives when accessing /dev/uinput
	valgrind --leak-check=full \
			 --show-leak-kinds=all \
			 --track-origins=yes \
			 --track-origins=yes \
			 --verbose \
			 --sim-hints=lax-ioctls \
			 ./$(BUILD_TARGET) -c $(TEST_CONFIG_BIN)

layout: $(TEST_CONFIG_BIN)

$(TEST_CONFIG_BIN): $(TEST_CONFIG_LAYOUT)
	../../host-software/keyplus-cli program \
		-M 0x0000 0x0200 0x1000 \
		-o "$@" -f bin \
		--new-id 0 \
		--layout "$<" \
		--rf ../../layouts/test_rf_config.yaml \
		-F chip_name=virtual \
		-F scan_method=virtual \
		-F max_rows=1

.PHONY: all run run-user clean setup gdb layout
