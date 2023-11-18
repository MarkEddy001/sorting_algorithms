#include "sort.h"

void insertion_sort(int *, long int, long int, size_t);

/**
 * shell_sort - Applies the Shell Sort algorithm
 *              using Knuth's sequence to sort an array.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	long int n = 1;
	long int index1, index3, temp;

	if (size < 2)
		return;

	while (n < (long int)size / 3)
		n = n * 3 + 1;

	while (n > 0)
	{
		for (index1 = n; index1 < (long int) size; index1++)
		{
			temp = array[index1];
			for (index3 = index1; index3 >= n && array[index3 - n] > temp;
					index3 = index3 - n)
				array[index3] = array[index3 - n];
			array[index3] = temp;
		}
		print_array(array, size);
		n = (n - 1) / 3;
	}
}
