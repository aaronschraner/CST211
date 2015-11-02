#include "CircularQueue.h"
#include <iostream>

using namespace std;

int main()
{
	//test circular queue by passing a bunch of numbers through it 10 at a time
	// (similar to dd bs=10 on UNIX machines)
	int blockSize=10;

	//create a circular queue with up to 10 elements
	CircularQueue <int> myCQ (blockSize);

	//pass 100 numbers through it
	for (int iteration = 0; iteration < 10; iteration++)
	{
		int i=iteration*blockSize;

		while(!myCQ.isFull())
			myCQ.Enqueue(i++);

		while(!myCQ.isEmpty())
			cout << myCQ.Dequeue() << " ";
	}
	cout << endl;

	//try to make the queue underflow
	cout << "Trying to underflow queue." << endl;

	try {
		cout << "This element shouldn't exist!" << myCQ.Dequeue() << endl;
	}
	catch (CircularQueue<int>::Error e)
	{
		if (e == CircularQueue<int>::_Underflow)
			cout << "Caught underflow exception" << endl;
	}

	//fill the queue
	while(!myCQ.isFull())
		myCQ.Enqueue(10);

	//try to make it overflow
	cout << "Trying to overflow queue." << endl;

	try {
		myCQ.Enqueue(9);
	}
	catch(CircularQueue<int>::Error e)
	{
		if (e == CircularQueue<int>::_Overflow)
			cout << "Caught overflow exception" << endl;
	}


}


