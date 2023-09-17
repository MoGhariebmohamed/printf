#include "main.h"

/**
 * int_printf - Append an integer to a character buffer.
 *
 * This function converts an integer to a string representation and
 * appends it to the output buffer.
 *
 * @param count: Current count of characters in the buffer.
 * @param buffer: The character buffer to append to.
 * @param buffer_index: Pointer to the current index in the buffer.
 * @param num: The integer to append to the buffer.
 *
 * @return: The updated count of characters in the buffer.
 */
int int_printf(int count, char buffer[], int *buffer_index, int num) {
    char num_buffer[12]; 
    int num_length = snprintf(num_buffer, sizeof(num_buffer), "%d", num);
    int i;
    for (i = 0; i < num_length; i++) {
        buffer[(*buffer_index)++] = num_buffer[i];
        count++;
    }

    return count;
}

