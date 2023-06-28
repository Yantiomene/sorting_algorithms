#include <stdio.h>
#include "sort.h"

/**
 * print_bit - prints a part of the array
 * @a: input array
 * @start: start index
 * @end: end index
 *
 * Return: nothing
 */
void print_bit(int *a, int start, int end)
{
	char *sp = "";

	for (; start < end; start++)
	{
		printf("%s%d", sp, a[start]);
		sp = ", ";
	}
	printf("\n");
}

/**
 * bit_sort - sort a part of array according to a direction
 * @a: input array
 * @start: start index
 * @end: end index
 * @dir: sorting direction
 *
 * Return: nothing
 */
void bit_sort(int *a, int start, int end, int dir)
{
	int i, j, swap;

	for (i = start; i < end; i++)
	{
		swap = i;
		for (j = i + 1; j < end; j++)
		{
			if (dir == (a[swap] > a[j]))
				swap = j;
		}
		if (swap != i)
		{
			a[i] = a[i] + a[swap];
			a[swap] = a[i] - a[swap];
			a[i] = a[i] - a[swap];
		}
	}
}

/**
 * bitonic_merge - Merge the sorted bitonic sequence
 * @a: input array
 * @start: start index
 * @end: end index
 * @size: array size
 * @dir: sorting direction
 *
 * Return: nothing
 */
void bitonic_merge(int *a, int start, int end, size_t size, int dir)
{
	int mid;
	char *dir_n;

	if (end - start < 2)
		return;
	dir_n = (dir == 1) ? "UP" : "DOWN";
	printf("Merging [%d/%ld] (%s):\n", end - start, size, dir_n);
	print_bit(a, start, end);

	if (end - start == 2)
		return;

	mid = (start + end) / 2;
	bitonic_merge(a, start, mid, size, 1);
	bit_sort(a, start, mid, 1);
	printf("Result [%d/%ld] (%s):\n", mid - start, size, "UP");
	print_bit(a, start, mid);

	bitonic_merge(a, mid, end, size, 0);
	bit_sort(a, mid, end, 0);
	printf("Result [%d/%ld] (%s):\n", end - mid, size, "DOWN");
	print_bit(a, mid, end);
}

/**
 * bitonic_sort - sorts an array of integers using the Bitonic sort algo
 * @array: input array
 * @size: array size
 *
 * Return: nothing
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || !(size && (!(size & (size - 1)))))
		return;
	bitonic_merge(array, 0, size, size, 1);
	bit_sort(array, 0, size, 1);
	printf("Result [%ld/%ld] (%s):\n", size, size, "UP");
	print_bit(array, 0, size);
}
