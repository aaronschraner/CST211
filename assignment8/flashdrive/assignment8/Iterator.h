//generic iterator class
#ifndef ITERATOR_H
#define ITERATOR_H

template <typename T>
class Iterator
{
	public:
		//TODO: possibly broken
		Iterator(const Iterator<T>& it):iter(it.iter) {}
		Iterator(Iterator<T>* iter):iter(iter) {}
		Iterator():iter(0) {}
		virtual void operator--(int)	{ --(*iter);}
		virtual void operator--()		{ --(*iter);}
		virtual void operator++(int)	{ ++(*iter);}
		virtual void operator++()		{ ++(*iter);}

		//dereference
		virtual const T& operator*() const { return **iter; }
		virtual T& operator*() { return **iter; }

		//comparison
		virtual bool operator==(const Iterator<T>&) const;
		virtual bool isValid() const { return iter && iter->isValid();}
	private:
		Iterator* iter;
};

#endif
