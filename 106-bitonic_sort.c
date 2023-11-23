#include "sort.h"

/**
 * bitonic_sort - Function that sorts ints w/ bitonic sort algorithm
 * @array: The array of integers
 * @size: The array size
 *
 * Return: None
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}

/**
 * bitonic_merge - Function that sorts a bitonic sequence inside an array
 * @array: The array ofintegers
 * @size: The array size
 * @start: The starting index of the sequence in array to sort
 * @seq: The size of the sequence to sort
 * @flow: The direction to sort in
 *
 * Return: None
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == UP && array[i] > array[i + jump]) ||
			    (flow == DOWN && array[i] < array[i + jump]))
				swap(array + i, array + i + jump);
		}

		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_seq - Function that converts an array into a bitonic sequence.
 * @array: The array of integers
 * @size: The array size
 * @start: The starting index of a block of the building bitonic sequence
 * @seq: The size of a block of the building bitonic sequence
 * @flow: The direction to sort the bitonic sequence block in
 *
 * Return: None
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
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
