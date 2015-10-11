/*******************************************************
 * Author: Aaron Schraner
 * Date created: 10/06/15
 * Last modification date: 10/10/15
 * Assignment: 2D array class
 * Filename: row_impl.h
 *
 * purpose: row class for Array2D to provide array[x][y] functionality
 * does not store any user data, just contains pointer to an Array2D and
 * accesses that data.
 * (method implementations)
 *
 *******************************************************/

#ifndef ROW_IMPL_H
#define ROW_IMPL_H

//include exception class for out-of-bounds errors
#include "Exception.h"

/*****************************************************************
 * Row(Array2D<T>& ar, int row)
 * Constructor given mutable array reference
 * sets m_array2D to point at ar
 *****************************************************************/
template <typename T>
Row<T>::Row(Array2D<T>& ar, int row):
	m_array2D(&ar),
	row(row)
{
}

/*****************************************************************
 * Row(const Array2D& ar, const int row)
 * Constructor given const array reference
 * does the same thing as the other constructor
 *****************************************************************/
template <typename T>
Row<T>::Row(const Array2D<T>& ar, const int row):
	m_array2D(&ar),
	row(row)
{
}

/*****************************************************************
 * T& Row<T>::operator[] (int index)
 * returns a mutable reference to the desired Array2D element
 *****************************************************************/
template <typename T>
T& Row<T>::operator[](int index)
{
	//I know it's awful but it's the only way I could think of that would compile
	return (const_cast <Array2D<T>*> (m_array2D) )->select(row, index);
}

/*****************************************************************
 * const T& Row<T>::operator[] (int index) const
 * returns a const reference to the desired Array2D element
 *****************************************************************/
template <typename T>
const T& Row<T>::operator[](int index) const
{
	return m_array2D->select(row, index);
}

#endif
