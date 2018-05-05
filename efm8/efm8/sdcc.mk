# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

MAKEFILE_INC += Makefile
MAKEFILE_INC += $(EFM8_PATH)/efm8.mk

CFLAGS += \
	$(CDEFS) \
	$(INC_PATHS) \
	$(OPTIMIZATION) \

C_REL_FILES = $(patsubst %.c,$(OBJ_DIR)/%.rel,$(C_SRC))
ASM_REL_FILES = $(patsubst %.S,$(OBJ_DIR)/%.rel,$(ASM_SRC))
DEP_FILES = $(patsubst %.c,$(OBJ_DIR)/%.dep,$(C_SRC))

REL_FILES = $(C_REL_FILES) $(ASM_REL_FILES)

all: $(TARGET_HEX) size

$(REL_FILES): $(MAKEFILE_INC)

$(TARGET_HEX): $(REL_FILES)
	@echo "=== compiling target ==="
	$(CC) $(CFLAGS) $(LFLAGS) $(REL_FILES) -o $@
	mv "$(TARGET).lk" "$(TARGET).map" "$(TARGET).mem" -t $(OBJ_DIR)

.PHONY:
size: $(TARGET_HEX)
	@echo "=== Size Information ($(TARGET_HEX))==="
	@$(EFM8_PATH)/scripts/hex-size.sh $< "$(TARG_OBJ).mem" "$(CODE_SIZE)"

# rule for c
$(OBJ_DIR)/%.rel: %.c $(EXTRA_DEPENDENCIES)
	@echo "compiling: $<"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# rule for asm
$(OBJ_DIR)/%.rel: %.S $(EXTRA_DEPENDENCIES)
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) $@ $<

# rule for DEP_FILES
# sdcc doesn't pass the -MT flag correctly to the preprocessor, so need to
# call the preprocessor directly to generate dependency files
$(OBJ_DIR)/%.dep: %.c
	@mkdir -p $(dir $@)
	@$(PP) $(INC_PATHS) $(CDEFS) -MM \
		-MT $(basename $@).rel $< -o $@

.PHONY:
clean:
	rm -f $(TARGET_HEX)
	rm -f $(TARG_OBJ).lk
	rm -f $(TARG_OBJ).map
	rm -f $(TARG_OBJ).mem
	rm -fr $(OBJ_DIR)
