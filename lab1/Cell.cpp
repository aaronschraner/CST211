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
/********************************************************************************
 * char charRep() const;
 * 	Purpose: 
 * 		Get a character that represents this Minesweeper cell.
 * 		Cell character meanings:
 * 		< : flagged cell
 * 		# : covered (invisible) cell
 * 		X : cell with a mine in it
 * 		1-8: cell with that many adjacent mines
 * 		_ : cell with 0 adjacent mines
 * 	
 * 	Entry: 
 * 		Nothing (reads member variables for Cell)
 * 	
 * 	Exit: 
 * 		Returns a character representing the cell's contents and status
 * 	
 ********************************************************************************/
char Cell::charRep() const
{
	if(flagged)
		return '<';
	if(!visible)
		return '#';
	if(mine)
		return 'X';
	//if there are more than 0 adjacent mines, return a number
	//otherwise use '_'
	return neighbors ? ('0' + neighbors) : '_';
}

/********************************************************************************
 * std::ostream& operator<< (std::ostream& os, const Cell& c);
 * 	Purpose: 
 * 		Stream output operator for Cell objects
 * 		Outputs the character representation of the cell (as defined by charRep())
 * 	
 * 	Entry: 
 * 		os: the output stream to print to
 * 		c: the cell to be outputted
 * 	
 * 	Exit: 
 * 		returns a reference to the ostream
 * 	
 ********************************************************************************/
std::ostream& operator<<( std::ostream& os, const Cell& c)
{
	os << c.charRep() ;
	return os;
}
