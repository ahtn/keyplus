ifndef MCU
    MCU = atxmega32a4u
endif

CDEFS += -DCHECK_PORT=PORTE
CDEFS += -DCHECK_PIN=PIN2_bm
