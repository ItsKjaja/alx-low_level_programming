#include "main.h"


/**
 * set_bit it sets the value of a bit to 1 at such index given.
 * @n: pointer to set
 * @index: which to set the bit.
 *
 * Return: 1 if it worked,  -1 in error case.
 */

int set_bit(unsigned long int *n, unsigned int index)

{
	unsigned long int set_a_bit;


	if (index > (sizeof(unsigned long int) *8 - 1))
		return (-1);

	set_a_bit = 1 << index;
	*n = *n | set_a_bit;
	return (1);

}
