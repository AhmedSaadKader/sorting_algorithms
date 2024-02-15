#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order using
 * the selection sort algorithm
 * @array: the array of integers
 * @size: the size of the array
*/

void selection_sort(int *array, size_t size)
{
	size_t i, j, lowest;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		lowest = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[lowest])
				lowest = j;
		}
		if (lowest != i)
		{
			temp = array[i];
			array[i] = array[lowest];
			array[lowest] = temp;
		}
		print_array(array, size);
	}
}
