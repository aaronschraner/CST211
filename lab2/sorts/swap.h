#ifndef SWAP_H
#define SWAP_H

#ifndef MIN
#define MIN(x,y) ( (x) < (y) ? (x) : (y) )
#endif

template <typename T>
void swap(T& val1, T& val2)
{
	T temp = val1;
	val1 = val2;
	val2 = temp;
}

#endif
