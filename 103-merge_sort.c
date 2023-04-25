#include "sort.h"


/**
 * merge - merge an array
 * @array: pointer to the array
 * @temp: pointer to a place holder
 * @left: the merge left
 * @middle: the merge middle
 * @right: the merge right
 */
void merge(int *array, int *temp, int left, int middle, int right)
{
	int i, j, k;

	for (i = left, j = middle, k = left; i < middle && j < right; k++)
	{
		if (array[i] < array[j])
		{
			temp[k] = array[i];
			i++;
		}
		else
		{
			temp[k] = array[j];
			j++;
		}
	}

	while (i < middle)
	{
		temp[k] = array[i];
		i++;
		k++;
	}

	while (j < right)
	{
		temp[k] = array[j];
		j++;
		k++;
	}

	for (i = left; i < right; i++)
	{
		array[i] = temp[i];
	}
}


/**
 * merge_sort_recursive - sort the merged array recursively
 * @array: pointer to the array
 * @temp: pointer toa place holder
 * @left: the merge left
 * @right: the merge right
 */
void merge_sort_recursive(int *array, int *temp, int left, int right)
{
	int middle;

	if (right - left <= 1)
	{
		return;
	}

	middle = left + (right - left) / 2;
	merge_sort_recursive(array, temp, left, middle);
	merge_sort_recursive(array, temp, middle, right);
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, middle - left);
	printf("[right]: ");
	print_array(array + middle, right - middle);

	merge(array, temp, left, middle, right);
	printf("[Done]: ");
	print_array(array + left, right - left);
}


/**
 * merge_sort - sort the merged array in ascending order
 * @array: the pointer to the array
 * @size: number of element in the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
	{
		return;
	}

	temp = malloc(size * sizeof(*temp));
	if (!temp)
		return;

	merge_sort_recursive(array, temp, 0, size);
	free(temp);
}

