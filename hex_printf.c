#include "main.h"
/**
 * hex_printf - Append a hexadecimal representation of an unsigned integer to a character buffer.
 *
 * @count: Current count of characters in the buffer.
 * @buffer: The character buffer to append to.
 * @buffer_index: Pointer to the current index in the buffer.
 * @args: The variable argument list.
 *
 * Description: This function appends a hexadecimal representation of an unsigned integer
 * to the output buffer.
 *
 * Return: The updated count of characters in the buffer.
 */
int hex_printf(int count, char buffer[], int *buffer_index, va_list args) {
    unsigned int num = va_arg(args, unsigned int);
    char num_buffer[12];
    int num_length = 0;
    int i, j;

    if (num == 0) {
        num_buffer[num_length++] = '0';
    } else {
        while (num > 0) {
            int remainder = num % 16;
            if (remainder < 10) {
                num_buffer[num_length++] = '0' + remainder;
            } else {
                num_buffer[num_length++] = 'a' + (remainder - 10);
            }
            num /= 16;
        }

        for (i = 0, j = num_length - 1; i < j; i++, j--) {
            char temp = num_buffer[i];
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
