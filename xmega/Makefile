# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

# TODO: build system needs cleanup for building for different hardware

#######################################################################
#                        global build defines                         #
#######################################################################


ARCH = XMEGA

F_CPU = 32000000
F_USB = 48000000

# The clock speed to use when we are running on battery power (12MHz).
# We use 12MHz for battery mode because speeds >12MHz require voltage >1.8V
CLOCK_SPEED_SLOW = 12000000

# Output format. (can be srec, ihex, binary)
FORMAT = ihex

# Object files directory
OBJ_DIR = obj

BASE_PATH=../src
XMEGA_PATH=.

VPATH += $(BASE_PATH)
VPATH += $(XMEGA_PATH)

INC_PATHS += \
	-I$(BASE_PATH)

#######################################################################
#                        board config options                         #
#######################################################################

# Note: Specific board configs are stored in the `boards` directory.

ifndef BOARD
  include boards/default/config.mk
  TARGET = xmega_keyplus
else ifneq ("$(wildcard boards/$(BOARD)/config.mk)","")
  include boards/$(BOARD)/config.mk
  TARGET = xmega_keyplus_$(BOARD)
else
  $(error "Unknown board $(BOARD)")
endif

ifndef MCU
  MCU = atxmega32a4u
endif

#######################################################################
#                        common build settings                        #
#######################################################################

include $(BASE_PATH)/core/core.mk
include $(BASE_PATH)/usb/usb.mk
include $(BASE_PATH)/key_handlers/key_handlers.mk

include $(XMEGA_PATH)/xusb/makefile
include $(XMEGA_PATH)/xusb/xmega/makefile
include $(XMEGA_PATH)/hardware/hardware.mk

#######################################################################
#                         programmer options                          #
#######################################################################

# AVRDUDE_CMD=avrdude-pdi -C ~/local/etc/avrdude-pdi.conf -c usbasp -p $(AVRDUDE_PART)
AVRDUDE_CMD=avrdude -p $(AVRDUDE_PART) -c avrispmkII

#######################################################################
#                             c settings                              #
#######################################################################

CFLAGS += $(INC_PATHS)
CFLAGS += -Wno-error=unused-variable
CFLAGS += -Wno-error=unused-but-set-variable

# workaround for bad code generation on avr-gcc on linux (as of version 6.2.0)
CFLAGS += -fno-jump-tables

# List C source files here.
C_SRC += $(SRC_USB) \
	aes.c \
	descriptors.c \
	flash.c \
	fuses.c \
	hardware.c \
	led.c \
	led_vm.c \
	main.c \
	matrix_scanner.c \
	nonce.c \
	power.c \
	timer.c \
	usb_reports.c \
	ws2812.c \

# List Assembler source files here.
# NOTE: Use *.S for user written asm files. *.s is used for compiler generated
ASM_SRC =

# Optimization level, can be [0, 1, 2, 3, s].
OPT = s

# List any extra directories to look for include files here.
EXTRAINCDIRS = $(XMEGA_PATH)/

# Compiler flag to set the C Standard level.
CSTANDARD = -std=gnu99

# Place -D or -U options here for C sources
CDEFS += -DCLOCK_SPEED_SLOW=$(CLOCK_SPEED_SLOW)UL
CDEFS += -DF_CPU=$(F_CPU)UL
CDEFS += -DF_USB=$(F_USB)UL
CDEFS += -DBOARD=BOARD_$(BOARD) -DARCH=ARCH_$(ARCH)
CDEFS += $(USB_OPTS)
CDEFS += -D'HW_VERSION=$(HW_VERSION)'
CDEFS += -D'FW_VERSION=$(FW_VERSION)'

# Place -D or -U options here for ASM sources
ADEFS  = -DF_CPU=$(F_CPU)
ADEFS += -DF_USB=$(F_USB)UL
ADEFS += -DBOARD=BOARD_$(BOARD)
ADEFS += $(USB_OPTS)

#
ifdef ID
  CDEFS += -DDEVICE_ID=$(ID)
endif

#######################################################################
#                          optional imports                           #
#######################################################################

ifeq ($(USE_I2C), 1)
	C_SRC += wired.c
endif

# TODO: enable/disable nrf24 and i2c at run time using flash settings
ifeq ($(USE_NRF24), 1)
	C_SRC += nrf24.c
endif

CDEFS += -DUSE_CHECK_PIN=$(USE_CHECK_PIN)

#######################################################################
#                   xmega flash and memory settings                   #
#######################################################################

FUSE_SECTION_START=0x08F0020

