@dir src/hid_reports
@brief Provides a hardware abstraction layer between HID reports and the HID
    transport protocol (i.e. USB/BLE)

# Overview of code layout

The mcu ports should implement the functions in `hid_reports/usb_reports.h`.
The rest of the code in this module, uses that interface to provide the various
USB/BLE functions

| module | function |
|--------|----------|
| `hid_reports/usb_reports.h` | USB abstraction layer |
| `hid_reports/keyboard_report.c` | Implements 6KRO and NKRO USB reports |
| `hid_reports/media_report.c` | Implements HID media controls|
| `hid_reports/mouse_report.c` | Implements HID mouse |
| `hid_reports/vendor_report.c` | Implements a RAW HID report for sending arbitrary data to and from the host |
