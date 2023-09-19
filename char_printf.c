#include "main.h"
/**
 *char_printf - Append a character to a character buffer.
 *
 *@count: Current count of characters in the buffer.
 *@buffer: The character buffer to append to.
 *@buffer_index: Pointer to the current index in the buffer.
 *@c: The character to append to the buffer.
 *
 *Return: The updated count of characters in the buffer
 */
int char_printf(int count, char buffer[], int *buffer_index, char c)
{
	buffer[(*buffer_index)++] = c;
	return (++count);
}
