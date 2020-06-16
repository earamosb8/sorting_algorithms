#include "sort.h"
/**
 * quick_sort - sort array
 * @array: int array for sort
 * @size: length array
 */
void quick_sort(int *array, size_t size)
{
	recursion_qs(array, 0, size - 1, size);
}
/**
 * partition - part array
 * @arr: int array for sort
 * @low: numbers < pivot
 * @high: numbers < pivot
 * @size: length array
 * Return: int
 */
int partition(int *arr, int low, int high, size_t size)
{
	int pivot = arr[high];
	int i = (low - 1);
	int t, j;

	for (j = low; j < high; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			if (i != j)
			{
				t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
				print_array(arr, size);
			}
		}
	}
	i++;
	if (i != j)
	{
		t = arr[i];
		arr[i] = arr[high];
		arr[high] = t;
		print_array(arr, size);
	}
	return (i);
}
/**
 * recursion_qs - recursive sort function
 * @arr: int array for sort
 * @low: numbers < pivot
 * @high: numbers < pivot
 * @size: length array
 * Return: int
 */
void recursion_qs(int arr[], int low, int high, size_t size)
{
	int pi = 0;

	if (low < high)
	{
		pi = partition(arr, low, high, size);
		recursion_qs(arr, low, pi - 1, size);
		recursion_qs(arr, pi + 1, high, size);
	}
}
