#include "lists.h"

/**
 * sum_dlistint - Sums all data of a dlistint_t list.
 * @head: dlistint_t list's head
 *
 * Return: Sum of all the data.
 */

int sum_dlistint(dlistint_t *head)

{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
