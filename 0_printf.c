#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - A simplified version of printf that handles 'c', 's', 'd', 'i', and '%' specifiers.
 *
 * @format: The format string.
 * @...: Variable number of additional arguments.
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int count = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == 'c')
			{
				char c = va_arg(args, int);
				_putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				const char *str = va_arg(args, const char *);
				while (*str != '\0')
				{
					_putchar(*str);
					str++;
					count++;
				}
			}
			else if (*format == '%')
				{
				_putchar('%');
				count++;
				}
				else
				{
				}
		}
		else
		{
			_putchar(*format);
			count++;
		}

		format++;
	}

	va_end(args);
	return count;
}

int main()
{
	int printed = _printf("This is a test: %c, %s, %%\n", 'A', "Hello, World!");
	printf("Number of characters printed: %d\n", printed);
	return 0;
}

