#include "sort.h"

/**
 * radix_sort - Function that sorts ints w/ radix sort algorithm
 * @array: The array of integers
 * @size: The array size
 *
 * Return: None
 */
void radix_sort(int *array, size_t size)
{
	int max, sig_dig, *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	max = max_int(array, size);
	for (sig_dig = 1; max / sig_dig > 0; sig_dig *= 10)
	{
		lsd_radix_sort(array, size, sig_dig, buffer);
		print_array(array, size);
	}

	free(buffer);
}

/**
 * lsd_radix_sort - Function that sorts sig-dig of ints w/ Counting sort algo.
 * @array: The array of integers
 * @size: The array size
 * @sig_dig: The significant digit to sort
 * @buffer: A copy of array to sort
 *
 * Return: None
 */
void lsd_radix_sort(int *array, size_t size, int sig_dig, int *buffer)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sig_dig) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buffer[count[(array[i] / sig_dig) % 10] - 1] = array[i];
		count[(array[i] / sig_dig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buffer[i];
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
