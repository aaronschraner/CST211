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
#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <iostream>

using std::ostream;

class Exception
{
	private:
		//the error message
		char* message;
		
	public:
		//constructors
		Exception();
		Exception(const char* msg);
		Exception(const Exception& e);

		//destructor
		~Exception();

		//operators and methods
		const Exception& operator=(const Exception& e);
		const char* getMessage() const { return message; }
		void setMessage(const char* msg);
		friend ostream& operator<<(ostream& os, const Exception &e);
};

#endif

