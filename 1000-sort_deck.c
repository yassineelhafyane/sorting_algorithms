#include "deck.h"

/**
 * sort_deck - Function that sorts a deck of cards
 * @deck: A pointer to the first node of deck_node_t doubly-linked list
 * Return: None
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	sort_kind(deck);
	sort_value(deck);
}


/**
 * _strcmp - Function that compares 2 strings
 * @first: The first string
 * @second: The second string
 *
 * Return: +ve if first is greater, 0 if equal, -ve if first is less
 */
int _strcmp(const char *first, const char *second)
{
	while (*first && *second && *first == *second)
	{
		first++;
		second++;
	}

	if (*first != *second)
		return (*first - *second);

	return (0);
}

/**
 * card_value - Functuin that returns the value of a card
 * @card: A pointer to a deck_node_t card
 * Return: Numerical value of the card
 */
char card_value(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * sort_kind - Function that sorts cards based on kind w/ insertion sort
 * @deck: A pointer to the head of a deck_node_t doubly-linked list
 * Return: None
 */
void sort_kind(deck_node_t **deck)
{
	deck_node_t *i, *tmp, *shuf;

	for (i = (*deck)->next; i != NULL; i = tmp)
	{
		tmp = i->next;
		shuf = i->prev;
		while (shuf != NULL && shuf->card->kind > i->card->kind)
		{
			shuf->next = i->next;
			if (i->next != NULL)
				i->next->prev = shuf;

			i->prev = shuf->prev;
			i->next = shuf;
			if (shuf->prev != NULL)
				shuf->prev->next = i;
			else
				*deck = i;

			shuf->prev = i;
			shuf = i->prev;
		}
	}
}

/**
 * sort_value - Function that sorts cards based on value w/ insertion sort
 * @deck: A pointer to the head of a deck_node_t doubly-linked list
 * Return: None
 */
void sort_value(deck_node_t **deck)
{
	deck_node_t *i, *tmp, *shuf;

	for (i = (*deck)->next; i != NULL; i = tmp)
	{
		tmp = i->next;
		shuf = i->prev;
		while (shuf != NULL && shuf->card->kind == i->card->kind &&
				card_value(shuf) > card_value(i))
		{
			shuf->next = i->next;
			if (i->next != NULL)
				i->next->prev = shuf;

			i->prev = shuf->prev;
			i->next = shuf;
			if (shuf->prev != NULL)
				shuf->prev->next = i;
			else
				*deck = i;

			shuf->prev = i;
			shuf = i->prev;
		}
	}
}
