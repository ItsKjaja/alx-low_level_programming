#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * hash_table_set - add node to hash table
 * @ht: pointer to hash table
 * @key: key
 * @value: value
 * Return: 1 in success 0 in failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *curr_node, *new_node;
	unsigned long int index;

	if (ht == NULL || *key == '\n' || *value == '\n')
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	curr_node = ht->array[index];

	if (!curr_node)
	{
	new_node = (hash_node_t *)malloc(sizeof(hash_node_t));
	if (!new_node)
		return (0);
	new_node->value = strdup(value);
	new_node->key = strdup(key);
	new_node->next = NULL;
	ht->array[index] = new_node;
	return (1);
	}
	while (curr_node)
	{

	       if (strcmp(key, curr_node->key) == 0)
	       {
	       free(curr_node->value);
		curr_node->value = strdup(value);
		return (1);
	      }

	      curr_node = curr_node->next;
       }
       new_node = (hash_node_t *)malloc(sizeof(hash_node_t));
       if (!new_node)
       return (0);
       new_node->value = strdup(value);
       new_node->key = strdup(key);
       new_node->next = ht->array[index];
       ht->array[index] = new_node;
       return (1);
}
