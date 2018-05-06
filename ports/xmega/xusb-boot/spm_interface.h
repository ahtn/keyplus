// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <avr/io.h>
#include <stdint.h>

#define SPM_INTERFACE_TABLE_ENTRIES 24

#if BOOT_SECTION_SIZE <= 0x1000
#define SPM_INTERFACE_TABLE_ENTRIE_SIZE 2
#define SPM_FN_TABLE_SIZE (SPM_INTERFACE_TABLE_ENTRIES * SPM_INTERFACE_TABLE_ENTRIE_SIZE)
#else
#define SPM_INTERFACE_TABLE_ENTRIE_SIZE 4
#define SPM_FN_TABLE_SIZE (SPM_INTERFACE_TABLE_ENTRIES * SPM_INTERFACE_TABLE_ENTRIE_SIZE)
#endif


// How to use the spm interface functions in C from the application section.
// Example for ATxmega32a4u

#define BYTE_TO_WORD_ADDR(x) ((x) / 2)
#define SPM_FN_TABLE_BYTE_ADDR (BOOT_SECTION_END - (SPM_FN_TABLE_SIZE - 1))
#define SPM_FN_TABLE_ADDR (BYTE_TO_WORD_ADDR(SPM_FN_TABLE_BYTE_ADDR))

#if BOOT_SECTION_SIZE <= 0x1000
// Small boot section (e.g.ATxmega32a4u, 0x1000 == 4kb)
// Can access with rjmp (reaches +- 2k words from call)
#define SPM_JMP_SIZE 1
#else
// Large bootsection (e.g. ATxmega128a4u, 0x2000 == 8kb)
// Access with jmp (reaches 4M word program space)
#define SPM_JMP_SIZE 2
#endif

#define SPM_FN_ADDR(fn_pos) (SPM_FN_TABLE_ADDR + ((fn_pos) * SPM_JMP_SIZE))

// The word addresses of the functions
#define SPM_ERASE_ADDR                     SPM_FN_ADDR(0)
#define SPM_WRITE_ADDR                     SPM_FN_ADDR(1)
#define SP_READCALIBRATIONBYTE_ADDR        SPM_FN_ADDR(2)
#define SP_READFUSEBYTE_ADDR               SPM_FN_ADDR(3)
#define SP_WRITELOCKBITS_ADDR              SPM_FN_ADDR(4)
#define SP_READLOCKBITS_ADDR               SPM_FN_ADDR(5)
#define SP_READUSERSIGNATUREBYTE_ADDR      SPM_FN_ADDR(6)
#define SP_ERASEUSERSIGNATUREROW_ADDR      SPM_FN_ADDR(7)
#define SP_WRITEUSERSIGNATUREROW_ADDR      SPM_FN_ADDR(8)
#define SP_ERASEAPPLICATIONPAGE_ADDR       SPM_FN_ADDR(9)
#define SP_ERASEWRITEAPPLICATIONPAGE_ADDR  SPM_FN_ADDR(10)
#define SP_WRITEAPPLICATIONPAGE_ADDR       SPM_FN_ADDR(11)
#define SP_LOADFLASHWORD_ADDR              SPM_FN_ADDR(12)
#define SP_LOADFLASHPAGE_ADDR              SPM_FN_ADDR(13)
#define SP_READFLASHPAGE_ADDR              SPM_FN_ADDR(14)
#define SP_ERASEFLASHBUFFER_ADDR           SPM_FN_ADDR(15)
#define SP_APPLICATIONCRC_ADDR             SPM_FN_ADDR(16)
#define SP_BOOTCRC_ADDR                    SPM_FN_ADDR(17)
#define SP_LOCKSPM_ADDR                    SPM_FN_ADDR(18)
#define SP_WAITFORSPM_ADDR                 SPM_FN_ADDR(19)


// call from application section

#if BOOT_SECTION_START < 0x20000

// This function erases the given flash page. The byte address may point anywhere
// inside the flash page.
// Note: This function is equivalent to calling `SP_EraseApplicationPage()` and
// `SP_WaitForSPM()`
#define SPM_flash_erase_page       ((void (*)(uint32_t addr))(SPM_ERASE_ADDR))

// This writes a flash page to the given byte address.
#define SPM_flash_write_page       ((void (*)(uint8_t* data, uint32_t addr))(SPM_WRITE_ADDR))

// The following functions are the same as those found in the ATMEL
// self-programming driver. See `sp_driver_h` for more information.
#define SP_ReadCalibrationByte       ((uint8_t (*)(uint8_t index))SP_READCALIBRATIONBYTE_ADDR)

#define SP_ReadFuseByte              ((uint8_t (*)(uint8_t index))SP_READFUSEBYTE_ADDR)

