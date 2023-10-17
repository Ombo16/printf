#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * conv_specifier - handle a single conversion specifier
 * @specifier: the specifier character
 * @args: the va_list of arguments
 * @buffer: the output buffer
 * @count: the number of characters printed
 */

void conv_specifier(char specifier, va_list args, int *count, char buffer[])
{

	specifier_t specifiers[] = {
		{'c', &print_char},
		{'S' , &print_S},
		{'s', &print_string},
		{'d', &print_integer},
		{'i', &print_integer},
		{'b', &print_binary},
		{'o', &print_octal},
		{'u', &print_unsigned},
		{'x', &print_hex},
		{'X', &print_hex_upper},
		{'%', &print_percent},
		{'\0', NULL}
	};
	int i;

	for (i = 0; specifiers[i].specifier != '\0'; i++)
	{
		if (specifier == specifiers[i].specifier)
		{
			specifiers[i].print_func(args, count, buffer);
			break;
		}
	}
}
