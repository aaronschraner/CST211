//Author: Aaron Schraner
//Date: September 30, 2015
//Purpose: Main function to test functionality of Array class

#include <iostream>
#include <iomanip>
#include "Array.h"

using namespace std;

void print_array_stats(const Array<int>& ar);
void test_ctors();
void test_operators();
void test_setters();

//WARNING: This was designed to work with the included Makefile. 
//Uncomment the following three lines if you are not using it.
//#define TEST_CTORS
//#define TEST_OPERS
//#define TEST_SETTERS

int main()
{
#ifdef TEST_CTORS
	cout << "Press enter to test constructors...";
	cin.get();
	test_ctors();
#endif

#ifdef TEST_OPERS
	cout << "Press enter to test operators...";
	cin.get();
	test_operators();
#endif

#ifdef TEST_SETTERS
	cout << "Press enter to test setters...";
	cin.get();
	test_setters();
#endif

	cout << "Press enter to exit...";
	cin.get();
	return 0;

}

void test_ctors()
{
	//default constructor
	{
		//create array with default constructor
		Array<int> myArray;

		//print information about the array
		cout << "Default constructor test:\n";
		print_array_stats(myArray);
		cout << endl;
	}

	//constructor given length and start index
	{
		Array<int> myArray(6, -3);
		cout << "Valued constructor test with 6, -3:\n";
		print_array_stats(myArray);
		cout << endl;

	}

	//copy constructor
	{
		cout << "Copy constructor test:\n";

		//create a unique array
		Array <int> sourceArray(5, -2);
		sourceArray[-1] =   9;
		sourceArray[0]	=  99;
		sourceArray[1]	= 998;

		//print the source array
		cout << "Source array:\n";
		print_array_stats(sourceArray);

		//create and print the destination array
		Array <int> destArray(sourceArray);
		cout << "Destination array:\n";
		print_array_stats(destArray);
		cout << endl;
	}




}

void print_array_stats(const Array<int>& ar)
{
	try {
		for(int i = ar.getStartIndex(); 
				i < ar.getStartIndex() + ar.getLength(); i++)
			cout << "\tarray [" << setw(3) << right << i << "] = " 
				<< ar[i] << endl;

		//print the array's starting index and length
		cout <<  "\tlength: " << ar.getLength() << endl 
			<< "\tstart index: " << ar.getStartIndex() << endl;
			
	}
	catch(Exception e)
	{
		cout << "Exception occurred in print_array_stats():\n"
			<< e << endl;
	}
}

void test_operators()
{
	//operator=
	{
		cout << "Testing assignment operator:\n";

		//create 2 different arrays
		Array <int> array1(3, -1);
		array1[0] = 92;
		Array <int> array2(2, 3);
		array2[4] = 11;

		//show both arrays in the assignment
		cout << "\tLHS = RHS\nLHS:\n";
		print_array_stats(array1);
		cout << "RHS:\n";
		print_array_stats(array2);

		array1 = array2;

		//show the result
		cout << "result:\n";
		print_array_stats(array1);
		cout << endl;
	}

	//operator[]
	{
		cout << "Testing index operator []:\n";
		Array<int> myArray(5, 0);

		cout << "Setting element 0 to 9900\n";
		myArray[0] = 9900;
		print_array_stats(myArray);

		cout << "Changing element 0 to 1234\n";
		myArray[0] = 1234;
		print_array_stats(myArray);
		
		cout << endl;

		//test range checking
		cout << "Testing range checking\n"
			<< "\tattempting to access array[5]\n";
		try { cout << myArray[5] << endl; }
		catch (Exception e)
		{
			cout << "\tCaught exception:\n\t\t" << e << endl;
		}

		cout << "\tattempting to access array[-1]\n";
		try { cout << myArray[-1] << endl; }
		catch (Exception e) 
		{
			cout << "\tCaught exception:\n\t\t" << e << endl;
		}

	}

}

void test_setters()
{
	//test setLength()
	cout << "Testing setLength\n";
	cout << "\tStarting array:\n";

	//create a unique array with length 5 and starting index 6
	Array <int> myArray (5, 6);
	for(int i=6; i<11; i++)
		myArray[i]=i;
	print_array_stats(myArray);
	cout << endl;

	//resize it to 11 elements
	cout << "Resizing to 11 elements.\n";
	myArray.setLength(11);
	print_array_stats(myArray);
	cout << endl;

	//resize it to 3 elements
	cout << "Resizing to 3 elements.\n";
	myArray.setLength(3);
	print_array_stats(myArray);
	cout << endl;

	//change the start index to -3
	cout << "Setting start index to -3\n";
	myArray.setStartIndex(-3);
	print_array_stats(myArray);
	cout << endl;
}
