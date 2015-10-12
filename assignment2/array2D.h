/*******************************************************
 * Author: Aaron Schraner
 * Date created: 10/06/15
 * Last modification date: 10/10/15
 * Assignment: 2D array class
 * Filename: array2D.h
 *
 * purpose: A 2 dimensional array with lots of problems
 * this class is designed to be used with the Row class to access
 * elements using array[row][col] syntax. 
 * array[row] returns a Row object with a reference 
 * to the array object that created it. That row object 
 * will return the desired element when indexed with 
 * square brackets
 * array2D <T> [index] -> Row<T>
 * row <T> [index] -> T
 *
 *     _                         ____  ____  
 *    / \   _ __ _ __ __ _ _   _|___ \|  _ \
 *   / _ \ | '__| '__/ _` | | | | __) | | | |
 *  / ___ \| |  | | | (_| | |_| |/ __/| |_| |
 * /_/   \_\_|  |_|  \__,_|\__, |_____|____/ 
 *                         |___/             
 *
 *******************************************************/


#ifndef ARRAY2D_H
#define ARRAY2D_H

#include <iostream>
#include "row.h"

template <typename T>
class Array2D
{
	private:
		//number of rows and columns in the array
		int rows;
		int cols;

		void checkRange(int row, int col=0) const;
		//pointer to the internal array where everything is stored
		T** m_array;

	public:
		//constructors + destructor
		Array2D();
		Array2D(int rows , int cols );
		Array2D(const Array2D<T> &ar);
		~Array2D();

		//overloaded operators
		Array2D& operator=(const Array2D &ar);
		Row<T> operator[] (int index);
		const Row<T> operator[] (int index) const;

		//getters and setters
		int getRows() const		{ return rows; }
		void setRows(int height);
		int getColumns() const	{ return cols; }
		void setColumns(int width);
		void setSize(int nrows, int ncols);

		//array accessors
		T& select(int row, int col);
		const T& select(int row, int col) const;
};

//include the implementation for these member functions
#include "array2D_impl.h"

#endif

