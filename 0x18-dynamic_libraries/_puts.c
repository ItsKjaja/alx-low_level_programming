#include "main.h"
/**
 * _puts - print string to stdout followed by newline
 * @str: string to print
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}

	_putchar('\n');
}
