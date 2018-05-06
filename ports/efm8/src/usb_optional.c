// Copyright (c) 2015 by Silicon Laboratories Inc. All rights reserved.
//
// http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
// With modifications by:
// jem@seethis (c) 2018

/*********************************************************************
 *                             GetStatus                             *
 *********************************************************************/

#if 0
static USB_Status_TypeDef GetStatus(void)
{
  USB_Status_TypeDef retVal = USB_STATUS_REQ_ERR;

  if ((setup.wLength == 2)
      && (setup.wValue == 0)
      && (setup.bmRequestType.Direction == USB_SETUP_DIR_IN)
      && (s_usb_state >= USBD_STATE_ADDRESSED))
  {
    pStatus = htole16(0);         // Default return value is 0x0000

    switch (setup.bmRequestType.Recipient)
    {
      case USB_SETUP_RECIPIENT_DEVICE:
        if (setup.wIndex == 0)
        {
  #if SLAB_USB_REMOTE_WAKEUP_ENABLED
          // Remote wakeup feature status
          if (remoteWakeupEnabled)
          {
            pStatus |= htole16(REMOTE_WAKEUP_ENABLED);
          }
  #endif // SLAB_USB_REMOTE_WAKEUP_ENABLED

  #if SLAB_USB_IS_SELF_POWERED_CB
          // Current self/bus power status
          if (USBD_IsSelfPoweredCb())
          {
            pStatus |= htole16(DEVICE_IS_SELFPOWERED);
          }
  #elif (SLAB_USB_BUS_POWERED == 0)
          pStatus |= htole16(DEVICE_IS_SELFPOWERED);
  #endif // SLAB_USB_IS_SELF_POWERED_CB

          retVal = USB_STATUS_OK;
        }
        break;

      case USB_SETUP_RECIPIENT_INTERFACE:
        if (setup.wIndex < SLAB_USB_NUM_INTERFACES)
        {
          retVal = USB_STATUS_OK;
        }
        break;


      case USB_SETUP_RECIPIENT_ENDPOINT:
        // Device does not support halting endpoint 0, but do not give
        // an error as this is a valid request
        if (((setup.wIndex & ~USB_EP_DIR_IN) == 0)
            && (s_usb_state == USBD_STATE_ADDRESSED))
        {
          retVal = USB_STATUS_OK;
        }
        else if (s_usb_state == USBD_STATE_CONFIGURED)
        {
          switch (setup.wIndex & 0xFF)
          {
  #if SLAB_USB_EP1OUT_USED
            case (USB_EP_DIR_OUT | 1):
              if (ep1out.state == D_EP_HALT)
              {
                pStatus = htole16(1);
              }
              retVal = USB_STATUS_OK;
              break;
  #endif
  #if SLAB_USB_EP2OUT_USED
            case (USB_EP_DIR_OUT | 2):
              if (ep2out.state == D_EP_HALT)
              {
                pStatus = htole16(1);
              }
              retVal = USB_STATUS_OK;
              break;
  #endif
  #if SLAB_USB_EP3OUT_USED
            case (USB_EP_DIR_OUT | 3):
              if (ep3out.state == D_EP_HALT)
              {
                pStatus = htole16(1);
              }
              retVal = USB_STATUS_OK;
              break;
  #endif
  #if SLAB_USB_EP1IN_USED
            case (USB_EP_DIR_IN | 1):
              if (ep1in.state == D_EP_HALT)
              {
                pStatus = htole16(1);
              }
              retVal = USB_STATUS_OK;
              break;
  #endif
  #if SLAB_USB_EP2IN_USED
            case (USB_EP_DIR_IN | 2):
              if (ep2in.state == D_EP_HALT)
              {
                pStatus = htole16(1);
              }
              retVal = USB_STATUS_OK;
              break;
  #endif
  #if SLAB_USB_EP3IN_USED
            case (USB_EP_DIR_IN | 3):
              if (ep3in.state == D_EP_HALT)
              {
                pStatus = htole16(1);
              }
              retVal = USB_STATUS_OK;
              break;
  #endif
          }
        }
        break;
    }

    // If the command was valid, send the requested status.
    if (retVal == USB_STATUS_OK)
    {
      EP0_Write((SI_VARIABLE_SEGMENT_POINTER(, uint8_t, SI_SEG_GENERIC))&pStatus, 2);
    }
  }

  return retVal;
}
#endif

/*********************************************************************
 *                           ClearFeature                            *
 *********************************************************************/

