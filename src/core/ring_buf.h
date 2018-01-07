// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <stdint.h>
#include "core/util.h"
#include "core/debug.h"

/*********************************************************************
 *               ring buffer (byte stream ring buffer)               *
 *********************************************************************/

// Note: A ring buffer defined with a given size `size` will only be able to
// store `(size-1)` elements at a time, but still uses `size*sizeof(data_type)`
// bytes in memory. This simplifies the implementation.
#define DEFINE_RING_BUF_TYPE(size, ptr_type, data_type, type_name) \
typedef struct type_name ## _type { \
    data_type data[size]; \
    ptr_type head; \
    ptr_type tail; \
} type_name ## _type \

#define RING_BUF_MOD(size, x) ((x) % (size))
#define RING_BUF_ADD(size, x, y) (RING_BUF_MOD(size, x + y))
#define RING_BUF_LEN(size, ptr_type, buf) (RING_BUF_MOD(size, (ptr_type)(buf->tail - buf->head)))
#define RING_BUF_SPACE(size, ptr_type, buf) (((size-1) - RING_BUF_LEN(size, ptr_type, buf)))

// clear()
#define PROTO_RING_BUF_CLEAR_FUNCTION(size, ptr_type, data_type, type_name, fn_type) \
fn_type void type_name ## _clear (XRAM type_name ## _type *buf)

#define DEFINE_RING_BUF_CLEAR_FUNCTION(size, ptr_type, data_type, type_name, fn_type) \
PROTO_RING_BUF_CLEAR_FUNCTION(size, ptr_type, data_type, type_name, fn_type) { \
    buf->head = 0; \
    buf->tail = 0; \
} \

// has_data()
#define PROTO_RING_BUF_HAS_DATA_FUNCTION(size, ptr_type, data_type, type_name, fn_type) \
fn_type uint8_t type_name ## _has_data (XRAM const type_name ## _type *buf)

#define DEFINE_RING_BUF_HAS_DATA_FUNCTION(size, ptr_type, data_type, type_name, fn_type) \
PROTO_RING_BUF_HAS_DATA_FUNCTION(size, ptr_type, data_type, type_name, fn_type) { \
    return buf->head != buf->tail; \
} \

// len()
#define PROTO_RING_BUF_LEN_FUNCTION(size, ptr_type, data_type, type_name, fn_type) \
fn_type ptr_type type_name ## _len (XRAM const type_name ## _type *buf)

#define DEFINE_RING_BUF_LEN_FUNCTION(size, ptr_type, data_type, type_name, fn_type) \
PROTO_RING_BUF_LEN_FUNCTION(size, ptr_type, data_type, type_name, fn_type) { \
    return RING_BUF_LEN(size, ptr_type, buf); \
} \

// free_space()
#define PROTO_RING_BUF_SPACE_FUNCTION(size, ptr_type, data_type, type_name, fn_type) \
fn_type ptr_type type_name ## _free_space (XRAM const type_name ## _type *buf) \

#define DEFINE_RING_BUF_SPACE_FUNCTION(size, ptr_type, data_type, type_name, fn_type) \
PROTO_RING_BUF_SPACE_FUNCTION(size, ptr_type, data_type, type_name, fn_type) { \
    return RING_BUF_SPACE(size, ptr_type, buf); \
} \

// get()
#define PROTO_RING_BUF_GET_FUNCTION(size, ptr_type, data_type, type_name, fn_type) \
fn_type data_type type_name ## _get (XRAM type_name ## _type *buf)

#define DEFINE_RING_BUF_GET_FUNCTION(size, ptr_type, data_type, type_name, fn_type) \
PROTO_RING_BUF_GET_FUNCTION(size, ptr_type, data_type, type_name, fn_type) { \
    const data_type data = buf->data[buf->head]; \
    assert(buf->head != buf->tail); \
    buf->head = RING_BUF_ADD(size, buf->head, 1); \
    return data; \
} \

// peek()
#define PROTO_RING_BUF_PEEK_FUNCTION(size, ptr_type, data_type, type_name, fn_type) \
fn_type data_type type_name ## _peek (XRAM const type_name ## _type *buf)

