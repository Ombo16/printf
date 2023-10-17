#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - A simplified version of printf that
 * handles 'c', 's', 'd', 'i', and '%' specifiers.
 *
 * @format: The format string.
 * @...: Variable number of additional arguments.
 *
 * Return: The number of characters printed
 * (excluding the null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
	int count  = 0;
	va_list args;
	char buffer[BUF_SIZE];

	va_start(args, format);

	if (format == NULL)
		return (-1);

	check_format(format, args, &count, buffer);

	if (count > 0)
		write(1, buffer, count);

	va_end(args);
	return (count);
}
