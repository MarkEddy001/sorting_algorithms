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
	size_t i, j, swap = 0;
	int temp;

	if (size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		swap = 0;
		for (j = 0; j < size - i && !(j + 1 >= size - i); j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swap = 1;
				print_array(array, size);
			}
		}
		if (swap == 0)
			break;
	}
}
