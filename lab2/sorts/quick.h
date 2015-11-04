
#ifndef QUICK_H
#define QUICK_H
#include "swap.h"
#include "sortable_polymorphism.h"

POLYMORPHISM (quickSort);

template <typename T>
int partition(Sortable<T> array, int low, int high)
{
	int pivot = array[low];
	int i = low ; 
	int j = high ;

	while (true)
	{
		while (array[j] > pivot)
			j--;

		while(array[i] < pivot)
			i++;

		if(i < j)
			swap(array[i], array[j]);
		else
			return j;
	}

}

template <typename T>
void quickSort(Sortable<T> array)
{
	quickSort(array, 0, array.size - 1);
}

template <typename T>
void quickSort(Sortable<T> array, int low, int high)
{
	if ( low < high )
	{
		int p = partition (array, low, high);
		quickSort(array, low, p);
		quickSort(array, p+1, high);
	}

}



#endif

