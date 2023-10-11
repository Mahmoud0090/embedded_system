/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Mahmoud Abdulaal
 * @date October 4 2023
 *
 */
#include "../include/common/memory.h"
#include <stdint.h>
/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t *my_memmove(uint8_t *src, uint8_t *dst, size_t length)
{
    if (src == NULL || dst == NULL || length == 0)
    {
        // Handle invalid input or nothing to move
        return dst;
    }

    // Check for overlap: if src is after dst but within the copied region
    if (src < dst && src + length > dst)
    {
        // Copy bytes from the end to the beginning to avoid overwriting data prematurely
        src += length;
        dst += length;

        while (length--)
        {
            *(--dst) = *(--src);
        }
    }
    else
    {
        // Standard memory copy from start to end
        while (length--)
        {
            *(dst++) = *(src++);
        }
    }

    return dst;
}

uint8_t *my_memcopy(uint8_t *src, uint8_t *dst, size_t length)
{
    if (src == NULL || dst == NULL || length == 0)
    {
        // Handle invalid input or nothing to copy
        return dst;
    }

    // Perform memory copy using pointer arithmetic
    while (length--)
    {
        *(dst++) = *(src++);
    }

    return dst;
}

uint8_t *my_memset(uint8_t *src, size_t length, uint8_t value)
{
    if (src == NULL || length == 0)
    {
        // Handle invalid input or nothing to set
        return src;
    }

    uint8_t* temp = src;

    // Perform memory setting using pointer arithmetic
    while (length--)
    {
        *(temp++) = value;
    }

    return src;
}

uint8_t *my_memzero(uint8_t *src, size_t length)
{
    if (src == NULL || length == 0)
    {
        // Handle invalid input or nothing to zero out
        return src;
    }

    uint8_t* temp = src;

    // Perform memory zeroing using pointer arithmetic
    while (length--)
    {
        *(temp++) = 0;
    }

    return src;
}

uint8_t *my_reverse(uint8_t *src, size_t length)
{
    if (src == NULL || length <= 1)
    {
        // Handle invalid input or no need to reverse
        return src;
    }

    uint8_t *start = src;            // Pointer to the beginning of the memory region
    uint8_t *end = src + length - 1; // Pointer to the end of the memory region

    while (start < end)
    {
        // Swap the bytes at 'start' and 'end'
        uint8_t temp = *start;
        *start = *end;
        *end = temp;

        // Move the pointers inward
        start++;
        end--;
    }

    return src;
}

int32_t * reserve_words(size_t length)
{
    int32_t *ptr = (int32_t *)malloc(length * sizeof(int32_t));
    return ptr;
}

void free_words(int32_t * src)
{
    free(src);
}

