#ifndef __fifo_h__
#define __fifo_h__

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define FIFO_BUF_LEN 512

typedef struct
{
    uint8_t  buf[FIFO_BUF_LEN];
    uint32_t start_idx;
    uint32_t end_idx;
    uint32_t free_items;
} fifo_t;

static inline void fifo_init(fifo_t * p_fifo)
{
    memset(p_fifo, 0, sizeof(fifo_t));
    p_fifo->free_items = FIFO_BUF_LEN;
}

static inline uint32_t fifo_num_elem_get(fifo_t * p_fifo)
{
    return (FIFO_BUF_LEN - p_fifo->free_items);
}

static inline void fifo_get_pkt(fifo_t * p_fifo, uint8_t * p_buf, uint32_t * p_buf_len)
{
    uint32_t num_items;
    
    if (p_fifo->free_items == sizeof(p_fifo->buf))
    {
        *p_buf_len = 0;
        return;
    }
    
    if (p_fifo->start_idx < p_fifo->end_idx)
    {
        num_items = p_fifo->end_idx - p_fifo->start_idx;
    }
    else
    {
        num_items = p_fifo->end_idx + (sizeof(p_fifo->buf) - p_fifo->start_idx);
    }
    
    // Truncating elements to get from fifo
    if (num_items > *p_buf_len)
    {
        num_items = *p_buf_len;
    }
    
    *p_buf_len = num_items;
    
    if (p_fifo->start_idx + num_items > sizeof(p_fifo->buf))
    {
        uint32_t bytes_to_copy;
        
        // Wrap around
        bytes_to_copy = sizeof(p_fifo->buf) - p_fifo->start_idx;
        
        memcpy(p_buf, &p_fifo->buf[p_fifo->start_idx], bytes_to_copy);
        p_buf                  += bytes_to_copy;
        p_fifo->free_items += bytes_to_copy;
        p_fifo->start_idx   = 0;
        num_items              -= bytes_to_copy;
    }
    
    memcpy(p_buf, &p_fifo->buf[p_fifo->start_idx], num_items);
    p_fifo->start_idx  += num_items;
    p_fifo->free_items += num_items;
}

static inline void fifo_peek_pkt(fifo_t * p_fifo, uint8_t * p_buf, uint32_t * p_buf_len)
{
    uint32_t num_items, start_idx;
    
    if (p_fifo->free_items == sizeof(p_fifo->buf))
    {
        *p_buf_len = 0;
        return;
    }
    
    start_idx  = p_fifo->start_idx;
    
    if (p_fifo->start_idx < p_fifo->end_idx)
    {
        num_items = p_fifo->end_idx - p_fifo->start_idx;
    }
    else
    {
        num_items = p_fifo->end_idx + (sizeof(p_fifo->buf) - p_fifo->start_idx);
    }
    
    // Truncating elements to get from fifo
    if (num_items > *p_buf_len)
    {
        num_items = *p_buf_len;
    }
    
    *p_buf_len = num_items;
    
    if (start_idx + num_items > sizeof(p_fifo->buf))
    {
        uint32_t bytes_to_copy;
        
        // Wrap around
        bytes_to_copy = sizeof(p_fifo->buf) - start_idx;
        
        memcpy(p_buf, &p_fifo->buf[start_idx], bytes_to_copy);
        p_buf      += bytes_to_copy;
        start_idx   = 0;
        num_items  -= bytes_to_copy;
    }
    
    memcpy(p_buf, &p_fifo->buf[start_idx], num_items);
}

static inline bool fifo_put_pkt(fifo_t * p_fifo, uint8_t * p_buf, uint32_t p_buf_len)
{
    if (p_fifo->free_items < p_buf_len)
    {
        return false;
    }
    
    for (int i = 0; i < p_buf_len; ++i)
    {
        p_fifo->buf[p_fifo->end_idx] = p_buf[i];
        ++p_fifo->end_idx;
        if (p_fifo->end_idx == sizeof(p_fifo->buf))
        {
            p_fifo->end_idx = 0;
        }
    }
    
    p_fifo->free_items -= p_buf_len;
    
    return true;
}

static inline bool fifo_put_char(fifo_t * p_fifo, uint8_t p_char)
{
    if (p_fifo->free_items == 0)
    {
        return false;
    }
    
    p_fifo->buf[p_fifo->end_idx++] = p_char;
    
    if (p_fifo->end_idx == sizeof(p_fifo->buf))
    {
        p_fifo->end_idx = 0;
    }
    
    p_fifo->free_items -= 1;
    
    return true;
}

#endif /* __fifo_h__ */
