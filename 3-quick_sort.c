#include "sort.h"

/**
 * lamuto_partition - divides array into 2 partitions
 * @a: input array
 * @start: start index
 * @end: end index
 * @size: array size
 *
 * Return: the pivot index
 */
int lamuto_partition(int *a, int start, int end, size_t size)
{
	int pivot = a[end], swap;
	int i, j;

	i = start;
	for (j = start; j < end; j++)
	{
		if (a[j] <= pivot)
		{
			if (j != i)
			{
				swap = a[i];
				a[i] = a[j];
				a[j] = swap;
				print_array(a, size);
			}
			i++;
		}
	}

	if (i != end && a[i] != pivot)
	{
		swap = a[i];
		a[i] = a[end];
		a[end] = swap;
		print_array(a, size);
	}
	return (i);
}

/**
 * _qsort - recursive quicksort algo
 * @a: input array
 * @start: start index
 * @end: end index
 * @size: array size
 *
 * Return: nothing
 */
void _qsort(int *a, int start, int end, size_t size)
{
	int p;

	if (start >= end)
		return;
	p = lamuto_partition(a, start, end, size);

	_qsort(a, start, p - 1, size);
	_qsort(a, p + 1, end, size);
}

/**
 * quick_sort - sorts array of integer using Quick sort algo
 * @array: input array
 * @size: array size
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	_qsort(array, 0, size - 1, size);
}
