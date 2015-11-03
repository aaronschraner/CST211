#ifndef BUBBLE_H
#define BUBBLE_H

#include "swap.h"
#include "sortable_polymorphism.h"

POLYMORPHISM(bruteForceBubbleSort);

template <typename T>
void bruteForceBubbleSort(Sortable<T> array)
{
	bool isSorted=false;
	while(!isSorted)
	{
		isSorted = true;
		for(int i=0; i<array.size - 1; i++)
		{
			if (array[i] > array[i+1])
			{
				isSorted = false;
				swap(array[i], array[i+1]);
			}
		}
	}

}



template <typename T>
void flaggedBubbleSort(std::vector<T> &array)
{
	//TODO
	//I have no idea what a flagged bubble sort is.
}


#endif
