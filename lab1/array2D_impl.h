/*******************************************************
 * Author: Aaron Schraner
 * Date created: 10/06/15
 * Last modification date: 10/10/15
 * Assignment: 2D array class
 * Filename: array2D_impl.h
 *
 * see array2D.h for class description
 * this file contains the implementations for all member functions in the Array2D class
 *
 *
 *     _                         ____  ____  
 *    / \   _ __ _ __ __ _ _   _|___ \|  _ \
 *   / _ \ | '__| '__/ _` | | | | __) | | | |
 *  / ___ \| |  | | | (_| | |_| |/ __/| |_| |
 * /_/   \_\_|  |_|  \__,_|\__, |_____|____/ 
 *                         |___/              (implementation)
 *
 *******************************************************/

#ifndef ARRAY2D_IMPL_H
#define ARRAY2D_IMPL_H

#define MIN(x,y) ( (x < y) ? (x) : (y) )

#include "Exception.h"

/*********************************************************
 * Default constructor for Array2D class
 * sets rows, cols, and m_array to 0.
 */
template <typename T>
Array2D<T>::Array2D():
	Array2D(0,0)
{

}
/*********************************************************
 * Array2D (int rows, int cols)
 * Purpose: constructor for Array2D class given number of 
 * rows and columns in the array
 *
 *********************************************************/
template <typename T>
Array2D<T>::Array2D(int rows, int cols):
	rows(rows),
	cols(cols)
{
	if ( rows < 0 || cols < 0 )
		throw Exception ("tried to create zero or negative size array");

	//allocate memory for the new array
	//(set pointer to null if zero-length array is requested)
	m_array = rows * cols ? new T* [rows] : 0;

	//allocate each row (only if number of array elements is nonzero)
	if(rows*cols)
		for(int i=0; i < rows; i++)
			m_array [i] = new T[cols];
}

/**********************************************
 * Array2D (const Array2D& ar)
 * Purpose: copy constructor for Array2D class
 * (uses previous constructor for allocation)
 *********************************************/
template <typename T>
Array2D<T>::Array2D(const Array2D<T> &ar):

	//allocate using Array2D(rows, cols) constructor
	Array2D(ar.rows, ar.cols)
{
	//copy each item from the old array to the new one
	for(int row = 0; row < rows; row++)
		for(int col = 0; col < cols; col++)
			m_array[row][col] = ar.m_array[row][col];
}

/***********************************************************
 * Row<T> Array2D::operator[](int index)
 * Purpose: non-const index operator for 2D array class
 * Takes: int index (the number of row you want to access)
 * Returns: a Row object with desired row
 ***********************************************************/
template <typename T>
Row<T> Array2D<T>::operator[](int index)
{
	//perform range checking
	checkRange(index);

	//return the requested row
	return Row<T>(*this, index);
}

/***********************************************************
 * const Row<T> Array2D::operator[](int index) const
 * Purpose: const/read-only index operator for 2D array class
 * Takes: int index (the number of row you want to access)
 * Returns: a const Row object with desired row
 ***********************************************************/
template <typename T>
const Row<T> Array2D<T>::operator[] (int index) const
{
	//range checking
	checkRange(index);

	//return the requested row
	const Row<T> r (*this, index);
	return r;
}


/***********************************************************
 * Array2D destructor
 * De-allocates m_array as long as it is not null
 ***********************************************************/
template <typename T>
Array2D<T>::~Array2D()
{
	if(m_array)
	{
		//delete the rows
		for(int i=0; i<rows; i++)
			delete[] m_array[i];

		//delete the array of pointers to the rows
		delete[] m_array;
	}
}

/*
 * Array2D<T>& Array2D<T>::operator=(const Array2D<T> &ar)
 * Purpose: assignment operator for Array2D class
 * deletes any existing array contents, resizes array, and
 * copies all elements from ar to m_array
 */
template <typename T>
Array2D<T>& Array2D<T>::operator= (const Array2D<T> &ar)
{
	//change the array size to that of ar
	setSize(ar.rows, ar.cols);

	//copy ar's contents into this array
	for(int r = 0; r < rows; r++)
		for(int c = 0; c < cols; c++)
			m_array[r][c] = ar.m_array[r][c];

	return *this;
}

/*
 * Array2D::setRows(int rows)
 * Purpose: change the number of rows in the array (without losing data in the array)
 */
template <typename T>
void Array2D<T>::setRows(int rows)
{
	// this magic works because the rows parameter is the 
	// first argument and not the rows member variable
	setSize(rows, cols);
}

/*
 * Array2D::setColumns(int cols)
 * Purpose: change the number of rows in the array (without losing data in the array)
 */
template <typename T>
void Array2D<T>::setColumns(int cols)
{
	// for magic explanation see setRows()
	setSize(rows, cols);
}

/*
 * Array2D::setSize(int nrows, int ncols)
 * Purpose: change the size of the array while preserving as much data as possible
 */
template <typename T>
void Array2D<T>::setSize(int nrows, int ncols)
{
	//make sure size is valid
	if ( nrows <= 0 || ncols <= 0 )
		throw Exception("Tried to create zero or negative size array");

	//allocate a new array of the requested size
	T** newArray = new T* [nrows];
	for(int i = 0; i < nrows; i++)
		newArray[i] = new T [ncols];

	//copy as many elements as possible into the new array
	for(int row = 0; row < MIN(rows, nrows); row++)
		for(int col = 0; col < MIN(cols, ncols); col++)
			newArray[row][col] = m_array[row][col];

	//de-allocate the old array
	for(int i = 0; i < rows; i++)
		delete[] m_array[i];
	if(m_array)
		delete[] m_array;
	
	//make m_array point to the new array and update member variables
	m_array	= newArray;
	rows	= nrows;
	cols	= ncols;
}

/*
 * Array2D<T>::checkRange (int row, int col) const
 * Checks if both row and col are within range of array
 * and throws exception if they are not
 */
template <typename T>
void Array2D<T>::checkRange(int row, int col) const
{
	if ( row >= rows || row < 0
			|| col >= cols || col < 0)
		throw Exception("Tried to access array outside of range");
}

/*
 * T& Array2D<T>::select(int row, int col)
 * Returns a mutable reference to an element inside the array 
 * throws exception if row or col is out of array range
 * at (row, col)
 */
template <typename T>
T& Array2D<T>::select(int row, int col)
{
	checkRange(row, col);
	return m_array[row][col];
}

/*
 * const T& Array2D<T>::select(int row, int col) const
 * Returns a const reference to an element inside the array 
 * throws exception if row or col is out of array range
 * at (row, col)
 */
template <typename T>
const T& Array2D<T>::select(int row, int col) const
{
	checkRange(row, col);
	return m_array[row][col];
}
#endif
