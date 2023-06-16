#include <stdlib.h>
#include "lists.h"

/**
 * free_dlistint - free doubly linked list
 * @h: head
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *next;

	while (head)
	{
		next = head->next;
		free(head);
		head = next;
	}
}
