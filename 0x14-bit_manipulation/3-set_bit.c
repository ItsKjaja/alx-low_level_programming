#include "main.h"

/**
 * set_bit - sets a bit to 1 at an index given
 * @n: pointer of an unsigned long int.
 * @index: index of the bit
 *
 *
 * Return: 1 if it worked,-1 if not;
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int m, i;

		m = (sizeof(unsigned long int) * 8) - 1;
	if (index > m)
		return (-1);
	i = 1 << index;
	*n = *n | i;
	return (1);
}
