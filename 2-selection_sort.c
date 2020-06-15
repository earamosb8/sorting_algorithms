#include "sort.h"
/**
 * selection_sort - organise list with selection sort
 * @array: a list for sort
 * @size: size the list
 */

void selection_sort(int *array, size_t size)
{
	size_t j, i, m;
	int tmp = 0;

	if (array == NULL)
	{
		return;
	}

	for (i = 0; i < size; i++)
	{
		m = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[m])
			{
				m = j;
			}
		}
		tmp = array[i];
		array[i] = array[m];
		array[m] = tmp;

		print_array(array, size);
	}
}
