#include <iostream>
#include <cstdlib>
#include <chrono>
#include <fstream>

#include "BinaryTree.h"

using namespace std;

void display(int i)
{
	cout << i << " ";
}

void myFunc(TreeNode<int>& tn)
{
	cout << tn.getValue() << endl;
}

void testTraversalSpeed(int count);

int main()
{
	int number = 50;
	BinaryTree<int> mytree;
	for(int i=0; i<20; i++)
	{
		srand(time(NULL) + i);
		mytree.Insert(rand()%100);
		if(i==10)
			mytree.Insert(number);
	}
	cout << mytree << endl;

	TreeNode<int>* mynode = mytree.find(number);
	if(mynode)
		cout << "found " << mynode->getValue() << endl;
	else
		cout << "failed to find " << number << "." << endl;
	cout << "Tree is " << mytree.Height() << " nodes tall." << endl;
	cout << mytree << endl;
	mytree.Traverse(myFunc, BinaryTree<int>::_PreOrder);

	testTraversalSpeed(100000);

}


void doNothingFunc(TreeNode<int>& tn)
{
	//do nothing
}

//test time for each type of traversal
void testTraversalSpeed(int count)
{
	//create a tree with a lot of elements
	BinaryTree<int> mytree;
	for(int i=0; i<count; i++)
	{
		srand(time(NULL)+i);
		mytree.Insert(rand());
	}
	chrono::time_point<chrono::system_clock> start,end;

	for(int i=0; i <= 3; i++)
	{
		if (i==3)
			cout << "breadth first traversal takes a very long time..." << endl;
		start = chrono::system_clock::now();
		mytree.Traverse(doNothingFunc, (BinaryTree<int>::TraversalPath)i);
		end = chrono::system_clock::now();
		chrono::duration<double> elapsed_seconds = end - start;
		cout << "time for ";
		switch((BinaryTree<int>::TraversalPath)i)
		{
			case BinaryTree<int>::_InOrder:      cout << "In-order "; break;
			case BinaryTree<int>::_PreOrder:     cout << "Pre-order "; break;
			case BinaryTree<int>::_PostOrder:    cout << "Post-order "; break;
			case BinaryTree<int>::_BreadthFirst: cout << "Breadth-first "; break;
		}
		cout << "traversal with " << count << " elements: " << elapsed_seconds.count() << " seconds." << endl;
	}
	cout << "calculating tree height..." << endl;
	cout << "tree height: " << mytree.Height() << endl;
}

	

