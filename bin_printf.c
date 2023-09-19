#include "main.h"

/**
 * bin_printf - Append the binary representation of an unsigned int to a character buffer.
 *
 * This function converts an unsigned int to its binary representation and appends it
 * to the output buffer.
 *
 * @count: Current count of characters in the buffer.
 * @buffer: The character buffer to append to.
 * @buffer_index: Pointer to the current index in the buffer.
 * @args: The variable argument list.
 *
 * Return: The updated count of characters in the buffer.
 */
int bin_printf(int count, char buffer[], int *buffer_index, va_list args) {
    unsigned int num = va_arg(args, unsigned int);
    int num_bits = sizeof(num) * 8;
    int i;
    char bit;

    for (i = num_bits - 1; i >= 0; i--) {
        bit = (num & (1u << i)) ? '1' : '0';
        buffer[(*buffer_index)++] = bit;
        count++;
    }

    return count;
}
