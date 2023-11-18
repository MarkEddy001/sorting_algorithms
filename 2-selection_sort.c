#include "sort.h"

/**
 * selection_sort - Applies the selection sort algorithm 
 *                  to arrange an array in ascending order.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
	unsigned int index1, index3;
	int min = 0, index = 0;

	for (index1 = 0; index1 < size; index1 += 1)
	{
		min = array[index1];
		for (index3 = index1; index3 < size; index3 += 1)
		{
			if (array[index3] < min)
			{
				min = array[index3];
				index = index3;
			}
		}
		if (min != array[index1])
		{
			array[index] = array[index1];
			array[index1] = min;
			print_array(array, size);
		}

	}
}
