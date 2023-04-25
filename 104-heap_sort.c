#include "sort.h"


/**
 * swap_int - Swap two integers in an array
 * @array: The array containing the integers
 * @i: The index of the first integer
 * @j: The index of the second integer
 */
void swap_int(int *array, int i, int j)
{
	int temp = array[i];

	array[i] = array[j];
	array[j] = temp;
}


/**
 * heapify - Turn an array into a valid max heap
 * @array: The array to heapify
 * @n: The size of the array
 * @i: The current index to consider as the root
 * @size: The original size of the array
 */
void heapify(int *array, int n, int i, size_t size)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && array[left] > array[largest])
		largest = left;

	if (right < n && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap_int(array, i, largest);
		print_array(array, size);
		heapify(array, n, largest, size);
	}
}


/**
 * heap_sort - Sort an array of integers in ascending order using the
 * Heap sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		swap_int(array, 0, i);
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}

