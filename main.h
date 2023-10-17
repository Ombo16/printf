#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#define UNUSED(x) (void)(x)
#define BUF_SIZE 1024

int _printf(const char *format, ...);
int _putchar(char c);
void scan_format(const char *format, va_list args, int *count, char buffer[]);
void conv_specifier(char specifier, va_list args, int *count, char buffer[]);

#endif
