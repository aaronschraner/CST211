//Author: Aaron Schraner
//Date: September 30, 2015
//Purpose: generic exception class containing error message (c-string)
#include "Exception.h"
#include <cstring>
#include <iostream>

using std::ostream;

//default constructor
Exception::Exception():
	message(0)
{
	setMessage("Undefined exception");
}

//constructor given exception message
Exception::Exception(const char* msg):
	message(0)
{
	setMessage(msg);
}

//copy constructor
Exception::Exception(const Exception& e):
	message(0)
{
	setMessage(e.message);
}

//destructor
Exception::~Exception()
{
	if(message)
		delete[] message;
}

//assignment operator
const Exception& Exception::operator=(const Exception& e)
{
	setMessage(e.message);
	return *this;
}

//set exception message
void Exception::setMessage(const char* msg)
{
	if(message)
		delete[] message;
	
	//allocate space for and copy the message
	message = new char [ strlen(msg) ];
	strcpy(message, msg);
}

//stream output operator
ostream& operator<<(ostream& os, const Exception& e)
{
	os << e.getMessage();
	return os;
}

