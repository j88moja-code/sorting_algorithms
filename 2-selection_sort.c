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
  * selection_sort -  sorts an array of ints in an ascending order using
  *			the selection sort algorithm.
  *
  * @array: an array of integers.
  * @size: the size of the array.
  *
  * Return: nothing.
  */

void selection_sort(int *array, size_t size)
{
	int *x;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		x = array + i;
		for (j = i + 1; j < size; j++)
			x = (array[j] < *x) ? (array + j) : x;

		if ((array + i) != x)
		{
			swap(array + i, x);
			print_array(array, size);
		}
	}
}

