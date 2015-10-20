/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      October 17, 2015
 * Last Modified:     October 17, 2015
 * Lab Number:        1
 * Filename:          Cell.h
 * 
 * Class: Cell
 * 
 * Methods: 
 *      bool hasMine ():
 *         returns true if cell has a mine on it
 * 
 *      bool isVisible ():
 *         returns true if cell is visible
 * 
 *      bool flagged ():
 *         returns true if cell has a flag on it
 * 
 *      void setMine (bool m):
 *         Puts a mine on the cell if m is true
 * 
 *      void flag (bool m):
 *         flags the cell if m is true
 * 
 *      void setVisible (bool m):
 *         makes the cell visible if m is true
 * 
 *      short getNeighbors ():
 *         return the number of neighbors
 * 
 *      void setNeighbors (short n):
 *         set the number of adjacent mines (Game/Board use only)
 * 
 * more detailed documentation on inline functions is available in .doc/funcs/Cell/
 ********************************************************************************/
#ifndef CELL_H
#define CELL_H

#include <iostream>
class Cell
{
    private:
		bool mine; //true if cell has a mine
		short neighbors; //the number of adjacent mines
		bool visible; 
		bool flagged;
		friend std::ostream& operator<< (std::ostream& os, const Cell& c);

    public:
		//find if the cell has a mine on it
        bool hasMine () { return mine; }

		//find if the cell has been uncovered or not
        bool isVisible () { return visible; }

		//find if the cell has been flagged or not
        bool isFlagged () { return flagged; }

		//either put/remove a mine on/from the cell (depending on if m is true/false)
        void setMine (bool m) { mine=m; }

		//place or remove the flag on/from the cell
        void setFlag (bool m) {flagged=m;}

		//change the visibility of the cell
        void setVisible (bool m) {visible=m;}

		//return the number of neighbors the cell has
		//(depends on Board class to be accurate)
        short getNeighbors () { return neighbors;}

		//get a character representation of the cell
		char charRep() const;

		//set the number of neighbors the cell has (only for use by Board class)
        void setNeighbors (short n) { neighbors=n; }

		//default constructor for cell (set everything to 0 or false)
		Cell(): neighbors(0), mine(0), visible(0), flagged(0) {}



};
#endif

