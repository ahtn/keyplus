# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

TARGET	= nrf24lu1_keyboard
OBJ_DIR	= obj
MCU		= NRF24LU1
F_CPU	= 16000000

# valid 16 or 32
FLASH_SIZE = 32

BASE_PATH = ../src

USE_KEYBOARD_REPORTS := 1
USE_NRF24 := 1
USE_I2C := 0
USE_SCANNER := 0

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


include $(BASE_PATH)/core/core.mk
include $(BASE_PATH)/usb/usb.mk
include $(BASE_PATH)/key_handlers/key_handlers.mk

VPATH += $(BASE_PATH)

INC_PATHS += \
	-I. \
	-I$(BASE_PATH) \

CDEFS += \
	-D$(MCU) \
	-DINTEL_8052 \
	-DFLASH_$(FLASH_SIZE) \
	-DNO_RF_TRANSMIT \
	-DF_CPU=$(F_CPU)UL \


# Using optimize for speed can result in a smaller binary in sdcc
OPTIMIZATION = --opt-code-speed
# OPTIMIZATION = --opt-code-size

ifeq ($(FLASH_SIZE), 16)
	BOOTLOADER = bins/nrf24lu1_bootloader-f16.hex
	CODE_SIZE=--code-size 0x4000
else ifeq ($(FLASH_SIZE), 32)
	BOOTLOADER = bins/nrf24lu1_bootloader-f32.hex
	CODE_SIZE=--code-size 0x8000
else
	$(error Invalid size for flash='$(FLASH_SIZE)')
endif


AS = /usr/local/bin/sdas8051
CC = /usr/local/bin/sdcc
PP = /usr/local/bin/sdcpp
CFLAGS   = \
	$(CDEFS) \
	$(INC_PATHS) \
	$(OPTIMIZATION) \
	--fomit-frame-pointer \
	--model-small \
	# --stack-auto \
	# --Werror \
	# --model-small \
	# --code-movx \
	# --disable-warning 85 \
	# --model-large \
	#

LFLAGS   = \
	--code-loc 0x0000 \
	$(CODE_SIZE) \
	--xram-loc 0x8000 \
	--xram-size 0x800 \
	--iram-size 0x100 \
	--stack-loc 0x080 \
	--stack-size 0x060 \
	# --parms-in-bank1

ASFLAGS  = -xglospff

C_REL_FILES = $(patsubst %.c, $(OBJ_DIR)/%.rel, $(C_SRC))
ASM_REL_FILES = $(patsubst %.S, $(OBJ_DIR)/%.rel, $(ASM_SRC))
DEP_FILES = $(patsubst %.c, $(OBJ_DIR)/%.dep, $(C_SRC))
REL_FILES = $(C_REL_FILES) $(ASM_REL_FILES)

all: $(TARGET).hex size

$(TARGET).hex: $(REL_FILES) $(BOOTLOADER)
	@echo "=== compiling target ==="
	$(CC) $(CFLAGS) $(LFLAGS) $(REL_FILES) -o $@
	@echo "=== appending bootloader ==="
	cat $(BOOTLOADER) >> $@
# sort the hex for easier inspection
	@scripts/sort-intel-hex $@ > $@-temp
	@mv $@-temp $@
	@mv *.lk *.map *.mem -t $(OBJ_DIR)

size: $(TARGET).hex
	@echo "=== Size Information ($(TARGET))==="
	@scripts/hex-size.sh $< obj/$(TARGET).mem

# rule for c
$(OBJ_DIR)/%.rel: %.c
	@echo "compiling: $<"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# rule for asm
$(OBJ_DIR)/%.rel: %.S
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) $@ $<

# rule for DEP_FILES
# sdcc doesn't pass the -MT flag correctly to the preprocessor, so need to
# call the preprocessor directly to generate dependency files
$(OBJ_DIR)/%.dep: %.c
	@mkdir -p $(dir $@)
	@$(PP) $(INC_PATHS) $(CDEFS) -MM -MT $(basename $@).rel $< -o $@

clean:
	rm -f $(TARGET).hex
	rm -fr $(OBJ_DIR)
	rm -fr nrfburn.txt

# program: flash
program-boot: $(TARGET).hex size
	./scripts/flash_hex.sh $(TARGET).hex

program-hard: flash
flash: $(TARGET).hex size
	nrfburn -f $(FLASH_SIZE) -w $(TARGET).hex

-include $(DEP_FILES)

.PHONY: clean flash program all size
