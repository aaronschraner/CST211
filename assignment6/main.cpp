#include <iostream>
#include <cstdlib>

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

int main()
{
	int number = 29;
	BinaryTree<int> mytree;
	for(int i=0; i<20; i++)
	{
		srand(time(NULL) + i);
		mytree.Insert(rand()%100);
	}
	cout << mytree << endl;

	TreeNode<int>* mynode = mytree.find(number);
	if(mynode)
		cout << "found " << mynode->getValue() << endl;
	else
		cout << "failed to find " << number << "." << endl;
	cout << "Tree is " << mytree.Height() << " nodes tall." << endl;
	mytree.Traverse(myFunc, BinaryTree<int>::_BreadthFirst);

}
