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
#include <climits>

using namespace std;

// typedef for the exceptions thrown by a Stack of ints
typedef typename Stack<int>::Error StackError;

// Take a Stack<int> Error and explain what it means
void handleException(StackError e);

// Say if the stack is empty and if it is full
template <typename T>
void checkEmptyFull(const Stack<T>& stack);

// Test overflow and underflow condition handling
void testOverUnderflow(int maxElements);

// Test the stack constructors
void testStackCtors();


int main()
{
	cout << " --- Testing over/underflow cases. --- " << endl;
	testOverUnderflow(10);

	cout << endl << endl << " --- Testing constructors --- " << endl;
	testStackCtors();
}

/********************************************************************************
 * void testOverUnderflow(int maxElements)
 *	Purpose:
 *		Test overflow and underflow conditions for the Stack class by:
 *		 - Creating a new stack with maximum capacity of <maxElements>
 *		 - Pushing <maxElements> integers onto it
 *		 - Showing the user the contents and statistics on the Stack
 *		 - Trying to push another integer onto the now-full Stack
 *		 - Popping each element off the stack
 *		 - Trying to pop an element off the now-empty Stack
 *
 *	Entry:
 *		int maxElements:
 *			The number of elements to test the stack with.
 *			Smaller values are generally easier to read but large (>20) values 
 *			are still cleanly formatted
 *
 *	Exit:
 *		Program output should make logical sense with the description in the
 *			Purpose section. 
 *			(this function prints the stack elements as it pops them off.)
 *			(compile with VERBOSE defined to show destructor calls)
 *
 ********************************************************************************/
void testOverUnderflow(int maxElements)
{
	//create a new Stack of ints with <maxElements> maximum elements
	cout << "Creating a new stack with maximum of " << maxElements << " elements." << endl;
	Stack<int> myStack (maxElements);

	// Push <maxElements> integers (from 0 to 10*maxElements in intervals of 10) onto the stack
	cout << "Pushing " << maxElements << " integers onto the stack." << endl;
	for(int i=0; i<maxElements; i++)
		myStack.Push(i*10);

	// print information about the stack
	myStack.print(0, "\t");
	checkEmptyFull(myStack);
	cout << endl;

	// Try to push an integer onto the now-full stack
	cout << "Attempting to push another integer onto the stack." << endl;
	try { 
		myStack.Push(9000);
	} catch (StackError e) { 
		handleException(e);
	}
	
	// Pop every element off the stack (and print it)
	cout << "Popping: ";
	while(!myStack.isEmpty())
		cout << myStack.Pop() << " ";
	cout << endl;

	// Print statistics about the stack (should be empty)
	checkEmptyFull(myStack);
	myStack.print(0, "\t");
	
	// Try to pop an int off the now-empty stack
	cout << "Trying to pop an int off the empty stack." << endl;
	try {
		myStack.Pop();
	} catch (StackError e) {
		handleException(e);
	}

}





/********************************************************************************
 * void handleException(StackError e)
 *	Purpose:
 *		Take a Stack<int> Error and explain what it means to the user
 *
 *	Entry:
 *		StackError (Stack<int>::Error) e: the exception to be explained
 *
 *	Exit:
 *		outputs what the exception means to stdout
 *
 ********************************************************************************/
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

/********************************************************************************
 * void checkEmptyFull(const Stack<T>& stack)
 *	Purpose:
 *		Take a stack and find out if it is...
 *		 - empty
 *		 - full
 *		Keeping in mind that a stack with a maxSize of 0 is both empty and full
 *
 *	Entry:
 *		const Stack<T>& stack: the stack to check the (empti|full)ness of.
 *
 *	Exit:
 *		Tells the user (via stdout) if the stack is empty/full
 *		Note: output is indented with tabs
 *
 ********************************************************************************/
template <typename T>
void checkEmptyFull(const Stack<T>& stack)
{
	cout << "\tStack is: " << endl;
	cout << "\t\t" << (stack.isEmpty() ? "" : "not ") << "empty," << endl;
	cout << "\t\t" << (stack.isFull () ? "" : "not ") << "full." << endl;
}

void testStackCtors()
{
	cout << " Creating stack with default constructor:\n";
	Stack<int> defaultStack;
	defaultStack.print(0, "\t");
	cout << endl;

	cout << "Creating stack with maximum of 20 elements:\n";
	Stack<int> sizeStack(20);
	sizeStack.print(0, "\t");
	cout << endl;

	cout << "Adding 10 elements to previous stack\n";
	for(int i=0; i<10; i++)
		sizeStack.Push(i+1);

	cout << "Stack with elements added:\n";
	sizeStack.print(0, "\t");
	cout << endl;

	cout << "Creating stack using copy constructor from previous stack:\n";
	Stack <int> copyStack (sizeStack);
	copyStack.print(0, "\t");
	cout << endl;

	cout << "Creating a default stack and assigning it to the previous stack\n";
	Stack <int> equalsStack;
	equalsStack = sizeStack;
	equalsStack.print(0, "\t");
	cout << endl;

	cout << "Destroying stacks." << endl;
#ifndef VERBOSE
	cout << "Compile with VERBOSE defined to show destructor calls (run \"make debug\" if using make)" << endl;
#endif
}

