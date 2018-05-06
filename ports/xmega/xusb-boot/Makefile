# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

TARGET_BASE_NAME = xusb-boot

ARCH = XMEGA
F_CPU = 32000000
F_USB = 48000000

# Output format. (can be srec, ihex, binary)
FORMAT = ihex

BOARD_DIR = boards
BUILD_DIR = build

AVR_MKFILE_DIR = ./avr-makefile
include $(AVR_MKFILE_DIR)/boards.mk

#######################################################################
#                         programmer options                          #
#######################################################################

# AVRDUDE_CMD=avrdude-pdi -C ~/local/etc/avrdude-pdi.conf -c usbasp -p $(AVRDUDE_PART)
AVRDUDE_CMD=avrdude -p $(AVRDUDE_PART) -c avrispmkII

#######################################################################
#                            fuse settings                            #
#######################################################################

 # JTAG UID
FUSE0=00
# Watchdog settings
FUSE1=00 # No watch dog
# b6 = BOOTRST, b5 = TOSCSEL, b1:0 = BODPD
FUSE2=BD # (reset to bootloader and use sampled brown out detection sleep mode)
# b4 = RSTDISBL, b3:2 = STARTUPTIME, b1 = WDLOCK, b0 = JTAGEN
FUSE4=FF
# b5:4 = BODACT, b3 = EESAVE, b2:0 = BODLEVEL
FUSE5=D6 # sampled BOD @ 1.8V, preserve EEPROM on chip erase
# FUSE5=DE # sampled BOD @ 1.8V, erase EEPROM on chip erase

LOCKBITS_DEBUG := BF # RW enabled for external programmer
LOCKBITS_RELEASE := BC # RW disabled for external programmer
LOCKBITS = $(LOCKBITS_RELEASE)

#######################################################################
#                           compiler setup                            #
#######################################################################

# Update path
XMEGA_PATH=xusb
VPATH += $(XMEGA_PATH)
INC_PATHS += \

# Include sub makefiles
include $(XMEGA_PATH)/makefile
include $(XMEGA_PATH)/xmega/makefile

 # workaround for bad code generation on avr-gcc on linux (version 6.2.0)
CFLAGS += -fno-jump-tables

# we don't want to use interrupts in the bootloader, so poll the USB IRQ flags
CFLAGS += -DUSE_USB_POLLING

# Number of bytes to reserve for spm_interface vector table.
# Need 2 bytes for each entry to use `rjmp` (devices with 4kb bootloader)
# Need 4 bytes for each entry to use `jmp` (devices with 8kb bootloader)

include avr-makefile/avr-xmega.mk

SPM_INTERFACE_TABLE_ENTRIES = 24
ifeq ($(BOOTLOADER_SIZE), 0x1000)
  JMP_SIZE = 2
else ifeq ($(BOOTLOADER_SIZE), 0x2000)
  JMP_SIZE = 4
else
  $(error "Unsupported bootloader size BOOTLOADER_SIZE=$(BOOTLOADER_SIZE)")
endif
SPM_INTERFACE_TABLE_SIZE = $(shell echo "$$(($(SPM_INTERFACE_TABLE_ENTRIES) * $(JMP_SIZE) ))")

CFLAGS += $(INC_PATHS)

# List C source files here.
C_SRC += $(SRC_USB) \
	descriptors.c \
	boot_protocol.c \
	vendor_report.c \
	util.c \
	main.c \

# List Assembler source files here.
# NOTE: Use *.S for user written asm files. *.s is used for compiler generated
ASM_SRC = \
	init_vector.S \
	sp_driver.S \
	spm_interface.S \
	main_pre_init.S \

# Optimization level, can be [0, 1, 2, 3, s].
OPT = s

# List any extra directories to look for include files here.
EXTRAINCDIRS = $(XMEGA_PATH)/

# Compiler flag to set the C Standard level.
CSTANDARD = -std=gnu99

CDEFS += $(USB_OPTS)
ADEFS += $(USB_OPTS)

# LD_SCRIPT_DIR = /usr/lib/ldscripts
LD_SCRIPT_DIR = ./ld-scripts

SPM_INTERFACE_TABLE_POS = $(shell python -c \
    "print(hex($(BOOT_SECTION_START)+$(BOOTLOADER_SIZE)-$(SPM_INTERFACE_TABLE_SIZE)))")
LDFLAGS += -T $(LD_SCRIPT_DIR)/$(LD_SCRIPT)
LDFLAGS += -Wl,--section-start=.text=$(BOOT_SECTION_START)
LDFLAGS += -Wl,--section-start=.noinit=0x802400 # magic flag for bootloader entry
LDFLAGS += -Wl,--section-start=.spm_interface_table=$(SPM_INTERFACE_TABLE_POS)

all: fuse hex

include $(AVR_MKFILE_DIR)/avr.mk
include $(AVR_MKFILE_DIR)/avr-program.mk

# Listing of phony targets.
.PHONY : all begin finish end sizebefore sizeafter gccversion \
build elf hex eep lss sym coff extcoff doxygen clean \
