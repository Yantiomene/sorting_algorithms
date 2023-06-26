#include "sort.h"

/**
 * radix_sort - sorts an array of integers using the Radix sort algo
 * @array: input array
 * @size: array size
 *
 * Return: nothing
 */
void radix_sort(int *array, size_t size)
{
	int tmp;
	int s_digit = 10, not_sorted = 1, prev, curr;
	size_t i;

	if (!array || size < 2)
		return;

	while (not_sorted)
	{
		not_sorted = 0;
		for (i = 1; i < size; i++)
		{
			if (((array[i - 1] % (s_digit * 10)) / s_digit) > 0)
				not_sorted = 1;
			prev = (array[i - 1] % s_digit) / (s_digit / 10);
			curr = (array[i] % s_digit) / (s_digit / 10);
			if (prev > curr)
			{
				tmp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = tmp;
				if ((i - 1) > 0)
					i -= 2;
			}
		}
		print_array(array, size);
		s_digit *= 10;
	}
}
