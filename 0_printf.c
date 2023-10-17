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
int _printf(const char *format, ...) {
	va_list args;
	int count = 0;
	char c;
	const char *str;
	int num;
	va_start(args, format);

	while (*format != '\0') {
		if (*format == '%') {
			format++;
			if (*format == '\0')
				break;
			if (*format == 'c') {
				char c = va_arg(args, int);
				write(1, &c, 1);
				count++;
			} else if (*format == 's') {
				const char *str = va_arg(args, const char *);
				while (*str != '\0') {
					write(1, str, 1);
					str++;
					count++;
				}  else if (*format == 'd' || *format == 'i') {
					int num = va_arg(args, int);
					fprintf(stdout, "%d", num);
					count++;
					} else if (*format == '%') {
						write(1, "%", 1);
						count++;
			}
		} else {
			write(1, format, 1);
			count++;
		}

		format++;
	}

	va_end(args);
	return (count);
}

int main() {
	int printed = _printf("This is a test: %c, %s, %%\n", 'A', "Hello, World!");
	printf("Number of characters printed: %d\n", printed);
	return (0);
}
