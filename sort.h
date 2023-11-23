#ifndef SORT_H
#define SORT_H

#define UP 0
#define DOWN 1

#include <stdio.h>
#include<stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/**
 * enum bool - Enumerate Boolean values
 * @false: 0
 * @true: 1
 */
typedef enum bool
{
	false = 0,
	true
} bool;

/* Prototypes for print_array and print_list functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Prototypes for Bubble Sort */
void bubble_sort(int *array, size_t size);
void swap(int *first, int *second);

/* Prototypes for Insert sort */
void insertion_sort_list(listint_t **list);
void swap_linked_list(listint_t **head, listint_t **first, listint_t *second);

/* Prototype for Selection sort */
void selection_sort(int *array, size_t size);

/* Prototypes for Quick sort */
void quick_sort(int *array, size_t size);
void lomuto_sort(int *array, size_t size, int left, int right);

/* Prototype for Shell sort */
void shell_sort(int *array, size_t size);

/* Prototypes for Cocktail shaker sort */
void cocktail_sort_list(listint_t **list);
void swap_right(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_left(listint_t **list, listint_t **tail, listint_t **shaker);

/* Prototypes for Counting sort */
void counting_sort(int *array, size_t size);
int max_int(int *array, int size);

/* Prototypes for Merge sort */
void merge_sort(int *array, size_t size);
void top_down_merge_sort(int *array, int *buffer, size_t top, size_t down);

/* Prototypes for Heap sort */
void heap_sort(int *array, size_t size);
void heapify(int *array, size_t size, size_t base, size_t root);

/* Prototypes for Radix sort */
void radix_sort(int *array, size_t size);
void lsd_radix_sort(int *array, size_t size, int sig, int *buff);

/* Prototypes for Bitonic sort */
void bitonic_sort(int *array, size_t size);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);

/* Prototypes for Quick sort Hoare Partition Scheme */
void quick_sort_hoare(int *array, size_t size);
void hoare_sort(int *array, size_t size, int left, int right);

#endif