#if 0
static USB_Status_TypeDef ClearFeature(void)
{
  USB_Status_TypeDef retVal = USB_STATUS_REQ_ERR;

  if (setup.wLength == 0)
  {
    switch (setup.bmRequestType.Recipient)
    {
  #if SLAB_USB_REMOTE_WAKEUP_ENABLED
      case USB_SETUP_RECIPIENT_DEVICE:
        if ((setup.wIndex == 0)
            && (setup.wValue == USB_FEATURE_DEVICE_REMOTE_WAKEUP)
            && (s_usb_state >= USBD_STATE_ADDRESSED))
        {
          // Remote wakeup feature clear
          remoteWakeupEnabled = false;
          retVal = USB_STATUS_OK;
        }
        break;
  #endif // SLAB_USB_REMOTE_WAKEUP_ENABLED
      case USB_SETUP_RECIPIENT_ENDPOINT:
        if (setup.wValue == USB_FEATURE_ENDPOINT_HALT)
        {
          // Device does not support halting endpoint 0, but do not return
          // an error as this is a valid request
          if (((setup.wIndex & ~USB_EP_DIR_IN) == 0)
              && (s_usb_state >= USBD_STATE_ADDRESSED))
          {
            retVal = USB_STATUS_OK;
          }
          else if (((setup.wIndex & ~USB_SETUP_DIR_D2H) < SLAB_USB_NUM_EPS_USED)
                   && (s_usb_state == USBD_STATE_CONFIGURED))
          {
            retVal = USB_STATUS_OK;
            USB_SetIndex((setup.wIndex & 0xFF) & ~USB_SETUP_DIR_D2H);

#if (SLAB_USB_EP1IN_USED || SLAB_USB_EP2IN_USED || SLAB_USB_EP3IN_USED)
            if ((setup.wIndex & 0xFF) & USB_EP_DIR_IN)
            {
              USB_EpnInEndStallAndClearDataToggle();
            }
#endif
#if (SLAB_USB_EP1OUT_USED || SLAB_USB_EP2OUT_USED || SLAB_USB_EP3OUT_USED)
            if (((setup.wIndex & 0xFF) & USB_EP_DIR_IN) == 0)
            {
              USB_EpnOutEndStallAndClearDataToggle();
            }
#endif

            switch (setup.wIndex & 0xFF)
            {
#if SLAB_USB_EP1OUT_USED
              case (USB_EP_DIR_OUT | 1):
                if (ep1out.state != D_EP_RECEIVING)
                {
                  ep1out.state = D_EP_IDLE;
                }
                break;
#endif
#if SLAB_USB_EP2OUT_USED
              case (USB_EP_DIR_OUT | 2):
                if (ep2out.state != D_EP_RECEIVING)
                {
                  ep2out.state = D_EP_IDLE;
                }
                break;
#endif
#if SLAB_USB_EP3OUT_USED
              case (USB_EP_DIR_OUT | 3):
                if (ep3out.state != D_EP_RECEIVING)
                {
                  ep3out.state = D_EP_IDLE;
                }
                break;
#endif
#if SLAB_USB_EP1IN_USED
              case (USB_EP_DIR_IN | 1):
                if (ep1in.state != D_EP_TRANSMITTING)
                {
                  ep1in.state = D_EP_IDLE;
                }
                break;
#endif
#if SLAB_USB_EP2IN_USED
              case (USB_EP_DIR_IN | 2):
                if (ep2in.state != D_EP_TRANSMITTING)
                {
                  ep2in.state = D_EP_IDLE;
                }
                break;
#endif
#if SLAB_USB_EP3IN_USED
              case (USB_EP_DIR_IN | 3):
                if (ep3in.state != D_EP_TRANSMITTING)
                {
                  ep3in.state = D_EP_IDLE;
                }
                break;
#endif
            }
          }
        }
    }
  }
  return retVal;
}
#endif

#if 0
bool USBD_EpIsBusy(uint8_t epAddr) {
    SI_VARIABLE_SEGMENT_POINTER(ep, USBD_Ep_TypeDef, MEM_MODEL_SEG);

    // Verify this is a valid endpoint address
    if (epAddr >= SLAB_USB_NUM_EPS_USED)
    {
        SLAB_ASSERT(false);
        return true;
    }

    ep = GetEp(epAddr);

    if (ep->state == D_EP_IDLE)
    {
        return false;
    }

    return true;
}
#endif

