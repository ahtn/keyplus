ifndef MCU
  MCU=atxmega32a4u
endif

CDEFS += -DCHECK_PIN=PIN1_bm
CDEFS += -DCHECK_PORT=PORTR
