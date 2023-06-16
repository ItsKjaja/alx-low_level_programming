#include "lists.h"
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - inserts a new node in a dlistint_t list.
 * at a given position
 * @head: the pointer to the head of the dlistint_t list.
 * index: the position to insert the new node
 * @n: the integer for the new node to contain.
 *
 * Return: NULL in faillure otherwise the address of the new node.
 *
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **head, unsigned int index, int n)
{
	dlistint_t *tmp = *head, *new;

	if (index == 0)
		return (add_dnodeint(head, n));

	for (; index != 1; index--)
	{
		tmp = tmp->next;
		if (tmp == NULL)
			return (NULL);
	}

	if (tmp->next == NULL)
		return (add_dnodeint_end(head, n));

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = tmp;
	new->next = tmp->next;
	tmp->next->prev = new;
	tmp->next = new;

	return (new);
}
