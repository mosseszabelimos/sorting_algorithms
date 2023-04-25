#include "sort.h"


/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort
 * @list: Pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *left, *right;

	if (!list || !*list || !(*list)->next)
		return;

	left = *list, right = NULL;
	while (swapped)
	{
		swapped = 0;
		while (left->next && left->next != right)
		{
			if (left->n > left->next->n)
			{
				swap_nodes(list, left, left->next);
				print_list((const listint_t *)*list);
				swapped = 1;
			}
			else
				left = left->next;
		}

		if (!swapped)
			break;

		right = left, left = left->prev;
		swapped = 0;
		while (left->prev && left->prev != right)
		{
			if (left->n < left->prev->n)
			{
				swap_nodes(list, left->prev, left);
				print_list((const listint_t *)*list);
				swapped = 1;
			}
			else
				left = left->prev;
		}
		right = left;
	}
}


/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the doubly linked list
 * @left: Pointer to the first node
 * @right: Pointer to the second node
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (left->prev)
		left->prev->next = right;
	else
		*list = right;

	if (right->next)
		right->next->prev = left;

	left->next = right->next;
	right->prev = left->prev;
	right->next = left;
	left->prev = right;
}

