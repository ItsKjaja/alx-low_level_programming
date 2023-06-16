#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * get_dnodeint_at_index - return node at specific index
 * @head: head
 * @index: index
 * Return: node
 */



dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	while (head && index--)
	{
		head = head->next;
	}
	return (head);
}
