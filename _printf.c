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
	int count = 0;
	int buffer_index = 0, i = 0;

	formatH format_handlers[] = {
		{'c', char_printf}, {'s', string_printf},
		{'d', int_printf}, {'i', int_printf},
		{'u', uint_printf}, {'o', oct_printf},
		{'x', hex_printf}, {'X', hex_upper_printf},
		{'b', bin_printf}, {'\0', NULL}
	};
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			i = 0;
			while (format_handlers[i].specifier != '\0')
			{
				if (format_handlers[i].specifier == *format)
				{
					count = format_handlers[i].handler(count, buffer, &buffer_index, args);
					break;
				}
				i++;
			}
			if (format_handlers[i].specifier == '\0')
			{
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
	return (count);
}
