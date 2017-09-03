// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include "xmega/usb_xmega.h"

#define USB_EP0_IN_BUF 0
#define USB_EP0_IN_WRITE(x) usb_ep0_in(x)
#define USB_EP0_HSNAK()
#define USB_EP0_STALL() usb_ep0_stall()
