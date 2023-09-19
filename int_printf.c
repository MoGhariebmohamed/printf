#include "main.h"

/**
 * int_printf - Append an integer to a character buffer.
 * @count: Current count of characters in the buffer.
 * @buffer: The character buffer to append to.
 * @buffer_index: Pointer to the current index in the buffer.
 * @args: The variable argument list.
 *
 * Description: This function converts an integer to a string representation and
 * appends it to the output buffer.
 *
 * Return: The updated count of characters in the buffer.
 */
int int_printf(int count, char buffer[], int *buffer_index, va_list args)
{
    int num = va_arg(args, int);
    char num_buffer[12];
    int num_length = snprintf(num_buffer, sizeof(num_buffer), "%d", num);

    for (int i = 0; i < num_length; i++) {
        buffer[(*buffer_index)++] = num_buffer[i];
        count++;
    }

    return count;
}

}
