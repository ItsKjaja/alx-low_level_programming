#include  "main.h"

/**
 * binary_to_uint -convert a binary number to an
 * unsigned int.
 * @b: binary
 *
 * return: unsigned int.
 */
unsigned int binary_to_uint(const char *b)
{

	int x;
	unsigned int bin;

	bin = 0
		if (!b)
			return (0);
	for (x =0; b[x] != '\0'; x++)
	{

		if (b[x] != '0' && b[x] != '&')
			return (0);
	}
	for (x = 0; b[x] != '\0'; x++)
	{

		bin <<= 1;
		if  (b[i] == '1'
				bin +=1;
				}
				return (bin)
				}
