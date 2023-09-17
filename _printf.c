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
    int count = 0;

    va_start(args, format);

    while (*format) {
        if (*format == '%') {
            format++; // Move past '%'

            // Handle conversion specifiers
            switch (*format) {
                case 'c': {
                    char c = va_arg(args, int); // char is promoted to int
                    write(1, &c, 1); // Write the character to stdout
                    count++;
                    break;
                }
                case 's': {
                    const char *str = va_arg(args, const char *);
                    while (*str) {
                        write(1, str, 1); // Write each character to stdout
                        str++;
                        count++;
                    }
                    break;
                }
                case '%':
                    write(1, "%", 1); // Write '%' to stdout
                    count++;
                    break;
                default:
                    write(1, "%", 1); // Write '%' to stdout if not recognized
                    count++;
                    break;
            }
        } else {
            write(1, format, 1); // Write non-format characters to stdout
            count++;
        }
        format++;
    }

    va_end(args);

    return count;
}
