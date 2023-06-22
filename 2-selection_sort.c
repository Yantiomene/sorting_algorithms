#include "sort.h"

/**
 * selection_sort - sorts an array in ascending order using selection sort
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, i_min;
	int swap;

	for (i = 0; i < size - 1; i++)
	{
		i_min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[i_min])
				i_min = j;
		}
		if (i_min != i)
		{
			swap = array[i];
			array[i] = array[i_min];
			array[i_min] = swap;
			print_array(array, size);
		}
	}
}
