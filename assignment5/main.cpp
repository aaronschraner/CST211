/********************************************************************************
 * 	Purpose: 
 * 		Driver file for array-based CircularQueue and linked list-based
 * 		Queue classes.
 * 		Tests the ability of both to:
 * 		- pass integers through the queue, appending and popping 10 at a time
 * 		- throw appropriate exceptions for under/overflow conditions
 * 	
 * 	Input: 
 * 		Requires no input from user
 * 	
 * 	Output: 
 * 		You should see the exact same output twice.
 * 		The first one is the List-based regular queue and the second one
 * 		is the array-based circular queue.
 * 		
 * 		You should see:
 * 		- the numbers 0 through 99, space separated
 * 		- the following text:
 *			Trying to underflow queue.
 *			Caught underflow exception
 *			Trying to overflow queue.
 *			Caught overflow exception
 *
 * 		That should be displayed twice when you run the program.
 * 	
 ********************************************************************************/
#include "CircularQueue.h"
#include "Queue.h"
#include <iostream>

using namespace std;

void testListQueue();
void testCircQueue();

int main()
{
	testListQueue();
	cout << endl;
	testCircQueue();
}

void testListQueue()
{
	//test circular queue by passing a bunch of numbers through it 10 at a time
	// (similar to dd bs=10 on UNIX machines)
	int blockSize=10;

	//create a circular queue with up to 10 elements
	Queue <int> myQueue (blockSize);

	cout << "trying to pass " << blockSize * 10 << " integers through the list-based queue" << endl;
	//pass 100 numbers through it
	for (int iteration = 0; iteration < 10; iteration++)
	{
		int i=iteration*blockSize;

		while(!myQueue.isFull())
			myQueue.Enqueue(i++);

		while(!myQueue.isEmpty())
			cout << myQueue.Dequeue() << " ";
	}
	cout << endl;

	//try to make the queue underflow
	cout << "Trying to underflow queue." << endl;

	try {
		cout << "This element shouldn't exist!" << myQueue.Dequeue() << endl;
	}
	catch (Queue<int>::Error e)
	{
		if (e == Queue<int>::_Underflow)
			cout << "Caught underflow exception" << endl;
	}

	//fill the queue
	while(!myQueue.isFull())
		myQueue.Enqueue(10);

	//try to make it overflow
	cout << "Trying to overflow queue." << endl;

	try {
		myQueue.Enqueue(9);
	}
	catch(Queue<int>::Error e)
	{
		if (e == Queue<int>::_Overflow)
			cout << "Caught overflow exception" << endl;
	}


}

void testCircQueue()
{
	//test circular queue by passing a bunch of numbers through it 10 at a time
	// (similar to dd bs=10 on UNIX machines)
	int blockSize=10;

	//create a circular queue with up to 10 elements
	CircularQueue <int> myCQ (blockSize);

	//pass 100 numbers through it
	cout << "trying to pass " << blockSize * 10 << " integers through the circular queue" << endl;
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
