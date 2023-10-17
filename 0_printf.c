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
int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int count;

    count = vprintf(format, args);

    va_end(args);
    return count;
}

int main() {
    int printed = _printf("This is a test: %c, %s, %d, %i, %%\n", 'A', "Hello, World!", 42, -123);
    printf("Number of characters printed: %d\n", printed);
    return 0;
}

