// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#define USB_VERSION_ACCESS_TYPE_bp      (12)
#define USB_VERSION_ACCESS_TYPE_MASK    (0xf000)
#define USB_VERSION_HID_INTERFACE_3     (0 << USB_VERSION_ACCESS_TYPE_bp)
#define USB_VERSION_HID_INTERFACE_2     (1 << USB_VERSION_ACCESS_TYPE_bp)
#define USB_VERSION_HID_INTERFACE_1     (2 << USB_VERSION_ACCESS_TYPE_bp)
#define USB_VERSION_HID_INTERFACE_0     (3 << USB_VERSION_ACCESS_TYPE_bp)

