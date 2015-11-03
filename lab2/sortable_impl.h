#ifndef SORTABLE_IMPL_H
#define SORTABLE_IMPL_H

#include "Array.h"

using std::vector;

template <typename T>
Sortable<T>::Sortable(std::vector<T> &vec):
	containerType(_vector), vptr(&vec), size(vec.size())
{
}

template <typename T>
Sortable<T>::Sortable(T* carray, int sz):
	containerType(_carray), vptr(carray), size(sz)
{
}

template <typename T>
Sortable<T>::Sortable(Array<T> &myarray):
	containerType(_myarray), vptr(&myarray), size(myarray.getLength())
{
}

template <typename T>
T& Sortable<T>::operator[](int index)
{
	switch(containerType)
	{
		case Sortable::_vector:
			return (*((vector<T>*)vptr))[index];
		case Sortable::_myarray:
			return (*((Array<T>*)vptr))[index];
		case Sortable::_carray:
			return ((T*)vptr)[index];
	}
}

template <typename T>
std::ostream& operator<<(std::ostream& os, Sortable<T>& array)
{
	for(int i=0; i<array.size; i++)
		os << array[i] << " ";
	return os;
}

#endif
