#include "lists.h"
#include "stdio.h"

/**
 * print elements of linked list
 * @h:header of the list
 *
 * Return: te numbers of nodes
 */
   size_t prin_ listint(const listint_t *h)

{	size_t count_nodes = 0;
	const listint_t *current = h;

	while
	      
	      (current != NULL)
	      {
		      printf ("%i\n", current->n);
                     current = current->next;
                      count_nodes++;
	      }
	return count_nodes;
}
	

