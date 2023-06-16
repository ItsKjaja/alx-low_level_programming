#include <stdlib.h>
#include "lists.h"



/**
 * delete_dnodeint_at_index - delete node in a given index
 * @h: head
 * @idx: index
 * Return: 1 in success otherwise -1
 */

int delete_dnodeint_at_index(dlistint_t **h, unsigned int idx)

{
	dlistint_t *lis;

	if (!(*h))
		return (-1);
	if (idx == 0)
	{
		lis = (*h);
		(*h) = lis->next;
		(lis->next)->prev = NULL;
		free(lis);
		return (1);
	}
	lis = (*h);
	while (lis && idx--)
	{
		lis = lis->next;
	}
	if (!lis)
		return (-1);
	if (!lis->next)
	{
		(lis->prev)->next = NULL;
		free(lis);
		return (1);
	}

	(lis->prev)->next = lis->next;
	(lis->next)->prev = lis->prev;
	free(lis);
	return (1);
}
