# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

TARGET	= blinky
OBJ_DIR	= obj
MCU		= C8051F387
F_CPU	= 12000000 / 8

BASE_PATH = .
VPATH += $(BASE_PATH)/src

INC_PATHS += \
	-I$(BASE_PATH)/src

C_SRC += \
	main.c \

ASM_SRC = \
	# crtxinit.S \

# Using optimize for speed can result in a smaller binary in sdcc
OPTIMIZATION = --opt-code-speed
# OPTIMIZATION = --opt-code-size

CODE_LOC := 0x0000
CODE_SIZE := 0x4000

XRAM_LOC := 0x0000
XRAM_SIZE := 0x0800
# XRAM_SIZE := 0x1000

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
	--code-loc $(CODE_LOC) \
	--code-size $(CODE_SIZE) \
	--xram-loc  $(XRAM_LOC)\
	--xram-size $(XRAM_SIZE) \
	--iram-size 0x100 \
	--stack-loc 0x080 \
	--stack-size 0x060 \
	# --parms-in-bank1

ASFLAGS  = -xglospff

C_REL_FILES = $(patsubst %.c, $(OBJ_DIR)/%.rel, $(C_SRC))
ASM_REL_FILES = $(patsubst %.S, $(OBJ_DIR)/%.rel, $(ASM_SRC))
DEP_FILES = $(patsubst %.c, $(OBJ_DIR)/%.dep, $(C_SRC))
REL_FILES = $(C_REL_FILES) $(ASM_REL_FILES)

all: $(TARGET).hex

# $(TARGET).hex: $(REL_FILES) $(BOOTLOADER)
# 	@echo "=== compiling target ==="
# 	$(CC) $(CFLAGS) $(LFLAGS) $(REL_FILES) -o $@
# 	@echo "=== appending bootloader ==="
# 	cat $(BOOTLOADER) >> $@
# # sort the hex for easier inspection
# 	@scripts/sort-intel-hex $@ > $@-temp
# 	@mv $@-temp $@
# 	@mv *.lk *.map *.mem -t $(OBJ_DIR)

$(TARGET).hex: $(REL_FILES)
	@echo "=== compiling target ==="
	$(CC) $(CFLAGS) $(LFLAGS) $(REL_FILES) -o $@
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

-include $(DEP_FILES)

.PHONY: clean flash program all size
