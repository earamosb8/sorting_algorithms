#include "sort.h"
/**
 * insertion_sort_list - sort a list with insertion sort
 * @list: list with elements by sort
 **/
void insertion_sort_list(listint_t **list)
{
	listint_t  *left, *right, *tmp2, *tmp, *head;

	if (list == NULL || *list == NULL)
		return;
	head = *list;
	while (head)
	{left = head->prev, right = head, tmp = head;
		while (tmp && tmp->prev)
		{left = tmp->prev, right = tmp;
			if (left->n > right->n)
			{
				if (left->prev == NULL && right->next == NULL)
				{
					left->next = NULL, right->prev = NULL;
					left->prev = right, right->next = left;
				}
				else if (right->next == NULL)
				{
					left->prev->next = right, right->prev = left->prev;
					left->next = NULL, right->next = left, left->prev = right;
				}
				else if (left->prev == NULL)
				{
					right->prev = NULL, left->next = right->next, right->next->prev = left;
					right->next = left, left->prev = right, *list = right;
				}
				else
				{
					left->prev->next = right, right->prev = left->prev;
					left->next = right->next, right->next->prev = left;
					right->next = left, left->prev = right;
				}
				print_list(*list), tmp2 = left, left = right, right = tmp2;
			}
			else
				break;
			tmp = right, tmp = tmp->prev;
		}
		head = tmp, head = head->next;
	}
}
