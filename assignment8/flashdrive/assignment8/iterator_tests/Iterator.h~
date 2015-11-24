//generic iterator class
#ifndef ITERATOR_H
#define ITERATOR_H

template <typename T>
class Iterator
{
	public:
		virtual Iterator<T>& operator--(int);
		virtual Iterator<T>& operator--();
		virtual Iterator<T>& operator++(int);
		virtual Iterator<T>& operator++();
		virtual const T& operator*() const;
		virtual T& operator*();
		virtual bool operator==(const Iterator<T>&) const;
};

#endif
