#include <iostream>
#include <cstdlib>

#include "BinaryTree.h"

using namespace std;

void display(int i)
{
	cout << i << " ";
}

int main()
{
	BinaryTree<int> mytree;
	for(int i=0; i<20; i++)
	{
		srand(time(NULL) + i);
		mytree.Insert(rand()%100);
	}
	cout << mytree << endl;
}
