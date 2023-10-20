#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"
#include "check_format"
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
int _printf(const char *format, ...) {
	va_list args;
	va_start(args, format);

	int count = 0;  // To keep track of the number of characters printed.

	while (*format != '\0') {
		if (*format == '%') {
			format++; // Move past the '%'
			if (*format == '\0') // Handle a '%' at the end of the format string.
				break;
			if (*format == 'c') {
				// Handle character
				char c = va_arg(args, int);
				write(1, &c, 1); // Write the character to stdout
				count++;
			} else if (*format == 's') {
				// Handle string
				const char *str = va_arg(args, const char *);
				while (*str != '\0') {
					write(1, str, 1); // Write each character of the string to stdout
					str++;
					count++;
				}
			} else if (*format == 'd' || *format == 'i') {
				// Handle decimal or integer
				int num = va_arg(args, int);
				dprintf(1, "%d", num); // Print the number to stdout
				count++;
			} else if (*format == '%') {
				// Handle '%' character
				write(1, "%", 1); // Write '%' to stdout
				count++;
			}
		} else {
			// Handle regular characters
			write(1, format, 1); // Write the character to stdout
			count++;
		}

		format++;
	}

	va_end(args);
	return count;
}
