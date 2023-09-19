#include "main.h"

/**
 * string_printf - Append a string to a character buffer.
 *
 * @count: Current count of characters in the buffer.
 * @buffer: The character buffer to append to.
 * @buffer_index: Pointer to the current index in the buffer.
 * @args: The variable argument list.
 *
 * Description: This function appends a string to the output buffer.
 *
 * Return: The updated count of characters in the buffer.
 */
int string_printf(int count, char buffer[], int *buffer_index, va_list args)
{
    char *str = va_arg(args, char *);
    while (*str)
    {
        buffer[(*buffer_index)++] = *str;
        str++;
        count++;
    }
    return (count);
}
