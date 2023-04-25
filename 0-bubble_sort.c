#include <stdbool.h>
#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using the Bubble
 *               sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void bubble_sort(int *array, size_t size)
{
	bool swapped;
	size_t i, j;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = false;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];

				array[j] = array[j + 1];
				array[j + 1] = temp;

				print_array(array, size);

				swapped = true;
			}
		}

		if (!swapped)
			break;
	}
}

