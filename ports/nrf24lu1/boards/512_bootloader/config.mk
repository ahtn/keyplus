
# Generic nRF24LU1+ dongle
SETTINGS_ADDR=0x6E00
LAYOUT_ADDR=0x7000
LAYOUT_SIZE=0x0C00
NONCE_ADDR=0x7C00
BOOTLOADER_ADDR=0x7E00

# Use default settings for the other values. (see ./hardware_user_impl.h)
CDEFS += -DUSE_UNIFYING_BOOTLOADER=0

BOOTLOADER=bins/nrf24lu1_bootloader-f32.hex

USE_MOUSE_GESTURE = 0

ifeq ($(FLASH_SIZE), 16)
	BOOTLOADER=bins/nrf24lu1_bootloader-f16.hex
	CODE_SIZE=0x4000
	$(error "Curent build needs 32kb flash")
else ifeq ($(FLASH_SIZE), 32)
	BOOTLOADER=bins/nrf24lu1_bootloader-f32.hex
	CODE_SIZE=0x8000
else
	$(error Invalid size for flash='$(FLASH_SIZE)')
endif
