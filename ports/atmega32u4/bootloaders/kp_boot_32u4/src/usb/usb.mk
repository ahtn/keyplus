# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

USB_HID_PATH = usb

C_SRC += \
	$(USB_HID_PATH)/device_descriptors.c \

ifdef USB_VID
  CDEFS += -DUSB_VID=0x$(USB_VID)
endif

ifdef USB_VID
  CDEFS += -DUSB_PID=0x$(USB_PID)
endif
