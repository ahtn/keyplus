bit_t send_media_report(void) {
    if (is_ready_media_report() && g_report_pending_media) {
        const uint8_t report_size = sizeof(hid_report_media_t);

        usb_write_endpoint_in_data(
            EP_NUM_MEDIA,
            (uint8_t*)&g_media_report,
            report_size
        );

        g_report_pending_media = false;
        return false;
    } else {
        return true;
    }
}
