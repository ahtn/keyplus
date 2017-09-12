// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include <avr/io.h>
#include <stdint.h>

#define JTAG_UID 0xCC

#ifndef NVM_FUSES_JTAGEN_bm
#define NVM_FUSES_JTAGEN_bm 0x01
#endif

// NOTE: remember that for fuses
// 0 -> enabled
// 1 -> disabled
#define ON 0
#define OFF 1

#define FUSE2_UNUSED 0b10011100
#define FUSE4_UNUSED 0b11100000
#define FUSE5_UNUSED 0b11000000

/*********************************************************************
 *                            fuse bytes                             *
 *********************************************************************/

// BODLEVEL, BODACT (active), BODPD (power down). (at least use sampled mode in
// PD) Continuous mode: 138μA Sampled mode: 1.2μA (uses ULP clock @1.024kHz, so
// sampled every 1ms)

// FUSEBYTE0: JTAGUID
#define FUSEBYTE0 (JTAG_UID)

// FUSEBYTE1: WDWPER ,WDPER
#define FUSEBYTE1 ( \
    WD_8CLK_gc | \
    WDP_8CLK_gc \
)

// FUSEBYTE2: BOOTRST, TOSCSEL, BODPD
#define FUSEBYTE2 ( \
    FUSE2_UNUSED | \
    BOOTRST_BOOTLDR_gc | \
    TOSCSEL_XTAL_gc | \
    BOD_SAMPLED_gc \
)

// FUSEBYTE4: RSTDISBL, STARTUPTIME, WDLOCK, JTAGEN
#define FUSEBYTE4 ( \
    FUSE4_UNUSED | SUT_0MS_gc | \
    (OFF * NVM_FUSES_RSTDISBL_bm) | \
    (OFF * NVM_FUSES_WDLOCK_bm) | \
    (OFF * NVM_FUSES_JTAGEN_bm) \
)

// FUSEBYTE5: BODACT, EESAVE, BODLEVEL
#define FUSEBYTE5 ( \
    FUSE5_UNUSED | \
    BODACT_SAMPLED_gc | \
    (ON * NVM_FUSES_EESAVE_bm) | \
    BODLVL_1V8_gc \
)

/*********************************************************************
 *                             lock bits                             *
 *********************************************************************/

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

const uint8_t fuses[] __attribute__ ((section (".fuse"))) = {
    [0] = FUSEBYTE0,
    [1] = FUSEBYTE1,
    [2] = FUSEBYTE2,
    [3] = 0xff, // FUSEBYTE3:  RESERVED
    [4] = FUSEBYTE4,
    [5] = FUSEBYTE5,
};

const uint8_t lockbits[] __attribute__ ((section (".lock"))) = {
    [0] = LOCK_SETTINGS,
};

const uint8_t usersig[] __attribute__ ((section (".user_signatures"))) = {
};
