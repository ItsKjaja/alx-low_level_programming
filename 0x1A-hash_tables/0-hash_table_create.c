#include "hash_tables.h"
#include <stdlib.h>


/**
 * hash_table_create - create hash table
 * @size: size of hash table
 * Return: pointer to hash_table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new_hash_table;

	new_hash_table = (hash_table_t *)malloc(sizeof(hash_table_t));

	if (new_hash_table == NULL)
		return (NULL);
	new_hash_table->array = (hash_node_t **)malloc(size * sizeof(hash_node_t *));

	if (new_hash_table->array == NULL)
		return (NULL);
	new_hash_table->size = size;

	return (new_hash_table);
}
