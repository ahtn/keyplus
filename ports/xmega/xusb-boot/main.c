// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "config.h"

#include <stdbool.h>
#include <avr/io.h>

#include "sp_driver.h"
#include "boot_protocol.h"

#ifdef ALPHA_SPLIT_V2
#include "boards/alpha_split/alpha_split_util.h"
#endif


// If the bootloader flag is set to this value before a software reset, then
// the bootloader will run
// NOTE: SRAM is cleared except for this value by code in `.init3` section.
// So we should clear its value after we are done with it.
#define BOOTLOADER_MAGIC 0x97e1e28e
uint32_t boot_magic __attribute__ ((section (".noinit")));

// If this flag is set in `boot_magic` when the application code is running,
// then it means that a reset occured while the bootloader was running.
#define BOOTMAGIC_BOOTLOADER_RESET_FLAG (1 << 9)

int main(void) {
    const bool power_on_reset = RST.STATUS & RST_PORF_bm;
    const bool ext_reset = RST.STATUS & RST_EXTRF_bm;
    const bool software_reset = RST.STATUS & RST_SRF_bm;
#if NO_CHECKPIN == 1
    const bool has_vbus = 1;
#else
    const bool has_vbus = CHECK_PORT.IN & CHECK_PIN; // io pins default to input
#endif
    const bool has_magic = (boot_magic == BOOTLOADER_MAGIC);
    const bool bootloader_reset = (boot_magic == BOOTLOADER_MAGIC_BOOT_RESET);

#ifdef ALPHA_SPLIT_V2
    init_bus_switches();
#endif

    // The flags in the RST.STATUS register are not cleared automatically
    // when the mcu is reset. They are only cleared on power on reset, or by
    // manually clearing the flags
    //
    // The flags in the RST.STATUS register must be cleared now for the
    // bootloader to work correctly because it can't rely on the application
    // code to clear them. Write these values to the `boot_magic` variable so
    // that the application code still has away to know the cause of reset.
    //
    // This also serves the role of clearing the boot_magic flag if it contained
    // any sensitive information.
    boot_magic = RST.STATUS;
    if (bootloader_reset) {
        boot_magic |= BOOTMAGIC_BOOTLOADER_RESET_FLAG;
    }
    RST.STATUS = (RST_PORF_bm | RST_SRF_bm | RST_EXTRF_bm);

    // Reset into the bootloader instead of running the application code if one
    // of these conditions is met:
    // * USB plugged in and the external reset button was pressed while
    //   application code was running.
    //   NOTE: If bootloader code was running when the external reset was
    //   received, then run the application code instead. If this happens then
    //   `boot_magic` will have the `BOOTMAGIC_BOOTLOADER_RESET_FLAG` set.
    //   NOTE: If the bootloader does not receive at least one USB SOF packets
    //   after `WATCH_DOG_PERIOD`, then it will reset into the application
    //   code section.
    // * the application flash is not programmed
    // * application section performs a software reset into bootloader
    if ( (has_vbus && ext_reset && !power_on_reset && !bootloader_reset)
        || SP_ReadWord(0x0000) == 0xFFFF
        || (software_reset && has_magic)
    ) {
        run_bootloader();
    }

    // // jump to the application code
    asm("jmp   0x0000");
}
