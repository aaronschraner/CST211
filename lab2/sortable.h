#ifndef SORTABLE_H
#define SORTABLE_H

#include "Array.h"
#include <vector>
//the worst way to implement polymorphism
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
		friend std::ostream& operator<<(ostream& os, Sortable<U>& array);
	public:
		T& operator[](int index);
		const int size;
		Sortable(std::vector<T> &vec);
		Sortable(T* carray, int sz);
		Sortable(Array<T>& myarray);

};

#include "sortable_impl.h"

#endif
