#include "main.h"

/**
 * _strchr - locates a character in a string.
 * @s: pointer to string
 * @c: character
 * Return: pointer to char
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		s++;
		

		if (*s == c)
			return (s);
	}
	return (0);
}
