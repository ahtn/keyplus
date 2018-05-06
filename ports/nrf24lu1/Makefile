# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

#######################################################################
#                        global build defines                         #
#######################################################################

TARGET_BASE_NAME = keyplus_nrf24lu1
ARCH			 = 8051
OBJ_DIR          = obj
MCU              = NRF24LU1
F_CPU            = 16000000
MCU_STRING       = nRF24LU1P_F32
SHELL            = /bin/bash

# USB settings
USB_DESCRIPTOR_ARRANGEMENT = normal

# valid 16 or 32
FLASH_SIZE  = 32
USE_USB     = 1
USE_NRF24   = 1
USE_I2C     = 0
USE_SCANNER = 0

KEYPLUS_PATH  = ../../src
NRF24LU1_PATH = ./src

VPATH += $(KEYPLUS_PATH)
VPATH += $(NRF24LU1_PATH)

INC_PATHS += -I$(NRF24LU1_PATH)

#######################################################################
#                               config                                #
#######################################################################

include scripts/boards.mk

CHIP_NAME=nRF24LU1P-F32
SCAN_METHOD=none
SCANNER_MAX_ROWS=0

#######################################################################
#                            source files                             #
#######################################################################

C_SRC += \
	aes.c \
	flash.c \
	hardware.c \
	led.c \
	main.c \
	nonce.c \
	nrf24.c \
	timer.c \
	usb.c \
	usb_reports.c \
	descriptors.c \


ASM_SRC = \
	crtxinit.S \


include $(KEYPLUS_PATH)/core/core.mk
include $(KEYPLUS_PATH)/usb/usb.mk
include $(KEYPLUS_PATH)/key_handlers/key_handlers.mk

#######################################################################
#                              c defines                              #
#######################################################################

INC_PATHS += \
	-I. \
	-I$(KEYPLUS_PATH) \

CDEFS += \
	-D$(MCU) \
	-DINTEL_8052 \
	-DNO_RF_TRANSMIT \
	-DF_CPU=$(F_CPU)UL \

CDEFS += -DUSB_BUFFERED=0

ifdef DEBUG_LEVEL
	CDEFS += -DDEBUG_LEVEL=$(DEBUG_LEVEL)
endif

#######################################################################
#                     flash and storage settings                      #
#######################################################################

CDEFS += -DFLASH_$(FLASH_SIZE)

#######################################################################
#                     linker and compiler options                     #
#######################################################################

# Using optimize for speed can result in a smaller binary in sdcc
OPTIMIZATION = --opt-code-speed
# OPTIMIZATION = --opt-code-size

# Version of sdcc used:
# /usr/local/bin/sdcc --version
# SDCC : mcs51/z80/z180/r2k/r3ka/gbz80/tlcs90/ds390/pic16/pic14/TININative/ds400/hc08/s08/stm8 3.6.8 #9948 (Linux)

# SDCC_PATH = /usr/local
ifdef SDCC_PATH
  # when this variable is set, we use a custom path to the SDCC
  # internal libraries/header files.
  CFLAGS += \
	-I"$(SDCC_PATH)/share/sdcc/include" \
	-I"$(SDCC_PATH)/share/sdcc/include/mcs51" \
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

CFLAGS += \
	$(CDEFS) \
	$(INC_PATHS) \
	$(OPTIMIZATION) \
	--fomit-frame-pointer \
	--model-small \
	--std-sdcc99 \
	# --stack-auto \
	# --Werror \
	# --model-small \
	# --code-movx \
	# --disable-warning 85 \
	# --model-large \
	#

LFLAGS   = \
	--code-loc 0x0000 \
	--code-size $(CODE_SIZE) \
	--xram-loc 0x8000 \
	--xram-size 0x800 \
	--iram-size 0x100 \
	--stack-loc 0x080 \
	--stack-size 0x080 \
	# --parms-in-bank1

ASFLAGS  = -xglospff

#######################################################################
#                               recipes                               #
#######################################################################

