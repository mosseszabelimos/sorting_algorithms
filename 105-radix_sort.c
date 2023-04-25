#include "sort.h"


/**
 * counting_sort_radix - Modified counting sort for use in radix sort.
 * @array: The array to sort.
 * @size: The size of the array.
 * @exp: The current digit (10^exp) to sort by.
 * @count: The count array for counting sort.
 */
void counting_sort_radix(int *array, size_t size, int exp, int *count)
{
	int *output = malloc(sizeof(int) * size);
	size_t i;

	for (i = 0; i < 10; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i != SIZE_MAX; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}


/**
 * radix_sort - Radix sort an array of integers.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int max = 0;
	int exp;
	size_t i;
	int count[10];

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort_radix(array, size, exp, count);
		print_array(array, size);
	}
}

