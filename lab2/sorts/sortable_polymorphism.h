#ifndef SORTABLE_POLYMORPHISM_H
#define SORTABLE_POLYMORPHISM_H
#include "../Array.h"
#include "../sortable.h"
#include <vector>

//macro to allow sorting algorithms to implicitly cast vectors, c-arrays, and Arrays to Sortables for sorting
//when they are passed as arguments
//invoke with POLYMORPHISM(algorithmName);
#define POLYMORPHISM(x) \
	template <typename T> void x(std::vector<T> &array) { x(Sortable<T>(array)); } \
	template <typename T> void x(Array<T>       &array) { x(Sortable<T>(array)); } \
	template <typename T> void x(T* array, int size   ) { x(Sortable<T>(array,size)); }

#endif
