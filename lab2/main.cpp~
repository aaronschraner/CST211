#include "sorts.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>
#include <time.h>
#include <stdlib.h>


#include "sort.h"

using namespace std;

/********************************************************************************
 * int main(int argc, char* argv[]):
 *	Purpose: 
 *		driver program to test sorting algorithms
 *		Tests each sorting algorithm in sorts/ using the containers:
 *		 - vector
 *		 - Array (my class)
 *		 - C-array
 *
 *		and displays compute time required for each algorithm
 *	Entry: 
 *		Can take a number as first parameter. This corresponds to the number of 
 *		elements to be randomly generated and sorted (defaults to 16)
 *
 *	Exit: 
 *		Displays each algorithm as it is run with the container, algorithm, and
 *		compute time used.
 *	
 ********************************************************************************/
int main(int argc, char* argv[])
{
	ofstream logFile("sort.log");
	dualstream log(cout, logFile);
	//number of elements to create (defaults to 16)
	long numElements=16;

	//if the user gave a number as a parameter, use that many elements
	if (argc > 1)
		numElements=atol(argv[1]);

	//create a vector with the requested size and fill it with random numbers
	vector<int> myVector(numElements);
	for(int i=0; i<numElements; i++)
	{
		srand(time(NULL)+i);
		myVector[i]=rand();
	}

	//tell the user how many elements are being sorted
	log << "sorting array with " << numElements << " integers.\n" ;

	//if user wants to see all the elements that will be sorted (specified at compile time) 
	//show all the integers that will be sorted
#ifdef SHOWSORTS
	log << "Array to be sorted:\n" ;
	copy(myVector.begin(), myVector.end(), ostream_iterator<int>(cout, " "));
#endif

	log << "\n\n";


	//for each possible container type
	for (int ct = 0; ct < 3; ct++)
	{
		//for each possible sorting algorithm
		for (int sa = 0; sa < 7; sa++)
		{
			//sort a copy of the vector and display how long it takes
			sort(myVector, (ContainerType)ct, (SortingAlgorithm)sa, log);
		}
	}
	logFile.close();
}

