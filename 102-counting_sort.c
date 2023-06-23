#include "sort.h"

/**
 * counting_sort - sorts an array of integer using counting sort
 * @array: input array
 * @size: array size
 *
 * Return: nothing
 */
void counting_sort(int *array, size_t size)
{
	int k, i;
	int *count, *out;

	if (size < 2)
		return;
	for (k = i = 0; i < (int)size; i++)
		if (array[i] > k)
			k = array[i];
	count = malloc(sizeof(int) * (k + 1));
	if (!count)
		return;
	for (i = 0; i <= k; i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 1; i <= k; i++)
		count[i] += count[i - 1];
	print_array(count, k + 1);
	out = malloc(sizeof(int) * size);
	if (!out)
	{
		free(count);
		return;
	}
	for (i = 0; i < (int)size; i++)
	{
		out[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = out[i];
	free(count);
	free(out);
}
