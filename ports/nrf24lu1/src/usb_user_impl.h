// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include "nrf24lu1_usb.h"
#include "nrf24lu1_usb_regs.h"

#define USB_EP0_IN_BUF (in0buf)

#define USB_EP0_IN_WRITE(x) (in0bc = x)

// clear hsnak bit
#define USB_EP0_HSNAK() (ep0cs = EP0CS_HSNAK_bm)

// set stall and dstall bits to stall during setup data transaction
#define USB_EP0_STALL() (ep0cs = (EP0CS_DSTALL_bm | EP0CS_EP0STALL_bm))
