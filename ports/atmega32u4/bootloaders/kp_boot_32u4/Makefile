# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

TARGET_BASE_NAME = kp_boot_32u4

ARCH = AVR8
F_CPU = 16000000

# Output format. (can be srec, ihex, binary)
FORMAT = ihex

USB_VID = 1209
USB_PID = BB05

VPATH += src
CFLAGS += -Isrc

#######################################################################
#                        board config options                         #
#######################################################################

BOARD_DIR = boards
BUILD_DIR = build

# Note: Specific board configs are stored in the `boards` directory.

ifndef BOARD
  BOARD = default
endif

# Look for the board appropriate board .mk file to include
AVR_MK_FILE_DIR = ./avr-makefile
include $(AVR_MK_FILE_DIR)/boards.mk

#######################################################################
#                       include other makefiles                       #
#######################################################################

include avr-makefile/avr-mega.mk

include src/usb/usb.mk

#######################################################################
#                         programmer options                          #
#######################################################################

AVRDUDE_PROGRAMMER = usbasp
AVRDUDE_CMD = avrdude -p $(MCU) -c $(AVRDUDE_PROGRAMMER)

#######################################################################
#                           compiler setup                            #
#######################################################################

CFLAGS += -Wno-error=unused-function
# CFLAGS += -Wl,-verbose

# CFLAGS += -DUSE_KEYBOARD_TEST=1

# List C source files here.
C_SRC += \
	main.c \
	usb.c

# List Assembler source files here.
# NOTE: Use *.S for user written asm files. *.s is used for compiler generated
ASM_SRC = \
	spm.S \

# Optimization level, can be [0, 1, 2, 3, s].
OPT = s

# List any extra directories to look for include files here.
EXTRAINCDIRS =

# Compiler flag to set the C Standard level.
CSTANDARD = -std=gnu99

CDEFS +=
ADEFS +=

CFLAGS += -DBOOT_SIZE=BOOT_SIZE_$(BOOTSZ)
CFLAGS += -DCHIP_ID=CHIP_ID_$(MCU_STRING)

# Position the spm_call function at the very end of flash/bootloader
SPM_CALL_SIZE = 16
# SPM_CALL_POS = $(shell python -c "print( hex(\ $(FLASH_SIZE)-$(SPM_CALL_SIZE)\) )")
# BOOT_SECTION_START = $(shell python -c "print( hex(\$(FLASH_SIZE)-$(BOOT_SIZE)\) )")
SPM_CALL_POS = $(shell python -c "print( hex( $(FLASH_SIZE)-$(SPM_CALL_SIZE)) )")
BOOT_SECTION_START = $(shell python -c "print( hex($(FLASH_SIZE)-$(BOOT_SIZE)) )")

# LD_SCRIPT_DIR = /usr/lib/ldscripts
LD_SCRIPT_DIR = ./ld_scripts

LD_SCRIPT = avr5.xn

LDFLAGS += -T $(LD_SCRIPT_DIR)/$(LD_SCRIPT)

LDFLAGS += -Wl,--section-start=.text=$(BOOT_SECTION_START)

LDFLAGS += -Wl,--section-start=.boot_extra=$(SPM_CALL_POS)
LDFLAGS += -Wl,--undefined=.boot_extra

#######################################################################
#                            fuse settings                            #
#######################################################################

# to program fuses settings run: `make program-fuses`

#####################
# 4kb for pro micro #
#####################

# LFUSE = 7F
# HFUSE = D8 # same as below, except 4kb BOOTSZ
# EFUSE = CB

#######
# 1kb #
#######

# LFUSE: 0x7F == 0b0111_1111
# CKDIV8     : 0    -> Clock divided by 8 on reset
# CKOUT      : 1    -> Clock output disabled
# SUT        : 11   -> 14CK + 65ms start up time.  16K CK from power down/save
# CKSEL3..1  : 111  -> 8-16MHz crystal
# CKSEL0     : 1    -> (used to help choose SUT value above)
LFUSE = 7F

# HFUSE: 0xDC == 0b1101_1100
# * OCDEN   : 1   -> OCD disabled
# * JTAGEN  : 1   -> JTAG disabled
# * SPIEN   : 0   -> SPI programming enabled
# * WDTON   : 1   -> Don't force Watchdog timer on
# * EESAVE  : 1   -> Preserve EEPROM after chip erase
# * BOOTSZ  : 10  -> 1024 byte bootloader section
# * BOOTRST : 0   -> On reset, start execution in the bootloader
HFUSE = DC

# EFUSE: 0xCB == 0bXX11_1011
# * B7-B4   : XX11 -> Unused
# * HWBE    : 0    -> Hardware boot pin disabled
# * BODLEVEL: 011  -> Brown out trigger at 2.6V
EFUSE = CB

###############
#  lock bits  #
###############

# to program fuses settings run: `make program-lock`

# LOCK BITS: 0x2F == 0bXX101111
# B7-B6 : XX -> Unused
# BLB1  : 10 -> Write not allowed in bootloader (read allowed)
# BLB0  : 11 -> Read and write allowed in application section
# LB    : 11 -> External programmer read/write allowed
LOCKBITS = 2F

#######################################################################
#                               recipes                               #
#######################################################################


all: hex fuse

hex: Makefile

program-dfu: $(TARGET_HEX)
	dfu-programmer $(MCU) erase --force
	dfu-programmer $(MCU) flash $(TARGET_HEX)
	dfu-programmer $(MCU) start

include avr-makefile/avr.mk
include avr-makefile/avr-program.mk

# Listing of phony targets.
.PHONY : all begin finish end sizebefore sizeafter gccversion \
build elf hex eep lss sym coff extcoff doxygen clean program-fuses \
