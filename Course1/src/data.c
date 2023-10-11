#include<stdint.h>
#include "../include/common/data.h"

uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base)
{
    if (ptr == 0 || base < 2 || base > 16)
    {
        // Invalid input or unsupported base
        return 0;
    }

    // Initialize variables
    uint8_t* start_ptr = ptr;
    int32_t absolute_value = (data < 0) ? -data : data;
    uint32_t digit;

    // Handle the sign if the number is negative
    if (data < 0)
    {
        *ptr = '-';
        ptr++;
    }

    // Handle the case when the number is 0
    if (absolute_value == 0)
    {
        *ptr = '0';
        ptr++;
    }
    else
    {
        // Convert the absolute value to ASCII in the specified base
        while (absolute_value > 0)
        {
            digit = absolute_value % base;
            *ptr = (digit < 10) ? '0' + digit : 'A' + digit - 10;
            ptr++;
            absolute_value /= base;
        }
    }

    // Add the null terminator
    *ptr = '\0';
    uint8_t* temp_start_ptr = start_ptr;
    // Reverse the string (excluding the possible negative sign)
    if (data < 0)
    {
        temp_start_ptr++; // Move past the negative sign
    }

    // Perform a simple in-place string reversal
    uint8_t* end_ptr = ptr - 1;
    while (temp_start_ptr < end_ptr)
    {
        uint8_t temp = *temp_start_ptr;
        *temp_start_ptr = *end_ptr;
        *end_ptr = temp;
        temp_start_ptr++;
        end_ptr--;
    }

    /*uint8_t* trying = start_ptr;

    while(trying<ptr)
    {
        printf("%d\t" , *trying);
        printf("%c\t" , *trying);
        trying++;
    }*/

    // Calculate and return the length of the converted data (including null terminator)
    return (uint8_t)(ptr - start_ptr + 1);
}



int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base)
{
    if (ptr == 0 || base < 2 || base > 16)
    {
        // Invalid input or unsupported base
        return 0;
    }

    int32_t result = 0;
    int32_t sign = 1;

    // Check for a negative sign
    if (*ptr == '-')
    {
        sign = -1;
        ptr++;
    }

    // Convert the ASCII string to an integer
    while (digits > 0 && *ptr != '\0')
    {
        uint8_t digit = *ptr;
        //printf("%d\n" , digit);
        int32_t value;

        if (digit >= '0' && digit <= '9')
        {
            value = digit - '0';
        }
        else if (digit >= 'A' && digit <= 'F')
        {
            value = 10 + (digit - 'A');
        }
        else if (digit >= 'a' && digit <= 'f')
        {
            value = 10 + (digit - 'a');
        }
        else
        {
            // Invalid character encountered
            return 0;
        }

        if (value >= base)
        {
            // Digit out of range for the specified base
            return 0;
        }

        result = result * base + value;
        ptr++;
        digits--;
    }

    return result * sign;
}
