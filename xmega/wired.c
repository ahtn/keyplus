// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#include "wired.h"

#include <string.h>

#include "hardware/twi_master_driver.h"
#include "hardware/twi_slave_driver.h"

#include "core/error.h"
#include "core/io_map.h"
#include "core/settings.h"
#include "core/matrix_scanner.h"
#include "core/matrix_interpret.h"

static TWI_Master_t twi_master;
static TWI_Slave_t twi_slave;

/*! TWIE Master Interrupt vector. */
ISR(TWIE_TWIM_vect) {
    TWI_MasterInterruptHandler(&twi_master);
}

/*! TWIE Slave Interrupt vector. */
ISR(TWIE_TWIS_vect) {
    TWI_SlaveInterruptHandler(&twi_slave);
}

#define I2C_BUFFER_PTR_INC(ptr) ((ptr+1) % I2C_BUFFER_COUNT)

static uint8_t i2c_buffer_ptr;
static uint8_t i2c_buffer_ptr_oldest;
static uint8_t i2c_buffers[I2C_BUFFER_COUNT][I2C_BROADCAST_MAX_SIZE];

static void TWIE_SlaveProcessData(void);

static uint8_t our_i2c_address;

void i2c_init(void) {
    if (g_runtime_settings.feature.ctrl.wired_disabled) {
        return;
    }

    our_i2c_address = device_id_to_i2c_address(GET_SETTING(device_id));
    i2c_buffer_ptr = 0;
    i2c_buffer_ptr_oldest = 0;

    if (io_map_claim_pins(PORT_TO_NUM(PORTE), PIN0_bm | PIN1_bm)) {
        register_error(ERROR_PIN_MAPPING_CONFLICT);
        return;
    }

    PORTE.DIRSET = PIN0_bm | PIN1_bm;
    PORTE.OUTSET = PIN0_bm;

    /* Initialize TWI master. */
    TWI_MasterInit(&twi_master, &TWIE, TWI_MASTER_INTLVL_MED_gc, TWI_BAUDSETTING);
    /* Initialize TWI slave. */
    TWI_SlaveInitializeDriver(&twi_slave, &TWIE, TWIE_SlaveProcessData);
    TWI_SlaveInitializeModule(&twi_slave, our_i2c_address, TWI_SLAVE_INTLVL_MED_gc);
}

uint8_t i2c_get_active_address(void) {
    return our_i2c_address;
}

uint8_t i2c_broadcast(const uint8_t* data, uint8_t size) {
    return TWI_MasterWrite(&twi_master, I2C_GENERAL_CALL_ADDRESS, data, size);
}

// i2c packet format:
// byte 0: src address
// byte 1: packet type and length n
// byte 2,...,n+2: data bytes
// byte n+3: checksum
void TWIE_SlaveProcessData(void) {
    static bool i2c_discard_data;
    static uint8_t packet_last_byte;
    static uint8_t checksum;
    uint8_t byte_num = twi_slave.bytesReceived;
    const uint8_t received_byte = twi_slave.receivedData[byte_num];

    if (byte_num == 0) {
        const uint8_t address = twi_slave.receivedData[0] >> 1;

        if (I2C_BUFFER_PTR_INC(i2c_buffer_ptr) == i2c_buffer_ptr_oldest ||
                                address == our_i2c_address ) {
            // Don't save any data if the i2c buffers are all full.
            // Also ignore packets not sent by this device
            i2c_discard_data = true;
            return;
        } else {
            i2c_discard_data = false;
            packet_last_byte = 255;
            checksum = 0;
        }
    }

        if (i2c_discard_data) {
        return;
    }

    if (byte_num == 1) {
        // contains the packet type and size
        const uint8_t matrix_data_size = received_byte & PACKET_MATRIX_SIZE_MASK;
        const uint8_t address_size = 1;
        const uint8_t packet_type_size = 1;
        const uint8_t check_sum_size = 1;
        const uint8_t total_size = matrix_data_size + (address_size + packet_type_size + check_sum_size);

        if (total_size >= I2C_BROADCAST_MAX_SIZE) {
            // ignore packets that are too large for our buffers
            i2c_discard_data = true;
            return;
        }

        packet_last_byte = total_size - 1;
    }

    i2c_buffers[i2c_buffer_ptr][byte_num] = received_byte;
    checksum += received_byte;

    if (byte_num == packet_last_byte) {
        if (checksum == 0) {
            // only accept the packet if the checksum is valid
            i2c_buffer_ptr = I2C_BUFFER_PTR_INC(i2c_buffer_ptr);
        }
        // TODO: if we have a checksum error, make the host send a resend
        // resuest

        // got all the data we are expecting, so discard the rest if any more
        // comes in this transaction
        i2c_discard_data = true;
    }
}

uint8_t i2c_calculate_checksum(uint8_t *buffer, uint8_t length) {
    uint8_t i;
    uint8_t csum = 0;
    for (i = 0; i < length; ++i) {
        csum += buffer[i];
    }
    return (uint8_t)(-csum);
}

// gets the next buffer in the queue. if no buffer is availabe, returns NULL
uint8_t *i2c_get_buffer(void) {
    if (i2c_buffer_ptr == i2c_buffer_ptr_oldest) {
        return NULL;
    }

    return i2c_buffers[i2c_buffer_ptr_oldest];
}

void i2c_buffer_advance(void) {
    if (i2c_buffer_ptr_oldest == i2c_buffer_ptr) {
        return;
    }

    i2c_buffer_ptr_oldest = I2C_BUFFER_PTR_INC(i2c_buffer_ptr_oldest);
}
