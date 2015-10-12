//Author: Aaron Schraner
//Date: September 30, 2015
//Purpose: generic exception class containing error message (c-string)
#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <iostream>

using std::ostream;

class Exception
{
	private:
		char* message;
		
	public:
		Exception();
		Exception(const char* msg);
		Exception(const Exception& e);
		~Exception();
		const Exception& operator=(const Exception& e);
		const char* getMessage() const { return message; }
		void setMessage(const char* msg);
		friend ostream& operator<<(ostream& os, const Exception &e);
};

#endif

