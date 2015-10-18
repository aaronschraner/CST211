/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      October 17, 2015
 * Last Modified:     October 17, 2015
 * Lab Number:        1
 * Filename:          Cell.cpp
 * 
 ********************************************************************************/
#include "Cell.h"

//character representation for cell
char Cell::charRep()
{
	if(!visible)
		return ' ';
	if(mine)
		return 'X';
	if(flagged)
		return '<';
	return '0' + neighbors;
}

	