#define DEFINE_RING_BUF_PEEK_FUNCTION(size, ptr_type, data_type, type_name, fn_type) \
PROTO_RING_BUF_PEEK_FUNCTION(size, ptr_type, data_type, type_name, fn_type) { \
    const data_type data = buf->data[buf->head]; \
    assert(buf->head != buf->tail); \
    return data; \
} \

// put()
#define PROTO_RING_BUF_PUT_FUNCTION(size, ptr_type, data_type, type_name, fn_type) \
fn_type void type_name ## _put (XRAM type_name ## _type *buf, data_type val)

#define DEFINE_RING_BUF_PUT_FUNCTION(size, ptr_type, data_type, type_name, fn_type) \
PROTO_RING_BUF_PUT_FUNCTION(size, ptr_type, data_type, type_name, fn_type) { \
    const ptr_type next_tail = RING_BUF_ADD(size, buf->tail, 1); \
    assert(next_tail != buf->head); \
    buf->data[buf->tail] = val; \
    buf->tail = next_tail; \
} \

// fill()
#define PROTO_RING_BUF_FILL_FUNCTION(size, ptr_type, data_type, type_name, fn_type) \
fn_type void type_name ## _fill (XRAM type_name ## _type *buf, const data_type *fill_data, ptr_type fill_len)

#define DEFINE_RING_BUF_FILL_FUNCTION(size, ptr_type, data_type, type_name, fn_type) \
PROTO_RING_BUF_FILL_FUNCTION(size, ptr_type, data_type, type_name, fn_type) { \
    assert(fill_len <= RING_BUF_SPACE(size, ptr_type, buf)); \
    while (fill_len--) { \
        buf->data[buf->tail] = *fill_data++; \
        buf->tail = RING_BUF_ADD(size, buf->tail, 1); \
    } \
} \

// take()
#define PROTO_RING_BUF_TAKE_FUNCTION(size, ptr_type, data_type, type_name, fn_type) \
fn_type void type_name ## _take (XRAM type_name ## _type *buf, data_type *dest, ptr_type take_len)

#define DEFINE_RING_BUF_TAKE_FUNCTION(size, ptr_type, data_type, type_name, fn_type) \
PROTO_RING_BUF_TAKE_FUNCTION(size, ptr_type, data_type, type_name, fn_type) { \
    assert(take_len <= RING_BUF_LEN(size, ptr_type, buf)); \
    while (take_len--) { \
        *dest++ = buf->data[buf->head]; \
        buf->head = RING_BUF_ADD(size, buf->head, 1); \
    } \
} \

// skip()
#define PROTO_RING_BUF_SKIP_FUNCTION(size, ptr_type, data_type, type_name, fn_type) \
fn_type void type_name ## _skip (XRAM type_name ## _type *buf, ptr_type skip_len)

#define DEFINE_RING_BUF_SKIP_FUNCTION(size, ptr_type, data_type, type_name, fn_type) \
PROTO_RING_BUF_SKIP_FUNCTION(size, ptr_type, data_type, type_name, fn_type) { \
    const ptr_type new_head = RING_BUF_ADD(size, buf->head, skip_len); \
    assert(skip_len <= RING_BUF_LEN(size, ptr_type, buf)); \
    buf->head = new_head; \
} \


// This macro defines a ring buffer type and the associated functions to operate
// on it. It takes the following parameters:
// * buf_len: the maximum number of elements that can be stored in the ring buffer
//      at any one time
// * ptr_type: unsigned integer type that is used for the internal pointers of
//      the buffer
// * data_type: type of the elements in the ring_buf
// * buf_name: name for the ring buffer. The generated functions will be prefixed
//      with `buf_name` and the ring buffer type itself will be `<buf_name>_type`.
// Note: Uses `(buf_len+1)*sizeof(data_type) + 2*ptr_type` in RAM for the type.
// NOTE: The `ptr_type` should be an integer type that can hold the
// `buf_len` parameter without overflowing. For example:
// if buf_len == 255 --> ptr_type == uint8_t
// if buf_len == 256 --> ptr_type == uint16_t
// NOTE: For the better code optimization by the compiler, `ptr_type` should be
// an unsigned integer. Also, choosing `buf_len` of the form `2^n-1`
// will result in more efficient code as `(x % (buf_len+1))` can be optimized
// to `(x & buf_len)`.
//
// DEFINE_RING_BUF_VARIANT(buf_len, ptr_type, data_type, buf_name) will define
// the ring buffer type `<buf_name>_type` and the following functions:
//   <buf_name>_clear(*buf): empty the ring buffer
//   <buf_name>_has_data(*buf): check if the ring buffer has data
//   <buf_name>_get(*buf): read one item from the ring buffer
//   <buf_name>_peek(*buf): read one item from the ring buffer without consuming it
//   <buf_name>_put(*buf, data_type value): put one item into the ring buffer
//   <buf_name>_fill(*buf, data_type *value, ptr_type len): put multiple items in ring buffer
//   <buf_name>_take(*buf, data_type *value, ptr_type len): get multiple items in ring buffer
//   <buf_name>_skip(*buf, data_type len): discard `len` items from the ring buffer

