#include "sort.h"

/**
 * quick_sort - Function that sorts array of int w/ quicksort algorithm
 * @array: THe integer array
 * @size: Array size
 *
 * Return: None
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}

/**
 * lomuto_sort - Lomuto partition scheme
 * @array: THe arrayof integers
 * @size: Array size
 * @left: The starting index of the array partition to order
 * @right: The ending index of the array partition to order
 *
 * Return: None
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;
	int part;

	if (right - left > 0)
	{
		pivot = array + right;
		for (above = below = left; below < right; below++)
		{
			if (array[below] < *pivot)
			{
				if (above < below)
				{
					swap(array + below, array + above);
					print_array(array, size);
				}
				above++;
			}
		}

		if (array[above] > *pivot)
		{
			swap(array + above, pivot);
			print_array(array, size);
		}

		part = above;
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
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
