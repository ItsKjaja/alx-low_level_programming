#include "main.h"

/**
 * _strlen - return length of string 
 * @s: string
 * Return: length
 */

int _strlen(char *s)
{
	int count = 0;
	int i;
	for (i = 0; s[i] != '\0'; i++)
		count++;
	return (count);
}
