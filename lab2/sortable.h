#ifndef SORTABLE_H
#define SORTABLE_H

/********************************************************************************
 * template <typename T>
 * class Sortable
 *	Purpose: 
 *		This class is designed to manipulate C-arrays, vectors, and my array class 
 *		using one consistent interface.
 *
 *		Having this class tremendously reduces the amount of code that needs to be
 *		retyped to implement the same sorting algorithm for multiple containers.
 *
 *		Why the hell did I do this:
 *			At first I wanted to use inheritance, but because I don't own the 
 *			std::vector class, I didn't think it was possible.
 *
 *			Then I wanted to try it with templates, but C-arrays are not templated
 *			classes (as far as I know)
 *
 *			This method can encapsulate the different ways that the size of each
 *			container is determined. (size() for vectors, getLength() for my array,
 *			or a manually specified int for C-arrays) This method also makes it 
 *			easier to support other container types. All that needs to be modified
 *			is the switch statement in operator[] and a constructor added. 
 *
 *	Members:
 *		void* vptr:
 *			A void pointer to hold the address of the vector, Array, or C-array 
 *			being used by this Sortable object.
 *
 *		containerType:
 *			An enum to store the type of container <vptr> is pointing to.
 *		
 *		const int size:
 *			Stores the size of the container's array
 *
 *	Constructors:
 *		Sortable(std::vector<T> &vec):
 *			Makes <vptr> point to <vec> and sets the containerType to _vector.
 *			sets <size> to vec.size()
 *
 *		Sortable(T* carray, int sz):
 *			Makes <vptr> point to <carray> and sets the containerType to _carray.
 *			Sets <size> to <sz>
 *
 *		Sortable(Array<T>& myarray):
 *			Makes <vptr> point to <myarray> and sets the containerType to _myarray.
 *			Sets <size> to myarray.getLength()
 *	
 *	Methods:
 *		T& operator[](int index):
 *			Index operator.
 *			Reads the value of containerType and determines how to first convert
 *			<vptr> into a pointer to the requested container type, then access
 *			the <index>th element in the container. 
 *
 *	Friend functions:
 *		std::ostream& operator<<(ostream& os, Sortable<T>& array):
 *			Stream output operator.
 *			Displays every value in the container, space-separated
 *			(uses operator[] to access values)
 *	
 ********************************************************************************/

#include "Array.h"
#include <vector>

//the worst way to implement polymorphism in C++

template <typename T>
class Sortable
{
	private:
		void* vptr;
		enum ContainerType
		{
			_vector,
			_myarray,
			_carray
		} containerType;

		template <typename U>
		friend std::ostream& operator<<(ostream& os, Sortable<U> array);

	public:
		const int size;

		T& operator[](int index);

		Sortable(std::vector<T> &vec);
		Sortable(T* carray, int sz);
		Sortable(Array<T>& myarray);

};

#include "sortable_impl.h"

#endif
