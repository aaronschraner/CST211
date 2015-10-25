/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      October 24, 2015
 * Last Modified:     October 24, 2015
 * Assignment number: 4 Stacks
 * Filename:          main.cpp
 * 
 * 	Overview: 
 * 		This program tests the Stack class's functionality
 * 		it does this by:
 * 		- creating an empty stack with a maximum capacity of 10 elements
 * 		- adding 10 elements to the stack
 * 		- checking if it is empty/full
 * 		- trying to add another element (should fail)
 * 		- Clearing the stack by popping everything off
 * 		- checking if it's empty
 * 		- try popping an element off the empty list
 * 	
 * 	Input: 
 * 		Doesn't take any input from user
 * 	
 * 	Output: 
 * 		Output should make sense with description in Overview section
 * 	
 ********************************************************************************/

#include "Stack.h"
#include <iostream>

using namespace std;


typedef typename Stack<int>::Error StackError;

void handleException(StackError e)
{
	switch(e)
	{
		case Stack<int>::_Overflow:
			cout << "Stack has overflowed!" << endl;
			break;
		case Stack<int>::_Underflow:
			cout << "Stack has underflowed!" << endl;
			break;
	}
}

template <typename T>
void checkEmptyFull(const Stack<T>& stack)
{
	cout << "\tStack is: " << endl;
	cout << "\t\t" << (stack.isEmpty() ? "" : "not ") << "empty," << endl;
	cout << "\t\t" << (stack.isFull () ? "" : "not ") << "full." << endl;
}

int maxElements = 30;
int main()
{
	cout << "Creating a new stack with maximum of " << maxElements << " elements." << endl;
	Stack<int> myStack (maxElements);

	cout << "Pushing " << maxElements << " integers onto the stack." << endl;
	for(int i=0; i<maxElements; i++)
		myStack.Push(i*10);

	myStack.print(0, "\t");
	checkEmptyFull(myStack);
	cout << endl;

	cout << "Attempting to push another integer onto the stack." << endl;
	try { 
		myStack.Push(9000);
	} catch (StackError e) { 
		handleException(e);
	}
	
	cout << "Popping: ";
	while(!myStack.isEmpty())
		cout << myStack.Pop() << " ";
	cout << endl;
	checkEmptyFull(myStack);
	myStack.print(0, "\t");
	
	cout << "Trying to pop an int off the empty stack." << endl;
	try {
		myStack.Pop();
	} catch (StackError e) {
		handleException(e);
	}

}

