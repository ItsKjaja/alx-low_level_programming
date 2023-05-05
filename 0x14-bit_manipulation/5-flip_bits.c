#include "main.h"


/**
 * flip_bits - number of bits needed to covert number
 * @n: first number
 * @m: second number
 * Return: the number of different bits between first number and second number
 */



unsigned int flip_bits(unsigned long int n, unsigned long int m)

	int num_d;

	for (num_d = 0; n || m; n >>= 1, m >>= 1)

{
	if ((n & 1) != (m & 1))
		num_d++;
}
return (num_d);
}
