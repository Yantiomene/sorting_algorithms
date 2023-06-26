#include <stdio.h>
#include "sort.h"

/**
 * print_part - prints the left and rigth part of the array
 * Before merging and after merging
 * @msg: message to print before printing numbers
 * @A: initial array
 * @start: start index
 * @end: end index
 *
 * Return: nothing
 */
void print_part(char *msg, int *A, int start, int end)
{
	int i;
	char *sp;

	printf("[%s]: ", msg);
	sp = "";
	for (i = start; i <= end; i++)
	{
		printf("%s%d", sp, A[i]);
		sp = ", ";
	}
	printf("\n");
}

/**
 * merge - merge the partition arrays
 * @A: initial array
 * @start: start index
 * @mid: middle index
 * @end: end index
 * @B: partiton array
 *
 * Return: nothing
 */
void merge(int *A, int start, int mid, int end, int *B)
{
	int i, j, k;

	printf("Merging...\n");
	print_part("left", A, start, mid);
	print_part("right", A, mid + 1, end);

	i = j = start;
	k = mid + 1;
	while (i <= mid && k <= end)
	{
		if (A[i] < A[k])
			B[j++] = A[i++];
		else
			B[j++] = A[k++];
	}
	while (i <= mid)
		B[j++] = A[i++];
	while (k <= end)
		B[j++] = A[k++];
	for (i = start; i <= end; i++)
		A[i] = B[i];
	print_part("Done", A, start, end);
}

/**
 * m_sort - recursive sorting 2 parts of the array
 * @A: initial array
 * @start: start index
 * @end: end index
 * @B: array to hold the partition
 *
 * Return: nothing
 */
void m_sort(int *A, int start, int end, int *B)
{
	int mid;

	if (start >= end)
		return;
	mid = (start + end - 1) / 2;
	m_sort(A, start, mid, B);
	m_sort(A, mid + 1, end, B);
	merge(A, start, mid, end, B);
}

/**
 * merge_sort - sorts an array of integers using merge sort
 * @array: input array
 * @size: size of the array
 *
 * Return: nothing
 */
void merge_sort(int *array, size_t size)
{
	int *B;

	B = malloc(sizeof(int) * size);
	if (!B)
		return;
	m_sort(array, 0, size - 1, B);
	free(B);
}
