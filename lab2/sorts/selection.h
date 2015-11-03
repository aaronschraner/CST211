#ifndef SELECTION_H
#define SELECTION_H
#include "swap.h"
#include "sortable_polymorphism.h"

POLYMORPHISM(selectionSort);

template <typename T>
void selectionSort(Sortable<T> array)
{
	int smallestIndex;
	for(int i=0; i<array.size; i++)
	{
		smallestIndex=i;
		for(int j=i; j < array.size; j++)
			if(array[j] < array[smallestIndex])
				smallestIndex = j;
		swap(array[smallestIndex], array[i]);
	}
}

#endif
