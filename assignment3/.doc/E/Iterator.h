/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      October 18, 2015
 * Last Modified:     October 18, 2015
 * Assignment number: 
 * Filename:          Iterator.h
 * 
 * Class: Iterator
 * 
 * Methods: 
 *      bool operator== ( const Iterator<T>& rhs):
 *         Returns true if the iterators point to the same node
 * 
 *      Iterator<T>& operator= (const Iterator<T>& rhs):
 *         assigns this iterator's node to <rhs>'s
 * 
 *      Iterator<T>& operator++ (int):
 *         same as the other operator++ but postfix
 * 
 *      Iterator<T>& operator-- (int):
 *         same as the other operator-- but postfix
 * 
 *      Iterator ( const Iterator<T>& rhs):
 *         copy constructor (sets node to <rhs>'s node)
 * 
 * 
 ********************************************************************************/
#ifndef ITERATOR_H
#define ITERATOR_H
template < typename  >
class Iterator
{
    private:
        //TODO: add member variables

    public:
        //TODO: brief description
        bool operator== ( const Iterator<T>& rhs);

        //TODO: brief description
        Iterator<T>& operator= (const Iterator<T>& rhs);

        //TODO: brief description
        Iterator<T>& operator++ (int);

        //TODO: brief description
        Iterator<T>& operator-- (int);

        //TODO: brief description
        Iterator ( const Iterator<T>& rhs);

};
#include "Iterator_impl.h"

#endif

