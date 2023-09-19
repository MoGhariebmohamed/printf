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
    int is_negative = 0;
    int num_length = 0;
    int i, j;
    char temp;
    if (num < 0)
    {
        is_negative = 1;
        num = -num;
    }
    do
    {
        num_buffer[num_length++] = '0' + (num % 10);
        num /= 10;
    } while (num > 0);
    if (is_negative)
    {
        num_buffer[num_length++] = '-';
    }
    for (i = 0, j = num_length - 1; i < j; i++, j--)
    {
        temp = num_buffer[i];
        num_buffer[i] = num_buffer[j];
        num_buffer[j] = temp;
    }
    for (i = 0; i < num_length; i++)
    {
        buffer[(*buffer_index)++] = num_buffer[i];
        count++;
    }
    return count;
}
