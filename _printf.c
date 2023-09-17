#include <stdarg.h>
#include <unistd.h>


/**
* _printf - is a function that do the same functions as print.
*@format: identifier to look for.
*
*Return:  the length of the string.
**/

int _printf(const char *format, ...) {
    va_list args;
    char buffer[1024];
    int count = 0;
    int buffer_index = 0;

    va_start(args, format);

    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c': {
                    char c = va_arg(args, int);
                    buffer[buffer_index++] = c;
                    count++;
                    break;
                }
                case 's': {
                    const char *str = va_arg(args, const char *);
                    while (*str) {
                        buffer[buffer_index++] = *str;
                        str++;
                        count++;
                    }
                    break;
                }
                case '%':
                    buffer[buffer_index++] = '%';
                    count++;
                    break;
                default:
                    buffer[buffer_index++] = '%';
                    count++;
                    break;
            }
        } else {
            buffer[buffer_index++] = *format;
            count++;
        }
        format++;
    }

    va_end(args);

    if (buffer_index > 0) {
        write(1, buffer, buffer_index);
    }

    return count;
}

