#include "sort.h"

/**
 * swap_num - swaps 2 arrays index position
 * @a: input array
 * @i: first index
 * @j: second index
 *
 * Return: nothing
 */
void swap_num(int *a, int i, int j)
{
	a[i] = a[i] + a[j];
	a[j] = a[i] - a[j];
	a[i] = a[i] - a[j];
}

/**
 * sift_down - repair the heap whose root is at index
 * 'start'
 * @a: input array
 * @start: start index
 * @end: end index
 * @size: array size
 *
 * Return: nothing
 */
void sift_down(int *a, int start, int end, size_t size)
{
	int swap, root, child;

	root = start;
	child = (start * 2) + 1;
	while (child <= end)
	{
		swap = root;
		if (a[swap] < a[child])
			swap = child;
		if (end >= (child + 1) && a[swap] < a[child + 1])
			swap = child + 1;
		if (swap == root)
			return;
		swap_num(a, root, swap);
		root = swap;
		print_array(a, size);
		child = (root * 2) + 1;
	}
}

/**
 * heapify - puts elements of an array in a heap order
 * @a: input array
 * @size: array size
 *
 * Return: nothing
 */
void heapify(int *a, size_t size)
{
	int start;

	start = ((int)size - 2) / 2;
	while (start >= 0)
	{
		sift_down(a, start, (int)size - 1, size);
		start--;
	}
}

/**
 * heap_sort - sorts an array using the HeapSort
 * @array: inout array
 * @size: array size
 *
 * Return: nothing
 */
void heap_sort(int *array, size_t size)
{
	int end;

	if (!array || size < 2)
		return;

	heapify(array, size);

	end = (int)size - 1;
	while (end > 0)
	{
		swap_num(array, end, 0);
		print_array(array, size);
		end--;
		sift_down(array, 0, end, size);
	}
}
