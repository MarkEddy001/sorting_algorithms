#include "deck.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * get_val - Retrieves the relative value of a card
 *           from its string representation.
 * @str: The string value of the card.
 *
 * Return: The relative value of the card (ranging from 0 to 12).
 */
int get_val(const char *str)
{
	int index1;
	char *array[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
			"10", "Jack", "Queen", "King"};

	for (index1 = 0; index1 < 13; index1++)
	{
		if (strcmp(str, array[index1]) == 0)
		{
			return (index1);
		}
	}
	exit(1);
}

/**
 * swap_node - Exchanges a node with its next node in a linked list.
 * @list: Double pointer to the beginning of the list.
 * @node: The node to be swapped.
 *
 * Return: void
 */
void swap_node(deck_node_t **list, deck_node_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

/**
 * sort_deck - Arranges a linked list deck of cards in ascending order.
 * @deck: Double pointer to the deck to be sorted.
 *
 * Return: void
 */
void sort_deck(deck_node_t **deck)
{
	char swapped = 1, c1, c2;
	deck_node_t *current;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;
	current = *deck;
	while (swapped != 0)
	{
		swapped = 0;
		while (current->next != NULL)
		{
			c1 = get_val(current->card->value) + 13 * current->card->kind;
			c2 = get_val(current->next->card->value) + 13 * current->next->card->kind;
			if (c1 > c2)
			{
				swap_node(deck, current);
				swapped = 1;
			}
			else
				current = current->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (current->prev != NULL)
		{
			c1 = get_val(current->card->value) + 13 * current->card->kind;
			c2 = get_val(current->prev->card->value) + 13 * current->prev->card->kind;
			if (c1 < c2)
			{
				swap_node(deck, current->prev);
				swapped = 1;
			}
			else
				current = current->prev;
		}
	}
}
