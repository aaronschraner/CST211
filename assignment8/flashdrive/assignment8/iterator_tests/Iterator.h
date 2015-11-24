//generic iterator class
#ifndef ITERATOR_H
#define ITERATOR_H

template <typename T>
class Iterator
{
	public:
		//TODO: possibly broken
		virtual Iterator<T>& operator--(int);
		virtual Iterator<T>& operator--();
		virtual Iterator<T>& operator++(int);
		virtual Iterator<T>& operator++();

		//dereference
		virtual const T& operator*() const;
		virtual T& operator*();

		//comparison
		virtual bool operator==(const Iterator<T>&) const;
};

#endif
