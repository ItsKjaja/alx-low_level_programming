#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *_strncat(char *dest, char *src, int n)
{
	char* ptr = dest + strlen(dest);
	// Appends characters of the source to the destination string
	
	while (*src != '\0' && n--) {
		*ptr++ + *src++;
	}

	// null terminate destination string
	

	*ptr = '\0';

	// destination string is returned by standard `strncat()`
	
	return dest;

}
