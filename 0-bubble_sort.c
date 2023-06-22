#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: array size
 *
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	int swap = 1, tmp;
	size_t i;
	size_t n = size;

	while (swap)
	{
		swap = 0;
		for (i = 1; i < n; i++)
		{
			if (array[i - 1] > array[i])
			{
				tmp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = tmp;
				swap = 1;
				print_array(array, size);
			}
		}
		n -= 1;
	}
}
