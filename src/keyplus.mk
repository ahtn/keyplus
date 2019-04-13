# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

MAKEFILE_INC += $(KEYPLUS_PATH)/keyplus.mk

LAYOUT_NAME=$(basename $(notdir $(LAYOUT_FILE)))
MERGED_HEX=$(basename $(TARGET_HEX))-$(LAYOUT_NAME).hex

.PHONY: all print_keyplus_info create_build_dirs hex

all: hex $(MERGED_HEX)

hex: print_keyplus_info create_build_dirs $(EXTRA_TARGET)

$(LAYOUT_FILE):

create_build_dirs:
	@mkdir -p $(BUILD_TARGET_DIR)

print_keyplus_info:
	@echo "### Build settings ###"
	@echo -e "TARGET:\t\t$(TARGET)"
	@echo -e "BOARD:\t\t$(BOARD)"
	@echo -e "MCU:\t\t$(MCU)"
	@echo -e "LAYOUT_FILE:\t$(LAYOUT_FILE)"
	@echo -e "RF_FILE:\t$(RF_FILE)"
	@echo "compiler c flags:"
	@echo "$(ALL_CFLAGS)"
	@echo ""

$(MERGED_HEX): $(TARGET_HEX) $(LAYOUT_FILE) $(RF_FILE)
	@echo
	@echo "### Merging layout settings into hex file ###"
	$(KEYPLUS_CLI) program \
		$(KEYPLUS_CLI_EXTRA) \
		--new-id $(ID) \
		--layout "$(LAYOUT_FILE)" \
		--rf "$(RF_FILE)" \
		--fw-hex "$(TARGET_HEX)" \
		-M $(SETTINGS_ADDR) $(LAYOUT_ADDR) $(LAYOUT_SIZE) \
		-o "$(MERGED_HEX)" \
		-F chip_name="$(MCU_STRING)" \
		-F scan_method=$(SCAN_METHOD) \
		-F max_rows=$(MAX_NUM_ROWS) \

# vim: noet
