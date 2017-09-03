#
# MIT License
#
# Copyright (c) 2017 seethis.link
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

MCU = atmega328p
FORMAT = ihex
TARGET = wireless-slave
OBJ_DIR = obj

BASE_PATH = ../src
VPATH += $(BASE_PATH)

USE_KEYBOARD_REPORTS = 0
USE_SCANNER = 1
USE_NRF24 := 1
include $(BASE_PATH)/core/core.mk

# options: avr-crypto-lib, tiny-aes128, aes-min
#	avr-crypto-lib: gpl, fast asm implementation
#	tiny-aes128: unlicense
#	aes-min: mit, small but probably too slow
AES_LIB = avr-crypto-lib
include aes/aes.mk

C_SRC += \
	main.c \
	clock.c \
	scan.c \
	hardware.c \
	nonce.c \


ASM_FILES += \


EEPROM_FILE = ./eeprom-split.eep

# Oscillator frequency.
F_OSC = 8000000
# Processor frequency.
F_CPU = 4000000


# Output format. (can be srec, ihex, binary)
FORMAT = ihex

# Optimization level, can be [0, 1, 2, 3, s].
OPT = s

# Debugging format.
#     Native formats for AVR-GCC's -g are dwarf-2 [default] or stabs.
#     AVR Studio 4.10 requires dwarf-2.
#     AVR [Extended] COFF format requires stabs, plus an avr-objcopy run.
DEBUG = dwarf-2


# List any extra directories to look for include files here.
#     Each directory must be seperated by a space.
#     Use forward slashes for directory separators.
#     For a directory that has spaces, enclose it in quotes.
EXTRAINCDIRS =


# Compiler flag to set the C Standard level.
#     c89   = "ANSI" C
#     gnu89 = c89 plus GCC extensions
#     c99   = ISO C99 standard (not yet fully implemented)
#     gnu99 = c99 plus GCC extensions
CSTANDARD = -std=gnu99


# Place -D or -U options here
CDEFS += -DF_CPU=$(F_CPU)UL
CDEFS += -DF_OSC=$(F_OSC)UL
CDEFS += -DFLASH_32
CDEFS += -DNO_RF_RECEIVE
CDEFS += -DHARDWARE_SPECIFIC_SCAN

# Place -I options here
CDEFS += -I $(BASE_PATH)

# LDFLAGS += -lm -lc

-include ../xmega/avr.mk



build-left: clean
# build-left: dependencies
build-left: CDEFS += -DCE=1
build-left: CDEFS += -DCSN=2
build-left: CDEFS += -DDEVICE_ID=4
build-left: build-common

build-right: clean
# build-right: dependencies
build-right: CDEFS += -DCE=1
build-right: CDEFS += -DCSN=2
build-right: CDEFS += -DDEVICE_ID=5
build-right: build-common

build-middle: clean
build-middle: CDEFS += -DCE=1
build-middle: CDEFS += -DCSN=2
build-middle: CDEFS += -DDEVICE_ID=2
build-middle: build-common

build-8: clean
build-8: CDEFS += -DCE=1
build-8: CDEFS += -DCSN=2
build-8: CDEFS += -DDEVICE_ID=8
build-8: build-common

build-9: clean
build-9: CDEFS += -DCE=1
build-9: CDEFS += -DCSN=2
build-9: CDEFS += -DDEVICE_ID=9
build-9: build-common

build-common: sizebefore hex sizeafter

program-left: build-left
program-left: program-slave
# program-left: lock

program-right: build-right
program-right: program-slave
# program-right: lock

program-middle: build-middle
program-middle: program-slave
# program-right: lock

program-8: build-8
program-8: program-slave

program-9: build-9
program-9: program-slave

program: program-slave $(TARGET).hex

AVRDUDE_PROGRAMMER = -c usbasp -B 20
AVRDUDE_CMD=avrdude -p $(MCU) $(AVRDUDE_PROGRAMMER)

# fuses:
#	$(AVRDUDE_CMD) \
#		-U lfuse:w:0x42:m \
#		-U hfuse:w:0xd9:m \
#		-U efuse:w:0x06:m
fuses:
	$(AVRDUDE_CMD) \
		-U lfuse:w:"0x42":m \
		-U hfuse:w:"0xd9":m \
		-U efuse:w:"0xfe":m

lock:
	# disable reading and writing to flash and eeprom
	$(AVRDUDE_CMD) \
		-U lock:w:0x3c:m

eeprom:
	$(AVRDUDE_CMD) -U eeprom:w:$(EEPROM_FILE):i

program-slave:
	$(AVRDUDE_CMD) -U flash:w:$(TARGET).hex:i

# Listing of phony targets.
.PHONY : all begin finish end sizebefore sizeafter gccversion \
build elf hex eep lss sym coff extcoff \
clean clean_list program debug gdb-config \
program program-left program-right
