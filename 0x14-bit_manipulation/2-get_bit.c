#include "main.h"

/**
 * get_bit - returns the value of a bit at an index gived
 * @n: insigned int input
 * @index: index to find bit at
 * Return: value of the bit.
 *
 */

int get_bit(unsigned long int n, unsigned int index)

{
	unsigned int i, m = 1;

	i = (sizeof(unsigned long int) * 8) - 1;
	if (n == 0)
		return (0);
	m = m << index;
	if (index > i)
		return (-1);
	if (m & n)
		return (1);
	else
		return (0);
}

