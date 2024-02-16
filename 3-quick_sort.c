#include "sort.h"

/**
 * partition - takes last element as pivot, places the pivot element
 * at its correct position in sorted array, and places all smaller to
 * left of pivot and all greater elements to right of pivot
 * @array: the array to sort
 * @low: the lowest index
 * @high: the highest index equivalent to size of array - 1
 * @size: size of the array
 *
 * Return: the correct index of the pivot
*/

int partition(int *array, int low, int high, size_t size)
{
	int i, j, pivot, temp;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (high > (i + 1))
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_helper - helper function for quick sort
 * @array: the array to sort
 * @low: the lowest index
 * @high: the highest index equivalent to size of array - 1
 * @size: size of the array
*/

void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);
		quick_sort_helper(array, low, pi - 1, size);
		quick_sort_helper(array, pi + 1, high, size);
	}
}


/**
 * quick_sort - sorts an array of integers in ascending order using the
 * quick sort algorithm
 * @array: array of integers
 * @size: the size of the array
*/

void quick_sort(int *array, size_t size)
{
	quick_sort_helper(array, 0, size - 1, size);
}
