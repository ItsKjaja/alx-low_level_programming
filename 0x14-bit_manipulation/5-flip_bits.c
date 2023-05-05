#include "main.h"


/**
 * flip_bits - number of bits needed to covert number
 * @n: first number
 * @m: second number
 * Return: the number of different bits between first number and second number
 */



unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int dif;
        int count = 0;
	dif = n ^ m;

       while (dif != 0)
{
	count += dif & 1;
	dif = dif >> 1;
}

return (count);
	}
