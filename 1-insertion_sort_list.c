#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using the Insertion sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next_node, *tmp;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		next_node = current->next;
		while (current->prev && current->prev->n > current->n)
		{
			tmp = current->prev;

			if (tmp->prev)
				tmp->prev->next = current;
			else
				*list = current;

			current->prev = tmp->prev;
			tmp->next = current->next;
			if (current->next)
				current->next->prev = tmp;

			current->next = tmp;
			tmp->prev = current;
			print_list(*list);
		}

		current = next_node;
	}
}

