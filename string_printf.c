#include "main.h"

/**
 *string_printf - Append a string to a character buffer.
 *
 *@count: Current count of characters in the buffer.
 *@buffer: The character buffer to append to.
 *@buffer_index: Pointer to the current index in the buffer.
 *@str: The string to append to the buffer.
 *
 *Return: The updated count of characters in the buffer.
 */
int string_printf(int count, char buffer[], int *buffer_index, const char *str)
{
	while (*str)
	{
		buffer[(*buffer_index)++] = *str;
		str++;
		count++;
	}
	return (count);
}
