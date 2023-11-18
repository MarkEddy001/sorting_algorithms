#include "sort.h"
#include <stdlib.h>

/**
 * pow_10 - Computes a positive power of 10.
 * @power: The exponent for the power of 10 to calculate.
 *
 * Return: The result of the corresponding power of 10.
 */
unsigned int pow_10(unsigned int power)
{
        unsigned int index1, result;

        result = 1;
        for (index1 = 0; index1 < power; index1++)
                result *= 10;
        return (result);
}

/**
 * count_sort - Applies the Counting Sort algorithm to arrange an
 *              array of integers in ascending order based on a
 *              specific digit location.
 * @array: The array to be sorted.
 * @size: The size of the array to be sorted.
 * @digit: The digit to sort by.
 *
 * Return: 1 if further sorting is needed, 0 otherwise.
 */
unsigned int count_sort(int *array, size_t size, unsigned int digit)
{
	int index1, count[10] = {0};
	int *copy = NULL;
	size_t index2, temp, total = 0;
	unsigned int dp1, dp2, sort = 0;

	dp2 = pow_10(digit - 1);
	dp1 = dp2 * 10;
	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		exit(1);
	for (index2 = 0; index2 < size; index2++)
	{
		copy[index2] = array[index2];
		if (array[index2] / dp1 != 0)
			sort = 1;
	}
	for (index1 = 0; index1 < 10 ; index1++)
		count[index1] = 0;
	for (index2 = 0; index2 < size; index2++)
		count[(array[index2] % dp1) / dp2] += 1;
	for (index1 = 0; index1 < 10; index1++)
	{
		temp = count[index1];
		count[index1] = total;
		total += temp;
	}
	for (index2 = 0; index2 < size; index2++)
	{
		array[count[(copy[index2] % dp1) / dp2]] = copy[index2];
		count[(copy[index2] % dp1) / dp2] += 1;
	}
	free(copy);
	return (sort);
}

/**
 * radix_sort - Applies the Radix Sort algorithm to arrange
 *              an array of integers in ascending order.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
        unsigned int index1, sort = 1;

        if (array == NULL || size < 2)
                return;
        for (index1 = 1; sort == 1; index1++)
        {
                sort = count_sort(array, size, index1);
                print_array(array, size);
        }
}
