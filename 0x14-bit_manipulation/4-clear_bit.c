#include "main.h"


/**
 * clear_bit - sets the value of a bit to 0.
 * at a given index.
 * @n: pointer of an unsigned long int.
 * @index: index of the bit.
 *
 * Return: 1 if success, -1 if it didn't
 */

int clear_bit(unsigned long int *n, unsigned int index)

{
	unsigned long int m;

	if (!n)
		return (-1);
	m = (sizeof(unsigned long int) * 8) - 1;

	if (index > m)
		return (-1);
	m = 1 << index;
	if ((m | *n) == *n)
		*n = *n ^ m;
	return (1);
}
