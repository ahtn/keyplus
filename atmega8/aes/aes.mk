# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

AES_MIN_SRC = \
	aes/aes-min/aes-decrypt.c \
	aes/aes-min/aes-encrypt.c \
	aes/aes-min/aes-inv.c \
	aes/aes-min/aes-key-schedule.c \
	aes/aes-min/aes-key-schedule-round.c \
	aes/aes-min/aes-mix-columns.c \
	aes/aes-min/aes-mix-columns-inv.c \
	aes/aes-min/aes-mul.c \
	aes/aes-min/aes-shift-rows.c \
	aes/aes-min/aes-shift-rows-inv.c \
	aes/aes-min/aes-sbox.c \
	aes/aes-min/aes-sbox-inv.c \
	# aes/aes-min/aes-sbox-inv-small.c \
	# aes/aes-min/aes-sbox-small.c \


AES_CRYPTO_LIB_ASM_SRC = \
	aes/avr-crypto-lib/aes_aleph_keyschedule-asm.S \
	aes/avr-crypto-lib/aes_invsbox-asm.S \
	aes/avr-crypto-lib/aes_sbox-asm.S \
	aes/avr-crypto-lib/avr-asm-macros.S \
	aes/avr-crypto-lib/aes_enc-asm.S \
	aes/avr-crypto-lib/aes_dec-asm_faster.S \
	# aes/avr-crypto-lib/aes_dec-asm.S \

AES_TINY128_SRC = aes/tiny_aes128/aes.c

ifeq ($(AES_LIB), tiny-aes128)
CDEFS += -DAES_TINY128 -DECB=1 -DCBC=0
C_SRC +=$(AES_TINY128_SRC)
endif

ifeq ($(AES_LIB), avr-crypto-lib)
CDEFS += -DAES_CRYPTO_LIB
ASM_SRC += $(AES_CRYPTO_LIB_ASM_SRC)
endif

ifeq ($(AES_LIB), aes-min)
CDEFS += -DAES_MIN
C_SRC +=$(AES_MIN_SRC)
endif
