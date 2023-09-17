#include "main.h"

/**
 * string_printf - Append a string to a character buffer.
 *
 * @param count: Current count of characters in the buffer.
 * @param buffer: The character buffer to append to.
 * @param buffer_index: Pointer to the current index in the buffer.
 * @param str: The string to append to the buffer.
 *
 * @return: The updated count of characters in the buffer.
 */
int string_printf(int count, char buffer[], int *buffer_index, const char *str) {
    while (*str) {
        buffer[(*buffer_index)++] = *str;
        str++;
        count++;
    }
    return count;
}

