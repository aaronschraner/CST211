/*
 * Author: Aaron Schraner
 * Date created: September 30, 2015
 * Last modified: October 10, 2015
 * Filename: Exception.cpp
 *
 * Purpose: generic exception class containing error message (c-string)
*/
#include "Exception.h"
#include <cstring>
#include <iostream>

using std::ostream;

/*
 * Default constructor
 * sets message to "Undefined exception"
 */
Exception::Exception():
	message(0)
{
	setMessage("Undefined exception");
}

/*
 * constructor given exception message
 * sets message to first argument
 */
Exception::Exception(const char* msg):
	message(0)
{
	setMessage(msg);
}

/*
 * copy constructor
 * copies the message into the new exception
 */
Exception::Exception(const Exception& e):
	message(0)
{
	setMessage(e.message);
}

/*
 * destructor
 * de-allocates message
 */
Exception::~Exception()
{
	//de-allocate the message
	if(message)
		delete[] message;
}

/*
 * assignment operator
 * copies message from right side into left side
 *
 */
const Exception& Exception::operator=(const Exception& e)
{
	setMessage(e.message);
	return *this;
}

/*
 * set exception message
 * de-allocate any message that already exists,
 * allocate memory to store the new message, 
 * copy the message passed into the new message memory
 */
void Exception::setMessage(const char* msg)
{
	//de-allocate the old message
	if(message)
		delete[] message;
	
	//allocate space for and copy the provided message
	message = new char [ strlen(msg) ];
	strcpy(message, msg);
}

/*
 * stream output operator
 * print the contained message when sent
 * to an ostream with <<
 */
ostream& operator<<(ostream& os, const Exception& e)
{
	os << e.getMessage();
	return os;
}

