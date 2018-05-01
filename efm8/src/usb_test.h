// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include "usbconfig.h"

#include <stdint.h>

#include "si_toolchain.h"
#include "compiler_defs.h"

#include "core/util.h"

#include "usb/util/usb_hid.h"

#define MEM_MODEL_SEG XRAM

#if SLAB_USB_POLLED_MODE
#define DISABLE_USB_INTS  {}
#define ENABLE_USB_INTS   {}

#else
/// Saves the current state of the USB Interrupt Enable to a variable called
/// usbIntsEnabled, then disables USB interrupts.
#define DISABLE_USB_INTS  { usbIntsEnabled = USB_GetIntsEnabled(); USB_DisableInts(); }

/// Sets the USB Interrupt Enable bit to the value of usbIntsEnabled.
/// @ref DISABLE_USB_INTS must be used before this macro is used.
#define ENABLE_USB_INTS   { if (usbIntsEnabled) {USB_EnableInts(); } }
#endif  // SLAB_USB_POLLED_MODE

#define SLAB_ASSERT(x)

/// Macro for getting minimum value.
#ifndef EFM8_MIN
#define EFM8_MIN(a, b)    ((a) < (b) ? (a) : (b))
#endif

/// Macro for getting maximum value.
#ifndef EFM8_MAX
#define EFM8_MAX(a, b)    ((a) > (b) ? (a) : (b))
#endif

#ifndef UNREFERENCED_ARGUMENT
#if defined __C51__
/// Macro for removing unreferenced arguments from compiler warnings
#define UNREFERENCED_ARGUMENT(arg) (0, arg)
#elif defined __ICC8051__
/// Macro for removing unreferenced arguments from compiler warnings
#define UNREFERENCED_ARGUMENT(arg) ((void)arg)
#elif defined __SDCC
#define UNREFERENCED_ARGUMENT(arg) ((void)arg)
#endif
#endif

#define USB_EPTYPE_CTRL                   0       ///< Endpoint type control.
#define USB_EPTYPE_ISOC                   1       ///< Endpoint type isochronous.
#define USB_EPTYPE_BULK                   2       ///< Endpoint type bulk.
#define USB_EPTYPE_INTR                   3       ///< Endpoint type interrupt.

#define htole16(x) (x)

#define EP0_FIFO_NUM 0

// -----------------------------------------------------------------------------
// Typedefs

/// @brief USB transfer status enumerator.
typedef enum {
  USB_STATUS_OK = 0,                            ///< No errors detected.
  USB_STATUS_REQ_ERR = 1,                      ///< Setup request error.
  USB_STATUS_EP_BUSY = 2,                      ///< Endpoint is busy.
  USB_STATUS_REQ_UNHANDLED = 3,                ///< Setup request not handled.
  USB_STATUS_ILLEGAL = 4,                      ///< Illegal operation attempted.
  USB_STATUS_EP_STALLED = 5,                   ///< Endpoint is stalled.
  USB_STATUS_EP_ABORTED = 6,                   ///< Endpoint transfer was aborted.
  USB_STATUS_EP_ERROR = 7,                     ///< Endpoint transfer error.
  USB_STATUS_EP_NAK = 8,                       ///< Endpoint NAK'ed transfer request.
  USB_STATUS_DEVICE_UNCONFIGURED = 9,          ///< Device is unconfigured.
  USB_STATUS_DEVICE_SUSPENDED = 10,            ///< Device is suspended.
  USB_STATUS_DEVICE_RESET = 11,                ///< Device is/was reset.
  USB_STATUS_TIMEOUT = 12,                     ///< Transfer timeout.
  USB_STATUS_DEVICE_REMOVED = 13,              ///< Device was removed.
  USB_STATUS_EP_RX_BUFFER_OVERRUN = 14,        ///< Not enough data in the Rx buffer to hold the
  USB_STATUS_DATA_ERROR = 15,                  ///< OUT packet had CRC or bit-stuffing error
                                                ///< last received packet
} USB_Status_TypeDef_Values;

