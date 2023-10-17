#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"

/**
 * scan_format - print the formatted output
 * @format: the format string
 * @args: the va_list of arguments
 * @count: the number of characters printed
 * @buffer: the buffer to write to
 */
void scan_format(const char *format, va_list args, int *count, char buffer[])
{

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			conv_specifier(*format, args, count, buffer);
		}
		else
		{
			if (*count >= BUF_SIZE)
			{
				write(1, buffer, BUF_SIZE);
				*count = 0;
			}
			buffer[(*count)++] = *format;
		}
		format++;
	}
}
