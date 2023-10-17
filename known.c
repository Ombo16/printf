#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * print_string - print a string
 * print_char - print a single character
 * print_percent - print a percent character
 * print_integer - print a decimal integer
 * print_binary - print an unsigned integer in binary
 * @args: the va_list of arguments
 * @buffer: the buffer to store the output
 * @count: the number of characters printed
 */

void print_string(va_list args, int *count, char buffer[])
{
	char *str = va_arg(args, char *);
	int i;

	if (!str)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
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

void print_char(va_list args, int *count, char buffer[])
{
	char char_arg = va_arg(args, int);

	if (*count >= BUF_SIZE)
	{
		write(1, buffer, BUF_SIZE);
		*count = 0;
	}
	buffer[(*count)++] = char_arg;
}

void print_percent(va_list args, int *count, char buffer[])
{
	UNUSED(args);
	if (*count < BUF_SIZE - 1)
	{
		buffer[(*count)++] = '%';
	}
	else
	{
		write(1, buffer, *count);
		*count = 0;
		buffer[(*count)++] = '%';
	}
}

void print_integer(va_list args, int *count, char buffer[])
{

	int num = va_arg(args, int);
	int i = 0;
	char str[32];

	if (num < 0)
	{
		if (*count >= BUF_SIZE - 1)
			return;
		buffer[(*count)++] = '-';
		num = -num;
	}

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

void print_binary(va_list args, int *count, char buffer[])
{
	unsigned int num = va_arg(args, unsigned int);
	char str[33];
	int i = 0;

	do {
		str[i++] = (num % 2) + '0';
		num /= 2;
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
