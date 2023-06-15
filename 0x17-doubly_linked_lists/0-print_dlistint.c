#include <stdio.h>
#include "lists.h"


/**
 * print_dlistint - print dbly linked list
 * @h: head
 * Return: number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t num_node = 0;

	if (!h)
		return (0);
	while (h)
	{
		num_node++;
		printf("%d\n", h->n);
		h = h->next;

	}


	return (num_node);
}