#define DEFINE_INLINE_RING_BUF_VARIANT(buf_len, ptr_type, data_type, buf_name) \
    DEFINE_RING_BUF_TYPE(buf_len+1, ptr_type, data_type, buf_name); \
    DEFINE_RING_BUF_CLEAR_FUNCTION(buf_len+1, ptr_type, data_type, buf_name, static inline) \
    DEFINE_RING_BUF_HAS_DATA_FUNCTION(buf_len+1, ptr_type, data_type, buf_name, static inline) \
    DEFINE_RING_BUF_LEN_FUNCTION(buf_len+1, ptr_type, data_type, buf_name, static inline) \
    DEFINE_RING_BUF_SPACE_FUNCTION(buf_len+1, ptr_type, data_type, buf_name, static inline) \
    DEFINE_RING_BUF_GET_FUNCTION(buf_len+1, ptr_type, data_type, buf_name, static inline) \
    DEFINE_RING_BUF_PEEK_FUNCTION(buf_len+1, ptr_type, data_type, buf_name, static inline) \
    DEFINE_RING_BUF_PUT_FUNCTION(buf_len+1, ptr_type, data_type, buf_name, static inline) \
    DEFINE_RING_BUF_FILL_FUNCTION(buf_len+1, ptr_type, data_type, buf_name, static inline) \
    DEFINE_RING_BUF_TAKE_FUNCTION(buf_len+1, ptr_type, data_type, buf_name, static inline)

#define EMPTY
#define DEFINE_PROTO_RING_BUF_VARIANT(buf_len, ptr_type, data_type, buf_name) \
    DEFINE_RING_BUF_TYPE(buf_len+1, ptr_type, data_type, buf_name); \
    PROTO_RING_BUF_CLEAR_FUNCTION(buf_len+1, ptr_type, data_type, buf_name, EMPTY); \
    PROTO_RING_BUF_HAS_DATA_FUNCTION(buf_len+1, ptr_type, data_type, buf_name, EMPTY); \
    PROTO_RING_BUF_LEN_FUNCTION(buf_len+1, ptr_type, data_type, buf_name, EMPTY); \
    PROTO_RING_BUF_SPACE_FUNCTION(buf_len+1, ptr_type, data_type, buf_name, EMPTY); \
    PROTO_RING_BUF_GET_FUNCTION(buf_len+1, ptr_type, data_type, buf_name, EMPTY); \
    PROTO_RING_BUF_PEEK_FUNCTION(buf_len+1, ptr_type, data_type, buf_name, EMPTY); \
    PROTO_RING_BUF_PUT_FUNCTION(buf_len+1, ptr_type, data_type, buf_name, EMPTY); \
    PROTO_RING_BUF_FILL_FUNCTION(buf_len+1, ptr_type, data_type, buf_name, EMPTY); \
    PROTO_RING_BUF_TAKE_FUNCTION(buf_len+1, ptr_type, data_type, buf_name, EMPTY)

