#include "Iterator.h"
#include "Node.h"
#include "LinkedList.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "creating list" << endl;
	LinkedList<int> myList;

	cout << "appending ints" << endl;
	for(int i=9000; i<9010; i++)
		myList.Append(i);

	cout << "creating copy" << endl;

	LinkedList<int> listCopy;
	listCopy=myList;

	try 
	{

		listCopy.InsertAfter(9002, 9020);
	}
	catch (Exception e)
	{
		cout << "Error: " << e << endl;
	}


	cout << "printing the contents" << endl;
	for( auto it = myList.Begin(); *it; ++it)
		cout << (*it)->getContents() << endl;

	for( auto it = listCopy.Begin(); *it; ++it)
		cout << "copy: " << (*it)->getContents() << endl;

	cout << "checking if list is empty" << endl;
	cout << "List is " << (myList.isEmpty() ? "" : "not ") << "empty.\n";
}
