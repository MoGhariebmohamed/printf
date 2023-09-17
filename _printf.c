#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...) {
    va_list args;
    char buffer[1024]; // Buffer to accumulate characters
    int count = 0;
    int buffer_index = 0; // Index to track the buffer position

    va_start(args, format);

    while (*format) {
        if (*format == '%') {
            format++; // Move past '%'

            // Handle conversion specifiers
            switch (*format) {
                case 'c': {
                    char c = va_arg(args, int); // char is promoted to int
                    buffer[buffer_index++] = c; // Add character to the buffer
                    count++;
                    break;
                }
                case 's': {
                    const char *str = va_arg(args, const char *);
                    while (*str) {
                        buffer[buffer_index++] = *str; // Add characters to the buffer
                        str++;
                        count++;
                    }
                    break;
                }
                case '%':
                    buffer[buffer_index++] = '%'; // Add '%' to the buffer
                    count++;
                    break;
                default:
                    buffer[buffer_index++] = '%'; // Add '%' to the buffer if not recognized
                    count++;
                    break;
            }
        } else {
            buffer[buffer_index++] = *format; // Add non-format characters to the buffer
            count++;
        }
        format++;
    }

    va_end(args);

    // Write the accumulated buffer to stdout
    if (buffer_index > 0) {
        write(1, buffer, buffer_index);
    }

    return count;
}

