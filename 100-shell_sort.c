#include "sort.h"

/**
 * shell_sort - sort list with shell sort
 * @array: a list for sort
 * @size: size the list
 **/

void shell_sort(int *array, size_t size)
{
	int inner, outer, valueToInsert;
	int interval = 1;
	int elements = size;
	int i = 0;

	if (array == NULL || size < 2)
		return;

	while (interval <= elements / 3)
	{
		interval = interval * 3 + 1;
	}

	while (interval > 0)
	{

		for (outer = interval; outer < elements; outer++)
		{
			valueToInsert = array[outer];
			inner = outer;

			while (inner > interval - 1 && array[inner - interval]
			       >= valueToInsert)
			{
				array[inner] = array[inner - interval];
				inner -= interval;
			}

			array[inner] = valueToInsert;
		}
		print_array(array, size);

		interval = (interval - 1) / 3;
		i++;

	}
}
