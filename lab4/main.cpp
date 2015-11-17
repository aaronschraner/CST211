#include <iostream>
#include <cstdlib>
#include <chrono>
#include <fstream>

#include "BinaryTree.h"

using namespace std;

int main()
{
	int number = 50;
	BinaryTree<int> mytree;
	for(int i=0; i<number; i++)
	{
		srand(time(NULL) + i);
		int x=rand()%100;
		if(!mytree.find(x))
			mytree.Insert(x);
		else
			number++;
		
	}

	cout<< "a <number> to add number" << endl
		<< "b <number> to force balance() on that number" << endl
		<< "[ rr | lr | rl | ll ] <number> to force rotate a node" << endl;

	cout << mytree << endl;
	while(true)
	{
		char action;
		int num;
		cout << "> ";
		action = cin.get();
		cout << endl;
		switch(action)
		{
			case 'a':
				cout << "\nadd > ";
				cin >>num;
				mytree.Insert(num);
				cout << endl;
				break;
			case 'b':
				cout << "\nbalance > ";
				cin >> num;
				mytree.find(num)->balance();
				cout << endl;
				break;
			case 'r':
				cin >> action;
				cout <<  "rotating r" << action;
				cout << "element > ";
				cin >> num;
				mytree.find(num)->rotate(action=='r'?_RightRight:_RightLeft);
				cout << endl;
				break;
			case 'l':
				cin >> action;
				cout <<  "rotating l" << action << " [";
				cout << "element > ";
				cin >> num;
				mytree.find(num)->rotate(action=='r'?_LeftRight:_LeftLeft);
				cout << endl;
				break;
		}
		cout << mytree << endl;
	}
	

}


