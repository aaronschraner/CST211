#ifndef SORTS_H
#define SORTS_H

#include "sorts/bubble.h"
#include "sorts/selection.h"
#include "sorts/insertion.h"
#include "sorts/shell.h"
#include "sorts/heap.h"
#include "sorts/merge.h"
#include "sorts/quick.h"
//TODO: finish heap and merge sorts

enum SortingAlgorithm
{
	_BubbleSort = 0,
	_SelectionSort = 1,
	_InsertionSort = 2,
	_ShellSort = 3,
	_HeapSort = 4,
	_MergeSort = 5,
	_QuickSort = 6
};

enum ContainerType
{
	_vector = 0,
	_myarray = 1,
	_carray = 2
};


#endif
