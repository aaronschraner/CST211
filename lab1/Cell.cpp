/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      October 17, 2015
 * Last Modified:     October 17, 2015
 * Lab Number:        1
 * Filename:          Cell.cpp
 * 
 ********************************************************************************/
#include "Cell.h"
#include <iostream>
//character representation for cell
char Cell::charRep() const
{
	if(flagged)
		return '<';
	if(!visible)
		return '#';
	if(mine)
		return 'X';
	return neighbors ? ('0' + neighbors) : '_';
}

	
std::ostream& operator<<( std::ostream& os, const Cell& c)
{
	os << c.charRep() ;
	return os;
}
