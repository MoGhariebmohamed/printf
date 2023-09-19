#include "main.h"

/**
 * oct_printf - Append an octal representation of an unsigned integer to a character buffer.
 *
 * @count: Current count of characters in the buffer.
 * @buffer: The character buffer to append to.
 * @buffer_index: Pointer to the current index in the buffer.
 * @args: The variable argument list.
 *
 * Description: This function appends an octal representation of an unsigned integer
 * to the output buffer.
 *
 * Return: The updated count of characters in the buffer.
 */
int oct_printf(int count, char buffer[], int *buffer_index, va_list args) {
    unsigned int num = va_arg(args, unsigned int);
    char num_buffer[12];
    int num_length = 0;
    int i, j;
    char temp;

    if (num == 0) {
        num_buffer[num_length++] = '0';
    } else {
        while (num > 0) {
            num_buffer[num_length++] = '0' + (num % 8);
            num /= 8;
        }

        for (i = 0, j = num_length - 1; i < j; i++, j--) {
            temp = num_buffer[i];
            num_buffer[i] = num_buffer[j];
            num_buffer[j] = temp;
        }
    }

    for (i = 0; i < num_length; i++) {
        buffer[(*buffer_index)++] = num_buffer[i];
        count++;
    }

    return count;
}
