#include "sort.h"

/**
  * swap - swaps the integers in an array.
  *
  * @xp: pointer to the current int.
  * @yp: pointer to the next int.
  *
  * Return: nothing.
  */

static void swap(int *xp, int *yp)
{
	int temp = *xp;

	*xp = *yp;
	*yp = temp;
}

/**
  * bubble_sort - sorts an array of integers in ascending order.
  *
  * @array: pointer to the array of integers to be sorted.
  * @size: size of the array.
  *
  * Return: nothing.
  */

void bubble_sort(int *array, size_t size)
{
	size_t i, j = size;
	bool bubble = false;

	if (array == NULL || size < 2)
		return;

	while (bubble == false)
	{
		bubble = true;
		for (i = 0; i < j - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(array + i, array + i + 1);
				print_array(array, size);
				bubble = false;
			}
		}
		j--;
	}
}
