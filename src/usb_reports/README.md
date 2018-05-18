@dir src/usb_reports
@brief Provides a hardware abstraction layer between the USB endpoints and the HID reports.

# Overview of code layout

The mcu ports should implement the functions in `usb_reports/usb_reports.h`.
The rest of the code in this module, uses that interface to provide the various
USB functions

| module | function |
|--------|----------|
| `usb_reports/usb_reports.h` | USB abstraction layer |
| `usb_reports/keyboard_report.c` | Implements 6KRO and NKRO USB reports |
| `usb_reports/media_report.c` | Implements HID media controls|
| `usb_reports/mouse_report.c` | Implements HID mouse |
| `usb_reports/vendor_report.c` | Implements a RAW HID report for sending arbitrary data to and from the host |
