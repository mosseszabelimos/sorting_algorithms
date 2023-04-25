#include <stdio.h>
#include "sort.h"


/**
 * swap - Swaps two integers in an array
 * @array: The array containing the integers to swap
 * @i: The index of the first integer
 * @j: The index of the second integer
 */
void swap(int *array, int i, int j)
{
	int tmp = array[i];

	array[i] = array[j];
	array[j] = tmp;
}


/**
 * lomuto_partition - Partitions an array using the Lomuto partition scheme
 * @array: The array to partition
 * @low: The lower index of the subarray to partition
 * @high: The upper index of the subarray to partition
 * @size: The size of the array
 *
 * Return: The final partition index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(array, i, j);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap(array, i + 1, high);
		print_array(array, size);
	}
	return (i + 1);
}


/**
 * lomuto_quick_sort - Implements the quick sort algorithm using the Lomuto
 *                     partition scheme
 * @array: The array to sort
 * @low: The lower index of the subarray to sort
 * @high: The upper index of the subarray to sort
 * @size: The size of the array
 */
void lomuto_quick_sort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);
		lomuto_quick_sort(array, low, pivot - 1, size);
		lomuto_quick_sort(array, pivot + 1, high, size);
	}
}


/**
 * quick_sort - Sorts an array of integers in ascending order
 * @array: The array to sort
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_quick_sort(array, 0, size - 1, size);
}

