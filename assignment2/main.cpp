/*******************************************************
 * Author: Aaron Schraner
 * Date created: 10/06/15
 * Last modification date: 10/10/15
 * Assignment: 2D array class
 * Filename: main.cpp
 *
 * purpose: Driver test routine for Array2D class
 *		Tests:
 *			- instantiation given 2D size
 *			- copy construction
 *			- const and mutable access
 *			- range-checking exceptions
 *			- assignment operator
 *			- default constructor
 *			- demonstrates an unavoidable memory problem with this class design
 *
 *
 *     _                         ____  ____  
 *    / \   _ __ _ __ __ _ _   _|___ \|  _ \
 *   / _ \ | '__| '__/ _` | | | | __) | | | |
 *  / ___ \| |  | | | (_| | |_| |/ __/| |_| |
 * /_/   \_\_|  |_|  \__,_|\__, |_____|____/ 
 *                         |___/             (test driver program)
 *
 *******************************************************/

#include <iostream>

#include "array2D.h"
#include "Exception.h"

using namespace std;

void test_2D_instantiation();
void test_copy_ctor();
void test_const_mut_access();
void test_range_checking();
void test_assignment_oper();
void test_default_ctor();

//demonstrates an inherent bug with this class design in certain usage cases
void how_to_break_this_class(); 

template <typename T> void printArrayInfo(const Array2D<T>& ar);



/*
 * Main routine for program
 * executes tests detailed in file header comment block
 */
int main()
{
	test_2D_instantiation();
	test_copy_ctor();
	test_const_mut_access();
	test_range_checking();
	test_assignment_oper();
	test_default_ctor();
	how_to_break_this_class();
}



/*************************************************************
 * void test_2D_instantiation()
 *		tests Array2D's constructor that takes rows and cols as parameters
 *****************************************************************/
void test_2D_instantiation()
{
	cout << "Testing constructor with size 2x4\n";
	//create an array with 2 rows and 4 columns
	Array2D <int> myArray (2, 4);

	//set the top left element equal to 100
	myArray[0][0] = 100;

	//print information about the array
	cout << "2x4 array with 100 in the top left:\n";
	printArrayInfo(myArray);
}

/*****************************************************************
 * void test_copy_ctor()
 *		tests the Array2D copy constructor 
 *****************************************************************/
void test_copy_ctor()
{
	cout << "Testing copy constructor.\n";
	//create a 3x3 array and fill it with unique data
	Array2D<int> myArray(3, 3);
	for(int i=0; i<9; i++)
		myArray[i/3][i%3] = i;
	
	//show the array to be copied
	cout << "Array to be copied:\n";
	printArrayInfo(myArray);

	//construct an array from myArray and show its contents
	Array2D<int> myOtherArray(myArray);
	cout << "Copied array:\n";
	printArrayInfo(myOtherArray);
}

/*****************************************************************
 * void test_const_mut_access()
 * test Array2D's const array access and verify that assigning values in a const array fails.
 * also test mutable array reading and writing
 *****************************************************************/
void test_const_mut_access()
{
	cout << "Testing const / mutable access.\n";

	//create a 2D array and fill it with unique data
	Array2D<int> myArray(4, 4);
	for(int i=0; i<16; i++)
		myArray[i/4][i%4] = 0x0F^i;
	printArrayInfo(myArray);

	//assign and print a value in a mutable array
	myArray[0][0] = 100;
	cout << "mutable array [0][0] = " << myArray[0][0] << endl;

	//use the copy constructor to create an identical constant array
	const Array2D<int> myConstArray(myArray);

	//assign a value in a const array
	//myConstArray[0][0] = 1; //causes compiler error
	
	//print the contents of the const array (only works if const accessor methods work)
	cout << "const array:\n";
	printArrayInfo(myConstArray);

}

/*********************************************************************
 * void test_range_checking()
 *		verifies that accessing values outside the range of the array
 *		throws an exception 
 *********************************************************************/
void test_range_checking()
{
	cout << "Testing range checking...\n";

	//create a 3x6 array and display it
	Array2D <int> myArray(3, 6);
	printArrayInfo(myArray);

	//list of values to test array access range checking
	int testrows [] = {0, 0, 0, 0, 0, -1, 0, 1, 2, 3};
	int testcols [] = {-1, 0, 2, 5, 6, 0, 0, 0, 0, 0};

	//show the size of the array
	cout << "(using a " << myArray.getRows() << "x" << myArray.getColumns() << " array)" << endl;

	//try to access all the coordinates specified by testrows[] and testcols[]
	for(int i=0; i < 10; i++)
	{
		cout << "Attempting to access array[" << testrows[i] << "][" << testcols[i]  << "]... ";
		try
		{
			cout << myArray[testrows[i]][testcols[i]];
		}
		catch (const Exception &e)
		{
			//display all exceptions encountered
			cout << "Failed with exception \"" << e << "\"";
		}
		cout << endl;
	}
}

/**********************************************************************
 * void test_assignment_oper()
 *		make sure the assignment operator works
 **********************************************************************/
void test_assignment_oper()
{
	//create an array with unique values
	cout << "Testing assignment operator.\n";
	Array2D <int> myArray(4, 4);
	for(int i=0; i<16; i++)
		myArray[i/4][i%4] = i;

	//print that array
	cout << "Array1 = Array2" << endl;
	cout << "Array2:" << endl;
	printArrayInfo(myArray);

	//assign an array to that one and print it
	Array2D <int> myOtherArray = myArray;
	cout << "Array1:" << endl;
	printArrayInfo(myOtherArray);
}

/***************************************************************************
 * void test_default_ctor()
 *		test the default constructor
 ***************************************************************************/
void test_default_ctor()
{
	cout << "Testing default constructor.\n";

	//create an array with the default ctor and print it
	Array2D <int> myArray;
	printArrayInfo(myArray);
}

/*****************************************************************
 * void how_to_break_this_class()
 * demonstrates a bug in which a Row's m_array2D can still point to a 2D array 
 * after the array has been de-allocated, resulting in undefined behavior
 *****************************************************************/
void how_to_break_this_class()
{
	cout << "Deallocated memory access bug:\n";
	Array2D <int> testArray (3, 3);
	Row <int> myRow(testArray, 0);
	{
		Array2D <int> myArray (3, 3);
		myArray[0][0] = 9001;

		myRow = myArray[0]; //everything is fine as long as you don't do this

		cout << "Value before array is deallocated: " << myRow[0] << endl;
	}
	cout << "Value after array is deallocated: " << myRow[0] << endl;
}


/********************************************************
 * void printArrayInfo(const Array2D &ar)
 *		prints information about an array like rows, columns, and contained elements
 *
 *****************************************************************/
template <typename T>
void printArrayInfo(const Array2D<T> &ar)
{
	//print array dimensions
	cout << "\t----- Rows: " << ar.getRows() << ", Columns: " << ar.getColumns() << " -----" << endl;

	//print array contents
	for (int r = 0; r < ar.getRows(); r++)
	{
		cout << "\t";
		for (int c = 0; c < ar.getColumns(); c++)
			cout << ar[r][c] << "\t";
		cout << endl;
	}
}


