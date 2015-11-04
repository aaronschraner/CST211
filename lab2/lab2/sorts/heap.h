#ifndef HEAP_H
#define HEAP_H
#include "swap.h"
#include "sortable_polymorphism.h"

//make it accept vectors, C-arrays, and Arrays as arguments
POLYMORPHISM (heapSort);

template <typename T>
void siftDown(Sortable<T> array, int start, int end)
{
	int root=start;
	while (root * 2 + 1 <= end)
	{
		int child = root * 2 + 1;
		int swapIndex = root;
		if (array[swapIndex] < array[child])
			swapIndex = child;

		if(child + 1 <= end && array[swapIndex] < array[child + 1])
			swapIndex = child + 1;
		if ( swapIndex == root)
			return;
		else
		{
			swap(array[root], array[swapIndex]);
			root=swapIndex;
		}
	}


}

template <typename T>
void heapify(Sortable<T> array, int count)
{
	int start = ((count - 2) / 2);
	while (start >= 0)
	{
		siftDown(array, start, count - 1);
		start--;
	}
}

template <typename T>
void heapSort(Sortable<T> array)
{
	heapify(array, array.size);

	int end = array.size - 1;
	while (end > 0)
	{
		swap(array[end], array[0]);
		end--;
		siftDown(array, 0, end);
	}
}

#endif
