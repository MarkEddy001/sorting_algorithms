#include "sort.h"

/**
* bubble_sort - Implements the Bubble Sort algorithm to arrange an array of 
*               integers in ascending order.
* @array: The array to be sorted
* @size: The number of the array
*
* Return: void
*/
void bubble_sort(int *array, size_t size)
{
	size_t index1, n, new_n;
	int swap;

	if (array == NULL || size < 2)
		return;

	n = size;
	while (n > 0)
	{
		new_n = 0;
		for (index1 = 0; index1 < n - 1; index1++)
		{
			if (array[index1] > array[index1 + 1])
			{
				swap = array[index1];
				array[index1] = array[index1 + 1];
				array[index1 + 1] = swap;
				new_n = index1 + 1;
				print_array(array, size);
			}
		}
		n = new_n;
	}
}
