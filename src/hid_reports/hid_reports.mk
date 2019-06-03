# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)


HID_REPORTS_PATH = $(KEYPLUS_PATH)/hid_reports

ifeq ($(USE_HID), 1)
    C_SRC += \
        $(HID_REPORTS_PATH)/keyboard_report.c \
        $(HID_REPORTS_PATH)/media_report.c \
        $(HID_REPORTS_PATH)/vendor_report.c \
        $(HID_REPORTS_PATH)/mouse_report.c \
        $(HID_REPORTS_PATH)/hid_reports.c \

    CDEFS += -DHAS_MOUSE_SUPPORT
endif
