#ifndef SORT_H
#define SORT_H

#include "sorts.h"
#include <vector>
#include "Array.h"
#include "dualstream.h"
#include "sortable.h"
#include <time.h>

/********************************************************************************
 * void sort (Sortable<T> array, SortingAlgorithm algorithm, std::ostream& log):
 *	Purpose: 
 *		Sort the array <array> using the sorting algorithm <algorithm>
 *		Designed to only be called by sort(vector<T>, ContainerType, SortingAlgorithm)
 *
 *	Entry: 
 *		Sortable<T> array: the array to be sorted 
 *		SortingAlgorithm algorithm: the enumerated value corresponding to the
 *			sorting algorithm that should be used to sort <array>.
 *		std::ostream& log: the stream that information should be outputted to
 *	
 *	Exit: 
 *		Performs an in-place sort on the container referenced in <array> and
 *		exits.
 *		
 *	
 ********************************************************************************/
template <typename T>
void sort (Sortable<T> array, SortingAlgorithm algorithm, dualstream& log)
{
	//say what algorithm is being used
	log << " using [";
	switch(algorithm)
	{
		case _BubbleSort: log << "bubble sort"; break;
		case _SelectionSort: log << "selection sort"; break;
		case _InsertionSort: log << "insertion sort"; break;
		case _ShellSort: log << "shell sort"; break;
		case _HeapSort: log << "heap sort"; break;
		case _MergeSort: log << "merge sort"; break;
		case _QuickSort: log << "quick sort"; break;
	}
	log << "].\n" ;

	//array of function pointers to sorting algorithms
	//SortingAlgorithm enum value corresponds to the index of that algorithm in this array. 
	static void (* SortingAlgorithms [])(Sortable<T>) = {
		bruteForceBubbleSort, selectionSort, insertionSort, shellSort, heapSort, mergeSort, quickSort};

	// clock time values to store start and end times of sorting
	clock_t start, end;
	double cpu_time_used;

	//record the start time
	start = clock();
	
	//sort the array with the requested algorithm
	(SortingAlgorithms[algorithm])(array);

	//record the end time
	end = clock();

	//calculate the CPU time used
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

	//if the user wants to see the sorted arrays, print them out. 
#ifdef SHOWSORTS
	log << array;
#endif

	//say how long the sort took.
	log << "(sorting took " << cpu_time_used << " CPU seconds)\n\n";


}

/********************************************************************************
 * void sort (vector<T> &array, ContainerType container, SortingAlgorithm algorithm, std::ostream& log)
 *	Purpose: 
 *		Create a copy of <array> in a container type specified by <container>
 *		and sort it using the sorting algorithm <algorithm>
 *		
 *	Entry: 
 *		vector<T> &array: the numbers to be copied and sorted
 *		ContainerType container: the type of container the elements should be copied
 *			into for sorting. 
 *		SortingAlgorithm algorithm: the algorithm that should be used to sort. 
 *		log: the dual stream to output to
 *	
 *	Exit: 
 *		
 *	
 ********************************************************************************/
template <typename T>
void sort (std::vector<T> &array, ContainerType container, SortingAlgorithm algorithm, dualstream& log)
{
	switch(container)
	{
		//if the user wants to sort a vector...
		case _vector:
			{
				//say what container is being used
				log << "Sorting [vector]";

				//create a vector copy of <array>
				std::vector<T> myvec = array;

				//sort it 
				sort(Sortable<T>(myvec), algorithm,log);
			}
			break;

		//if the user wants to sort my Array class from assignment 1...
		case _myarray:
			{
				//say what container is being used
				log << "Sorting [custom array]";

				//create a copy of the array in the specified container
				Array<T> myArray(array.size(), 0);
				for(int i=0; i<array.size(); i++)
					myArray[i]=array[i];

				//sort it
				sort(Sortable<T>(myArray), algorithm, log);
			}
			break;

		// if the user wants to sort a C-array...
		case _carray:
			{
				//say what container is being used
				log << "Sorting [c-array]";

				//create a C-array copy of <array>
				T* cArray = new T [array.size()];
				for(int i=0; i<array.size(); i++)
					cArray[i] = array[i];

				//sort the copy
				sort(Sortable<T>(cArray, array.size()), algorithm,log);
			}
			break;
	}
}
#endif
