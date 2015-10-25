/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      September 30, 2015
 * Last Modified:     October 18, 2015
 * Assignment number: 3
 * Filename:          Exception.h
 * 
 * Purpose: generic exception class containing error message (c-string)
 *
 * Class: Exception
 * 
 * Methods: 
 *      Exception ():
 *         default constructor
 * 
 *      Exception ( const char* msg):
 *         constructor given error message
 * 
 *      Exception ( const Exception& e):
 *         copy constructor
 * 
 *      ~Exception ():
 *         destructor
 * 
 *     const Exception& operator= (const Exception& e):
 *         assignment operator (sets this exception to <e>'s message)
 * 
 *     getMessage() const char* const:
 *         Returns the error message in this exception
 * 
 *      void setMessage (const char* msg):
 *         set the error message of this exception to <msg>
 * 
 *      ostream& operator<< (ostream& os, const Exception& e):
 *         stream output operator for Exception (just outputs message without formatting)
 * 
 * 
 ********************************************************************************/

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

