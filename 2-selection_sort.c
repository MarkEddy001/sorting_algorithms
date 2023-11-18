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
	int index1, index2, pos;
	int min, temp, flag;

	if (size < 2)
		return;
	for (index1 = 0; (size_t)index1 < size; index1++)
	{
		flag = 0;
		min = array[index1];
		if ((size_t)index1 == size - 1)
			break;
		for (index2 = index1; (size_t)index2 < size; index2++)
		{
			if (min > array[index2])
			{
				min = array[index2];
				pos = index2;
				flag = 1;
			}
		}
		if (flag)
		{
			temp = array[index1];
			array[index1] = array[pos];
			array[pos] = temp;
			print_array(array, size);
		}
	}
}
