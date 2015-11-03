/**********************************************************************
 * Author: Aaron Schraner
 * Date created: September 30, 2015
 * Last modified: October 11, 2015 (added comments)
 * Filename: Array.h
 * Purpose: Generic array class with range checking and adjustable 
 * 			starting index.
 *	Constructors:
 *		Array() : default constructor
 *			sets size to 10 and starting index to 0
 *
 *		Array(int length, int start_index)
 *			creates array of length length with starting index start_index
 *
 *		Array(const Array& ar)
 *			copy constructor
 *	Destructor:
 *		~Array()
 *			deletes contents of array
 *
 *	Operators:
 *		const Array& operator=( const Array& ar)
 *			assignment operator
 *			de-allocates array and creates a new one with size and contents matching ar
 *		T& operator[] (int index) 
 *			index operator
 *			access the <index>th element of the array
 *		const T& operator[] (int index) const
 *			const version of index operator
 *			does the same thing but const
 *
 *	Accessors:
 *		getStartIndex()
 *			returns starting index of the array
 *		getLength()
 *			returns the length of the array
 *
 *	Mutators:
 *		setStartIndex(int start_index)
 *			sets the starting index to start_index
 *			(preserves array)
 *		setLength(int length)
 *			change the length of the array to <length>
 *			(preserves as much data as possible)
 *			
 *			
 ************************************************************************/

/***********************************************************************
 * Default constructor
 * sets size to 10 and start index to 0
 ***********************************************************************/
template <typename T>
Array<T>::Array():
	m_length(10),
	m_start_index(0)
{
	//allocate space for the array
	m_array = new T[m_length];
}


/*****************************************************************
 * constructor given length and start index
 * sets the start index to whatever you want and allocates an array
 * checks to make sure array is valid length
 *
 * my asterisk key hates me right now
 *****************************************************************/
template <typename T>
Array<T>::Array(int length, int start_index):
	m_length(length),
	m_start_index(start_index)
{
	//validate the length
	if(length<=0)
		throw Exception("Tried to create row with invalid length!");

	//allocate the new array
	m_array = new T[length];

}


/*****************************************************************
 * copy constructor
 * takes an array and constructs itself as a copy of ar
 *****************************************************************/
template <typename T>
Array<T>::Array(const Array<T>& ar):
	m_length(ar.m_length),
	m_start_index(ar.m_start_index)
{
	//allocate space for the new array
	m_array = new T [ ar.m_length ];

	//copy the elements from ar into the new array
	for(int i=0; i<m_length; i++)
		m_array[i] = ar.m_array[i];
	
}


/*****************************************************************
 * destructor
 * de-allocate the memory for the array
 *****************************************************************/
template <typename T>
Array<T>::~Array()
{
	//free the array's memory
	if ( m_array )
		delete[] m_array;


}

/*****************************************************************
 * assignment operator
 * takes all the values from ar and puts them in the array
 *****************************************************************/
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

}

/*****************************************************************
 * index operator (operator[])
 * returns a mutable reference to an element in the array
 * takes:
 *	int index - the index of the element to be accessed
 * 
 * also performs range checking
 *****************************************************************/
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


}

/*****************************************************************
 * const index operator (const T& operator[] (int index) const)
 * returns a const reference to an element in the array
 * takes:
 *	int index - the index of the element to be accessed
 * 
 * also performs range checking
 *****************************************************************/
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

/*****************************************************************
 * void Array<T>::setLength(int length)
 * Purpose:	
 *		resize an array to the given length
 *		(preserves as many elements as possible)
 *****************************************************************/
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




