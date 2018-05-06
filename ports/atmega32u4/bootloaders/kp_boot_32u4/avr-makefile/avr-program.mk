
AVRDUDE_EXTRA = -C +$(AVR_MKFILE_DIR)/avrdude-extra.conf

# program a board using an external programmer
program-hard: $(TARGET_HEX)
	$(AVRDUDE_CMD) $(AVRDUDE_EXTRA) -e -U flash:w:$<:i

program-hard-no-erase: $(TARGET_HEX)
	$(AVRDUDE_CMD) $(AVRDUDE_EXTRA) -U flash:w:$<:i

# erase a board using an external programmer
program-erase:
	$(AVRDUDE_CMD) $(AVRDUDE_EXTRA) -e

# readback flash and eeprom
.PHONY:
readback:
	$(AVRDUDE_CMD) $(AVRDUDE_EXTRA) \
        -U flash:r:readback-flash.hex:i \
        -U eeprom:r:readback-eeprom.hex:i

.PHONY:
program-fuses:
	$(AVRDUDE_CMD) $(AVRDUDE_EXTRA) $(AVRDUDE_DEVICE_FUSES)

.PHONY:
program-lock:
	$(AVRDUDE_CMD) $(AVRDUDE_EXTRA) $(AVRDUDE_DEVICE_LOCK)
