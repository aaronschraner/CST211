/*
 * Author: Aaron Schraner
 * Date created: September 30, 2015
 * Last modified: October 10, 2015
 * Filename: Exception.h
 *
 * Purpose: generic exception class containing error message (c-string)
*/

#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <iostream>

using std::ostream;

class Exception
{
	private:
		char* message;
		
	public:
		//constructors and destructor
		Exception();
		Exception(const char* msg);
		Exception(const Exception& e);
		~Exception();

		//operators, getters, and setters
		const Exception& operator=(const Exception& e);
		const char* getMessage() const { return message; }
		void setMessage(const char* msg);
		friend ostream& operator<<(ostream& os, const Exception &e);
};

#endif

