
//default constructor
//use default length of 10 and starting index of 0
template <typename T>
Array<T>::Array():
	m_length(10),
	m_start_index(0)
{
	m_array = new T[m_length];
}

//constructor given length and start index
template <typename T>
Array<T>::Array(int length, int start_index):
	m_length(length),
	m_start_index(start_index)
{
	if(length<0)
		throw Exception("Tried to create row with negative length!");

	m_array = new T[length];

}

//copy constructor
template <typename T>
Array<T>::Array(const Array<T>& ar):
	m_length(ar.m_length),
	m_start_index(ar.m_start_index)
{
	m_array = new T [ ar.m_length ];
	for(int i=0; i<m_length; i++)
		m_array[i] = ar.m_array[i];

	/*
	 * Writeup question:
	 *		"What is the similarity and difference between copy constructor and operator= function?"
	 *	Both functions require new memory to be allocated for a copy of the source data.
	 *	However, only the operator= function requires that you free any existing array data. 
	 *	There cannot be an existing array for the copy constructor because the object has just been 
	 *	created and has no meaningful existing member data yet. 
	 *
	 */
}


//destructor
template <typename T>
Array<T>::~Array()
{
	//free the array's memory
	if ( m_array )
		delete[] m_array;

	/*
	 * Writeup question:
	 *		"What steps did you take to ensure no memory leaks?"
	 *	I was careful to free the array in the destructor. I also chose to free and re-allocate the array 
	 *	if setLength() is used to expand the array beyond its current length. 
	 *	The Exception class also frees the memory containing its error message in the destructor. 
	 *
	 */

}

//assignment operator
template <typename T>
const Array<T>& Array<T>::operator=(const Array<T>& ar)
{
	//free the current array's memory
	if(m_array)
		delete[] m_array;
	//allocate a new array the same size as ar's
	m_array = new T [ ar.m_length ];
	m_length = ar.m_length;
	m_start_index = ar.m_start_index;

	//copy all the elements of the array form ar to this array
	for(int i=0; i < ar.m_length; i++)
		m_array[i] = ar.m_array[i];


	return *this;

	/*
	 * Writeup question:
	 *		"What are the considerations you had to include in your operator= function?"
	 *	I had to ensure that the data was deep copied and not shallow copied, meaning I had to 
	 *	manually allocate memory for and copy each element in the array. If I had just copied the pointer,
	 *	modifying any one of the copies would affect the array data for all of them, and more than one 
	 *	destruction would result in a double-free. 
	 *	I also had to be sure to free any previously stored data in the array
	 *
	 */
}


//index operator ([])
template <typename T>
T& Array<T>::operator[](int index)
{
	//check index range
	if(index < m_start_index) 
		throw Exception("Index below range!");

	else if( index >= m_start_index + m_length)
		throw Exception("Index above range!");

	//if range is ok, return the desired element
	return m_array[index-m_start_index];


	/*
	 * Writeup question:
	 *		"In terms of big O how long would it take to find an element of this array? How could this be improved? What would the expression become?"
	 *	The algorithm to find an element in this array currently requires O(n) time. (where n is the number of elements in the array)
	 *	If the array were sorted, that could be reduced to O(log n). 
	 *
	 */
}

//index operator (const version)
template <typename T>
const T& Array<T>::operator[] (int index) const
{
	//check index range
	if(index < m_start_index) 
		throw Exception("Index below range!");

	else if( index >= m_start_index + m_length)
		throw Exception("Index above range!");

	//if range is ok, return the desired element
	return m_array[index-m_start_index];
}


//change length of the array
template <typename T>
void Array<T>::setLength(int length)
{
	//do not allow negative lengths
	if ( length < 0 )
		throw Exception("Tried to create array with negative length");

	//if the new array is bigger than the old one
	if(length > m_length )
	{
		//create a new bigger array and copy the existing elements into it
		T* newArray = new T [length];
		for(int i=0; i<m_length; i++)
			newArray[i] = m_array[i];

		//free the old array's memory
		delete[] m_array;

		m_array = newArray;
	}

	//set the length to its new value
	m_length = length;
}




