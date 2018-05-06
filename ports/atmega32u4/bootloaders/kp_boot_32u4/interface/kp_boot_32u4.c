// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)
/// @file

#include "kp_boot_32u4.h"

/// Interface to the SPM instruction in the bootloader section.
///
/// Parameters:
/// * addr: address which the SPM instruction operates on (Z register)
/// * spmCmd: SPM command to perform (valued loaded into SPMCSR)
/// * spmCmd2: After performing the first SPM operation, this value will be
///     loaded into the SPMCSR register.  Erase and write operations disable
///     reading from the application section (technically RWW section), so
///     this value can be used to re-enable reading from the RWW section
///     after performing the first SPM command. So this value should
///     be set to `(1<<SPMEN)|(1<<RWWSRE)` to re-enable reading from flash.
/// * optValue: the data value for the SPM instruction (r0:r1)
static void spm_leap_cmd(uint16_t addr, uint8_t spmCmd, uint8_t spmCmd2, uint16_t optValue) {
    asm volatile(
        "push r10\n\t" // spmCmd 1
        "push r11\n\t" // spmCmd 2
        "push r0\n\t" // r0:r1 -> data to SPM instruction
        "push r1\n\t"
        "push r30\n\t" // Z[r30:r31] -> address to SPM instruction
        "push r31\n\t"

        // NOTE: bootloader always waits after executing the SPM instruction,
        // so no need to wait for the SPM instruction to execute.

        // For the `call_spm_fn` function, the following registers are used
        // * Z[r30:r31]: word address which the command will operate on
        // * [r0:r1]: optional value used by the command
        // * r20: command value loaded into the SPMCSR register
        "movw r0, %[optValue] \n\t" // set the value to be written
        "mov r10, %[spmCmd]\n\t"    // SPMCSR value 1
        "mov r11, %[spmCmd2]\n\t"   // SPMCSR value 2
        "mov r30, %A[addr]\n\t"
        "mov r31, %B[addr]\n\t"

        "call %[SPM_ADDR]\n\t"

        // Return from the bootloader, pop values from stack and return
        "pop r31\n\t"
        "pop r30\n\t"
        "pop r1\n\t"
        "pop r0\n\t"
        "pop r11\n\t"
        "pop r10\n\t"
            // output registers
            : "=r" (addr)                                       // %0
            // input registers
            : [spmCmd] "r" (spmCmd),                            // %1
              [spmCmd2] "r" (spmCmd2),                          // %2
              [optValue] "r" (optValue),                        // %3
              [addr] "0" (addr),                                // %4
              [SPM_CSR] "I" (_SFR_IO_ADDR(SPMCSR)),             // %5
              [SPM_ADDR] "i" (SPM_INTERFACE_ADDRESS)

    );
}

/// Erases the page at which the address points to/inside.
void spm_erase_page(uint16_t addr) {
    spm_leap_cmd(
        addr,
        (1<<SPMEN) | (1<<PGERS),
        (1<<SPMEN) | (1<<RWWSRE),
        0
    );
}

/// Load a value into the temporary page buffer
void spm_load_temporary_buffer(uint8_t offset, uint16_t data_word) {
    spm_leap_cmd(
        offset,
        (1<<SPMEN),
        0,
        data_word
    );
}

/// Write the temporary page buffer to the page at the given address.
void spm_write_page(uint16_t addr) {
    spm_leap_cmd(
        addr,
        (1<<SPMEN) | (1<<PGWRT),
        (1<<SPMEN) | (1<<RWWSRE),
        0
    );
}