#define DEFINE_BODY_RING_BUF_VARIANT(buf_len, ptr_type, data_type, buf_name) \
    DEFINE_RING_BUF_CLEAR_FUNCTION(buf_len+1, ptr_type, data_type, buf_name, EMPTY) \
    DEFINE_RING_BUF_HAS_DATA_FUNCTION(buf_len+1, ptr_type, data_type, buf_name, EMPTY) \
    DEFINE_RING_BUF_LEN_FUNCTION(buf_len+1, ptr_type, data_type, buf_name, EMPTY) \
    DEFINE_RING_BUF_SPACE_FUNCTION(buf_len+1, ptr_type, data_type, buf_name, EMPTY) \
    DEFINE_RING_BUF_GET_FUNCTION(buf_len+1, ptr_type, data_type, buf_name, EMPTY) \
    DEFINE_RING_BUF_PEEK_FUNCTION(buf_len+1, ptr_type, data_type, buf_name, EMPTY) \
    DEFINE_RING_BUF_PUT_FUNCTION(buf_len+1, ptr_type, data_type, buf_name, EMPTY) \
    DEFINE_RING_BUF_FILL_FUNCTION(buf_len+1, ptr_type, data_type, buf_name, EMPTY) \
    DEFINE_RING_BUF_TAKE_FUNCTION(buf_len+1, ptr_type, data_type, buf_name, EMPTY)


/*********************************************************************
 *                block ring (block base ring buffer)                *
 *********************************************************************/

// Note: A ring buffer defined with a given size `size` will only be able to
// store `(size-1)` elements at a time, but still uses `size*sizeof(data_type)`
// bytes in memory. This simplifies the implementation.
#define DEFINE_BLOCK_RING_TYPE(num_blocks, block_size, ptr_type, data_type, type_name) \
typedef struct type_name ## _type { \
    data_type data[num_blocks][block_size]; \
    ptr_type head; \
    ptr_type tail; \
    ptr_type length; \
} type_name ## _type

// len()
#define PROTO_BLOCK_RING_LEN_FUNCTION(ptr_type, data_type, type_name, fn_type) \
fn_type ptr_type type_name ## _len (XRAM type_name ## _type *buf, ptr_type skip_len)

#define DEFINE_BLOCK_RING_LEN_FUNCTION(block_count, block_size, ptr_type, \
    data_type, type_name, fn_type) \
PROTO_BLOCK_RING_LEN_FUNCTION(ptr_type, data_type, type_name, fn_type) { \
    return buf->length; \
}

// is_full()
#define PROTO_BLOCK_RING_IS_FULL_FUNCTION(ptr_type, data_type, type_name, fn_type) \
fn_type uint8_t type_name ## _is_full (XRAM type_name ## _type *buf, ptr_type skip_len)

#define DEFINE_BLOCK_RING_IS_FULL_FUNCTION(block_count, ptr_type, data_type, \
    type_name, fn_type) \
PROTO_BLOCK_RING_IS_FULL_FUNCTION(ptr_type, data_type, type_name, fn_type) { \
    return buf->length == block_count; \
}

// get()
#define PROTO_BLOCK_RING_GET_FUNCTION(ptr_type, data_type, type_name, fn_type) \
fn_type data_type* type_name ## _get (XRAM type_name ## _type *buf, ptr_type skip_len)

#define DEFINE_BLOCK_RING_GET_FUNCTION(block_count, ptr_type, data_type, \
    type_name, fn_type) \
PROTO_BLOCK_RING_TAKE_FUNCTION(ptr_type, data_type, type_name, fn_type) { \
    assert(buf->length > 0); \
    data_type* result = buf->data[buf->head]; \
    buf->head = RING_BUF_ADD(block_count, buf->head, 1); \
    buf->length--; \
}

// put()
#define PROTO_BLOCK_RING_PUT_FUNCTION(ptr_type, data_type, type_name, fn_type) \
fn_type data_type* type_name ## _put (XRAM type_name ## _type *buf, ptr_type skip_len)

#define DEFINE_BLOCK_RING_PUT_FUNCTION(block_count, ptr_type, data_type, \
    type_name, fn_type) \
PROTO_BLOCK_RING_TAKE_FUNCTION(ptr_type, data_type, type_name, fn_type) { \
    assert(buf->length < block_count); \
    data_type* result = buf->data[buf->tail]; \
    buf->tail = RING_BUF_ADD(block_count, buf->tail, 1); \
    buf->length++; \
}


// DEFINE_INLINE_RING_BUF_VARIANT(127, uint8_t, uint8_t, ring_buf128);


// DEFINE_PROTO_RING_BUF_VARIANT(127, uint8_t, uint8_t, ring_buf128);