C_REL_FILES = $(patsubst %.c, $(OBJ_DIR)/%.rel, $(C_SRC))
ASM_REL_FILES = $(patsubst %.S, $(OBJ_DIR)/%.rel, $(ASM_SRC))
DEP_FILES = $(patsubst %.c, $(OBJ_DIR)/%.dep, $(C_SRC))
REL_FILES = $(C_REL_FILES) $(ASM_REL_FILES)


LAYOUT_NAME=$(basename $(notdir $(LAYOUT_FILE)))
MERGED_HEX="$(BUILD_TARGET_DIR)/$(basename $(TARGET))-$(LAYOUT_NAME).hex"

all: $(TARGET_HEX) $(MERGED_HEX) size

$(MERGED_HEX): $(TARGET_HEX) $(BOOTLOADER)
	@echo "=== appending bootloader ==="
	sed '/^:00000001FF/d' $(TARGET_HEX) > $(TARGET_HEX)_with_bootloader.hex
	cat $(BOOTLOADER) >> $(TARGET_HEX)_with_bootloader.hex
	echo ':00000001FF' >> $(TARGET_HEX)_with_bootloader.hex
# sort the hex for easier inspection
	@echo "=== merging layout settings files ==="
	$(KEYPLUS_CLI) program \
		$(KEYPLUS_CLI_LAYOUT_FLAGS) \
		--new-id $(ID) \
		--layout $(LAYOUT_FILE) \
		--rf $(RF_FILE) \
		--fw-hex $(TARGET_HEX)_with_bootloader.hex \
		-M $(SETTINGS_ADDR) $(LAYOUT_ADDR) $(LAYOUT_SIZE) \
		-o $(BUILD_TARGET_DIR)/$(TARGET)-$(LAYOUT_NAME).hex \
		-F scan_method=$(SCAN_METHOD) \
		-F chip_name=$(CHIP_NAME) \
		-F max_rows=$(SCANNER_MAX_ROWS) \

$(TARGET_HEX): $(DEP_FILES) $(REL_FILES)
	@echo "=== compiling target ==="
	@$(CC) --version | grep SDCC
	@$(CC) $(CFLAGS) $(LFLAGS) $(REL_FILES) -o $@
# @mv *.lk *.map *.mem -t $(OBJ_DIR)

size: $(TARGET_HEX)
	@echo "=== Size Information ($(TARGET))==="
	@scripts/hex-size.sh $< $(BUILD_TARGET_DIR)/$(TARGET).mem

# rule for c
$(OBJ_DIR)/%.rel: %.c
	@echo "compiling: $<"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# rule for asm
$(OBJ_DIR)/%.rel: %.S
	@mkdir -p $(dir $@)
	@$(AS) $(ASFLAGS) $@ $<

# rule for DEP_FILES
# sdcc doesn't pass the -MT flag correctly to the preprocessor, so need to
# call the preprocessor directly to generate dependency files
$(OBJ_DIR)/%.dep: %.c
	@mkdir -p $(dir $@)
	@$(PP) $(INC_PATHS) $(CDEFS) -MM -MT $(basename $@).rel $< -o $@

clean:
	rm -f $(BUILD_TARGET_DIR)/*.hex
	rm -f $(BUILD_TARGET_DIR)/*.lk
	rm -f $(BUILD_TARGET_DIR)/*.map
	rm -f $(BUILD_TARGET_DIR)/*.mem
	rm -fr $(OBJ_DIR)
	rm -fr nrfburn.txt

program-boot: $(MERGED_HEX) size
	$(KEYPLUS_CLI) bootloader -p $(MCU_STRING) | sleep 1.0
	./nrf24lu1p-512-bootloader/scripts/flash.py write_hex $<

program-unirecv: $(MERGED_HEX)
	$(KEYPLUS_CLI) bootloader -p $(MCU_STRING) | sleep 1.0
	../host-software/uniflash/uniflash.py flash $<

program-hard:: $(MERGED_HEX) size
	./scripts/strip_chip_id.sh $(MERGED_HEX) > $(MERGED_HEX)_no_chip_id.hex
	nrfburn -f $(FLASH_SIZE) -w $(MERGED_HEX)_no_chip_id.hex


version:
	$(CC) --version

-include $(DEP_FILES)

.PHONY: clean flash program all size version
