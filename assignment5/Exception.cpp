/**********************************************************************
 * Author: Aaron Schraner
 * Date created: September 30, 2015
 * Last modified: October 11, 2015 (added comments)
 * Filename: Exception.cpp
 * Purpose: Generic exception class with error message
 *	Constructors:
 *		Exception(): default constructor
 *			sets message to "Undefined exception"
 *
 *		Exception(const char* msg)
 *			sets message to msg
 *
 *		Exception(const Exception& e)
 *			copy constructor
 *			copies message from e to self
 *	Destructor:
 *		~Exception()
 *			deletes message
 *
 *	Operators:
 *		operator<< (ostream& os, const Exception& e)
 *			send the message to the output stream
 *			
 ************************************************************************/
#include "Exception.h"
#include <cstring>
#include <iostream>

using std::ostream;

/*****************************************************************
 * Exception default constructor
 * sets message to "Undefined exception"
 *****************************************************************/
Exception::Exception():
	message(0)
{
	//sets message to "Undefined exception"
	setMessage("Undefined exception");
}

/*****************************************************************
 * Exception constructor given exception message
 * sets exception message to given message
 *****************************************************************/
Exception::Exception(const char* msg):
	message(0)
{
	//set message to msg parameter
	setMessage(msg);
}

/*****************************************************************
 * copy constructor
 * makes this exception the same as the one that gets passed 
 * to this constructor
 *****************************************************************/
Exception::Exception(const Exception& e):
	message(0)
{
	//summon a dwarf 
	setMessage(e.message);
}

/*****************************************************************
 * Exception destructor
 * frees the memory containing the exception message
 *****************************************************************/
Exception::~Exception()
{
	//free the memory containing the exception message
	if(message)
		delete[] message;
}

/*****************************************************************
 * Exception assignment operator
 * make my error message match e's error message
 *****************************************************************/
const Exception& Exception::operator=(const Exception& e)
{
	//set message to e's message
	setMessage(e.message);

	//return a const reference to myself
	return *this;
}

/*****************************************************************
 * Exception::setMessage(const char* msg)
 * de-allocates any existing message and sets it to whatever
 * is passed as msg
 *****************************************************************/
void Exception::setMessage(const char* msg)
{
	//delete any existing message
	if(message)
		delete[] message;
	
	//allocate space for and copy the message
	message = new char [ strlen(msg) + 1];
	strcpy(message, msg);
}

/*****************************************************************
 * operator<<(ostream& os, const Exception &e)
 * stream output operator for Exception class
 * just outputs the error message
 *****************************************************************/
ostream& operator<<(ostream& os, const Exception& e)
{
	os << e.getMessage();
	return os;
}