typedef int_fast8_t USB_Status_TypeDef;

/// @brief USB device state enumerator.
typedef enum {
  USBD_STATE_NONE = 0,               ///< Device state is undefined/unknown.
  USBD_STATE_ATTACHED = 1,           ///< Device state is ATTACHED.
  USBD_STATE_POWERED = 2,            ///< Device state is POWERED.
  USBD_STATE_DEFAULT = 3,            ///< Device state is DEFAULT.
  USBD_STATE_ADDRESSED = 4,          ///< Device state is ADDRESSED.
  USBD_STATE_SUSPENDED = 5,          ///< Device state is SUSPENDED.
  USBD_STATE_CONFIGURED = 6,         ///< Device state is CONFIGURED.
  USBD_STATE_LASTMARKER = 7,         ///< Device state enum end marker.
} USBD_State_TypeDef;

/// @cond DO_NOT_INCLUDE_WITH_DOXYGEN
/// @brief Endpoint states
typedef enum {
  D_EP_DISABLED = 0,                 ///< Endpoint is disabled
  D_EP_IDLE = 1,                     ///< Endpoint is idle
  D_EP_TRANSMITTING = 2,             ///< Endpoint is transmitting data
  D_EP_RECEIVING = 3,                ///< Endpoint is receiving data
  D_EP_STATUS = 4,                   ///< Endpoint is in status stage
  D_EP_STALL = 5,                    ///< Endpoint is stalling
  D_EP_HALT = 6,                     ///< Endpoint is halted
  D_EP_LASTMARKER = 7                ///< End of EpState enum
} USBD_EpState_TypeDef;
/// @endcond DO_NOT_INCLUDE_WITH_DOXYGEN

typedef enum {
  EP0,
#if (SLAB_USB_EP1IN_USED)
  EP1IN,
#endif
#if (SLAB_USB_EP2IN_USED)
  EP2IN,
#endif
#if (SLAB_USB_EP3IN_USED)
  EP3IN,
#endif
#if (SLAB_USB_EP1OUT_USED)
  EP1OUT,
#endif
#if (SLAB_USB_EP2OUT_USED)
  EP2OUT,
#endif
#if (SLAB_USB_EP3OUT_USED)
  EP3OUT,
#endif
} USB_EP_Index_TypeDef;

typedef struct {
    uint8_t *buf;
    uint16_t remaining;
    USBD_EpState_TypeDef state;
    union {
        struct {
            uint8_t callback         : 1;
            uint8_t outPacketPending : 1;
            uint8_t inPacketPending  : 1;
            uint8_t waitForRead      : 1;
        } bits;
        uint8_t c;
    } misc;
} USBD_Ep_TypeDef;

/// @brief USB Setup type.
typedef struct {
    struct {
        uint8_t Recipient : 5;           ///< Request recipient (device, interface, endpoint, other)
        uint8_t Type : 2;                ///< Request type (standard, class or vendor).
        uint8_t Direction : 1;           ///< Transfer direction of SETUP data phase.
    } bmRequestType;

    uint8_t bRequest;
    uint16_t wValue;
    uint16_t wIndex;
    uint16_t wLength;
} USB_Setup_TypeDef;

typedef union {
  struct {
      uint8_t type : 7;
      uint8_t init : 1;
  } encoding;
  uint8_t c;
} ep0String_type;

typedef uint8_t KeyReport_TypeDef[8];

uint8_t usb_init(void);

void USBD_SetUsbState(USBD_State_TypeDef newState);
void USBD_SofCb(uint16_t sofNr);

USB_Status_TypeDef USBD_SetupCmdCb(XRAM USB_Setup_TypeDef *setup);
int8_t USBD_Write(uint8_t epAddr, void *dat, uint16_t byteCount, bool callback);
int8_t USBD_Read(uint8_t epAddr, void *dat, uint16_t byteCount, bool callback);
bool USBD_EpIsBusy(uint8_t epAddr);
