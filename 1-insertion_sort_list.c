#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list
 * @list: pointer to the head of the list
 *
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ptr, *curr, *left_top;

	if (!*list || !(*list)->next)
		return;
	ptr = (*list)->next;
	while (ptr)
	{
		left_top = ptr;
		while (left_top->prev && (left_top->prev)->n > left_top->n)
		{
			curr = left_top->prev;
			curr->next = left_top->next;
			left_top->prev = curr->prev;

			if (curr->prev)
				(curr->prev)->next = left_top;
			if (left_top->next)
				(left_top->next)->prev = curr;

			left_top->next = curr;
			curr->prev = left_top;

			if (!left_top->prev)
				*list = left_top;

			print_list(*list);

		}
		ptr = ptr->next;
	}
}
