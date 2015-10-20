/*******************************************************
 * Author: Aaron Schraner
 * Date created: 10/06/15
 * Last modification date: 10/10/15
 * Assignment: 2D array class
 * Filename: row.h
 *
 * purpose: row class for Array2D to provide array[x][y] functionality
 * does not store any user data, just contains pointer to an Array2D and
 * accesses that data.
 *
 *******************************************************/

#ifndef ROW_H
#define ROW_H

//prototype for Array2D
template <typename T>
class Array2D;

/************************************************************
 * Class: Row <T>
 * Constructors:
 *		Row (Array2D <T> &array, int row)
 *			initializes m_array2D and row with given arguments
 *			used for mutable access
 *		Row ( const Array2D <T> &array, const int row)
 *			does the same as the other constructor
 *			used for const access
 * 
 * Methods/operators:
 *		T& operator[] (int index)
 *			returns a mutable reference to an element in m_array2D
 *		const T& operator[] (int index) const
 *			returns a const reference to an element in m_array2D
 ***************************************************************/
template <typename T>
class Row
{
	private:
		//pointer to the Array2D that contains the data we want to access
		const Array2D<T>* m_array2D;

		//the row we want to access
		int row;

	public:
		//constructors
		Row(Array2D<T>& ar, int row);
		Row(const Array2D<T>& ar, const int row);

		//index operators
		T& operator[] (int index);
		const T& operator[] (int index) const;

};

//include the implementation file
#include "row_impl.h"

#endif

