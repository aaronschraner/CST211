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

/********************************************************************************
 * Exception();
 * 	Purpose: 
 * 		default constructor for Exception class
 * 		sets message to "Undefined exception"
 * 	
 * 	Entry: 
 * 		nothing
 * 	
 * 	Exit: 
 * 		Constructs exception with a copy of the message "Undefined Exception"
 * 	
 ********************************************************************************/
Exception::Exception():
	message(0)
{
	setMessage("Undefined exception");
}

/********************************************************************************
 * Exception(const char* msg);
 * 	Purpose: 
 * 		Constructor given a c-string error message
 * 		simplifies syntax for throwing exceptions
 * 	
 * 	Entry: 
 * 		const char* msg: the message to copy into the Exception
 * 	
 * 	Exit: 
 * 		constructed exception with message matching <msg>
 * 	
 ********************************************************************************/
Exception::Exception(const char* msg):
	message(0)
{
	setMessage(msg);
}

/********************************************************************************
 * Exception(const Exception& e);
 * 	Purpose: 
 * 		Copy constructor for exception class
 * 		just copies the message from e into the new exception
 * 	
 * 	Entry: 
 * 		const Exception& e: the exception to be copied
 * 	
 * 	Exit: 
 * 		constructed exception with message matching e's message
 * 	
 ********************************************************************************/
Exception::Exception(const Exception& e):
	message(0)
{
	setMessage(e.message);
}

/********************************************************************************
 * ~Exception();
 * 	Purpose: 
 * 		Destructor for Exception class
 * 		(just de-allocates the memory for the error message)
 * 	
 * 	Entry: 
 * 		A still allocated exception (this)
 * 	
 * 	Exit: 
 * 		A not allocated exception (that)
 * 	
 ********************************************************************************/
Exception::~Exception()
{
	//de-allocate the message
	if(message)
		delete[] message;
}

/********************************************************************************
 * const Exception& operator=(const Exception& e);
 * 	Purpose: 
 * 		Assignment operator for exception class
 * 		Deletes any existing message contained in this exception and
 * 		replaces it with the message in <e>
 * 	
 * 	Entry: 
 * 		const Exception& e: the exception to be copied into this one
 * 	
 * 	Exit: 
 * 		A const reference to the newly assigned exception
 * 	
 ********************************************************************************/
const Exception& Exception::operator=(const Exception& e)
{
	setMessage(e.message);
	return *this;
}

/********************************************************************************
 * void setMessage(const char* msg);
 * 	Purpose: 
 * 		Set the message contained in this exception
 * 		(also deletes any existing message)
 * 	
 * 	Entry: 
 * 		const char* msg (the message to be assigned)
 * 	
 * 	Exit: 
 * 		Exception now contains the same message as <msg>
 * 	
 ********************************************************************************/
void Exception::setMessage(const char* msg)
{
	//de-allocate the old message
	if(message)
		delete[] message;
	
	//allocate space for and copy the provided message
	message = new char [ strlen(msg) + 1 ];
	strcpy(message, msg);
}

/********************************************************************************
 * ostream& operator<<(ostream& os, const Exception &e);
 * 	Purpose: 
 * 		Overloaded stream output operator
 * 		allows Exception to be passed to streams like cout
 * 		only prints exception message with no special formatting
 * 	
 * 	Entry: 
 * 		ostream& os (the output stream to send message to)
 * 		const Exception &e: the exception to output
 * 	
 * 	Exit: 
 * 		Returns a reference to the output stream
 * 		and uses it to output the error message
 * 	
 ********************************************************************************/
ostream& operator<<(ostream& os, const Exception& e)
{
	os << e.getMessage();
	return os;
}

