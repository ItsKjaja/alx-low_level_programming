#include "main.h"

#include "main.h"

/**
 *  converts a binary number to an unsigned int
 *  @b: string
 *  Return: the converted number, or 0 if
there is one or more chars in the string b that is not 0 or 1
b is NULL
*/

unsigned int binary_to_uint(const char *b)
{
	unsigned int a = 0, i;

	if (!b)
		return (0);
	for (i = 0; *(b + i); i++)
	{
		a = a << 1;
		if (*(b +i) == '1')
			a = a | 1;
		else if (*(b +i) != '0')
			return (0);
	}
	return (a);
}
