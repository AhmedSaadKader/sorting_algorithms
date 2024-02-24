#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using
 * the shell sort algorithm, using the Knuth sequence
 * @array: the array of integers
 * @size: size of the array
*/

void shell_sort(int *array, size_t size)
{
	int gap, i, temp, j;

	for (gap = size / 2; gap > 0; gap /= 2)
	{
		temp = array[i];
		for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			array[j] = array[j - gap];
		array[j] = temp;
	}
}
