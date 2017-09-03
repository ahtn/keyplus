
.default_report_mode = KEYBOARD_REPORT_MODE_AUTO,

#if DEVICE_ID == 0
.device_name = "simple split 40\% - left",
#elif DEVICE_ID == 1
.device_name = "simple split 40\% - right",
#elif DEVICE_ID == 2
.device_name = "simple split 40\% - numpad",
#elif DEVICE_ID == 4
.device_name = "atmega8 - left",
#elif DEVICE_ID == 5
.device_name = "atmega8 - right",
#elif DEVICE_ID == 8
.device_name = "atmega8 - 3d 1 - left",
#elif DEVICE_ID == 9
.device_name = "atmega8 - 3d 2 - right",
#elif DEVICE_ID == 0x30
.device_name = "nRF24LU1+ dongle - 1",
#endif

#ifdef CONFIG_NO_MATRIX
.scan_mode = MATRIX_SCANNER_MODE_NONE, // dongle
.row_count = 0,
.col_count = 0,
#else
.scan_mode = CONFIG_MATRIX_SCAN_MODE,
.row_count = CONFIG_MATRIX_ROW_COUNT,
.col_count = CONFIG_MATRIX_COL_COUNT,
#endif