#define SP_WriteLockBits             ((void (*)(uint8_t data))SP_WRITELOCKBITS_ADDR)

#define SP_ReadLockBits              ((uint8_t (*)(void))SP_READLOCKBITS_ADDR)

#define SP_ReadUserSignatureByte     ((uint8_t (*)(uint16_t index))SP_READUSERSIGNATUREBYTE_ADDR)

#define SP_EraseUserSignatureRow     ((void (*)(void))SP_ERASEUSERSIGNATUREROW_ADDR)

#define SP_WriteUserSignatureRow     ((void (*)(void))SP_WRITEUSERSIGNATUREROW_ADDR)

#define SP_EraseApplicationPage      ((void (*)(uint32_t addr))SP_ERASEAPPLICATIONPAGE_ADDR)

#define SP_EraseWriteApplicationPage ((void (*)(uint32_t addr))SP_ERASEWRITEAPPLICATIONPAGE_ADDR)

#define SP_WriteApplicationPage      ((void (*)(uint32_t addr))SP_WRITEAPPLICATIONPAGE_ADDR)

#define SP_LoadFlashWord             ((void (*)(uint16_t addr, uint16_t data))SP_LOADFLASHWORD_ADDR)

#define SP_LoadFlashPage             ((void (*)(const uint8_t* data))SP_LOADFLASHPAGE_ADDR)

#define SP_ReadFlashPage             ((void (*)(const uint8_t* data, uint32_t addr))SP_READFLASHPAGE_ADDR)

#define SP_EraseFlashBuffer          ((void (*)(void))SP_ERASEFLASHBUFFER_ADDR)

#define SP_ApplicationCRC            ((uint32_t (*)(void))SP_APPLICATIONCRC_ADDR)

#define SP_BootCRC                   ((uint32_t (*)(void))SP_BOOTCRC_ADDR)

#define SP_LockSPM                   ((void (*)(void))SP_LOCKSPM_ADDR)

#define SP_WaitForSPM                ((void (*)(void))SP_WAITFORSPM_ADDR)

#elif BOOT_SECTION_START >= 0x20000

// NOTE: Since the AVR uses word address, it is possible to reach upto 128kb
// with normal call instructions. But to go beyond that need to use EICALL.

// TODO: not sure if there is a less repetitive approach to achieve this.

#include <util/atomic.h>

#if 0
#define SPM_flash_erase_page(addr) ATOMIC_BLOCK(ATOMIC_RESTORESTATE) { \
    EIND = SPM_ERASE_ADDR >> 16; \
    ((void (*)(uint32_t addr_))(SPM_ERASE_ADDR))(addr); \
    EIND = 0; \
}

// This writes a flash page to the given byte address.
#define SPM_flash_write_page(data, addr) ATOMIC_BLOCK(ATOMIC_RESTORESTATE) { \
    EIND = SPM_WRITE_ADDR >> 16; \
    ((void (*)(uint8_t* data_, uint32_t addr_))(SPM_WRITE_ADDR))(data, addr); \
    EIND = 0; \
}
#endif

// The following functions are the same as those found in the ATMEL
// self-programming driver. See `sp_driver_h` for more information.
#define SP_ReadCalibrationByte(index) ATOMIC_BLOCK(ATOMIC_RESTORESTATE) { \
    EIND = SP_READCALIBRATIONBYTE_ADDR >> 16; \
    ((uint8_t (*)(uint8_t index_))SP_READCALIBRATIONBYTE_ADDR)(index); \
    EIND = 0; \
}

#define SP_ReadFuseByte(index) ATOMIC_BLOCK(ATOMIC_RESTORESTATE) { \
    EIND = SP_READFUSEBYTE_ADDR >> 16; \
    ((uint8_t (*)(uint8_t index_))SP_READFUSEBYTE_ADDR)(index); \
    EIND = 0; \
}

#define SP_WriteLockBits(data) ATOMIC_BLOCK(ATOMIC_RESTORESTATE) { \
    EIND = SP_WRITELOCKBITS_ADDR >> 16; \
    ((void (*)(uint8_t data_))SP_WRITELOCKBITS_ADDR)(data); \
    EIND = 0; \
}

#define SP_ReadLockBits() ATOMIC_BLOCK(ATOMIC_RESTORESTATE) { \
    EIND = SP_READLOCKBITS_ADDR >> 16; \
    ((uint8_t (*)(void))SP_READLOCKBITS_ADDR)(); \
    EIND = 0; \
}

#define SP_ReadUserSignatureByte(index) ATOMIC_BLOCK(ATOMIC_RESTORESTATE) { \
    EIND = SP_READUSERSIGNATUREBYTE_ADDR >> 16; \
    ((uint8_t (*)(uint16_t index_))SP_READUSERSIGNATUREBYTE_ADDR)(index); \
    EIND = 0; \
}

