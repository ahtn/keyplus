# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

ifeq ($(USE_USB), 1)
    C_SRC += \
        $(USB_REPORTS_PATH)/keyboard_report.c \
        $(USB_REPORTS_PATH)/media_report.c \
        $(USB_REPORTS_PATH)/vendor_report.c \
        $(USB_REPORTS_PATH)/mouse_report.c \

    CDEFS += -DHAS_MOUSE_SUPPORT
endif
