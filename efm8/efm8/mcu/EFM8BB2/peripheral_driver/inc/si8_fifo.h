/**************************************************************************//**
 * Copyright (c) 2015 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

#include "si8Options.h"
#include "si_toolchain.h"

//debug
#define SI8_FIFO_USE 1

#if SI8_FIFO_USE == 1

/**
 * Structure defining a FIFO
 */
typedef struct si8Fifo
{
  uint8_t* buf;   //!< Poiner to user provided data buffer
  uint8_t  head;  //!< Current head position
  uint8_t  tail;  //!< Current tail position
  uint8_t  size;  //!< Size ofdata buffer
}si8Fifo_t;

/**
 * @brief push data into the fifo
 */
uint8_t si8_push_fifo(si8Fifo_t fifo, uint8_t* data, uint8_t size);

/**
 * @brief pop data out of the fifo
 */
uint8_t si8_pop_fifo(si8Fifo_t fifo, uint8_t* data, uint8_t size);

/**
 * Get the number of words currently in the fifo
 */
uint8_t si8_get_fifo_count(si8Fifo_t fifo);

#if SI8_FIFO_USE_CALLBACKS == 1

/**
 * Called when an underflow occurs
 */
void fifo_underflow(si8Fifo_t fifo);
//CB
/**
 * Called when an overflow occurs
 */
void fifo_underflow(si8Fifo_t fifo);

#endif //SI8_FIFO_USE_CALLBACKS
#endif //SI8_FIFO_USE
