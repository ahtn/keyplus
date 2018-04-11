// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/nonce.h"

#include <avr/eeprom.h>

#include "arch/avr/eeprom_map.h"

// TODO: let atmega8 and xmega both use this implementation

// NOTE: have 2 redundant copies stored so that we can recover the correct
// value if the mcu was reseting while writing to the eeprom. Store 3 copies
// of the nonce, and write to them sequentially. This way if all the values are
// not equal, then we know there was an error. Since the eeprom will only
// corrupt one byte during a reset during write, we can infer the correct value
// of the nonce from the other two redundant values.

// NOTE: The time it takes to complete an erase/write on one byte of eeprom
// memory is the same as it takes to write an entire page. The timing for
// eeprom operations on xmega is:
// * write: 4ms
// * erase: 4ms
// * atomic erase and write: 8ms
// To update the nonce, the majority of the time only the least significant byte
// will need to be updated.

// TODO: rate limit this?
// TODO: should cause critical error before we overflow that won't let the keyboard
// operate until the value is reset with a new encryption key.
// TODO: on corruption we might not want to set this to a known value
// TODO: should probably ensure BOD is enabled while these commands are run
// because if the voltage drops too low, the EEPROM can become corrupted.
// TODO: should read back the value written and check if it matches what we
// wrote, if it's wrong, should cause a critical error.
uint16_t load_session_id(void) {
    const uint16_t nonce_0 = eeprom_read_word(EEPROM_NONCE_0);
    const uint16_t nonce_1 = eeprom_read_word(EEPROM_NONCE_1);
    const uint16_t nonce_2 = eeprom_read_word(EEPROM_NONCE_2);

    if (nonce_0 == nonce_1 && nonce_1 == nonce_2) {
        return nonce_0;
    } else if (nonce_0 == nonce_1 && nonce_0 != nonce_2) {
        // NONCE_2 corrupt
        eeprom_update_word(EEPROM_NONCE_2, nonce_0);
        return nonce_0; // nonce not corrupt
    } else if (nonce_0 != nonce_1 && nonce_0 == nonce_2+1) {
        // NONCE_1 corrupt
        // eeprom reset while writing nonce_1, nonce_0 holds correct value and
        // nonce_2 holds the old value
        eeprom_update_word(EEPROM_NONCE_1, nonce_0);
        eeprom_update_word(EEPROM_NONCE_2, nonce_0);
        return nonce_0;
    } else if (nonce_0 != nonce_1 && nonce_1 == nonce_2) {
        // NONCE_0 corrupt
        // eeprom reset while writing nonce_0, nonce_1 && nonce_2 hold the old
        // value of the nonce. So correct nonce value is nonce_1+1.
        eeprom_update_word(EEPROM_NONCE_0, nonce_1+1);
        eeprom_update_word(EEPROM_NONCE_1, nonce_1+1);
        eeprom_update_word(EEPROM_NONCE_2, nonce_1+1);
        return nonce_1+1;
    } else {
        // Nonce not initalized, or corrupt and can't be recovered
        // TODO: if the nonce is corrupt, we probably don't want to reset the
        // counter.
        eeprom_update_word(EEPROM_NONCE_0, 0);
        eeprom_update_word(EEPROM_NONCE_1, 0);
        eeprom_update_word(EEPROM_NONCE_2, 0);
        return 0;
    }
}

uint16_t increment_session_id(void) {
    const uint16_t nonce = load_session_id() + 1;
    eeprom_update_word(EEPROM_NONCE_0, nonce);
    eeprom_update_word(EEPROM_NONCE_1, nonce);
    eeprom_update_word(EEPROM_NONCE_2, nonce);
    return nonce;
}
