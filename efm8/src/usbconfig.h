// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#define SLAB_USB_FULL_SPEED 1
#define SLAB_USB_BUS_POWERED 1

#include "usb_desc/descriptors.h"

#define SLAB_USB_EP1IN_USED                 1
#define SLAB_USB_EP1IN_TRANSFER_TYPE        USB_EPTYPE_INTR
#define SLAB_USB_EP1IN_MAX_PACKET_SIZE      EP1_IN_SIZE

#define SLAB_USB_EP1OUT_USED                0
#define SLAB_USB_EP1OUT_MAX_PACKET_SIZE     EP1_OUT_SIZE

#define SLAB_USB_EP2IN_USED                 1
#define SLAB_USB_EP2IN_TRANSFER_TYPE        USB_EPTYPE_INTR
#define SLAB_USB_EP2IN_MAX_PACKET_SIZE      EP2_IN_SIZE

#define SLAB_USB_EP2OUT_USED                0
#define SLAB_USB_EP2OUT_TRANSFER_TYPE       USB_EPTYPE_INTR
#define SLAB_USB_EP2OUT_MAX_PACKET_SIZE     EP2_OUT_SIZE

#define SLAB_USB_EP3IN_USED                 1
#define SLAB_USB_EP3IN_TRANSFER_TYPE        USB_EPTYPE_INTR
#define SLAB_USB_EP3IN_MAX_PACKET_SIZE      EP3_IN_SIZE

#define SLAB_USB_EP3OUT_USED                1
#define SLAB_USB_EP3OUT_TRANSFER_TYPE       USB_EPTYPE_INTR
#define SLAB_USB_EP3OUT_MAX_PACKET_SIZE     EP3_OUT_SIZE

/// @brief Total number of USB endpoints used by the device
#define SLAB_USB_NUM_EPS_USED    (SLAB_USB_EP1IN_USED   \
                                  + SLAB_USB_EP1OUT_USED \
                                  + SLAB_USB_EP2IN_USED  \
                                  + SLAB_USB_EP2OUT_USED \
                                  + SLAB_USB_EP3IN_USED  \
                                  + SLAB_USB_EP3OUT_USED \
                                  + 1)

#define SLAB_USB_SETUP_CMD_CB 1
#define SLAB_USB_SOF_CB 0

#define SLAB_USB_NUM_LANGUAGES 1

#define SLAB_USB_LANGUAGE HID_LANG_ID(HID_LANG_ENGLISH, HID_SUBLANG_ENGLISH_US)

#define SLAB_USB_NUM_INTERFACES 1
