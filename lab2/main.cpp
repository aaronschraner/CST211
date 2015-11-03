#include "sorts.h"
#include <vector>
#include <iostream>
#include <iterator>


using namespace std;

template <typename T>
void sort (Sortable<T> array, SortingAlgorithm algorithm)
{
	cout << " using [";
	switch(algorithm)
	{
		case _BubbleSort: cout << "bubble sort"; break;
		case _SelectionSort: cout << "selection sort"; break;
		case _InsertionSort: cout << "insertion sort"; break;
		case _ShellSort: cout << "shell sort"; break;
		case _HeapSort: cout << "heap sort"; break;
		case _MergeSort: cout << "merge sort"; break;
		case _QuickSort: cout << "quick sort"; break;
	}
	cout << "]." << endl;

	static void (* SortingAlgorithms [])(Sortable<T>) = {
		bruteForceBubbleSort, selectionSort, insertionSort, shellSort, heapSort, mergeSort, quickSort};

	(SortingAlgorithms[algorithm])(array);
	cout << array << endl << endl;


}

template <typename T>
void sort (vector<T> &array, ContainerType container, SortingAlgorithm algorithm)
{
	switch(container)
	{
		case _vector:
			{
				cout << "Sorting [vector]";
				vector<T> myvec = array;
				sort(Sortable<T>(myvec), algorithm);
			}
			break;

		case _myarray:
			{
				cout << "Sorting [custom array]";
				Array<T> myArray(array.size(), 0);
				for(int i=0; i<array.size(); i++)
					myArray[i]=array[i];
				sort(Sortable<T>(myArray), algorithm);
			}
			break;

		case _carray:
			{
				cout << "Sorting [c-array]";
				T* cArray = new T [array.size()];
				for(int i=0; i<array.size(); i++)
					cArray[i] = array[i];
				sort(Sortable<T>(cArray, array.size()), algorithm);
			}
			break;

	}

}


int main()
{

	vector<int> myVector;
	for(int i=0; i<16; i++)
		myVector.push_back(i^5);

	int myCarray [16] ;
	for(int i=0; i<16; i++)
		myCarray[i]=myVector[i];

	cout << "Array to be sorted:" << endl;
	copy(myVector.begin(), myVector.end(), ostream_iterator<int>(cout, " "));
	cout << endl << endl;

	for (int ct = 0; ct < 3; ct++)
	{
		for (int sa = 0; sa < 7; sa++)
		{
			sort(myVector, (ContainerType)ct, (SortingAlgorithm)sa);
		}
	}





}

