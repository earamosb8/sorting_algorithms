#include "sort.h"
/**
 * quick_sort - sort array
 * @array: int array for sort
 * @size: length array
 */
void quick_sort(int *array, size_t size)
{
	int low = 0;
	int high = size - 1;

	recursion_qs(array, low, high, size);
}
/**
 * partition - part array
 * @arr: int array for sort
 * @low: numbers < pivot
 * @high: numbers < pivot
 * @size: length array
 * Return: int
 */
int partition(int arr[], int low, int high, size_t size)
{
	int pivot = arr[high];
	int i = (low - 1);
	int t = 0;
	int j = 0;

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
		}
	}
	t = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = t;
	print_array(arr, size);
	return (i + 1);
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
