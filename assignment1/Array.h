//Author: Aaron Schraner
//Date: September 30, 2015
//Purpose: Generic array class with range checking and adjustable 
//			starting index.

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
