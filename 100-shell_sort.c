#include "sort.h"

/**
 * swap - to swap 2 values
 * @array: the array
 * @i: 1st index
 * @j: 2nd index
 */

void swap(int *array, int i, int j)
{
	int tmp;

	if (array[i] != array[j])
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
}


/**
 * shell_sort - sorts an array of integers in ascending order using
 * the shell sort algorithm, using the Knuth sequence
 * @array: the array of integers
 * @size: size of the array
*/

void shell_sort(int *array, size_t size)
{
	size_t i, j, gap = 0;

	if (size < 2)
		return;

	while (gap <= size / 3)
		gap = gap * 3 + 1;

	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i; j >= gap && array[j] < array[j - gap]; j -= gap)
				swap(array, j, j - gap);
		}
		gap /= 3;
		print_array(array, size);
	}
}
