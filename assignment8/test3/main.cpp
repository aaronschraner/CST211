#include <iostream>
#include <cstdlib>
#include <chrono>
#include <fstream>
#include <list>

#include "BinaryTree.h"
#include "iterators.h"
#include "LinkedList.h"

using namespace std;

int main()
{
	cout << "Creating tree" << endl;
	BinaryTree<int> mytree;
	for(int i=0; i<10; i++)
	{
		mytree.Insert(i^5);
	}
	cout << mytree << endl;

	//using individual iterator types
	cout << "Iterating in-order" << endl;
	for (InOrderIterator<int> myIterator(mytree ); myIterator != mytree.end(); ++myIterator)
		cout << *myIterator << " ";
	cout << endl;

	cout << "Iterating pre-order" << endl;
	for (PreOrderIterator<int> myIterator (mytree); myIterator != mytree.end(); ++myIterator)
		cout << *myIterator << " ";
	cout << endl;

	cout << "Iterating post-order" << endl;
	for (PostOrderIterator<int> myIterator (mytree); myIterator != mytree.end(); ++myIterator)
		cout << *myIterator << " ";
	cout << endl;

	cout << "Iterating breadth-first" << endl;
	for (BreadthFirstIterator<int> myIterator (mytree); myIterator != mytree.end(); ++myIterator)
		cout << *myIterator << " ";
	cout << endl;


	//generic tree version (defaults to in-order traversal from beginning to end)
	cout << "Generic iteration" << endl;
	for(TreeIterator<int> myIterator = mytree.begin(); myIterator != mytree.end(); ++myIterator)
		cout << *myIterator << " ";
	cout << endl;

	//version using linked lists
	LinkedList<int> myList;
	for(TreeIterator<int> myIterator = mytree.begin(); myIterator != mytree.end(); ++myIterator)
		myList.Append(*myIterator);

	cout << "List iteration" << endl;
	for(Iterator<int> listIter = myList.Begin(); listIter != myList.End(); ++listIter)
		cout << *listIter << " ";
	cout << endl;

}
