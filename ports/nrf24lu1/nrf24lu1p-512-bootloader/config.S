; For devices with version HI == 0x20, will copy the Nordic protocol with
; some add features (reset cmd, raw HID descriptor)
; value returned by version cmd
BOOTLOADER_VERSION_HI = 0x20
BOOTLOADER_VERSION_LO = 0x00

; usb vendor id bytes
USB_VID_HI = 0x12
USB_VID_LO = 0x09

; usb product id bytes
USB_PID_HI = 0xBB
USB_PID_LO = 0x03

; CMD_NONE        = 0x00
CMD_VERSION        = 0x01
CMD_WRITE_INIT     = 0x02
CMD_READ_FLASH     = 0x03
CMD_ERASE_PAGE     = 0x04
CMD_READ_DISABLE   = 0x05
CMD_SELECT_FLASH   = 0x06
CMD_RESET          = 0x07
