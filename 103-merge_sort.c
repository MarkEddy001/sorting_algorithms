#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * TDMerge - Sorts and merges the subarrays within the source array.
 * @start: Starting index (inclusive) for the left subarray.
 * @middle: End index (exclusive) for the left subarray and
 *          starting index (inclusive) for the right subarray.
 * @end: End index (exclusive) for the right subarray.
 * @dest: Destination for the merged data.
 * @source: Source of the data to be merged.
 *
 * Return: void
 */
void TDMerge(size_t start, size_t middle, size_t end, int *dest, int *source)
{
	size_t index1, index2, index3;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(source + start, middle - start);
	printf("[right]: ");
	print_array(source + middle, end - middle);
	index1 = start;
	index2 = middle;
	for (index3 = start; index3 < end; index3++)
	{
		if (index1 < middle && (index2 >= end || source[index1] <= source[index2]))
		{
			dest[index3] = source[index1];
			index1++;
		}
		else
		{
			dest[index3] = source[index2];
			index2++;
		}
	}
	printf("[Done]: ");
	print_array(dest + start, end - start);
}

/**
 * TDSplitMerge - Recursively splits the array and merges the sorted subarrays.
 * @start: Starting index (inclusive).
 * @end: End index (exclusive).
 * @array: The array to be sorted.
 * @copy: A copy of the array.
 *
 * Return: void
 */
void TDSplitMerge(size_t start, size_t end, int *array, int *copy)
{
	size_t middle;

	if (end - start < 2)
		return;
	middle = (start + end) / 2;
	TDSplitMerge(start, middle, array, copy);
	TDSplitMerge(middle, end, array, copy);
	TDMerge(start, middle, end, array, copy);
	for (middle = start; middle < end; middle++)
		copy[middle] = array[middle];
}

/**
 * merge_sort - Applies the Merge Sort algorithm to arrange
 *              an array of integers in ascending order.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	size_t index1;
	int *copy;

	if (array == NULL || size < 2)
		return;
	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;
	for (index1 = 0; index1 < size; index1++)
		copy[index1] = array[index1];
	TDSplitMerge(0, size, array, copy);
	free(copy);
}
