
#define DEFAULT_DEBOUNCE_PRESS_TIME 5
#define DEFAULT_DEBOUNCE_RELEASE_TIME (2*DEFAULT_DEBOUNCE_PRESS_TIME)
#define DEFAULT_RELEASE_TRIGGER_TIME 3
#define DEFAULT_PRESS_TRIGGER_TIME 1
#define DEFAULT_PARASITIC_DISCHARGE_DELAY_PRESS 1
#define DEFAULT_PARASITIC_DISCHARGE_DELAY_DEBOUNCE 10

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
#elif DEVICE_ID == 10
.device_name = "xmega test board - left",
#elif DEVICE_ID == 11
.device_name = "xmega test board - right",
#elif DEVICE_ID == 0x30
.device_name = "nRF24LU1+ dongle - 1",
#endif

#ifdef NO_MATRIX
.scan_plan = {
    .mode = MATRIX_SCANNER_MODE_NO_MATRIX, // dongle
    .rows = 0,
    .cols = 0,
},
#else
.scan_plan = {
    .mode = CONFIG_MATRIX_SCAN_MODE,
    .rows = CONFIG_MATRIX_ROW_COUNT,
    .cols = CONFIG_MATRIX_COL_COUNT,
    .debounce_time_press               = DEFAULT_DEBOUNCE_PRESS_TIME,
    .debounce_time_release             = DEFAULT_DEBOUNCE_RELEASE_TIME,
    .trigger_time_press                 = DEFAULT_PRESS_TRIGGER_TIME,
    .trigger_time_release               = DEFAULT_RELEASE_TRIGGER_TIME,
    .parasitic_discharge_delay_idle       = DEFAULT_PARASITIC_DISCHARGE_DELAY_PRESS,
    .parasitic_discharge_delay_debouncing = DEFAULT_PARASITIC_DISCHARGE_DELAY_DEBOUNCE,
},
#endif
