#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

/**
  * print_octal - print an unsigned interger in octal
  * print_hex - Print an unsigned int in hex lower case
  * print_hex_upper - Print an unsigned int in hex upper case
  * print_unsigned - Print an unsigned int
  * @args: the va_list of arguments
  * @count: the number of characters printed
  * @buffer: the buffer to write to
  */

void print_octal(va_list args, int *count, char buffer[])
{
	unsigned int num = va_arg(args, unsigned int);
	char str[32];
	int i = 0;

	do {
		str[i++] = num % 8 + '0';
		num /= 8;
	} while (num);

	while (--i >= 0)
	{
		if (*count >= BUF_SIZE - 1)
			break;

		buffer[(*count)++] = str[i];
	}

	if (*count >= BUF_SIZE - 1)
	{
		write(1, buffer, *count);
		*count = 0;
	}
}

void print_hex(va_list args, int *count, char buffer[])
{
	unsigned int num = va_arg(args, unsigned int);
	char str[32];
	int i = 0;

	do {
		str[i++] = "0123456789abcdef"[num % 16];
		num /= 16;
	} while (num != 0);

	while (--i >= 0)
	{
		if (*count >= BUF_SIZE - 1)
			break;
		buffer[(*count)++] = str[i];
	}
	if (*count >= BUF_SIZE - 1)
	{
		write(1, buffer, *count);
	}
}

void print_hex_upper(va_list args, int *count, char buffer[])
{
	unsigned int num = va_arg(args, unsigned int);
	char str[32];
	int i = 0;

	do {
		str[i++] = "0123456789abcdef"[num % 16];
		num /= 16;
	} while (num);

	while (--i >= 0)
	{
		if (*count >= BUF_SIZE - 1)
			break;
		buffer[(*count)++] = str[i];
	}
	if (*count >= BUF_SIZE - 1)
	{
		write(1, buffer, *count);
		*count = 0;
	}

}

void print_unsigned(va_list args, int *count, char buffer[])
{
	unsigned int num = va_arg(args, unsigned int);
	char str[32];
	int i = 0;

	do {
		str[i++] = (num % 10) + '0';
		num /= 10;
	} while (num);

	while (--i >= 0)
	{
		if (*count >= BUF_SIZE - 1)
			break;
		buffer[(*count)++] = str[i];
	}

	if (*count >= BUF_SIZE - 1)
	{
		write(1, buffer, *count);
		*count = 0;
	}
}
