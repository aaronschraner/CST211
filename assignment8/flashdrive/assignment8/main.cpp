#include <iostream>
#include <cstdlib>
#include <chrono>
#include <fstream>

#include "BinaryTree.h"
#include "traversals.h"

using namespace std;

int main()
{
	{
		BinaryTree<int>* myTreePtr = new BinaryTree<int>;
		BinaryTree<int> &myTree = *myTreePtr;
		for(int i=0; i<16; i++)
			myTree.Insert((i^0x5)*10);
		cout << myTree << endl;
		cout << "creating tree iterator" << endl;
		{
			Iterator<int> myIterator = myTree.getIterator(BinaryTree<int>::_InOrder);
			cout << "looping" << endl;

			for(;myIterator.isValid(); ++myIterator)
			{
				cout << "loop entered" << endl;

				cout << *myIterator << endl;

				cout << "loop exited" << endl;
			}
			cout << "left loop" << endl;
		}
		cout << "destroyed iterator" << endl;
		delete myTreePtr;
	}
	cout << "destroyed tree" << endl;
}


