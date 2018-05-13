# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

VPATH += $(BASE_PATH)/src
VPATH += $(EFM8_PATH)

ifndef MCU
  $(error "MCU not defined")
endif

ifndef MCU_SPECIFIC
  $(error "MCU_SPECIFIC not defined")
endif

ifndef F_CPU
  $(error "F_CPU not defined")
else
  CDEFS += -DF_CPU=$(F_CPU)ULL
endif

ifeq ($(MCU), EFM8UB10F16)
  MCU_FAMILY := EFM8UB1
  CODE_SIZE := 0x4000 # 16kB
  XRAM_SIZE := 0x0800 #  2kB
else ifeq ($(MCU), EFM8UB11F16)
  MCU_FAMILY := EFM8UB1
  CODE_SIZE := 0x4000 # 16kB
  XRAM_SIZE := 0x0800 #  2kB
else ifeq ($(MCU), EFM8UB10F16)
  MCU_FAMILY := EFM8UB1
  CODE_SIZE := 0x4000 # 16kB
  XRAM_SIZE := 0x0800 #  2kB
else ifeq ($(MCU), EFM8UB10F8)
  MCU_FAMILY := EFM8UB1
  CODE_SIZE := 0x2000 #  8kB
  XRAM_SIZE := 0x0800 #  2kB
else ifeq ($(MCU), EFM8UB20F32)
  MCU_FAMILY := EFM8UB2
  CODE_SIZE := 0x8000 # 32kB
  XRAM_SIZE := 0x0800 #  2kB
else ifeq ($(MCU), EFM8UB20F64)
  MCU_FAMILY := EFM8UB2
  CODE_SIZE := 0xFC00 # 64kB
  XRAM_SIZE := 0x1000 #  4kB
else ifeq ($(MCU), EFM8UB30F40)
  MCU_FAMILY := EFM8UB3
  CODE_SIZE := 0xA000 # 40kB
  XRAM_SIZE := 0x0800 #  2kB
else
  $(error "No definition for this MCU='$(MCU)' (NOTE: must be all CAPS)"\
	"TODO: not many have been defined yet")
endif

# $(error echo 'XRAM == $(XRAM_SIZE)')

# TODO: check if this is true for all micros
CODE_LOC := 0x0000
XRAM_LOC := 0x0000

ifndef STACK_LOC
  STACK_LOC = 0x80
endif

ifndef STACK_SIZE
  STACK_SIZE = 0x60
endif

CDEFS += -DMCU_STRING=$(MCU_STRING)
CDEFS += -DPIN_COUNT=$(PIN_COUNT)
CDEFS += -DMCU_$(MCU_FAMILY)
CDEFS += -D$(MCU_FAMILY)_DEVICE=$(MCU_SPECIFIC)

VPATH += $(EFM8_PATH)/mcu/$(MCU_FAMILY)
VPATH += $(EFM8_PATH)/lib

INC_PATHS += -I$(BASE_PATH)
INC_PATHS += -I$(EFM8_PATH)
INC_PATHS += -I$(EFM8_PATH)/mcu
INC_PATHS += -I$(EFM8_PATH)/mcu/$(MCU_FAMILY)/
INC_PATHS += -I$(EFM8_PATH)/mcu/$(MCU_FAMILY)/inc
INC_PATHS += -I$(EFM8_PATH)/mcu/$(MCU_FAMILY)/peripheral_driver/inc
INC_PATHS += -I$(EFM8_PATH)/si8051Base

ifndef LFLAGS_EXTRA
  LFLAGS_EXTRA = --fomit-frame-pointer
endif

LFLAGS += \
	$(LFLAGS_EXTRA) \
	$(OPTIMIZATION) \
	--model-$(MEMORY_MODEL) \
	--iram-size 0x100 \
	--stack-loc $(STACK_LOC) \
	--stack-size $(STACK_SIZE) \
	--code-loc $(CODE_LOC) \
	--code-size $(CODE_SIZE) \
	--xram-loc  $(XRAM_LOC)\
	--xram-size $(XRAM_SIZE) \

# Can't use these values on EFM8 architecture:
# --code-movx

ifdef SIMPLICITY_STUDIO_PATH
  ADAPTER_PACKS_PATH="$(SIMPLICITY_STUDIO_PATH)/developer/adapter_packs"
  FLASH_8051="$(ADAPTER_PACKS_PATH)/c8051/flash8051"
  INSPECT_8051="$(ADAPTER_PACKS_PATH)/inspect_c8051/device8051"
  FLASH_EFM8="$(ADAPTER_PACKS_PATH)/efm8/flashefm8"
endif
