#include "sort.h"
#include <stdio.h>

/**
 * partition - Identifies the partition using the Lomuto
 *            scheme for the Quick Sort algorithm.
 * @array: The array to be sorted.
 * @lo: The lowest index of the partition to be sorted.
 * @hi: The highest index of the partition to be sorted.
 * @size: The size of the array.
 *
 * Return: The index of the partition.
 */
size_t partition(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	ssize_t index1, index2;
	int swap, pivot;

	pivot = array[hi];
	index1 = lo - 1;
	for (index2 = lo; index2 < hi; index2++)
	{
		if (array[index2] < pivot)
		{
			index1++;
			if (index1 != index2)
			{
				swap = array[index1];
				array[index1] = array[index2];
				array[index2] = swap;
				print_array(array, size);
			}
		}
	}
	if (array[hi] < array[index1 + 1])
	{
		swap = array[index1 + 1];
		array[index1 + 1] = array[hi];
		array[hi] = swap;
		print_array(array, size);
	}
	return (index1 + 1);
}

/**
 * quicksort - Applies the Quick Sort algorithm to
 *             sort a partition of an array of integers.
 * @array: The array to be sorted.
 * @lo: The lowest index of the partition to be sorted.
 * @hi: The highest index of the partition to be sorted.
 * @size: The size of the array.
 *
 * Return: void
 */
void quicksort(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	ssize_t pivot;

	if (lo < hi)
	{
		pivot = partition(array, lo, hi, size);
		quicksort(array, lo, pivot - 1, size);
		quicksort(array, pivot + 1, hi, size);

	}
}

/**
 * quick_sort - Applies the Quick Sort algorithm to arrange
 *              an array of integers in ascending order.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
