#include "main.h"


/**
 * Write a function - sets the value of a bit to 1
 * @n: pointer
 * @index: Starting from 0
 *
 * Return: 1 if it worked,  -1 in error case.
 */

int set_bit(unsigned long int *n, unsigned int index)

{
	unsigned long int set_bit;


	if (index > (sizeof(unsigned long int) *8 - 1))
		return (-1);

	set_bit = 1 << index;
	*n = *n | set_bit;
	return (1);

}
