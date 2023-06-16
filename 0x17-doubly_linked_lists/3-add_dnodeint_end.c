#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint_end - add node at the end of doubly linked list
 * @head: head
 * @n: value
 * Return: node
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *node;
	dlistint_t *tmp;

	node = (dlistint_t *) malloc(sizeof(dlistint_t));
	if (!node)
		return (NULL);
	node->n = n;
	tmp = *head;
	if (!tmp)
	{
		(*head) = node;
		return (node);
	}
	while (tmp->next)
		tmp = tmp->next;
	node->prev = tmp;
	tmp->next = node;

	return (node);
}
