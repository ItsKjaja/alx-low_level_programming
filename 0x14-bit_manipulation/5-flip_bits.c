#include "main.h"


/**
 * flip_bits - number of bits needed to covert number
 * @n: first number
 * @m: second number
 * Return: the number of different bits between first number and second number
 */



unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int dif = 0;


	while (n || m)
	{
		if ((n & 1) != (m & 1))
			dif++;
		m = m >> 1;
		n = n >> 1;
	}
	return (dif);
}		
