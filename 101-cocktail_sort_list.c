#include "sort.h"
#include <stdlib.h>

void swap_list(listint_t *curr, listint_t *prev, listint_t **head);

/**
 * cocktail_sort_list - Applies the Cocktail Sort algorithm to sort a Doubly Linked List.
 * @list: The Doubly Linked List to be sorted.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *cur;
	listint_t *max = NULL;
	listint_t *min = NULL;

	if (!list || !(*list) || (*list)->next == NULL)
		return;
	cur = *list;
	do {
		while (cur->next)
		{
			if (cur->n > cur->next->n)
				swap_list(cur->next, cur, list);
			else
				cur = cur->next;
		}
		max = cur;
		while (cur->prev != min)
		{
			if (cur->n < cur->prev->n)
				swap_list(cur, cur->prev, list);
			else
				cur = cur->prev;
		}
		min = cur;
	} while (min != max);
}

/**
 * swap_list - Exchanges the positions of two nodes in a linked list.
 *
 * @curr: The current node.
 * @prev: The previous node.
 * @head: The head of the list.
 */
void swap_list(listint_t *curr, listint_t *prev, listint_t **head)
{
	listint_t *temp1 = curr->next;
	listint_t *temp2 = prev->prev;

	if (temp1 != NULL)
		temp1->prev = prev;
	if (temp2 != NULL)
		temp2->next = curr;
	curr->prev = temp2;
	prev->next = temp1;
	curr->next = prev;
	prev->prev = curr;
	if (*head == prev)
		*head = curr;
	print_list(*head);
}
