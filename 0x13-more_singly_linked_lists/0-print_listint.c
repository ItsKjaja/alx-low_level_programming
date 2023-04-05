#include "lists.h"


/**
 * print elements of linked list
 * @h:header of the list
 *
 * Return: the numbers of nodes
 */


size_t print_listint(const listint_t *h)
{
	const listint_t *cursor = h;
	size_t count = 0;

	while (cursor != NULL)
	{
		printf("%d\n", cursor->n);
		count += 1;
		cursor = cursor->next;
	}
	return (count);
}
