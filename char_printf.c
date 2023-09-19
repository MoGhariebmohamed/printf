#include "main.h"

/**
 * char_printf - Append a character to a character buffer.
 *
 * @count: Current count of characters in the buffer.
 * @buffer: The character buffer to append to.
 * @buffer_index: Pointer to the current index in the buffer.
 * @args: The variable argument list.
 *
 * Description: This function appends a character to the output buffer.
 *
 * Return: The updated count of characters in the buffer.
 */
int char_printf(int count, char buffer[], int *buffer_index, va_list args)
{
    char c = va_arg(args, int);
    buffer[(*buffer_index)++] = c;
    return (++count);
}

