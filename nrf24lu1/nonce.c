// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "core/nonce.h"

#include "core/flash.h"

// The only non-volatile storage in the nrf24lu1+ is its flash.
// The flash is broken into 512 bytes (32 in 16kb, 64 in 32kb).
// The pages have a minimum endurance of 1000 erase cycles.
//
// From the nrf24lu1+ datasheet:
// Note: You can write to a flash byte twice between each erase. A page (or full) erase sets the value
// of all erased bytes to 0xFF. A write to a flash byte only programs the 0-bits of the byte, leav-
// ing the 1-bits as they are (after the erase). Thus for the second write, only the remaining 1-
// bits can be programmed. This results in an "and" function of the first and second write.
// Example: Writing 0x46 and 0x27 to the same byte (without erase in between) will result in a
// stored value 0x06 .

// We use a tally mark/unary counting system here to overcome these limitations.

// TODO: should probably use 2 pages to store this value
// session id defines
#define NONCE_PAGE (NONCE_ADDR / PAGE_SIZE)
#define SID_MAGIC_VALUE (0x268e8728UL)

#define SID_VALUE_OFFSET 0
#define SID_MAGIC_OFFSET 2
#define SID_COUNTER_OFFSET 6
#define SID_COUNTER_LEN (PAGE_SIZE-SID_COUNTER_OFFSET)
#define SID_COUNTING_CAPACITY (SID_COUNTER_LEN*2)
// For each page write, we can increment the counter by 506*2 (==1012) per a
// page write. So 1012*1000 writes per a page minimum.

AT(NONCE_ADDR) static ROM uint16_t s_sid_value;
AT(NONCE_ADDR+SID_MAGIC_OFFSET) static ROM uint32_t s_sid_magic;
AT(NONCE_ADDR+SID_COUNTER_OFFSET) static ROM uint8_t s_sid_counter[SID_COUNTER_LEN];

// Since we can only write twice to a byte twice, use these values to represent
// the 3 possible bytes values used for counting
#define SID_0_WRITES (0xff)
#define SID_1_WRITES (0xfe)
#define SID_2_WRITES (0xfc)


static void sid_write_value(uint16_t value) {
    const uint32_t magic = SID_MAGIC_VALUE;
    flash_modify_enable();
    flash_erase_page(NONCE_PAGE);
    flash_write(&value, (NONCE_ADDR+SID_VALUE_OFFSET), sizeof(uint16_t));
    flash_write(&magic, (NONCE_ADDR+SID_MAGIC_OFFSET), sizeof(uint32_t));
    flash_modify_disable();
}

uint16_t load_session_id(void) {
    if (s_sid_magic != SID_MAGIC_VALUE) {
        sid_write_value(0);
        return 0;
    } else {
        uint16_t result = s_sid_value;
        uint16_t i;
        for (i = 0; i < SID_COUNTER_LEN; ++i) {
            const uint8_t value = s_sid_counter[i];
            switch (value) {
                case SID_0_WRITES: {
                    return result+0;
                } break;
                case SID_1_WRITES: {
                    return result+1;
                } break;
                case SID_2_WRITES: {
                    result += 2;
                } break;
                default: {
                    // TODO: this is bad, should send a error message that is
                    // visible to the user since if this is happening
                    // continually, the flash is corrupt and the user will be
                    // vulnerable to replay attacks

                    // for now, just increment the SID to the value it would be
                    // after filling this block
                    result += SID_COUNTING_CAPACITY+1;
                }
            }
        }
        return result;
    }
}

uint16_t increment_session_id(void) {
    uint16_t i;
    uint16_t nonce_value = load_session_id();

    for (i = 0; i < SID_COUNTER_LEN; ++i) {
        const uint8_t tally_value = s_sid_counter[i];
        if (tally_value == SID_2_WRITES) {
            continue;
        } else if (tally_value == SID_1_WRITES || tally_value == SID_0_WRITES) {
            uint8_t value_to_write;
            if (tally_value == SID_0_WRITES) {
                value_to_write = SID_1_WRITES;
            } else { // SID_1_WRITES
                value_to_write = SID_2_WRITES;
            }
            flash_modify_enable();
            flash_write(&value_to_write, (NONCE_ADDR+SID_COUNTER_OFFSET+i), 1);
            flash_modify_disable();
            return nonce_value + 1;
        } else {
            // TODO: PANIC
        }
    }

    { // if we got here that means the page is full
        sid_write_value(nonce_value + 1);
        return nonce_value + 1;
    }

}
