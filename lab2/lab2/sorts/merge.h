#ifndef MERGE_H
#define MERGE_H
#include "swap.h"
#include "sortable_polymorphism.h"

//make it accept vectors, C-arrays, and Arrays as arguments
POLYMORPHISM (mergeSort);

template <typename T>
void merge(Sortable<T> array, int begin, int middle, int end, std::vector<T> &temp)
{
	int i0 = begin, i1 = middle;

	for(int j=begin; j < end; j++)
	{
		if (i0 < middle && (i1 >= end || array[i0] <= array[i1]))
		{
			temp[j] = array[i0];
			i0++;
		}
		else
		{
			temp[j] = array[i1];
			i1++;
		}
	}
}

template <typename T>
void copy(std::vector<T> &temp, int begin, int end, Sortable<T> array)
{
	for(int i=begin; i<end; i++)
		array[i]=temp[i];
}

template <typename T>
void splitMerge(Sortable<T> array, int begin, int end, std::vector<T> &temp)
{
	if (end - begin < 2)
		return;
	int middle = (end + begin) / 2;
	splitMerge(array, begin, middle, temp);
	splitMerge(array, middle, end, temp);
	merge(array, begin, middle, end, temp);
	copy(temp, begin, end, array);
}

template <typename T>
void mergeSort(Sortable<T> array)
{
	std::vector<T> temp(array.size);
	splitMerge(array, 0, array.size , temp);
}

#endif

