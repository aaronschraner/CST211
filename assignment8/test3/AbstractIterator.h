#ifndef ABSTRACTITERATOR_H
#define ABSTRACTITERATOR_H

template <typename T>
class AbstractIterator
{
	public:
		virtual AbstractIterator<T>& operator++(int) = 0;
		virtual AbstractIterator<T>& operator++() = 0 ;
		virtual AbstractIterator<T>& operator--(int) = 0;
		virtual AbstractIterator<T>& operator--() = 0;
		virtual T& operator*() = 0;
		virtual const T& operator*() const = 0;


};

#endif