#define SP_EraseUserSignatureRow() ATOMIC_BLOCK(ATOMIC_RESTORESTATE) { \
    EIND = SP_ERASEUSERSIGNATUREROW_ADDR >> 16; \
    ((void (*)(void))SP_ERASEUSERSIGNATUREROW_ADDR)(); \
    EIND = 0; \
}

#define SP_WriteUserSignatureRow() ATOMIC_BLOCK(ATOMIC_RESTORESTATE) { \
    EIND = SP_WRITEUSERSIGNATUREROW_ADDR >> 16; \
    ((void (*)(void))SP_WRITEUSERSIGNATUREROW_ADDR)(); \
    EIND = 0; \
}

#define SP_EraseApplicationPage(addr) ATOMIC_BLOCK(ATOMIC_RESTORESTATE) { \
    EIND = SP_ERASEAPPLICATIONPAGE_ADDR >> 16; \
    ((void (*)(uint32_t addr_))SP_ERASEAPPLICATIONPAGE_ADDR)(addr); \
    EIND = 0; \
}

#define SP_EraseWriteApplicationPage(addr) ATOMIC_BLOCK(ATOMIC_RESTORESTATE) { \
    EIND = SP_ERASEWRITEAPPLICATIONPAGE_ADDR >> 16; \
    ((void (*)(uint32_t addr_))SP_ERASEWRITEAPPLICATIONPAGE_ADDR)(addr); \
    EIND = 0; \
}

#define SP_WriteApplicationPage(addr) ATOMIC_BLOCK(ATOMIC_RESTORESTATE) { \
    EIND = SP_WRITEAPPLICATIONPAGE_ADDR >> 16; \
    ((void (*)(uint32_t addr_))SP_WRITEAPPLICATIONPAGE_ADDR)(addr); \
    EIND = 0; \
}

#define SP_LoadFlashWord(addr, data) ATOMIC_BLOCK(ATOMIC_RESTORESTATE) { \
    EIND = SP_LOADFLASHWORD_ADDR >> 16; \
    ((void (*)(uint16_t addr_, uint16_t data_))SP_LOADFLASHWORD_ADDR)(addr, data); \
    EIND = 0; \
}

#define SP_LoadFlashPage(data) ATOMIC_BLOCK(ATOMIC_RESTORESTATE) { \
    EIND = SP_LOADFLASHPAGE_ADDR >> 16; \
    ((void (*)(const uint8_t* data_))SP_LOADFLASHPAGE_ADDR)(data); \
    EIND = 0; \
}

#define SP_ReadFlashPage(data, addr) ATOMIC_BLOCK(ATOMIC_RESTORESTATE) { \
    EIND = SP_READFLASHPAGE_ADDR >> 16; \
    ((void (*)(const uint8_t* data_, uint32_t addr_))SP_READFLASHPAGE_ADDR)(data, addr); \
    EIND = 0; \
}

#define SP_EraseFlashBuffer() ATOMIC_BLOCK(ATOMIC_RESTORESTATE) { \
    EIND = SP_ERASEFLASHBUFFER_ADDR >> 16; \
    ((void (*)(void))SP_ERASEFLASHBUFFER_ADDR)(); \
    EIND = 0; \
}

#if 0
#define SP_ApplicationCRC() ATOMIC_BLOCK(ATOMIC_RESTORESTATE) { \
    EIND = SP_APPLICATIONCRC_ADDR >> 16; \
    ((uint32_t (*)(void))SP_APPLICATIONCRC_ADDR)(); \
    EIND = 0; \
}

#define SP_BootCRC() ATOMIC_BLOCK(ATOMIC_RESTORESTATE) { \
    EIND = SP_BOOTCRC_ADDR >> 16; \
    ((uint32_t (*)(void))SP_BOOTCRC_ADDR)(); \
    EIND = 0; \
}
#else
// #error "Currently SP_ApplicationCRC and SP_BootCRC are not supported in 128kb flash devices"
#endif

#define SP_LockSPM() ATOMIC_BLOCK(ATOMIC_RESTORESTATE) { \
    EIND = SP_LOCKSPM_ADDR >> 16; \
    ((void (*)(void))SP_LOCKSPM_ADDR)(); \
    EIND = 0; \
}

#define SP_WaitForSPM() ATOMIC_BLOCK(ATOMIC_RESTORESTATE) { \
    EIND = SP_WAITFORSPM_ADDR >> 16; \
    ((void (*)(void))SP_WAITFORSPM_ADDR)(); \
    EIND = 0; \
}

#endif
