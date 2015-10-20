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
 * 
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
        //TODO: brief description
        bool hasMine () { return mine; }

        //TODO: brief description
        bool isVisible () { return visible; }

        //TODO: brief description
        bool isFlagged () { return flagged; }

        //TODO: brief description
        void setMine (bool m) { mine=m; }

        //TODO: brief description
        void setFlag (bool m) {flagged=m;}

        //TODO: brief description
        void setVisible (bool m) {visible=m;}

        //TODO: brief description
        short getNeighbors () { return neighbors;}

		char charRep() const;

        //TODO: brief description
        void setNeighbors (short n) { neighbors=n; }
		Cell(): neighbors(0), mine(0), visible(0), flagged(0) {}



};
#endif

