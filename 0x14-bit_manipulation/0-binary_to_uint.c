#include "main.h"

#include "main.h"

/**
 * binary_to_uint -  converts a binary number to an unsigned int
 *  @b: string of binary
 *  Return: the converted number, or 0 if is NULL
*/

unsigned int binary_to_uint(const char *b)
{
	unsigned int a = 0, i;

	if (!b)
		return (0);
	for (i = 0; *(b + i); i++)
	{
		a = a << 1;
		if (*(b + i) == '1')
			a = a | 1;
		else if (*(b + i) != '0')
			return (0);
	}
	return (a);
}
