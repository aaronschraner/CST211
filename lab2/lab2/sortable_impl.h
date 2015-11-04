#ifndef SORTABLE_IMPL_H
#define SORTABLE_IMPL_H

#include "Array.h"


/********************************************************************************
 * Sortable::Sortable(std::vector<T> &vec):
 *	Purpose: 
 *		Constructor for Sortable class given a vector
 *		Creates a Sortable object that references <vec> when operator[] is used
 *
 *	Entry: 
 *		vec: the vector that vptr should point at
 *	
 *	Exit: 
 *		sets containerType to _vector, vptr to the address of vec, and size to
 *		vec.size().
 *	
 ********************************************************************************/
template <typename T>
Sortable<T>::Sortable(std::vector<T> &vec):
	containerType(_vector), vptr(&vec), size(vec.size())
{
}

/********************************************************************************
 * Sortable::Sortable(T* carray, int sz):
 *	Purpose: 
 *		Constructor for Sortable class given a C-array
 *		Creates a Sortable object that references <carray> when operator[] is invoked
 *
 *	Entry: 
 *		carray: the C-array that vptr should point at and operator[] should operate on
 *	
 *	Exit: 
 *		sets containerType to _carray, vptr to the address of carray, and size to
 *		sz.
 *	
 ********************************************************************************/
template <typename T>
Sortable<T>::Sortable(T* carray, int sz):
	containerType(_carray), vptr(carray), size(sz)
{
}

/********************************************************************************
 * Sortable::Sortable(Array<T> &myarray):
 *	Purpose: 
 *		Constructor for Sortable class given an instance of my array class from 
 *			assignment 1.
 *
 *		Creates a Sortable object that references <myarray> when operator[] is invoked
 *
 *	Entry: 
 *		myarray: the Array<T> that vptr should point at and operator[] should operate on
 *	
 *	Exit: 
 *		sets containerType to _myarray, vptr to the address of myrray, and size to
 *		myarray.getLength().
 *	
 ********************************************************************************/
template <typename T>
Sortable<T>::Sortable(Array<T> &myarray):
	containerType(_myarray), vptr(&myarray), size(myarray.getLength())
{
}

/********************************************************************************
 * T& Sortable::operator[](int index)
 *	Purpose: 
 *		Index operator for Sortable class
 *		Converts <vptr> to the type of array specified by containerType and returns
 *		a reference to the <index>th element in that container
 *
 *	Entry: 
 *		index: the index of the element that the user wants to access
 *
 *	Exit: 
 *		Returns a reference to the element in the container at the index.
 *	
 ********************************************************************************/
template <typename T>
T& Sortable<T>::operator[](int index)
{
	switch(containerType)
	{
		//if this Sortable object points to a vector, treat vptr like 
		//a pointer to a vector<T> and return the element at the index.
		case Sortable::_vector:
			return (*((std::vector<T>*)vptr))[index];

		//if this Sortable object points to an instance of my array class, treat
		//vptr like an Array<T>* and return the element at the index.
		case Sortable::_myarray:
			return (*((Array<T>*)vptr))[index];

		//if this Sortable object points to a C-array, treat vptr like a T* and
		//return the element at the index.
		case Sortable::_carray:
			return ((T*)vptr)[index];
	}
}


/********************************************************************************
 * ostream& operator<<(ostream& os, Sortable<T>& array)
 *	Purpose: 
 *		generic stream output operator for Sortable class
 *		prints every element in the container space-separated.
 *
 *	Entry: 
 *		os: the ostream to output to
 *		array: the Sortable object whose contents should be printed
 *
 *	Exit: 
 *		prints everything in the Sortable and returns a reference to the stream
 *		that was passed in.
 *	
 ********************************************************************************/
template <typename T>
std::ostream& operator<<(std::ostream& os, Sortable<T> array)
{
	for(int i=0; i<array.size; i++)
		os << array[i] << " ";
	return os;
}

#endif
