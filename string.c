#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

/**
  *print_S - Prints a string
  *@count: The number of character printed
  *@args: The va_list of arguments
  *@buffer: The buffer to write to
  *@buf_size: The size of buffer
  */
void print_S(va_list args, int *count, char *buffer)
{
	char *str = va_arg(args, char *);
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 32 && str[i] < 127)
		{
			if (*count >= BUF_SIZE - 1)
				break;
			buffer[(*count)++] = str[i];
		} else
		{
			if (*count >= BUF_SIZE - 4)
				break;
			buffer[(*count)++] = '\\';
			buffer[(*count)++] = 'x';
			buffer[(*count)++] = "0123456789ABCDEF"
				[str[i] / 16];
			buffer[(*count)++] = "0123456789ABCDEF"
				[str[i] % 16];
		}
	}
	if (*count >= BUF_SIZE - 1)
	{
		write(1, buffer, *count);
		*count = 0;
	}
}
