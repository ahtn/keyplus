ifndef LAYOUT_FILE
    LAYOUT_FILE=$(KEYPLUS_PATH)/../layouts/nrf52_dk.yaml
endif

MCU = nrf52840
MCU_STRING = nRF52840_QIAA
NRF52_LINK_SCRIPT := $(BOARD_DIR)/$(BOARD)/keyplus_gcc_nrf52840.ld