# see avr-gcc for information on avrxmega2, avrxmega4, etc
# NOTE: haven't tested on all these chips
ifeq ($(MCU), atxmega16a4u)
  BOOT_SECTION_START = 0x004000
  BOOTLOADER_SIZE = 0x1000
  AVRDUDE_PART = x16a4
  LD_SCRIPT = avrxmega2.xn
  MCU_STRING = "ATxmega16a4u"
else ifeq ($(MCU), atxmega32a4u)
  BOOT_SECTION_START = 0x008000
  BOOTLOADER_SIZE = 0x1000
  AVRDUDE_PART = x32a4
  LD_SCRIPT = avrxmega2.xn
  MCU_STRING = "ATxmega32a4u"
else ifeq ($(MCU), atxmega64a4u)
  BOOT_SECTION_START = 0x010000
  BOOTLOADER_SIZE = 0x1000
  AVRDUDE_PART = x64a4
  LD_SCRIPT = avrxmega4.xn
  MCU_STRING = "ATxmega64a4u"
else ifeq ($(MCU), atxmega128a4u)
  BOOT_SECTION_START = 0x020000
  BOOTLOADER_SIZE = 0x2000
  AVRDUDE_PART = x128a4
  MCU_STRING = "ATxmega128a4u"
  # NOTE: avr-gcc says atxmega128a4u -> avrxmega7, but it also says avrxmega7
  # is for devices with more than 128KiB program memory and more than 64KiB
  # of RAM. So avrxmega7 is probably used with external RAM
  # LD_SCRIPT = avrxmega7.xn
  LD_SCRIPT = avrxmega6.xn
else
  $(error No part matches MCU='$(MCU)')
endif

# LD_SCRIPT_DIR = /usr/lib/ldscripts
LD_SCRIPT_DIR = ./ld-scripts

SETTING_ADDR := 0x6E00
LAYOUT_ADDR := 0x7000
LAYOUT_SIZE := 0x1000

LDFLAGS += -T $(LD_SCRIPT_DIR)/$(LD_SCRIPT)
LDFLAGS += -Wl,--section-start=.key_settings_block=$(SETTING_ADDR)
LDFLAGS += -Wl,--section-start=.key_layout_block=$(LAYOUT_ADDR)

CDEFS += -DSETTINGS_ADDR=$(SETTING_ADDR)
CDEFS += -DLAYOUT_ADDR=$(LAYOUT_ADDR)
CDEFS += -DLAYOUT_SIZE=$(LAYOUT_SIZE)

#######################################################################
#                              recepies                               #
#######################################################################

all: hex fuse lock

program: hex program-boot

# reset a board into bootloader via usb, then program it via the bootloader
program-boot: $(TARGET).hex
	./scripts/flash_hex.sh $<

# program a board that is already in in bootloader mode
program-boot-2: $(TARGET).hex
	./xusb-boot/scripts/flash.py -f $<

# program a board using an external programmer
program-hard: $(TARGET).hex
	$(AVRDUDE_CMD) -U flash:w:$<:i -E noreset

#######################################################################
#                     fuse and lock bit settings                      #
#######################################################################

# fuse options, see fuses.c (fuses values generated in $(TARGET).fuse)

FUSE0 = CC # JTAG_UID
FUSE1 = 00 # Watchdog settings
# b6 = BOOTRST, b5 = TOSCSEL, b1:0 = BODPD
FUSE2 = BD
# b4 = RSTDISBL, b3:2 = STARTUPTIME, b1 = WDLOCK, b0 = JTAGEN
FUSE4 = FF
# b5:4 = BODACT, b3 = EESAVE, b2:0 = BODLEVEL
FUSE5 = D6

program-fuses:
	$(AVRDUDE_CMD) \
		-U fuse0:w:0x$(FUSE0):m \
		-U fuse1:w:0x$(FUSE1):m \
		-U fuse2:w:0x$(FUSE2):m \
		-U fuse4:w:0x$(FUSE4):m \
		-U fuse5:w:0x$(FUSE5):m

# lock options, see fuses.c (lock bit values generated in $(TARGET).lock)
LOCKBITS_DEBUG := BF # RW enabled for external programmer
LOCKBITS_RELEASE := BC # RW disabled for external programmer
LOCKBITS = $(LOCKBITS_RELEASE)

program-lock:
	$(AVRDUDE_CMD) -U lock:w:0x$(LOCKBITS):m \

# extract the fuse section from the elf file
$(TARGET).fuse: $(TARGET).elf
	avr-objcopy -O $(FORMAT) -j .fuse --change-section-lma .fuse=$(FUSE_SECTION_START) $< $@

-include avr.mk

# Listing of phony targets.
.PHONY : all program bootload_only bootload program-fuses program-boot \
program-hard
