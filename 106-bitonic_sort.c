#include "sort.h"
#include <stdio.h>

/**
 * bitonic_compare - Arranges the values in a sub-array according to
 *                   the Bitonic Sort algorithm.
 * @up: The direction of sorting.
 * @array: The sub-array to be sorted.
 * @size: The size of the sub-array.
 *
 * Return: void
 */
void bitonic_compare(char up, int *array, size_t size)
{
	size_t index1, dist;
	int swap;

	dist = size / 2;
	for (index1 = 0; index1 < dist; index1++)
	{
		if ((array[index1] > array[index1 + dist]) == up)
		{
			swap = array[index1];
			array[index1] = array[index1 + dist];
			array[index1 + dist] = swap;
		}
	}
}

/**
 * bitonic_merge - Recursively merges two sub-arrays according
 *                 to the Bitonic Sort algorithm.
 * @up: The direction of sorting.
 * @array: The sub-array to be sorted.
 * @size: The size of the sub-array.
 *
 * Return: void
 */
void bitonic_merge(char up, int *array, size_t size)
{
	if (size < 2)
		return;
	bitonic_compare(up, array, size);
	bitonic_merge(up, array, size / 2);
	bitonic_merge(up, array + (size / 2), size / 2);
}

/**
 * bit_sort - Applies the Bitonic Sort algorithm recursively to a sub-array.
 * @up: The direction of sorting.
 * @array: The sub-array to be sorted.
 * @size: The size of the sub-array.
 * @t: The total size of the original array.
 *
 * Return: void
 */
void bit_sort(char up, int *array, size_t size, size_t t)
{
	if (size < 2)
		return;
	printf("Merging [%lu/%lu] (%s):\n", size, t, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);
	bit_sort(1, array, size / 2, t);
	bit_sort(0, array + (size / 2), size / 2, t);
	bitonic_merge(up, array, size);
	printf("Result [%lu/%lu] (%s):\n", size, t, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);

}

/**
 * bitonic_sort - Applies the Bitonic Sort algorithm to arrange an
 *                array of integers in ascending order.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Return: void
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bit_sort(1, array, size, size);
}
