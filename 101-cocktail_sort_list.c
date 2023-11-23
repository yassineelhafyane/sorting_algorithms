#include "sort.h"

/**
 * cocktail_sort_list - Function to sort list w/ cocktail shaker algorithm
 * @list: Pointer to first node of doubly linked list
 * Return: None
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool shaken = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken == false)
	{
		shaken = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_right(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_left(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken = false;
			}
		}
	}
}

/**
 * swap_right - Function to swap with node on the right in d-l list
 * @list: Pointer to first node in d-l list
 * @tail: Pointer to last node in d-l list
 * @shaker: Pointer to current node to swap
 *
 * Return: None
 */
void swap_right(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp_node = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmp_node;

	else
		*list = tmp_node;

	tmp_node->prev = (*shaker)->prev;
	(*shaker)->next = tmp_node->next;

	if (tmp_node->next != NULL)
		tmp_node->next->prev = *shaker;

	else
		*tail = *shaker;

	(*shaker)->prev = tmp_node;
	tmp_node->next = *shaker;
	*shaker = tmp_node;
}

/**
 * swap_left - Function to swap with node on the left in d-l list
 * @list: Pointer to first node in d-l list
 * @tail: Pointer to last node in d-l list
 * @shaker: Pointer to current node to swap
 *
 * Return: None
 */
void swap_left(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp_node = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tmp_node;

	else
		*tail = tmp_node;

	tmp_node->next = (*shaker)->next;
	(*shaker)->prev = tmp_node->prev;

	if (tmp_node->prev != NULL)
		tmp_node->prev->next = *shaker;

	else
		*list = *shaker;

	(*shaker)->next = tmp_node;
	tmp_node->prev = *shaker;
	*shaker = tmp_node;
}
