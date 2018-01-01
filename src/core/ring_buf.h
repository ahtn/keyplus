// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include <stdint.h>
#include <assert.h>

// Note: A ring buffer defined with a given size `size` will only be able to
// store `(size-1)` elements at a time, but still uses `size*sizeof(data_type)`
// bytes in memory. This simplifies the implementation.
#define DEFINE_RING_BUF_TYPE(size, ptr_type, data_type, type_name) \
typedef struct type_name ## _type { \
    data_type data[size]; \
    ptr_type head; \
    ptr_type tail; \
} type_name ## _type ; \

#define RING_BUF_MOD(size, x) ((x) % (size))
#define RING_BUF_ADD(size, x, y) (RING_BUF_MOD(size, x + y))
#define RING_BUF_LEN(size, buf) (RING_BUF_MOD(size, buf->tail - buf->head))
#define RING_BUF_SPACE(size, buf) ((size-1) - RING_BUF_LEN(size, buf))

#define DEFINE_RING_BUF_CLEAR_FUNCTION(size, ptr_type, data_type, type_name) \
static inline void type_name ## _clear (type_name ## _type *buf) { \
    buf->head = 0; \
    buf->tail = 0; \
} \

#define DEFINE_RING_BUF_HAS_DATA_FUNCTION(size, ptr_type, data_type, type_name) \
static inline uint8_t type_name ## _has_data (type_name ## _type *buf) { \
    return buf->head != buf->tail; \
} \

#define DEFINE_RING_BUF_LEN_FUNCTION(size, ptr_type, data_type, type_name) \
static inline ptr_type type_name ## _len (type_name ## _type *buf) { \
    return RING_BUF_LEN(size, buf); \
} \

#define DEFINE_RING_BUF_SPACE_FUNCTION(size, ptr_type, data_type, type_name) \
static inline ptr_type type_name ## _space (type_name ## _type *buf) { \
    return RING_BUF_SPACE(size, buf); \
} \

#define DEFINE_RING_BUF_GET_FUNCTION(size, ptr_type, data_type, type_name) \
static inline data_type type_name ## _get (type_name ## _type *buf) { \
    const data_type data = buf->data[buf->head]; \
    assert(buf->head != buf->tail); \
    buf->head = RING_BUF_ADD(size, buf->head, 1); \
    return data; \
} \

#define DEFINE_RING_BUF_PEEK_FUNCTION(size, ptr_type, data_type, type_name) \
static inline data_type type_name ## _peek (type_name ## _type *buf) { \
    const data_type data = buf->data[buf->head]; \
    assert(buf->head != buf->tail); \
    return data; \
} \

#define DEFINE_RING_BUF_PUT_FUNCTION(size, ptr_type, data_type, type_name) \
static inline void type_name ## _put (type_name ## _type *buf, data_type val) { \
    const ptr_type next_tail = RING_BUF_ADD(size, buf->tail, 1); \
    assert(next_tail != buf->head); \
    buf->data[buf->tail] = val; \
    buf->tail = next_tail; \
} \

#define DEFINE_RING_BUF_FILL_FUNCTION(size, ptr_type, data_type, type_name) \
static inline void type_name ## _fill (type_name ## _type *buf, data_type *fill_data, ptr_type fill_len) { \
    assert(fill_len < RING_BUF_SPACE(size, buf)); \
    while (fill_len--) { \
        buf->data[buf->tail] = *fill_data++; \
        buf->tail = RING_BUF_ADD(size, buf->tail, 1); \
    } \
} \

#define DEFINE_RING_BUF_TAKE_FUNCTION(size, ptr_type, data_type, type_name) \
static inline void type_name ## _take (type_name ## _type *buf, data_type *dest, ptr_type take_len) { \
    assert((ptr_type)take_len < (ptr_type)RING_BUF_LEN(size, buf)); \
    while (take_len--) { \
        *dest++ = buf->data[buf->head]; \
        buf->head = RING_BUF_ADD(size, buf->head, 1); \
    } \
} \

#define DEFINE_RING_BUF_SKIP_FUNCTION(size, ptr_type, data_type, type_name) \
static inline void type_name ## _skip (type_name ## _type *buf, ptr_type skip_len) { \
    const ptr_type new_head = RING_BUF_ADD(size, buf->head, skip_len); \
    assert((ptr_type)skip_len < (ptr_type)RING_BUF_LEN(size, buf)); \
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
//
#define DEFINE_RING_BUF_VARIANT(buf_len, ptr_type, data_type, buf_name) \
    DEFINE_RING_BUF_TYPE(buf_len+1, ptr_type, data_type, buf_name) \
    DEFINE_RING_BUF_CLEAR_FUNCTION(buf_len+1, ptr_type, data_type, buf_name) \
    DEFINE_RING_BUF_HAS_DATA_FUNCTION(buf_len+1, ptr_type, data_type, buf_name) \
    DEFINE_RING_BUF_LEN_FUNCTION(buf_len+1, ptr_type, data_type, buf_name) \
    DEFINE_RING_BUF_SPACE_FUNCTION(buf_len+1, ptr_type, data_type, buf_name) \
    DEFINE_RING_BUF_GET_FUNCTION(buf_len+1, ptr_type, data_type, buf_name) \
    DEFINE_RING_BUF_PEEK_FUNCTION(buf_len+1, ptr_type, data_type, buf_name) \
    DEFINE_RING_BUF_PUT_FUNCTION(buf_len+1, ptr_type, data_type, buf_name) \
    DEFINE_RING_BUF_FILL_FUNCTION(buf_len+1, ptr_type, data_type, buf_name) \
    DEFINE_RING_BUF_TAKE_FUNCTION(buf_len+1, ptr_type, data_type, buf_name) \
    DEFINE_RING_BUF_SKIP_FUNCTION(buf_len+1, ptr_type, data_type, buf_name)
