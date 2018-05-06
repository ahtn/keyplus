TARGET   = bootloader.hex

ASM_FILES = main.S

AS       = sdas8051
CC       = sdcc

ASFLAGS  = -xglos

ASM_REL_FILES = $(patsubst %.S,obj/%.rel,$(ASM_FILES))
REL_FILES += $(ASM_REL_FILES)

# clean so in case changes are made to include files
all: clean $(TARGET) size

$(TARGET): $(REL_FILES)
	$(CC) $(REL_FILES) -o $(TARGET)

$(REL_FILES): | obj

obj:
	@mkdir -p $@

obj/%.rel: %.S
	$(AS) $(ASFLAGS) $@ $<

size: $(TARGET)
	size $(TARGET)

clean:
	rm -f $(TARGET) *.lnk *.lst *.map *.rel *.rst *.sym *.mem *.lk *.asm *.lk *.cdb *.omf
	rm -fr obj

flash: clean $(TARGET) size
	nrfburn -f 16 -w $(TARGET)

flash16: clean $(TARGET) size
	nrfburn -f 16 -w $(TARGET)

flash32: clean $(TARGET) size
	nrfburn -f 32 -w $(TARGET)

.PHONY: size clean flash
