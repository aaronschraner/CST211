/********************************************************************************
 * Author:            Aaron Schraner
 * Date Created:      October 17, 2015
 * Last Modified:     October 17, 2015
 * Lab Number:        1
 * Filename:          Board.h
 * 
 * Class: Board
 * 
 * Methods: 
 *      void generateNeighbors ():
 *         calculates the number of adjacent mines for each cell
 * 
 *      void uncoverArea (int x, int y):
 *         Make all surrounding unmined cells visible
 * 
 *      void print ():
 *         display the board
 * 
 *      void click (int x, int y):
 *         Try clicking the selected tile
 * 
 *      void flag (int x, int y):
 *         flag the selected cell
 * 
 * 
 ********************************************************************************/
#ifndef BOARD_H
#define BOARD_H
#include "array2D.h"
#include "Cell.h"
class Board
{
    private:
        Array2D <Cell> board;


    public:
        //TODO: brief description
        void generateNeighbors ();

        //TODO: brief description
        void uncoverArea (int x, int y);

        //TODO: brief description
        void print ();

        //TODO: brief description
        void click (int x, int y);

        //TODO: brief description
        void flag (int x, int y);
		
		Board(int rows, int cols, int mines);

};
#endif
