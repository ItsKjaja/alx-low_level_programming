#include "main.h"
/**
 * _strncpy - copy n character of string from src to dest
 * @dest: pointer to dest memory
 * @src: pointer to string
 * @n: number of byte
 * Return: pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	for (; i < n; i++)
		dest[i] = '\0';
	return (dest);
}

