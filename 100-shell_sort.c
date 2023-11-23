#include "sort.h"

/**
 * shell_sort - Function to sort array int w/ shell sort algorithm
 * @array: The array
 * @size: The array size
 *
 * Return: None
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
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
