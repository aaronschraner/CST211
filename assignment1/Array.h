/**********************************************************************
 * Author: Aaron Schraner
 * Date created: September 30, 2015
 * Last modified: October 11, 2015 (added comments)
 * Filename: Array.h
 * Purpose: Generic array class with range checking and adjustable 
 * 			starting index.
 *	Constructors:
 *		Array() : default constructor
 *			sets size and starting index to 0
 *
 *		Array(int length, int start_index)
 *			creates array of length length with starting index start_index
 *
 *		Array(const Array& ar)
 *			copy constructor
 *	Destructor:
 *		~Array()
 *			deletes contents of array
 *
 *	Operators:
 *		const Array& operator=( const Array& ar)
 *			assignment operator
 *			de-allocates array and creates a new one with size and contents matching ar
 *		T& operator[] (int index) 
 *			index operator
 *			access the <index>th element of the array
 *		const T& operator[] (int index) const
 *			const version of index operator
 *			does the same thing but const
 *
 *	Accessors:
 *		getStartIndex()
 *			returns starting index of the array
 *		getLength()
 *			returns the length of the array
 *
 *	Mutators:
 *		setStartIndex(int start_index)
 *			sets the starting index to start_index
 *			(preserves array)
 *		setLength(int length)
 *			change the length of the array to <length>
 *			(preserves as much data as possible)
 *			
 *			
 ************************************************************************/

#ifndef ARRAY_H
#define ARRAY_H
#include "Exception.h"

template <typename T>
class Array
{
	private:
		//array to store the data
		T* m_array;

		//length and start index of the array
		int m_length, m_start_index;

	public:
		//constructors
		Array();
		Array(int length, int start_index);
		Array(const Array& ar);
		
		//destructor
		~Array();

		//operators
		const Array& operator=(const Array& ar);
		T& operator[](int index);
		const T& operator[] (int index) const;

		//getters
		int getStartIndex() const { return m_start_index; }
		int getLength() const { return m_length; }

		//setters
		void setStartIndex(int start_index) { m_start_index = start_index; }
		void setLength(int length);
};

#include "Array_impl.h"

#endif
