# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

.PHONY: program-list
program-list:
	$(INSPECT_8051) -slist

.PHONY: program-efm8
program-efm8: $(TARGET_HEX)
	$(FLASH_EFM8) -sn $(SERIAL_NUM) -upload $< -erasemode page

.PHONY: program-c8051
program-c8051: $(TARGET_HEX)
	$(FLASH_8051) -sn $(SERIAL_NUM) -upload $< -erasemode page

.PHONY: program-hex-file
program-hex-file: $(HEX_FILE)
	$(FLASH_8051) -sn $(SERIAL_NUM) -upload $< -erasemode full
