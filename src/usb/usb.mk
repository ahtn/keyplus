# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

MAKEFILE_INC += $(KEYPLUS_PATH)/usb/usb.mk

USB_HID_PATH = $(KEYPLUS_PATH)/usb

ifeq ($(USB_DESCRIPTOR_ARRANGEMENT), normal)
  C_SRC += $(USB_HID_PATH)/desc/normal/descriptors.c
  CDEFS += -DUSB_DESCRIPTOR_ARRANGEMENT=0
else ifeq ($(USB_DESCRIPTOR_ARRANGEMENT), compact)
  C_SRC += $(USB_HID_PATH)/desc/compact/descriptors.c
  CDEFS += -DUSB_DESCRIPTOR_ARRANGEMENT=1
else
  $(error "USB_DESCRIPTOR_ARRANGEMENT not set")
endif
