#include "main.h"
/**
 * _memcpy - copies n byte fromsrc to dest
 * @dest: pointer to dest memory
 * @src: pointer to src memory
 * @n: number of bytes
 * Return: pointer to dest memory
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
