#include "Iterator.h"
#include "Node.h"
#include "LinkedList.h"
#include <iostream>

using namespace std;

int main()
{
	/*
	Node<int>* myNode = new Node<int>(32);
	Node<int>* itnode = myNode;
	for ( int i=0; i<10 ; i++)
	{
		itnode -> append ( new Node<int>(i*10) );
		itnode = itnode -> getNext();
	}

	for (Iterator<int> it (myNode); *it; ++it)
		cout << (*it)->getContents() << endl;

	while(myNode->getNext())
		myNode->deleteNext();
	delete myNode;
	*/
	cout << "creating list" << endl;
	LinkedList<int> myList;

	cout << "appending ints" << endl;
	for(int i=9000; i<9010; i++)
		myList.Append(i);

	LinkedList<int> listCopy = myList;

	cout << "printing the contents" << endl;
	for( auto it = myList.Begin(); *it; ++it)
		cout << (*it)->getContents() << endl;

	for( auto it = listCopy.Begin(); *it; ++it)
		cout << "copy: " << (*it)->getContents() << endl;

	cout << "checking if list is empty" << endl;
	cout << "List is " << (myList.isEmpty() ? "" : "not ") << "empty.\n";
	myList.Purge();
	cout << "List is " << (myList.isEmpty() ? "" : "not ") << "empty.\n";
}
