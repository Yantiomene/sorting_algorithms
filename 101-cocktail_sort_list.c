#include "sort.h"

/**
 * swap_node - swap node to the right
 * @list: pointer to the head of the list
 * @a: first node
 * @b: second node
 *
 * Return - nothing
 */
void swap_node(listint_t **list, listint_t *a, listint_t *b)
{
	b->prev = a->prev;
	a->next = b->next;
	if (b->next)
		(b->next)->prev = a;
	if (a->prev)
		(a->prev)->next = b;
	a->prev = b;
	b->next = a;
	if (!b->prev)
		*list = b;
	print_list(*list);
}

/**
 * cocktail_sort_list - sorts a doubly linked list in ascending order
 * @list: pointer to the head of the list
 *
 * Return: nothing
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *ptr, *curr, *left, *right;
	int swap;

	if (!list || !*list || !(*list)->next)
		return;
	ptr = *list;
	do {
		swap = 0;
		while (ptr->next)
		{
			curr = ptr;
			if (curr->n > curr->next->n)
			{
				right = curr->next;
				swap_node(list, curr, right);
				swap = 1;
				continue;
			}
			ptr = ptr->next;
		}
		if (swap == 0)
			break;
		swap = 0;
		while (ptr->prev)
		{
			curr = ptr;
			if (curr->n < curr->prev->n)
			{
				left = curr->prev;
				swap_node(list, left, curr);
				swap = 1;
				continue;
			}
			ptr = ptr->prev;
		}
	} while (swap == 1);
}
