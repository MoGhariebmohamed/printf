#include "main.h"
/**
 *_printf - Custom printf function.
 *description: This function formats and prints a string to standard output.
 *@format: The format string with optional format specifiers.
 *Return: number characters printed(excluding the null terminator),or -1 error
 */
int _printf(const char *format, ...)
{
	va_list args;
	char buffer[1024];
	int count = 0, buffer_index = 0;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'c':
				count = char_printf(count, buffer, &buffer_index, va_arg(args, int));
				break;
			case 's':
				count = string_printf(count, buffer, &buffer_index,va_arg(args, const char *));
				break;
			case 'd':
			case 'i':
				count = int_printf(count, buffer, &buffer_index, va_arg(args, int));
				break;
			case '%':
				buffer[buffer_index++] = '%';
				count++;
				break;
			default:
				buffer[buffer_index++] = '%';
				count++;
				break;
			}
		}
		else
		{
			buffer[buffer_index++] = *format;
			count++;
			if (buffer_index > 0)
			{
				write(1, buffer, buffer_index);
				buffer_index = 0;
			}
		}
		format++;
	}
	va_end(args);
	if (buffer_index > 0)
		write(1, buffer, buffer_index);
	return (count);
}
