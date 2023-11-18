#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * partition - Identifies the partition using the Hoare
 *             scheme for the Quick Sort algorithm.
 * @array: The array to be sorted.
 * @lo: The lowest index of the partition to be sorted.
 * @hi: The highest index of the partition to be sorted.
 * @size: The size of the array.
 *
 * Return: The index of the partition.
 */
size_t partition(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	int swap, pivot;

	pivot = array[hi];
	while (lo <= hi)
	{
		while (array[lo] < pivot)
			lo++;
		while (array[hi] > pivot)
			hi--;
		if (lo <= hi)
		{
			if (lo != hi)
			{
				swap = array[lo];
				array[lo] = array[hi];
				array[hi] = swap;
				print_array(array, size);
			}
			lo++;
			hi--;
		}
	}
	return (hi);
}

/**
 * quicksort - Applies the Quick Sort algorithm to sort a
 *             partition of an array of integers.
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
		quicksort(array, lo, pivot, size);
		quicksort(array, pivot + 1, hi, size);

	}
}

/**
 * quick_sort_hoare - Applies the Quick Sort algorithm to
 *                    arrange an array of integers in ascending order.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
