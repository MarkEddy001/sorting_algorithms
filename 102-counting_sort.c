#include "sort.h"
#include "stdlib.h"

/**
 * counting_sort - Applies the Counting Sort algorithm to
 *                 arrange an array of integers in ascending order.
 * @array: The array to be sorted.
 * @size: The size of the array to be sorted.
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int index1, max;
	int *count = NULL, *copy = NULL;
	size_t index2, temp, total = 0;


	if (array == NULL || size < 2)
		return;
	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;
	for (index2 = 0, max = 0; index2 < size; index2++)
	{
		copy[index2] = array[index2];
		if (array[index2] > max)
			max = array[index2];
	}
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(copy);
		return;
	}
	for (index1 = 0; index1 <= max; index1++)
		count[index1] = 0;
	for (index2 = 0; index2 < size; index2++)
		count[array[index2]] += 1;
	for (index1 = 0; index1 <= max; index1++)
	{
		temp = count[index1];
		count[index1] = total;
		total += temp;
	}
	for (index2 = 0; index2 < size; index2++)
	{
		array[count[copy[index2]]] = copy[index2];
		count[copy[index2]] += 1;
	}
	print_array(count, max + 1);
	free(count);
	free(copy);
}
