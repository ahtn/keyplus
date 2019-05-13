// Copyright 2019 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "hid_reports/usb_reports.h"

#include "usb/util/descriptor_defs.h"

#include "nrf_drv_usbd.h"


/// Checks if a USB IN endpoint is ready to take more data
bit_t is_in_endpoint_ready(uint8_t endpoint_num) {
    return !nrf_drv_usbd_ep_is_busy(USB_DIR_IN | endpoint_num);
}

/// Checks if a USB OUT endpoint has data
bit_t is_out_endpoint_ready(uint8_t endpoint_num) {
    return !nrf_drv_usbd_ep_is_busy(USB_DIR_OUT | endpoint_num);
}


/// Write to a USB IN endpoint
void usb_write_in_endpoint(
    uint8_t endpoint_num,
    const XRAM uint8_t *data,
    uint8_t length
) {
    const uint8_t ep = USB_DIR_IN | endpoint_num;

    nrf_drv_usbd_transfer_t transfer = {0};
    // TODO: the data may need to be copied to a secondary buffer first?
    transfer.p_data.tx = data;
    transfer.size = length;
    nrf_drv_usbd_ep_transfer(ep, &transfer);
}

/// Read from a USB OUT endpoint
void usb_read_out_endpoint(
    uint8_t endpoint_num,
    XRAM uint8_t *dest,
    uint8_t *length
) {
    const uint8_t ep = USB_DIR_OUT | endpoint_num;

    *length = nrf_drv_usbd_epout_size_get(ep);
    NRF_DRV_USBD_TRANSFER_OUT(transfer, dest, *length);

    nrf_drv_usbd_ep_transfer(ep, &transfer);
}

