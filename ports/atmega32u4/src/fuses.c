// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include <stdint.h>
#include <avr/io.h>

#define LFUSE (\
    FUSE_CKDIV8 & FUSE_SUT1 & FUSE_CKSEL0 \
)
#define HFUSE (\
    FUSE_SPIEN & FUSE_BOOTSZ1 & FUSE_BOOTSZ0 \
)
// FUSE_SPIEN & FUSE_BOOTSZ1 & FUSE_BOOTSZ0 & FUSE_BOOTRST

#define EFUSE ( \
    FUSE_HWBE & FUSE_BODLEVEL2 \
)

const uint8_t fuses[FUSE_MEMORY_SIZE] __attribute__ ((section (".fuse"))) = {
    [0] = LFUSE,
    [1] = HFUSE,
    [2] = EFUSE,
};

// lock bit options configuration
// NOLOCK: read and write allowed
// WLOCK: write disabled
// RLOCK: read disabled
// RWLOCK: read and write disable
//
// BLBB: boot section
// BLBA: application section
// BLBA: application table section
// LB: external programmer read/write access
#define LOCK_SETTINGS ( \
    NVM_BLBB_WLOCK_gc | \
    NVM_BLBA_NOLOCK_gc | \
    NVM_BLBAT_NOLOCK_gc | \
    NVM_LB_RWLOCK_gc \
)

// LB: external programmer access
#define LB_gp 0
#define LB_NO_LOCK_gc (0b11 << LB_gp)
#define LB_W_LOCK_gc  (0b10 << LB_gp)
#define LB_RW_LOCK_gc (0b00 << LB_gp)
// BLB0: application section
#define BLB0_gp 2
#define BLB0_APP_NO_LOCK_gc (0b11 << BLB0_gp)
#define BLB0_APP_W_LOCK_gc  (0b10 << BLB0_gp)
#define BLB0_APP_R_LOCK     (0b01 << BLB0_gp)
#define BLB0_APP_RW_LOCK_gc (0b00 << BLB0_gp)
// BLB1: bootloader section
#define BLB1_gp 4
#define BLB1_BOOT_NO_LOCK_gc (0b11 << BLB1_gp)
#define BLB1_BOOT_W_LOCK_gc  (0b10 << BLB1_gp)
#define BLB1_BOOT_R_LOCK     (0b01 << BLB1_gp)
#define BLB1_BOOT_RW_LOCK_gc (0b00 << BLB1_gp)

#define UNUSED_LOCK 0xc0

#define LOCK_DEFAULT (\
    LB_RW_LOCK_gc | \
    BLB0_APP_NO_LOCK_gc | \
    BLB1_BOOT_W_LOCK_gc \
)

#define LOCK_DEBUG  (\
    LB_NO_LOCK_gc | \
    BLB0_APP_NO_LOCK_gc | \
    BLB1_BOOT_W_LOCK_gc \
)

const uint8_t lockbits[] __attribute__ ((section (".lock"))) = {
    [0] = LOCK_DEBUG,
};
