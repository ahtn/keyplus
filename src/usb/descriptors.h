// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

enum {
    USB_DESCRIPTORS_NORMAL = 0,
    USB_DESCRIPTORS_COMPACT = 1,
};

#include "usb/desc/common.h"

#if USB_DESCRIPTOR_ARRANGEMENT == 0
#  include "usb/desc/normal/descriptors.h"
#elif USB_DESCRIPTOR_ARRANGEMENT == 1
#  include "usb/desc/compact/descriptors.h"
#else
#  error "USB_DESCRIPTOR_ARRANGEMENT not defined"
#endif
