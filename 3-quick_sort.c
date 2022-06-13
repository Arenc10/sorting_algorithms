#include "sort.h"
/**
 * partition - Function that takes last el as pivot, and sorts based on it
 * @arr: Array that is going to be sorted
 * @low: Lowest int of the array
 * @high: Highest int of the array
 * @size: Size of the array
 * Return: Returns an int
 */
int partition(int arr[], int low, int high, size_t size)
{
	int j;
	int tmp;
	int tmp2;
	int pivot;
	int i = (low - 1);

	pivot = arr[high];
	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
				print_array(arr, size);
			}
		}
	}
	if (arr[high] < arr[i + 1])
	{
		tmp2 = arr[i + 1];
		arr[i + 1] = arr[j];
		arr[j] = tmp2;
		print_array(arr, size);
	}
	return (i + 1);
}
/**
 * lmtSort - Lomuto Sort
 * @arr: Array to be sorted
 * @low: Lowest int in the array
 * @high: Highest int in the array
 * @size: Size of the array
 */

void lmtSort(int arr[], int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = partition(arr, low, high, size);
		lmtSort(arr, low, pi - 1, size);
		lmtSort(arr, pi + 1, high, size);
	}
}
/**
 * quick_sort - Quick sort sorting algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lmtSort(array, 0, size - 1, size);
}
