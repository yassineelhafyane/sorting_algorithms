#include "sort.h"

/**
 * quick_sort_hoare - Function that sorts ints w/ quick sort algorithm
 * @array: The array of integers
 * @size: The array size
 *
 * Return: None
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}

/**
 * hoare_sort - Function that uses quicksort algorithm through recursion
 * @array: The array of integers
 * @size: The array size
 * @left: The starting index of the array partition to order
 * @right: The ending index of the array partition to order
 *
 * Return: None
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	if (right - left > 0)
	{
		pivot = array[right];
		for (above = left - 1, below = right + 1; above < below;)
		{
			do {
				above++;
			} while (array[above] < pivot);
			do {
				below--;
			} while (array[below] > pivot);

			if (above < below)
			{
				swap(array + above, array + below);
				print_array(array, size);
			}
		}
		hoare_sort(array, size, left, above - 1);
		hoare_sort(array, size, above, right);
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
