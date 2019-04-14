# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

MAKEFILE_INC += Makefile
MAKEFILE_INC += $(EFM8_PATH)/efm8.mk

ALL_CFLAGS += \
	$(CFLAGS) \
	$(CDEFS) \
	$(INC_PATHS) \
	$(LIB_PATHS) \
	$(OPTIMIZATION) \

include $(EFM8_PATH)/obj_file.mk

C_REL_FILES = $(call obj_file_list, $(C_SRC),rel)
ASM_REL_FILES = $(call obj_file_list, $(ASM_SRC),rel)
DEP_FILES = $(call obj_file_list, $(C_SRC),dep)

REL_FILES = $(C_REL_FILES) $(ASM_REL_FILES)

all: pre_build $(TARGET_HEX) size

.PHONY: pre_build
pre_build:
	@echo "======  Building: $(TARGET_HEX)  ======="
	@echo ">>> CFLAGS:"
	@echo $(CFLAGS)
	@echo ">>> CDEFS:"
	@echo $(CDEFS)
	@echo ">>> INC_PATHS:"
	@echo $(INC_PATHS)
	@echo ">>> LIB_PATHS:"
	@echo $(LIB_PATHS)
	@echo ">>> LFLAGS:"
	@echo $(LFLAGS)
	@echo
	@echo "=== Compiling files ==="

$(REL_FILES): $(MAKEFILE_INC)

# @echo "REL_FILES:"
# @echo $(REL_FILES)


$(TARGET_HEX): $(REL_FILES)
	@echo
	@echo "=== Compiling and linking target hex file==="
	@$(CC) $(ALL_CFLAGS) $(LFLAGS) $(REL_FILES) -o $@
	@mv "$(TARGET).lk" "$(TARGET).map" "$(TARGET).mem" -t $(OBJ_DIR)

.PHONY:
size: $(TARGET_HEX)
	@echo
	@echo "=== Size Information ($(TARGET_HEX))==="
	@$(EFM8_PATH)/scripts/hex-size.sh $< "$(TARG_OBJ).mem" "$(CODE_SIZE)"
	@echo

define c_file_recipe
	@echo "compiling: $$<"
	@$(CC) $$(ALL_CFLAGS) -c $$< -o $$@
endef

define asm_file_recipe
	@echo "assembling: $$<"
	@$(AS) $$(ASFLAGS) $$@ $$<
endef

# rule for DEP_FILES
# sdcc doesn't pass the -MT flag correctly to the preprocessor, so need to
# call the preprocessor directly to generate dependency files
define dep_file_recipe
	@$(PP) $$(INC_PATHS) $$(CDEFS) -MM -MT $$(basename $$@).rel $$< -o $$@
endef

# Create the recipes for the object files
$(call create_recipes, $(C_SRC),c_file_recipe,rel)
$(call create_recipes, $(C_SRC),dep_file_recipe,dep)
$(call create_recipes, $(ASM_SRC),asm_file_recipe,rel)

.PHONY:
clean:
	rm -f $(TARGET_HEX)
	rm -f $(TARG_OBJ).lk
	rm -f $(TARG_OBJ).map
	rm -f $(TARG_OBJ).mem
	rm -fr $(OBJ_DIR)
