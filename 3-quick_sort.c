#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 * using Quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 **/

void quick_sort(int *array, size_t size)
{
	size_t pivot_index;

	pivot_index = partition(array, 0, size - 1);
	if (size <= 1)
		return;

	print_array(array, size);
	if (pivot_index > 0)
		quick_sort(array, pivot_index);
	if (pivot_index < size - 1)
		quick_sort(array + pivot_index + 1, size - pivot_index - 1);
}

/**
 * swap - swaps the value of two integers
 * @a: first integer
 * @b: secocnd integer
 **/

void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * partition - partitions the array by selecting the last element
 * as pivot and placing all smaller elements to the left of the pivot
 * and all large elements to the right of the pivot
 * @array: array to be partitioned
 * @low: starting index
 * @high: ending index
 * Return: index of the pivot element
 **/

int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);

	return (i + 1);
}
