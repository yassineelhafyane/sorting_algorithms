#include "sort.h"

/**
 * counting_sort - Function to sort int w/ counting sort algorithm
 * @array: The array of integers
 * @size: The array size
 *
 * Return: None
 */
void counting_sort(int *array, size_t size)
{
	int *current, *sorted, max, i;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;

	max = max_int(array, size);
	current = malloc(sizeof(int) * (max + 1));
	if (current == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		current[i] = 0;

	for (i = 0; i < (int)size; i++)
		current[array[i]] += 1;

	for (i = 0; i < (max + 1); i++)
		current[i] += current[i - 1];

	print_array(current, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[current[array[i]] - 1] = array[i];
		current[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(current);
}

/**
 * max_int - Function to return the maximum value in an array of integers
 * @array: The array of integers
 * @size: The array size
 *
 * Return: Maximum integer
 */
int max_int(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}
