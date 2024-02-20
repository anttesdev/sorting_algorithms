#include "sort.h"

/**
 * swap - Swaps two integers
 *
 * @x: Pointer to the first integer
 * @y: Pointer to the second integer
 */
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick Sort
 *
 * @array: The array to be partitioned
 * @start: Starting index of the partition
 * @end: Ending index of the partition
 * @size: Number of elements in @array
 *
 * Return: The final position of the pivot element after partitioning
 */
size_t lomuto_partition(int *array, ssize_t start, ssize_t end, size_t size)
{
	int ref = array[end];
	ssize_t i = start - 1;
	ssize_t j;

	for (j = start; j <= end - 1; ++j)
	{
		if (array[j] <= ref)
		{
			++i;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if ((size_t)(i + 1) != (size_t)end)
	{
		swap(&array[i + 1], &array[end]);
		print_array(array, size);
	}
	return ((size_t)(i + 1));
}

/**
 * lomuto_recursive - Recursive function for
 * Quick Sort (Lomuto partition scheme)
 *
 * @array: The array to be sorted
 * @start: Starting index of the partition
 * @end: Ending index of the partition
 * @size: Number of elements in @array
 */
void lomuto_recursive(int *array, ssize_t start, ssize_t end, size_t size)
{
	size_t ref_index;

	if (start < end)
	{
		ref_index = lomuto_partition(array, start, end, size);

		lomuto_recursive(array, start, (ssize_t)(ref_index - 1), size);
		lomuto_recursive(array, (ssize_t)(ref_index + 1), end, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_recursive(array, 0, (ssize_t)(size - 1), size);
}
