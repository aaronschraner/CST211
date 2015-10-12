#include "tempfun.h"
#include <iostream>

using namespace std;

int main()
{
	int myArray[10];

	fillArray(myArray, 9, 10);

	cout << "Filled array:\n";
	for(int i=0; i<10; i++)
		cout << myArray[i] << endl;

	int* myArray2 = mkArray(8, 10);

	cout << "Created array:\n";
	for(int i=0; i<10; i++)
		cout << myArray2[i] << endl;
	int b=20;
	int a;
	a=*&b;
	cout << a << endl;

}
