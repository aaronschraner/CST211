#ifndef INSERTION_H
#define INSERTION_H
#include "swap.h"
#include "sortable_polymorphism.h"

POLYMORPHISM(insertionSort);

template <typename T>
void insertionSort(Sortable<T> array)
{
	int j,compare;

	for(int i=0; i<array.size ; i++)
	{
		j = i;
		while (j > 0 && array[j-1] > array[j])
		{
			swap(array[j], array[j-1]);
			j--;
		}
	}

}


#endif
