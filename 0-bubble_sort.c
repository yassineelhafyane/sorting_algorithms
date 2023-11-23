#include "sort.h"

/**
 * bubble_sort - A function to sort an array of integers
 * @array: The array of integers to sort
 * @size: Size of the array
 *
 * Return: None
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, tmp_size;
	bool b_flag = false;

	if (array == NULL || size < 2)
		return;

	tmp_size = size;
	while (b_flag == false)
	{
		b_flag = true;
		for (i = 0; i < tmp_size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(array + i, array + i + 1);
				print_array(array, size);
				b_flag = false;
			}
		}
		tmp_size--;
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
