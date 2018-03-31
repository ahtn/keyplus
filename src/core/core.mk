# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

CORE_PATH = core
USB_REPORTS_PATH = usb_reports

#######################################################################
#                  firmware compile time information                  #
#######################################################################

PYTHON_CMD = /usr/bin/env python3

BUILD_TIME_STAMP := $(shell $(PYTHON_CMD) -c "import datetime;\
a = int(datetime.datetime.now().timestamp());\
res = ','.join(['0x{:x}'.format((a >> (i*8))&0xff) for i in range(8)]); \
print(res); \
")

GIT_HASH_FULL := $(shell git rev-parse HEAD)

GIT_HASH := $(shell $(PYTHON_CMD) -c "import datetime;\
hash = '$(GIT_HASH_FULL)'; \
b = ['0x'+hash[i*2:(i+1)*2] for i in range(8)]; \
b.reverse(); \
res = ','.join(b); \
print(res); \
")

CDEFS += -DBUILD_TIME_STAMP="$(BUILD_TIME_STAMP)"
CDEFS += -DGIT_HASH="$(GIT_HASH)"

CDEFS += -DMCU_CHIP_ID=CHIP_ID_$(MCU_STRING)

#######################################################################
#                            board config                             #
#######################################################################

ifndef ID
  ID = 0
endif

CDEFS += -DDEVICE_ID=$(ID)

# Note: Specific board configs are stored in the `boards` directory.

ifndef BOARD
  BOARD = keyplus_mini
endif

ifndef LAYOUT_FILE
  LAYOUT_FILE=../layouts/basic_split_test.yaml
endif

ifndef RF_FILE
  RF_FILE=../layouts/test_rf_config.yaml
endif

#######################################################################
#                            source files                             #
#######################################################################

C_SRC += \
	$(CORE_PATH)/crc.c \
	$(CORE_PATH)/error.c \
	$(CORE_PATH)/flash.c \
	$(CORE_PATH)/hardware.c \
	$(CORE_PATH)/layout.c \
	$(CORE_PATH)/packet.c \
	$(CORE_PATH)/ring_buf.c \
	$(CORE_PATH)/settings.c \
	$(CORE_PATH)/util.c \

# NRF24 module, defaults to 0
ifeq ($(USE_NRF24), 1)
    C_SRC += \
        $(CORE_PATH)/nrf24.c \
        $(CORE_PATH)/rf.c \
        $(CORE_PATH)/nonce.c
    CDEFS += -DUSE_NRF24=1

    ifeq ($(USE_UNIFYING), 0)
        CDEFS += -DUSE_UNIFYING=0
    else
        ifeq ($(USE_USB), 1)
            C_SRC += $(CORE_PATH)/unifying.c
            CDEFS += -DUSE_UNIFYING=1
        else
            $(error "Need USB for unifying support")
        endif
    endif
else
    CDEFS += -DUSE_NRF24=0
    CDEFS += -DUSE_UNIFYING=0
endif

# I2C module, defaults to 0
ifeq ($(USE_I2C), 1)
    CDEFS += -DUSE_I2C=1
else
    CDEFS += -DUSE_I2C=0
endif

# Scanner module, defaults to 1
ifeq ($(USE_SCANNER), 0)
    CDEFS += -DUSE_SCANNER=0
else
    C_SRC += \
        $(CORE_PATH)/io_map.c \
        $(CORE_PATH)/matrix_scanner.c
    CDEFS += -DUSE_SCANNER=1
endif

# Hardware specific scan, defaults to 0
ifeq ($(USE_HARDWARE_SPECIFIC_SCAN), 1)
    CDEFS += -DUSE_HARDWARE_SPECIFIC_SCAN=1
else
    CDEFS += -DUSE_HARDWARE_SPECIFIC_SCAN=0
endif

# USB Keyboard module, defaults to 1
ifeq ($(USE_USB), 0)
    CDEFS += -DUSE_USB=0
else
    C_SRC += \
        $(CORE_PATH)/matrix_interpret.c \
        $(CORE_PATH)/mods.c \
        $(CORE_PATH)/usb_commands.c \
        $(CORE_PATH)/macro.c \
        $(CORE_PATH)/keycode.c
    CDEFS += -DUSE_USB=1
endif

# Bluetooth module, defaults to 0
ifeq ($(USE_BLUETOOTH), 1)
    CDEFS += -DUSE_BLUETOOTH=1
else
    CDEFS += -DUSE_BLUETOOTH=0
endif

include $(KEYPLUS_PATH)/$(USB_REPORTS_PATH)/usb_reports.mk
