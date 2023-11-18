#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Displays the element of an array
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t index1;

    index1 = 0;
    while (array && index1 < size)
    {
        if (index1 > 0)
            printf(", ");
        printf("%d", array[index1]);
        ++index1;
    }
    printf("\n");
}
