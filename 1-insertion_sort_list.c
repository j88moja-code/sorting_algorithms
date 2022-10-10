#include "sort.h"

/**
  * swap_nodes - Swaps 2 nodes in a listint_t linked list.
  *
  * @h: double pointer to the head of the linked list.
  * @n1: double pointer to the first node to swap.
  * @n2: pointer to the second node to swap.
  */

static void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
  * insertion_sort_list - sorts a linked list of ints using the insertion
  * sort algorithm.
  *
  * @list: double pointer to the head of a linked list of integers.
  *
  * Return: nothing.
  */

void insertion_sort_list(listint_t **list)
{
	listint_t *x, *y, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (x = (*list)->next; x != NULL; x = tmp)
	{
		tmp = x->next;
		y = x->prev;
		while (y != NULL && x->n < y->n)
		{
			swap_nodes(list, &y, x);
			print_list((const listint_t *)*list);
		}
	}
}
