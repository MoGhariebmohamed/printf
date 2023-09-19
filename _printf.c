#include "main.h"

/**
 * _printf - Custom printf function with support for format specifiers.
 *
 * @format: The format string.
 *
 * Description: This function formats and prints data to the standard output
 * according to a format specifier.
 *
 * Return: The number of characters printed, or -1 on error.
 */
int _printf(const char *format, ...)
{
    va_list args;
    char buffer[1024];
    int count = 0;
    int buffer_index = 0;
    int i = 0;

    if (format == NULL || (format[0] == '%' && format[1] == '\0'))
        return (-1);

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            i=0;
            while (format_handlers[i].specifier != '\0') {
                if (format_handlers[i].specifier == *format) {
                    count = format_handlers[i].handler(count, buffer, &buffer_index, args);
                    break;
                }
                i++;
            }

            if (format_handlers[i].specifier == '\0') {
                buffer[buffer_index++] = *format;
                count++;
            }
        }
        else
        {
            buffer[buffer_index++] = *format;
            count++;
        }

        if (buffer_index > 0)
        {
            write(1, buffer, buffer_index);
            buffer_index = 0;
        }

        format++;
    }

    va_end(args);

    if (buffer_index > 0)
    {
        write(1, buffer, buffer_index);
    }

    return count;
}

