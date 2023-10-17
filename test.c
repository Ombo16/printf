#include "main.h"
#include <stdio.h>

int main(void)
{	
	int len = 1;
	int len2 = 2;
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	len = _printf("Percent:[%%]\n");	
	len2 = printf("Percent:[%%]\n");
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	_printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
	return 0;
}
