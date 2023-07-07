#include "hash_tables.h"
#include <stdlib.h>

/**
 * key_index - return index for key
 * @key: key to hash it
 * @size: size of hash table
 * Return: index
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int index = hash_djb2(key) % size;

	return (index);
}
