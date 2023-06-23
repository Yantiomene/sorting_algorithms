#include "sort.h"

/**
 * shell_sort - sorts an array in ascending order using the shell sort algo
 * @array: input array
 * @size: array size
 *
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t n, gap, i, j;
	int swap;

	n = 1;
	while (n < size)
		n = (n * 3) + 1;
	for (gap = (n - 1) / 3; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i; j >= gap; j -= gap)
			{
				if (array[j] < array[j - gap])
				{
					swap = array[j];
					array[j] = array[j - gap];
					array[j - gap] = swap;
				}
			}
		}
		print_array(array, size);
	}
}
