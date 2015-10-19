/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      October 16, 2015
 * Last Modified:     October 18, 2015
 * Lab Number:        3
 * Filename:          main.cpp
 * 
 * 	Overview: 
 * 		Driver file for linked list class
 * 		Tests the following LinkedList methods:
 * 		- isEmpty
 * 		- First() (mutable version)
 * 		- Last() (mutable version)
 * 		- Prepend()
 * 		- Append()
 * 		- Purge()
 * 		- Extract()
 * 		- InsertAfter()
 * 		- InsertBefore()
 * 		- Begin() (mutable version)
 * 		- End() (mutable version)
 * 		Also tests iterator++ functionality
 *
 * 		main() has comments explaining what each line does
 * 	
 * 	Input: 
 *		doesn't really have any input
 * 	
 * 	Output: 
 * 		tests various methods
 * 		you should see the numbers -9 to 9 with two 0's,
 * 		then the numbers 9 to -9 with only one 0
 * 		then the numbers 9001, 500, 420, -1000
 * 		then at the very end you should see lots of freed node containing [something] messages
 * 	
 ********************************************************************************/
// uncomment the following line to show node destructor calls
//#define VERBOSE
#include "Iterator.h"
#include "Node.h"
#include "LinkedList.h"
#include <iostream>
#include <string>

using namespace std;

/********************************************************************************
 * ostream& operator<<(ostream& os, const LinkedList<T>& ll):
 * 	Purpose: 
 * 		Stream output operator for linked list class
 * 		used only for demonstration purposes
 * 		(uses ++Iterator, *Iterator, Iterator=LinkedList::Begin(), isEmpty())
 * 		displays contents of a linked list in the same format as backDisp()
 * 		but from front to back instead of back to front
 * 		(head to tail instead of tail to head)
 * 	
 * 	Entry: 
 * 		ostream& os: the output stream to print the contents to
 * 		const LinkedList<T>& ll: the linked list to print
 * 	
 * 	Exit: 
 * 		outputs the contents of the list <ll>
 * 		uses same [element1] [element2] [element3] format as backDisp
 * 		except in the correct order
 * 	
 ********************************************************************************/
template <typename T>
ostream& operator<<(ostream& os, const LinkedList<T>& ll)
{
	// create a LinkedList iterator starting at the beginning of the list
	// and iterate through each element
	// this function tests/uses:
	//  - LinkedList::Begin()
	//  - Iterator dereferencing and incrementing
	//  - LinkedList::isEmpty()
	for( auto it = ll.Begin(); it.isValid(); ++it)
		os << "[" << *it << "] ";
	if ( ll.isEmpty())
		os << "<list is empty>";
	return os;
}

/********************************************************************************
 * ostream& backDisp(ostream& os, const LinkedList<T>& ll):
 * 	Purpose: 
 * 		Display a linked list using iterators moving from End() to Begin()
 * 		(tests iterator functionality)
 * 	
 * 	Entry: 
 * 		ostream& os: the output stream to print the list to
 * 		const LinkedList<T>& ll: the list to be printed
 * 	
 * 	Exit: 
 * 		outputs the contents of the list with each element in square
 * 		brackets (eg: [element1] [element2] [element3])
 * 		outputs <list is empty> if list is empty
 * 	
 ********************************************************************************/
template <typename T>
ostream& backDisp(ostream& os, const LinkedList<T>& ll)
{
	// works exactly the same as operator<< with same arguments
	// but in reverse
	// this function tests/uses:
	//  - LinkedList::End()
	//  - Iterator dereferencing (const)
	//  - LinkedList::isEmpty()
	//  - Iterator decrementing (operator--) 
	for( auto it= ll.End(); it.isValid(); --it)
		os << "[" << *it << "] ";
	if ( ll.isEmpty())
		os << "<List is empty>";
	return os;
}

void oldLoop();

/********************************************************************************
 * int main():
 * 	Purpose: 
 * 		main test program for this class
 * 		- creates a list
 * 		- appends the numbers 0-9 to it
 * 		- prepends the numbers -9 to 0
 * 		- displays what the list looks like
 * 		- removes one of the 0's
 * 		- displays the list backwards
 * 		- clears the list
 * 		- appends 9001 and -1000 to the now empty list
 * 		- inserts a 500 before the number -1000
 * 		- inserts a 360 after the number 9001
 * 		- displays the list
 * 		- calls oldLoop()
 * 		- destructs all nodes in the list
 * 	
 * 	Entry: 
 * 		nothing really
 * 	
 * 	Exit: 
 * 		should display output that makes sense with that ^^^
 * 	
 ********************************************************************************/
int main()
{
	//create a new empty list
	LinkedList<int> myList;

	//append the numbers 0 through 9 to the end of the list
	// (uses LinkedList::Append())
	for(int i=0; i<10; i++)
		myList.Append(i);

	//prepend the numbers -9 to 0 to the start of the list
	// (uses LinkedList::Prepend())
	for(int i=0; i<10; i++)
		myList.Prepend(-i);

	//display the list (front to back)
	cout << myList << endl;

	//remove the first 0 in the list
	delete &myList.Extract(0);

	//display the list (back to front)
	backDisp(cout, myList) << endl;

	//clear the list 
	myList.Purge();

	//add the numbers 9001 and -1000 to the list
	myList.Append(9001);
	myList.Append(-1000);

	//insert the number 500 after -1000
	myList.InsertBefore(-1000, 500);

	//insert the number 360 after 9001
	myList.InsertAfter(9001, 360);

	//show the list
	cout << myList << endl;
	oldLoop();

}

/********************************************************************************
 * void oldLoop():
 * 	Purpose: 
 * 		some code I first used to test the class
 * 		called oldLoop() because it is older than the current main()
 * 	
 * 	Entry: 
 * 		nothing
 * 	
 * 	Exit: 
 * 		(verbosely states what it is doing)
 * 		- creates a list
 * 		- appends the numbers 9000-9009 to it
 * 		- creates a copy of the list with the assignment operator =
 * 		- attempts to insert the number 9020 after 9002
 * 		(throws error if 9002 isn't in there for some reason)
 * 		- prints the contents of the first list with an iterator for loop
 * 		- prints the contents of the copy with another iterator based loop
 * 		- says if isEmpty() actually knows that the list is empty
 * 		- (implicitly) calls destructor on list, destroying all nodes
 * 	
 ********************************************************************************/
void oldLoop()
{
	//create an empty list
	cout << "creating list" << endl;
	LinkedList<int> myList;

	//append the numbers 9000-9009 to it
	cout << "appending ints" << endl;
	for(int i=9000; i<9010; i++)
		myList.Append(i);

	//make a copy of it using operator=
	cout << "creating copy" << endl;
	LinkedList<int> listCopy;
	listCopy=myList;

	try 
	{
		//insert the number 9020 after 9002
		listCopy.InsertAfter(9002, 9020);
	}
	catch (Exception e)
	{
		cout << "Error: " << e << endl;
	}


	//print the list and its copy
	cout << "printing the contents" << endl;
	for( auto it = myList.Begin(); it.isValid(); ++it)
		cout << *it << endl;

	for( auto it = listCopy.Begin(); it.isValid(); ++it)
		cout << "copy: " << *it << endl;

	//check if the list is empty
	cout << "checking if list is empty" << endl;
	cout << "List is " << (myList.isEmpty() ? "" : "not ") << "empty.\n";
}
