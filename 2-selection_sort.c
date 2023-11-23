#include "sort.h"

/**
 * selection_sort - Function to sort array of int w/ selection sort algorithm
 * @array: The array
 * @size: The array size
 *
 * Return: None
 */
void selection_sort(int *array, size_t size)
{
	int *min_elem;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_elem = array + i;
		for (j = i + 1; j < size; j++)
			if (array[j] < *min_elem)
				min_elem = array + j;

		if ((array + i) != min_elem)
		{
			swap(array + i, min_elem);
			print_array(array, size);
		}
	}
}

/**
 * swap - Function to swap position of 2 elements in list
 * @first: Fist element
 * @second: Second element
 *
 * Return: None
 */
void swap(int *first, int *second)
{
	int tmp_elem;

	tmp_elem = *first;
	*first = *second;
	*second = tmp_elem;
}
